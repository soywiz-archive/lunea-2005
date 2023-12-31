/*  $Id: netpacket.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_netpacket
#define header_netpacket

#if _MSC_VER > 1000
#pragma once
#endif

#include "inputsource_netpacket.h"
#include "outputsource_netpacket.h"
#include <string>
#include <list>

class CL_NetComputer;
class CL_NetPacket_Generic;

//: Net packet class.
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_NetPacket
{
//! Construction:
public:
	//: Constructs a packet.
	//param data, size: Initial data for packet.
	CL_NetPacket();

	CL_NetPacket(const void *data, int size);

	CL_NetPacket(const std::string &data);

	CL_NetPacket(const CL_NetPacket &copy);

	// Destructor.
	~CL_NetPacket();

//! Attributes:
public:
	//: Returns a pointer to netpacket data.
	unsigned char *get_data();

	const unsigned char *get_data() const;

	//: Return size of netpacket data.
	int get_size() const;

	//: Input source interface for netpacket.
	CL_InputSource_NetPacket input;

	//: Output source interface for netpacket.
	CL_OutputSource_NetPacket output;

//! Operations:
public:
	//: Resize data. Does not destroy the old data in the packet.
	void resize(int new_size);

	// Copy assignment operator.
	CL_NetPacket &operator =(const CL_NetPacket &copy);

//! Implementation:
private:
	friend class CL_InputSource_NetPacket;
	friend class CL_OutputSource_NetPacket;
	friend class CL_NetComputer;

	CL_NetPacket_Generic *impl;
};

#endif
