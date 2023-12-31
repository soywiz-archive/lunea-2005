/*  $Id: command_line.h,v 1.6 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_core_system_command_line
#define header_core_system_command_line

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include <vector>

class CL_CommandLine_Generic;

//: Helper class to parse command line arguments
//- !group=Core/System!
//- !header=core.h!
//- <p>The CL_CommandLine class helps to parse command line arguments, namely
//- the argc/argv pair that you get from main(). CL_CommandLine mimics
//- getopt_long() behaviour as closely as possible, while providing a
//- cleaner interface and a few additional features, like automatic
//- generation of '--help' output. CL_CommandLine can parse long arguments
//- in the following styles:</p>
//-
//- <p>program --file FILENAME<br>
//- program --file=FILENAME</p>
//-
//- <p>Short arguments are handled like this:</p>
//-
//- <p>program -f FILENAME</p>
//-
//- <p>Concatenating short arguments is also supported, so that:</p>
//- 
//- <p>program -f -a -b FILENAME</p>
//-
//- <p>is equivalent to:</p>
//-
//- <p>program -fab FILENAME</p>
//-
//- <p>Non-option arguments (aka rest arguments) are supported as well:</p>
//-
//- <p>program SOMEFILE SOMEOTHERFILE ...</p>
//- 
//- <p>To avoid ambiguity when a filename starts with '-' CL_CommandLine stops
//- parsing arguments after the first encounter of a '--', so in</p>
//-
//- <p>program -f -b -- -f -b</p>
//-
//- <p>In the above example the first '-f -b' options are treated as
//- normal while the ones after the '--' are treated as rest arguments
//- (aka filenames in most programs).</p>
class CL_CommandLine
{
//! Construction:
public:
	CL_CommandLine();

	~CL_CommandLine();

//! Attributes:
public:
	enum
	{
		REST_ARG  = -2
	};

	//: Return the key of the current option
	int get_key();

	//: Return the argument to the current option
	std::string get_argument();

//! Operations:
public:
	//: Change the indention used for the help message, default is 18
	void set_help_indent(int i);

	//: Add a usage line to the help output, usage is for example
	//: "[OPTIONS]... FILE", the program name will get appended
	//: automatically
	void add_usage(const std::string& usage);

	//: Adds extra documentation to the help output, should only be
	//: used at the beginning or at the end, to
	void add_doc(const std::string& doc);
	
	//: Starts a new group of options, the grouptopic gets printed
	//: above the group of options in the print_help() output
	void add_group(const std::string& grouptopic);
  
	//: Adds a option to the parser
	//param key: a letter for a short-option or a numeric value
	//param key: larger than 255 that identifies the option
	//param long_option: the long name of this option or "" if non
	//param long_option: should be used for this option
	//param argument: the type of the argument that this option
	//param argument: requires (i.e. FILE, SIZE, WIDTH, etc.) or "" if no argument is
	//param argument: required
	//param help: the help string for this option
	//param visible: true if the option should be listed in the help
	//param visible: output, false will not list it in the help output which might
	//param visible: be usefull for cheat-options or backward-compability options
	//param visible: than would only clutter the help output
	void add_option(
		int key,
		const std::string& long_option, 
		const std::string& argument,
		const std::string& help,
		bool visible = true);
	
	//: Parse the options arcording to the options added with
	//: add_option(), result of the parsing is accessible via
	//: next() and get_key()/get_argument()
	void parse_args(int argc, char** argv);

	//: Print the help output, normaly done via a --help option
	void print_help();

	//: Goto the next option
	bool next();

//! Implementation:
private:
	CL_CommandLine_Generic* impl;
};

#endif
