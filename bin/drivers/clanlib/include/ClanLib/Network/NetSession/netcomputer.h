/*  $Id: netcomputer.h,v 1.12 2004/02/01 19:44:41 sphair Exp $
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

#ifndef header_netcomputer
#define header_netcomputer

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Socket/ip_address.h"
#include "netsession.h"

class CL_NetComputer_Generic;

//: Class representing a computer in a network game.
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_NetComputer
{
//! Construction:
public:
	//: Creates a netcomputer object.
	CL_NetComputer();

	CL_NetComputer(const CL_NetComputer &copy);

	//: Net Computer Destructor.
	virtual ~CL_NetComputer();

//! Attributes:
public:
	//: Returns the IP address (in network byte order) of the computer.
	CL_IPAddress get_address() const;

	//: Returns the netsession that the computer is attached to.
	CL_NetSession get_session();

	//: Returns true if computer is disconnected.
	bool is_disconnected() const;

	//: Returns the disconnect reason.
	const std::string &get_disconnect_reason() const;

	//: Returns true if objects are the same.
	bool operator == (const CL_NetComputer &other_instance) const;

	//: Returns true if the other netcomputer is less.
	//- <p>This is used for sorting purposes (eg. if you use a std::map<CL_NetComputer, Player>).</p>
	bool operator < (const CL_NetComputer &other_instance) const;

	//: Returns true if the other netcomputer is greater.
	//- <p>This is used for sorting purposes (eg. if you use a std::map<CL_NetComputer, Player>).</p>
	bool operator > (const CL_NetComputer &other_instance) const;

//! Operations:
public:
	//: Disconnects the computer from server.
	void disconnect(std::string reason = (std::string)"No reason given");

	//: Send packet to the specified channel.
	//- <p>set reliable to false to send with udp.</p>
	void send(const std::string &packet_channel, const CL_NetPacket &packet, bool reliable = true);

	//: Copy Operator.
	CL_NetComputer &operator = (const CL_NetComputer &other_instance);

//! Implementation:
public:
	CL_NetComputer(class CL_NetComputer_Generic *impl);

	CL_NetComputer_Generic *impl;
};

#endif
