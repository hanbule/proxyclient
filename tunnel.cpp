#include "defs.h"
#include "tunnel.h"
#include "ringbuffer.h"
#include "socks5.h"

extern RakNet::RakPeerInterface *rakPeer;

unsigned char GetPacketIdentifier(RakNet::Packet *p);
unsigned char *GetPacketData(RakNet::Packet *p);
size_t GetPacketLength(RakNet::Packet *p);

Tunnel::Tunnel()
{
    _stage = TUNNEL_STAGE_NOT_CONNECTED;
    _proxy_server_host = "";
}

Tunnel::~Tunnel()
{
}

void Tunnel::setup(const char *proxy_server_host, uint16_t proxy_server_port, const char *key)
{
    SHA256_CTX sha256;
    int len = strlen(key);

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, key, len);
    SHA256_Final(password, &sha256);

    _proxy_server_host = proxy_server_host;
    _proxy_server_port = proxy_server_port;
}

void Tunnel::handle_packet(RakNet::Packet *p)
{
    unsigned char packetIdentifier;
    unsigned char *data;
    size_t length;

    packetIdentifier = GetPacketIdentifier(p);
    data = GetPacketData(p);
    length = GetPacketLength(p);

    switch (packetIdentifier)
    {
    case ID_DISCONNECTION_NOTIFICATION:
    case ID_CONNECTION_BANNED: // Banned from this server
    case ID_CONNECTION_ATTEMPT_FAILED:
    case ID_NO_FREE_INCOMING_CONNECTIONS:
    case ID_INVALID_PASSWORD:
    case ID_CONNECTION_LOST:
        _stage = TUNNEL_STAGE_NOT_CONNECTED;
        printf("connect to server falled.\n");
        break;
    case ID_ALREADY_CONNECTED:
    case ID_CONNECTION_REQUEST_ACCEPTED:
        _stage = TUNNEL_STAGE_CONNECTED;
        // This tells the client they have connected
        printf("connection request accepted to %s with GUID %s\n", p->systemAddress.ToString(true), p->guid.ToString());
        break;

    default:
        break;
    }
}

void Tunnel::update_connection_state()
{
    if (_stage == TUNNEL_STAGE_NOT_CONNECTED)
    {
        if (RakNet::CONNECTION_ATTEMPT_STARTED == rakPeer->Connect(_proxy_server_host, _proxy_server_port, NULL, 0))
        {
            _stage = TUNNEL_STAGE_CONNECTING;
            printf("connecting to proxy server %s:%d....\n", _proxy_server_host, _proxy_server_port);
        }
    }
}

void Tunnel::send(std::shared_ptr<socks5_client> &client, RakNet::BitStream &packet)
{
    RakNet::BitStream encrypted_packet;
    uint8_t nonce[8];
    *(uint64_t *)&nonce = rakPeer->Get64BitUniqueRandomNumber();
    s20_crypt(password, S20_KEYLEN_256, nonce, 0, packet.GetData(), packet.GetNumberOfBytesUsed());

    encrypted_packet.Write((unsigned char)ID_USER_PACKET_ENUM);
    encrypted_packet.Write(nonce);
    encrypted_packet.Write(packet);

    char orderingChannel = client->guid % 32; //PacketPriority::NUMBER_OF_ORDERED_STREAMS
    rakPeer->Send(&encrypted_packet, IMMEDIATE_PRIORITY, RELIABLE, orderingChannel, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true);
}

void Tunnel::on_frame()
{
    _lock.lock();

    update_connection_state();

    if (_stage != TUNNEL_STAGE_CONNECTED)
    {
        for (size_t i = 0; i < _connecting_requests.size(); i++)
        {
            // _connecting_requests[i]->event.SetEvent();
        }

        _connecting_requests.clear();
    }
    else
    {
        for (size_t i = 0; i < _connecting_requests.size(); i++)
        {
            std::shared_ptr<socks5_client> &client = _connecting_requests[i];

            RakNet::BitStream serializer;
            serializer.Write((unsigned char)1);
            serializer.Write((unsigned char)client->guid);
            serializer.Write((unsigned char)client->remote_addrtype);

            if (client->remote_addrtype == SOCKS5_ADDRTYPE_IPV4)
            {
                serializer.Write(client->remote_addr.v4.sin_addr);
                serializer.Write(client->remote_addr.v4.sin_port);
            }

            if (client->remote_addrtype == SOCKS5_ADDRTYPE_IPV6)
            {
                serializer.Write(client->remote_addr.v6.sin6_addr);
                serializer.Write(client->remote_addr.v6.sin6_port);
            }

            if (client->remote_addrtype == SOCKS5_ADDRTYPE_DOMAIN)
            {
                serializer.Write(client->remote_addr.domain.domain);
                serializer.Write(client->remote_addr.domain.port);
            }

            send(client, serializer);
        }

        _connecting_requests.clear();
    }

    _lock.unlock();
}

void Tunnel::request_connect(std::shared_ptr<socks5_client> &client)
{
    _lock.lock();

    if (_stage != TUNNEL_STAGE_CONNECTED)
    {
        client->stage = SOCKS5_CONN_STAGE_CONNECTED;
        client->resp_status = SOCKS5_RESPONSE_SERVER_FAILURE;
        client->event.SetEvent();

        _lock.unlock();
        return;
    }

    _connecting_requests.push_back(client);
    _lock.unlock();
}

void Tunnel::link_client(std::shared_ptr<socks5_client> &client)
{
    _lock.lock();
    _socks5_clientmap[client->guid] = client;
    _lock.unlock();
}

void Tunnel::unlink_client(std::shared_ptr<socks5_client> &client)
{
    _lock.lock();

    auto iterator = _socks5_clientmap.find(client->guid);
    if (iterator == _socks5_clientmap.end())
    {
        _lock.unlock();
        return;
    }

    _socks5_clientmap.erase(iterator);
    _lock.unlock();
}

void Tunnel::send_stream(std::shared_ptr<socks5_client> &client)
{
    size_t totalsize = client->incoming_buffers.size();
    void *buffer = malloc(totalsize);
    client->incoming_buffers.deque(buffer, totalsize);

    RakNet::BitStream serializer;
    serializer.Write((unsigned char)1);
    serializer.Write((unsigned char)client->guid);
    serializer.Write((char *)buffer, totalsize);

    send(client, serializer);
}