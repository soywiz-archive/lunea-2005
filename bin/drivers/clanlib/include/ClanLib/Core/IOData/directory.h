/*  $Id: directory.h,v 1.6 2004/01/07 11:22:57 sphair Exp $
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

#ifndef header_directory
#define header_directory

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

//: Directory utility class
//- !group=Core/IO Data!
//- !header=core.h!
class CL_Directory
{
//! Operations:
public:
	//: Create directory.
	//- <p>return true on success or false on error.</p>
	//param dir_name: Directory name for create.
	static bool create(const std::string &dir_name);

	//: Remove directory.
	//- <p>Return true on success or false on error.</p>
	//param dir_name: Directory name for delete.
	//param delete_files: If true, function will delete files.
	//param delete_sub_directoies: If true, function will delete
	//param delete_sub_directoies: sub directoies too.
	static bool remove(
		const std::string &dir_name,
		bool delete_files = false,
		bool delete_sub_directories = false);

	//: Change current directory.
	//- <p>Return true on success or false on error.</p>
	//param path: Directory name to change to.
	static bool change_to(const std::string &path);

	//: Get current directory.
	//- <p>Returns the current directory path.</p>
	static std::string get_current();
};

#endif // header_directory
