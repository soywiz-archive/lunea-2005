/*  $Id: gradient.h,v 1.4 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_gradient
#define header_gradient

#if _MSC_VER > 1000
#pragma once
#endif

#include "color.h"

//: Colorgradient description class.
//- !group=Display/Display 2D!
//- !header=display.h!
class CL_Gradient
{
//! Construction:
public:
	//: Constructs a color gradient.
	//param top_left: Top left color component.
	//param top_right: Top right color component.
	//param bottom_left: Bottom left color component.
	//param bottom_right: Bottom right color component.
	CL_Gradient() { return; }

	CL_Gradient(const CL_Color &top_left, const CL_Color &top_right, const CL_Color &bottom_left, const CL_Color &bottom_right)
		: top_left(top_left), top_right(top_right), bottom_left(bottom_left), bottom_right(bottom_right) { return; }

//! Attributes:
public:
	CL_Color top_left;
	CL_Color top_right;
	CL_Color bottom_left;
	CL_Color bottom_right;
};

#endif
