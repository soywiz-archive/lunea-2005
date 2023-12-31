/*  $Id: display.h,v 1.35 2004/04/04 14:37:12 harry Exp $
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

//: <p>ClanLib display and input library. This provide you with 2D display
//: support, and the input devices attached to that display.</p>
//! Global=Display

#ifndef header_display_include
#define header_display_include

#if _MSC_VER > 1000
#pragma once
#endif

#include "Display/blend_func.h"
#include "Display/color.h"
#include "Display/display.h"
#include "Display/display_iostream.h"
#include "Display/display_mode.h"
#include "Display/display_window.h"
#include "Display/display_window_description.h"
#include "Display/font.h"
#include "Display/frameratecounter.h"
#include "Display/glyph_buffer.h"
#include "Display/gradient.h"
#include "Display/graphic_context.h"
#include "Display/input_buffer.h"
#include "Display/input_button.h"
#include "Display/input_context.h"
#include "Display/input_device.h"
#include "Display/input_event.h"
#include "Display/joystick.h"
#include "Display/key_binding.h"
#include "Display/keyboard.h"
#include "Display/keys.h"
#include "Display/mouse.h"
#include "Display/palette.h"
#include "Display/pixel_buffer.h"
#include "Display/pixel_format.h"
#include "Display/pixel_format_type.h"
#include "Display/rle_surface.h"
#include "Display/setupdisplay.h"
#include "Display/sprite.h"
#include "Display/sprite_description.h"
#include "Display/sprite_packer.h"
#include "Display/surface.h"
#include "Display/canvas.h"
#include "Display/text_styler.h"
#include "Display/Providers/jpeg_provider.h"
#include "Display/Providers/pcx_provider.h"
#include "Display/Providers/png_provider.h"
#include "Display/Providers/targa_provider.h"
#include "Display/Providers/provider_factory.h"
#include "Display/Providers/provider_type.h"
#include "Display/Collision/collision_outline.h"
#include "Display/Collision/outline_accuracy.h"

#if defined (_MSC_VER)
#if !defined (_DEBUG)
#pragma comment(lib, "clanDisplay.lib")
#else
#pragma comment(lib, "clanDisplayd.lib")
#endif
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dinput.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "libpng.lib")
#endif

#endif
