/*  $Id: triangle_math.h,v 1.1 2004/04/04 14:37:12 harry Exp $
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

#ifndef header_triangle_math
#define header_triangle_math

#include "point.h"

//: Math operations on triangles.
//- !group=Core/Math!
//- !header=core.h!
class CL_TriangleMath
{
 public:
// Operations:

	//: Return true if the point is inside the triangle.
	//param CL_Pointf P: point to test
	//param float *vertices: Pointer to triangle vertices {x1,y1,x2,y2,x3,y3}.
	//param bool on_edge_is_outside: are points exactly on a edge in or out.
	static bool point_inside_triangle(const CL_Pointf &P, float *vertices, bool on_edge_is_outside);
	static bool point_inside_triangle(float px, float py, float *vertices, bool on_edge_is_outside);

};

#endif
