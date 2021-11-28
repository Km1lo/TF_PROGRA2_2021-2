#pragma once
#include "MyForm.h" //JUEGO NIVEL 1
#include "Nivel2Form.h" //JUEGO NIVEL 2

namespace EndOfVirusBeta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ElegirNivelForm
	/// </summary>
	public ref class ElegirNivelForm : public System::Windows::Forms::Form
	{
	public:
		ElegirNivelForm(void)
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
		~ElegirNivelForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btonNivel1;
	protected:
	private: System::Windows::Forms::Button^ btonNivel2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ElegirNivelForm::typeid));
			this->btonNivel1 = (gcnew System::Windows::Forms::Button());
			this->btonNivel2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btonNivel1
			// 
			this->btonNivel1->BackColor = System::Drawing::Color::Transparent;
			this->btonNivel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btonNivel1.BackgroundImage")));
			this->btonNivel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btonNivel1->FlatAppearance->BorderSize = 0;
			this->btonNivel1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btonNivel1->Font = (gcnew System::Drawing::Font(L"Harlow Solid Italic", 27.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btonNivel1->Location = System::Drawing::Point(430, 294);
			this->btonNivel1->Name = L"btonNivel1";
			this->btonNivel1->Size = System::Drawing::Size(247, 76);
			this->btonNivel1->TabIndex = 1;
			this->btonNivel1->Text = L"Nivel 1";
			this->btonNivel1->UseVisualStyleBackColor = false;
			this->btonNivel1->Click += gcnew System::EventHandler(this, &ElegirNivelForm::btonNivel1_Click);
			// 
			// btonNivel2
			// 
			this->btonNivel2->BackColor = System::Drawing::Color::Transparent;
			this->btonNivel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btonNivel2.BackgroundImage")));
			this->btonNivel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btonNivel2->FlatAppearance->BorderSize = 0;
			this->btonNivel2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btonNivel2->Font = (gcnew System::Drawing::Font(L"Harlow Solid Italic", 27.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btonNivel2->Location = System::Drawing::Point(430, 389);
			this->btonNivel2->Name = L"btonNivel2";
			this->btonNivel2->Size = System::Drawing::Size(247, 76);
			this->btonNivel2->TabIndex = 2;
			this->btonNivel2->Text = L"Nivel 2";
			this->btonNivel2->UseVisualStyleBackColor = false;
			this->btonNivel2->Click += gcnew System::EventHandler(this, &ElegirNivelForm::btonNivel2_Click);
			// 
			// ElegirNivelForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(976, 561);
			this->Controls->Add(this->btonNivel2);
			this->Controls->Add(this->btonNivel1);
			this->Name = L"ElegirNivelForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"v";
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		void BtonNivel1() {
			MyForm^ frmNivel1 = gcnew MyForm();
			frmNivel1->ShowDialog();
			this->Close();
		}
		void BtonNivel2() {
			Nivel2Form^ frmNivel2 = gcnew Nivel2Form();
			frmNivel2->ShowDialog();
			this->Close();
		}
	private: System::Void btonNivel1_Click(System::Object^ sender, System::EventArgs^ e) {
		BtonNivel1();
	}
	private: System::Void btonNivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		BtonNivel2();
	}
	};
}
