/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM E:\Documents and Settings\ivanmen\Mis documentos\Visual Studio 2008\Projects\Mozilla  Sdks\mozilla-1.9.1\modules\plugin\tools\sdk\samples\scriptable\npWinFormsHost\nsIPluginWinForms.idl
 */

#ifndef __gen_nsIPluginWinForms_h__
#define __gen_nsIPluginWinForms_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptablePluginSample */
#define NS_ISCRIPTABLEPLUGINSAMPLE_IID_STR "d2d536a0-b6fc-11d5-9d10-0060b0fbd8ac"

#define NS_ISCRIPTABLEPLUGINSAMPLE_IID \
  {0xd2d536a0, 0xb6fc, 0x11d5, \
    { 0x9d, 0x10, 0x00, 0x60, 0xb0, 0xfb, 0xd8, 0xac }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptablePluginSample : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEPLUGINSAMPLE_IID)

  /* void showVersion (); */
  NS_SCRIPTABLE NS_IMETHOD ShowVersion(void) = 0;

  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /* PRUint32 invokeMethod (in string aCommandName, in string aCommandParameter); */
  NS_SCRIPTABLE NS_IMETHOD InvokeMethod(const char *aCommandName, const char *aCommandParameter, PRUint32 *_retval) = 0;

  /* PRBool loadClassUI (in string aAssemblyLocation, in string aclassFullName); */
  NS_SCRIPTABLE NS_IMETHOD LoadClassUI(const char *aAssemblyLocation, const char *aclassFullName, PRBool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptablePluginSample, NS_ISCRIPTABLEPLUGINSAMPLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEPLUGINSAMPLE \
  NS_SCRIPTABLE NS_IMETHOD ShowVersion(void); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD InvokeMethod(const char *aCommandName, const char *aCommandParameter, PRUint32 *_retval); \
  NS_SCRIPTABLE NS_IMETHOD LoadClassUI(const char *aAssemblyLocation, const char *aclassFullName, PRBool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEPLUGINSAMPLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowVersion(void) { return _to ShowVersion(); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD InvokeMethod(const char *aCommandName, const char *aCommandParameter, PRUint32 *_retval) { return _to InvokeMethod(aCommandName, aCommandParameter, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadClassUI(const char *aAssemblyLocation, const char *aclassFullName, PRBool *_retval) { return _to LoadClassUI(aAssemblyLocation, aclassFullName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEPLUGINSAMPLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowVersion(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowVersion(); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD InvokeMethod(const char *aCommandName, const char *aCommandParameter, PRUint32 *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvokeMethod(aCommandName, aCommandParameter, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadClassUI(const char *aAssemblyLocation, const char *aclassFullName, PRBool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadClassUI(aAssemblyLocation, aclassFullName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptablePluginSample : public nsIScriptablePluginSample
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEPLUGINSAMPLE

  nsScriptablePluginSample();

private:
  ~nsScriptablePluginSample();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptablePluginSample, nsIScriptablePluginSample)

nsScriptablePluginSample::nsScriptablePluginSample()
{
  /* member initializers and constructor code */
}

nsScriptablePluginSample::~nsScriptablePluginSample()
{
  /* destructor code */
}

/* void showVersion (); */
NS_IMETHODIMP nsScriptablePluginSample::ShowVersion()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsScriptablePluginSample::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 invokeMethod (in string aCommandName, in string aCommandParameter); */
NS_IMETHODIMP nsScriptablePluginSample::InvokeMethod(const char *aCommandName, const char *aCommandParameter, PRUint32 *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool loadClassUI (in string aAssemblyLocation, in string aclassFullName); */
NS_IMETHODIMP nsScriptablePluginSample::LoadClassUI(const char *aAssemblyLocation, const char *aclassFullName, PRBool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginWinForms_h__ */
