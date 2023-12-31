/*  $Id: layout.h,v 1.7 2004/02/01 20:53:15 mbn Exp $
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

#ifndef header_layout
#define header_layout

#include "../Core/System/sharedptr.h"

class CL_Component;
class CL_Layout_Generic;
class CL_Rect;

//: Layout types for CL_Layout.
//- !group=GUI/Framework!
//- !header=gui.h!
enum CL_LayoutType
{
	layout_vertical,
	layout_horizontal,
	layout_grid
};

//: Layout management class.
//- !group=GUI/Framework!
//- !header=gui.h!
class CL_Layout
{
//! Construction:
public:
	CL_Layout();

	CL_Layout(const CL_Layout &copy);

	CL_Layout(CL_LayoutType type);

	virtual ~CL_Layout();

//! Operations:
public:
	void set_grid_columns(int columns);

	void set_margin(int margin);

	void set_spacing(int spacing);

	void add_component(CL_Component *component);

	void add_component(int index, CL_Component *component);

	void add_component(int col, int row, CL_Component *component, int span=1);

	void add_layout(const CL_Layout &layout);

	void add_layout(int index, const CL_Layout &layout);

	void add_layout(int col, int row, const CL_Layout &layout, int span=1);

	void remove_component(CL_Component *component);

	void remove_layout(CL_Layout *layout);

	void set_position(const CL_Rect &pos);

//! Implementation:
private:
	CL_SharedPtr<CL_Layout_Generic> impl;
};

#endif
