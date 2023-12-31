/*  $Id: dom_element.h,v 1.11 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_element
#define header_dom_element

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Element class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>By far the vast majority of objects (apart from text) that authors encounter when
//- traversing a document are Element nodes. Assume the following XML document:</p>
//- <pre>
//- &lt;elementExample id="demo"&gt;
//-  &lt;subelement1/&gt;
//-  &lt;subelement2&gt;&lt;subsubelement/&gt;&lt;/subelement2&gt;
//- &lt;/elementExample/gt;
//- </pre>
//- <p>When represented using DOM, the top node is an Element node for "elementExample",
//- which contains two child Element nodes, one for "subelement1" and one for "subelement2".
//- "subelement1" contains no child nodes.</p>
//- <p>Elements may have attributes associated with them; since the Element interface
//- inherits from Node, the generic Node interface method getAttributes may be used to
//- retrieve the set of all attributes for an element. There are methods on the Element
//- interface to retrieve either an Attr object by name or an attribute value by name.
//- In XML, where an attribute value may contain entity references, an Attr object should
//- be retrieved to examine the possibly fairly complex sub-tree representing the attribute
//- value.</p>
class CL_DomElement : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Element handle.
	CL_DomElement();
	
	CL_DomElement(CL_DomDocument &doc, const std::string &tag_name);

	CL_DomElement(const CL_SharedPtr<CL_DomNode_Generic> &impl);

	~CL_DomElement();

//! Attributes:
public:
	//: Returns the name of the element.
	std::string get_tag_name() const;

//! Operations:
public:
	//: Returns true if the element has the specified attribute.
	bool has_attribute(const std::string &name) const;

	//: Returns the specified attribute.
	std::string get_attribute(const std::string &name) const;

	//: Returns the specified attribute, using a default value if its not there.
	std::string get_attribute(const std::string &name, const std::string &default_value) const;

	//: Adds a new attribute.
	//- <p>If an attribute with that name is already present in the element, its value is
	//- changed to be that of the value parameter.</p>
	//- <p>This value is a simple string, it is not parsed as it is being set. So any markup
	//- (such as syntax to be recognized as an entity reference) is treated as literal text, and
	//- is appropriately escaped by the implementation when it is written out. In order to
	//- assign an attribute value that contains entity references, the user must create an Attr
	//- node plus any Text and EntityReference nodes, build the appropriate subtree, and use
	//- set_attribute_node to assign it as the value of an attribute.</p>
	void set_attribute(const std::string &name, const std::string &value);

	//: Removes an attribute by name.
	//- <p>If the removed attribute has a default value it is immediately replaced.</p>
	void remove_attribute(const std::string &name);
	
	//: Returns a NodeList of all descendant elements with a given tag name.
	//- <p>The descendant elements are returned in the order in which they would be
	//- encountered in a preorder traversal of the Element tree.</p>
	CL_DomNodeList get_elements_by_tag_name(const std::string &name);

	//: Merges any adjacent Text nodes.
	//- <p>Puts all Text nodes in the full depth of the sub-tree underneath this Element into
	//- a "normal" form where only markup (e.g., tags, comments, processing instructions, CDATA
	//- sections, and entity references) separates Text nodes, i.e., there are no adjacent Text
	//- nodes. This can be used to ensure that the DOM view of a document is the same as if it
	//- were saved and re-loaded, and is useful when operations (such as XPointer lookups) that
	//- depend on a particular document tree structure are to be used.</p>
	void normalize();

	//: Returns the text of all child Text nodes appended together.
	std::string get_text() const;
};

#endif
