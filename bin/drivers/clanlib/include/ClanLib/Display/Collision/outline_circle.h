/*  $Id: outline_circle.h,v 1.4 2004/04/20 13:36:27 sphair Exp $
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

#ifndef header_outline_circle
#define header_outline_circle

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../Core/Math/point.h"
#include <cmath>

//: Collision detection outline segmentation circle.
//- !group=Display/Collision !
//- !header=display.h!
//- <p>Outline circles split the line segments into groups for faster collision detection.
//- If two circles encapsulating the lines don't collide, none of the lines inside them can 
//- collide either. </p>
class CL_OutlineCircle
{
//! Construction:
 public:
	//: Construct a outline circle
	CL_OutlineCircle() :
		position(-1.0f,-1.0f),
		radius(0),
		start(-1),
		end(-1)
	{
		return;
	}
	
//! Operations:
 public:
	//: Construct a outline circle
	//param CL_OutlineCircle &other : Other circle to test.
	bool collide(const CL_OutlineCircle &other) const
	{
		if( &other == this )
			return false;

		CL_Pointf pos = position - other.position;
		float dist = (float) sqrt( pos.x*pos.x+pos.y*pos.y );	
		
		if( dist > (radius + other.radius) )
			return false;

		return true;
	}

//! Attributes:
 public:
	CL_Pointf position;
	float radius;
	int start;
	int end;
};

#endif
