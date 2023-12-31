/*  $Id: listitem.h,v 1.6 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_listbox_item
#define header_listbox_item

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

//: List item class.
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_ListItem
{
public:
	CL_ListItem() : selected(false), delete_item(false) {}

	bool operator< ( const CL_ListItem &item ) const
	{
		return str < item.str;
	}

	bool operator== ( const CL_ListItem &item ) const
	{
		return str == item.str;
	}

	std::string str;
	bool selected;
	bool delete_item;
};

#endif
