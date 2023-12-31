/*  $Id: checkbox_silver.h,v 1.8 2004/01/03 23:03:22 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_checkbox_silver
#define header_checkbox_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/checkbox.h"
#include "../GUI/component_style.h"
#include "checkbox_silver.h"

class CL_Font;
class CL_Surface;
class CL_StyleManager_Silver;

//: CheckBox default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
//- <p>Script attributes:</p>
//- <ul>
//- <li>surface_checked: The surface used when button is checked. [String]</li>
//- <li>surface_unchecked: The surface used when button is unchecked. [String]</li>
//- <li>surface_checked_disabled: The surface used when button is checked, but disabled. [String]</li>
//- <li>surface_unchecked_disabled: The surface used when button is unchecked and disabled. [String]</li>
//- <li>font: The font used to draw the label. [String]</li>
//- </ul>
//- <p>Note that it inherits the attributes of CL_CheckBox, CL_Button and CL_Component as well.</p>
class CL_CheckBox_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_CheckBox_Silver(
		CL_CheckBox *checkbox,
		CL_StyleManager_Silver *style);
		
	//: Destructor
	virtual ~CL_CheckBox_Silver();

//! Attributes:
public:

//! Operations:
public:
	//: Sets the font used to draw the label.
	//- <p>If 'delete_font' is true, the font will be deleted when the component is deleted.</p>
	void set_font(CL_Font *font, bool delete_font = false);

	//: Sets the font used to draw the label in disabled mode.
	//- <p>If 'delete_font' is true, the font will be deleted when the component is deleted.</p>
	void set_font_disabled(CL_Font *font, bool delete_font = false);

	//: Sets the surface used when button is in the up-state.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_checked(CL_Surface *surface, bool delete_surface = false);

	//: Set the surface used when button is in the down-state.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_unchecked(CL_Surface *surface, bool delete_surface = false);

	//: Sets the surface used when button is highlighted.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_checked_disabled(CL_Surface *surface, bool delete_surface = false);

	//: Sets the surface used when button is disabled.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_unchecked_disabled(CL_Surface *surface, bool delete_surface = false);

//! Implementation:
private:
	void on_set_options(const CL_DomElement &options);
	CL_Slot slot_set_options;

	void on_get_preferred_size(CL_Size &size);
	CL_Slot slot_get_preferred_size;

	void on_paint(CL_SlotParent_v0 &super);
	CL_Slot slot_paint;

	CL_CheckBox *checkbox;

	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	
	CL_Font *font;
	CL_Font *font_disabled;
	bool delete_font;
	bool delete_font_disabled;

	CL_Surface *sur_checked;
	CL_Surface *sur_unchecked;
	CL_Surface *sur_checked_disabled;
	CL_Surface *sur_unchecked_disabled;

	bool delete_sur_checked;
	bool delete_sur_unchecked;
	bool delete_sur_checked_disabled;
	bool delete_sur_unchecked_disabled;
};

#endif

