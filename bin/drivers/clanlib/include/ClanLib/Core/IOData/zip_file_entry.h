/*  $Id: zip_file_entry.h,v 1.8 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_zip_file_entry
#define header_zip_file_entry

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include "datatypes.h"

class CL_Zip_FileEntry_Generic;

//: File entry in zip file.
//- !group=Core/IO Data!
//- !header=core.h!
class CL_Zip_FileEntry
{
//! Construction:
public:
	CL_Zip_FileEntry();
	
	CL_Zip_FileEntry(const CL_Zip_FileEntry &copy);
	
	~CL_Zip_FileEntry();

//! Attributes:
public:
	//: Returns the filename of file entry.
	const std::string & get_filename() const;
	
	//: Returns the uncompressed size of file entry.
	cl_int64 get_uncompressed_size();
	
	//: Returns the compressed size of file entry.
	cl_int64 get_compressed_size();

//! Operations:
public:
	//: Copy assignment operator.
	CL_Zip_FileEntry &operator =(const CL_Zip_FileEntry &copy);
	
	//: Sets the filename of file entry.
	void set_filename(const std::string &filename);

//! Implementation:
private:
	CL_Zip_FileEntry_Generic *impl;
	friend class CL_Zip_Archive;
	friend class CL_InputSource_Zip_FileEntry;
};

#endif
