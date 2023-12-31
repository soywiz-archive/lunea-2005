/*  $Id: setupgui.h,v 1.20 2004/03/13 23:04:12 mbn Exp $
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

//! clanGUI="System"
//! header=gui.h

#ifndef header_setupgui
#define header_setupgui

#if _MSC_VER > 1000
#pragma once
#endif

//: Setup GUI Class
//- !group=GUI/System!
//- !header=gui.h!
class CL_SetupGUI
{
//! Construction:
public:
	//: Initializes clanGUI.
	//- <p>Constructing a CL_SetupGUI object is equalent to calling CL_SetupGUI::init().</p>
	//- <p>When the CL_SetupGUI instance is destroyed, CL_SetupGUI::deinit() is called.</p>
	CL_SetupGUI(bool register_resources_only = false);

	~CL_SetupGUI();

//! Operations:
public:
	//: Init the GUI.
	static void init(bool register_resources_only = false);

	//: Deinit the GUI.
	static void deinit();
};

#endif
