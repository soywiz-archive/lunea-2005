/*  $Id: image.h,v 1.15 2004/03/28 00:13:14 sphair Exp $
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

//! clanGUI="Controls"
//! header=gui.h

#ifndef header_image
#define header_image

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_Surface;
class CL_Image_Generic;

//: Image component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_Image : public CL_Component
{
//! Enums:
public:
	//: Mode enums
	enum Mode
	{
		normal,
		center,
		stretch,
		tile
	};

//! Construction:
public:
	//: Image Constructor
	CL_Image(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Image Constructor
	CL_Image(
		CL_Surface *surface,
		bool delete_surface,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Image Constructor
	CL_Image(
		const CL_Rect &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Image Constructor
	CL_Image(
		const CL_Rect &pos,
		CL_Surface *surface,
		bool delete_surface,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Image Constructor
	CL_Image(
		const CL_Point &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Image Constructor
	CL_Image(
		const CL_Point &pos,
		CL_Surface *surface,
		bool delete_surface,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Image Destructor
	virtual ~CL_Image();

//! Attributes:
public:
	//: Returns the surface.
	CL_Surface *get_surface() const;

	//: Returns the current display mode.
	Mode get_mode() const;

//! Operations:
public:
	//: Sets the surface.
	void set_surface(CL_Surface *surface, bool delete_surface = false);

	//: Sets the display mode.
	void set_mode(Mode mode);

//! Implementation:
private:
	Mode mode;

	CL_Image(const CL_Image &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_Image_Generic *impl;
};  

#endif
