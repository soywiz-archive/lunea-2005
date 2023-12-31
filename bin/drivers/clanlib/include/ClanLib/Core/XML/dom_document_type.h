/*  $Id: dom_document_type.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_document_type
#define header_dom_document_type

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

class CL_DomNamedNodeMap;

//: DOM Document Type class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>Each Document has a doctype attribute whose value is either null
//- or a DocumentType object. The DocumentType interface in the DOM Level 1
//- Core provides an interface to the list of entities that are defined for
//- the document, and little else because the effect of namespaces and the
//- various XML scheme efforts on DTD representation are not clearly understood
//- as of this writing.</p>
//- <p>The DOM Level 1 doesn't support editing DocumentType nodes.</p>
class CL_DomDocumentType : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Document Type handle.
	CL_DomDocumentType();

	CL_DomDocumentType(CL_DomDocument &doc);
	
	CL_DomDocumentType(const CL_SharedPtr<CL_DomNode_Generic> &impl);

	~CL_DomDocumentType();

//! Attributes:
public:
	//: The name of DTD; i.e., the name immediately following the DOCTYPE keyword.
	std::string get_name() const;

	//: A NamedNodeMap containing the general entities, both external and internal, declared in the DTD.
	CL_DomNamedNodeMap get_entities() const;

	//: A NamedNodeMap containing the notations declared in the DTD.
	CL_DomNamedNodeMap get_notations() const;

//! Operations:
public:
};

#endif
