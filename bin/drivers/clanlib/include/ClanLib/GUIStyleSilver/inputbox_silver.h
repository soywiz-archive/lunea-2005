/*  $Id: inputbox_silver.h,v 1.7 2004/01/03 23:03:22 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_inputbox_silver
#define header_inputbox_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/inputbox.h"
#include "../GUI/component_style.h"

class CL_Font;
class CL_StyleManager_Silver;

//: InputBox default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_InputBox_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_InputBox_Silver(
		CL_InputBox *inputbox,
		CL_StyleManager_Silver *style);
	
	//: Destructor
	virtual ~CL_InputBox_Silver();

//! Operations:
public:
	//: Sets the size of the border around inputbox.
	void set_border_size(int size);

//! Implementation:
private:
	CL_Slot slot_paint;
	void on_paint();

	CL_Slot slot_activity;
	void on_activity();
	CL_Slot slot_get_preferred_size;
	void on_get_preferred_size(CL_Size &size);

	CL_InputBox *inputbox;

	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	CL_Font *font;
	CL_Font *font_disabled;

	int character_offset;

	bool show_cursor;
	unsigned int cursor_blink_time;

	int border_size;
	
//	int get_mouse_position(int x, int y);
};

#endif
