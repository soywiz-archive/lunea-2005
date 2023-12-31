/*  $Id: outputsource_netstream.h,v 1.9 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_outputsource_netstream
#define header_outputsource_netstream

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../Core/IOData/outputsource.h"

class CL_NetStream;
class CL_NetStream_Generic;

//: Output Source NetStream Class.
//- !group=Network/NetSessions!
//- !header=network.h!
class CL_OutputSource_NetStream : public CL_OutputSource
{
//! Construction:
public:
	//: Output Source NetStream Constructor.
	CL_OutputSource_NetStream(const CL_NetStream &netstream);

	virtual ~CL_OutputSource_NetStream();

//! Attributes:
public:
	//: Returns current position in output source.
	//return: Current position in source.
	virtual int tell() const;

	//: Returns the size of the output source.
	//return: Size of the output source.
	virtual int size() const;

//! Operations:
public:
	//: Writes larger amounts of data (no endian and 64 bit conversion).
	//param data: Points to the array from which to write.
	//param size: Number of bytes to write.
	//return: Num bytes actually written.
	virtual int write(const void *data, int size);
	
	//: Opens the output source. By default, it is open.
	virtual void open();
	
	//: Closes the output source.
	virtual void close();

	//: Make a copy of the current outputsource, standing at the same position.
	//return: The copy of the output source.
	virtual CL_OutputSource *clone();

//! Implementation:
private:
	friend class CL_NetStream;

	// Constructor used to initialize internal CL_NetStream member variable.
	CL_OutputSource_NetStream() { netstream = 0; ref_count_netstream = false; }

	CL_NetStream_Generic *netstream;
	bool ref_count_netstream;
};

#endif
