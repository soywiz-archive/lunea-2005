/*  $Id: menu_item_silver.h,v 1.4 2004/01/06 00:52:27 sphair Exp $
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

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_menu_item_silver
#define header_menu_item_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/menu_item.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_Font;

//: MenuItem default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_MenuItem_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_MenuItem_Silver(
		CL_MenuItem *label,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_MenuItem_Silver();

//! Operations:
public:
	//: Sets the menu items icon
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_icon(CL_Surface *surface, bool delete_surface = false);

//! Implementation:
private:
	void on_paint();

	void on_get_preferred_size(CL_Size &size);

	CL_Slot slot_paint;

	CL_Slot slot_get_preferred_size;

	CL_MenuItem *menu_item;
	
	CL_ResourceManager *resources;

	CL_Font *font;

	CL_Font *font_disabled;

	CL_Surface *sur_icon;

	CL_Surface *sur_checked;

	CL_Surface *sur_unchecked;

	bool delete_sur_icon;
};

#endif
