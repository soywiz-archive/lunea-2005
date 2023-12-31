/*  $Id: guistylesilver.h,v 1.6 2004/01/05 15:46:25 sphair Exp $
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

#ifndef header_guistylesilver
#define header_guistylesilver

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "GUIStyleSilver/stylemanager_silver.h"
#include "GUIStyleSilver/button_silver.h"
#include "GUIStyleSilver/checkbox_silver.h"
#include "GUIStyleSilver/frame_silver.h"
#include "GUIStyleSilver/image_silver.h"
#include "GUIStyleSilver/inputbox_silver.h"
#include "GUIStyleSilver/label_silver.h"
#include "GUIStyleSilver/listbox_silver.h"
#include "GUIStyleSilver/progressbar_silver.h"
#include "GUIStyleSilver/radiobutton_silver.h"
#include "GUIStyleSilver/scrollbar_silver.h"
#include "GUIStyleSilver/window_silver.h"
#include "GUIStyleSilver/menu_silver.h"
#include "GUIStyleSilver/menu_node_silver.h"
#include "GUIStyleSilver/menu_item_silver.h"
#include "GUIStyleSilver/treeview_silver.h"
#include "GUIStyleSilver/treeitem_silver.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanGUIStyleSilver.lib")
#else
#pragma comment(lib, "clanGUIStyleSilverd.lib")
#endif
#endif

#endif
