/*  $Id: inputdialog.h,v 1.13 2004/01/08 18:55:32 sphair Exp $
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

#ifndef header_inputdialog
#define header_inputdialog

#if _MSC_VER > 1000
#pragma once
#endif

#include "window.h"

class CL_InputDialog_Generic;
class CL_InputBox;
class CL_CheckBox;

//: CL_InputDialog component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_InputDialog : public CL_Window
{
//! Construction:
public:
	//: CL_InputDialog constructor
	CL_InputDialog(
		const std::string &title,
		const std::string &button1,
		const std::string &button2,
		const std::string &button3,
		CL_Component *parent,
		CL_StyleManager *style = NULL);
	
	//: CL_InputDialog destructor
	virtual ~CL_InputDialog();

//! Operations:
public:
	//: Add inputbox with label to dialog.
	//: The inputbox is deleted by the InputDialog when destroyed.
	CL_InputBox *add_input_box(
		const std::string &label = "",
		const std::string &default_value = "",
		int inputbox_width = 100);

	//: Add checkbox with label to dialog.
	//: The checkbox is deleted by the InputDialog when destroyed.
	CL_CheckBox *add_check_box(
		const std::string &text = "",
		bool checked = false,
		int check_box_width = 100);

	//: Returns the number of the button that was used to close the dialog.
	int get_result_button();

//! Implementation:
private:
	CL_InputDialog(const CL_InputDialog &copy) : CL_Window(NULL, NULL) { return; } // disallow copy construction.

	CL_InputDialog_Generic *impl;
};

#endif
