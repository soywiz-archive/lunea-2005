/*  $Id: dom_exception.h,v 1.5 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_dom_exception
#define header_dom_exception

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/error.h"

//: DOM Exception class.
//- !group=Core/XML!
//- !header=core.h!
class CL_DomException : public CL_Error
{
//! Construction:
public:
	CL_DomException(unsigned short code);

	CL_DomException(
		const std::string &message,
		unsigned short code);

//! Attributes:
public:
	enum ExceptionCodes
	{
		INDEX_SIZE_ERR               = 1,
		DOMSTRING_SIZE_ERR           = 2,
		HIERARCHY_REQUEST_ERR        = 3,
		WRONG_DOCUMENT_ERR           = 4,
		INVALID_CHARACTER_ERR        = 5,
		NO_DATA_ALLOWED_ERR          = 6,
		NO_MODIFICATION_ALLOWED_ERR  = 7,
		NOT_FOUND_ERR                = 8,
		NOT_SUPPORTED_ERR            = 9,
		INUSE_ATTRIBUTE_ERR          = 10
	};

	unsigned short code;
	
//! Implementation:
private:
};

#endif
