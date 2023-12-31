/*  $Id: ip_address.h,v 1.13 2004/01/02 15:42:44 mbn Exp $
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

//! clanNetwork="Sockets"
//! header=network.h

#ifndef header_ip_address
#define header_ip_address

#if _MSC_VER > 1000
#pragma once
#endif

#include <string>

class CL_IPAddress_Generic;

//: Socket name; container class for an IP address and port.
//- !group=Network/Sockets!
//- !header=network.h!
class CL_IPAddress
{
//! Construction:
public:
	//: Constructs an IP address using INADDR_ANY and port 0.
	CL_IPAddress();

	//: Constructs an IP address using INADDR_ANY and the specified port.
	CL_IPAddress(const std::string &port);

	//: Construct an IP address using the hostname and the port.
	CL_IPAddress(const std::string &hostname, const std::string &port);

	//: Copy constructor.
	CL_IPAddress(const CL_IPAddress &copy);

//! Attributes:
public:
	//: Returns the internal addrinfo struct
	void get_addrinfo(int type, struct sockaddr &addr, int &len, int domain) const;

	//: Returns the IP address as a string.
	std::string get_address() const;

	//: Returns the IP port as a string.
	std::string get_port() const;

	//: Returns true if objects are the same.
	bool operator == (const CL_IPAddress &other_instance) const;

	//: Returns true if the other address is less.
	//- <p>This is used for sorting
	//- purposes (eg. if you use a std::map<CL_IPAddress, CL_Socket>), and sorts
	//- the address based on lowest IP number address.</p>
	bool operator < (const CL_IPAddress &other_instance) const;

	//: Returns true if the other address is greater.
	//- <p>This is used for sorting
	//- purposes (eg. if you use a std::map<CL_IPAddress, CL_Socket>), and sorts
	//- the address based on lowest IP number address.</p>
	bool operator > (const CL_IPAddress &other_instance) const;

//! Operations:
public:

	//: Set the IP address using a hostname and port.
	//param hostname: Can be an IPv4 dotted-quad, hostname or a valid IPv6 address.
	//param port: Port number.
	void set_address(const std::string &hostname, const std::string &port);

	//: Set the IP port.  Note, this will reset the hostname to the default value of any host.
	void set_port(const std::string &port);

	//: Do a DNS lookup on the IP address.
	std::string dns_lookup() const;
	
	//: Check to see if the address has an IPv4 mapping
	//: is_ipv4() and is_ipv6() are not mutally exclusive
	//: An address can have both IPv4 and IPv6 mappings
	bool is_ipv4() const;
	
	//: Check to see if the address has an IPv6 mapping
	//: is_ipv4() and is_ipv6() are not mutally exclusive
	//: An address can have both IPv4 and IPv6 mappings
	bool is_ipv6() const;

//! Implementation:
private:
	CL_IPAddress_Generic *impl;
};

#endif
