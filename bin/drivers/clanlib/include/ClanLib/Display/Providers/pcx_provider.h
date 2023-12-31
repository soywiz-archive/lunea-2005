/*  $Id: pcx_provider.h,v 1.11 2004/01/24 21:52:05 mbn Exp $
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

//! clanDisplay="Surface Providers"
//! header=display.h

#ifndef header_pcx_provider
#define header_pcx_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include "../pixel_buffer.h"
#include <string>

class CL_InputSourceProvider;

//: Surface provider that can load PCX files.
//- !group=Display/Surface Providers!
//- !header=display.h!
class CL_PCXProvider : public CL_PixelBuffer
{
//! Construction:
public:
	//: Constructs a surface provider that can read pcx files.
	//param name: Name of the pcx file to load.
	//param provider: Input source provider that delivers the pcx file.
	CL_PCXProvider(
		const std::string &name,
		CL_InputSourceProvider *provider = 0);
};

#endif
