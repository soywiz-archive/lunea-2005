/*  $Id: window.h,v 1.34 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_window
#define header_window

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_Window_Generic;

//: Window component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_Window : public CL_Component
{
//! Construction:
public:
	//: Creates a window.
	CL_Window(
		CL_Component *parent,
		CL_StyleManager *style = NULL);
	CL_Window(
		const std::string &title,
		CL_Component *parent,
		CL_StyleManager *style = NULL);
	CL_Window(
		const CL_Rect &pos,
		const std::string &title,
		CL_Component *parent,
		CL_StyleManager *style = NULL);
	CL_Window(
		const CL_Rect &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Window destructor
	virtual ~CL_Window();

//! Attributes:
public:
	//: Returns the window title.
	const std::string &get_title() const;

//! Operations:
public:
	//: Sets the window title.
	//param text: An std::string with the new title
	void set_title(const std::string &text);

//! Signals:
public:

//! Implementation:
private:
	CL_Window(const CL_Window &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_Window_Generic *impl;
};  

#endif
