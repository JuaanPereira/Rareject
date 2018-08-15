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



	private: System::Windows::Forms::Button^  btnProcesos;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtRuta;
	private: System::Windows::Forms::Button^  btnBuscar;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Button^  button2;

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
			this->btnProcesos = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtRuta = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnProcesos
			// 
			this->btnProcesos->BackColor = System::Drawing::Color::Black;
			this->btnProcesos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnProcesos.BackgroundImage")));
			this->btnProcesos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnProcesos->ForeColor = System::Drawing::Color::Cyan;
			this->btnProcesos->Location = System::Drawing::Point(30, 206);
			this->btnProcesos->Name = L"btnProcesos";
			this->btnProcesos->Size = System::Drawing::Size(114, 23);
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
			this->label4->Location = System::Drawing::Point(12, 131);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"- PID :";
			this->label4->Click += gcnew System::EventHandler(this, &Rareject::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::MenuText;
			this->label5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label5->ForeColor = System::Drawing::Color::Cyan;
			this->label5->Location = System::Drawing::Point(12, 97);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"- Ruta DLL: ";
			// 
			// txtRuta
			// 
			this->txtRuta->Enabled = false;
			this->txtRuta->Location = System::Drawing::Point(83, 94);
			this->txtRuta->Name = L"txtRuta";
			this->txtRuta->Size = System::Drawing::Size(204, 20);
			this->txtRuta->TabIndex = 6;
			this->txtRuta->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::Color::Black;
			this->btnBuscar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBuscar.BackgroundImage")));
			this->btnBuscar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnBuscar->ForeColor = System::Drawing::Color::Cyan;
			this->btnBuscar->Location = System::Drawing::Point(30, 177);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(114, 23);
			this->btnBuscar->TabIndex = 7;
			this->btnBuscar->Text = L"Buscar DLL";
			this->btnBuscar->UseVisualStyleBackColor = false;
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
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->ForeColor = System::Drawing::Color::Cyan;
			this->button3->Location = System::Drawing::Point(30, 235);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(114, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Inyectar";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Rareject::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(83, 128);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(46, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->ForeColor = System::Drawing::Color::Cyan;
			this->button1->Location = System::Drawing::Point(152, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Asignar proceso buscado";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Rareject::button1_Click);
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
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->BackColor = System::Drawing::SystemColors::MenuText;
			this->linkLabel1->DisabledLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->linkLabel1->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->linkLabel1->Location = System::Drawing::Point(27, 285);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(250, 13);
			this->linkLabel1->TabIndex = 12;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://github.com/JuanPabloPereiraCaro/Rareject";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuText;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(182, 184);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 67);
			this->button2->TabIndex = 13;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Rareject::button2_Click);
			// 
			// Rareject
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(300, 316);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->txtRuta);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnProcesos);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Rareject";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Rareject v 0.1";
			this->Load += gcnew System::EventHandler(this, &Rareject::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion

		VentanaProcesos ^ Vent_Proc;

		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

			Vent_Proc = gcnew VentanaProcesos();

		}

		private: System::Void btnProcesos_Click(System::Object^  sender, System::EventArgs^  e) {
			
			/* Se abre la ventana con los procesos activos en el sistema */

			Vent_Proc->ShowDialog();

		}

		private: System::Void btnBuscar_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		
				txtRuta->Text = openFileDialog1->FileName;
			
			}
		
		}

		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {


		}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	textBox1->Text = System::Convert::ToString(processID);

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Close();

}
};
}
