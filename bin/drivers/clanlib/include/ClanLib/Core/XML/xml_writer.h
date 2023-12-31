/*  $Id: xml_writer.h,v 1.9 2004/02/01 04:31:55 mbn Exp $
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

#ifndef header_xml_writer
#define header_xml_writer

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/sharedptr.h"

class CL_OutputSource;
class CL_XMLTokenSave;
class CL_XMLWriter_Generic;

//: The XML Writer writes a XML file based on XML tokens.
//- !group=Core/XML!
//- !header=core.h!
class CL_XMLWriter
{
//! Construction:
public:
	CL_XMLWriter();
	
	CL_XMLWriter(const CL_XMLWriter &copy);
	
	CL_XMLWriter(CL_OutputSource *output, bool delete_output = false);
	
	virtual ~CL_XMLWriter();

//! Attributes:
public:
	//: Returns the insert whitespace flag.
	bool get_insert_whitespace() const;

	//: Inserts whitespace between tags if enabled.
	void set_insert_whitespace(bool enable);

//! Operations:
public:
	//: Write token to file.
	void write(const CL_XMLTokenSave &token);
	
//! Implementation:
private:
	CL_SharedPtr<CL_XMLWriter_Generic> impl;
};

#endif
