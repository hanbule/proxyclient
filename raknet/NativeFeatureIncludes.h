/*
 *  Copyright (c) 2004, Oculus VR, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant 
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

// If you want to change these defines, put them in NativeFeatureIncludesOverrides so your changes are not lost when updating RakNet
// The user should not edit this file
#include "NativeFeatureIncludesOverrides.h"

#ifndef __NATIVE_FEATURE_INCLDUES_H
#define __NATIVE_FEATURE_INCLDUES_H

// Uncomment below defines, and paste to NativeFeatureIncludesOverrides.h, to exclude plugins that you do not want to build into the static library, or DLL
// These are not all the plugins, only those that are in the core library
// Other plugins are located in DependentExtensions
// #define _RAKNET_SUPPORT_ConnectionGraph2 0
// #define _RAKNET_SUPPORT_DirectoryDeltaTransfer 0
// #define _RAKNET_SUPPORT_FileListTransfer 0
// #define _RAKNET_SUPPORT_FullyConnectedMesh2 0
// #define _RAKNET_SUPPORT_MessageFilter 0
// #define _RAKNET_SUPPORT_NatPunchthroughClient 0
// #define _RAKNET_SUPPORT_NatPunchthroughServer 0
// #define _RAKNET_SUPPORT_NatTypeDetectionClient 0
// #define _RAKNET_SUPPORT_NatTypeDetectionServer 0
// #define _RAKNET_SUPPORT_PacketLogger 0
// #define _RAKNET_SUPPORT_ReadyEvent 0
// #define _RAKNET_SUPPORT_ReplicaManager3 0
// #define _RAKNET_SUPPORT_Router2 0
// #define _RAKNET_SUPPORT_RPC4Plugin 0
// #define _RAKNET_SUPPORT_TeamBalancer 0
// #define _RAKNET_SUPPORT_TeamManager 0
// #define _RAKNET_SUPPORT_UDPProxyClient 0
// #define _RAKNET_SUPPORT_UDPProxyCoordinator 0
// #define _RAKNET_SUPPORT_UDPProxyServer 0
// #define _RAKNET_SUPPORT_ConsoleServer 0
// #define _RAKNET_SUPPORT_RakNetTransport 0
// #define _RAKNET_SUPPORT_TelnetTransport 0
// #define _RAKNET_SUPPORT_TCPInterface 0
// #define _RAKNET_SUPPORT_LogCommandParser 0
// #define _RAKNET_SUPPORT_RakNetCommandParser 0
// #define _RAKNET_SUPPORT_EmailSender 0
// #define _RAKNET_SUPPORT_HTTPConnection 0
// #define _RAKNET_SUPPORT_HTTPConnection2 0
// #define _RAKNET_SUPPORT_PacketizedTCP 0
// #define _RAKNET_SUPPORT_TwoWayAuthentication 0

// SET DEFAULTS IF UNDEFINED
#ifndef LIBCAT_SECURITY
#define LIBCAT_SECURITY 0
#endif
#ifndef _RAKNET_SUPPORT_ConnectionGraph2
#define _RAKNET_SUPPORT_ConnectionGraph2 0
#endif
#ifndef _RAKNET_SUPPORT_DirectoryDeltaTransfer
#define _RAKNET_SUPPORT_DirectoryDeltaTransfer 0
#endif
#ifndef _RAKNET_SUPPORT_FileListTransfer
#define _RAKNET_SUPPORT_FileListTransfer 0
#endif
#ifndef _RAKNET_SUPPORT_FullyConnectedMesh
#define _RAKNET_SUPPORT_FullyConnectedMesh 0
#endif
#ifndef _RAKNET_SUPPORT_FullyConnectedMesh2
#define _RAKNET_SUPPORT_FullyConnectedMesh2 0
#endif
#ifndef _RAKNET_SUPPORT_MessageFilter
#define _RAKNET_SUPPORT_MessageFilter 0
#endif
#ifndef _RAKNET_SUPPORT_NatPunchthroughClient
#define _RAKNET_SUPPORT_NatPunchthroughClient 0
#endif
#ifndef _RAKNET_SUPPORT_NatPunchthroughServer
#define _RAKNET_SUPPORT_NatPunchthroughServer 0
#endif
#ifndef _RAKNET_SUPPORT_NatTypeDetectionClient
#define _RAKNET_SUPPORT_NatTypeDetectionClient 0
#endif
#ifndef _RAKNET_SUPPORT_NatTypeDetectionServer
#define _RAKNET_SUPPORT_NatTypeDetectionServer 0
#endif
#ifndef _RAKNET_SUPPORT_PacketLogger
#define _RAKNET_SUPPORT_PacketLogger 0
#endif
#ifndef _RAKNET_SUPPORT_ReadyEvent
#define _RAKNET_SUPPORT_ReadyEvent 0
#endif
#ifndef _RAKNET_SUPPORT_ReplicaManager3
#define _RAKNET_SUPPORT_ReplicaManager3 0
#endif
#ifndef _RAKNET_SUPPORT_Router2
#define _RAKNET_SUPPORT_Router2 0
#endif
#ifndef _RAKNET_SUPPORT_RPC4Plugin
#define _RAKNET_SUPPORT_RPC4Plugin 0
#endif
#ifndef _RAKNET_SUPPORT_TeamBalancer
#define _RAKNET_SUPPORT_TeamBalancer 0
#endif
#ifndef _RAKNET_SUPPORT_TeamManager
#define _RAKNET_SUPPORT_TeamManager 0
#endif
#ifndef _RAKNET_SUPPORT_UDPProxyClient
#define _RAKNET_SUPPORT_UDPProxyClient 0
#endif
#ifndef _RAKNET_SUPPORT_UDPProxyCoordinator
#define _RAKNET_SUPPORT_UDPProxyCoordinator 0
#endif
#ifndef _RAKNET_SUPPORT_UDPProxyServer
#define _RAKNET_SUPPORT_UDPProxyServer 0
#endif
#ifndef _RAKNET_SUPPORT_ConsoleServer
#define _RAKNET_SUPPORT_ConsoleServer 0
#endif
#ifndef _RAKNET_SUPPORT_RakNetTransport
#define _RAKNET_SUPPORT_RakNetTransport 0
#endif
#ifndef _RAKNET_SUPPORT_TelnetTransport
#define _RAKNET_SUPPORT_TelnetTransport 0
#endif
#ifndef _RAKNET_SUPPORT_TCPInterface
#define _RAKNET_SUPPORT_TCPInterface 0
#endif
#ifndef _RAKNET_SUPPORT_LogCommandParser
#define _RAKNET_SUPPORT_LogCommandParser 0
#endif
#ifndef _RAKNET_SUPPORT_RakNetCommandParser
#define _RAKNET_SUPPORT_RakNetCommandParser 0
#endif
#ifndef _RAKNET_SUPPORT_EmailSender
#define _RAKNET_SUPPORT_EmailSender 0
#endif
#ifndef _RAKNET_SUPPORT_HTTPConnection
#define _RAKNET_SUPPORT_HTTPConnection 0
#endif
#ifndef _RAKNET_SUPPORT_HTTPConnection2
#define _RAKNET_SUPPORT_HTTPConnection2 0
#endif
#ifndef _RAKNET_SUPPORT_PacketizedTCP
#define _RAKNET_SUPPORT_PacketizedTCP 0
#endif
#ifndef _RAKNET_SUPPORT_TwoWayAuthentication
#define _RAKNET_SUPPORT_TwoWayAuthentication 0
#endif
#ifndef _RAKNET_SUPPORT_CloudClient
#define _RAKNET_SUPPORT_CloudClient 0
#endif
#ifndef _RAKNET_SUPPORT_CloudServer
#define _RAKNET_SUPPORT_CloudServer 0
#endif
#ifndef _RAKNET_SUPPORT_DynDNS
#define _RAKNET_SUPPORT_DynDNS 0
#endif
#ifndef _RAKNET_SUPPORT_Rackspace
#define _RAKNET_SUPPORT_Rackspace 0
#endif
#ifndef _RAKNET_SUPPORT_FileOperations
#define _RAKNET_SUPPORT_FileOperations 0
#endif
#ifndef _RAKNET_SUPPORT_UDPForwarder
#define _RAKNET_SUPPORT_UDPForwarder 0
#endif
#ifndef _RAKNET_SUPPORT_StatisticsHistory
#define _RAKNET_SUPPORT_StatisticsHistory 0
#endif
#ifndef _RAKNET_SUPPORT_LibVoice
#define _RAKNET_SUPPORT_LibVoice 0
#endif
#ifndef _RAKNET_SUPPORT_RelayPlugin
#define _RAKNET_SUPPORT_RelayPlugin 0
#endif

// Take care of dependencies
#if _RAKNET_SUPPORT_DirectoryDeltaTransfer==0
#undef _RAKNET_SUPPORT_FileListTransfer
#define _RAKNET_SUPPORT_FileListTransfer 0
#endif
#if _RAKNET_SUPPORT_FullyConnectedMesh2==0
#undef _RAKNET_SUPPORT_ConnectionGraph2
#define _RAKNET_SUPPORT_ConnectionGraph2 0
#endif
#if _RAKNET_SUPPORT_TelnetTransport==0
#undef _RAKNET_SUPPORT_PacketizedTCP
#define _RAKNET_SUPPORT_PacketizedTCP 0
#endif
#if _RAKNET_SUPPORT_PacketizedTCP==0 || _RAKNET_SUPPORT_EmailSender==0 || _RAKNET_SUPPORT_HTTPConnection==0
#undef _RAKNET_SUPPORT_TCPInterface
#define _RAKNET_SUPPORT_TCPInterface 0
#endif












#endif // __NATIVE_FEATURE_INCLDUES_H
