/*  $Id: console_window.h,v 1.16 2004/01/02 15:42:43 mbn Exp $
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

//! clanCore="System"
//! header=core.h

#ifndef header_console_window
#define header_console_window

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_ConsoleWindow_Generic;

//: Text console window.
//- !group=Core/System!
//- !header=core.h!
//- <p>Note: This class has no effect under Linux.</p>
class CL_ConsoleWindow
{
//! Construction:
public:
	//: Console Window constructor.
	//param title: Window title of console window.
	//param width: Columns in console window.
	//param height: Rows in console window.
	CL_ConsoleWindow(
		const std::string &title,
		int width = 80,
		int height = 25);

	//: Console Window destructor.
	~CL_ConsoleWindow();

//! Operations:
public:
	//: Redirects stdout, stdin and stderr to the console window.
	void redirect_stdio();

	//: Redirects stdout and stderr to filename.
	void redirect_stdio(const std::string &filename);

	//: Waits until user hits a key.
	void wait_for_key();

	//: Displays 'press any key to close this console window',
	//: and waits until user hits a key.
	void display_close_message();

//! Implementation:
private:
	CL_ConsoleWindow_Generic *impl;
};

#endif
