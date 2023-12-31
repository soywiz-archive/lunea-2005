/*  $Id: cd_drive.h,v 1.5 2004/02/01 20:28:56 mbn Exp $
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

//! clanSound="CD Audio"
//! header=sound.h

#ifndef header_cd_drive
#define header_cd_drive

#if _MSC_VER > 1000
#pragma once
#endif

#include "../Core/System/sharedptr.h"
#include <string>
#include <vector>

class CL_CDDrive_Generic;

//: CD drive audio interface.
//- !group=Sound/CD Audio!
//- !header=sound.h!
//- <p>Use this class to control the CDROM drive in your computer.</p>
class CL_CDDrive
{
//! Construction:
public:
	//: Constructs a CD drive object.
	CL_CDDrive();

	CL_CDDrive(const CL_CDDrive &copy);

	virtual ~CL_CDDrive();

//! Attributes:
public:
	//: Returns the amount of CD drives available on the system.
	static std::vector<CL_CDDrive> &get_drives();

	//: Get the path of the CD drive.
	std::string get_drive_path();

	//: Get the name of the CD.
	std::string get_cd_name();

	//: Get the number of tracks available on the cd.
	int get_num_tracks();

	//: Returns true if the CD drive is playing.
	bool is_playing();
	
	//: Returns the current track.
	int get_cur_track();

	//: Returns the current frame on the track.
	int get_cur_frame();

//! Operations:
public:
	//: Play from track 'track' til track 'end_track'.
	//param track: Begin track.
	//param end_track: End track.
	bool play_tracks(int track, int end_track=0);

	//: Play from frame 'frame' to 'end_frame'.
	//param frame: Begin frame.
	//param end_frame: End frame.
	bool play_frames(int frame, int end_frame=0);

	//: Play track 'track'. Returns true if successful.
	bool play_track(int track);

	//: Stop playing.
	void stop();

	//: Pause the playback.
	void pause();

	//: Resume the playback.
	void resume();

//! Implementation:
private:
	CL_SharedPtr<CL_CDDrive_Generic> impl;
};

#endif
