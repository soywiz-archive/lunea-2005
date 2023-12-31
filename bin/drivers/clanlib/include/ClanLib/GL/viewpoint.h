/*  $Id: viewpoint.h,v 1.17 2004/01/02 15:42:43 mbn Exp $
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
*/

//! clanGL="Display 3D"
//! header=gl.h

#ifndef header_viewpoint
#define header_viewpoint

#include "../Core/Math/cl_vector.h"

//: CL_Viewpoint object.
//- !group=GL/Display 3D!
//- !header=gl.h!
//- <p>A viewpoint represents a position and viewing direction in 3D.</p>
class CL_Viewpoint
{
//! Construction:
public:
	//: Constructs a viewpoint.
	//param pos: Position of viewpoint.
	//param dir: Viewing direction of viewpoint.
	//param up: Up direction of viewpoint.
	CL_Viewpoint();

	CL_Viewpoint(
		const CL_Vector &pos,
		const CL_Vector &dir,
		const CL_Vector &up);

//! Attributes:
public:
	//: Position of viewpoint.
	CL_Vector pos;
	
	//: Viewing direction of viewpoint.
	CL_Vector dir;

	//: Up direction of viewpoint.
	CL_Vector up;

//! Operations:
public:
	//: Translates viewpoint position.
	void translate(float mov_x, float mov_y, float mov_z);

	//: Sets the viewpoint position.
	void set(float pos_x, float pos_y, float pos_z);

	//: Moves the viewpoint from its local point of view.
	//- <p>Moving in local coordinates means that it is moved according to its
	//- current viewing direction, where the z axis is in the facing direction,
	//- and the y axis is in the up direction.</p>
	void translate_local(float mov_x, float mov_y, float mov_z);

	//: Rotates the viewpoint from its local point view.
	//- <p>Rotating in local coordinates means that it is rotated according to its
	//- current viewing direction, where the z axis is in the facing direction,
	//- and the y axis is in the up direction.</p>
	void rotate_local(double angle, double rot_x, double rot_y, double rot_z);

	//: Setup OpenGL model view matrix to use local viewpoint coordinates.
	//- <p>Calling this function causes CL_Viewpoint to do the following:</p>
	//- <ul>
	//- <li>glMatrixMode(GL_MODELVIEW)</li>
	//- <li>glPushMatrix()</li>
	//- <li>glMultMatrix(world2local_transform)</li>
	//- </ul>
	//- <p>world2local_transform is a coordinate switch matrix, that convert local
	//- coordinates for a model to be positioned in the world at the viewpoint's
	//- position and viewing direction.</p>
	//- <p>It is required that leave_local() is to be called, when the local
	//- coordinate space model view is no longer needed.</p>
	void enter_local() const;

	//: Restores the OpenGL model view matrix prior to a call to enter_local().
	void leave_local() const;

	//: Converts a direction vector from world into local coordinates.
	CL_Vector make_local_direction(const CL_Vector &v) const;

	//: Sets up the model view matrix to look from this viewpoint.
	//- <p>Calling this function causes CL_Viewpoint to do the following:</p>
	//- <ul>
	//- <li>glMatrixMode(GL_MODELVIEW)</li>
	//- <li>glLoadIdentity()</li>
	//- <li>gluLookAt(pos, pos+dir, up)</li>
	//- </ul>
	void setup_modelview() const;
};

#endif
