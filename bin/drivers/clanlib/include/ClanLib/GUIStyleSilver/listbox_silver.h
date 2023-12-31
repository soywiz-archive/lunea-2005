/*  $Id: listbox_silver.h,v 1.7 2004/01/06 14:21:55 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_listbox_silver
#define header_listbox_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/listbox.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_Font;
class CL_ScrollBar;

//: ListBox default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_ListBox_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_ListBox_Silver(
		CL_ListBox *listbox,
		CL_StyleManager_Silver *style);
	
	//: Destructor
	virtual ~CL_ListBox_Silver();

//! Implementation:
private:
	CL_SlotContainer slots;
	
	void on_mouse_down(const CL_InputEvent &key);
	void on_set_options(const CL_DomElement &options);
	void on_scroll_change(int new_offset);
	void on_resize(int old_width, int old_height);
	void on_paint_background();
	void on_paint_listbox();
	void on_item_added(int index);
	void on_item_removed(int index);
	void on_clear();
	
	void update_scrollbar(bool resize);

	CL_ListBox *listbox;

	CL_ScrollBar *scrollbar;
	bool visible_scrollbar;

	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	CL_Font *font;
};

#endif
