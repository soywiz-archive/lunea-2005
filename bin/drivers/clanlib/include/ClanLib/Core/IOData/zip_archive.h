/*  $Id: zip_archive.h,v 1.8 2004/02/01 03:07:16 mbn Exp $
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

#ifndef header_zip_archive
#define header_zip_archive

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"
#include "zip_file_entry.h"
#include "inputsource_provider.h"

class CL_InputSource;
class CL_OutputSource;
class CL_Zip_Archive_Generic;

//: Zip archive.
//- !group=Core/IO Data!
//- !header=core.h!
class CL_Zip_Archive : public CL_InputSourceProvider
{
//! Construction:
public:
	//: Constructs or loads a ZIP archive.
	//param filename: .zip archive to load.
	CL_Zip_Archive();
	
	CL_Zip_Archive(const std::string &filename);
	
	CL_Zip_Archive(const CL_Zip_Archive &copy);
	
	~CL_Zip_Archive();

//! Attributes:
public:
	//: List of file entries in archive.
	std::vector<CL_Zip_FileEntry> &get_file_list();

//! Operations:
public:
	//: Opens a file in the archive.
	CL_InputSource *open_source(const std::string &filename);
	
	//: Clones this input source provider.
	CL_InputSourceProvider *clone();

	//: Get full path to source:
	std::string get_pathname(const std::string &filename);

	//: Returns a new inputsource provider object that uses a new path relative to current one.
	CL_InputSourceProvider *create_relative(const std::string &path);

	//: Creates a new file entry
	CL_OutputSource *create_file(const std::string &filename, bool compress = true);

	//: Adds a file to zip archive.
	//- <p>File is not added to zip file until it save() is called.</p>
	//param filename: Filename of file.
	void add_file(const std::string &filename, bool compress = true);

	//: Saves zip archive.
	//param filename: Filename of zip archive. Must not be used to save to the same as loaded from.
	//- <p>If no filename parameter was passed, it will modify the zip
	//- archive loaded at construction time. It does this by creating a
	//- temporary file, saving the new archive, deletes the old one and
	//- renames the temp file to the original archive filename.</p>
	//-
	//- <p>If the archive was created instead of loaded, a filename must
	//- be specify a filename. Likewise, if saving to same archive as
	//- loaded from, a filename must not be specified. Doing so will
	//- cause the save operation to fail.</p>
	void save();
	
	void save(const std::string &filename);

//! Implementation:
private:
	CL_SharedPtr<CL_Zip_Archive_Generic> impl;
};

#endif
