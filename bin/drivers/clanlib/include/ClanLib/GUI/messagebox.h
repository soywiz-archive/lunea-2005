/*  $Id: messagebox.h,v 1.28 2004/03/29 13:19:02 sphair Exp $
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

#ifndef header_messagebox
#define header_messagebox

#if _MSC_VER > 1000
#pragma once
#endif

#include "window.h"

class CL_MessageBox_Generic;

//: MessageBox component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_MessageBox : public CL_Window
{
//! Construction:
public:
	//: MessageBox constructor
	CL_MessageBox(
		const std::string &title,
		const std::string &text,
		const std::string &button1,
		const std::string &button2,
		const std::string &button3,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: MessageBox destructor
	virtual ~CL_MessageBox();

	//: Creates a messagebox.
	//: Returns the button clicked, starting at index 0.
	static int info(
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	static int info(
		const std::string &title,
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	static int info(
		const std::string &title,
		const std::string &text,
		const std::string &button1,
		const std::string &button2,
		const std::string &button3,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

//! Attributes:
public:
	//: Returns the index of the button clicked.
	int get_result_button() const;

//! Implementation:
private:
	CL_MessageBox(const CL_MessageBox &copy) : CL_Window(NULL, NULL) { return; } // disallow copy construction.

	CL_MessageBox_Generic *impl;
};

#endif
