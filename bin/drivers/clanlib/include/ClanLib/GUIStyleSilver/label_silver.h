/*  $Id: label_silver.h,v 1.6 2004/01/03 23:03:22 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_label_silver
#define header_label_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/label.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_Font;

//: Label default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_Label_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_Label_Silver(
		CL_Label *label,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_Label_Silver();

//! Implementation:
private:
	CL_Slot slot_paint;
	CL_Slot slot_get_preferred_size;

	void on_paint();
	void on_get_preferred_size(CL_Size &size);

	CL_Label *label;
	
	CL_ResourceManager *resources;
	CL_Font *font;
};

#endif
