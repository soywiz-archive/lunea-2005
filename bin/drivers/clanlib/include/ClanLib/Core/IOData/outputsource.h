/*  $Id: outputsource.h,v 1.19 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_outputsource
#define header_outputsource

#if _MSC_VER > 1000
#pragma once
#endif

#include "datatypes.h"
#include <string>

//: Interface to write data to different types of output sources.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_OutputSource is used to write data to different types of input sources.
//- In most cases, this is regular files and ClanLib zlib compressed datafiles.</p>
//- 
//- <p>To access some system specific output source types, such as datafiles and
//- regular ones, use the static create functions in the CL_OutputSourceProvider
//- class.</p>
//- <p>CL_OutputSourceProvider - Interface to open output sources with.</p>
class CL_OutputSource
{
//! Construction:
public:
	//: Output Source constructor.
	CL_OutputSource() { set_system_mode(); }

	//: Output Source destructor.
	virtual ~CL_OutputSource() { return; }

//! Attributes:
public:
	//: Returns current position in output source.
	//return: Current position in source.
	virtual int tell() const = 0;

	//: Returns the size of the output source.
	//return: Size of the output source.
	virtual int size() const = 0;

//! Operations:
public:
	//: Changes output data endianess to the local systems mode.
	virtual void set_system_mode();

	//: Changes output data endianess to big endian mode.
	virtual void set_big_endian_mode();

	//: Changes output data endianess to little endian mode. This is the default setting.
	virtual void set_little_endian_mode();

	//: Writes a signed 64 bit integer to output source.
	virtual void write_int64(cl_int64 data);

	//: Writes an unsigned 64 bit integer to output source.
	virtual void write_uint64(cl_uint64 data);

	//: Writes a signed 32 bit integer to output source.
	virtual void write_int32(cl_int32 data);

	//: Writes an unsigned 32 bit integer to output source.
	virtual void write_uint32(cl_uint32 data);

	//: Writes a signed 16 bit integer to output source.
	virtual void write_int16(cl_int16 data);

	//: Writes an unsigned 16 bit integer to output source.
	virtual void write_uint16(cl_uint16 data);

	//: Writes a signed 8 bit integer to output source.
	virtual void write_int8(cl_int8 data);

	//: Writes an unsigned 8 bit integer to output source.
	virtual void write_uint8(cl_uint8 data);

	//: Writes a signed 16 bit integer (short) to output source.
	virtual void write_short16(short data);

	//: Writes an unsigned 16 bit integer (short) to output source.
	virtual void write_ushort16(unsigned short data);

	//: Writes a signed 8 bit integer (char) to output source.
	virtual void write_char8(char data);

	//: Writes an unsigned 8 bit integer (char) to output source.
	virtual void write_uchar8(unsigned char data);

	//: Writes an ieee format floating point to output source.
	virtual void write_float32(float data);

	//: Writes a bool to output source.
	virtual void write_bool8(bool data);

	//: Writes a string to the output source.
	//- <p>The binary format written to the output source is first an uint32 telling the length of the
	//- string, and then the string itself.</p>
	virtual void write_string(const std::string &str);

	//: Writes larger amounts of data (no endian and 64 bit conversion).
	//param data: Points to the array from which to write.
	//param size: Number of bytes to write.
	//return: Num bytes actually written.
	virtual int write(const void *data, int size) = 0;
	
	//: Opens the output source. By default, it is open.
	virtual void open() = 0;
	
	//: Closes the output source.
	virtual void close() = 0;

	//: Make a copy of the current outputsource, standing at the same position.
	//return: The copy of the output source.
	virtual CL_OutputSource *clone() = 0;

//! Implementation:
protected:
	bool little_endian_mode;
};

#endif
