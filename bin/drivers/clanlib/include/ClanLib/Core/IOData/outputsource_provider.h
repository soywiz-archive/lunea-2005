/*  $Id: outputsource_provider.h,v 1.14 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_outputsource_provider
#define header_outputsource_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_OutputSource;

//: Class that provides output targets.
//- !group=Core/IO Data!
//- !header=core.h!
//- <p>CL_OutputSourceProvider is used to open output sources. This can be from a
//- datafile where the outputsource is an index - or it a directory where the
//- files are the outputsources.</p>
class CL_OutputSourceProvider
{
public:
//! Overrideables:
	//: Output Source Provider destructor.
	virtual ~CL_OutputSourceProvider() { return; }

	//: Opens an outputsource using the passed handle.
	//param handle: handle/index/filename/identier to the output source requested.
	//return: The output source opened.
	virtual CL_OutputSource *open_source(const std::string &handle) = 0;

	//: Returns a copy of the current provider.
	//return: The copy of the outputsource provider.
	virtual CL_OutputSourceProvider *clone() = 0;
};

#endif
