/*  $Id: menu_node.h,v 1.7 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_menu_node
#define header_menu_node

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/component.h"

class CL_Menu;
class CL_MenuNode_Generic;

//: MenuNode component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_MenuNode : public CL_Component
{
//! Construction:
public:
	//: CL_MenuNode Constructor
	CL_MenuNode(
		CL_Menu *parent_menu,
		CL_StyleManager *style = NULL);

	//: CL_MenuNode destructor
	virtual ~CL_MenuNode();

//! Attributes:
public:
	//: Returns a pointer to the CL_Component which is this MenuNodes MenuItem.
	CL_Component *get_data();
	
	//: Returns true if the mouse is in the submenus of this node.
	bool has_mouse_in_submenus();
	
	//: Returns true if the mouse is on this component or it's MenuItem
	//: This overrides CL_Component's has_mouse_over()
	bool has_mouse_over();
	
	//: Returns true if the node has a submenu.
	bool has_submenu();

	//: Returns true if the node has an open submenu.
	bool has_open_submenu();
	
	//: Returns the nodes submenu, or NULL if the node has no submenu.
	CL_Menu *get_submenu();
	
	//: Returns the nodes parent menu.
	CL_Menu *get_parent_menu();

	//: Returns the name of the menu node. 
	//: A menu nodes name forms a part of the path used by the CL_Menu::get_<menu/node/item>(std::string path) functions.
	std::string get_name();

//! Operations:
public:
	//: Set the nodes submenu.
	void set_submenu(CL_Menu *menu);

	//: Set the nodes parent menu.
	void set_parent_menu(CL_Menu *menu);

	//: Set whether the menus should collapse when an node is clicked
	void set_close_on_click(bool close);
	
	//: Close the nodes submenu.
	void collapse();

	//: Open the nodes submenu.
	void open_submenu();

	//: Start the repositioning of the nodes submenus.
	void reposition_submenus();

	//: Set the name of the node. This forms a part of the path used in adressing menu components.
	void set_name(std::string);

//! Signals:
public:
	//: Emitted when repositioning of the menus is requested.
	CL_Signal_v0 &sig_reposition();

	//: Emitted when a menu node is clicked.
	CL_Signal_v0 &sig_clicked();

//! Implementation:
private:
	CL_MenuNode(const CL_MenuNode &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.

	CL_MenuNode_Generic *impl;
};

#endif
