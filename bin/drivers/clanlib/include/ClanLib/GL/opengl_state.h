/*  $Id: opengl_state.h,v 1.7 2004/01/31 19:36:04 mbn Exp $
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

//! clanGL="System"
//! header=gl.h

#ifndef header_opengl_state
#define header_opengl_state

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/sharedptr.h"

class CL_GraphicContext;
class CL_GraphicContext_OpenGL;
class CL_OpenGLStateData;
class CL_OpenGLState_Generic;
class CL_GLStateChecker;

//: OpenGL state setup handler class.
//- !group=GL/System!
//- !header=gl.h!
class CL_OpenGLState
{
//! Construction:
public:
	//: Constructs an opengl state set.
	CL_OpenGLState();

	CL_OpenGLState(CL_GraphicContext *gc);

	CL_OpenGLState(const CL_OpenGLState &copy);

	~CL_OpenGLState();

//! Attributes:
public:
	//: Returns true if opengl state is currently active.
	bool is_active() const;

//! Operations:
public:
	//: Activates this OpenGL state set.
	void set_active();

	//: Attaches a new data object responsible for saving and restoring states.
	void attach_data(CL_OpenGLStateData *data, bool delete_data = false);

	//: Detaches a data object.
	void detach_data(CL_OpenGLStateData *data);

	//: Setup window 2D rendering mode.
	//param upside_down: If set to true, (0,0) will be in the lower left corner.
	//- <p> This effectively loads a Orto 2D projection matrix and makes sure
	//- the device are using sane texture parameter values.</p>
	void setup_2d(bool upside_down = false);

//! Implementation:
private:
	CL_OpenGLState(CL_GraphicContext_OpenGL *gc_opengl);

	CL_SharedPtr<CL_OpenGLState_Generic> impl;

	friend class CL_GLStateChecker;
};

#endif
