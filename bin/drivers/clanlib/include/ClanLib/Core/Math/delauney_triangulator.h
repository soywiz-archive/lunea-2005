/*  $Id: delauney_triangulator.h,v 1.3 2004/04/07 22:00:51 mbn Exp $
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

#ifndef header_delauney_triangulator
#define header_delauney_triangulator

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

//: Vertex in the delauney triangulation.
class CL_DelauneyTriangulator_Vertex
{
//! Attributes:
public:
	//: Data pointer given when adding the vertex.
	void *data;

	//: X position of vertex.
	double x;
	
	//: Y position of vertex.
	double y;
};

//: Triangle generated from a delauney triangulation.
class CL_DelauneyTriangulator_Triangle
{
//! Attributes:
public:
	//: First point in the triangle.
	CL_DelauneyTriangulator_Vertex *vertex_A;

	//: Second point in the triangle.
	CL_DelauneyTriangulator_Vertex *vertex_B;

	//: Third point in the triangle.
	CL_DelauneyTriangulator_Vertex *vertex_C;
};

class CL_DelauneyTriangulator_Generic;

//: Delauney triangulator.
//- <p>This class uses the <a href="http://astronomy.swin.edu.au/~pbourke/terrain/triangulate/">
//- delauney triangulation algorithm</a> to produce
//- triangles between a list of points.</p>
class CL_DelauneyTriangulator
{
//! Construction:
public:
	//: Creates a triangulator object.
	CL_DelauneyTriangulator();

	virtual ~CL_DelauneyTriangulator();

//! Attributes:
public:
	//: Returns the list of vertices in the triangulation.
	const std::vector<CL_DelauneyTriangulator_Vertex> &get_vertices() const;

	//: Returns the resulting triangles produced from triangulation.
	const std::vector<CL_DelauneyTriangulator_Triangle> &get_triangles() const;

//! Operations:
public:
	//: This function specifies a point to be used in the triangulation.
	void add_vertex(double x, double y, void *data);

	//: Converts passed points into triangles.
	void generate();

//! Implementation:
private:
	CL_SharedPtr<CL_DelauneyTriangulator_Generic> impl;
};

#endif
