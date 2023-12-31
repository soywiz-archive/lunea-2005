/*  $Id: netvariables.h,v 1.4 2004/01/02 15:42:44 mbn Exp $
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

//! clanNetwork="NetObjects"
//! header=network.h

#ifndef header_netvariables
#define header_netvariables

#if _MSC_VER > 1000
#pragma once
#endif

class CL_NetVariables_Generic;
class CL_InputSource;
class CL_OutputSource;

//: Easy serialization of a data structure.
//- !group=Network/NetObjects!
//- !header=network.h!
//- <p>The netvariables class is used to read a set of variables from an object,
//- and write them structured, in network byte order, to an output source.</p>
//-
//- <p>The Netvariables interface can also read the data again, and produce 'diff'
//- packages where it only write variables that have changed since last write.</p>
class CL_NetVariables
{
//! Construction:
public:
	//: Construct a netvariables object.
	CL_NetVariables();

	//: Net Variables Destructor
	virtual ~CL_NetVariables();

//! Attributes:

	//: Returns true if the variables have changed since last save.
	bool is_different();

//! Operations:

	//: Add booleans to the data structure.
	void add_bool(bool *var, int array = 1);

	//: Add integers to the data structure.
	void add_int(int *var, int array = 1);

	//: Add shorts to the data structure.
	void add_short(short *var, int array = 1);

	//: Add floats to the data structure.
	void add_float(float *var, int array = 1);

	//: Add doubles to the data structure.
	void add_double(double *var, int array = 1);

	//: Add structures to the data structure.
	void add_vars(CL_NetVariables *variables, int array = 1);

	//: Write all variables in the data structure to the output source.
	void save_all(class CL_OutputSource *msg);

	//: Read all variables in the data structure from the input source.
	void load_all(class CL_InputSource *msg);

	//: Write all variables that have changed since last save.
	void save_diff(class CL_OutputSource *msg);

	//: Read a diff produced with save_diff from the input source.
	void load_diff(class CL_InputSource *msg);

//! Implementation:
public:
	CL_NetVariables_Generic *impl;
};

#endif
