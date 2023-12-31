/*  $Id: progressbar_silver.h,v 1.5 2004/01/02 15:42:44 mbn Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_progressbar_silver
#define header_progressbar_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/progressbar.h"
#include "../GUI/component_style.h"

class CL_StyleManager_Silver;
class CL_ResourceManager;

//: ProgressBar default style.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_ProgressBar_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_ProgressBar_Silver(
		CL_ProgressBar *progressbar,
		CL_StyleManager_Silver *style);
	
	//: Destructor
	virtual ~CL_ProgressBar_Silver() {};

//! Implementation:
private:
	void on_paint();

	CL_Slot slot_paint;

	CL_StyleManager_Silver *style;
	CL_ProgressBar *progressbar;
};

#endif

