/*  $Id: xml_token_string.h,v 1.6 2004/01/09 22:19:14 grumbel Exp $
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

//! clanCore="XML"
//! header=core.h

#ifndef header_xml_writer_generic
#define header_xml_writer_generic

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>
#include <algorithm>

//: String class for XML Tokens.
//- !group=Core/XML!
//- !header=core.h!
class CL_XMLTokenString
{
public:
	CL_XMLTokenString();
	CL_XMLTokenString(char const * pointer, int len, bool is_need_escape);
	CL_XMLTokenString(char * pointer, int len, bool is_need_escape);
	CL_XMLTokenString(const CL_XMLTokenString & copy);
	
	CL_XMLTokenString & operator=(const CL_XMLTokenString & copy);

public:
	char * ptr();
	char const * ptr() const;
    int length() const;

	char operator[](int i) const;
	char & operator[](int i);

	std::string to_string() const;
	bool empty() const;
	bool need_escape() const;

	char * begin();
	char * end();
	char * begin() const;
	char * end() const;

private:
	char * pointer;
	int len;
	bool is_need_escape;
};


inline CL_XMLTokenString::CL_XMLTokenString()
	: pointer(0)
	, len(0)
	, is_need_escape(false)
{
}

inline CL_XMLTokenString::CL_XMLTokenString(char * pointer, int len, bool is_need_escape)
	: pointer(pointer)
	, len(len)
	, is_need_escape(is_need_escape)
{
}

// unsafe ctor
inline CL_XMLTokenString::CL_XMLTokenString(char const * pointer, int len, bool is_need_escape)
	: pointer(const_cast<char*>(pointer))
	, len(len)
	, is_need_escape(is_need_escape)
{
}

inline CL_XMLTokenString::CL_XMLTokenString(const CL_XMLTokenString & copy)
	: pointer(copy.pointer)
	, len(copy.len)
	, is_need_escape(copy.is_need_escape)
{
}

inline CL_XMLTokenString & CL_XMLTokenString::operator=(const CL_XMLTokenString & copy)
{
	if (this == &copy)
		return *this;

	pointer = copy.pointer;
	len = copy.len;
	is_need_escape = copy.is_need_escape;

	return *this;
}

inline char * CL_XMLTokenString::ptr()
{
	return pointer;
}

inline char const * CL_XMLTokenString::ptr() const
{
	return pointer;
}
   
inline int CL_XMLTokenString::length() const
{
	return len;
}

inline bool CL_XMLTokenString::empty() const
{
	return len == 0;
}

inline char * CL_XMLTokenString::begin()
{
	return pointer;
}

inline char * CL_XMLTokenString::end()
{
	return pointer + len;
}

inline char * CL_XMLTokenString::begin() const
{
	return pointer;
}

inline char * CL_XMLTokenString::end() const
{
	return pointer + len;
}

inline bool CL_XMLTokenString::need_escape() const
{
	return is_need_escape;
}

inline bool operator==(CL_XMLTokenString const & lhs, CL_XMLTokenString const & rhs)
{
	return lhs.length() == rhs.length() && !memcmp(lhs.ptr(), rhs.ptr(), lhs.length());
}

inline char CL_XMLTokenString::operator[](int i) const
{
	return pointer[i];
}

inline char & CL_XMLTokenString::operator[](int i)
{
	return pointer[i];
}

template <typename Container, typename Iter>
inline bool append_escape(Container & buff, size_t & buff_size, Iter & begin, Iter end, std::string const & escape, char escape_char)
{
	if ((int)escape.size() <= (end - begin))
		if (std::equal(escape.begin(), escape.end(), begin))
		{
			buff[buff_size] = escape_char;
			buff_size += 1;
			begin += escape.size();
			return true;
		}
	return false;
}

inline std::string replace_escapes_fast(CL_XMLTokenString const & token_string)
{
	static std::string const amp("&amp;");
	static std::string const quot("&quot;");
	static std::string const apos("&apos;");
	static std::string const lt("&lt;");
	static std::string const gt("&gt;");

	char const * begin = token_string.begin();
	char const * end = token_string.end();

	std::string::size_type size = token_string.length();

	static std::vector<char> buff;
	if (buff.size() < size)
		buff.resize(size);

	size_t buff_size = 0;

	while(begin != end)
	{
		char const * pos = std::find(begin, end, '&');
		std::copy(begin, pos, buff.begin() + buff_size);
		buff_size += std::distance(begin, pos);

		if (pos == end)
			break;

		begin = pos;
		if (	append_escape(buff, buff_size, begin, end, amp, '&')
			||	append_escape(buff, buff_size, begin, end, quot, '\"')
			||	append_escape(buff, buff_size, begin, end, apos, '\'')
			||	append_escape(buff, buff_size, begin, end, gt, '>')
			||	append_escape(buff, buff_size, begin, end, lt, '<'))
		{
		}
		else
		{
			buff[buff_size] = '&';
			buff_size += 1;
			++begin;
		}
	}
	return std::string(&buff[0], buff_size);
}

inline std::string CL_XMLTokenString::to_string() const
{
	if (!is_need_escape)
		return std::string(pointer, len);

	return replace_escapes_fast(*this);
}

inline CL_XMLTokenString trim_whitespace(CL_XMLTokenString const & str)
{
	if (str.empty())
		return str;

	char const * begin = str.begin();
	char const * end = str.end();

	while(begin != end)
	{
		char ch = *begin;
		if (	ch != ' '
			&&	ch != '\t'
			&&	ch != '\r'
			&&	ch != '\n')
		{
			break;
		}
		++begin;
	}

	while(end != begin)
	{
		char const * old_end = end--;
		
		char ch = *end;
		if (	ch != ' '
			&&	ch != '\t'
			&&	ch != '\r'
			&&	ch != '\n')
		{
			end = old_end;
			break;
		}
		--end;
	}

	return CL_XMLTokenString(begin, std::distance(begin, end), str.need_escape());
}

#endif
