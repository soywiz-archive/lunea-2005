/*  $Id: outline_triangulator.h,v 1.2 2004/04/11 15:37:31 mbn Exp $
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

#ifndef header_outline_triangulator
#define header_outline_triangulator

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

class CL_OutlineTriangulator_Generic;

//: Polygon Tesselator.
//- <p>This class uses constrained delauney triangulation to convert polygon outlines into triangles.</p>
class CL_OutlineTriangulator
{
//! Construction:
public:
	//: Creates a tessellation object.
	CL_OutlineTriangulator();

	virtual ~CL_OutlineTriangulator();

//! Attributes:
public:

//! Operations:
public:
	//: This function specifies a vertex on a polygon.
	void add_vertex(double x, double y, void *data);

	//: Mark next contour in polygon path.
	void next_contour();

	//: Mark next polygon.
	void next_polygon();

	//: Converts passed polygons into triangles.
	void generate();

//! Implementation:
private:
	CL_SharedPtr<CL_OutlineTriangulator_Generic> impl;
};

#endif
