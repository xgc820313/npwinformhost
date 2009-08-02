#include "stdafx.h"
#include "ClassLoader.h"

using namespace npscriptable;

ClassLoader::ClassLoader()
{
}


void ClassLoader::SetMainUserControlName(String^ userControlName)
{
	MainUserControlName = userControlName;
	UserControlClass = CurrentAssembly->GetType(userControlName);
	MainUserControl = (System::Windows::Forms::UserControl^) Activator::CreateInstance(UserControlClass);
}

bool ClassLoader::LoadAssemblyUrlLocation(String^ assemblyUrlLocation)
{
	AssemblyUrlLocation = assemblyUrlLocation;
	CurrentAssembly = Assembly::LoadFrom(assemblyUrlLocation);
	
	return true;
}



Int32 ClassLoader::InvokeMember(String^ funcName, String^ parameter)
{
	Int32 value = (Int32)UserControlClass->InvokeMember(funcName,
		BindingFlags::InvokeMethod | BindingFlags::Instance | BindingFlags::Public,
		nullptr, MainUserControl, gcnew array<Object^> { parameter });

	return value;
}



void ClassLoader::SetSizeControl(int sizeX, int sizeY)
{
	MainUserControl->Width = sizeX;
	MainUserControl->Height = sizeY;


	
	return;
}

