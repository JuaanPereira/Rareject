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

	public ref class VentanaModulos : public System::Windows::Forms::Form
	{
	public:
		VentanaModulos(void)
		{
			InitializeComponent();
		}
		
		VentanaModulos(DWORD PID, bool injecting)
		{
			InitializeComponent(PID, injecting);
		}
		
	protected:
		~VentanaModulos()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^  listaModulos;
	private: DWORD PID;
	private: String^ ProcessName;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnSalir;
	private: bool dragging;
	private: Point offset;
	public: System::Windows::Forms::Timer^  tmActualizarModulos;
	public: bool injecting;
	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaModulos::typeid));
			this->listaModulos = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->tmActualizarModulos = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// listaModulos
			// 
			this->listaModulos->BackColor = System::Drawing::SystemColors::WindowText;
			this->listaModulos->ForeColor = System::Drawing::Color::Cyan;
			this->listaModulos->FormattingEnabled = true;
			this->listaModulos->Location = System::Drawing::Point(26, 35);
			this->listaModulos->Name = L"listaModulos";
			this->listaModulos->Size = System::Drawing::Size(208, 147);
			this->listaModulos->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Aqua;
			this->label1->Location = System::Drawing::Point(24, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"- Módulos cargados en el proceso:";
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Black;
			this->btnSalir->ForeColor = System::Drawing::Color::Aqua;
			this->btnSalir->Location = System::Drawing::Point(75, 195);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(105, 23);
			this->btnSalir->TabIndex = 2;
			this->btnSalir->Text = L"Finalizar";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &VentanaModulos::btnSalir_Click);
			// 
			// tmActualizarModulos
			// 
			this->tmActualizarModulos->Interval = 3000;
			this->tmActualizarModulos->Tick += gcnew System::EventHandler(this, &VentanaModulos::tmActualizarModulos_Tick);
			// 
			// VentanaModulos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(261, 230);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listaModulos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"VentanaModulos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Módulos del proceso...";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaModulos::VentanaModulos_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaModulos::VentanaModulos_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaModulos::VentanaModulos_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		void InitializeComponent(DWORD PID, bool injecting){
			
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaModulos::typeid));
			this->listaModulos = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->tmActualizarModulos = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// listaModulos
			// 
			this->listaModulos->BackColor = System::Drawing::SystemColors::WindowText;
			this->listaModulos->ForeColor = System::Drawing::Color::Cyan;
			this->listaModulos->FormattingEnabled = true;
			this->listaModulos->Location = System::Drawing::Point(26, 35);
			this->listaModulos->Name = L"listaModulos";
			this->listaModulos->Size = System::Drawing::Size(208, 147);
			this->listaModulos->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Aqua;
			this->label1->Location = System::Drawing::Point(24, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"- Módulos cargados en el proceso:";
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Black;
			this->btnSalir->ForeColor = System::Drawing::Color::Aqua;
			this->btnSalir->Location = System::Drawing::Point(75, 195);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(105, 23);
			this->btnSalir->TabIndex = 2;
			this->btnSalir->Text = L"Finalizar";
			this->btnSalir->UseVisualStyleBackColor = false;
			// 
			// tmActualizarModulos
			// 
			this->tmActualizarModulos->Interval = 3000;
			this->tmActualizarModulos->Tick += gcnew System::EventHandler(this, &VentanaModulos::tmActualizarModulos_Tick);
			//
			// PID
			//
			this->PID = PID;
			//
			// Injecting
			//
			this->injecting = injecting;
			//
			// VentanaModulos
			//
			this->btnSalir->Click += gcnew System::EventHandler(this, &VentanaModulos::btnSalir_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(261, 230);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listaModulos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"VentanaModulos";
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->label1->Text = L"- Módulos cargados en el proceso:";
			this->Text = L"Módulos del proceso...";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaModulos::VentanaModulos_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaModulos::VentanaModulos_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaModulos::VentanaModulos_MouseUp);
			this->ResumeLayout(false);
			this->Load += gcnew System::EventHandler(this, &VentanaModulos::VentanaModulos_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &VentanaModulos::VentanaModulos_FormClosing);
			

			
		}
#pragma endregion
		

		private: System::Void VentanaModulos_Load(System::Object^ sender, System::EventArgs^ e) {
		
			HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->PID); //Creamos snapshot de los módulos del proceso
			MODULEENTRY32* moduleInfo = new MODULEENTRY32;

			moduleInfo->dwSize = sizeof(MODULEENTRY32);

			byte c = 0;
			while (Module32Next(hSnapShot, moduleInfo)) {
				UInt64^ baseAddress = (UInt64)moduleInfo->modBaseAddr;
				String^ moduleName = gcnew String(moduleInfo->szModule);
				String^ module = String::Format("{0:X8} - {1}", baseAddress, moduleName);
				
				if(c > 0) //Evita que se muestre el nombre del propio proceso
					listaModulos->Items->Add(module);

				c++;
			}

			CloseHandle(hSnapShot);

			if(!injecting)
				tmActualizarModulos->Start();
		

		}
	
		private: System::Void VentanaModulos_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			tmActualizarModulos->Stop();
			listaModulos->Items->Clear();

		}

		private: System::Void VentanaModulos_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			this->dragging = false;


		}

		private: System::Void VentanaModulos_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if (this->dragging) {

				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X,
				currentScreenPos.Y - this->offset.Y);

			}
		}

		private: System::Void VentanaModulos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {


			this->dragging = true;
			this->offset = Point(e->X, e->Y);

		}

		private: System::Void btnSalir_Click(System::Object^  sender, System::EventArgs^  e) {

			this->Close();

		}

		private: System::Void tmActualizarModulos_Tick(System::Object^  sender, System::EventArgs^  e) {

			HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->PID); //Creamos snapshot de los módulos del proceso
			MODULEENTRY32* moduleInfo = new MODULEENTRY32;

			moduleInfo->dwSize = sizeof(MODULEENTRY32);

			byte c = 0;
			while (Module32Next(hSnapShot, moduleInfo)) {
				bool exists = false;
				UInt64^ baseAddress = (UInt64)moduleInfo->modBaseAddr;
				String^ moduleName = gcnew String(moduleInfo->szModule);
				String^ module = String::Format("{0:X8} - {1}", baseAddress, moduleName);

				if (c > 0) { //No tiene en cuenta el propio módulo
					for (int i = 0; i < listaModulos->Items->Count; i++) {
						String^ itemLista = listaModulos->Items[i]->ToString();
						if (itemLista->Substring(0, 8) == String::Format("{0:X8}", baseAddress) || itemLista->Substring(0, 12) == String::Format("{0:X12}", baseAddress)) {
							exists = true;
						}
					}

					if (!exists) {

						listaModulos->Items->Add(module);
						listaModulos->TopIndex = listaModulos->Items->Count - 1;

					}
				}
				c++;
			}

			CloseHandle(hSnapShot);

		}
	};
}
