/*  $Id: treenode.h,v 1.20 2004/02/24 22:08:34 sphair Exp $
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

#ifndef header_treenode
#define header_treenode

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/Math/point.h"
#include <string>

class CL_TreeItem;
class CL_TreeView;
class CL_TreeNode_Generic;
class CL_Component;

//: TreeView node
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_TreeNode
{
//! Construction:
public:
	//: The treenode constructor.
	//- <p>Not to be constructed by user - use insert_item() instead, which
	//- creates a CL_TreeNode.</p>
	CL_TreeNode(CL_TreeNode *parent, CL_TreeView *root_tree);
	
	virtual ~CL_TreeNode();

//! Attributes:
public:
	//: Returns true if node is selectable.
	bool is_selectable() const;

	//: Returns true if node is collapsable.
	bool is_collapsable() const;

	//: Returns true if node is selected.
	bool is_selected() const;
	
	//: Return true if node is collapsed.
	bool is_collapsed() const;

	//: Return true if node has sub-items.
	bool has_children() const;

	//: Returns true if node is root item.
	bool is_root() const;

	//: Returns the current selected item.
	//: Note: This searches children as well.
	CL_TreeNode *get_current_item() const;

	//: Returns the attaches userdata, if any.
	void *get_userdata() const;

	//: Returns the CL_Component this node uses.
	CL_Component *get_component() const;

	//: Returns the CL_TreeView this node belongs to.
	CL_TreeView *get_treeview() const;

	//: Returns the parent node.
	CL_TreeNode *get_parent() const;

	//: Returns the depth of this node. Root node starts at 1.
	int get_depth() const;

	//: Returns the x offset the component is located at.
	//: Used by themes to align columns correctly.
	int get_placement_offset() const;

	//: Returns the height of all opened items.
	int get_items_height() const;

//! Operations:
public:
	//: Inserts a child item. 
	CL_TreeItem *insert_item(
		const std::string &label1, 
		const std::string &label2 = std::string(),
		const std::string &label3 = std::string(),
		const std::string &label4 = std::string(),
		const std::string &label5 = std::string(),
		const std::string &label6 = std::string(),
		const std::string &label7 = std::string(),
		const std::string &label8 = std::string());

	//: Inserts a child item. 
	//: It takes ownership of the components, and deletes them on shutdown.
	CL_TreeNode *insert_item(
		CL_Component *component1, 
		CL_Component *component2 = NULL, 
		CL_Component *component3 = NULL, 
		CL_Component *component4 = NULL, 
		CL_Component *component5 = NULL, 
		CL_Component *component6 = NULL, 
		CL_Component *component7 = NULL, 
		CL_Component *component8 = NULL);

	//: Removes an item from tree.
	//: Note that it searches children as well for the item.
	//: Returns true if item was found and deleted.
	bool remove_item(CL_TreeNode *node);

	//: Sets/changes a new component for the node.
	//: It takes ownership of the component, and deletes it on shutdown.
	void set_component(CL_Component *component);

	//: Collapse this node.
	void set_collapsed(bool collapse = true);
	
	//: Set the tree to collapsable or not.
	//: If set to false, item will never be collapsable by the user.
	void set_collapsable(bool enable = true);
	
	//: Set the tree to selectable or not.
	//: If set to false, item will never be selectable by the user.
	void set_selectable(bool enable = true);

	//: Select this node.
	void set_selected(bool select = true);

	//: Select any of the children nodes.
	void set_selected(CL_TreeNode *node, bool select = true);

	//: Deselects current selected item.
	void clear_selection();

	//: Inverts the selection.
	//: Works only in Multi selection mode.
	void invert_selection();

	//: Deletes all items in the tree.
	void clear();

	//: Attaches userdata to node.
	void set_userdata(void *data);

	//: Set the x offset the component is located at.
	//: Used by themes to align columns correctly.
	void set_placement_offset(int offset);

//! Implementation:
private:
	CL_TreeNode(const CL_TreeNode &copy) { return; } // disallow copy construction.
	CL_TreeNode_Generic *impl;

	friend class CL_TreeView_Generic;
	friend class CL_TreeNode_Generic;
};

#endif
