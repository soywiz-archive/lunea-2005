/*  $Id: netobject_controller.h,v 1.12 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_netobject_controller
#define header_netobject_controller

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4786)
#endif

#include <string>
#include "../../signals.h"
#include "../NetSession/netcomputer.h"
#include "../NetSession/netpacket.h"

class CL_NetObject_Controller_Generic;
class CL_NetGroup;
class CL_NetObject_Client;

//: Network object replication channel.
//- !group=Network/NetObjects!
//- !header=network.h!
//- <p>Manages a netchannel with netobject replication data. It dispatches incoming
//- messages to the correct netobject.</p>
class CL_NetObject_Controller
{
//! Construction:
public:
	//: Constructs a netobject controller.
	CL_NetObject_Controller(class CL_NetSession *netsession, const std::string &channel);

	//: Copy constructor.
	CL_NetObject_Controller(const CL_NetObject_Controller &copy);

	//: NetObject Controller destructor.
	virtual ~CL_NetObject_Controller();

//! Attributes:
public:

//! Operations:
public:
	// Copy assignment operator.
	CL_NetObject_Controller &operator =(const CL_NetObject_Controller &copy);

//! Signals:
public:
	//: Signal that is called whenever the netobject channel receives a message for a netobject
	//: it doesnt know. The application should hook a slot into this signal and determine what
	//: to do with the message.
	//- <p>CL_Signal_v3<netobject, msgtype, message>.</p>
	//- <p>Signal parameters:
	//- CL_NetObject &netobj_handle - Handle identifying the netobject created.
	//- int msg_type - Message type of the message (the msg_type param used to send it with netobj.send()).
	//- CL_NetPacket &message - The message itself.</p>
	CL_Signal_v3<CL_NetObject_Client &, int, CL_NetPacket &> &sig_create_object();

//! Implementation:
public:
	//: NetObjectController implementation.
	CL_NetObject_Controller_Generic *impl;
};

#endif
