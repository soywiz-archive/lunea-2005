/*  $Id: outputsource_zipped.h,v 1.15 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_outputsource_zipped
#define header_outputsource_zipped

#if _MSC_VER > 1000
#pragma once
#endif

#include "outputsource.h"

class CL_OutputSource_Zipped_Generic;

//: Zlib compressed output source.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_OutputSource_Zipped_Generic provides write access to compress files while internally
//-  dealing with endianess.</p>
//- <p>CL_OutputSource_Zipped_Generic should not be instantiated directly, but
//- rather CL_OutputSourceProvider should create the appropriate output source.</p>

class CL_OutputSource_Zipped : public CL_OutputSource
{
//! Construction:
public:
	//: Constructs an output source that zips the data and passes it on to
	//: the passed output source.
	//- <p>If delete_output is true, the zipped output source will delete the
	//- output source at destruction.</p>
	CL_OutputSource_Zipped(CL_OutputSource *output, bool delete_output = false);

	CL_OutputSource_Zipped(const CL_OutputSource_Zipped &copy);

	//: Destructor.
	virtual ~CL_OutputSource_Zipped();

//! Attributes:
public:
	//: Returns current position in output source.
	//return: Current position in source.
	virtual int tell() const;

	//: Returns the size of the output source
	//return: Size of the output source.
	virtual int size() const;

//! Operations:
public:
	//: Writes larger amounts of data (no endian and 64 bit conversion):
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
	CL_OutputSource_Zipped_Generic *impl;
};

#endif
