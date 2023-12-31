/*  $Id: stylemanager_silver.h,v 1.9 2004/05/06 21:20:47 grumbel Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_stylemanager_silver
#define header_stylemanager_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/stylemanager.h"

class CL_ResourceManager;
class CL_Component;
class CL_Rect;
class CL_Color;

//: Style manager that uses the default clanlib gui style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_StyleManager_Silver : public CL_StyleManager
{
//! Construction:
public:
	//: Construct a default style manager using the specified resources.
	CL_StyleManager_Silver(CL_ResourceManager *resources);

	//: Destructor.
	virtual ~CL_StyleManager_Silver();

//! Attributes:
public:
	
//! Operations:
public:

//! Overrideables:
public:
	//: Connect component styles to component.
	//: The 'type' parameter indicates what type the component is.
	virtual void connect_styles(
		const std::string &type,
		CL_Component *component);

//! Implementation:
private:
	// Disallow copy contruction of style managers.
	CL_StyleManager_Silver(const CL_StyleManager_Silver &copy) : CL_StyleManager(0) { return; }
};

#endif
