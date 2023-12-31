/*  $Id: outputsource_memory.h,v 1.18 2004/01/02 15:42:43 mbn Exp $
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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_outputsource_memory
#define header_outputsource_memory

#if _MSC_VER > 1000
#pragma once
#endif

#include "outputsource.h"

//: Outputsource writing to memory.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_OutputSource_Memory provides a way to write to memory in a way that is abstracted from 
//- the user. CL_OutputSource_Memory should not be instantiated directly, but 
//- rather CL_OutputSourceProvider should create the appropriate output source.</p>

class CL_OutputSource_Memory : public CL_OutputSource
{
//! Construction:
public:
	//: Constructs a memory output source.
	CL_OutputSource_Memory();

	//: Output Source Memory destructor.
	virtual ~CL_OutputSource_Memory();

//! Attributes:
public:
	//: Returns current position in output source.
	//return: Current position in source.
	virtual int tell() const;

	//: Returns the size of the output source.
	//return: Size of the output source.
	virtual int size() const;

	//: Get the pointer to the internal data array in the memory source.
	//- <p>Used to extract the data after usage.</p>
	//return: String containing the data written to the output source.
	std::string get_data() const;

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
	std::string data;
	unsigned int pos;
};

#endif
