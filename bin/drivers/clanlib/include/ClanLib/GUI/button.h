/*  $Id: button.h,v 1.69 2004/03/28 13:01:41 sphair Exp $
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

#ifndef header_button
#define header_button

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_Surface;
class CL_Button_Generic;

//: Button component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_Button : public CL_Component
{
//! Construction:
public:
	//: Button Constructor
	CL_Button(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Button Constructor
	CL_Button(
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Button Constructor
	CL_Button(
		const CL_Point &pos,
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Button Constructor
	CL_Button(
		const CL_Rect &pos,
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Button Constructor
	CL_Button(
		const CL_Rect &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Button Constructor
	CL_Button(
		const CL_Point &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Button Destructor
	virtual ~CL_Button();

//! Attributes:
public:
	//: Returns the button text.
	const std::string &get_text() const;

	//: Returns true if the button is a toggle button.
	bool is_toggle_button() const;

	//: Returns true if the button state is down, or false if it is raised.
	bool is_down() const;

	//: Returns true if the button is visually pressed down, or false if it is raised.
	//: This can be used by theme, to get immediate state of the button.
	bool is_drawn_down() const;

//! Operations:
public:
	//: Sets the button text.
	void set_text(const std::string &text);

	//: If toggle is true, pressing the button toggles it between an On and and Off state. 
	//: If toggle is false, pressing the button causes an action, then the button returns to the unpressed state. 
	void set_toggle_mode(bool toggle = true);

	//: Sets the state of the button to pressed down if enable is true or to standing up if enable is false. 
	//: No signals are not emitted by this function. 
	void set_down(bool enable = true);

	//: Toggle the button.
	//: The toggled() signal are emitted by this function.
	void toggle();

//! Signals:
public:
	//: This signal is emitted whenever a toggle button changes status.
	//param bool on: Is true if the button is on, or false otherwise.
	CL_Signal_v1<bool> &sig_toggled();

	//: This signal is emitted when the button is activated (i.e. first pressed down and then released when the mouse cursor is inside the button).
	CL_Signal_v0 &sig_clicked();
	
	//: This signal is emitted when the button is pressed down. 
	//: In most cases, you want to use sig_clicked() instead.
	CL_Signal_v0 &sig_pressed();

	//: This signal is emitted when the button is released.
	//: In most cases, you want to use sig_clicked() instead.
	CL_Signal_v0 &sig_released();

//! Implementation:
private:
	CL_Button(const CL_Button &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_Button_Generic *impl;
};

#endif
