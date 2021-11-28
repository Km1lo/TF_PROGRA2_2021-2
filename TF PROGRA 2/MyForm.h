#pragma once
//#include "MenuForm.h"
#include "Controlador.h"
#include "MyForm1.h" //FORM          ==       GAMER OVER TE QUEDASTE SIN TIEMPO
#include "MyPerdisteInfectado.h"  //FORM          ==       GAMER OVER TE INFECTASTE
#include "MyVictory.h"  //FORM      ==  GANASTE 
#include <fstream>

namespace EndOfVirusBeta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();

			tiempo = 61;
			isclose = false;

			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap
			bmpJugador = gcnew Bitmap("jugador.png");
			bmpMapa = gcnew Bitmap("mapanivel1tf.png");
			bmpEnemigo = gcnew Bitmap("enemigo.png");
			bmpEnfermera = gcnew Bitmap("enfermera.png");
			bmpAnimal = gcnew Bitmap("buho.png");
			musicnivel1 = gcnew SoundPlayer("musicnivel1.wav");

			controlador = new Controlador(bmpJugador, bmpEnemigo, bmpEnfermera, bmpAnimal);
		}

	private:
		bool isclose;
		//Tiempo
		int tiempo;

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpJugador;
		Bitmap^ bmpMapa;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpEnfermera;
		Bitmap^ bmpAnimal;

		//music
		SoundPlayer^ musicnivel1;


	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblhp;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ tiempoJug;
	private: System::Windows::Forms::Button^ btonCerrar;
	private: System::Windows::Forms::Button^ btonPausa;
	private: System::Windows::Forms::Button^ btonReanudar;




		   //Controller
		   Controlador* controlador;


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{

			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btonCerrar = (gcnew System::Windows::Forms::Button());
			this->btonReanudar = (gcnew System::Windows::Forms::Button());
			this->btonPausa = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblhp = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tiempoJug = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btonCerrar);
			this->panel1->Controls->Add(this->btonReanudar);
			this->panel1->Controls->Add(this->btonPausa);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->lblhp);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(840, 672);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// btonCerrar
			// 
			this->btonCerrar->Location = System::Drawing::Point(720, -1);
			this->btonCerrar->Name = L"btonCerrar";
			this->btonCerrar->Size = System::Drawing::Size(114, 35);
			this->btonCerrar->TabIndex = 3;
			this->btonCerrar->Text = L"Cerrar";
			this->btonCerrar->UseVisualStyleBackColor = true;
			this->btonCerrar->Visible = false;
			this->btonCerrar->Click += gcnew System::EventHandler(this, &MyForm::btonCerrar_Click);
			// 
			// btonReanudar
			// 
			this->btonReanudar->Location = System::Drawing::Point(480, -1);
			this->btonReanudar->Name = L"btonReanudar";
			this->btonReanudar->Size = System::Drawing::Size(114, 35);
			this->btonReanudar->TabIndex = 2;
			this->btonReanudar->Text = L"Reanudar";
			this->btonReanudar->UseVisualStyleBackColor = true;
			this->btonReanudar->Visible = false;
			this->btonReanudar->Click += gcnew System::EventHandler(this, &MyForm::btonReanudar_Click);
			// 
			// btonPausa
			// 
			this->btonPausa->Location = System::Drawing::Point(600, -1);
			this->btonPausa->Name = L"btonPausa";
			this->btonPausa->Size = System::Drawing::Size(114, 36);
			this->btonPausa->TabIndex = 1;
			this->btonPausa->Text = L"Pausa";
			this->btonPausa->UseVisualStyleBackColor = true;
			this->btonPausa->Visible = false;
			this->btonPausa->Click += gcnew System::EventHandler(this, &MyForm::btonPausa_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(172, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Tiempo";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// lblhp
			// 
			this->lblhp->AutoSize = true;
			this->lblhp->Location = System::Drawing::Point(100, 25);
			this->lblhp->Name = L"lblhp";
			this->lblhp->Size = System::Drawing::Size(0, 13);
			this->lblhp->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// tiempoJug
			// 
			this->tiempoJug->Enabled = true;
			this->tiempoJug->Interval = 1000;
			this->tiempoJug->Tick += gcnew System::EventHandler(this, &MyForm::tiempoJug_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 695);
			this->Controls->Add(this->panel1);
			this->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
	
		//MOVIMIENTO JUGADOR
		void MovimientoJugador(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode)
			{
			case Keys::Left:
				controlador->getJugador()->mover(buffer->Graphics, 'A', controlador->getMyRectangles()); break;
			case Keys::Right:
				controlador->getJugador()->mover(buffer->Graphics, 'D', controlador->getMyRectangles()); break;
			case Keys::Up:
				controlador->getJugador()->mover(buffer->Graphics, 'W', controlador->getMyRectangles()); break;
			case Keys::Down:
				controlador->getJugador()->mover(buffer->Graphics, 'S', controlador->getMyRectangles()); break;
			case Keys::Escape:
				
				btonCerrar->Enabled =    true;
				btonPausa->Enabled =     true;
				btonReanudar->Enabled =  true;
				btonCerrar->Visible = true;
				btonPausa->Visible = true;
				btonReanudar->Visible = true;
				
			}
		}

		//TIMER TICK 1 
		void TimerTick1(System::Object^ sender, System::EventArgs^ e) {
			//Clear
			buffer->Graphics->Clear(Color::White);//limpia el lienzo
			//Colision
			controlador->colision();
			//move
			controlador->moverTodo(buffer->Graphics);

			//dibujar
			label1->Text = "Vidas: " + Convert::ToString(controlador->getJugador()->getVida());

			if (controlador->getJugador()->getVida() <= 0) {
				timer1->Enabled = false;
				tiempoJug->Enabled = false;
				musicnivel1->Stop();
				MyPerdisteInfectado^ forminfc = gcnew MyPerdisteInfectado();
				forminfc->ShowDialog();
				this->Close();
				isclose = true;
			}

			if (controlador->getJugador()->getGano() == 0) {
				timer1->Enabled = false;
				tiempoJug->Enabled = false;
				musicnivel1->Stop();
				MyVictory^ formwin = gcnew MyVictory();
				formwin->ShowDialog();
				this->Close();
				isclose = true;
			}

			buffer->Graphics->DrawImage(bmpMapa, 0, 0, panel1->Width, panel1->Height);

			controlador->dibujarTodo(buffer->Graphics, bmpJugador, bmpEnemigo, bmpEnfermera, bmpAnimal);

			//Render
			if (isclose == false) {
				buffer->Render(g);
			}
		}

		//TIMER TICK TIEMPO DEL JUEGO
		void TimerTickJuego(System::Object^ sender, System::EventArgs^ e) {
			tiempo -= 1;
			if (tiempo == 0) {
				timer1->Enabled = false;
				tiempoJug->Enabled = false;
				musicnivel1->Stop();
				MyForm1^ frm2 = gcnew MyForm1();
				frm2->ShowDialog();
				this->Close();

			}

			label2->Text = "Tiempo: " + tiempo;
		}

		//PONER MUSICA
		void MusicaJuego() {
			musicnivel1->PlayLooping();
		}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		TimerTick1(sender, e);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		MovimientoJugador(sender, e); //MOVIMIENTO
	}
    private: System::Void tiempoJug_Tick(System::Object^ sender, System::EventArgs^ e) {
    	TimerTickJuego(sender, e);
    }
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    	MusicaJuego();
    }
    private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
    private: System::Void btonCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Stop();
		tiempoJug->Stop();
		musicnivel1->Stop();
    	this->Close();
    }
    private: System::Void btonPausa_Click(System::Object^ sender, System::EventArgs^ e) {
    	timer1->Stop();
    	tiempoJug->Stop();
    	musicnivel1->Stop();
    }
    private: System::Void btonReanudar_Click(System::Object^ sender, System::EventArgs^ e) {
    	timer1->Start();
    	tiempoJug->Start();
    	musicnivel1->Play();
		btonCerrar->Enabled = false;
		btonPausa->Enabled = false;
		btonReanudar->Enabled = false;
    }

};
}
