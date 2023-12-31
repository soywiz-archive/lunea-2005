/*  $Id: radiobutton_silver.h,v 1.6 2004/01/03 23:03:22 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_radiobutton_silver
#define header_radiobutton_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/radiobutton.h"
#include "../GUI/component_style.h"

class CL_Font;
class CL_Surface;
class CL_StyleManager_Silver;

//: RadioButton default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_RadioButton_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_RadioButton_Silver(
		CL_RadioButton *radiobutton,
		CL_StyleManager_Silver *style);
		
	//: Desstructor
	virtual ~CL_RadioButton_Silver();

//! Implementation:
private:
	void on_get_preferred_size(CL_Size &size);
	CL_Slot slot_get_preferred_size;

	void on_paint(CL_SlotParent_v0 &super);
	CL_Slot slot_paint;

	CL_RadioButton *radiobutton;

	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	
	CL_Font *font;
	CL_Surface *sur_checked;
	CL_Surface *sur_unchecked;
	CL_Surface *sur_checked_disabled;
	CL_Surface *sur_unchecked_disabled;
};

#endif

