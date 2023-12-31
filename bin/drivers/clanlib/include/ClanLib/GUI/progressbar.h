/*  $Id: progressbar.h,v 1.15 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_progressbar
#define header_progressbar

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_DomElement;
class CL_Rect;
class CL_ProgressBar_Generic;

//: ProgressBar component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_ProgressBar : public CL_Component
{
//! Construction:
public:
	//: ProgressBar Constructor
	CL_ProgressBar(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ProgressBar Constructor
	CL_ProgressBar(
		int steps,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ProgressBar Constructor
	CL_ProgressBar(
		const CL_Rect &pos,
		int steps,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ProgressBar Destructor
	virtual ~CL_ProgressBar();

//! Attributes:
public:
	//: Returns the total number of steps.
	int get_steps() const;

	//: Returns the current amount of progress.
	int get_progress() const;

	//: Returns the current amount of progress in percentage.
	float get_percentage() const;

//! Operations:
public:
	//: Sets the total number of steps to total_steps. 
	void set_steps(int total_steps);

	//: Sets the current amount of progress of the total number of steps. 
	void set_progress(int progress);

	//: Progresses the bar with steps.
	void increase(int steps = 1);

	//: Reset the progress bar. The progress bar `rewinds'. 
	void reset();

//! Signals:
public:

//! Implementation:
private:
	CL_ProgressBar(const CL_ProgressBar &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_ProgressBar_Generic *impl;
};

#endif
