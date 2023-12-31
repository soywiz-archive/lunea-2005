/*  $Id: inputsource_provider.h,v 1.17 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_inputsource_provider
#define header_inputsource_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
class CL_InputSource;

//: Class that provides input sources.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_InputSourceProvider is used to open inputsources. This can be from a
//- datafile where the inputsource is an index - or it a directory where the
//- files are the inputsources.</p>
class CL_InputSourceProvider
{
public:
//! Construction:
	//: Input Source Provider destructor.
	virtual ~CL_InputSourceProvider() { return; }

	//: Creates a file provider.
	//- <p>Input sources opened are considered as files.</p>
	//param path: Path where the files are located.
	//return: The file input provider created.
	static CL_InputSourceProvider *create_file_provider(const std::string &path);

	//: Creates a datafile provider.
	//- <p>Input sources are opened as indexes in the specified datafile.</p>
	//param filename: Name of the datafile to be used.
	//return: The datafile input provider created.
	static CL_InputSourceProvider *create_datafile_provider(const std::string &filename);

//! Overrideables:
	//: Opens an inputsource using the passed handle.
	//param handle: handle/index/filename/identier to the input source requested.
	//return: The opened input source.
	virtual CL_InputSource *open_source(const std::string &handle) = 0;

	//: Returns a copy of the current provider.
	//return: The copy of the inputsource provider.
	virtual CL_InputSourceProvider *clone() = 0;

	//: Get full path to source:
	virtual std::string get_pathname(const std::string &filename) = 0;

	//: Returns a new inputsource provider object that uses a new path relative to current one.
	virtual CL_InputSourceProvider *create_relative(const std::string &path) = 0;
};

#endif
