/*  $Id: button_silver.h,v 1.8 2004/02/18 14:47:54 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_button_silver
#define header_button_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/button.h"
#include "../GUI/component_style.h"

class CL_Font;
class CL_Surface;
class CL_StyleManager_Silver;

//: Button default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
//- <p>Script attributes:</p>
//- <ul>
//- <li>surface_up: The surface used when button is in the up-state. [String]</li>
//- <li>surface_down: The surface used when button is in the down-state. [String]</li>
//- <li>surface_disabled: The surface used when button is disabled. [String]</li>
//- <li>surface_highlighted: The surface used when button is highlighted. [String]</li>
//- <li>font: The font used to draw the label. [String]</li>
//- <li>font_disabled: The font used to draw the label in disabled mode. [String]</li>
//- </ul>
//- <p>Note that it inherits the attributes of CL_Button and CL_Component as well.</p>
class CL_Button_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_Button_Silver(
		CL_Button *button,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_Button_Silver();

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
	void set_surface_up(CL_Surface *surface, bool delete_surface = false);

	//: Set the surface used when button is in the down-state.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_down(CL_Surface *surface, bool delete_surface = false);

	//: Sets the surface used when button is highlighted.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_highlighted(CL_Surface *surface, bool delete_surface = false);

	//: Sets the surface used when button is disabled.
	//- <p>If 'delete_surface' is true, the surface will be deleted when the component is deleted.</p>
	void set_surface_disabled(CL_Surface *surface, bool delete_surface = false);

	//: Draws the button as a scrollbar increase button.
	void set_scrollbar_increase_mode();

	//: Draws the button as a scrollbar decrease button.
	void set_scrollbar_decrease_mode();

//! Implementation:
private:
	void on_set_options(const CL_DomElement &options);
	CL_Slot slot_set_options;

	void on_paint();
	CL_Slot slot_paint;

	void on_get_preferred_size(CL_Size &size);
	CL_Slot slot_get_preferred_size;

	CL_Button *button;
	
	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;

	CL_Font *font;
	CL_Font *font_disabled;

	bool delete_font;
	bool delete_font_disabled;
	
	CL_Surface *sur_up;
	CL_Surface *sur_down;
	CL_Surface *sur_highlighted;
	CL_Surface *sur_disabled;

	bool delete_sur_up;
	bool delete_sur_down;
	bool delete_sur_highlighted;
	bool delete_sur_disabled;
};

#endif
