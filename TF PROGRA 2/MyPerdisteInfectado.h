#pragma once

namespace EndOfVirusBeta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyPerdisteInfectado
	/// </summary>
	public ref class MyPerdisteInfectado : public System::Windows::Forms::Form
	{
	public:
		MyPerdisteInfectado(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			musicaPerder = gcnew SoundPlayer("gameover.wav");
		}
	private:
		SoundPlayer^ musicaPerder;
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyPerdisteInfectado()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyPerdisteInfectado::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Harlow Solid Italic", 27.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(423, 520);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 54);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Cerrar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyPerdisteInfectado::button1_Click);
			// 
			// MyPerdisteInfectado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(952, 586);
			this->Controls->Add(this->button1);
			this->Name = L"MyPerdisteInfectado";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyPerdisteInfectado";
			this->Load += gcnew System::EventHandler(this, &MyPerdisteInfectado::MyPerdisteInfectado_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		musicaPerder->Stop();
		this->Close();
	}
	private: System::Void MyPerdisteInfectado_Load(System::Object^ sender, System::EventArgs^ e) {
		musicaPerder->Play();
	}
	};
}
