#pragma once

#include <sstream>
#include <iostream>
#include <Windows.h>
#include <Psapi.h>
#include <Tlhelp32.h>
#include <list>
#include <string>

static int processID;

namespace RarejectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	public ref class VentanaProcesos : public System::Windows::Forms::Form
	{
	public:
		VentanaProcesos(void)
		{
			InitializeComponent();
		}

		VentanaProcesos(TextBox^ pidTextBox)
		{
			InitializeComponent(pidTextBox);
		}
		
	protected:
		~VentanaProcesos()
		{
			if (components)
			{
				delete components;
			}
		}

	public: bool Proceso_Elegido = false;
	private: System::Windows::Forms::ListBox^  listaProcesos;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  txtPID;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^ pidTextBox;
	private: bool dragging;
	private: Point offset;
	private: System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaProcesos::typeid));
			this->listaProcesos = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtPID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			this->listaProcesos->BackColor = System::Drawing::SystemColors::WindowText;
			this->listaProcesos->ForeColor = System::Drawing::Color::Cyan;
			this->listaProcesos->FormattingEnabled = true;
			this->listaProcesos->HorizontalScrollbar = true;
			this->listaProcesos->Location = System::Drawing::Point(26, 22);
			this->listaProcesos->Name = L"listaProcesos";
			this->listaProcesos->Size = System::Drawing::Size(221, 147);
			this->listaProcesos->TabIndex = 0;
			this->listaProcesos->SelectedIndexChanged += gcnew System::EventHandler(this, &VentanaProcesos::listaProcesos_SelectedIndexChanged);
			this->listaProcesos->DoubleClick += gcnew System::EventHandler(this, &VentanaProcesos::btnFinalizar_Click);
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(69, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Finalizar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &VentanaProcesos::btnFinalizar_Click);
			this->txtPID->Enabled = false;
			this->txtPID->Location = System::Drawing::Point(26, 188);
			this->txtPID->Name = L"txtPID";
			this->txtPID->Size = System::Drawing::Size(221, 20);
			this->txtPID->TabIndex = 2;
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(23, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"PID";
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(54, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre del proceso";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(277, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPID);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listaProcesos);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"VentanaProcesos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Procesos activos...";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaProcesos::VentanaProcesos_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaProcesos::VentanaProcesos_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaProcesos::VentanaProcesos_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void InitializeComponent(TextBox^ pidTextBox)
		{

			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaProcesos::typeid));
			this->listaProcesos = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtPID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pidTextBox = pidTextBox;
			this->SuspendLayout();
			// 
			// listaProcesos
			// 
			this->listaProcesos->BackColor = System::Drawing::SystemColors::WindowText;
			this->listaProcesos->ForeColor = System::Drawing::Color::Cyan;
			this->listaProcesos->FormattingEnabled = true;
			this->listaProcesos->HorizontalScrollbar = true;
			this->listaProcesos->HorizontalExtent = 0;
			this->listaProcesos->IntegralHeight = true;
			this->listaProcesos->Location = System::Drawing::Point(26, 22);
			this->listaProcesos->Name = L"listaProcesos";
			this->listaProcesos->Size = System::Drawing::Size(221, 147);
			this->listaProcesos->TabIndex = 0;
			this->listaProcesos->SelectedIndexChanged += gcnew System::EventHandler(this, &VentanaProcesos::listaProcesos_SelectedIndexChanged);
			this->listaProcesos->DoubleClick += gcnew System::EventHandler(this, &VentanaProcesos::btnFinalizar_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(69, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Finalizar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &VentanaProcesos::btnFinalizar_Click);
			// 
			// txtPID
			// 
			this->txtPID->Enabled = false;
			this->txtPID->Location = System::Drawing::Point(26, 188);
			this->txtPID->Name = L"txtPID";
			this->txtPID->Size = System::Drawing::Size(221, 20);
			this->txtPID->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(23, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"PID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(54, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre del proceso";
			// 
			// VentanaProcesos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(277, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtPID);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listaProcesos);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"VentanaProcesos";
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Procesos activos...";
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaProcesos::VentanaProcesos_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaProcesos::VentanaProcesos_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaProcesos::VentanaProcesos_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->Load += gcnew System::EventHandler(this, &VentanaProcesos::VentanaProcesos_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &VentanaProcesos::VentanaProcesos_FormClosing);

		}

		/*public: static int processID;*/

		private: System::Void listaProcesos_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			
			String^ process = listaProcesos->GetItemText(listaProcesos->SelectedItem) == "" ? listaProcesos->GetItemText(listaProcesos->Items[listaProcesos->Items->Count - 1]) : listaProcesos->GetItemText(listaProcesos->SelectedItem); //Asegura de que no se ha elegido un elemento vacío en la lista
			array<String^>^ processinfo = process->Split(' ');	//Separa la información del proceso en varias cadenas de texto
			
			if (processinfo[1]->EndsWith(")")) {	//Modifica la visualización de la información del proceso
				txtPID->Text = processinfo[1]->Substring(1, (processinfo[1]->Length - 2)) + " (" + processinfo[0] + ")";
			} else {
				txtPID->Text = processinfo[1]->Substring(1, (processinfo[1]->Length - 1)) + ".exe (" + processinfo[0] + ")";
			}
			
			processID = System::Convert::ToInt32(processinfo[0]);
				
			Proceso_Elegido = true;

		}

		private: System::Void btnFinalizar_Click(System::Object^  sender, System::EventArgs^  e) {

			pidTextBox->Text = System::Convert::ToString(processID);

			this->Close();

		}

		private: System::Void VentanaProcesos_Load(System::Object^  sender, System::EventArgs^  e) {
			typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL); 
			LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process"); //Recibe la función del kernel que permite saber si un proceso (32 bits) se está ejecutando bajo el subsistema WoW64

			HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //Creamos snapshot de los procesos activos actualmente
			PROCESSENTRY32* processInfo = new PROCESSENTRY32;

			processInfo->dwSize = sizeof(PROCESSENTRY32);
			Process32Next(hSnapShot, processInfo);	//Se salta el primer proceso

			while (Process32Next(hSnapShot, processInfo) != FALSE) {
				typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
				int pid = processInfo->th32ProcessID;

				HANDLE proceso = OpenProcess(PROCESS_QUERY_INFORMATION, false, pid);

				BOOL isWin32 = false;
				String^ name = gcnew String(processInfo->szExeFile);
				String^ processinfo;

				if (fnIsWow64Process(proceso, &isWin32)) {
					if (isWin32)
						processinfo = pid + " (" + name + ")" + " - 32 bits";
					else
						processinfo = pid + " (" + name + ")";
				}

				listaProcesos->Items->Add(processinfo);
			}
			
			updateHorizontalScrollbar();
		}

		private: System::Void VentanaProcesos_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

			listaProcesos->Items->Clear();

		}
	
		private: System::Void VentanaProcesos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
			this->dragging = true;
			this->offset = Point(e->X, e->Y);

		}
		
		private: System::Void VentanaProcesos_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			this->dragging = false;
		
		}
			
		private: System::Void VentanaProcesos_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if (this->dragging) {

				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X,
				currentScreenPos.Y - this->offset.Y);

			}
		}

		private: void updateHorizontalScrollbar() {
			Graphics ^graphics = listaProcesos->CreateGraphics();
			
			int index = 0;
			int stringLength = 0;
			for (int i = 0; i < listaProcesos->Items->Count - 1; i++) {
				if (listaProcesos->Items[i]->ToString()->Length > stringLength) {
					index = i;
					stringLength = listaProcesos->Items[i]->ToString()->Length;
				}
			}

			listaProcesos->HorizontalExtent = (int) graphics->MeasureString(listaProcesos->Items[index]->ToString(), listaProcesos->Font).Width;
		}
	};
}
