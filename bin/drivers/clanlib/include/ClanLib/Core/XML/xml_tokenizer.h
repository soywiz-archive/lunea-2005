/*  $Id: xml_tokenizer.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_xml_tokenizer
#define header_xml_tokenizer

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

class CL_InputSource;
class CL_XMLTokenLoad;
class CL_XMLTokenizer_Generic;

//: The XML Tokenizer breaks a XML file into XML tokens.
//- !group=Core/XML!
//- !header=core.h!
class CL_XMLTokenizer
{
//! Construction:
public:
	CL_XMLTokenizer();
	
	CL_XMLTokenizer(const CL_XMLTokenizer &copy);

	CL_XMLTokenizer(CL_InputSource *input, bool delete_input = false);
	
	virtual ~CL_XMLTokenizer();
	
//! Attributes:
public:
	//: Returns true if eat whitespace flag is set.
	bool get_eat_whitespace() const;

	//: If enabled, will eat any whitespace between tags.
	void set_eat_whitespace(bool enable);

//! Operations:
public:
	//: Returns the next token available in input stream.
	CL_XMLTokenLoad next();

//! Implementation:
private:
	CL_SharedPtr<CL_XMLTokenizer_Generic> impl;
};

#endif
