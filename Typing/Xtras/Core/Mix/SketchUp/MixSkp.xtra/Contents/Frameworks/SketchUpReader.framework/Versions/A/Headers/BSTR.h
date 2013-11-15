// $Header: /home/cvs/refactor/source/sketchup/macwin/BSTR.h,v 1.6 2007/04/05 21:29:25 mikes Exp $
//=============================================================================
// Copyright 1999-2003 @Last Software
//=============================================================================
//
//  BSTR.h

#ifndef BSTR_H
  #define BSTR_H
  #if defined(__APPLE__) || defined(__LINUX__)
    #if defined(SketchUpReader_H)
      // this means that this is used in SketchUp.framework
      #include <SketchUpReader/wintype.h>
      #include <SketchUpReader/comtype.h>
    #else
      #include "source/common/utils/mac/wintype.h"
      #include "source/sketchup/macwin/comtype.h"
    #endif

    #ifdef __OBJC__
      #include <Foundation/NSString.h>
    #endif 

class _variant_t;

//=============================================================================

// Wrapper class for BSTR
//
//////////////////////////////////////////////////////////////////////////////

class _bstr_t {
public:
  // Constructors
  //
  _bstr_t();
  _bstr_t(const _bstr_t &s);
  _bstr_t(const char *s);
  _bstr_t(const WCHAR *s);
  _bstr_t(const _variant_t &var);
  _bstr_t(BSTR bstr, bool fCopy);

    #ifdef __OBJC__
  _bstr_t(NSString *s);
    #endif 

  // Destructor
  //
  ~_bstr_t();

  // Assignment operators
  //
  _bstr_t &operator = (const _bstr_t &s);
  _bstr_t &operator = (const char *s);
  _bstr_t &operator = (const WCHAR *s);
  _bstr_t &operator = (const _variant_t &var);

  // Operators
  //
  _bstr_t &operator += (const _bstr_t &s);
  _bstr_t operator + (const _bstr_t &s)const;

  // Friend operators
  //
  friend _bstr_t operator + (const char *s1, const _bstr_t &s2);
  friend _bstr_t operator + (const WCHAR *s1, const _bstr_t &s2);

  // Let us use this as a BSTR
  operator const BSTR()const;
  BSTR *operator &();

  // Extractors
  //
  // NOTE: The WCHAR versions of these return a pointer to a static
  // array, so you have to be careful how you use it.
  operator const WCHAR *()const;
  operator WCHAR *()const;
  operator const char *()const;
  operator char *()const;

  // Comparison operators
  //
  bool operator !()const;
  bool operator == (const _bstr_t &str)const;
  bool operator != (const _bstr_t &str)const;
  bool operator < (const _bstr_t &str)const;
  bool operator > (const _bstr_t &str)const;
  bool operator <= (const _bstr_t &str)const;
  bool operator >= (const _bstr_t &str)const;

  // Low-level helper functions
  //
  BSTR copy()const;
  unsigned int length()const;

  // Binary string assign
  //
  void Assign(BSTR s);

private:
  BSTR m_bstr;

private:
  void AddRef();
  void Release();
};

//=============================================================================

const char *BSTRToUTF8(BSTR s);
const char *BSTRToPath(BSTR s);

BSTR BSTRCreate(const char *s);
BSTR BSTRCreate(const WCHAR *s);
bool BSTREqual(BSTR s1, BSTR s2);

inline BSTR SysAllocString(const char *s) {
  return BSTRCreate(s);
}

inline BSTR SysAllocString(const WCHAR *s) {
  return BSTRCreate(s);
}

void SysFreeString(BSTR s);

//=============================================================================
  #endif // __APPLE__
#endif // BSTR_H
