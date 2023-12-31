/*  $Id: network.h,v 1.17 2004/02/20 13:23:46 sphair Exp $
**
**  ClanLib Game SDK
**  Copyright (C) 2003  The ClanLib Team
**  For a total list of contributers see the file CREDITS.
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Lesser General Public
**  License as published by the Free Software Foundation; either
**  version 2.1 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public
**  License along with this library; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
**
*/

//: <p>Enables network communication.  Includes low-lever socket access as well
//: as higher-level network objects.</p>
//! Global=Network

#ifndef header_network_api
#define header_network_api

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef WIN32
#pragma warning( disable : 4786)
#endif

#include "Network/IRC/irc_connection.h"
#include "Network/IRC/irc_numerics.h"
#include "Network/IRC/dcc_download.h"

#include "Network/NetVariables/netvariables.h"

#include "Network/NetObjects/netobject_client.h"
#include "Network/NetObjects/netobject_controller.h"
#include "Network/NetObjects/netobject_server.h"

#include "Network/NetSession/inputsource_netpacket.h"
#include "Network/NetSession/inputsource_netstream.h"
#include "Network/NetSession/netcomputer.h"
#include "Network/NetSession/netgroup.h"
#include "Network/NetSession/netpacket.h"
#include "Network/NetSession/netsession.h"
#include "Network/NetSession/netstream.h"
#include "Network/NetSession/outputsource_netpacket.h"
#include "Network/NetSession/outputsource_netstream.h"

#include "Network/Socket/inputsource_socket.h"
#include "Network/Socket/ip_address.h"
#include "Network/Socket/outputsource_socket.h"
#include "Network/Socket/socket.h"

#include "Network/setupnetwork.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanNetwork.lib")
#else
#pragma comment(lib, "clanNetworkd.lib")
#endif
#pragma comment(lib, "ws2_32.lib")
#endif

#endif
