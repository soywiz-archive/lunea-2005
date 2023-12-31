/*  $Id: frame.h,v 1.29 2004/01/02 15:42:43 mbn Exp $
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

//! clanGUI="Controls"
//! header=gui.h

#ifndef header_frame
#define header_frame

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_Frame_Generic;

//: Frame component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_Frame : public CL_Component
{
//! Construction:
public:
	//: Frame Constructor
	CL_Frame(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Frame Constructor
	CL_Frame(
		const CL_Rect &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Frame Destructor
	virtual ~CL_Frame();

//! Attributes:
public:
	//: Is fill enabled
	bool is_fill_enabled() const;

//! Operations:
public:
	//: Enable Fill
	void enable_fill(bool enabled = true);

//! Implementation:
private:
	CL_Frame(const CL_Frame &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_Frame_Generic *impl;
};  

#endif
