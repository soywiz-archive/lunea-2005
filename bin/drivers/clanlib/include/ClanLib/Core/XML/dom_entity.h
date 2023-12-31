/*  $Id: dom_entity.h,v 1.10 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_entity
#define header_dom_entity

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Entity class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>This interface represents an entity, either parsed or unparsed, in an
//- XML document. Note that this models the entity itself not the entity
//- declaration. Entity declaration modeling has been left for a later Level
//- of the DOM specification.</p>
class CL_DomEntity : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Entity handle.
	CL_DomEntity();
	
	CL_DomEntity(const CL_SharedPtr<CL_DomNode_Generic> &impl);

	~CL_DomEntity();

//! Attributes:
public:
	//: The public identifier associated with the entity.
	//- <p>If the public identifier was not specified, this is null.</p>
	std::string get_public_id() const;

	//: The system identifier associated with the entity.
	//- <p>If the system identifier was not specified, this is null.</p>
	std::string get_system_id() const;

	//: For unparsed entities, the name of the notation for the entity.
	//- <p>For parsed entities, this is null.</p>
	std::string get_notation_name() const;

//! Operations:
public:
};

#endif
