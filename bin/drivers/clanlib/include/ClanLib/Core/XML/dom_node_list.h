/*  $Id: dom_node_list.h,v 1.8 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_node_list
#define header_dom_node_list

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

class CL_DomNode;
class CL_DomNodeList_Generic;
class CL_DomDocument;

//: DOM Node List class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>The NodeList interface provides the abstraction of an ordered collection of nodes,
//- without defining or constraining how this collection is implemented.</p>
class CL_DomNodeList
{
//! Construction:
public:
	//: Constructs a DOM NodeList handle.
	CL_DomNodeList();
	
	CL_DomNodeList(CL_DomDocument &doc, const std::string &tag_name);

	~CL_DomNodeList();
	
//! Attributes:
public:
	//: The number of nodes in the list.
	int get_length() const;

//! Operations:
public:
	//: Returns the indexth item in the collection.
	//- <p>If index is greater than or equal to the number of nodes in the list, this returns null.</p>
	CL_DomNode item(unsigned long index) const;

//! Implementation:
private:
	CL_SharedPtr<CL_DomNodeList_Generic> impl;
};

#endif
