/*  $Id: quad.h,v 1.1 2004/04/20 13:36:26 sphair Exp $
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

#ifndef header_quad
#define header_quad

#if _MSC_VER > 1000
#pragma once
#endif

#include "rect.h"
#include "size.h"
#include "point.h"
#include "origin.h"

//: 2D (x1, y1, x2, y2, x3, y3, x4, y4) quad structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Quad
{
//! Construction:
public:
	//: Constructs a quad.
	//param x1: x-coord for first point of quad.
	//param y1: y-coord for first point of quad.
	//param x2: x-coord for second point of quad.
	//param y2: y-coord for second of quad.
	//param x3: x-coord for third point of quad.
	//param y3: y-coord for third point of quad.
	//param x4: x-coord for forth point of quad.
	//param y4: y-coord for forth point of quad.
	//param rect: Rectangle used to initialize the quad.
	CL_Quad() { return; }

	CL_Quad(int new_x1, int new_y1, int new_x2, int new_y2,
		int new_x3, int new_y3, int new_x4, int new_y4)
	{ x1 = new_x1; y1 = new_y1; x2 = new_x2; y2 = new_y2; 
		x3 = new_x3; y3 = new_y3; x4 = new_x4; y4 = new_y4; 
	}

	CL_Quad(const CL_Rect &rect)
	{ x1 = rect.left; y1 = rect.top; x2 = rect.right; y2 = rect.top; 
		x3 = rect.right; y3 = rect.bottom; x4 = rect.left; y4 = rect.bottom; 
	}

	CL_Quad(const CL_Quad &q)
	{ x1 = q.x1; y1 = q.y1; x2 = q.x2; y2 = q.y2; 
		x3 = q.x3; y3 = q.y3; x4 = q.x4; y4 = q.y4; 
	}

	//: Quad += Quad operator.
	CL_Quad &operator+=(const CL_Quad &q)
	{ x1 += q.x1; y1 += q.y1; x2 += q.x2; y2 += q.y2; 
		x3 += q.x3; y3 += q.y3; x4 += q.x4; y4 += q.y4; 
		return *this;
	}

	//: Quad -= Quad operator.
	CL_Quad &operator-=(const CL_Quad &q)
	{ x1 -= q.x1; y1 -= q.y1; x2 -= q.x2; y2 -= q.y2; 
		x3 -= q.x3; y3 -= q.y3; x4 -= q.x4; y4 -= q.y4; 
		return *this;
	}
	
	//: Quad += Point operator.
	CL_Quad &operator+=(const CL_Point &p)
	{ x1 += p.x; y1 += p.y; x2 += p.x; y2 += p.y; 
		x3 += p.x; y3 += p.y; x4 += p.x; y4 += p.y; 
		return *this;
	}

	//: Quad -= Point operator.
	CL_Quad &operator-=(const CL_Point &p)
	{ x1 -= p.x; y1 -= p.y; x2 -= p.x; y2 -= p.y; 
		x3 -= p.x; y3 -= p.y; x4 -= p.x; y4 -= p.y; 
		return *this;
	}

	//: Quad + Quad operator.
	CL_Quad operator+(const CL_Quad &q) const
	{ return CL_Quad(x1 + q.x1, y1 + q.y1, x2 + q.x2, y2 + q.y2,
		x3 + q.x3, y3 + q.y3, x4 + q.x4, y4 + q.y4); }

	//: Quad - Quad operator.
	CL_Quad operator-(const CL_Quad &q) const
	{ return CL_Quad(x1 - q.x1, y1 - q.y1, x2 - q.x2, y2 - q.y2,
		x3 - q.x3, y3 - q.y3, x4 - q.x4, y4 - q.y4); }

	//: Quad + Point operator.
	CL_Quad operator+(const CL_Point &p) const
	{ return CL_Quad(x1 + p.x, y1 + p.y, x2 + p.x, y2 + p.y,
		x3 + p.x, y3 + p.y, x4 + p.x, y4 + p.y); }

	//: Quad - Point operator.
	CL_Quad operator-(const CL_Point &p) const
	{ return CL_Quad(x1 - p.x, y1 - p.y, x2 - p.x, y2 - p.y,
		x3 - p.x, y3 - p.y, x4 - p.x, y4 - p.y); }

	//: Quad == Quad operator.
	bool operator==(const CL_Quad &q) const
	{ return (x1 == q.x1 && y1 == q.y1 && x2 == q.x2 && y2 == q.y2 &&
		x3 == q.x3 && y3 == q.y3 && x4 == q.x4 && y4 == q.y4); }

	//: Quad != Quad operator.
	bool operator!=(const CL_Quad &q) const
	{ return (x1 != q.x1 || y1 != q.y1 || x2 != q.x2 || y2 != q.y2 ||
		x3 != q.x3 || y3 != q.y3 || x4 != q.x4 || y4 != q.y4); }

//! Attributes:
public:
	//: X1-coordinate.
	int x1;
	
	//: Y1-coordinate.
	int y1;
	
	//: X2-coordinate.
	int x2;
	
	//: Y2-coordinate.
	int y2;
	
	//: X3-coordinate.
	int x3;
	
	//: Y3-coordinate.
	int y3;
	
	//: X4-coordinate.
	int x4;
	
	//: Y4-coordinate.
	int y4;
	
	//: Returns the width of the quad.
	int get_width() const;
	
	//: Returns the height of the quad.
	int get_height() const;

	//: Returns the size of the rectangle.
	CL_Size get_size() const { return CL_Size(get_width(), get_height()); }
	
	//: Returns the bounding box of the quad as a CL_Rect
	//param hotspot: Point to rotate around.
	//param origin: Determines the hotspot point within the rectangle
	//param x, y: Offsets applied negatively to the hotspot point
	//param angle: Angle to rotate in degrees.
	CL_Rect get_bounds() const;
	
//! Operations:
public:
	//: Rotates the Quad
	//param hotspot: Point to rotate around.
	//param angle: Angle to rotate in degrees.
	void rotate(const CL_Point &hotspot, float angle);
	
	//: Scale the Quad
	//param sx: Scale value in x-axis
	//param sy: Scale value in y-axis
	//param hotspot: Point to scale around.
	void scale(float sx, float sy);
	void scale(const CL_Point &hotspot, float sx, float sy);
	
	//: Returns the center point of the quad
	CL_Point center() const;
	
	//: Applies an origin and offset pair to this rectangle
	//param origin: The new origin to adjust to from default upper-left position
	//param x, y: Offsets applied negatively to each corner of the rectangle
	void apply_alignment(CL_Origin origin, int x, int y)
	{
		CL_Point offset = calc_origin(origin, get_size());
		offset.x -= x;
		offset.y -= y;
		
		x1 += offset.x;
		y1 += offset.y;
		x2 += offset.x;
		y2 += offset.y;
		x3 += offset.x;
		y3 += offset.y;
		x4 += offset.x;
		y4 += offset.y;
	}
};

#endif
