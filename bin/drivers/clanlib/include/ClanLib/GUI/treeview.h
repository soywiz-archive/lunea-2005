/*  $Id: treeview.h,v 1.30 2004/01/09 22:19:14 grumbel Exp $
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

#ifndef header_treeview
#define header_treeview

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"
#include "treenode.h"

class CL_TreeView_Generic;

//: TreeView component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_TreeView : public CL_Component, public CL_TreeNode
{
//! Construction:
public:
	//: TreeView Constructor
	CL_TreeView(
		CL_Component *parent,
		CL_StyleManager *style = NULL);
	
	//: TreeView Constructor
	CL_TreeView(
		const CL_Rect &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: TreeView Destructor
	virtual ~CL_TreeView();

//! Attributes:
public:
	//: Returns the column count.
	int get_column_count() const;

	//: Returns the column width at index.
	//: Index starts at 0.
	int get_column_width(int index) const;

	//: Returns the column name at index.
	//: Index starts at 0.
	const std::string &get_column_name(int index) const;

	//: Returns if root decoration is visible or not.
	bool is_root_decoration_visible() const;

	//: Returns if header is visible or not.
	bool is_header_visible() const;

//! Operations:
public:
	//: Add a column.
	int add_column(const std::string &name, int width);

	//: Show or hide root decoration for items.
	void show_root_decoration(bool enable = true);

	//: Show or hide columns.
	void show_header(bool enable = true);

//! Signals:
public:
	//: This signal is emitted when the selection set of a tree changes.
	CL_Signal_v1<const CL_TreeNode &> &sig_selection_changed();

	//: This signal is emitted when an item is clicked / selected.
	CL_Signal_v1<const CL_TreeNode &> &sig_item_clicked();

	//: This signal is emitted when a new item is added to the treeview.
	CL_Signal_v1<const CL_TreeNode &> &sig_item_added();

	//: This signal is emitted when an item is removed from the treeview.
	CL_Signal_v1<const CL_TreeNode &> &sig_item_removed();
	
	//: This signal is emitted when an item is collapsed.
	CL_Signal_v1<const CL_TreeNode &> &sig_item_collapsed();

	//: This signal is emitted when an item is collapsed.
	CL_Signal_v1<const CL_TreeNode &> &sig_item_expanded();
	
	//: This signal is emitted when a new column is added to the treeview.
	CL_Signal_v1<int> &sig_column_added();

	//: This signal is emitted when an column is removed from the treeview.
	CL_Signal_v1<int> &sig_column_removed();
	
	//: This signal is emitted when the treeview is cleared.
	CL_Signal_v0 &sig_clear();

	//: Draws the node (used by styles).
	CL_Signal_v2<CL_TreeNode *, CL_Point &> &sig_paint_node();

//! Implementation:
private:
	CL_TreeView(const CL_TreeView &copy) : CL_Component(NULL, NULL), CL_TreeNode(NULL, NULL) { return; } // disallow copy construction.
	CL_TreeView_Generic *impl;
};

#endif
