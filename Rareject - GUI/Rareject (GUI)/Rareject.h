#pragma once

#include "VentanaProcesos.h"
#include "VentanaOpcionesAvanzadas.h"
#include "VentanaAcercaDe.h"
#include <time.h>
#include <msclr\marshal.h>

namespace RarejectGUI {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class Rareject : public System::Windows::Forms::Form
	{

	public:
		Rareject(void)
		{
			InitializeComponent();
		
		}
	protected:
		~Rareject()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnProcesos;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtRuta;
	private: System::Windows::Forms::Button^  btnBuscar;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: bool currentCheckState = false;
	private: bool currentCBTimerState = false;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: bool dragging;
	private: Point offset;
	private: System::Windows::Forms::Button^  btnOpcionesAvanzadas;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblCloseInject;
	private: System::Windows::Forms::Label^  lblTimerStatus;
	private: System::Windows::Forms::Label^  lblTiempoEspera;
	private: System::Windows::Forms::Button^  btnAcercaDe;


	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Rareject::typeid));
			this->btnProcesos = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtRuta = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnOpcionesAvanzadas = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblCloseInject = (gcnew System::Windows::Forms::Label());
			this->lblTimerStatus = (gcnew System::Windows::Forms::Label());
			this->lblTiempoEspera = (gcnew System::Windows::Forms::Label());
			this->btnAcercaDe = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnProcesos
			// 
			this->btnProcesos->BackColor = System::Drawing::Color::Black;
			this->btnProcesos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnProcesos->ForeColor = System::Drawing::Color::Cyan;
			this->btnProcesos->Location = System::Drawing::Point(15, 173);
			this->btnProcesos->Name = L"btnProcesos";
			this->btnProcesos->Size = System::Drawing::Size(139, 34);
			this->btnProcesos->TabIndex = 3;
			this->btnProcesos->Text = L"Buscar proceso";
			this->btnProcesos->UseVisualStyleBackColor = false;
			this->btnProcesos->Click += gcnew System::EventHandler(this, &Rareject::btnProcesos_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::MenuText;
			this->label4->ForeColor = System::Drawing::Color::Cyan;
			this->label4->Location = System::Drawing::Point(12, 130);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"- PID :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::MenuText;
			this->label5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label5->ForeColor = System::Drawing::Color::Cyan;
			this->label5->Location = System::Drawing::Point(12, 100);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"- Ruta DLL: ";
			// 
			// txtRuta
			// 
			this->txtRuta->Enabled = false;
			this->txtRuta->Location = System::Drawing::Point(93, 97);
			this->txtRuta->Name = L"txtRuta";
			this->txtRuta->Size = System::Drawing::Size(216, 20);
			this->txtRuta->TabIndex = 6;
			this->txtRuta->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::Color::Black;
			this->btnBuscar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBuscar->ForeColor = System::Drawing::Color::Cyan;
			this->btnBuscar->Location = System::Drawing::Point(171, 173);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(139, 34);
			this->btnBuscar->TabIndex = 7;
			this->btnBuscar->Text = L"Buscar DLL";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &Rareject::btnBuscar_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->ForeColor = System::Drawing::Color::Cyan;
			this->button3->Location = System::Drawing::Point(15, 224);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 34);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Inyectar";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Rareject::btnInyectar_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(93, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(61, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::MenuText;
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(12, 285);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 11;
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"dll";
			this->openFileDialog1->Filter = L"Biblioteca dinámica (*.dll)|*.dll";
			// 
			// btnOpcionesAvanzadas
			// 
			this->btnOpcionesAvanzadas->BackColor = System::Drawing::Color::Black;
			this->btnOpcionesAvanzadas->Location = System::Drawing::Point(171, 125);
			this->btnOpcionesAvanzadas->Name = L"btnOpcionesAvanzadas";
			this->btnOpcionesAvanzadas->Size = System::Drawing::Size(138, 22);
			this->btnOpcionesAvanzadas->TabIndex = 14;
			this->btnOpcionesAvanzadas->Text = L"Opciones avanzadas...";
			this->btnOpcionesAvanzadas->UseVisualStyleBackColor = false;
			this->btnOpcionesAvanzadas->Click += gcnew System::EventHandler(this, &Rareject::btnOpcionesAvanzadas_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuText;
			this->button1->Location = System::Drawing::Point(15, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 34);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Cerrar Rareject";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Rareject::btnCerrar_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::MenuText;
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(168, 224);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 15;
			this->label2->Text = L"- Close on Inject:";
			// 
			// lblCloseInject
			// 
			this->lblCloseInject->AutoSize = true;
			this->lblCloseInject->BackColor = System::Drawing::SystemColors::MenuText;
			this->lblCloseInject->ForeColor = System::Drawing::Color::Yellow;
			this->lblCloseInject->Location = System::Drawing::Point(260, 224);
			this->lblCloseInject->Name = L"lblCloseInject";
			this->lblCloseInject->Size = System::Drawing::Size(57, 13);
			this->lblCloseInject->TabIndex = 16;
			this->lblCloseInject->Text = L"INACTIVO";
			// 
			// lblTimerStatus
			// 
			this->lblTimerStatus->AutoSize = true;
			this->lblTimerStatus->BackColor = System::Drawing::SystemColors::MenuText;
			this->lblTimerStatus->ForeColor = System::Drawing::Color::Cyan;
			this->lblTimerStatus->Location = System::Drawing::Point(168, 245);
			this->lblTimerStatus->Name = L"lblTimerStatus";
			this->lblTimerStatus->Size = System::Drawing::Size(107, 13);
			this->lblTimerStatus->TabIndex = 17;
			this->lblTimerStatus->Text = L"- Esperar (segundos):";
			// 
			// lblTiempoEspera
			// 
			this->lblTiempoEspera->AutoSize = true;
			this->lblTiempoEspera->BackColor = System::Drawing::SystemColors::MenuText;
			this->lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;
			this->lblTiempoEspera->Location = System::Drawing::Point(281, 245);
			this->lblTiempoEspera->Name = L"lblTiempoEspera";
			this->lblTiempoEspera->Size = System::Drawing::Size(13, 13);
			this->lblTiempoEspera->TabIndex = 18;
			this->lblTiempoEspera->Text = L"0";
			// 
			// btnAcercaDe
			// 
			this->btnAcercaDe->BackColor = System::Drawing::SystemColors::MenuText;
			this->btnAcercaDe->ForeColor = System::Drawing::Color::Cyan;
			this->btnAcercaDe->Location = System::Drawing::Point(171, 306);
			this->btnAcercaDe->Name = L"btnAcercaDe";
			this->btnAcercaDe->Size = System::Drawing::Size(139, 34);
			this->btnAcercaDe->TabIndex = 19;
			this->btnAcercaDe->Text = L"Acerca de...";
			this->btnAcercaDe->UseVisualStyleBackColor = false;
			this->btnAcercaDe->Click += gcnew System::EventHandler(this, &Rareject::btnAcercaDe_Click);
			// 
			// Rareject
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(321, 356);
			this->Controls->Add(this->btnAcercaDe);
			this->Controls->Add(this->lblTiempoEspera);
			this->Controls->Add(this->lblTimerStatus);
			this->Controls->Add(this->lblCloseInject);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnOpcionesAvanzadas);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->txtRuta);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnProcesos);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ForeColor = System::Drawing::Color::Cyan;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Rareject";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rareject v 0.1";
			this->Load += gcnew System::EventHandler(this, &Rareject::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion

		VentanaProcesos ^ Vent_Proc;
		VentanaOpcionesAvanzadas ^ Opc_Av;
		VentanaAcercaDe ^ Vent_Acerca;

		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

			Vent_Proc = gcnew VentanaProcesos(textBox1);

		}

		private: System::Void btnProcesos_Click(System::Object^  sender, System::EventArgs^  e) {
			
			Vent_Proc->ShowDialog();

		}

		private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		
				txtRuta->Text = openFileDialog1->FileName;
			
			}
		
		}

		private: System::Void btnOpcionesAvanzadas_Click(System::Object^  sender, System::EventArgs^  e) {

			Opc_Av = gcnew VentanaOpcionesAvanzadas(currentCheckState, currentCBTimerState);
			Opc_Av->ShowDialog();

			currentCheckState = Opc_Av->currentState;
			currentCBTimerState = Opc_Av->currentCBTimerState;

			if (Opc_Av->cbCloseOnInject->Checked) {

				lblCloseInject->Text = "ACTIVO";
				lblCloseInject->ForeColor = System::Drawing::Color::Green;


			}else if (!Opc_Av->cbCloseOnInject->Checked) {
			
				lblCloseInject->Text = "INACTIVO";
				lblCloseInject->ForeColor = System::Drawing::Color::Yellow;


			}

			if (Opc_Av->cbInjectionTimer->Checked) {

				lblTiempoEspera->Text = System::Convert::ToString(Opc_Av->Tiempo_Segundos);
				lblTiempoEspera->ForeColor = System::Drawing::Color::Green;

				if (lblTiempoEspera->Text == "0") {

					lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;

				}

			}

		}

		private: System::Void btnInyectar_Click(System::Object^  sender, System::EventArgs^  e) {

			marshal_context^ context = gcnew marshal_context();

			DWORD PID = System::Convert::ToInt32(textBox1->Text);
			const char *NOMBRE_DLL = context->marshal_as<const char*, String>(txtRuta->Text);

		
			HANDLE Proceso = OpenProcess(PROCESS_ALL_ACCESS, false, PID); 

			if (Proceso) {

				if (Opc_Av->Tiempo_Segundos > 0) {

					int Tiempo_Milisegundos = Opc_Av->Tiempo_Segundos * 1000;

					Sleep(Tiempo_Milisegundos);
				}
	
				LPVOID LoadLibraryAddress = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

				LPVOID ResMemDLL = VirtualAllocEx(Proceso, NULL, strlen(NOMBRE_DLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

				WriteProcessMemory(Proceso, ResMemDLL, NOMBRE_DLL, strlen(NOMBRE_DLL), NULL);

				HANDLE HiloRemoto = CreateRemoteThread(Proceso, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, ResMemDLL, 0, NULL);

				WaitForSingleObject(HiloRemoto, INFINITE);

				VirtualFreeEx(Proceso, ResMemDLL, strlen(NOMBRE_DLL), MEM_RELEASE);

				CloseHandle(HiloRemoto);
				CloseHandle(Proceso);

				if (Opc_Av->cbCloseOnInject->Checked) {

					this->Close();

				}

			} else {
			
				/* Ventanita de error ya que en este caso no habría ningún proceso existente. (En nuestro caso no hace 
				falta, ya que gracias a la opción de escoger un proceso de la lista de procesos, siempre escogeremos un
				proceso existente)*/

			}

		}
		
		private: System::Void btnCerrar_Click(System::Object^  sender, System::EventArgs^  e) {

			this->Close();

		}

		private: System::Void Rareject_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			this->dragging = true;
			this->offset = Point(e->X, e->Y);


		}

		private: System::Void Rareject_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if (this->dragging) { 
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X,
				currentScreenPos.Y - this->offset.Y);
				}

		}

		private: System::Void Rareject_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			this->dragging = false; 

		}
		
		private: System::Void btnAcercaDe_Click(System::Object^  sender, System::EventArgs^  e) {

			Vent_Acerca = gcnew VentanaAcercaDe();

			Vent_Acerca->ShowDialog();

		}

	};
}
