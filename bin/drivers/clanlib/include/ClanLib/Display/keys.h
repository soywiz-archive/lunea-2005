/*  $Id: keys.h,v 1.11 2003/10/14 15:52:10 mbn Exp $
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

//! clanDisplay="Input"
//! header=display.h

#ifndef header_keys
#define header_keys

#if _MSC_VER > 1000
#pragma once
#endif

// Keyboard & mouse platform independence support.

#ifdef WIN32

#include <windows.h>

#define CL_MOUSE_LEFT 0
#define CL_MOUSE_RIGHT 1
#define CL_MOUSE_MIDDLE 2
#define CL_MOUSE_WHEEL_UP 3
#define CL_MOUSE_WHEEL_DOWN 4
#define CL_MOUSE_XBUTTON1 5
#define CL_MOUSE_XBUTTON2 6

#define CL_KEY_BACKSPACE VK_BACK
#define CL_KEY_TAB VK_TAB
#define CL_KEY_CLEAR VK_CLEAR
#define CL_KEY_RETURN VK_RETURN
#define CL_KEY_SHIFT VK_SHIFT
#define CL_KEY_CONTROL VK_CONTROL
#define CL_KEY_MENU VK_MENU
#define CL_KEY_PAUSE VK_PAUSE
#define CL_KEY_ESCAPE VK_ESCAPE

#if !defined(__CYGWIN__) && !defined(__MINGW32__)
#  define CL_KEY_KANJI      VK_KANJI
#  define CL_KEY_CONVERT    VK_CONVERT
#  define CL_KEY_NONCONVERT VK_NONCONVERT
#endif

#define CL_KEY_SPACE VK_SPACE
#define CL_KEY_PRIOR VK_PRIOR
#define CL_KEY_NEXT VK_NEXT
#define CL_KEY_END VK_END
#define CL_KEY_HOME VK_HOME
#define CL_KEY_LEFT VK_LEFT
#define CL_KEY_UP VK_UP
#define CL_KEY_RIGHT VK_RIGHT
#define CL_KEY_DOWN VK_DOWN
#define CL_KEY_SELECT VK_SELECT
#define CL_KEY_PRINT VK_PRINT
#define CL_KEY_EXECUTE VK_EXECUTE
#define CL_KEY_INSERT VK_INSERT
#define CL_KEY_DELETE VK_DELETE
#define CL_KEY_HELP VK_HELP
#define CL_KEY_0 '0'
#define CL_KEY_1 '1'
#define CL_KEY_2 '2'
#define CL_KEY_3 '3'
#define CL_KEY_4 '4'
#define CL_KEY_5 '5'
#define CL_KEY_6 '6'
#define CL_KEY_7 '7'
#define CL_KEY_8 '8'
#define CL_KEY_9 '9'
#define CL_KEY_A 'A'
#define CL_KEY_B 'B'
#define CL_KEY_C 'C'
#define CL_KEY_D 'D'
#define CL_KEY_E 'E'
#define CL_KEY_F 'F'
#define CL_KEY_G 'G'
#define CL_KEY_H 'H'
#define CL_KEY_I 'I'
#define CL_KEY_J 'J'
#define CL_KEY_K 'K'
#define CL_KEY_L 'L'
#define CL_KEY_M 'M'
#define CL_KEY_N 'N'
#define CL_KEY_O 'O'
#define CL_KEY_P 'P'
#define CL_KEY_Q 'Q'
#define CL_KEY_R 'R'
#define CL_KEY_S 'S'
#define CL_KEY_T 'T'
#define CL_KEY_U 'U'
#define CL_KEY_V 'V'
#define CL_KEY_W 'W'
#define CL_KEY_X 'X'
#define CL_KEY_Y 'Y'
#define CL_KEY_Z 'Z'
#define CL_KEY_LWIN VK_LWIN
#define CL_KEY_RWIN VK_RWIN
#define CL_KEY_APPS VK_APPS
#define CL_KEY_NUMPAD0 VK_NUMPAD0
#define CL_KEY_NUMPAD1 VK_NUMPAD1
#define CL_KEY_NUMPAD2 VK_NUMPAD2
#define CL_KEY_NUMPAD3 VK_NUMPAD3
#define CL_KEY_NUMPAD4 VK_NUMPAD4
#define CL_KEY_NUMPAD5 VK_NUMPAD5
#define CL_KEY_NUMPAD6 VK_NUMPAD6
#define CL_KEY_NUMPAD7 VK_NUMPAD7
#define CL_KEY_NUMPAD8 VK_NUMPAD8
#define CL_KEY_NUMPAD9 VK_NUMPAD9
#define CL_KEY_MULTIPLY VK_MULTIPLY
#define CL_KEY_ADD VK_ADD
#define CL_KEY_SEPARATOR VK_SEPARATOR
#define CL_KEY_SUBTRACT VK_SUBTRACT
#define CL_KEY_DECIMAL VK_DECIMAL
#define CL_KEY_DIVIDE VK_DIVIDE
#define CL_KEY_F1 VK_F1
#define CL_KEY_F2 VK_F2
#define CL_KEY_F3 VK_F3
#define CL_KEY_F4 VK_F4
#define CL_KEY_F5 VK_F5
#define CL_KEY_F6 VK_F6
#define CL_KEY_F7 VK_F7
#define CL_KEY_F8 VK_F8
#define CL_KEY_F9 VK_F9
#define CL_KEY_F10 VK_F10
#define CL_KEY_F11 VK_F11
#define CL_KEY_F12 VK_F12
#define CL_KEY_F13 VK_F13
#define CL_KEY_F14 VK_F14
#define CL_KEY_F15 VK_F15
#define CL_KEY_F16 VK_F16
#define CL_KEY_F17 VK_F17
#define CL_KEY_F18 VK_F18
#define CL_KEY_F19 VK_F19
#define CL_KEY_F20 VK_F20
#define CL_KEY_F21 VK_F21
#define CL_KEY_F22 VK_F22
#define CL_KEY_F23 VK_F23
#define CL_KEY_F24 VK_F24
#define CL_KEY_NUMLOCK VK_NUMLOCK
#define CL_KEY_SCROLL VK_SCROLL
#define CL_KEY_LSHIFT VK_LSHIFT
#define CL_KEY_RSHIFT VK_RSHIFT
#define CL_KEY_LCONTROL VK_LCONTROL
#define CL_KEY_RCONTROL VK_RCONTROL
#define CL_KEY_LMENU VK_LMENU
#define CL_KEY_RMENU VK_RMENU

#else

#include <X11/keysym.h>

#define CL_MOUSE_LEFT 0
#define CL_MOUSE_RIGHT 1
#define CL_MOUSE_MIDDLE 2
#define CL_MOUSE_WHEEL_UP 3
#define CL_MOUSE_WHEEL_DOWN 4
#define CL_MOUSE_XBUTTON1 5
#define CL_MOUSE_XBUTTON2 6

#define CL_KEY_BACKSPACE XK_BackSpace
#define CL_KEY_TAB XK_Tab
#define CL_KEY_CLEAR XK_Clear
#define CL_KEY_RETURN XK_Return
#define CL_KEY_SHIFT XK_Shift_L
#define CL_KEY_CONTROL XK_Control_L
#define CL_KEY_MENU XK_Menu // there is no XK_Alt, only XK_Alt_L and XK_Alt_R. Maybe remove this key? -- mbn 30 sep 2003
#define CL_KEY_PAUSE XK_Pause
#define CL_KEY_KANJI XK_Kanji
#define CL_KEY_ESCAPE XK_Escape
#define CL_KEY_CONVERT XK_Henkan_Mode
#define CL_KEY_NONCONVERT XK_Muhenkan
#define CL_KEY_SPACE XK_space
#define CL_KEY_PRIOR XK_Prior
#define CL_KEY_NEXT XK_Next
#define CL_KEY_END XK_End
#define CL_KEY_HOME XK_Home
#define CL_KEY_LEFT XK_Left
#define CL_KEY_UP XK_Up
#define CL_KEY_RIGHT XK_Right
#define CL_KEY_DOWN XK_Down
#define CL_KEY_SELECT XK_Select
#define CL_KEY_PRINT XK_Print
#define CL_KEY_EXECUTE XK_Execute
#define CL_KEY_INSERT XK_Insert
#define CL_KEY_DELETE XK_Delete
#define CL_KEY_HELP XK_Help
#define CL_KEY_0 XK_0
#define CL_KEY_1 XK_1
#define CL_KEY_2 XK_2
#define CL_KEY_3 XK_3
#define CL_KEY_4 XK_4
#define CL_KEY_5 XK_5
#define CL_KEY_6 XK_6
#define CL_KEY_7 XK_7
#define CL_KEY_8 XK_8
#define CL_KEY_9 XK_9
#define CL_KEY_A XK_a
#define CL_KEY_B XK_b
#define CL_KEY_C XK_c
#define CL_KEY_D XK_d
#define CL_KEY_E XK_e
#define CL_KEY_F XK_f
#define CL_KEY_G XK_g
#define CL_KEY_H XK_h
#define CL_KEY_I XK_i
#define CL_KEY_J XK_j
#define CL_KEY_K XK_k
#define CL_KEY_L XK_l
#define CL_KEY_M XK_m
#define CL_KEY_N XK_n
#define CL_KEY_O XK_o
#define CL_KEY_P XK_p
#define CL_KEY_Q XK_q
#define CL_KEY_R XK_r
#define CL_KEY_S XK_s
#define CL_KEY_T XK_t
#define CL_KEY_U XK_u
#define CL_KEY_V XK_v
#define CL_KEY_W XK_w
#define CL_KEY_X XK_x
#define CL_KEY_Y XK_y
#define CL_KEY_Z XK_z
#define CL_KEY_LWIN XK_Super_L
#define CL_KEY_RWIN XK_Multi_key
#define CL_KEY_APPS XK_Menu
#define CL_KEY_NUMPAD0 XK_KP_0
#define CL_KEY_NUMPAD1 XK_KP_1
#define CL_KEY_NUMPAD2 XK_KP_2
#define CL_KEY_NUMPAD3 XK_KP_3
#define CL_KEY_NUMPAD4 XK_KP_4
#define CL_KEY_NUMPAD5 XK_KP_5
#define CL_KEY_NUMPAD6 XK_KP_6
#define CL_KEY_NUMPAD7 XK_KP_7
#define CL_KEY_NUMPAD8 XK_KP_8
#define CL_KEY_NUMPAD9 XK_KP_9
#define CL_KEY_MULTIPLY XK_KP_Multiply
#define CL_KEY_ADD XK_KP_Add
#define CL_KEY_SEPARATOR XK_KP_Separator
#define CL_KEY_SUBTRACT XK_KP_Subtract
#define CL_KEY_DECIMAL XK_KP_Decimal
#define CL_KEY_DIVIDE XK_KP_Divide
#define CL_KEY_F1 XK_F1
#define CL_KEY_F2 XK_F2
#define CL_KEY_F3 XK_F3
#define CL_KEY_F4 XK_F4
#define CL_KEY_F5 XK_F5
#define CL_KEY_F6 XK_F6
#define CL_KEY_F7 XK_F7
#define CL_KEY_F8 XK_F8
#define CL_KEY_F9 XK_F9
#define CL_KEY_F10 XK_F10
#define CL_KEY_F11 XK_F11
#define CL_KEY_F12 XK_F12
#define CL_KEY_F13 XK_F13
#define CL_KEY_F14 XK_F14
#define CL_KEY_F15 XK_F15
#define CL_KEY_F16 XK_F16
#define CL_KEY_F17 XK_F17
#define CL_KEY_F18 XK_F18
#define CL_KEY_F19 XK_F19
#define CL_KEY_F20 XK_F20
#define CL_KEY_F21 XK_F21
#define CL_KEY_F22 XK_F22
#define CL_KEY_F23 XK_F23
#define CL_KEY_F24 XK_F24
#define CL_KEY_NUMLOCK XK_Num_Lock
#define CL_KEY_SCROLL XK_Scroll_Lock
#define CL_KEY_LSHIFT XK_Shift_L
#define CL_KEY_RSHIFT XK_Shift_R
#define CL_KEY_LCONTROL XK_Control_L
#define CL_KEY_RCONTROL XK_Control_R
#define CL_KEY_LMENU XK_Meta_L
#define CL_KEY_RMENU XK_Meta_R
#endif

#define CL_KEY_ENTER CL_KEY_RETURN

#endif
