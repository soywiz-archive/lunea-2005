/*  $Id: treeitem_silver.h,v 1.10 2004/01/08 18:50:48 sphair Exp $
	
	ClanGUI, copyrights by various people. Have a look in the CREDITS file.
	
	This sourcecode is distributed using the Library GNU Public Licence,
	version 2 or (at your option) any later version. Please read LICENSE
	for details.
*/

//! clanGUI="Style: Silver"
//! header=guistylesilver.h

#ifndef header_treeitem_silver
#define header_treeitem_silver

#if _MSC_VER > 1000
#pragma once
#endif

#include "../GUI/treeitem.h"
#include "../GUI/component_style.h"

class CL_Font;
class CL_Surface;
class CL_StyleManager_Silver;

//: Theme class for CL_TreeItem for Silver theme.
//- !group=GUI/Style: Silver!
//- !header=guistylesilver.h!
class CL_TreeItem_Silver : public CL_ComponentStyle
{
//! Construction:
public:
	//: Constructor
	CL_TreeItem_Silver(
		CL_TreeItem *item,
		CL_StyleManager_Silver *style);

	//: Destructor
	virtual ~CL_TreeItem_Silver();

//! Implementation:
private:
	void on_paint();
	void on_get_preferred_size(CL_Size &size);

	CL_Slot slot_paint;
	CL_Slot slot_get_preferred_size;

	CL_TreeItem *item;

	CL_Font *font;

	CL_StyleManager_Silver *style;
};

#endif
