/*  $Id: rect.h,v 1.43 2004/01/21 00:22:42 mbn Exp $
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

#ifndef header_rect
#define header_rect

#if _MSC_VER > 1000
#pragma once
#endif

#include "size.h"
#include "point.h"
#include "origin.h"

//: 2D (left,top,right,bottom) rectangle structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Rect
{
//! Construction:
public:
	//: Constructs an rectangle.
	//param left: Initial left position of rectangle.
	//param top: Initial top position of rectangle.
	//param right: Initial right position of rectangle.
	//param bottom: Initial bottom position of rectangle.
	//param point: Initial top-left position of rectangle.
	//param size: Initial size of rectangle.
	//param rect: Initial rectangle position and size.
	CL_Rect() { return; }

	CL_Rect(int new_left, int new_top, int new_right, int new_bottom)
	{ left = new_left; top = new_top; right = new_right; bottom = new_bottom; }

	CL_Rect(const CL_Point &p, const CL_Size &size)
	{ left = p.x; top = p.y; right = left + size.width; bottom = top + size.height; }

	CL_Rect(const CL_Rect &rect)
	{ left = rect.left; top = rect.top; right = rect.right; bottom = rect.bottom; }

	//: Rect += Rect operator.
	CL_Rect &operator+=(const CL_Rect &r)
	{ left += r.left; top += r.top; right += r.right; bottom += r.bottom; return *this; }

	//: Rect -= Rect operator.
	CL_Rect &operator-=(const CL_Rect &r)
	{ left -= r.left; top -= r.top; right -= r.right; bottom -= r.bottom; return *this; }
	
	//: Rect += Point operator.
	CL_Rect &operator+=(const CL_Point &p)
	{ left += p.x; top += p.y; right += p.x; bottom += p.y; return *this; }

	//: Rect -= Point operator.
	CL_Rect &operator-=(const CL_Point &p)
	{ left -= p.x; top -= p.y; right -= p.x; bottom -= p.y; return *this; }

	//: Rect + Rect operator.
	CL_Rect operator+(const CL_Rect &r) const
	{ return CL_Rect(left + r.left, top + r.top, right + r.right, bottom + r.bottom); }

	//: Rect - Rect operator.
	CL_Rect operator-(const CL_Rect &r) const
	{ return CL_Rect(left - r.left, top - r.top, right - r.right, bottom - r.bottom); }

	//: Rect + Point operator.
	CL_Rect operator+(const CL_Point &p) const
	{ return CL_Rect(left + p.x, top + p.y, right + p.x, bottom + p.y); }

	//: Rect - Point operator.
	CL_Rect operator-(const CL_Point &p) const
	{ return CL_Rect(left - p.x, top - p.y, right - p.x, bottom - p.y); }

	//: Rect == Rect operator.
	bool operator==(const CL_Rect &r) const
	{ return (left == r.left && top == r.top && right == r.right && bottom && r.bottom); }

	//: Rect != Rect operator.
	bool operator!=(const CL_Rect &r) const
	{ return (left != r.left || top != r.top || right != r.right || bottom != r.bottom); }

//! Attributes:
public:
	//: X1-coordinate.
	int left;
	
	//: Y1-coordinate.
	int top;
	
	//: X2-coordinate.
	int right;
	
	//: Y2-coordinate.
	int bottom;
	
	//: Returns the width of the rectangle.
	int get_width() const { return right - left; }
	
	//: Returns the height of the rectangle.
	int get_height() const { return bottom - top; }

	//: Returns the size of the rectangle.
	CL_Size get_size() const { return CL_Size(right - left, bottom - top); }
	
	//: Returns true if point is inside the rectangle.
	bool is_inside(const CL_Point &p) const { return (p.x >= left && p.y >= top && p.x <= right && p.y <= bottom); }

	//: Returns true if rectangle passed is overlapping or inside this rectangle.
	bool is_overlapped(const CL_Rect &r) const 
	{
		return (r.left < right && r.right > left && r.top < bottom && r.bottom > top);
	}
	
	//: Returns another CL_Rect containing a rotated version of this one.
	//param hotspot: Point to rotate around.
	//param origin: Determines the hotspot point within the rectangle
	//param x, y: Offsets applied negatively to the hotspot point
	//param angle: Angle to rotate in degrees.
	CL_Rect get_rot_bounds(const CL_Point &hotspot, float angle) const;
	CL_Rect get_rot_bounds(CL_Origin origin, int x, int y, float angle) const;
	
//! Operations:
public:
	//: Sets the size of the rectangle, maintaining top/left position.
	void set_size(const CL_Size &size)
	{
		right = left + size.width;
		bottom = top + size.height;
	}

	//: Calculates and returns the union of two rectangles.
	CL_Rect calc_union(const CL_Rect &rect)
	{
		CL_Rect result;
		if (left   > rect.left)   result.left   = left;   else result.left   = rect.left;
		if (right  < rect.right)  result.right  = right;  else result.right  = rect.right;
		if (top    > rect.top)    result.top    = top;    else result.top    = rect.top;
		if (bottom < rect.bottom) result.bottom = bottom; else result.bottom = rect.bottom;
		return result;
	}

	//: Normalize rectangle. Ensures that left is less than right and top is less than bottom.
	void normalize()
	{
		if (left > right)
		{
			int temp = right;
			right = left;
			left = temp;
		}

		if (top > bottom)
		{
			int temp = bottom;
			bottom = top;
			top = temp;
		}
	}
	
	//: Applies an origin and offset pair to this rectangle
	//param origin: The new origin to adjust to from default upper-left position
	//param x, y: Offsets applied negatively to each corner of the rectangle
	void apply_alignment(CL_Origin origin, int x, int y)
	{
		CL_Point offset = calc_origin(origin, get_size());
		offset.x -= x;
		offset.y -= y;
		
		left += offset.x;
		top += offset.y;
		right += offset.x;
		bottom += offset.y;
	}
};

//: 2D (left,top,right,bottom) floating point rectangle structure.
class CL_Rectf
{
//! Construction:
public:
	//: Constructs an rectangle.
	//param left: Initial left position of rectangle.
	//param top: Initial top position of rectangle.
	//param right: Initial right position of rectangle.
	//param bottom: Initial bottom position of rectangle.
	//param point: Initial top-left position of rectangle.
	//param size: Initial size of rectangle.
	//param rect: Initial rectangle position and size.
	CL_Rectf() { return; }

	CL_Rectf(float new_left, float new_top, float new_right, float new_bottom)
	{ left = new_left; top = new_top; right = new_right; bottom = new_bottom; }

	CL_Rectf(const CL_Pointf &p, const CL_Sizef &size)
	{ left = p.x; top = p.y; right = left + size.width; bottom = top + size.height; }

	CL_Rectf(const CL_Rectf &rect)
	{ left = rect.left; top = rect.top; right = rect.right; bottom = rect.bottom; }

	//: Rect += Rect operator.
	CL_Rectf &operator+=(const CL_Rectf &r)
	{ left += r.left; top += r.top; right += r.right; bottom += r.bottom; return *this; }

	//: Rect -= Rect operator.
	CL_Rectf &operator-=(const CL_Rectf &r)
	{ left -= r.left; top -= r.top; right -= r.right; bottom -= r.bottom; return *this; }
	
	//: Rect += Point operator.
	CL_Rectf &operator+=(const CL_Pointf &p)
	{ left += p.x; top += p.y; right += p.x; bottom += p.y; return *this; }

	//: Rect -= Point operator.
	CL_Rectf &operator-=(const CL_Pointf &p)
	{ left -= p.x; top -= p.y; right -= p.x; bottom -= p.y; return *this; }

	//: Rect + Rect operator.
	CL_Rectf operator+(const CL_Rectf &r) const
	{ return CL_Rectf(left + r.left, top + r.top, right + r.right, bottom + r.bottom); }

	//: Rect - Rect operator.
	CL_Rectf operator-(const CL_Rectf &r) const
	{ return CL_Rectf(left - r.left, top - r.top, right - r.right, bottom - r.bottom); }

	//: Rect + Point operator.
	CL_Rectf operator+(const CL_Pointf &p) const
	{ return CL_Rectf(left + p.x, top + p.y, right + p.x, bottom + p.y); }

	//: Rect - Point operator.
	CL_Rectf operator-(const CL_Pointf &p) const
	{ return CL_Rectf(left - p.x, top - p.y, right - p.x, bottom - p.y); }

	//: Rect == Rect operator.
	bool operator==(const CL_Rectf &r) const
	{ return (left == r.left && top == r.top && right == r.right && bottom && r.bottom); }

	//: Rect != Rect operator.
	bool operator!=(const CL_Rect &r) const
	{ return (left != r.left || top != r.top || right != r.right || bottom != r.bottom); }

//! Attributes:
public:
	//: X1-coordinate.
	float left;
	
	//: Y1-coordinate.
	float top;
	
	//: X2-coordinate.
	float right;
	
	//: Y2-coordinate.
	float bottom;
	
	//: Returns the width of the rectangle.
	float get_width() const { return right - left; }
	
	//: Returns the height of the rectangle.
	float get_height() const { return bottom - top; }

	//: Returns the size of the rectangle.
	CL_Sizef get_size() const { return CL_Sizef(right - left, bottom - top); }
	
	//: Returns true if point is inside the rectangle.
	bool is_inside(const CL_Pointf &p) const { return (p.x >= left && p.y >= top && p.x <= right && p.y <= bottom); }
	
	//: Returns true if rectangle passed is overlapping or inside this rectangle.
	bool is_overlapped(const CL_Rectf &r) const 
	{
		return (r.left < right && r.right > left && r.top < bottom && r.bottom > top);
	}

	//: Returns another CL_Rectf containing a rotated version of this one.
	//param hotspot: Point to rotate around.
	//param origin: Determines the hotspot point within the rectangle
	//param x, y: Offsets applied negatively to the hotspot point
	//param angle: Angle to rotate in degrees.
	CL_Rectf get_rot_bounds(const CL_Pointf &hotspot, float angle) const;
	CL_Rectf get_rot_bounds(CL_Origin origin, float x, float y, float angle) const;
	
//! Operations:
public:
	//: Sets the size of the rectangle, maintaining top/left position.
	void set_size(const CL_Size &size)
	{
		right = left + size.width;
		bottom = top + size.height;
	}

	//: Calculates and returns the union of two rectangles.
	CL_Rectf calc_union(const CL_Rectf &rect)
	{
		CL_Rectf result;
		if (left   > rect.left)   result.left   = left;   else result.left   = rect.left;
		if (right  < rect.right)  result.right  = right;  else result.right  = rect.right;
		if (top    > rect.top)    result.top    = top;    else result.top    = rect.top;
		if (bottom < rect.bottom) result.bottom = bottom; else result.bottom = rect.bottom;
		return result;
	}

	//: Normalize rectangle. Ensures that left<right and top<bottom.
	void normalize()
	{
		if (left > right)
		{
			float temp = right;
			right = left;
			left = temp;
		}

		if (top > bottom)
		{
			float temp = bottom;
			bottom = top;
			top = temp;
		}
	}
	
	//: Applies an origin and offset pair to this rectangle
	//param origin: The new origin to adjust to from default upper-left position
	//param x, y: Offsets applied negatively to each corner of the rectangle
	void apply_alignment(CL_Origin origin, float x, float y)
	{
		CL_Pointf offset = calc_origin(origin, get_size());
		offset.x -= x;
		offset.y -= y;
		
		left += offset.x;
		top += offset.y;
		right += offset.x;
		bottom += offset.y;
	}
};

#endif
