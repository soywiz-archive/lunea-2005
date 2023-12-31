/*  $Id: dom_text.h,v 1.10 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_text
#define header_dom_text

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_character_data.h"

//: DOM Text class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>The Text interface represents the textual content (termed character data
//- in XML) of an Element or Attr. If there is no markup inside an element's content,
//- the text is contained in a single object implementing the Text interface that is
//- the only child of the element. If there is markup, it is parsed into a list of
//- elements and Text nodes that form the list of children of the element.</p>
//- <p>When a document is first made available via the DOM, there is only one Text
//- node for each block of text. Users may create adjacent Text nodes that represent
//- the contents of a given element without any intervening markup, but should be aware
//- that there is no way to represent the separations between these nodes in XML or HTML,
//- so they will not (in general) persist between DOM editing sessions. The normalize()
//- method on Element merges any such adjacent Text objects into a single node for each
//- block of text; this is recommended before employing operations that depend on a
//- particular document structure, such as navigation with XPointers.</p>
class CL_DomText : public CL_DomCharacterData
{
//! Construction:
public:
	//: Constructs a DOM Text handle.
	CL_DomText();

	CL_DomText(CL_DomDocument &doc, const std::string &data);

	CL_DomText(const CL_SharedPtr<CL_DomNode_Generic> &impl);
	
	~CL_DomText();

//! Attributes:
public:

//! Operations:
public:
	//: Breaks this Text node into two Text nodes at the specified offset, keeping both in the tree as siblings.
	//- <p>node then only contains all the content up to the offset point. And a new Text node, which
	//- is inserted as the next sibling of this node, contains all the content at and after the offset
	//- point.</p>
	//param offset: The offset at which to split.
	//retval: The new Text node.
	CL_DomText splitText(unsigned long offset);

//! Implementation:
protected:
	CL_DomText(CL_DomDocument &doc, unsigned short node_type);
};

#endif
