/*  $Id: listbox.h,v 1.57 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_listbox
#define header_listbox

#if _MSC_VER > 1000
#pragma once
#endif

#include "component.h"
#include "listitem.h"

class CL_ListBox_Generic;

//: Listbox component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_ListBox : public CL_Component
{
//! Construction:
public:
	//: Listbox constructor
	CL_ListBox(
		CL_Component *parent,
		CL_StyleManager *style = NULL);
	
	//: Listbox constructor
	CL_ListBox(
		const CL_Rect &pos,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: Listbox destructor
	virtual ~CL_ListBox();

//! Attributes:
public:
	//: Returns the number of items in the list box. 
	int get_count() const;

	//: Returns items in the list.
	std::vector<CL_ListItem *> &get_items() const;

	//: Returns selected items as strings.
 	std::vector<std::string> get_selected_items() const;

	//: Returns the text of the current item.
	//- <p>Returns "" if item not found. Best to use on single-selection lists, as it will only
	//- return the first selected item.</p>
	const std::string &get_current_text() const;

	//: Returns an item.
	//- <p>Returns NULL if item was not found.</p>S
	CL_ListItem *get_item(int index) const;

	//: Returns the text for an item.
	const std::string &get_text(int index) const;
	
	//: Returns the index of the current item of the listbox, or -1 if no item has been selected. 
	int get_current_item() const;

	//: Returns true if item index is selected. Returns false if it is not selected or if there is an error.
	bool is_selected(int index) const;

	//: Returns true if the listbox is in multiselection mode.
	bool is_multi_selection() const;

	//: Returns the height of one item.
	int get_item_height() const;

	//: Returns the index of the item at the top of the screen.
	int get_top_item() const;

//! Operations:
public:
	//: Inserts a listitem into the list at index. 
	//- <p>If index is negative, text is inserted at the end of the list.
	//- Returns the index of the text</p>
	int insert_item(CL_ListItem *item, int index = -1, bool delete_item = false);

	//: Inserts text into the list at index. 
	//- <p>If index is negative, text is inserted at the end of the list.
	//- Returns the index of the text</p>
	int insert_item(const std::string &text, int index = -1);

	//: Removes and deletes the item at position index.
	//- <p>If index is equal to get_current_item(), a new item gets highlighted and the sig_highlighted() signal is emitted.</p>
	void remove_item(int index);

	//: Replaces the item at position index with new item. 
	void change_item(CL_ListItem *item, int index);

	//: Replaces the item at position index with text. 
	void change_item(const std::string &text, int index);

	//: Sets the highlighted item to the item index.
	//- <p>The highlighting is moved and the listbox scrolled as necessary. </p>
	void set_current_item(int index);

	//: Selects item at index if select is true, or unselects it if select is false.
	//- <p>If the listbox is a single-selection listbox and and select is true, set_current_item() is called. 
	//- If the listbox is a single-selection listbox and and select is false, clear_selection()
	//- is called if index is the currently selected item. </p>
	void set_selected(int index, bool select);

	//: Deselects current selected item.
	void clear_selection();

	//: If select is true, all items get selected, else all get unselected.
	//: This works only in Multi selection mode.
	void select_all(bool select = true);

	//: Inverts the selection.
	//: Works only in Multi selection mode.
	void invert_selection();

	//: Sets the listbox to multiselection if enable is true,
	//: single selection otherwise.
	void set_multi_selection(bool enable = true);

	//: Sets the height of each item.
	void set_item_height(int height);

	//: Scrolls the list box so the item at position index in the list is displayed in the top row of the listbox. 
	void set_top_item(int index);

	//: Sorts the items in ascending order, if ascending is true, or descending otherwise. 
	void sort(bool ascending = true);

	//: Deletes all items in the list. 
	void clear();

//! Signals:
public:
	//: This signal is emitted when the user highlights a new current item.
	//- <p>The argument is the index of the new item, which is already current.</p>
	CL_Signal_v1<int> &sig_highlighted();

	//: This signal is emitted when the user double clicks, presses space or return on an item.
	//- <p>The argument is the index of the item.</p>
	CL_Signal_v1<int> &sig_activated();

	//: This signal is emitted when the selection set of a listbox changes.
	CL_Signal_v0 &sig_selection_changed();

	//: This signal is emitted when a new item is added to the listbox.
	CL_Signal_v1<int> &sig_item_added();

	//: This signal is emitted when an item is removed from the listbox.
	CL_Signal_v1<int> &sig_item_removed();
	
	//: This signal is emitted when the listbox is cleared.
	CL_Signal_v0 &sig_clear();

//! Implementation:
private:
	CL_ListBox(const CL_ListBox &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.

	CL_ListBox_Generic *impl;
};

#endif
