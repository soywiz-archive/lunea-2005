/*  $Id: menu_node_silver.h,v 1.3 2004/01/03 23:03:22 sphair Exp $
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

#ifndef header_menu_node_silver
#define header_menu_node_silver

//#include "../core.h"
//#include "../gui.h"

#include "../GUI/menu_node.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_Surface;

//: MenuNode default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_MenuNode_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_MenuNode_Silver(
		CL_MenuNode *node,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_MenuNode_Silver();

//! Implementation:
private:
	void on_set_options(const CL_DomElement &options);

	void on_paint();

	void on_pressed();

	void on_released();

	void on_reposition();

	void on_get_preferred_size(CL_Size &size);

	CL_SlotContainer slots;

	CL_MenuNode *node;
	
	CL_StyleManager_Silver *style;

	CL_ResourceManager *resources;

	CL_Surface *arrow;
	
	bool down;
};

#endif
