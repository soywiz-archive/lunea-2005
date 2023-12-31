/*  $Id: label.h,v 1.42 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_label
#define header_label

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"
#include "../Core/Math/origin.h"

class CL_Label_Generic;

//: Label component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_Label : public CL_Component
{
//! Construction:
public:
	//: Label Constructor
	CL_Label(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Label Constructor
	CL_Label(
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Label Constructor
	CL_Label(
		const CL_Point &pos,
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Label Constructor
	CL_Label(
		const CL_Rect &pos,
		const std::string &text,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Label Destructor
	virtual ~CL_Label();

//! Attributes:
public:
	//: Returns the labeltext.
	const std::string &get_text() const;

	//: Returns the alignment setting.
	//: See set_alignment() for more info.
	CL_Origin get_alignment() const;

//! Operations:
public:
	//: Sets the labeltext.
	void set_text(const std::string &text);

	//: Sets the label contents to a plain text containing the printed value of num.
	void set_text(int number);

	//: Sets the label contents to a plain text containing the printed value of num.
	void set_text(double number);

	//: Clears any label contents. Equivalent with setText("").
	void clear();

	//: Sets the alignment of the label contents
	void set_alignment(CL_Origin alignment);

//! Implementation:
private:
	void init(const std::string &text);

	CL_Label(const CL_Label &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_Label_Generic *impl;
};  

#endif
