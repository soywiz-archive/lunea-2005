/*
         $Id: 

      ------------------------------------------------------------------------
        ClanLib Game SDK

        This library is distributed under the GNU LIBRARY GENERAL PUBLIC LICENSE
        version 2. See COPYING for details.

        For a total list of contributers see CREDITS.

        See http://www.clanlib.org
      ------------------------------------------------------------------------
*/

//! clanVorbis="System"
//! header=vorbis.h

#ifndef header_setupvorbis
#define header_setupvorbis

#if _MSC_VER > 1000
#pragma once
#endif

//: ClanVorbis initialization functions
//- !group=Vorbis/System!
//- !header=vorbis.h!
class CL_SetupVorbis
{
//! Construction:
public:
	//: Initializes clanVorbis.
	//- <p>Constructing a CL_SetupVorbis object is equalent to calling CL_SetupVorbis::init().</p>
	//- <p>When the CL_SetupVorbis instance is destroyed, CL_SetupVorbis::deinit() is called.</p>
	CL_SetupVorbis(bool register_resources_only = false);

	~CL_SetupVorbis();

//! Operations:
public:
	//: Initialize the Vorbis library
	static void init(bool register_resources_only = false);

	//: Deinitialize the Vorbis library
	static void deinit();
};

#endif
