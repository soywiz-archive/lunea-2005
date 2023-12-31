/*  $Id: radiobutton.h,v 1.8 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_radiobutton
#define header_radiobutton

#if _MSC_VER > 1000
#pragma once
#endif

#include "button.h"

//: CheckBox component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_RadioButton : public CL_Button
{
//! Construction:
public:
	//: RadioButton constructor
	CL_RadioButton(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: RadioButton constructor
	CL_RadioButton(
		const CL_Point &pos,
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: RadioButton constructor
	CL_RadioButton(
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: RadioButton destructor
	virtual ~CL_RadioButton();

//! Attributes:
public:
	//: Returns true if the radiobutton is checked, or false if it is not checked.
	bool is_checked() const;

//! Operations:
public:
	//: Checks the radiobutton if check is true, or unchecks it if check is false. 
	void set_checked(bool check);

//! Implementation:
private:
	CL_RadioButton(const CL_RadioButton &copy) : CL_Button(NULL, NULL) { return; } // disallow copy construction.
};  

#endif
