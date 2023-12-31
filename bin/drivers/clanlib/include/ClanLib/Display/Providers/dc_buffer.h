/*  $Id: dc_buffer.h,v 1.9 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_dc_buffer
#define header_dc_buffer

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef WIN32
#include <windows.h>

#include "../pixel_buffer.h"

//: Win32 Device Context pixelbuffer.
//- !group=Display/Surface Providers!
//- !header=display.h!
//- <p>This is class is not crossplatform. It allows win32 applications to paint
//- to a pixelbuffer using device context system calls.</p>
class CL_DeviceContextBuffer : public CL_PixelBuffer
{
//! Construction:
public:
	//: Construct a pixelbuffer using the pixel format of the passed device context.
	CL_DeviceContextBuffer(HDC reference_dc, int width, int height, bool monocrome_alpha = false);

//! Attributes:
public:
	//: Returns device context of pixelbuffer.
	HDC get_dc();

//! Implementation:
private:
};

#endif

#endif
