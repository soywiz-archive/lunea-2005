/*  $Id: dom_character_data.h,v 1.10 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_dom_character_data
#define header_dom_character_data

#if _MSC_VER > 1000
#pragma once
#endif

#include "dom_node.h"

//: DOM Character Data class.
//- !group=Core/XML!
//- !header=core.h!
//- <p>The CharacterData interface extends Node with a set of attributes and methods
//- for accessing character data in the DOM. For clarity this set is defined here
//- rather than on each object that uses these attributes and methods. No DOM objects
//- correspond directly to CharacterData, though Text and others do inherit the
//- interface from it.</p>
class CL_DomCharacterData : public CL_DomNode
{
//! Construction:
public:
	//: Constructs a DOM CharacterData handle.
	CL_DomCharacterData();

	CL_DomCharacterData(const CL_SharedPtr<CL_DomNode_Generic> &impl);
	
	~CL_DomCharacterData();
	
//! Attributes:
public:
	//: The number of characters that are available through data and the substringData method below.
	//- <p>This may have the value zero, i.e., CharacterData nodes may be empty.</p>
	unsigned long get_length();

//! Operations:
public:
	//: Extracts a range of data from the node.
	//param offset: Start offset of substring to extract.
	//param count: The number of characters to extract.
	//retval: The specified substring. If the sum of offset and count exceeds the length, then all characters to the end of the data are returned.
	std::string substring_data(unsigned long offset, unsigned long count);

	//: Append the string to the end of the character data of the node.
	void append_data(const std::string &arg);

	//: Insert a string at the specified character offset.
	//param offset: The character offset at which to insert.
	//param arg: The DOMString to insert.
	void insert_data(unsigned long offset, const std::string &arg);

	//: Remove a range of characters from the node.
	//param offset: The offset from which to remove characters.
	//param count: The number of characters to delete. If the sum of offset and count exceeds length then all characters from offset to the end of the data are deleted.
	void delete_data(unsigned long offset, unsigned long count);

	//: Replace the characters starting at the specified character offset with the specified string.
	//param offset: The offset from which to start replacing.
	//param count: The number of characters to replace. If the sum of offset and count exceeds length, then all characters to the end of the data are replaced (i.e., the effect is the same as a remove method call with the same range, followed by an append method invocation).
	//param arg: The DOMString with which the range must be replaced.
	void replace_data(unsigned long offset, unsigned long count, const std::string &arg);

//! Implementation:
protected:
	CL_DomCharacterData(CL_DomDocument &doc, unsigned short node_type);
};

#endif
