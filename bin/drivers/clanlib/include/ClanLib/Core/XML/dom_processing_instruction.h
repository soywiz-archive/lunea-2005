/*  $Id: dom_processing_instruction.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_processing_instruction
#define header_dom_processing_instruction

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Processing Instruction class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>The ProcessingInstruction interface represents a "processing instruction", used in
//- XML as a way to keep processor-specific information in the text of the document.</p>
class CL_DomProcessingInstruction : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM Processing Instruction handle.
	CL_DomProcessingInstruction();
	
	CL_DomProcessingInstruction(CL_DomDocument &doc, const std::string &target, const std::string &data);

	CL_DomProcessingInstruction(const CL_SharedPtr<CL_DomNode_Generic> &impl);

	~CL_DomProcessingInstruction();
	
//! Attributes:
public:
	//: The target of this processing instruction.
	//- <p>XML defines this as being the first token following the markup that begins
	//- the processing instruction.</p>
	std::string get_target() const;

	//: The content of this processing instruction.
	//- <p>This is from the first non white space character after the target to the
	//- character immediately preceding the ?&gt;.</p>
	std::string get_data() const;
	
	void set_data(const std::string &data);

//! Operations:
public:
};

#endif
