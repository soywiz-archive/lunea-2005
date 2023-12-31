/*  $Id: radiogroup.h,v 1.8 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_radiogroup
#define header_radiogroup

#if _MSC_VER > 1000
#pragma once
#endif

#include "../signals.h"
#include <vector>

class CL_RadioGroup_Generic;
class CL_RadioButton;

//: RadioGroup
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_RadioGroup
{
//! Construction:
public:
	//: RadioGroup Constructor
	CL_RadioGroup();

	//: RadioGroup Destructor
	~CL_RadioGroup();

//! Attributes:
public:
	//: Returns the amount of buttons added to the group.
	int get_count() const;
	
	//: Returns the selected button if any, NULL otherwise.
	CL_RadioButton *get_toggled() const;

	//: Returns all buttons in the group.
	const std::vector<CL_RadioButton *> &get_buttons() const;
	
//! Operations:
public:
	//: Adds a component into the group.
	void add(CL_RadioButton *button, bool delete_component = false);
	
	//: Removes a component from the group.
	void remove(CL_RadioButton *button);
	
	//: Sets a radiobutton active (and unchecks any other).
	void set_checked(CL_RadioButton *button);
	
//! Signals:
public:
	//: This signal is emitted when the radio selection is changed.
	CL_Signal_v1<CL_RadioButton *> &sig_selection_changed();

//! Implementation:
private:
	CL_RadioGroup(const CL_RadioGroup &copy) { return; } // disallow copy construction.
	CL_RadioGroup_Generic *impl;
};

#endif
