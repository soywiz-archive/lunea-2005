/*  $Id: origin.h,v 1.6 2004/03/09 15:33:08 sphair Exp $
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

//! clanCore="Math"
//! header=core.h

#ifndef header_origin
#define header_origin

#if _MSC_VER > 1000
#pragma once
#endif

#include "size.h"
#include "point.h"

//: Alignment origins.
//- !group=Core/Math!
//- !header=core.h!
enum CL_Origin
{
	origin_top_left,
	origin_top_center,
	origin_top_right,
	origin_center_left,
	origin_center,
	origin_center_right,
	origin_bottom_left,
	origin_bottom_center,
	origin_bottom_right
};

//: Returns the anchor point for the origin within the dimensions of the size structure.
//- !group=Display/Display 2D!
//- !header=display.h!
CL_Point calc_origin(CL_Origin origin, const CL_Size &size);
CL_Pointf calc_origin(CL_Origin origin, const CL_Sizef &size);

#endif
