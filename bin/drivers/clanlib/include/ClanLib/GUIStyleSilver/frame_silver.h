/*  $Id: frame_silver.h,v 1.7 2004/02/10 07:00:22 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_frame_silver
#define header_frame_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/frame.h"
#include "../GUI/component_style.h"

class CL_Surface;
class CL_StyleManager_Silver;

//: Frame default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_Frame_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_Frame_Silver(
		CL_Frame *frame, 
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_Frame_Silver();

//! Implementation:
private:
	CL_Slot slot_set_options;
	CL_Slot slot_paint;
	CL_Slot slot_resize;

	void on_set_options(const CL_DomElement &options);
	void on_paint();
	void on_resize(int old_width, int old_height);

	CL_Frame *frame;

	enum Mode
	{
		center,
		stretch,
		tile
	} mode;
	
	CL_StyleManager_Silver *style;
	CL_ResourceManager *resources;
	CL_Surface *sur_surface;
};

#endif
