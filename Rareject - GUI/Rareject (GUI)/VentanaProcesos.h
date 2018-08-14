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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// listaProcesos
			// 
			this->listaProcesos->FormattingEnabled = true;
			this->listaProcesos->Location = System::Drawing::Point(26, 12);
			this->listaProcesos->Name = L"listaProcesos";
			this->listaProcesos->Size = System::Drawing::Size(221, 147);
			this->listaProcesos->TabIndex = 0;
			this->listaProcesos->SelectedIndexChanged += gcnew System::EventHandler(this, &VentanaProcesos::listaProcesos_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(69, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"FINALIZAR";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VentanaProcesos::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(26, 188);
			this->textBox1->Name = L"txtPID_NOMBRE";
			this->textBox1->Size = System::Drawing::Size(221, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &VentanaProcesos::textBox1_TextChanged);
			// 
			// VentanaProcesos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listaProcesos);
			this->Name = L"VentanaProcesos";
			this->Text = L"VentanaProcesos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void listaProcesos_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	
		textBox1->Text = listaProcesos->GetItemText(listaProcesos->SelectedItem);
	
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
