/*  $Id: treeview_silver.h,v 1.6 2004/01/12 08:20:41 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_treeview_silver
#define header_treeview_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/treeview.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_Font;
class CL_ScrollBar;

//: Theme class for CL_TreeView for Silver theme.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_TreeView_Silver : public CL_ComponentStyle
{
public:
	CL_TreeView_Silver(
		CL_TreeView *listbox,
		CL_StyleManager_Silver *style);
	
	virtual ~CL_TreeView_Silver() {};

private:
	CL_SlotContainer slots;

	void on_resize(int old_width, int old_height);
	void on_paint();
	void on_paint_client();
	void on_paint_node(CL_TreeNode *node, CL_Point &point);
	void on_mouse_down(const CL_InputEvent &key);
	void on_item_changed(const CL_TreeNode &node);
	void on_column_added(int index);
	void on_column_removed(int index);
	void on_clear();

	void update_scrollbar(bool resize);

	CL_TreeView *treeview;

	CL_ScrollBar *scrollbar;
	bool visible_scrollbar;

	CL_Font *font;

	CL_StyleManager_Silver *style;
};

#endif
