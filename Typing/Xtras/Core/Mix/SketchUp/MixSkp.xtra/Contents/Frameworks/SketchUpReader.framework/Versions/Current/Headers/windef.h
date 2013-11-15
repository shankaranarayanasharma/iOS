// $Header: /home/cvs/refactor/source/sketchup/macwin/windef.h,v 1.6 2007/04/14 19:35:00 mikes Exp $
//=============================================================================
// Copyright 1999-2001 @Last Software
//=============================================================================

// Various macros that are defined in Windows but not on Mac

#ifndef _windef_h_
#define _windef_h_
#if defined(__APPLE__) || defined(__LINUX__)

//  windef.h
//  
//  Created by joe on Fri Aug 10 2001.
#if defined(SketchUpReader_H) 
// this means that this is used in SketchUp.framework
#include <SketchUpReader/wintype.h>
#else
#include "source/common/utils/mac/wintype.h"
#endif

#ifdef __LINUX__
#include "source/common/utils/linux/stubbed.h"
#endif

//=============================================================================

// Do not define this because it causes conflicts with objective-C code
//#define interface struct

//-------------------------------------------------------------------

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
#define LOWORD(l)           ((WORD)(l))
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#define LOBYTE(w)           ((BYTE)(w))
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))

#define MAX_PATH 255

//-------------------------------------------------------------------

#include <algorithm>
using std::min;
using std::max;

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

//-------------------------------------------------------------------

/*
 * MessageBox() Flags
 */
#define MB_OK                       0x00000000L
#define MB_OKCANCEL                 0x00000001L
#define MB_ABORTRETRYIGNORE         0x00000002L
#define MB_YESNOCANCEL              0x00000003L
#define MB_YESNO                    0x00000004L
#define MB_RETRYCANCEL              0x00000005L

#define MB_ICONHAND                 0x00000010L
#define MB_ICONQUESTION             0x00000020L
#define MB_ICONEXCLAMATION          0x00000030L
#define MB_ICONASTERISK             0x00000040L

#define MB_USERICON                 0x00000080L
#define MB_ICONWARNING              MB_ICONEXCLAMATION
#define MB_ICONERROR                MB_ICONHAND

/*
 * Dialog Box Command IDs
 */
#define IDOK            1
#define IDCANCEL        2
#define IDABORT         3
#define IDRETRY         4
#define IDIGNORE        5
#define IDYES           6
#define IDNO            7
#define IDCLOSE         8
#define IDHELP          9

//-------------------------------------------------------------------
// On Windows, these are defined in winuser.h

/*
 * Virtual Keys, Standard Set
 * NOTE: Mac returns UNICODE codes, so some of these do not
 * match the Windows equivalent.  Unicode characters in the range
 * 0xF7xx are for "private use" and are apparently what the mac is using
 */
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#define VK_BACK           0x7F
#define VK_TAB            0x09

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

#define VK_SHIFT          (1<<17)
#define VK_CONTROL        (1<<18)
#define VK_ALT			  (1<<19)
#define VK_COMMAND        (1<<20)
#define VK_MENU           VK_ALT
//#define VK_SHIFT          0x10
//#define VK_CONTROL        0x11
//#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#define VK_KANA           0x15
#define VK_HANGEUL        0x15  /* old name - should be here for compatibility */
#define VK_HANGUL         0x15
#define VK_JUNJA          0x17
#define VK_FINAL          0x18
#define VK_HANJA          0x19
#define VK_KANJI          0x19

#define VK_ESCAPE         0x1B

#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

#define VK_SPACE          0x20
#define VK_PRIOR          0xF72C
#define VK_NEXT           0xF72D
#define VK_END            0xF72B
#define VK_HOME           0xF729
#define VK_LEFT           0xF702
#define VK_UP             0xF700
#define VK_RIGHT          0xF703
#define VK_DOWN           0xF701
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0xF728
#define VK_HELP           0x2F

/* VK_0 thru VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) */
/* VK_A thru VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) */

#define VK_LWIN           0x5B
#define VK_RWIN           0x5C
#define VK_APPS           0x5D

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0xF704
#define VK_F2             0xF705
#define VK_F3             0xF706
#define VK_F4             0xF707
#define VK_F5             0xF708
#define VK_F6             0xF709
#define VK_F7             0xF70A
#define VK_F8             0xF70B
#define VK_F9             0xF70C
#define VK_F10            0xF70D
#define VK_F11            0xF70E
#define VK_F12            0xF70F
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87

#define VK_NUMLOCK        0x90
#define VK_SCROLL         0x91

/*
 * Key State Masks for Mouse Messages
 * NOTE: These values are based on the constants returned by NSEvent
 * and are different than the values that we get on Windows.
 */
#define MK_LBUTTON  (1<<1)
#define MK_RBUTTON  (1<<3)
#define MK_SHIFT    (1<<17)
#define MK_CONTROL  (1<<18)
#define MK_MBUTTON  (1<<25)

#define MK_ALT		(1<<19)
#define MK_COMMAND	(1<<20)

// Constants used to control menu item display
#define MF_ENABLED   0x00000000L
#define MF_GRAYED    0x00000001L
#define MF_DISABLED  0x00000002L
#define MF_CHECKED   0x00000008L
#define MF_UNCHECKED 0x00000000L

//-------------------------------------------------------------------

// TODO_MAC: We should probably remove this call from the SketchUp model layer
extern void Sleep(DWORD mSec);

//-------------------------------------------------------------------

#define _alloca alloca

//=============================================================================
#endif // __APPLE__
#endif // _windef_h_
