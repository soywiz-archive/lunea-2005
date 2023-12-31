/*  $Id: opengl_state_data.h,v 1.3 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_opengl_state_data
#define header_opengl_state_data

#if _MSC_VER > 1000
#pragma once
#endif

class CL_OpenGLStateData_Generic;

//: OpenGL state worker; responsible for saving and restoring states.
//- !group=GL/System!
//- !header=gl.h!
class CL_OpenGLStateData
{
//! Construction:
public:
	CL_OpenGLStateData();

	virtual ~CL_OpenGLStateData();

//! Attributes:
public:

//! Operations:
public:
	//: Save state information needed to restore this OpenGL state.
	virtual void on_save()=0;

	//: Load state information and setup OpenGL to this state.
	virtual void on_load()=0;

	//: Flush current rendering batch.
	//- <p>This is a hint from clanDisplay that it needs to perform some state changes.
	//- Usually this happens if translate, viewport or scissor needs updating.</p>
	//- <p>Internally ClanLib uses this to end any open glBegin render batches.</p>
	virtual void on_flush()=0;

//! Implementation:
private:
	CL_OpenGLStateData_Generic *impl;
};

#endif
