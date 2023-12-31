/*  $Id: dom_attr.h,v 1.12 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_attr
#define header_dom_attr

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Attribute class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>The Attr interface represents an attribute in an Element object. Typically
//- the allowable values for the attribute are defined in a document type definition.</p>
//- <p>Attr objects inherit the Node interface, but since they are not actually child
//- nodes of the element they describe, the DOM does not consider them part of the
//- document tree. Thus, the Node attributes parentNode, previousSibling, and nextSibling
//- have a null value for Attr objects. The DOM takes the view that attributes are
//- properties of elements rather than having a separate identity from the elements
//- they are associated with; this should make it more efficient to implement such
//- features as default attributes associated with all elements of a given type. Furthermore,
//- Attr nodes may not be immediate children of a DocumentFragment. However, they can
//- be associated with Element nodes contained within a DocumentFragment. In short,
//- users and implementors of the DOM need to be aware that Attr nodes have some
//- things in common with other objects inheriting the Node interface, but they also
//- are quite distinct.</p>
//- <p>The attribute's effective value is determined as follows: if this attribute
//- has been explicitly assigned any value, that value is the attribute's effective
//- value; otherwise, if there is a declaration for this attribute, and that declaration
//- includes a default value, then that default value is the attribute's effective value;
//- otherwise, the attribute does not exist on this element in the structure model until
//- it has been explicitly added. Note that the nodeValue attribute on the Attr instance
//- can also be used to retrieve the string version of the attribute's value(s).</p>
//- <p>In XML, where the value of an attribute can contain entity references, the child
//- nodes of the Attr node provide a representation in which entity references are not
//- expanded. These child nodes may be either Text or EntityReference nodes. Because the
//- attribute type may be unknown, there are no tokenized attribute values.</p>
class CL_DomAttr : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Attr handle.
	CL_DomAttr();
	
	CL_DomAttr(CL_DomDocument doc, const std::string &name);

	CL_DomAttr(const CL_SharedPtr<CL_DomNode_Generic> &impl);
	
	~CL_DomAttr();

//! Attributes:
public:
	//: Returns the name of this attribute.
	std::string get_name() const;

	//: If this attribute was explicitly given a value in the original document, this is true; otherwise, it is false.
	//- <ul>
	//- <li>If the attribute has an assigned value in the document then specified is true,
	//- and the value is the assigned value.</li>
	//- <li>If the attribute has no assigned value in the document and has a default value
	//- in the DTD, then specified is false, and the value is the default value in the DTD.</li>
	//- <li>If the attribute has no assigned value in the document and has a value of #IMPLIED
	//- in the DTD, then the attribute does not appear in the structure model of the document.</li>
	//- </ul>
	bool get_specified() const;
	
	//: Returns the value of the attribute.
	std::string get_value() const;

	//: Sets the value of the attribute.
	void set_value(const std::string &value);

//! Operations:
public:

//! Implementation:
private:
	friend class CL_DomElement;
};

#endif
