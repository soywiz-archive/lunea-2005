/*  $Id: netobject_client.h,v 1.11 2004/01/02 15:42:44 mbn Exp $
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

//! clanNetwork="NetObjects"
//! header=network.h

#ifndef header_netobject_client
#define header_netobject_client

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4786)
#endif

#include <string>
#include "../../signals.h"

class CL_NetObject_Client_Generic;
class CL_NetPacket;
class CL_NetObject_Controller_Generic;
class CL_NetComputer;

//: Network replication object, client version.
//- !group=Network/NetObjects!
//- !header=network.h!
//- <p>The netobject is a message dispatcher for objects being replicated over the network.</p>
//- <p>It provides an easy system for a server object to send messages to replicated clients
//- on remote computers, as well as getting answers back.</p>
class CL_NetObject_Client
{
//! Construction:
public:
	//: NetObject client constructor.
	CL_NetObject_Client(int obj_id, const CL_NetComputer &server, CL_NetObject_Controller_Generic *controller);

	//: Copy constructor.
	CL_NetObject_Client(const CL_NetObject_Client &copy);

	//: NetObject destructor.
	virtual ~CL_NetObject_Client();

//! Attributes:
public:
	//: Returns the netobject handle that identifies it over the network.
	int get_obj_id() const;

	//: Returns the netcomputer handle to the server of this object.
	CL_NetComputer &get_server() const;

//! Operations:
public:
	//: Send a message to the server object.
	void send(int msg_type, const CL_NetPacket &message);

//! Signals:
public:
	//: Signal emitted when receiving messages of the specified type from the server.
	CL_Signal_v1<CL_NetPacket &> &sig_received_message(int msg_type);

//! Implementation:
private:
	CL_NetObject_Client_Generic *impl;
};

#endif
