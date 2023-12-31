/*  $Id: menu_item.h,v 1.4 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_menu_item
#define header_menu_item

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_MenuItem_Generic;
class CL_Surface;

//: Label component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_MenuItem : public CL_Component
{
//! Construction:
public:
	//: MenuItem Constructor
	CL_MenuItem(
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: MenuItem Destructor
	virtual ~CL_MenuItem();

//! Attributes:
public:
	//: Returns the menu item text.
	const std::string &get_text() const;

	//: Returns true if the menu item can have an icon.
	bool use_icon() const;
	
	//: Returns true if the menu item is in toggle mode, otherwise false.
	bool is_toggling() const;

	//: Returns true if the menu item is selected
	bool is_selected() const;

//! Operations:
public:
	//: Sets the item to toggle mode (true) or normal mode (false). Default is false.
	void set_toggling(bool toggle);

	//: Sets the item to toggle mode (true) or normal mode (false). Default is false.
	void set_use_icon(bool use_icon);

	//: Sets the menu items selected status, if in toggle mode.
	void set_selected(bool selected);

	//: Sets the menu item text.
	void set_text(const std::string &text);

	//: Sets the menu item contents to a plain text containing the printed value of num.
	void set_text(int number);

	//: Sets the menu item contents to a plain text containing the printed value of num.
	void set_text(double number);

	//: Clears any menu item text. Equivalent with set_text("").
	void clear();

//! Implementation:
private:
	void init(const std::string &text);

	CL_MenuItem(const CL_MenuItem &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	
	CL_MenuItem_Generic *impl;
};  

#endif
