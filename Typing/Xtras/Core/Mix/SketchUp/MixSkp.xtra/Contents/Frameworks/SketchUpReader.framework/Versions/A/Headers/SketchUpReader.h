// $Header: /home/cvs/refactor/source/sketchup/macreader/SketchUpReader.h,v 1.17 2007/04/19 21:17:13 mikes Exp $
//=============================================================================
// Copyright 1999-2002 @Last Software
//=============================================================================

#ifndef SketchUpReader_H
#define SketchUpReader_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

#include <SketchUpReader/windef.h>
#include <SketchUpReader/wintype.h>
#include <SketchUpReader/tchar.h>
#include <SketchUpReader/BSTR.h>
#include <SketchUpReader/Variant.h>
#include <SketchUpReader/comptr.h>

#include <SketchUpReader/SketchUpInterfaces.h>
#include <SketchUpReader/IProgressCB.h>

//=============================================================================

extern HRESULT GetModelFromPasteboard(ISkpDocument** ppDoc);
extern HRESULT GetSketchUpSkpApplication(ISkpApplication** ppApp);

//-----------------------------------------------------------------------------
#ifdef __OBJC__
//#include "SketchUpView.h"
#endif

//=============================================================================
#endif
