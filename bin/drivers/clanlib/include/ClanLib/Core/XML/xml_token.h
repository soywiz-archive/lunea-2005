/*  $Id: xml_token.h,v 1.8 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_xml_token
#define header_xml_token

#if _MSC_VER > 1000
#pragma once
#endif

//#include <map>
#include <string>

//class CL_XMLToken_Generic;

//: XML token in a XML file.
//- !group=Core/XML!
//- !header=core.h!
class CL_XMLToken
{
//! Construction:
public:
//	CL_XMLToken();
//	
//	CL_XMLToken(const CL_XMLToken &copy);
	
	virtual ~CL_XMLToken() {};
	
//! Attributes:
public:
	enum TokenType
	{
		NULL_TOKEN                     = 0,
		ELEMENT_TOKEN                  = 1,
		TEXT_TOKEN                     = 3,
		CDATA_SECTION_TOKEN            = 4,
		ENTITY_REFERENCE_TOKEN         = 5,
		ENTITY_TOKEN                   = 6,
		PROCESSING_INSTRUCTION_TOKEN   = 7,
		COMMENT_TOKEN                  = 8,
		DOCUMENT_TYPE_TOKEN            = 10,
		NOTATION_TOKEN                 = 12
	};
	
	enum TokenVariant
	{
		BEGIN  = 1,
		END    = 2,
		SINGLE = 3
	};

	//: Returns the token type.
	virtual TokenType get_type() const = 0;
	
	//: Returns the token variant.
	virtual TokenVariant get_variant() const = 0;
	
	//: Returns the name of the token.
	virtual std::string get_name() const = 0;
	
	//: Returns the value of the token.
	virtual std::string get_value() const = 0;
	
/*
	//: Returns all the attributes attached to the token.
	const std::vector< std::pair<std::string, std::string> > &get_attributes() const;
*/
	virtual int get_attributes_number() const = 0;

	//: Returns the attribute name and value for attribute with specified index.
	virtual std::pair<std::string, std::string> get_attribute(int attribute_num) const = 0;

	//: Returns the value of a named attribute.
//	virtual std::string get_attribute(const std::string &name) const = 0;

//! Operations:
//public:
	//: Copy assignment operator.
//	CL_XMLToken &operator =(const CL_XMLToken &copy);

//	//: Sets the type of the token.
//	void set_type(TokenType type);
//
//	//: Sets if token ends with a slash.
//	void set_variant(TokenVariant variant);
//
//	//: Sets the name of the token.
//	void set_name(const std::string &name);
//
//	//: Sets the value of the token.
//	void set_value(const std::string &value);
//	
//	//: Attaches attribute to token.
//	void set_attribute(const std::string &name, const std::string &value);

//! Implementation:
//private:
//	CL_XMLToken_Generic *impl;
};

#endif
