/*  $Id: netstream.h,v 1.10 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_netstream
#define header_netstream

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning(disable : 4786)
#endif

#include "inputsource_netstream.h"
#include "outputsource_netstream.h"
#include <string>

class CL_NetSession;
class CL_NetComputer;
class CL_EventTrigger;
class CL_NetStream_Generic;

//: Net stream class.
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_NetStream
{
//! Construction:
public:
	//: Connects to a remote netstream.
	//param stream_channel: Channel identifier establishing connection to.
	//param dest: Remote computer on which to connect.
	CL_NetStream(
		const std::string &stream_channel,
		CL_NetComputer &dest);

	CL_NetStream(const CL_NetStream &copy);

	virtual ~CL_NetStream();

//! Attributes:
public:
	//: Input source interface for netstream.
	CL_InputSource_NetStream input;

	//: Output source interface for netstream.
	CL_OutputSource_NetStream output;

	//: Event trigger for reading.
	CL_EventTrigger *get_read_trigger();

	//: Event trigger for writing.
	CL_EventTrigger *get_write_trigger();

//! Operations:
public:
	//: Copy constructor.
	CL_NetStream &operator =(const CL_NetStream &copy);

	//: Send data onto stream.
	int send(const void *data, int size);

	//: Receive data from stream.
	int recv(void *data, int size);

//! Implementation:
public:
	CL_NetStream(CL_NetStream_Generic *impl);

	CL_NetStream_Generic *impl;
};

#endif
