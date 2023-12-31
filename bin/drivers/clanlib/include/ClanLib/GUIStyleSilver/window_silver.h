/*  $Id: window_silver.h,v 1.5 2004/01/02 15:42:44 mbn Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_window_silver
#define header_window_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/window.h"
#include "../GUI/button.h"
#include "../GUI/component_style.h"
#include "../GUI/component_move_handler.h"
#include "../GUI/component_resize_handler.h"

class CL_StyleManager_Silver;
class CL_Font;

//: Window default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
//- <p>Script attributes:</p>
//- <ul>
//- <li>font: The font used to draw the caption. [String]</li>
//- </ul>
//- <p>Note that it inherits the attributes of CL_Window and CL_Component as well.</p>
class CL_Window_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_Window_Silver(
		CL_Window *window,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_Window_Silver();

//! Implementation:
private:
	CL_SlotContainer slots;

	void on_paint();
	void on_close();
	void on_resize(int old_width, int old_height);

	CL_Window *window;
	CL_Button *button_close;

	CL_ComponentMoveHandler *move_handler;
	CL_ComponentResizeHandler *resize_handler;

	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	
	CL_Font *font;
	CL_Font *font_disabled;

	int titlebar_height;
};

#endif
