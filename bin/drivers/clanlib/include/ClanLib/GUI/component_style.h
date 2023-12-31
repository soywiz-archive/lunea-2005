/*  $Id: component_style.h,v 1.17 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_component_style
#define header_component_style

#if _MSC_VER > 1000
#pragma once
#endif

class CL_Component;

//: Component Style interface.
//- !group=GUI/Framework!
//- !header=gui.h!
//- <p>The component style class is part of the style customization system of the
//- GUI. Each 'style' for a component is implemented by inheriating
//- CL_ComponentStyle and then attaching it to the component it is responsible
//- of visualizing.</p>
//- <p>When a component is constructed, it will contact its CL_StyleManager and
//- ask it to attach the component styles for its style to the component.
//- The general principle in the component style system is that a inheriated
//- CL_ComponentStyle object will hook itself into signals in the component it
//- is visualizing, thus keeping a kind of document/view relationship with its
//- component.</p>
//- <p>For source examples of how this is done, have a look at the GUIGL example.</p>
class CL_ComponentStyle
{
//! Construction:
public:
	//: Construct a component style.
	CL_ComponentStyle(CL_Component *component) : comp(component) { return; }

	//: Destructor.
	virtual ~CL_ComponentStyle() { return; }

//! Attributes:
public:
	//: Returns the component that is being styled.
	CL_Component *get_component() { return comp; }

	//: Returns the component that is being styled.
	const CL_Component *get_component() const { return comp; }

//! Implementation:
private:
	CL_Component *comp;
};

#endif
