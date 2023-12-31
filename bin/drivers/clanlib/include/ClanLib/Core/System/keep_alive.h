/*  $Id: keep_alive.h,v 1.13 2004/01/02 15:42:43 mbn Exp $
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

#ifndef header_keepalive
#define header_keepalive

#if _MSC_VER > 1000
#pragma once
#endif

//: Keep alive callback interface.
//- !group=Core/System!
//- !header=core.h!
//- <p>If you want to add something that gets called in a
//- CL_System::keep_alive() call, inherit this class and create an instance
//- of it.</p>
class CL_KeepAlive
{
//! Construction:
public:
	//: Constructs and registers the object as a keep_alive listener.
	CL_KeepAlive();
	
	//: Unregisters the object as a keep_alive listener.
	virtual ~CL_KeepAlive();

//! Operations:
public:
	//: Called when CL_System::keep_alive() is called.
	virtual void keep_alive()=0;

//! Implementation:
private:
	//: Thread ID of thread this keep alive object was created in.
	int create_thread_id;
};

#endif
