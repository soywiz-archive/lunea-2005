/*  $Id: contour.h,v 1.2 2004/04/05 09:51:58 sphair Exp $
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

#ifndef header_contour
#define header_contour

#if _MSC_VER > 1000
#pragma once
#endif

#include <vector>
#include "outline_circle.h"

//: Collision detection contour.
//- !group=Display/Collision !
//- !header=display.h!
//- <p>A outline consists of contours, which hold the actual outline geometry</p>
class CL_Contour
{
//! Construction:
 public:
	//: Construct a contour
	CL_Contour() {};
	~CL_Contour() {};

//! Attributes:
 public:
	// Points forming the countour.
	std::vector<CL_Pointf> points;

	// Circles encapsulating a part of the outline.
	// If two circles arent intersecting, none of the lines inside them
	// collide either.
	std::vector<CL_OutlineCircle> sub_circles;
};

#endif
