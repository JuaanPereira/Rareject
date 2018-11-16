#pragma once

namespace RarejectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class VentanaOpcionesAvanzadas : public System::Windows::Forms::Form{

	public:
		VentanaOpcionesAvanzadas(void)
		{
			InitializeComponent();
			
		}

		VentanaOpcionesAvanzadas(bool previousState, bool previousCBTimerState, int previousTBTimerValue) {

			InitializeComponent();

			cbCloseOnInject->Checked = previousState;
			cbInjectionTimer->Checked = previousCBTimerState;

			if (previousCBTimerState) {
				tbTime->Value = previousTBTimerValue;
				txtSegundos->Text = System::Convert::ToString(previousTBTimerValue);
				Tiempo_Segundos = previousTBTimerValue;
			} else
				txtSegundos->Text = System::Convert::ToString(0);

		}



	protected:
		~VentanaOpcionesAvanzadas()
		{
			if (components)
			{
				delete components;
			}
		}

	public: bool currentState;
	public: bool currentCBTimerState;
	public: int Tiempo_Segundos;
	private: bool dragging;
	private: Point offset;
	public: System::Windows::Forms::CheckBox^  cbCloseOnInject;
	private: System::Windows::Forms::Button^  btnSalir;
	public: System::Windows::Forms::CheckBox^  cbInjectionTimer;

	private: System::Windows::Forms::TrackBar^  tbTime;
	public: System::Windows::Forms::TextBox^  txtSegundos;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolTip^  ttTimer;



	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VentanaOpcionesAvanzadas::typeid));
			this->cbCloseOnInject = (gcnew System::Windows::Forms::CheckBox());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->cbInjectionTimer = (gcnew System::Windows::Forms::CheckBox());
			this->tbTime = (gcnew System::Windows::Forms::TrackBar());
			this->txtSegundos = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ttTimer = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbTime))->BeginInit();
			this->SuspendLayout();
			// 
			// cbCloseOnInject
			// 
			this->cbCloseOnInject->AutoSize = true;
			this->cbCloseOnInject->ForeColor = System::Drawing::Color::Cyan;
			this->cbCloseOnInject->Location = System::Drawing::Point(12, 35);
			this->cbCloseOnInject->Name = L"cbCloseOnInject";
			this->cbCloseOnInject->Size = System::Drawing::Size(114, 17);
			this->cbCloseOnInject->TabIndex = 0;
			this->cbCloseOnInject->Text = L"Cerrar tras inyectar";
			this->cbCloseOnInject->UseVisualStyleBackColor = true;
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Black;
			this->btnSalir->ForeColor = System::Drawing::Color::Cyan;
			this->btnSalir->Location = System::Drawing::Point(12, 127);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(148, 36);
			this->btnSalir->TabIndex = 1;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &VentanaOpcionesAvanzadas::btnSalir_Click);
			// 
			// cbInjectionTimer
			// 
			this->cbInjectionTimer->AutoSize = true;
			this->cbInjectionTimer->ForeColor = System::Drawing::Color::Cyan;
			this->cbInjectionTimer->Location = System::Drawing::Point(12, 58);
			this->cbInjectionTimer->Name = L"cbInjectionTimer";
			this->cbInjectionTimer->Size = System::Drawing::Size(152, 17);
			this->cbInjectionTimer->TabIndex = 2;
			this->cbInjectionTimer->Text = L"Injection Timer (Segundos)";
			this->cbInjectionTimer->UseVisualStyleBackColor = true;
			this->cbInjectionTimer->CheckedChanged += gcnew System::EventHandler(this, &VentanaOpcionesAvanzadas::cbInjectionTimer_CheckedChanged);
			// 
			// tbTime
			// 
			this->tbTime->Enabled = false;
			this->tbTime->LargeChange = 1;
			this->tbTime->Location = System::Drawing::Point(12, 81);
			this->tbTime->Maximum = 120;
			this->tbTime->Name = L"tbTime";
			this->tbTime->Size = System::Drawing::Size(95, 45);
			this->tbTime->TabIndex = 3;
			this->tbTime->TickFrequency = 30;
			this->tbTime->Scroll += gcnew System::EventHandler(this, &VentanaOpcionesAvanzadas::tbTime_Scroll);
			// 
			// txtSegundos
			// 
			this->txtSegundos->Enabled = false;
			this->txtSegundos->Location = System::Drawing::Point(116, 87);
			this->txtSegundos->Name = L"txtSegundos";
			this->txtSegundos->Size = System::Drawing::Size(40, 20);
			this->txtSegundos->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(15, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"OPCIONES DE INYECCIÓN";
			// 
			// VentanaOpcionesAvanzadas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(172, 175);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtSegundos);
			this->Controls->Add(this->tbTime);
			this->Controls->Add(this->cbInjectionTimer);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->cbCloseOnInject);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"VentanaOpcionesAvanzadas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Opciones Avanzadas";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaOpcionesAvanzadas::VentanaOpcionesAvanzadas_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaOpcionesAvanzadas::VentanaOpcionesAvanzadas_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VentanaOpcionesAvanzadas::VentanaOpcionesAvanzadas_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbTime))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
		private: System::Void btnSalir_Click(System::Object^  sender, System::EventArgs^  e) {

			currentState = cbCloseOnInject->Checked;
			currentCBTimerState = cbInjectionTimer->Checked;

			this->Close();

		}

		private: System::Void tbTime_Scroll(System::Object^  sender, System::EventArgs^  e) {
		
			ttTimer->SetToolTip(tbTime, "Para mover las posiciones de una en una usa las flechas del teclado o AvPag - RePag.");

			txtSegundos->Text = System::Convert::ToString(tbTime->Value);

			Tiempo_Segundos = System::Convert::ToInt16(txtSegundos->Text);

		}

		private: System::Void cbInjectionTimer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		
			if (cbInjectionTimer->Checked) {
			
				tbTime->Enabled = true;


			}
			else if (!cbInjectionTimer->Checked) {
			
				tbTime->Enabled = false;
				Tiempo_Segundos = 0;
			}

		}

		private: System::Void VentanaOpcionesAvanzadas_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			this->dragging = false;

		}

		private: System::Void VentanaOpcionesAvanzadas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			if (this->dragging) {
				Point currentScreenPos = PointToScreen(e->Location);
				Location = Point(currentScreenPos.X - this->offset.X,
					currentScreenPos.Y - this->offset.Y);
			}
		
		}

		private: System::Void VentanaOpcionesAvanzadas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		
			this->dragging = true;
			this->offset = Point(e->X, e->Y);
		
		}

	};
}
