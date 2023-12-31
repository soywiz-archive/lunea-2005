/*  $Id: menu_silver.h,v 1.3 2004/01/02 15:42:44 mbn Exp $
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

#ifndef header_menu_silver
#define header_menu_silver

#include "../GUI/menu.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_Menu;

//: Menu default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_Menu_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_Menu_Silver(
		CL_Menu *menu,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_Menu_Silver();

//! Implementation:
private:
	void on_set_options(const CL_DomElement &options);

	void on_paint();

	void on_reposition(int,int);

	void on_parent_resize(int,int);

	CL_SlotContainer slots;

	CL_Menu *menu;
	
	CL_StyleManager_Silver *style;
	
	bool repositioned;
};

#endif
