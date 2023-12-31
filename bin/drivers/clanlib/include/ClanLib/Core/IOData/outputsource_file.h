/*  $Id: outputsource_file.h,v 1.15 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_outputsource_file
#define header_outputsource_file

#if _MSC_VER > 1000
#pragma once
#endif

#include "outputsource.h"

#include <string>
#include <stdio.h>

//: Outputsource writing to file.         
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_OutputSource_File provides write access to files while internally dealing with endianess.
//- CL_OutputSource_File should not be instantiated directly, but 
//- rather CL_OutputSourceProvider should create the appropriate output source.</p>
class CL_OutputSource_File : public CL_OutputSource
{
//! Construction:
public:
	//: Construct file output source.
	//param file: Filename of file that the output source will use as destination.
	CL_OutputSource_File(const std::string &file);

	CL_OutputSource_File();

	//: Output Source File destructor.
	virtual ~CL_OutputSource_File();

//! Attributes:
public:
	//: Returns current position in output source.
	//return: Current position in source.
	virtual int tell() const;

	//: Returns the size of the output source.
	//return: Current size of output source.
	virtual int size() const;

//! Operations:
public:
	//: Writes larger amounts of data (no endian and 64 bit conversion):
	//param data: Points to the array written.
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
	unsigned int pos;
	FILE *file;
	std::string filename;
};

#endif
