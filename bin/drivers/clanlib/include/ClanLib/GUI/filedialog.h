/*  $Id: filedialog.h,v 1.23 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_file_dialog
#define header_file_dialog

#if _MSC_VER > 1000
#pragma once
#endif

#include "window.h"

class CL_FileDialog_Generic;

//: File dialog component
//- !group=GUI/Controls!
//- !header=gui.h!
class CL_FileDialog : public CL_Window
{
//! Construction:
public:
	//: File dialog constructor
	CL_FileDialog(
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: File dialog constructor
	CL_FileDialog(
		const std::string &title,
		const std::string &file,
		const std::string &filter,
		CL_Component *parent,
		CL_StyleManager *style = NULL);

	//: File dialog destructor
	virtual ~CL_FileDialog();

	//: Open
	static const std::string open(
		CL_Component *parent);

	//: Open
	static const std::string open(
		const std::string &file,
		const std::string &filter,
		CL_Component *parent);

	//: Save
	static const std::string save(
		CL_Component *parent);

	//: Save
	static const std::string save(
		const std::string &file,
		const std::string &filter,
		CL_Component *parent);

//! Attributes:
public:
	//: Returns the selected file name. 
	const std::string &get_file() const;

	//: Returns the filter which the user has chosen in the file dialog.
	const std::string &get_filter() const;

	//: Returns the active directory in the file dialog.
	const std::string &get_dir() const;

	//: Returns the active directory path in the file dialog. 
	const std::string &get_path() const;

	//: Returns true if hidden files are shown in the filedialog, else false.
	bool is_hidden_files_visible() const;

//! Operations:
public:
	//: Sets the default selection to filename.
	//- <p>If filename is absolute, set_dir() is also called.</p>
	void set_file(const std::string &filename);

	//: Sets a directory path for the file dialog. 
	void set_dir(const std::string &dir);

	//: Sets the filter to filter.
	void set_filter(const std::string &filter);

	//: If enable is true, hidden files are shown in the filedialog, else no hidden files are shown. 
	void show_hidden_files(bool enable = true);

	//: Re-reads the active directory in the file dialog. 
	//- <p>It is seldom necessary to call this function.
	//- It is provided in case the directory contents change and you want to refresh the directory listbox.</p>
	void refresh();

//! Signals:
public:
	//: This signal is emitted when the user highlights a file. 
	CL_Signal_v1<const std::string &> &sig_file_highlighted();

	//: This signal is emitted when the user selects a file. 
	CL_Signal_v1<const std::string &> &sig_file_selected();

	//: This signal is emitted when the user has selected a new directory. 
	CL_Signal_v1<const std::string &> &sig_dir_entered();

//! Implementation:
private:
// TODO: Fix this copy constructor
//	CL_FileDialog(const CL_FileDialog &copy) : CL_Component(NULL, NULL) { return; } // disallow copy construction.
	CL_FileDialog_Generic *impl;
};

#endif
