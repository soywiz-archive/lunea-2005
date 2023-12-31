/*  $Id: outline_provider_bitmap.h,v 1.2 2004/04/05 09:51:58 sphair Exp $
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

//! clanDisplay="Collision"
//! header=display.h

#ifndef header_outline_provider_bitmap
#define header_outline_provider_bitmap

#if _MSC_VER > 1000
#pragma once
#endif

#include <vector>
#include <string>

#include "outline_provider.h"
#include "outline_accuracy.h"

class CL_OutlineProviderBitmap_Generic;
class CL_PixelBuffer;

//: Bitmap outline provider.
//- !group=Display/Collision !
//- !header=display.h!
//- <p>A CL_OutlineProviderBitmap is used to find outlines based on the alpha channel of images.</p>
class CL_OutlineProviderBitmap : public CL_OutlineProvider
{
//! Construction:
 public:
	//: Construct a contour
	//param CL_PixelBuffer *pbuf : PixelBuffer containing image data.
	//param int alpha_limit : Minimum alpha value for a colliding pixel
	CL_OutlineProviderBitmap(CL_PixelBuffer *pbuf, int alpha_limit=128);
	~CL_OutlineProviderBitmap();

//! Attributes:
 public:
	//: return the countours that make up the outline
	virtual std::vector<CL_Contour> get_contours();

	//: return the width of the image used as basis for outline creation.
	virtual int get_width();

	//: return the height of the image used as basis for outline creation.
	virtual int get_height();

//! Implementation:
 private:
	CL_OutlineProviderBitmap_Generic *impl;
};

#endif
