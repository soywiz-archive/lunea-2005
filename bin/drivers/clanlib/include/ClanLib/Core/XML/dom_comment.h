/*  $Id: dom_comment.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_comment
#define header_dom_comment

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_character_data.h"

//: DOM Comment class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>This represents the content of a comment, i.e., all the characters between the starting
//- '&lt;!--' and ending '--&gt;'. Note that this is the definition of a comment in XML, and,
//- in practice, HTML, although some HTML tools may implement the full SGML comment structure.</p>
class CL_DomComment : public CL_DomCharacterData
{
//! Construction:
public:
	//: Constructs a DOM Comment handle.
	CL_DomComment();

	CL_DomComment(CL_DomDocument &doc, const std::string &data);

	CL_DomComment(const CL_SharedPtr<CL_DomNode_Generic> &impl);
	
	~CL_DomComment();

//! Attributes:
public:

//! Operations:
public:
};

#endif
