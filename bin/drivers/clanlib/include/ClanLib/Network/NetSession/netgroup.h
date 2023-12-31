/*  $Id: netgroup.h,v 1.10 2004/01/26 16:14:48 sphair Exp $
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

#ifndef header_netgroup
#define header_netgroup

#if _MSC_VER > 1000
#pragma once
#endif

#include <list>
#include "netcomputer.h"

//: Represents a group of computers.
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_NetGroup : public std::list<CL_NetComputer>
{
//! Construction:
public:
	//: Constructs a group.
	//param computer: Add this computer to group.
	//param group: Add this group of computers to the group.
	CL_NetGroup();

	CL_NetGroup(const CL_NetComputer &computer);

	CL_NetGroup(const std::list<CL_NetComputer> &group);

//! Operations:
public:
	//: Send packet to all the computers in the group.
	void send(const std::string &packet_channel, const CL_NetPacket &packet, bool reliable = true);

	//: Disconnects all computers in the group.
	void disconnect();

//! Implementation:
private:
};

#endif
