/*  $Id: clanapp.h,v 1.17 2004/01/02 15:42:43 mbn Exp $
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

//! clanApp="System"

#ifndef header_clanapp
#define header_clanapp

#if _MSC_VER > 1000
#pragma once
#endif

//: The starting place for all applications.
//- !group=App/System!
//- !header=app.h!
//- <p> The application class must be inherited by all ClanLib applications.
//- In your application create a class inheriting CL_ClanApplication, 
//- make a global instance of it, and fill in the main() function. </p>
class CL_ClanApplication
{
public:
	//: Clan Application constructor
	CL_ClanApplication();

	//: Clan Application destructor
	virtual ~CL_ClanApplication();

	//: Main application function
	//- <p> Every program made using ClanLib must implement this function. 
	//- This is the main application function, which will be called 
	//- <i>once</i> following system initialization. </p>
	//param argc: The number of arguments to the program (c-style)
	//param argv: A pointer to strings, containing the program arguments. The name of the program executable is always passed as first argument.
	//return: Program return value
	virtual int main(int argc, char** argv)=0;

	//: Static pointer to an initialized instance of this class.
	//: This is set by the constructor.
	static CL_ClanApplication *app;
};

#endif
