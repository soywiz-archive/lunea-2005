/*  $Id: jpeg_provider.h,v 1.10 2004/01/24 00:54:53 mbn Exp $
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

#ifndef header_jpeg_provider
#define header_jpeg_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include "../pixel_buffer.h"
#include <string>

class CL_InputSourceProvider;

//: Surface provider that can load JPEG (.jpg) files.
//- !group=Display/Surface Providers!
//- !header=display.h!
class CL_JPEGProvider : public CL_PixelBuffer
{
//! Construction:
public:
	//: Constructs a surface provider that can read JPEG files.
	//param name: Name of the JPEG file to load.
	//param provider: Input source provider that delivers the JPEG file.
	CL_JPEGProvider(
		const std::string &name, 
		CL_InputSourceProvider *provider = 0);
};

#endif
