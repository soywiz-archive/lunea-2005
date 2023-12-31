/*  $Id: rle_surface.h,v 1.11 2004/01/02 15:42:43 mbn Exp $
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

//! clanDisplay="Display 2D"
//! header=display.h

#ifndef header_rle_surface
#define header_rle_surface

#if _MSC_VER > 1000
#pragma once
#endif

class CL_PixelBuffer;
class CL_GraphicContext;
class CL_InputSource;
class CL_OutputSource;
class CL_RLESurface_Generic;

//: Runlength encoded surface.
//- !group=Display/Display 2D!
//- !header=display.h!
class CL_RLESurface
{
//! Construction:
public:
	//: Constructs a run length encoded surface.
	//param provider: Pixel buffer containing image data to be used for constructing RLE surface.
	//param delete_provider: If true, deletes the provider after copying its image data.
	//param input: Input source to load a surface in encoded form.
	CL_RLESurface(CL_PixelBuffer *provider, bool delete_provider = false);

	CL_RLESurface(CL_InputSource *input);

//! Operations:
public:
	//: Draw surface on screen.
	void put_screen(int x, int y, CL_GraphicContext *context = 0);

	//: Draw surface onto pixel buffer.
	void blit(int x, int y, CL_PixelBuffer *buffer);

	//: Save surface in encoded form to an output source.
	void save(CL_OutputSource *output);

//! Implementation:
private:
//	CL_RLESurface_Generic *impl;
};

#endif
