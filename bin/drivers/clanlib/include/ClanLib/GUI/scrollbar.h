/*  $Id: scrollbar.h,v 1.53 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_scrollbar
#define header_scrollbar

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"

class CL_Button;
class CL_DomElement;
class CL_Rect;
class CL_ScrollBar_Generic;

//: ScrollBar component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_ScrollBar : public CL_Component
{
//! Construction:
public:
	//: ScrollBar Constructor
	CL_ScrollBar(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ScrollBar Constructor
	//param Orientation: false: Vertical scrollbar, true: Hortizonal scrollbar
	CL_ScrollBar(
		int min,
		int max,
		bool orientation,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ScrollBar Constructor
	//param Orientation: false: Vertical scrollbar, true: Hortizonal scrollbar
	CL_ScrollBar(
		bool orientation,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ScrollBar Constructor
	//param Orientation: false: Vertical scrollbar, true: Hortizonal scrollbar
	CL_ScrollBar(
		const CL_Rect &pos,
		int min,
		int max,
		bool orientation,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ScrollBar Constructor
	//param Orientation: false: Vertical scrollbar, true: Hortizonal scrollbar
	CL_ScrollBar(
		const CL_Rect &pos,
		bool orientation,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: ScrollBar Destructor
	virtual ~CL_ScrollBar();

//! Attributes:
public:
	//: Returns the orientation of the scroll bar.
	//return: true if scrollbar is vertical, false otherwise.
	bool is_vertical() const;

	//: Returns true if tracking is enabled, or false if tracking is disabled. 
	//: Tracking is initially enabled. See set_tracking for more info on tracking.
	bool is_tracking() const;

	//: Returns the current min value.
	int get_min_value() const;

	//: Returns the current max value.
	int get_max_value() const;

	//: Returns the range (delta max-min).
	int get_range() const;

	//: Returns the current range control value. 
	int get_value() const;

	//: Returns true if the user has clicked the mouse on the slider and is currently dragging it, or false if not. 
	bool is_dragging_slider() const;
	
	//: Returns true if this is a fixed length slider, false otherwise.
	bool is_fixed_length_slider() const;

	//: Returns the scroll bar slider rectangle. 
	CL_Rect &get_slider_rect() const;

	//: Returns the minimum size of the slider.
	//: Only usable in variable-length sliders.
	int get_min_slider_length() const;

//! Operations:
public:
	//: Sets the length-mode of the slider.
	//- <p>If enable is true, the slider is constant in size. (See set_slider_length()).
	//- If enable is false, the slider is resized automatically based on the range.</p>
	void set_fixed_length_mode(bool enabel = true);

	//: Sets the current size of the slider.
	//: Only usable in fixed-length sliders.
	void set_slider_length(int length);

	//: Sets the minimum size of the slider.
	//: Only usable in variable-length sliders.
	void set_min_slider_length(int length);

	//: Sets the scroll bar orientation to vertical if enable is true, horizontal otherwise.
	void set_vertical(bool enable = true);

	//: Enables scroll bar tracking if enable is true, or disables tracking if enable is false. 
	//- <p>If tracking is enabled (the default), the scroll bar emits the
	//- sig_value_changed() signal while the slider is being dragged. If tracking is
	//- disabled, the scroll bar emits the sig_value_changed() only when the user
	//- releases the mouse button after moving the slider.</p>
	void set_tracking(bool enable = true);

	//: Sets the range between min_value and max_value. 
	//: If max_value is smaller than min_value, max_value is set to min_value.
	void set_range(int min_value, int max_value);

	//: Sets the range to start from value. 
	//: If current maximum value is less than the minvalue, maxvalue is set to minvalue.
	void set_min_value(int value);

	//: Sets the range to end at value. 
	//: If current maximum value is less than the minvalue, maxvalue is set to minvalue.
	void set_max_value(int value);

	//: Sets the range controls value to value and forces it to be within the legal range. 
	void set_value(int value);

	//: Increases current value with step.
	void increase(int step = 1);

	//: Decreases current value with step.
	void decrease(int step = 1);

//! Signals:
public:
	//: This signal is emitted when the scroll bar value has changed, with the new scroll bar value as an argument. 
	//: See set_tracking() for specifics on this signal.
	CL_Signal_v1<int> &sig_value_changed();

	//: This signal is emitted when the user presses the slider with the mouse. 
	CL_Signal_v0 &sig_slider_pressed();

	//: This signal is emitted when the slider is moved by the user, with the new scroll bar value as an argument. 
	//: This signal is emitted even when tracking is turned off. 
	CL_Signal_v1<int> &sig_slider_moved();

	//: This signal is emitted when the user releases the slider with the mouse. 
	CL_Signal_v0 &sig_slider_released();

//! Implementation:
private:
	CL_ScrollBar(const CL_ScrollBar &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_ScrollBar_Generic *impl;
};

#endif
