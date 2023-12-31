/*  $Id: image_silver.h,v 1.6 2004/03/28 00:13:14 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_image_silver
#define header_image_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/image.h"
#include "../GUI/component_style.h"

class CL_Surface;
class CL_StyleManager_Silver;

//: Image default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_Image_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_Image_Silver(
		CL_Image *image, 
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_Image_Silver() {}

//! Implementation:
private:
	CL_Slot slot_paint;
	CL_Slot slot_get_preferred_size;

	void on_paint();
	void on_get_preferred_size(CL_Size &size);

	CL_Image *image;

	CL_ResourceManager *resources;
};

#endif
