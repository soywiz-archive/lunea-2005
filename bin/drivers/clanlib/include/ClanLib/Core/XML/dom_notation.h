/*  $Id: dom_notation.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_notation
#define header_dom_notation

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Notation class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>This interface represents a notation declared in the DTD. A notation either declares,
//- by name, the format of an unparsed entity (see section 4.7 of the XML 1.0 specification),
//- or is used for formal declaration of Processing Instruction targets (see section 2.6 of
//- the XML 1.0 specification). The node name attribute inherited from Node is set to the
//- declared name of the notation.</p>
//- <p>The DOM Level 1 does not support editing Notation nodes; they are therefore readonly.</p>
//- <p>A Notation node does not have any parent.</p>
class CL_DomNotation : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Notation handle.
	CL_DomNotation();
	
	CL_DomNotation(const CL_SharedPtr<CL_DomNode_Generic> &impl);

	~CL_DomNotation();
	
//! Attributes:
public:
	//: The public identifier of this notation.
	//- <p>If the public identifier was not specified, this is null.</p>
	std::string get_public_id() const;

	//: The system identifier of this notation.
	//- <p>If the system identifier was not specified, this is null.</p>
	std::string get_system_id() const;

//! Operations:
public:
};

#endif
