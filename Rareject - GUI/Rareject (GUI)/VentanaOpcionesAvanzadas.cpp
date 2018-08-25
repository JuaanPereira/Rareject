#include "VentanaOpcionesAvanzadas.h"
#include "windows.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
static int VentanaOpcionesAvanzadas(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(%RarejectGUI::VentanaOpcionesAvanzadas());
}