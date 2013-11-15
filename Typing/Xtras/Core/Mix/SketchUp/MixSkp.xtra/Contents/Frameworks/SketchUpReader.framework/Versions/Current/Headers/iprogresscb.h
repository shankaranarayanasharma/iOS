// $Header: /home/cvs/refactor/source/sketchup/objmodel/iprogresscb.h,v 1.3 2005/02/04 21:53:34 markl Exp $
//=============================================================================
// Copyright 1999-2002 @Last Software
//=============================================================================

#ifndef IProgressCB_H
#define IProgressCB_H

//=============================================================================

#ifdef _WINDOWS
struct __declspec(uuid("{F84E9A80-2DED-11d5-9476-0050DA73EEF2}")) IProgressCB;
DEFINE_GUID(IID_IProgressCB, 0xF84E9A80, 0x2DED, 0x11d5, 0x94, 0x76, 0x00, 0x50, 0xDA, 0x73, 0xEE, 0xF2);
#else
#include <SketchUpReader/comtype.h>
typedef struct IProgressCB IProgressCB;
extern const IID IID_IProgressCB;
#endif

//=============================================================================
#ifndef __IProgressCB_FWD_DEFINED__
#define __IProgressCB_FWD_DEFINED__

struct IProgressCB : IUnknown
{
    STDMETHOD(HasBeenCancelled)(/*[out]*/ BOOL* pVal) = 0;
    STDMETHOD(SetPercentDone)(/*[in]*/ double percent) = 0;
    STDMETHOD(SetStepSize)(/*[in]*/ double percent) = 0;
    STDMETHOD(Step)() = 0;
    STDMETHOD(SetProgressMessage)(/*[in]*/ BSTR msg) = 0;
    
    virtual ~IProgressCB() {}
};

#endif // __IProgressCB_FWD_DEFINED__
//=============================================================================
#endif // IProgressCB_H
