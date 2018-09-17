#pragma once

#include <sstream>
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <Tlhelp32.h>
#include <list>
#include <string>

namespace RarejectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de VentanaModulos
	/// </summary>
	public ref class VentanaModulos : public System::Windows::Forms::Form
	{
	public:
		VentanaModulos(void)
		{
			InitializeComponent();
		}
		
		VentanaModulos(DWORD PID)
		{
			InitializeComponent(PID);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~VentanaModulos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^  listaModulos;
			 DWORD PID;
			 String^ ProcessName;
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
			this->listaModulos = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listaModulos
			// 
			this->listaModulos->BackColor = System::Drawing::SystemColors::WindowText;
			this->listaModulos->ForeColor = System::Drawing::Color::Cyan;
			this->listaModulos->FormattingEnabled = true;
			this->listaModulos->Location = System::Drawing::Point(0, 0);
			this->listaModulos->Name = L"listaModulos";
			this->listaModulos->Size = System::Drawing::Size(286, 264);
			this->listaModulos->TabIndex = 0;
			// 
			// VentanaModulos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->listaModulos);
			this->Name = L"VentanaModulos";
			this->Text = L"VentanaModulos";
			this->ResumeLayout(false);

		}
		
		void InitializeComponent(DWORD PID){
			this->listaModulos = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listaModulos
			// 
			this->listaModulos->BackColor = System::Drawing::SystemColors::WindowText;
			this->listaModulos->ForeColor = System::Drawing::Color::Cyan;
			this->listaModulos->FormattingEnabled = true;
			this->listaModulos->Location = System::Drawing::Point(0, 0);
			this->listaModulos->Name = L"listaModulos";
			this->listaModulos->Size = System::Drawing::Size(286, 264);
			this->listaModulos->TabIndex = 0;
			// 
			// VentanaModulos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->listaModulos);
			this->Name = L"VentanaModulos";
			this->Text = L"VentanaModulos";
			this->ResumeLayout(false);
			this->Load += gcnew System::EventHandler(this, &VentanaModulos::VentanaModulos_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &VentanaModulos::VentanaModulos_FormClosing);
			//PID
			this->PID = PID;
			
		}
#pragma endregion
		

		private: System::Void VentanaModulos_Load(System::Object^ sender, System::EventArgs^ e) {
			HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, this->PID); //Creamos snapshot del proceso para poder recibir su nombre
			PROCESSENTRY32* processInfo = new PROCESSENTRY32;

			processInfo->dwSize = sizeof(PROCESSENTRY32);

			if(Process32First(hSnapShot, processInfo))
				this->Text = gcnew String(processInfo->szExeFile);

			
			hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->PID); //Creamos snapshot de los módulos del proceso
			MODULEENTRY32* moduleInfo = new MODULEENTRY32;

			moduleInfo->dwSize = sizeof(MODULEENTRY32);

			byte c = 0;
			while (Module32Next(hSnapShot, moduleInfo)) {
				UInt64^ baseAddress = (UInt64)moduleInfo->modBaseAddr;
				String^ moduleName = gcnew String(moduleInfo->szModule);
				String^ module = String::Format("{0:X8} - {1}", baseAddress, moduleName);
				
				if(c > 0)
					listaModulos->Items->Add(module);

				c++;
			}

		}
	
		private: System::Void VentanaModulos_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			listaModulos->Items->Clear();
		}

	};
}
