// $Header: /home/cvs/Development/SketchUp/Source/MacWin/tchar.h,v 1.5 2005/05/10 18:38:51 joee Exp $
//=============================================================================
// Copyright 1999-2003 @Last Software
//=============================================================================

// The wchar_t support on the Mac is pretty much useless.  wchar_t is defined
// as a 32 bit value in gcc, but all of the Mac UI and CFString uses unichar
// which is a 16 bit value.

// Because of this, we can't use wchar_t on the Mac.  Internally in SketchUp
// we always use the macros WCHAR and TCHAR.  WCHAR is a typdef for unichar
// and since we only build a unicode version on the Mac, TCHAR == WCHAR.

#ifndef _tchar_h_
#define _tchar_h_

// On the Mac, we always use unicode, so TCHAR = WCHAR
#ifndef _UNICODE
#define _UNICODE
#endif

#include <SketchUpReader/wintype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

//=============================================================================
// First define WCHAR

#ifndef WCHAR_DEFINED
typedef unsigned short unichar;
typedef unichar WCHAR;
#define WCHAR_DEFINED
#endif

typedef WCHAR *PWCHAR;
typedef WCHAR *LPWCH, *PWCH;
typedef CONST WCHAR *LPCWCH, *PCWCH;
typedef WCHAR *NWPSTR;
typedef WCHAR *LPWSTR, *PWSTR;

typedef CONST WCHAR *LPCWSTR, *PCWSTR;

#ifndef WCHAR_MIN
#define WCHAR_MIN       0
#endif

#ifndef WCHAR_MAX
#define WCHAR_MAX       ((unicahr)-1)
#endif

#ifndef WEOF
#define WEOF (WCHAR)(0xFFFF)
#endif

//=============================================================================

// Define TCHAR - it is the same as WCHAR

#ifndef _TCHAR_DEFINED

typedef WCHAR TCHAR, *PTCHAR;
typedef WCHAR TBYTE , *PTBYTE ;
typedef WCHAR _TUCHAR;

#define _TCHAR_DEFINED
#endif /* !_TCHAR_DEFINED */

typedef LPWSTR LPTCH, PTCH;
typedef LPWSTR PTSTR, LPTSTR;
typedef LPCWSTR LPCTSTR;
typedef LPWSTR LP;

// The mac uses unichar instead of wchar_t.  I can't find any compile
// time feature for creating constant unichar strings (like L"abc" which
// creates a wchar_t constant.  For this reason, we need to use this more
// comlicated macro which actually does the conversion at runtime.

#define __TEXT(quote) A2CW(quote)
#define _TEOF       EOF
#define __T(x) A2CW(x)

#define TEXT(quote) __TEXT(quote)
#define _T(x)       __T(x)
#define _TEXT(x)    __T(x)

//=============================================================================

// On Windows, all of these _tcs functions are macros that switch between wchar
// and char* versions.  On the Mac, we only need the WCHAR versions.

#ifdef __cplusplus
extern "C"
{
#endif

inline char* _strinc(const char * _pc) { return (char *)(_pc+1); }
inline WCHAR* _wcsinc(const WCHAR * _pc) { return (WCHAR *)(_pc+1); }

// TODO_MAC: do something about these
extern int _stricmp(const char*, const char*);
extern int _stricoll(const char*, const char*);
extern char* _strupr(char* s);
extern char* _strlwr(char* s);
extern char* _strrev(char* s);

//===================================================================

WCHAR* _tcscat(WCHAR *, const WCHAR *);
WCHAR* _tcschr(const WCHAR *, WCHAR);
WCHAR* _tcscpy(WCHAR *, const WCHAR *);
size_t _tcscspn(const WCHAR *, const WCHAR *);
size_t _tcslen(const WCHAR *);
WCHAR* _tcsncat(WCHAR *, const WCHAR *, size_t);
WCHAR* _tcsncpy(WCHAR *, const WCHAR *, size_t);
WCHAR* _tcspbrk(const WCHAR *, const WCHAR *);
WCHAR* _tcsrchr(const WCHAR *, WCHAR);
size_t _tcsspn(const WCHAR *, const WCHAR *);
WCHAR* _tcsstr(const WCHAR *, const WCHAR *);
WCHAR* _tmemset(WCHAR*, WCHAR, size_t);
WCHAR* _tmemchr(const WCHAR*, WCHAR, size_t);

void _tsplitpath(const WCHAR* path,
                 WCHAR* drive, WCHAR* dir, WCHAR* filename, WCHAR* ext);

WCHAR* _tcsrev(WCHAR *);

int _tcscmp(const WCHAR *, const WCHAR *);
int _tcsicmp(const WCHAR *, const WCHAR *);
int _tcsnccmp(const WCHAR *, const WCHAR *, size_t);

WCHAR* _tcslwr(WCHAR *);
WCHAR* _tcsupr(WCHAR *);
inline WCHAR* _tcsinc(const WCHAR * _pc) { return (WCHAR *)(_pc+1); }

int _tcscoll(const WCHAR *, const WCHAR *);
int _tcsicoll(const WCHAR *, const WCHAR *);

int _ttoi(const WCHAR* s);
long _ttol(const WCHAR* s);

// ctype
#ifndef __cplusplus
#define _istdigit(c)    ( isdigit((int)c) )
#define _istspace(c)    ( isspace((int)c) )
#else   /* __cplusplus */
inline int _istdigit(WCHAR c) {return (isdigit((int)c)); }
inline int _istspace(WCHAR c) {return (isspace((int)c)); }
#endif  /* __cplusplus */

// Read a single unicode value from a file (16 bits)
WCHAR fgetunichar(FILE *fp);
 
/* Formatted i/o */

FILE* _tfopen(const WCHAR* filename, const WCHAR* mode);
int _taccess(const WCHAR* path, int mode);
int _tprintf(FILE *, const WCHAR *, ...);
int _ftprintf(FILE *, const WCHAR *, ...);
int _stprintf(WCHAR *, const WCHAR *, ...);
int _vtprintf(const WCHAR *, va_list);
int _vftprintf(FILE *, const WCHAR *, va_list);

// Time functions
size_t _tcsftime(WCHAR* sDst, size_t maxSize, const WCHAR* fmt, const struct tm* t);

//-------------------------------------------------------------------

// We assume that we never have MBCS on mac
#define _istlegal(_c)   (1)
#define _istlead(_c)    (0)
#define _istleadbyte(_c)    (0)

//-------------------------------------------------------------------

#define lstrlen _tcslen
#define lstrlenA strlen

inline LPTSTR lstrcpyn(LPTSTR d, LPCTSTR s, int n)
{
    LPTSTR r = _tcsncpy(d, s, n);
    d[n] = 0;
    return r;
}

#define wsprintf _stprintf

// End of extern "C"
#ifdef __cplusplus
}
#endif

