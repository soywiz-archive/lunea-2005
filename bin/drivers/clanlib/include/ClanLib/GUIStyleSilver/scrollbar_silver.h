/*  $Id: scrollbar_silver.h,v 1.6 2004/01/02 15:42:44 mbn Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_scrollbar_silver
#define header_scrollbar_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/timer.h"
#include "../GUI/scrollbar.h"
#include "../GUI/component_style.h"

class CL_ResourceManager;
class CL_Surface;
class CL_StyleManager_Silver;

//: ScrollBar default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_ScrollBar_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_ScrollBar_Silver(
		CL_ScrollBar *scrollbar,
		CL_StyleManager_Silver *style);
	
	//: Destructor
	virtual ~CL_ScrollBar_Silver();

//! Implementation:
private:
	void start_scroll(int delta);
	void stop_scroll();

	void on_paint();
	void on_timer_scroll();
	void on_resize(int old_width, int old_height);
	void on_set_options(const CL_DomElement &options);

	CL_SlotContainer slots;

	CL_Timer timer_scroll;
	int scroll_delta;

	CL_ScrollBar *scrollbar;
	
	CL_Button *button_increase;
	CL_Button *button_decrease;

	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	CL_Surface *sur_increase_normal;
	CL_Surface *sur_increase_toggled;
	CL_Surface *sur_decrease_normal;
	CL_Surface *sur_decrease_toggled;
};

#endif

