/*  $Id: netsession.h,v 1.16 2004/01/02 15:42:44 mbn Exp $
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

//! clanNetwork="NetSessions"
//! header=network.h

#ifndef header_netsession
#define header_netsession

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../signals.h"
#include <string>
class CL_NetStream;
class CL_NetPacket;
class CL_NetComputer;
class CL_NetSession_Generic;
class CL_IPAddress;
class CL_NetGroup;

//: Net session class.
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_NetSession
{
//! Construction:
public:
	//: Constructs a netsession.
	//param app_id: Application identifier. This must match any remote
	//param app_id: netsession connecting to/from this netsession.
	CL_NetSession(const std::string &app_id);

	CL_NetSession(const CL_NetSession &copy);

	virtual ~CL_NetSession();

//! Attributes:
public:
	//: Returns a list of all computers connected.
	CL_NetGroup &get_all();

//! Operations:
public:
	//: Start listening for connections.
	void start_listen(const std::string &listen_port);

	//: Stop listening for connections and disconnect everyone.
	void stop_listen();

	//: Connect to remote netsession.
	CL_NetComputer connect(const CL_IPAddress &address);

	//: Connect to remote netsession asyncronously.
	//- <p>The DNS lookup and connect is done in a worker thread, thus not
	//- blocking the calling thread. If the connection fails,
	//- CL_NetSession::sig_disconnected() is emitted.</p>
	CL_NetComputer connect_async(const std::string &hostname, const std::string &port);

	//: Enable or disable debug output.
	//- <p>This will output the netchannels each netpacket arrive in.</p>
	void show_debug(bool enable = true);

//! Signals:
public:
	//: Signal invoked when a computer connects to the netsession server.
	CL_Signal_v1<CL_NetComputer &> &sig_computer_connected();

	//: Signal invoked when a computer re-connects to the netsession server.
	//- <p>This happens when a CL_NetComputer instance has still not been destroyed
	//- since its last connect (allows you to recognize players dropping out, so
	//- they dont loose their score when they reconnect).</p>
	CL_Signal_v1<CL_NetComputer &> &sig_computer_reconnected();

	//: Signal invoked when a computer disconnects from the netsession server.
	CL_Signal_v1<CL_NetComputer &> &sig_computer_disconnected();

	//: Signal invoked when someone makes a connection to the specified
	//: netstream.
	CL_Signal_v1<CL_NetStream &> &sig_netstream_connect(const std::string &netstream);

	//: Signal invoked when someone sends a netpacket to the specified packet channel.
	CL_Signal_v2<CL_NetPacket &, CL_NetComputer &> &sig_netpacket_receive(const std::string &packet_channel);

//! Implementation:
public:
	CL_NetSession(CL_NetSession_Generic *impl);
private:
	CL_NetSession_Generic *impl;

	friend class CL_NetStream;
};

#endif
