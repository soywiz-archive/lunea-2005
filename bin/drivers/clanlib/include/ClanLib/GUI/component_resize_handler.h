/*  $Id: component_resize_handler.h,v 1.13 2004/01/02 15:42:43 mbn Exp $
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

//! clanGUI="Framework"
//! header=gui.h

#ifndef header_component_resize_handler
#define header_component_resize_handler

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_Rect;
class CL_ComponentResizeHandler_Generic;

//: Component Resize Handler
//- !group=GUI/Framework!
//- !header=gui.h!
class CL_ComponentResizeHandler : public CL_Component
{
//! Construction:
public:
	//: Constructor
	CL_ComponentResizeHandler(CL_Component *owner);

	//: Constructor
	CL_ComponentResizeHandler(const CL_Rect &resize_area, CL_Component *owner);

	//: Destructor
	virtual ~CL_ComponentResizeHandler();

//! Implementation:
private:
	CL_ComponentResizeHandler_Generic *impl;
};

#endif
