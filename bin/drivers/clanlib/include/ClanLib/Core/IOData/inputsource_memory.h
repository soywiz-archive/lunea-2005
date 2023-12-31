/*  $Id: inputsource_memory.h,v 1.16 2004/04/06 21:57:43 mbn Exp $
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

#ifndef header_inputsource_memory
#define header_inputsource_memory

#if _MSC_VER > 1000
#pragma once
#endif

#include "inputsource.h"

//: Interface to read data from a memory source.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_InputSource_Memory is used to read data from a memory source.
//- CL_InputSourceProvider - Interface to open input sources with.</p>
class CL_InputSource_Memory : public CL_InputSource
{
//! Construction:
public:
	//: Input Source Memory constructor.
	CL_InputSource_Memory(const std::string &data);

	CL_InputSource_Memory(void *data, int size, bool copy_data = false);

	//: Input Source Memory destructor.
	virtual ~CL_InputSource_Memory();

//! Attributes:
public:
	//: Returns current position in input source.
	//return: Current position in input source.
	virtual int tell() const;

	//: Returns the size of the input source
	//return: Size of the input source.
	virtual int size() const;

	//: Get the pointer to the internal data array in the memory source.
	//return: String containing the internal data array's data.
	std::string get_data() const;

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

	//: Pushes the current input source position.
	//- <p>The position can be restored again with pop_position.</p>
	virtual void push_position();
	
	//: Pops a previous pushed input source position (returns to the position).
	virtual void pop_position();

//! Implementation:
private:
	unsigned char *data;
	int data_size;
	int pos;
	std::string str_data;
};

#endif
