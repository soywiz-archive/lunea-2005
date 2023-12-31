/*  $Id: dom_named_node_map.h,v 1.9 2004/04/15 00:02:12 grumbel Exp $
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

#ifndef header_dom_named_node_map
#define header_dom_named_node_map

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

class CL_DomNode;
class CL_DomNamedNodeMap_Generic;

//: DOM Named Node Map class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>Objects implementing the NamedNodeMap interface are used to represent collections of nodes
//- that can be accessed by name. Note that NamedNodeMap does not inherit from NodeList;
//- NamedNodeMaps are not maintained in any particular order. Objects contained in an object
//- implementing NamedNodeMap may also be accessed by an ordinal index, but this is simply to
//- allow convenient enumeration of the contents of a NamedNodeMap, and does not imply that the
//- DOM specifies an order to these Nodes.</p>
class CL_DomNamedNodeMap
{
//! Construction:
public:
	//: Constructs a DOM NamedNodeMap handle.
	CL_DomNamedNodeMap();
	
	CL_DomNamedNodeMap(CL_DomNode &node);

	~CL_DomNamedNodeMap();
	
//! Attributes:
public:
	//: The number of nodes in the map.
	int get_length() const;
	
//! Operations:
public:
	//: Retrieves a node specified by name.
	CL_DomNode get_named_item(const std::string &name) const;

	//: Adds a node using its node name attribute.
	//- <p>As the node name attribute is used to derive the name which the node must be stored
	//- under, multiple nodes of certain types (those that have a "special" string value) cannot
	//- be stored as the names would clash. This is seen as preferable to allowing nodes to be
	//- aliased.</p>
	//param arg: A node to store in a named node map. The node will later be accessible using the value of the node name attribute of the node. If a node with that name is already present in the map, it is replaced by the new one.
	//retval: If the new Node replaces an existing node with the same name the previously existing Node is returned, otherwise null is returned.
	CL_DomNode set_named_item(const CL_DomNode &node);

	//: Removes a node specified by name.
	//- <p>If the removed node is an Attr with a default value it is immediately replaced.</p>
	//param name: The name of a node to remove.
	//retval: The node removed from the map or null if no node with such a name exists.
	CL_DomNode remove_named_item(const std::string &name);

	//: Returns the indexth item in the map.
	//- <p>If index is greater than or equal to the number of nodes in the map, this returns null.</p>
	CL_DomNode item(unsigned long index) const;
	
//! Implementation:
private:
	CL_SharedPtr<CL_DomNamedNodeMap_Generic> impl;
};

#endif
