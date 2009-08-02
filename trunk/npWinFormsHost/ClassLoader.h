#pragma once

using namespace System::Windows::Forms;
using namespace System;
using namespace System::Reflection;
using namespace System::IO;

namespace npscriptable
{


ref class ClassLoader
{
public:


	///<summary>
	///Full qualified name of the user control 
	///</summary>
	static void SetMainUserControlName(String^ userControlName);
	static bool LoadAssemblyUrlLocation(String^ assemblyUrlLocation);
	static property System::Windows::Forms::UserControl^ MainUserControl;
	static Int32 ClassLoader::InvokeMember(String^ funcName, String^ parameter);
	static void ClassLoader::SetSizeControl(int sizeX, int sizeY);

    static initonly ClassLoader^ Instance = gcnew ClassLoader;




private:
		
	ClassLoader();
	static property String^ MainUserControlName;
	static property String^ AssemblyUrlLocation;
	static property Assembly^ CurrentAssembly;
	static property Type^ UserControlClass ;
    static property Object^ padlock;

	

};
}
