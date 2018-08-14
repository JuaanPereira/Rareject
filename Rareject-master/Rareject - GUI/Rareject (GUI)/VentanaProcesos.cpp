#pragma comment(lib, "psapi.lib")

#include "VentanaProcesos.h"
#include "windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
static int VentanaProcesos(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(%RarejectGUI::VentanaProcesos());

}