/*  $Id: inputsource_netstream.h,v 1.8 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_inputsource_netstream
#define header_inputsource_netstream

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../Core/IOData/inputsource.h"

class CL_NetStream;
class CL_NetStream_Generic;

//: InputSource NetStream Class
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_InputSource_NetStream : public CL_InputSource
{
//! Construction:
public:
	//: InputSource Netstream Constructor
	CL_InputSource_NetStream(const CL_NetStream &netstream);

	virtual ~CL_InputSource_NetStream();

//! Attributes:
public:
	//: Returns current position in input source.
	//return: Current position in input source.
	virtual int tell() const;

	//: Returns the size of the input source
	//return: Size of the input source.
	virtual int size() const;

//! Operations:
public:
	//: Reads larger amounts of data (no endian and 64 bit conversion).
	//param data: Points to an array where the read data is stored.
	//param size: Number of bytes to read.
	//return: Num bytes actually read.
	virtual int read(void *data, int size);
	
	//: Opens the input source. By default, it is open.
	virtual void open();
	
	//: Closes the input source.
	virtual void close();

	//: Make a copy of the current inputsource, standing at the same position.
	//return: The copy of the input source.
	virtual CL_InputSource *clone() const;

	//: Seeks to the specified position in the input source.
	//param pos: Position relative to 'seek_type'.
	//param seek_type: Defines what the 'pos' is relative to. Can be either seek_set, seek_cur og seek_end.
	virtual void seek(int pos, SeekEnum seek_type);

	//: Pushes the current input source position. The position can be restored again with pop_position.
	virtual void push_position();
	
	//: Pops a previous pushed input source position (returns to the position).
	virtual void pop_position();

//! Implementation:
private:
	friend class CL_NetStream;

	// Constructor used to initialize internal CL_NetStream member variable.
	CL_InputSource_NetStream() { netstream = 0; ref_count_netstream = false; }

	CL_NetStream_Generic *netstream;
	bool ref_count_netstream;
};

#endif
