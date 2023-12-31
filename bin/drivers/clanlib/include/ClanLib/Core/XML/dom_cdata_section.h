/*  $Id: dom_cdata_section.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_cdata_section
#define header_dom_cdata_section

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_text.h"

//: DOM CDATA Section.
//- !group=Core/XML!
//- !header=core.h!
//- <p>CDATA sections are used to escape blocks of text containing characters that would
//- otherwise be regarded as markup. The only delimiter that is recognized in a CDATA
//- section is the "]]>" string that ends the CDATA section. CDATA sections can not be
//- nested. The primary purpose is for including material such as XML fragments, without
//- needing to escape all the delimiters.</p>
//- <p>The DOMString attribute of the Text node holds the text that is contained by the
//- CDATA section. Note that this may contain characters that need to be escaped outside
//- of CDATA sections and that, depending on the character encoding ("charset") chosen
//- for serialization, it may be impossible to write out some characters as part of a
//- CDATA section.</p>
//- <p>The CDATASection interface inherits the CharacterData interface through the Text
//- interface. Adjacent CDATASections nodes are not merged by use of the Element.normalize()
//- method.</p>
class CL_DomCDATASection : public CL_DomText
{
//! Construction:
public:
	//: Constructs a DOM CDATA Section handle.
	CL_DomCDATASection();

	CL_DomCDATASection(CL_DomDocument &doc, const std::string &data);

	CL_DomCDATASection(const CL_SharedPtr<CL_DomNode_Generic> &impl);
	
	~CL_DomCDATASection();

//! Attributes:
public:

//! Operations:
public:
};

#endif
