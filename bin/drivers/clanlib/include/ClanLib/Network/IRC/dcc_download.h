/*  $Id: dcc_download.h,v 1.5 2004/01/02 15:42:44 mbn Exp $
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
*/

//! clanNetwork="Internet Relay Chat"
//! header=network.h

#ifndef header_dcc_download
#define header_dcc_download

#if _MSC_VER > 1000
#pragma once
#endif

#include "../../signals.h"
#include <string>

class CL_DCCDownload_Generic;
class CL_OutputSourceProvider;

//: IRC DCC download session object.
//- !group=Network/Internet Relay Chat!
//- !header=network.h!
//- <p>This class connects to an IRC client listening for an incoming DCC
//- connection and then downloads the file offered. Should be used in
//- response to a DCC SEND CTCP command.</p>
class CL_DCCDownload
{
//! Construction:
public:
	//: Constructs a new DCC download session.
	CL_DCCDownload();
	
	CL_DCCDownload(const CL_DCCDownload &copy);

	CL_DCCDownload(
		const std::string &server,
		const std::string &port,
		const std::string &filename,
		int total_size = 0,
		CL_OutputSourceProvider *output = 0,
		bool delete_provider = false);
	
	virtual ~CL_DCCDownload();
	
//! Attributes:
public:
	enum Status
	{
		//: Connecting to DCC server.
		connecting,
		
		//: Currently downloading.
		downloading,
		
		//: Connection was lost to DCC server.
		connection_lost,
		
		//: Download was completed.
		finished
	};

	//: Returns the number of bytes transfered so far.
	int get_bytes_transfered();
	
	//: Returns the total size of file.
	//- <p>If the total size is unknown, it returns 0.</p>
	int get_total_size();
	
	//: Returns the current status of the download.
	Status get_status();

	//: sig_connection_lost(error_message)
	CL_Signal_v1<const std::string &> &sig_connection_lost();

	//: sig_download_complete()
	CL_Signal_v0 &sig_download_complete();

//! Operations:
public:
	//: Copy assignment operator.
	CL_DCCDownload &operator =(const CL_DCCDownload &copy);

	//: Attemp to reconnect and resume download.
	void reconnect();

//! Implementation:
private:
	CL_DCCDownload_Generic *impl;
};

#endif
