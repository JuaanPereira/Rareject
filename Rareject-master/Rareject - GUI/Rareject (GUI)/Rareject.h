#pragma once
#include "VentanaProcesos.h"

namespace RarejectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class Rareject : public System::Windows::Forms::Form
	{

	public:
		Rareject(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Rareject()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnProcesos;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtRuta;

	private: System::Windows::Forms::Button^  btnBuscar;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  txtPID;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Rareject::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnProcesos = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtRuta = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->txtPID = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(165, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Realizado por :";
			this->label1->Click += gcnew System::EventHandler(this, &Rareject::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(144, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Juan Pablo Pereira Caro";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(138, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Diego Rodríguez Vicente";
			// 
			// btnProcesos
			// 
			this->btnProcesos->Location = System::Drawing::Point(326, 102);
			this->btnProcesos->Name = L"btnProcesos";
			this->btnProcesos->Size = System::Drawing::Size(75, 23);
			this->btnProcesos->TabIndex = 3;
			this->btnProcesos->Text = L"Procesos";
			this->btnProcesos->UseVisualStyleBackColor = true;
			this->btnProcesos->Click += gcnew System::EventHandler(this, &Rareject::btnProcesos_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 102);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"PID :";
			this->label4->Click += gcnew System::EventHandler(this, &Rareject::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 143);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Ruta DLL : ";
			// 
			// txtRuta
			// 
			this->txtRuta->Enabled = false;
			this->txtRuta->Location = System::Drawing::Point(80, 140);
			this->txtRuta->Name = L"txtRuta";
			this->txtRuta->Size = System::Drawing::Size(204, 20);
			this->txtRuta->TabIndex = 6;
			this->txtRuta->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtRuta->TextChanged += gcnew System::EventHandler(this, &Rareject::txtRuta_TextChanged);
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(326, 138);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(75, 23);
			this->btnBuscar->TabIndex = 7;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &Rareject::btnBuscar_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"dll";
			this->openFileDialog1->Filter = L"Biblioteca dinámica (*.dll)|*.dll";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Rareject::openFileDialog1_FileOk);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(165, 232);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Inyectar !";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// txtPID
			// 
			this->txtPID->Enabled = false;
			this->txtPID->Location = System::Drawing::Point(80, 102);
			this->txtPID->Name = L"txtPID";
			this->txtPID->Size = System::Drawing::Size(46, 20);
			this->txtPID->TabIndex = 9;
			this->txtPID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtPID->TextChanged += gcnew System::EventHandler(this, &Rareject::textBox1_TextChanged);
			// 
			// Rareject
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 286);
			this->Controls->Add(this->txtPID);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->txtRuta);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnProcesos);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Rareject";
			this->Text = L"Rareject";
			this->Load += gcnew System::EventHandler(this, &Rareject::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		}

		private: System::Void btnProcesos_Click(System::Object^  sender, System::EventArgs^  e) {
			
			/* Se abre la ventana con los procesos activos en el sistema */

			VentanaProcesos ^ Vent_Proc = gcnew VentanaProcesos();
			Vent_Proc->ShowDialog();

		}

		private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				txtRuta->Text = openFileDialog1->FileName;
			}
		}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	}
private: System::Void txtRuta_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {



}
};
}
