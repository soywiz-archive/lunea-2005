/*  $Id: clanstring.h,v 1.63 2004/02/18 14:32:15 sphair Exp $
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

#ifndef header_clanstring
#define header_clanstring

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include <vector>

class CL_ResourceManager;

class CL_String
//: ClanLib string class.
//- !group=Core/System!
//- !header=core.h!
//- <p>This is a general purpose string class with formatting capabilities.</p>
//- <p>Example: str::string s = CL_String::format("You rock my %1, %2 (%3)", "world", name, 47);</p>
{
//! Operations:
public:
	//: Loads a string from a resource.
	//param res_id: Resource to load string from.
	//param resources: Resource manager used to load string.
	//param def_value: Default value if resource is not found.
	static std::string load(const std::string &res_id, CL_ResourceManager *resources);

	static std::string load(const std::string &res_id, CL_ResourceManager *resources, const std::string &def_value);
	
	//: Returns the first n characters of the string
	static std::string left(std::string string, int n);
	
	//: Returns the last n characters in the string
	static std::string right(std::string string, int n);

	//: String formatting.
	//- <p>The format specified is of the form "Some text %1, some more text %2".
	//- The %n markers can then be search/replaced using the arg() functions.</p>
	//- <pre>
	//- Example 1:
	//-   CL_String str;
	//-   str.format("%1 world! Meaning of life is: %2");
	//-   str.arg("Hello");
	//-   str.arg(42);
	//- Example 2:
	//-   CL_String str;
	//-   str.format("%1 is better than %2", "ClanLib 0.7", "ClanLib 0.6");
	//- </pre>
	//static std::string format(const std::string &format);

	template<class Param1>
	static std::string format(const std::string &str_format, const Param1 &p1)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		
		return ret;
	}

	template<class Param1, class Param2>
	static std::string format(const std::string &str_format, const Param1 &p1, const Param2 &p2)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		arg(ret, p2, 2);

		return ret;
	}

	template<class Param1, class Param2, class Param3>
	static std::string format(const std::string &str_format, const Param1 &p1, const Param2 &p2, const Param3 &p3)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		arg(ret, p2, 2);
		arg(ret, p3, 3);
		return ret;
	}

	template<class Param1, class Param2, class Param3, class Param4>
	static std::string format(const std::string &str_format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		arg(ret, p2, 2);
		arg(ret, p3, 3);
		arg(ret, p4, 4);
		return ret;
	}
	
	template<class Param1, class Param2, class Param3, class Param4, class Param5>
	static std::string format(const std::string &str_format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		arg(ret, p2, 2);
		arg(ret, p3, 3);
		arg(ret, p4, 4);
		arg(ret, p5, 5);
		return ret;
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5, class Param6>
	static std::string format(const std::string &str_format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5, const Param6 &p6)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		arg(ret, p2, 2);
		arg(ret, p3, 3);
		arg(ret, p4, 4);
		arg(ret, p5, 5);
		arg(ret, p6, 6);
		return ret;
	}

	template<class Param1, class Param2, class Param3, class Param4, class Param5, class Param6, class Param7>
	static std::string format(const std::string &str_format, const Param1 &p1, const Param2 &p2, const Param3 &p3, const Param4 &p4, const Param5 &p5, const Param6 &p6, const Param7 &p7)
	{
		std::string ret = str_format;
		arg(ret, p1, 1);
		arg(ret, p2, 2);
		arg(ret, p3, 3);
		arg(ret, p4, 4);
		arg(ret, p5, 5);
		arg(ret, p6, 6);
		arg(ret, p7, 7);
		return ret;
	}

	//: Converts from an integer to string.
	static std::string from_int(int value);

	//: Converts from an float to string.
	static std::string from_float(float value);

	//: Converts from an double to string.
	static std::string from_double(double value);

	//: Returns "true" or "false" based on a boolean.
	static std::string from_bool(bool value);

	//: Converts a string to a boolean.
	//- <p>Accepted values: "1", "0", "yes", "no", "true", "false". All other values return false.
	//- The function is not case sensitive.</p>
	static bool to_bool(const std::string &value);

	//: Converts string to an integer.
	static int to_int(const std::string&);

	//: Converts string to a floating point number.
	static float to_float(const std::string&);
	
	//: Converts string to a double precision floating point number.
	static double to_double(const std::string&);

	//: Returns the string with all characters converted to lowercase.
	static std::string to_lower(const std::string&);
	
	//: Returns the string with all characters converted to uppercase.
	static std::string to_upper(const std::string&);

	//: Breaks up the string into tokens.
	static std::vector<std::string> tokenize(const std::string &str, const std::string &delimiter, bool skip_empty = true);

	//: Does a case insensitive compare of string to other string.
	static bool compare_nocase(const std::string&, const std::string&);

	//: Returns the path part of a pathname (path+filename). If no path part is found, "." is returned.
	static std::string get_path(const std::string &pathname);

	//: Returns the filename part of a pathname (path+filename). If no path part is found, the entire string is returned.
	static std::string get_filename(const std::string &pathname);

	//: Returns the extension path of a filename (text after the last dot). If no extension part is found, an empty string is returned.
	static std::string get_extension(const std::string &filename);

	//: Returns a string trimmed for space characters in both ends of string.
	static std::string trim_spaces(const std::string &str);

	//: Returns a string trimmed for whitespace characters in both ends of string.
	//- <p>Whitespace are space, tabs, newlines and carrage return characters.</p>
	static std::string trim_whitespace(const std::string &str);

//! Implementation:
private:
	// Private Constructor to prevent people from creating instances of CL_String
	CL_String() {;}

	// Replaces argument %(num) in format with arg
	static void arg(std::string &format, const std::string &arg, int num);

	static void arg(std::string &format, const char *arg, int num);

	static void arg(std::string &format, int number, int num);

	static void arg(std::string &format, float number, int num);

	static void arg(std::string &format, double number, int num);
};

#endif
