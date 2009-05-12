#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "ClassLoader.h"
#include "plugin.h"
#include "nsIServiceManager.h"
#include "nsISupportsUtils.h" // some usefule macros are defined here

using namespace System::Collections;
using namespace npscriptable;
  
LRESULT CALLBACK PluginWinProc(HWND, UINT, WPARAM, LPARAM);


//////////////////////////////////////
//
// general initialization and shutdown
//
NPError NS_PluginInitialize()
{
  return NPERR_NO_ERROR;
}

void NS_PluginShutdown()
{


}

/////////////////////////////////////////////////////////////
//
// construction and destruction of our plugin instance object
//
nsPluginInstanceBase * NS_NewPluginInstance(nsPluginCreateData * aCreateDataStruct)
{
  if(!aCreateDataStruct)
    return NULL;

  nsPluginInstance * plugin = new nsPluginInstance(aCreateDataStruct->instance);
  return plugin;
}

void NS_DestroyPluginInstance(nsPluginInstanceBase * aPlugin)
{
  if(aPlugin)
    delete (nsPluginInstance *)aPlugin;
}

////////////////////////////////////////
//
// nsPluginInstance class implementation
//
nsPluginInstance::nsPluginInstance(NPP aInstance) : nsPluginInstanceBase(),
  mInstance(aInstance),
  mInitialized(FALSE),
  mScriptablePeer(NULL)
{
  mhWnd = NULL;
  mString[0] = '\0';
  lpOldProc = NULL;
}

nsPluginInstance::~nsPluginInstance()
{
  // mScriptablePeer may be also held by the browser 
  // so releasing it here does not guarantee that it is over
  // we should take precaution in case it will be called later
  // and zero its mPlugin member
  mScriptablePeer->SetInstance(NULL);
  NS_IF_RELEASE(mScriptablePeer);
}

NPBool nsPluginInstance::init(NPWindow* aWindow)
{
  if(aWindow == NULL)  
	  return FALSE;

  
  mhWnd = (HWND)aWindow->window;
  if(mhWnd == NULL)
    return FALSE;



  // subclass window so we can intercept window messages and
  // do our drawing to it
  lpOldProc = SubclassWindow(mhWnd, (WNDPROC)PluginWinProc);

  // associate window with our nsPluginInstance object so we can access 
  // it in the window procedure
  SetWindowLong(mhWnd, GWL_USERDATA, (LONG)this);

  mInitialized = TRUE;
  return TRUE;
}

void nsPluginInstance::shut()
{
  // subclass it back
  SubclassWindow(mhWnd, lpOldProc);
  mhWnd = NULL;
  mInitialized = FALSE;
}

NPBool nsPluginInstance::isInitialized()
{
  return mInitialized;
}

// this will force to draw a version string in the plugin window
void nsPluginInstance::showVersion()
{
  
	
	const char *ua = NPN_UserAgent(mInstance);
	strcpy(mString, ua);
	InvalidateRect(mhWnd, NULL, TRUE);
	UpdateWindow(mhWnd);

}

// this will clean the plugin window
void nsPluginInstance::clear()
{
  strcpy(mString, "");
  InvalidateRect(mhWnd, NULL, TRUE);
  UpdateWindow(mhWnd);
}


// ==============================
// ! Scriptability related code !
// ==============================
//
// here the plugin is asked by Mozilla to tell if it is scriptable
// we should return a valid interface id and a pointer to 
// nsScriptablePeer interface which we should have implemented
// and which should be defined in the corressponding *.xpt file
// in the bin/components folder
NPError	nsPluginInstance::GetValue(NPPVariable aVariable, void *aValue)
{
  NPError rv = NPERR_NO_ERROR;

  if (aVariable == NPPVpluginScriptableInstance) {
    // addref happens in getter, so we don't addref here
    nsIScriptablePluginSample * scriptablePeer = getScriptablePeer();
    if (scriptablePeer) {
      *(nsISupports **)aValue = scriptablePeer;
    } else
      rv = NPERR_OUT_OF_MEMORY_ERROR;
  }
  else if (aVariable == NPPVpluginScriptableIID) {
    static nsIID scriptableIID = NS_ISCRIPTABLEPLUGINSAMPLE_IID;
    nsIID* ptr = (nsIID *)NPN_MemAlloc(sizeof(nsIID));
    if (ptr) {
        *ptr = scriptableIID;
        *(nsIID **)aValue = ptr;
    } else
      rv = NPERR_OUT_OF_MEMORY_ERROR;
  }

  return rv;
}




void nsPluginInstance::SetUserControl(System::Windows::Forms::UserControl^ usrCtr)
{
	SetParent( (HWND)  ClassLoader::Instance->MainUserControl->Handle.ToPointer(), mhWnd);

}





// ==============================
// ! Scriptability related code !
// ==============================
//
// this method will return the scriptable object (and create it if necessary)
nsScriptablePeer* nsPluginInstance::getScriptablePeer()
{
  if (!mScriptablePeer) {
    mScriptablePeer = new nsScriptablePeer(this);
    if(!mScriptablePeer)
      return NULL;

    NS_ADDREF(mScriptablePeer);
  }

  // add reference for the caller requesting the object
  NS_ADDREF(mScriptablePeer);
  return mScriptablePeer;
}

LRESULT CALLBACK PluginWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

  switch (msg) {
    case WM_PAINT:
      {

        // draw a frame and display the string
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        RECT rc;
        GetClientRect(hWnd, &rc);
        FrameRect(hdc, &rc, GetStockBrush(BLACK_BRUSH));

        // get our plugin instance object and ask it for the version string
        nsPluginInstance *plugin = (nsPluginInstance *)GetWindowLong(hWnd, GWL_USERDATA);
        /*if (plugin)
          DrawText(hdc, plugin->mString, strlen(plugin->mString), &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        else {
          char string[] = "Error occured";
          DrawText(hdc, string, strlen(string), &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        }*/

        EndPaint(hWnd, &ps);
      }
      break;


    default:
      break;
  }

  return DefWindowProc(hWnd, msg, wParam, lParam);
}


