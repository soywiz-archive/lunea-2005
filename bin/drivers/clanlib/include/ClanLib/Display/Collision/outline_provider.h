/*  $Id: outline_provider.h,v 1.2 2004/04/05 09:51:58 sphair Exp $
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

#ifndef header_outline_provider
#define header_outline_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include "contour.h"

//: Collision detection contour.
//- !group=Display/Collision !
//- !header=display.h!
//- <p>Abstract Base class for outline providers. Don't use this!</p>
class CL_OutlineProvider
{
//! Construction:
 public:
	//: Construct a outline provider
	CL_OutlineProvider() {};
	virtual ~CL_OutlineProvider() {}; 

//! Attributes:
 public:
	//: return the countours that make up the outline
	virtual std::vector<CL_Contour> get_contours()=0;

	//: return the width of the image used as basis for outline creation, or -1 when loading a precompiled outline.
	virtual int get_width()=0;

	//: return the height of the image used as basis for outline creation, or -1 when loading a precompiled outline.
	virtual int get_height()=0;
};

#endif
