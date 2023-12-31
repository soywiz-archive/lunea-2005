/*  $Id: point.h,v 1.26 2004/04/06 21:59:49 mbn Exp $
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

#ifndef header_point
#define header_point

#if _MSC_VER > 1000
#pragma once
#endif

#include "math.h"

//: 2D (x,y) point structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Point
{
// Construction:
public:
	//: Constructs a point.
	//param x: Initial x value.
	//param y: Initial y value.
	//param p: Point to use for initial values.
	CL_Point()
	{ return; }

	CL_Point(int x, int y)
	: x(x), y(y) { }

	CL_Point(const CL_Point &p)
	{ x = p.x; y = p.y; }

// Operations:
public:
	//: Return a rotated version of this point.
	//param hotspot: The point around which to rotate.
	//param angle: The amount of degrees to rotate by, clockwise.
	CL_Point rotate(
		const CL_Point &hotspot,
		float angle) const
	{
		//Move the hotspot to 0,0
		CL_Point r(x - hotspot.x, y - hotspot.y);
		
		//Do some Grumbel voodoo.

		// Because MSVC sucks ass wrt standards compliance, it gets it own special function calls
		#ifdef _MSC_VER
		const float c = (float) sqrt((float)r.x*(float)r.x + (float)r.y*(float)r.y);
		const float nw = (float)(atan2((float)r.y, (float)r.x) + ((angle + 180) * M_PI / 180));
		r.x = (int)((sin(1.5 * M_PI - nw) * c) + 0.5) + hotspot.x;
		r.y = -(int)((sin(nw) * c) + 0.5) + hotspot.y;
		#else
		const float c = (float) std::sqrt((float)r.x*(float)r.x + (float)r.y*(float)r.y);
		const float nw = (float)(std::atan2((float)r.y, (float)r.x) + ((angle + 180) * M_PI / 180));
 		r.x = (int)((std::sin(1.5 * M_PI - nw) * c) + 0.5) + hotspot.x;
		r.y = -(int)((std::sin(nw) * c) + 0.5) + hotspot.y;
		#endif

		return r;
	}

	//: Return the distance to another point.
	//param CL_Point &p: The other point.
	int distance( const CL_Point &p ) const
	{
		#ifdef _MSC_VER
    	return int(sqrt(double((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y))) + 0.5f);
		#else
    	return int(std::sqrt(double((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y))) + 0.5f);
		#endif
	}
	
	//: Translate point.
	CL_Point &operator+=(const CL_Point &p)
	{ x += p.x; y += p.y; return *this; }

	//: Translate point negatively.
	CL_Point &operator-=(const CL_Point &p)
	{ x -= p.x; y -= p.y; return *this; }
	
	//: Point + Point operator.
	CL_Point operator+(const CL_Point &p) const
	{ return CL_Point(x + p.x, y + p.y); }

	//: Point - Point operator.
	CL_Point operator-(const CL_Point &p) const
	{ return CL_Point(x - p.x, y - p.y); }

	//: Point == Point operator (deep compare)
	bool operator==(const CL_Point &p) const
	{ return (x == p.x) && (y == p.y); }

	//: Point != Point operator (deep compare)
	bool operator!=(const CL_Point &p) const
	{ return (x != p.x) || (y != p.y); }

// Attributes:
public:
	//: X coordinate.
	int x;

	//: Y coordinate.
	int y;
};

//: 2D (x,y) floating point point structure.
class CL_Pointf
{
// Construction:
public:
	//: Constructs a point.
	//param x: Initial x value.
	//param y: Initial y value.
	//param p: Point to use for initial values.
	CL_Pointf()
	{ return; }
	
	CL_Pointf(float x, float y)
	: x(x), y(y) { }
	
	CL_Pointf(const CL_Pointf &p)
	{ x = p.x; y = p.y; }
	
// Operations:
public:
	//: Return a rotated version of this point.
	//param hotspot: The point around which to rotate.
	//param angle: The amount of degrees to rotate by, clockwise.
	CL_Pointf rotate(
		const CL_Pointf &hotspot,
		float angle) const
	{
		//Move the hotspot to 0,0
		CL_Pointf r(x - hotspot.x, y - hotspot.y);
		
		//Do some Grumbel voodoo.
		// MSVC is doesn't recognize std::sin and friends
		#ifdef _MSC_VER
		const float c = (float)(sqrt(r.x*r.x + r.y*r.y));

		const float nw = (float)((float)atan2(r.y, r.x) + ((angle + 180) * M_PI / 180));

		r.x = ((float)(sin(1.5 * M_PI - nw)) * c) + hotspot.x;
		r.y = -((float)(sin(nw)) * c) + hotspot.y;
		#else
 		const float c = (float)(std::sqrt(r.x*r.x + r.y*r.y));

		const float nw = (float)((float)std::atan2(r.y, r.x) + ((angle + 180) * M_PI / 180));

		r.x = ((float)(std::sin(1.5 * M_PI - nw)) * c) + hotspot.x;
		r.y = -((float)(std::sin(nw)) * c) + hotspot.y;
		#endif
		
		return r;
	}

	//: Return the distance to another point.
	//param CL_Pointf &p: The other point.
	float distance( const CL_Pointf &p ) const
	{
		#ifdef _MSC_VER
    	return (float) sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
		#else
    	return std::sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
		#endif
	}
	
	//: Translate point.
	CL_Pointf &operator+=(const CL_Pointf &p)
	{ x += p.x; y += p.y; return *this; }
	
	//: Translate point negatively.
	CL_Pointf &operator-=(const CL_Pointf &p)
	{ x -= p.x; y -= p.y; return *this; }
	
	//: Point + Point operator.
	CL_Pointf operator+(const CL_Pointf &p) const
	{ return CL_Pointf(x + p.x, y + p.y); }

	//: Point - Point operator.
	CL_Pointf operator-(const CL_Pointf &p) const
	{ return CL_Pointf(x - p.x, y - p.y); }

	//: Point == Point operator (deep compare)
	bool operator==(const CL_Pointf &p) const
	{ return (x == p.x) && (y == p.y); }

	//: Point != Point operator (deep compare)
	bool operator!=(const CL_Point &p) const
	{ return (x != p.x) || (y != p.y); }

// Attributes:
public:
	//: X coordinate.
	float x;
	
	//: Y coordinate.
	float y;
};

#endif
