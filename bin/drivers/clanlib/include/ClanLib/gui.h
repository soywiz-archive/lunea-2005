/*  $Id: gui.h,v 1.50 2004/01/07 02:58:48 mbn Exp $
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

//: <p>Graphical User Interface API. Provides a themeable and very flexible GUI
//: framework.</p>
//! Global=GUI

#ifndef header_gui
#define header_gui

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

// Framework
#include "GUI/component.h"
#include "GUI/component_manager.h"
#include "GUI/component_type.h"
#include "GUI/component_move_handler.h"
#include "GUI/component_resize_handler.h"
#include "GUI/component_style.h"
#include "GUI/gui_manager.h"
#include "GUI/setupgui.h"
#include "GUI/stylemanager.h"
#include "GUI/layout.h"

// Components
#include "GUI/button.h"
#include "GUI/checkbox.h"
#include "GUI/frame.h"
#include "GUI/image.h"
#include "GUI/inputbox.h"
#include "GUI/label.h"
#include "GUI/listbox.h"
#include "GUI/listitem.h"
#include "GUI/progressbar.h"
#include "GUI/radiobutton.h"
#include "GUI/radiogroup.h"
#include "GUI/scrollbar.h"
#include "GUI/treeview.h"
#include "GUI/treeitem.h"
#include "GUI/treenode.h"
#include "GUI/window.h"
#include "GUI/menu.h"
#include "GUI/menu_node.h"
#include "GUI/menu_item.h"

// Dialogs
#include "GUI/messagebox.h"
#include "GUI/filedialog.h"
#include "GUI/inputdialog.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanGUI.lib")
#else
#pragma comment(lib, "clanGUId.lib")
#endif
#endif

#endif
