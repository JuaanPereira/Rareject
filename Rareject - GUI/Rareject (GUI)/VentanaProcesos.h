#pragma once
#include <sstream>
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <Tlhelp32.h>
#include <list>

namespace RarejectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Resumen de VentanaProcesos
	/// </summary>
	public ref class VentanaProcesos : public System::Windows::Forms::Form
	{
	public:
		VentanaProcesos(void)
		{
			InitializeComponent();

			listaProcesos->Items->Add(String::Format("{0,-6} {1, 30}", "PID", "Nombre")); //Damos formato inicial a la lista

			HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); /*Creamos snapshot de los procesos activos actualmente*/
			PROCESSENTRY32* processInfo = new PROCESSENTRY32;

			processInfo->dwSize = sizeof(PROCESSENTRY32);
			int index = 0;

			while (Process32Next(hSnapShot, processInfo) != FALSE)
			{

				int ID_Proceso = processInfo->th32ProcessID;

				WCHAR* PName = processInfo->szExeFile;
				String^ Nombre = gcnew String(PName);

				listaProcesos->Items->Add(String::Format("{0,-6} {1,30}", ID_Proceso, Nombre));

			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VentanaProcesos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listaProcesos;

	protected:

	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listaProcesos = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listaProcesos
			// 
			this->listaProcesos->FormattingEnabled = true;
			this->listaProcesos->Location = System::Drawing::Point(-1, -1);
			this->listaProcesos->Name = L"listaProcesos";
			this->listaProcesos->Size = System::Drawing::Size(286, 264);
			this->listaProcesos->TabIndex = 0;
			this->listaProcesos->SelectedIndexChanged += gcnew System::EventHandler(this, &VentanaProcesos::listaProcesos_SelectedIndexChanged);
			// 
			// VentanaProcesos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->listaProcesos);
			this->Name = L"VentanaProcesos";
			this->Text = L"VentanaProcesos";
			this->ResumeLayout(false);

		}

	private: System::Void listaProcesos_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	
	
	}

	};
}
