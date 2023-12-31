/*  $Id: directory_scanner.h,v 1.23 2004/02/01 02:06:28 mbn Exp $
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

#ifndef header_directory_scanner
#define header_directory_scanner

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"
#include <string>

class CL_DirectoryScanner_Generic;

//: Directory scanning class.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_DirectoryScanner is used to parse through directory trees and return information about files.</p>
//-
//- <p>Example that prints all files and directories found in the root directory:</p>
//- <pre>
//- CL_DirectoryScanner scanner;
//- if (scanner.scan("/", "*"))
//- {
//- 		while (scanner.next())
//- 		{
//- 				std::cout << scanner.get_name() << std::endl;
//- 		}
//- }
//- </pre>
class CL_DirectoryScanner
{
//! Construction:
public:
	//: Constructs directory scanner for iterating over a directory.
	CL_DirectoryScanner();

	CL_DirectoryScanner(const CL_DirectoryScanner &copy);

	//: Destructor.
	~CL_DirectoryScanner();

//! Attributes:
public:
	//: Gets the directory being scanned.
	//return: Directory being scanned.
	std::string get_directory_path();

	//: Gets the name of the current file.
	//return: The name of the current found file.
	std::string get_name();

	//: Gets the size of the current file.
	//return: The size of the current found file.
	int get_size();

	//: Gets the pathname of the current file.
	//return: The name of the current found file, including the directory path.
	std::string get_pathname();

	//: Returns true if the current file is a directory.
	//return: True if filename is a directory.
	bool is_directory();

	//: Returns true if the file is hidden.
	//return: True if filename is hidden.
	bool is_hidden();

	//: Returns true if the file is readable by the current user.
	//return: True if the file is readable.
	bool is_readable();

	//: Returns true if the file is writable by the current user.
	//return: True if the file is writable.
	bool is_writable();

//! Operations:
public:       
	//: Selects the directory to scan through.
	//- <p>Selects the directory to scan through and use a matching pattern on the files.
	//The pattern is normal DOS pattern matching (*.*).</p>
	//param pathname: Path to the directory to scan.
	//param pattern: Pattern to match files against.
	//return: true if the directory can be accessed.
	bool scan(const std::string& pathname);

	bool scan(const std::string& pathname, const std::string& pattern);

	//: Find next file in directory scan. 
	//return: false if no more files was found.
	bool next();

//! Implementation:
private:
	// Yada yada, usual data hiding.
	CL_SharedPtr<CL_DirectoryScanner_Generic> impl;
};

#endif
