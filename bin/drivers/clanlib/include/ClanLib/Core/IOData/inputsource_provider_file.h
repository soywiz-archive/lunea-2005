/*  $Id: inputsource_provider_file.h,v 1.15 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_inputsource_provider_file
#define header_inputsource_provider_file

#if _MSC_VER > 1000
#pragma once
#endif

#include "inputsource_provider.h"
#include <string>

class CL_InputSource;

//: The Input Source Provider File Class    
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_InputSourceProvider_File is a subclass of CL_InputSourceProvider.
//- It provides a way to treat normal files as input sources and to read and write them 
//- in a endian transparent manner.</p>

class CL_InputSourceProvider_File : public CL_InputSourceProvider
{
//! Construction:
public:
	//: Construtcs a file input source provider.
	//param path: File to create a source for.
	CL_InputSourceProvider_File(const std::string &path);

	//: Open input source using file as its source.
	//param filename: Filename to open.
	//return: InputSource for the file.
	virtual CL_InputSource *open_source(const std::string &filename);

	//: Get full path to source:
	virtual std::string get_pathname(const std::string &filename);

	//: Returns a new inputsource provider object that uses a new path relative to current one.
	virtual CL_InputSourceProvider *create_relative(const std::string &path);

	//: Clone the provider.
	//- <p>Creates a new instance of the class with the same internal data.
	//- This is equivaled to <i>new CL_InputSourceProvider_File(get_path())</i>.</p>
	//return: New instance of the current provider.
	virtual CL_InputSourceProvider *clone();

//! Implementation:
private:
	std::string provider_path;
};

#endif
