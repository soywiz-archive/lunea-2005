/*  $Id: line_math.h,v 1.2 2004/04/11 15:37:31 mbn Exp $
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

#ifndef header_line_math
#define header_line_math

#include "point.h"

//: Math operations on 2D lines.
//- !group=Core/Math!
//- !header=core.h!
class CL_LineMath
{
 public:
// Operations:
	//: Return the distance from a point to a line.
	//param float x: X coordinate of point.
	//param float y: Y coordinate of point.
	//param CL_Pointf point: The point.
	//param float *line: Pointer to float array with elements {x1,y1,x2,y2}.
	static float distance_to_line(const CL_Pointf &point, float *line);
	static float distance_to_line(float x, float y, float *line);

	//: Return true if two line segments intersect.
	//param float *lineA: First line. Pointer to float array with elements {x1,y1,x2,y2}.
	//param float *lineB: Second line. Pointer to float array with elements {x1,y1,x2,y2}.
	//param bool collinear_intersect: set if a collision is reported when all points are on the same line.
	static bool intersects( float *lineA, float *lineB, bool collinear_intersect=false );

	//: Return true if two line segments are collinear. (All points are on the same line.)
	//param float *lineA: First line. Pointer to float array with elements {x1,y1,x2,y2}.
	//param float *lineB: Second line. Pointer to float array with elements {x1,y1,x2,y2}.
	static bool collinear( float *lineA, float *lineB );

	//: Return the intersection point of two lines.
	//param float *lineA: First line. Pointer to float array with elements {x1,y1,x2,y2}.
	//param float *lineB: Second line. Pointer to float array with elements {x1,y1,x2,y2}.
	static CL_Pointf get_intersection( float *lineA, float *lineB );	

	//: Return true if the point is on the right side of the line, as seen from x1, y1.
	//param float x: x coordinate of the point being tested.
	//param float y: y coordinate of the point being tested.
	//param float *line: The line. A pointer to a float array with the elements {x1,y1,x2,y2}.
	//param float line_x1, line_y1: First point defining the line.
	//param float line_x2, line_y2: Second point defining the line.
	static bool point_right_of_line( float x, float y, float *line );

	static bool point_right_of_line( float x, float y, float line_x1, float line_y1, float line_x2, float line_y2 );

	//: Return the midpoint of the line from point A to point B.
	//param CL_Pointf A: point A
	//param CL_Pointf B: point B
	static CL_Pointf midpoint( const CL_Pointf &A, const CL_Pointf &B );
};

#endif
