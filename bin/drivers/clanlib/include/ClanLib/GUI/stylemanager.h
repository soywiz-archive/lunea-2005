/*  $Id: stylemanager.h,v 1.35 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_stylemanager
#define header_stylemanager

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_DomElement;
class CL_Component;
class CL_ResourceManager;
class CL_StyleManager_Generic;

//: Manages the overall style of the system.
//- !group=GUI/Framework!
//- !header=gui.h!
//- <p>The style manager is responsible of attaching CL_ComponentStyle objects to
//- CL_Component objects.</p>
//- <p>When a component is constructed, it will contact its style manager's
//- connect_styles() function. The style manager will then construct and attach
//- component styles to the component.</p>
//- <p>The style manager also works as a 'component factory' for the component
//- manager. By using create_component(), it is possible to create a component
//- based on a name and component options describing it.</p>
class CL_StyleManager
{
//! Construction:
public:
	//: Construct a style manager using the specified resources.
	CL_StyleManager(CL_ResourceManager *resources);

	//: Destructor.
	virtual ~CL_StyleManager();

//! Attributes:
public:
	//: Returns style manager's resources.
	CL_ResourceManager *get_resources();

//! Overrideables:
public:
	//: Create a component based on a type name.
	virtual CL_Component *create_component(
		const std::string &type,
		CL_Component *parent);

	//: Connect component styles to component.
	//: The 'type' parameter indicates what type the component is.
	virtual void connect_styles(
		const std::string &type,
		CL_Component *owner)=0;

//! Implementation:
private:
	// Disallow copy contruction of style managers.
	CL_StyleManager(const CL_StyleManager &copy) { return; }
	
	CL_StyleManager_Generic *impl;
};

#endif
