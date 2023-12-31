/*  $Id: size.h,v 1.22 2004/01/21 00:22:42 mbn Exp $
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

#ifndef header_size
#define header_size

#if _MSC_VER > 1000
#pragma once
#endif

//: 2D (width,height) size structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Size
{
//! Construction:
public:
	//: Constructs a size structure.
	//param width: Initial width of size structure.
	//param height: Initial height of size structure.
	//param size: Size structure to construct this one from.
	CL_Size() { return; }

	CL_Size(int width, int height)
	: width(width), height(height) { }

	CL_Size(const CL_Size &s)
	{ width = s.width; height = s.height; }

//! Attributes:
public:
	//: Size width.
	int width;

	//: Size height.
	int height;

//! Operations:
public:
	//: Size += Size operator.
	CL_Size &operator+=(const CL_Size &s)
	{ width += s.width; height += s.height; return *this; }

	//: Size -= Size operator.
	CL_Size &operator-=(const CL_Size &s)
	{ width -= s.width; height -= s.height; return *this; }
	
	//: Size + Size operator.
	CL_Size operator+(const CL_Size &s) const
	{ return CL_Size(width + s.width, height + s.height); }

	//: Size - Size operator.
	CL_Size operator-(const CL_Size &s) const
	{ return CL_Size(width - s.width, height - s.height); }

	//: Size == Size operator (deep compare).
	bool operator==(const CL_Size &s) const
	{ return (width == s.width) && (height == s.height); }

	//: Size != Size operator (deep compare).
	bool operator!=(const CL_Size &s) const
	{ return (width != s.width) || (height != s.height); }
};

//: 2D (width,height) floating point size structure.
class CL_Sizef
{
//! Construction:
public:
	//: Constructs a size structure.
	//param width: Initial width of size structure.
	//param height: Initial height of size structure.
	//param size: Size structure to construct this one from.
	CL_Sizef() { return; }

	CL_Sizef(float width, float height)
	: width(width), height(height) { }

	CL_Sizef(const CL_Sizef &s)
	{ width = s.width; height = s.height; }

//! Attributes:
public:
	//: Size width.
	float width;

	//: Size height.
	float height;

//! Operations:
public:
	//: Size += Size operator.
	CL_Sizef &operator+=(const CL_Sizef &s)
	{ width += s.width; height += s.height; return *this; }

	//: Size -= Size operator.
	CL_Sizef &operator-=(const CL_Sizef &s)
	{ width -= s.width; height -= s.height; return *this; }
	
	//: Size + Size operator.
	CL_Sizef operator+(const CL_Sizef &s) const
	{ return CL_Sizef(width + s.width, height + s.height); }

	//: Size - Size operator.
	CL_Sizef operator-(const CL_Sizef &s) const
	{ return CL_Sizef(width - s.width, height - s.height); }

	//: Size == Size operator (deep compare).
	bool operator==(const CL_Sizef &s) const
	{ return (width == s.width) && (height == s.height); }

	//: Size != Size operator (deep compare).
	bool operator!=(const CL_Size &s) const
	{ return (width != s.width) || (height != s.height); }
};

#endif
