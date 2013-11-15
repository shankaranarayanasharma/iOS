// $Header: /home/cvs/refactor/source/common/utils/mac/wintype.h,v 1.1 2005/11/30 00:20:07 jeffh Exp $
//=============================================================================
// Copyright 1999-2001 @Last Software
//=============================================================================

// Define things that are used on Windows all the time that are not defined on Mac

#ifndef _WINTYPES_H_
#define _WINTYPES_H_

#if defined(__APPLE__) || defined(__LINUX__)

#ifndef _MAC
#ifdef __APPLE__
#define _MAC
#endif
#endif

#include <ctype.h>

// On the Mac, ctype.h defines _T.  This is used all over in SketchUp
// for doing generic text handling, so we need to undefine it
#undef _T

//===================================================================

// Standard constants
#undef FALSE
#undef TRUE
#undef NULL

#define FALSE   0
#define TRUE    1
#define NULL    0

#define _MAX_PATH 255

//===================================================================

// NOTE: On Windows, BOOL is defined as 'int'. In Objective-C however,
// there is a BOOL type that is a 'char'.  We use the Windows definition
// so that things of type BOOL are serialized correcly.  We cannot redefine
// it in files that include objective-C headers though.
#ifndef __OBJC__
typedef int             BOOL;
#endif
typedef int             CBOOL;

typedef unsigned long   DWORD;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef float           FLOAT;
typedef FLOAT           *PFLOAT;
//typedef BOOL            *PBOOL;
//typedef BOOL            *LPBOOL;
typedef BYTE            *PBYTE;
typedef BYTE            *LPBYTE;
typedef int             *PINT;
typedef int             *LPINT;
typedef WORD            *PWORD;
typedef WORD            *LPWORD;
typedef long            *LPLONG;
typedef DWORD           *PDWORD;
typedef DWORD           *LPDWORD;
typedef void            *LPVOID;
#define CONST const
typedef CONST void      *LPCVOID;

typedef int             INT;
typedef unsigned int    UINT;
typedef unsigned int    *PUINT;

#define VOID void
typedef char CHAR;
typedef short SHORT;
typedef unsigned short USHORT;
typedef long LONG;
typedef unsigned long ULONG;

#define UNALIGNED

//
// ANSI (Multi-byte Character) types
//
typedef CHAR *PCHAR;
typedef CHAR *LPCH, *PCH;

typedef CONST CHAR *LPCCH, *PCCH;
typedef CHAR *NPSTR;
typedef CHAR *LPSTR, *PSTR;
typedef CONST CHAR *LPCSTR, *PCSTR;

#ifndef WCHAR_DEFINED
typedef unsigned short unichar;
typedef unichar WCHAR;
#define WCHAR_DEFINED
#endif

//-------------------------------------------------------------------
// Calling conventions

#define CDECL
#define CALLBACK    PASCAL
#define WINAPI      CDECL
#define WINAPIV     CDECL
#define APIENTRY    WINAPI
#define APIPRIVATE  CDECL
#define PASCAL
#define AFXAPI
#define FASTCALL

#define AFX_DATA
#define AFX_DATADEF
#define AFX_API
#define AFX_CDECL

//===================================================================

inline long InterlockedIncrement(long* val)
{
    (*val)++;
    return *val;
}

inline long InterlockedDecrement(long* val)
{
    (*val)--;
    return *val;
}

//-------------------------------------------------------------------

#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;
#endif /* GUID_DEFINED */

//-------------------------------------------------------------------
// These are no longer used on the Mac
#if 0
typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
        BYTE    rgbBlue;
        BYTE    rgbGreen;
        BYTE    rgbRed;
        BYTE    rgbReserved;
} RGBQUAD, *LPRGBQUAD;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO, *LPBITMAPINFO, *PBITMAPINFO;

#define BI_RGB			0L
#define BI_RLE8			1L
#define BI_RLE4			2L
#define BI_BITFIELDS	3L

#endif

//===================================================================

typedef LONG LPARAM;
typedef UINT WPARAM;
typedef LONG LRESULT;

typedef void* HCURSOR;
typedef void* HICON;
typedef void* HWND;
typedef void* CWnd;
typedef long HINSTANCE;

//===================================================================
#endif // __APPLE__
#endif //_WINTYPES_H_


