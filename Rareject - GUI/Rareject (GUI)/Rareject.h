#pragma once

#include "VentanaProcesos.h"
#include "VentanaOpcionesAvanzadas.h"
#include "VentanaAcercaDe.h"
#include "VentanaModulos.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <cstdio>

namespace RarejectGUI {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;

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
	private: System::Windows::Forms::Button^  btnOpcionesAvanzadas;
	protected:


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtRuta;
	private: System::Windows::Forms::Button^  btnProcesos;
	private: System::Windows::Forms::Button^  btnBuscar;
	private: System::Windows::Forms::TextBox^  txtPID;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnCerrar;
	private: System::Windows::Forms::Button^  btnModulos;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblCloseInject;
	public: System::Windows::Forms::Label^  lblTimerStatus;
	private: System::Windows::Forms::Label^  lblTiempoEspera;
	private: System::Windows::Forms::Button^  btnAcercaDe;
	private: System::Windows::Forms::Button^  btnInyectar;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Timer^  tmInyeccion;
	private: System::ComponentModel::IContainer^  components;
	private: Windows::Forms::DialogResult Result;
	private: bool currentCheckState = false;
	private: bool currentCBTimerState = false;
	private: bool injecting = false;
	private: Point offset;
	private: bool dragging, hubo_carga = false;
	private: HANDLE Proceso;
	private: const char *NOMBRE_DLL;
	private: int Tiempo_Restante, Tiempo_Transcurrido, Tiempo_Rec, currentTBTimerValue;