//===================================================================
// Functions and Macros for converting from unicode to MBCS

extern size_t WcsToMbcs(char* mbstr, const WCHAR* wcstr, size_t count);
extern size_t MbcsToWcs(WCHAR* wcstr, const char* mbstr, size_t count);

// These globals are only used to temporarily hold a pointer to memory that
// is allocated on the stack using the macros.  It is to avoid having to include
// the USES_CONVERSION macro that is used on Windows.
extern unichar* _tempUnicharBuffer;
extern char* _tempCharBuffer;
extern wchar_t* _tempWCharBuffer;
extern size_t _tempBufferSize;

// Do not use these function directly.  Instead, use the macros A2W or W2A
extern unichar* A2WHelper(const char* ch, unichar* buffer, size_t l);
extern char* W2AHelper(const unichar* ch, char* buffer, size_t l);

// The native Mac API uses unichar for all UniCode stuff.  If we use some other
// UNIX tools though, they use wchar_t.  This function does the conversion.  Use
// the macro version of this
extern wchar_t* W2wchar_tHelper(const unichar* ch, wchar_t* buffer, size_t l);

// The USES_CONVERSION macro is not really needed in this implementation, but
// it is maintained for compatibility
#define USES_CONVERSION _tempBufferSize = 0

// This allocates memory on the stack to return the string data, so it
// automatically freed when it goes out of scope.
#define A2W(s) \
(_tempBufferSize = strlen((s)),\
 _tempUnicharBuffer = (unichar*)alloca((_tempBufferSize+1)*sizeof(unichar)), \
 A2WHelper((s), _tempUnicharBuffer, _tempBufferSize))

#define W2A(s) \
(_tempBufferSize = _tcslen((s)) * 2,\
 _tempCharBuffer = (char*)alloca((_tempBufferSize+1)*sizeof(char)), \
 W2AHelper((s), _tempCharBuffer, _tempBufferSize))

#define A2CW(lpa) ((LPCWSTR)A2W(lpa))
#define W2CA(lpw) ((LPCSTR)W2A(lpw))

#define W2wchar_t(s) \
(_tempBufferSize = _tcslen((s)),\
 _tempWCharBuffer = (wchar_t*)alloca((_tempBufferSize+1)*sizeof(wchar_t)), \
 W2wchar_tHelper((s), _tempWCharBuffer, _tempBufferSize))

// Conversion macros
// These come from atlconv.h on Windows

#define CP_ACP 0

#define A2T A2W
#define A2CT A2CW
#define T2A W2A
#define T2CA W2CA

#define T2W(t) t
#define T2CW(t) (LPCWSTR)t
#define W2T(t) t
#define W2CT(t) (LPCTSTR)t

#define T2wchar_t W2wchar_t

// This is currently a Mac only conversion utility.  It converts a unicode string
// (given as a LPCTSTR) into a const char* that is in the right format for use
// in file functions.  It is not implemented as a macro.  The string that is
// returned is owned by an auto-released NSString that is created by the function
// so it needs to be copied if you want to save it around.
const char* W2PATH(const WCHAR* path);
#define T2PATH W2PATH

//=============================================================================
// Some utility funcitons for working with NSStrings

#ifdef __OBJC__

#include <Foundation/NSString.h>

// Get an NSString from a resource ID
extern NSString* StringFromResource(UINT nID);

// Format a string
extern NSString* FormatStringA(const char* lpszFormat, va_list argList);
extern NSString* FormatStringW(const WCHAR* lpszFormat, va_list argList);
//#define FormatString FormatStringW

// Get an NSString from an array
extern NSString* StringFromChars(const char* str);
extern NSString* StringFromChars(const WCHAR* str);

#endif

//=============================================================================
#endif // _tchar_h_
