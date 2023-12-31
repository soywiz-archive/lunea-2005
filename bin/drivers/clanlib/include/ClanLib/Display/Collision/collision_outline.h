/*  $Id: collision_outline.h,v 1.6 2004/05/08 21:24:52 harry Exp $
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

#ifndef header_collision_outline
#define header_collision_outline

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include <vector>
#include "contour.h"
#include "outline_accuracy.h"
#include "../../Core/Resources/resource.h"
#include "../../Core/Math/origin.h"

class CL_CollisionOutline_Generic;
class CL_ResourceManager;
class CL_PixelBuffer;
class CL_OutputSourceProvider;

//: Collision detection outline.
//- !group=Display/Collision !
//- !header=display.h!
//- <p>A collision outline is used in collision detection</p>
class CL_CollisionOutline
{
//! Construction:
 public:
	//: Construct a collision outline.
	//param CL_PixelBuffer *pbuf : Find alpha outline from a pixel buffer
	//param int alpha_limit : Alpha limit for pixels considered solid (collidable) 
	//param CL_OutlineAccuracy accuracy : Amount of optimization of the outline (default: medium)
	//param std::string filename : Load outline from a file. The file can be an image or a precompiled outline.
	CL_CollisionOutline();
	CL_CollisionOutline(const CL_CollisionOutline &other);
	CL_CollisionOutline( CL_PixelBuffer *pbuf, int alpha_limit=128, CL_OutlineAccuracy accuracy=accuracy_medium );
	CL_CollisionOutline( const std::string &filename, int alpha_limit=128, CL_OutlineAccuracy accuracy=accuracy_medium );
	
	~CL_CollisionOutline();
	
//! Attributes:
 public:
	//: Returns the contour used as an object bounding box. (an rotated rectangle)
	const CL_Contour &get_object_bounding_box() const;
	
	//: Returns the radius of the outline.
	float get_radius() const;
		
	//: Returns true if object bounding box test is used.
	bool get_obb_test() const;
	
	//: Returns true if completely-inside test is used.
	bool get_inside_test() const;

	//: Returns the contours in the outline.
	std::vector<CL_Contour> &get_contours() const;

	//: Returns the position of the outline.
	CL_Pointf get_translation() const;

	//: Returns the scaling factor.
	CL_Pointf get_scale() const;

	//: Returns the rotation angle.
	float get_angle() const;
	
	//: Returns the width of the image this outline was created from.
	unsigned int get_width() const;

	//: Returns the height of the image this outline was created from.
	unsigned int get_height() const;

	//: Get the translation origin and hotspot of the outline.	
	void get_alignment( CL_Origin &origin, float &x, float &y ) const;

	//: Get the rotation hotspot of the outline.	
	void get_rotation_hotspot( CL_Origin &origin, float &x, float &y) const;

	//: Return the points of collision found in the last collision test.
	const std::vector<CL_Pointf> &get_collision_points() const;

	//: Return the normal vectors of the other outline, at the points of collision.
	const std::vector<CL_Pointf> &CL_CollisionOutline::get_collision_normals() const;
	
//! Operations:
 public:
	//: Optimize the outline by removing redundant points.
	//param unsigned char check_distance : the distance of points compared on the outline
	//param float corner_angle : angle for a corner
	void optimize( unsigned char check_distance=3, float corner_angle=M_PI/5.0f );

	//: Set the translation hotspot of the outline.	
	void set_alignment( CL_Origin origin, float x=0, float y=0 );

	//: Set the rotation hotspot of the outline.	
	void set_rotation_hotspot( CL_Origin origin, float x=0, float y=0 );

	//: Set the position of the outline.	
	void set_translation( float x, float y );
	
	//: Set the scale of the outline.	
	void set_scale( float x, float y );
	
	//: Set the angle (in degrees) of the outline.	
	void set_angle( float angle );
	
	//: Rotate the outline by angle (in degrees).
	void rotate( float angle );
	
	//: Set to true if obb test should be done
	void set_obb_test( bool value );
	
	//: Set to true if completely-inside test should be done
	void set_inside_test( bool value );

	//: Enable collision info gathering.
	void enable_collision_info( bool value=true );

	//: Enable collision info about normals. Only works when collision_info is also enabled.
	void enable_collision_info_normals( bool value=true );
	
	//: (Re)calculate the radius of the outline.
	void calculate_radius();

	//: (Re)calculate the subcircle segmentation of the outline.
	void calculate_sub_circles();

	//: Write the outline to a file.
	//param std::string filename: Name of file.
	//param CL_OutputSourceProvider *provider: (Optional) OutputSourceProvider to use.
	void save(const std::string &filename, CL_OutputSourceProvider *provider=0) const;

	//: Returns true if outlines overlap
	//param CL_CollisionOutline outline : Outline to test against.
	bool collide( const CL_CollisionOutline &outline );

	//: Returns true if a point is inside the outline.
	//param CL_Pointf &point: the point to test.
	bool point_inside( const CL_Pointf &point ) const;

//! Implementation:
 private:
	CL_CollisionOutline_Generic *impl;
};

#endif
