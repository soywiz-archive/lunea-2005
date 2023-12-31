/*  $Id: dom_entity_reference.h,v 1.10 2004/02/01 04:31:55 mbn Exp $
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

//! clanCore="XML"
//! header=core.h

#ifndef header_dom_entity_reference
#define header_dom_entity_reference

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Entity Reference class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>EntityReference objects may be inserted into the structure model when an entity reference
//- is in the source document, or when the user wishes to insert an entity reference. Note that
//- character references and references to predefined entities are considered to be expanded by
//- the HTML or XML processor so that characters are represented by their Unicode equivalent rather
//- than by an entity reference. Moreover, the XML processor may completely expand references to
//- entities while building the structure model, instead of providing EntityReference objects. If
//- it does provide such objects, then for a given EntityReference node, it may be that there is no
//- Entity node representing the referenced entity; but if such an Entity exists, then the child list
//- of the EntityReference node is the same as that of the Entity node. As with the Entity node, all
//- descendants of the EntityReference are readonly.</p>
class CL_DomEntityReference : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Entity Reference handle.
	CL_DomEntityReference();
	
	CL_DomEntityReference(CL_DomDocument &doc, const std::string &name);

	CL_DomEntityReference(const CL_SharedPtr<CL_DomNode_Generic> &impl);

	~CL_DomEntityReference();

//! Attributes:
public:

//! Operations:
public:
};

#endif