	void InitializeComponent(void)
			 {
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Rareject::typeid));
		this->btnOpcionesAvanzadas = (gcnew System::Windows::Forms::Button());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->txtRuta = (gcnew System::Windows::Forms::TextBox());
		this->btnProcesos = (gcnew System::Windows::Forms::Button());
		this->btnBuscar = (gcnew System::Windows::Forms::Button());
		this->txtPID = (gcnew System::Windows::Forms::TextBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->btnCerrar = (gcnew System::Windows::Forms::Button());
		this->btnModulos = (gcnew System::Windows::Forms::Button());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->lblCloseInject = (gcnew System::Windows::Forms::Label());
		this->lblTimerStatus = (gcnew System::Windows::Forms::Label());
		this->lblTiempoEspera = (gcnew System::Windows::Forms::Label());
		this->btnAcercaDe = (gcnew System::Windows::Forms::Button());
		this->btnInyectar = (gcnew System::Windows::Forms::Button());
		this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
		this->tmInyeccion = (gcnew System::Windows::Forms::Timer(this->components));
		this->SuspendLayout();
		// 
		// btnOpcionesAvanzadas
		// 
		this->btnOpcionesAvanzadas->BackColor = System::Drawing::Color::Black;
		this->btnOpcionesAvanzadas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->btnOpcionesAvanzadas->ForeColor = System::Drawing::Color::Cyan;
		this->btnOpcionesAvanzadas->Location = System::Drawing::Point(171, 126);
		this->btnOpcionesAvanzadas->Name = L"btnOpcionesAvanzadas";
		this->btnOpcionesAvanzadas->Size = System::Drawing::Size(139, 22);
		this->btnOpcionesAvanzadas->TabIndex = 3;
		this->btnOpcionesAvanzadas->Text = L"Opciones avanzadas...";
		this->btnOpcionesAvanzadas->UseVisualStyleBackColor = false;
		this->btnOpcionesAvanzadas->Click += gcnew System::EventHandler(this, &Rareject::btnOpcionesAvanzadas_Click);
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
		// btnProcesos
		// 
		this->btnProcesos->BackColor = System::Drawing::Color::Black;
		this->btnProcesos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->btnProcesos->ForeColor = System::Drawing::Color::Cyan;
		this->btnProcesos->Location = System::Drawing::Point(15, 189);
		this->btnProcesos->Name = L"btnProcesos";
		this->btnProcesos->Size = System::Drawing::Size(139, 34);
		this->btnProcesos->TabIndex = 7;
		this->btnProcesos->Text = L"Buscar proceso";
		this->btnProcesos->UseVisualStyleBackColor = false;
		this->btnProcesos->Click += gcnew System::EventHandler(this, &Rareject::btnProcesos_Click);
		// 
		// btnBuscar
		// 
		this->btnBuscar->BackColor = System::Drawing::Color::Black;
		this->btnBuscar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->btnBuscar->ForeColor = System::Drawing::Color::Cyan;
		this->btnBuscar->Location = System::Drawing::Point(170, 189);
		this->btnBuscar->Name = L"btnBuscar";
		this->btnBuscar->Size = System::Drawing::Size(139, 33);
		this->btnBuscar->TabIndex = 8;
		this->btnBuscar->Text = L"Buscar DLL";
		this->btnBuscar->UseVisualStyleBackColor = false;
		this->btnBuscar->Click += gcnew System::EventHandler(this, &Rareject::btnBuscar_Click);
		// 
		// txtPID
		// 
		this->txtPID->Enabled = false;
		this->txtPID->Location = System::Drawing::Point(93, 127);
		this->txtPID->Name = L"txtPID";
		this->txtPID->Size = System::Drawing::Size(61, 20);
		this->txtPID->TabIndex = 9;
		this->txtPID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
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
		// btnCerrar
		// 
		this->btnCerrar->BackColor = System::Drawing::Color::Black;
		this->btnCerrar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCerrar.BackgroundImage")));
		this->btnCerrar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->btnCerrar->Location = System::Drawing::Point(15, 325);
		this->btnCerrar->Name = L"btnCerrar";
		this->btnCerrar->Size = System::Drawing::Size(34, 34);
		this->btnCerrar->TabIndex = 14;
		this->btnCerrar->UseVisualStyleBackColor = false;
		this->btnCerrar->Click += gcnew System::EventHandler(this, &Rareject::btnCerrar_Click);
		// 
		// btnModulos
		// 
		this->btnModulos->BackColor = System::Drawing::SystemColors::MenuText;
		this->btnModulos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->btnModulos->Location = System::Drawing::Point(15, 246);
		this->btnModulos->Name = L"btnModulos";
		this->btnModulos->Size = System::Drawing::Size(139, 33);
		this->btnModulos->TabIndex = 13;
		this->btnModulos->Text = L"Ver módulos del proceso";
		this->btnModulos->UseVisualStyleBackColor = false;
		this->btnModulos->Click += gcnew System::EventHandler(this, &Rareject::btnModulos_Click);
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->BackColor = System::Drawing::SystemColors::MenuText;
		this->label2->ForeColor = System::Drawing::Color::Cyan;
		this->label2->Location = System::Drawing::Point(168, 266);
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
		this->lblCloseInject->Location = System::Drawing::Point(253, 266);
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
		this->lblTiempoEspera->Location = System::Drawing::Point(279, 245);
		this->lblTiempoEspera->Name = L"lblTiempoEspera";
		this->lblTiempoEspera->Size = System::Drawing::Size(13, 13);
		this->lblTiempoEspera->TabIndex = 18;
		this->lblTiempoEspera->Text = L"0";
		// 
		// btnAcercaDe
		// 
		this->btnAcercaDe->BackColor = System::Drawing::SystemColors::MenuText;
		this->btnAcercaDe->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAcercaDe.BackgroundImage")));
		this->btnAcercaDe->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
		this->btnAcercaDe->ForeColor = System::Drawing::Color::Cyan;
		this->btnAcercaDe->Location = System::Drawing::Point(55, 325);
		this->btnAcercaDe->Name = L"btnAcercaDe";
		this->btnAcercaDe->Size = System::Drawing::Size(34, 33);
		this->btnAcercaDe->TabIndex = 19;
		this->btnAcercaDe->UseVisualStyleBackColor = false;
		this->btnAcercaDe->Click += gcnew System::EventHandler(this, &Rareject::btnAcercaDe_Click);
		// 
		// btnInyectar
		// 
		this->btnInyectar->BackColor = System::Drawing::Color::Black;
		this->btnInyectar->Location = System::Drawing::Point(174, 325);
		this->btnInyectar->Name = L"btnInyectar";
		this->btnInyectar->Size = System::Drawing::Size(139, 33);
		this->btnInyectar->TabIndex = 20;
		this->btnInyectar->Text = L"Inyectar";
		this->btnInyectar->UseVisualStyleBackColor = false;
		this->btnInyectar->Click += gcnew System::EventHandler(this, &Rareject::btnInyectar_Click);
		// 
		// openFileDialog1
		// 
		this->openFileDialog1->DefaultExt = L"dll";
		this->openFileDialog1->Filter = L"Biblioteca dinámica (*.dll)|*.dll";
		// 
		// tmInyeccion
		// 
		this->tmInyeccion->Interval = 1000;
		this->tmInyeccion->Tick += gcnew System::EventHandler(this, &Rareject::Tick_Increaser);
		// 
		// Rareject
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::MenuHighlight;
		this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		this->ClientSize = System::Drawing::Size(325, 371);
		this->Controls->Add(this->btnInyectar);
		this->Controls->Add(this->btnAcercaDe);
		this->Controls->Add(this->lblTiempoEspera);
		this->Controls->Add(this->lblTimerStatus);
		this->Controls->Add(this->lblCloseInject);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->btnCerrar);
		this->Controls->Add(this->btnModulos);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->txtPID);
		this->Controls->Add(this->btnBuscar);
		this->Controls->Add(this->btnProcesos);
		this->Controls->Add(this->txtRuta);
		this->Controls->Add(this->label5);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->btnOpcionesAvanzadas);
		this->Cursor = System::Windows::Forms::Cursors::Arrow;
		this->ForeColor = System::Drawing::Color::Cyan;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->Name = L"Rareject";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"Rareject";
		this->Load += gcnew System::EventHandler(this, &Rareject::Rareject_Load);
		this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseDown);
		this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseMove);
		this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Rareject::Rareject_MouseUp);
		this->ResumeLayout(false);
		this->PerformLayout();

	}


	VentanaProcesos ^ Vent_Proc;
	VentanaOpcionesAvanzadas ^ Opc_Av;
	VentanaAcercaDe ^ Vent_Acerca;
	VentanaModulos ^ Vent_Modulos;


	private: System::Void Rareject_Load(System::Object^  sender, System::EventArgs^  e) {

		Vent_Proc = gcnew VentanaProcesos(txtPID);

	}

	private: System::Void btnProcesos_Click(System::Object^  sender, System::EventArgs^  e) {

		if (Opc_Av && Opc_Av->cbInjectionTimer->Checked) { //Muestra el valor de retardo en el label asociado al timer si el checkbox está activado

			tmInyeccion->Stop(); //Detiene el timer si se estaba ejecutando
			Tiempo_Transcurrido = 0; //Reinicia el contador del timer
			lblTimerStatus->Text = "- Esperar (segundos):";
			lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;
			lblTiempoEspera->Text = System::Convert::ToString(Opc_Av->Tiempo_Segundos);

		} else { //Reinicia el formato y valor si el checkbox del timer está desactivado

			lblTiempoEspera->Text = "0";

		}
		
		Vent_Proc->ShowDialog();

	}

	private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {

		if (Opc_Av && Opc_Av->cbInjectionTimer->Checked) { //Muestra el valor de retardo en el label asociado al timer si el checkbox está activado

			lblTiempoEspera->Text = System::Convert::ToString(Opc_Av->Tiempo_Segundos);
			tmInyeccion->Stop(); //Detiene el timer si se estaba ejecutando
			Tiempo_Transcurrido = 0; //Reinicia el contador del timer
			lblTimerStatus->Text = "- Esperar (segundos):";
			lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;

	
		}else { //Reinicia el formato y valor si el checkbox del timer está desactivado

			lblTiempoEspera->Text = "0";

		}

		//Muestra la ruta en el label correspondiente si se selecciona un archivo dll
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			txtRuta->Text = openFileDialog1->FileName;

		}

	}

	private: System::Void btnOpcionesAvanzadas_Click(System::Object^  sender, System::EventArgs^  e) {

		const char* Ruta_Archivo = Ruta_Marshalling();

		ifstream Archivo_Conf_Existe(Ruta_Archivo);

		if (!Opc_Av && Archivo_Conf_Existe) {

			Result = MessageBox::Show("¿Cargar la última configuración utilizada?", "Información", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Information);

			if (Result == System::Windows::Forms::DialogResult::Yes) {

				CargarArchivoConf();

				Opciones_Avanzadas();

			}
			else if (Result == System::Windows::Forms::DialogResult::No) {

				Opciones_Avanzadas();

			}

		} else {

			Opciones_Avanzadas();

		}

	}

	private: System::Void btnInyectar_Click(System::Object^  sender, System::EventArgs^  e) {
		//Convertimos las variables a los tipos necesarios a partir de las labels de la interfaz
		marshal_context^ context = gcnew marshal_context();
		DWORD PID = txtPID->Text->Equals("") ? -1 : System::Convert::ToInt32(txtPID->Text);
		NOMBRE_DLL = context->marshal_as<const char*, String>(txtRuta->Text);

		Proceso = OpenProcess(PROCESS_ALL_ACCESS, false, PID);

		if (Proceso && !txtRuta->Text->Equals("") && PID != -1) {
			injecting = true;

			if (Opc_Av && Opc_Av->Tiempo_Segundos > 0) {

				lblTimerStatus->Text = "- Tiempo restante:";

				lblTiempoEspera->ForeColor = System::Drawing::Color::Green;

				Tiempo_Restante = Opc_Av->Tiempo_Segundos;

				if (Vent_Modulos) { //Detiene el timer de la ventana módulos para evitar problemas en la inyección
					Vent_Modulos->tmActualizarModulos->Stop();
				}

				tmInyeccion->Start();


			} else {

				Inyectar();

				CloseOnInject();

			}

		}
		else if (txtRuta->Text->Equals("") && PID == -1) {

			MessageBox::Show("No se han seleccionado la DLL ni el PID del proceso", "Faltan parámetros", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else if (txtRuta->Text->Equals("")) {

			MessageBox::Show("No se ha seleccionado la DLL", "Falta la ruta", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else if (PID == -1) {

			MessageBox::Show("No se ha seleccionado el proceso previamente", "Falta el PID", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}

		/*else {

			Esto ya no sirve para nada, está parcheado.

			MessageBox::Show(("Error en la selección del proceso..."), "Error catastrófico", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}*/

	}

	private: System::Void btnModulos_Click(System::Object^  sender, System::EventArgs^  e) {


		if (Vent_Proc->Proceso_Elegido == false) {

			MessageBox::Show(("No se pueden cargar los módulos ya que no hay proceso seleccionado."), "Selecciona un proceso...", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		}
		else {

			DWORD PID = System::Convert::ToInt32(txtPID->Text);

			Vent_Modulos = gcnew VentanaModulos(PID, injecting);
			Vent_Modulos->ShowDialog();

		}
	}

	private: System::Void btnCerrar_Click(System::Object^  sender, System::EventArgs^  e) {

		GuardarArchivoConf();

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

	private: System::Void Tick_Increaser(System::Object^  sender, System::EventArgs^  e) {

		Tiempo_Transcurrido++;

		lblTiempoEspera->Text = Convert::ToString(Tiempo_Restante - Tiempo_Transcurrido);

		if (Tiempo_Transcurrido == Opc_Av->Tiempo_Segundos) {

			tmInyeccion->Stop();

			Inyectar();

			CloseOnInject();

			lblTiempoEspera->Text = System::Convert::ToString(Tiempo_Rec);
			Tiempo_Transcurrido = 0;
			lblTiempoEspera->ForeColor = Color::Yellow;

			if (Vent_Modulos && Vent_Modulos->Visible)
				Vent_Modulos->tmActualizarModulos->Start();

		}

	}

	private: System::Void Inyectar() {

		LPVOID LoadLibraryAddress = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

		LPVOID ResMemDLL = VirtualAllocEx(Proceso, NULL, strlen(NOMBRE_DLL), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		WriteProcessMemory(Proceso, ResMemDLL, NOMBRE_DLL, strlen(NOMBRE_DLL), NULL);

		HANDLE HiloRemoto = CreateRemoteThread(Proceso, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, ResMemDLL, 0, NULL);

		WaitForSingleObject(HiloRemoto, INFINITE);

		VirtualFreeEx(Proceso, ResMemDLL, strlen(NOMBRE_DLL), MEM_RELEASE);

		CloseHandle(HiloRemoto);
		CloseHandle(Proceso);

		injecting = false;
			
	}

	private: System::Void Opciones_Avanzadas(){

		if (hubo_carga == true) {

			currentTBTimerValue = Tiempo_Rec;

			Tiempo_Rec = NULL;

			hubo_carga = false;

		}
		else {


			if (Opc_Av && Opc_Av->cbInjectionTimer->Checked) {

				currentTBTimerValue = System::Convert::ToInt32(Opc_Av->txtSegundos->Text);

			}
			else {
			
				currentTBTimerValue = System::Convert::ToInt32(lblTiempoEspera->Text);

			}

		}

		if (Opc_Av && Opc_Av->cbInjectionTimer->Checked) { //Se ejecuta sólo si se ha marcado la opción del timer
			tmInyeccion->Stop(); //Detiene el timer si se estaba ejecutando
			lblTimerStatus->Text = "- Esperar (segundos):"; //Restaura el valor del texto al original
			Tiempo_Transcurrido = 0; //Reinicia el contador del timer
			lblTiempoEspera->Text = System::Convert::ToString(Opc_Av->Tiempo_Segundos); //Restaura el tiempo seleccionado a su valor original
			lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow; //Restaura el color al valor original
		}

		Opc_Av = gcnew VentanaOpcionesAvanzadas(currentCheckState, currentCBTimerState, currentTBTimerValue);
		Opc_Av->ShowDialog();

		//Almacena los valores de los checkbox tras cerrar la ventana de opciones avanzadas
		currentCheckState = Opc_Av->currentState;
		currentCBTimerState = Opc_Av->currentCBTimerState;


		if (Opc_Av->cbCloseOnInject->Checked) { //Muestra la palabra ACTIVO en verde si el checkbox de "Cerrar tras inyectar" está activado

			lblCloseInject->Text = "ACTIVO";
			lblCloseInject->ForeColor = System::Drawing::Color::Green;

		}

		else { //Muestra la palabra INACTIVO en amarillo si el checkbox está desactivado

			lblCloseInject->Text = "INACTIVO";
			lblCloseInject->ForeColor = System::Drawing::Color::Yellow;

		}

		if (Opc_Av->cbInjectionTimer->Checked) { //Muestra el valor de retardo en el label asociado al timer si el checkbox está activado

			lblTiempoEspera->Text = System::Convert::ToString(Opc_Av->Tiempo_Segundos);
			lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;
			
		}

		else { //Reinicia el formato y valor si el checkbox del timer está desactivado

			lblTiempoEspera->Text = "0";
			lblTiempoEspera->ForeColor = System::Drawing::Color::Yellow;

		}

	}

	private: System::Void CloseOnInject() {

		if (Opc_Av && Opc_Av->cbCloseOnInject->Checked) {

			GuardarArchivoConf();

			this->Close();
			
		}

	}

	private: System::Void CargarArchivoConf() {

		const char* Ruta_Archivo = Ruta_Marshalling();
		
		ifstream Cargar_Archivo_Conf(Ruta_Archivo);

		string linea, CB_CloseOnInject, CB_InjectionTimer;
		
		getline(Cargar_Archivo_Conf, linea); 
		getline(Cargar_Archivo_Conf, linea); 
		getline(Cargar_Archivo_Conf, linea);
		getline(Cargar_Archivo_Conf, linea);
		getline(Cargar_Archivo_Conf, linea); 
		getline(Cargar_Archivo_Conf, linea);

		CB_CloseOnInject = linea;

		if (CB_CloseOnInject == "ACTIVO") {

			currentCheckState = true;

		}
		else {

			currentCheckState = false;

		}

		getline(Cargar_Archivo_Conf, linea); 
		getline(Cargar_Archivo_Conf, linea);
		getline(Cargar_Archivo_Conf, linea);

		CB_InjectionTimer = linea;

		if (CB_InjectionTimer == "ACTIVO") {

			currentCBTimerState = true;

		}
		else {

			currentCBTimerState = false;

		}

		getline(Cargar_Archivo_Conf, linea);
		getline(Cargar_Archivo_Conf, linea);
		getline(Cargar_Archivo_Conf, linea);

		Tiempo_Rec = stoi(linea);

		hubo_carga = true;

	}

	private: System::Void GuardarArchivoConf() {
		
		ofstream Archivo_Configuracion;

		if(Opc_Av){

			String^ Path = gcnew String(getenv("APPDATA"));

			marshal_context^ context = gcnew marshal_context();

			const char* RUTA = context->marshal_as<const char*, String>(Path + "\\Rareject\\config");

			ifstream Comprobar_Existe(RUTA);
			
			if (Opc_Av->cbCloseOnInject->Checked || Opc_Av->cbInjectionTimer->Checked) {

				CreateDirectory(context->marshal_as<const TCHAR*>(Path + "\\Rareject"), NULL);

				Archivo_Configuracion.open(RUTA);
				
				string CB_CloseOnInject, CB_InjectionTimer, Timer_Value;

				if (currentCheckState == 1) {

					CB_CloseOnInject = "ACTIVO";
				}
				else {

					CB_CloseOnInject = "INACTIVO";

				}

				if (currentCBTimerState == 1) {

					CB_InjectionTimer = "ACTIVO";

				}
				else {

					CB_InjectionTimer = "INACTIVO";

				}

				std::string Delay = context->marshal_as<std::string>(Opc_Av->txtSegundos->Text);

				Archivo_Configuracion << "-------------------------------------------------" << std::endl;
				Archivo_Configuracion << "PARÁMETROS DE CONFIGURACIÓN DE RAREJECT, NO TOCAR" << std::endl; 
				Archivo_Configuracion << "-------------------------------------------------" << std::endl; 
				Archivo_Configuracion << "" << std::endl;
				Archivo_Configuracion << "[Close On Inject]" << std::endl; 
				Archivo_Configuracion << CB_CloseOnInject  << std::endl; 
				Archivo_Configuracion << "" << std::endl;
				Archivo_Configuracion << "[Injection Timer]" << std::endl; 
				Archivo_Configuracion << CB_InjectionTimer << std::endl;
				Archivo_Configuracion << "" << std::endl;
				Archivo_Configuracion << "[Injection Timer - Delay]"<< std::endl;
				Archivo_Configuracion << Delay << std::endl;

				Archivo_Configuracion.close();

			}
			else if(Comprobar_Existe){

				Archivo_Configuracion.close();
				Comprobar_Existe.close();
				
				remove(RUTA);
		
			}

		}
		
	}

	private: const char* Ruta_Marshalling() {

		String^ Path = gcnew String(getenv("APPDATA"));

		marshal_context^ context = gcnew marshal_context();

		const char* RUTA = context->marshal_as<const char*, String>(Path + "\\Rareject\\config");

		return RUTA;
	}
};
}
