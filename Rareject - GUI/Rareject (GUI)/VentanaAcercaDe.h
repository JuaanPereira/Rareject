#pragma once

namespace RarejectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class VentanaAcercaDe : public System::Windows::Forms::Form
	{
	public:
		VentanaAcercaDe(void)
		{
			InitializeComponent();
			
		}

	protected:
		~VentanaAcercaDe()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::LinkLabel^  linkGitHub;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::ComponentModel::Container ^components;
	private: bool dragging;
	private: System::Windows::Forms::Button^  btnCerrar;
	private: Point offset;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaAcercaDe::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->linkGitHub = (gcnew System::Windows::Forms::LinkLabel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(7, 96);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"- Realizado por:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->ForeColor = System::Drawing::Color::Cyan;
			this->label2->Location = System::Drawing::Point(107, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Juan Pablo Pereira Caro";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Cyan;
			this->label3->Location = System::Drawing::Point(107, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Diego Rodríguez Vicente";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Cyan;
			this->label4->Location = System::Drawing::Point(7, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"- GitHub:";
			// 
			// linkGitHub
			// 
			this->linkGitHub->AutoSize = true;
			this->linkGitHub->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->linkGitHub->Location = System::Drawing::Point(107, 146);
			this->linkGitHub->Name = L"linkGitHub";
			this->linkGitHub->Size = System::Drawing::Size(55, 13);
			this->linkGitHub->TabIndex = 4;
			this->linkGitHub->TabStop = true;
			this->linkGitHub->Text = L"Click aquí";
			this->linkGitHub->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &VentanaAcercaDe::linkGitHub_LinkClicked);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(7, 196);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"- IMPORTANTE:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Cyan;
			this->label6->Location = System::Drawing::Point(107, 196);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(125, 52);
			this->label6->TabIndex = 6;
			this->label6->Text = L"No nos hacemos \r\nresponsables del mal uso\r\nque se le de a nuestra \r\naplicación.";
			// 
			// btnCerrar
			// 
			this->btnCerrar->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnCerrar->ForeColor = System::Drawing::Color::Cyan;
			this->btnCerrar->Location = System::Drawing::Point(10, 261);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(75, 23);
			this->btnCerrar->TabIndex = 7;
			this->btnCerrar->Text = L"Cerrar";
			this->btnCerrar->UseVisualStyleBackColor = false;
			this->btnCerrar->Click += gcnew System::EventHandler(this, &VentanaAcercaDe::btnCerrar_Click);
			// 
			// VentanaAcercaDe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(237, 296);
			this->Controls->Add(this->btnCerrar);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->linkGitHub);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"VentanaAcercaDe";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"VentanaAcercaDe";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaAcercaDe::VentanaAcercaDe_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaAcercaDe::VentanaAcercaDe_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaAcercaDe::VentanaAcercaDe_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void linkGitHub_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {

			System::Diagnostics::Process::Start("https://github.com/JuanPabloPereiraCaro/Rareject");

		}

		private: System::Void VentanaAcercaDe_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			if (this->dragging) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X,
					currentScreenPos.Y - this->offset.Y);
			}

		}

		private: System::Void VentanaAcercaDe_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			this->dragging = false;
		
		}

		private: System::Void VentanaAcercaDe_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		
		}
	
		private: System::Void btnCerrar_Click(System::Object^  sender, System::EventArgs^  e) {

			this->Close();

		}

	};
}
