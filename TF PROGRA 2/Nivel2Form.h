#pragma once
#include "ControladorNivel2.h"
#include "MyForm1.h" //FORM          ==       GAMER OVER TE QUEDASTE SIN TIEMPO
#include "MyPerdisteInfectado.h"  //FORM          ==       GAMER OVER TE INFECTASTE
#include "MyVictory.h"  //FORM      ==  GANASTE 


namespace EndOfVirusBeta {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Nivel2Form
	/// </summary>
	public ref class Nivel2Form : public System::Windows::Forms::Form
	{
	public:
		Nivel2Form(void)
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
			bmpMapa = gcnew Bitmap("mapanivel2.png");
			bmpEnemigo = gcnew Bitmap("enemigo.png");
			bmpAnimal = gcnew Bitmap("buho.png");
			bmpVacuna = gcnew Bitmap("vacunitasprite.png");
			musicnivel1 = gcnew SoundPlayer("musicnivel1.wav");

			controladornivel2 = new ControladorNivel2(bmpJugador, bmpEnemigo, bmpAnimal);
			
		}


	private:
		bool isclose;

		//tiempo
		int tiempo;

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;


		//Bitmap
		Bitmap^ bmpJugador;
		Bitmap^ bmpMapa;
		Bitmap^ bmpEnemigo;
		Bitmap^ bmpVacuna;
		Bitmap^ bmpAnimal;

		//music
		SoundPlayer^ musicnivel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btonPausa;
	private: System::Windows::Forms::Button^ btonReanudar;
	private: System::Windows::Forms::Button^ btonCerrar;

		ControladorNivel2* controladornivel2;


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Nivel2Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timerJuego;
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
			this->btonPausa = (gcnew System::Windows::Forms::Button());
			this->btonReanudar = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btonCerrar);
			this->panel1->Controls->Add(this->btonPausa);
			this->panel1->Controls->Add(this->btonReanudar);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(0, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(840, 672);
			this->panel1->TabIndex = 0;
			// 
			// btonCerrar
			// 
			this->btonCerrar->Location = System::Drawing::Point(734, 0);
			this->btonCerrar->Name = L"btonCerrar";
			this->btonCerrar->Size = System::Drawing::Size(103, 27);
			this->btonCerrar->TabIndex = 8;
			this->btonCerrar->Text = L"Cerrar";
			this->btonCerrar->UseVisualStyleBackColor = true;
			this->btonCerrar->Visible = false;
			this->btonCerrar->Click += gcnew System::EventHandler(this, &Nivel2Form::btonCerrar_Click);
			// 
			// btonPausa
			// 
			this->btonPausa->Location = System::Drawing::Point(625, 0);
			this->btonPausa->Name = L"btonPausa";
			this->btonPausa->Size = System::Drawing::Size(103, 27);
			this->btonPausa->TabIndex = 7;
			this->btonPausa->Text = L"Pausa";
			this->btonPausa->UseVisualStyleBackColor = true;
			this->btonPausa->Visible = false;
			this->btonPausa->Click += gcnew System::EventHandler(this, &Nivel2Form::btonPausa_Click);
			// 
			// btonReanudar
			// 
			this->btonReanudar->Location = System::Drawing::Point(516, 0);
			this->btonReanudar->Name = L"btonReanudar";
			this->btonReanudar->Size = System::Drawing::Size(103, 27);
			this->btonReanudar->TabIndex = 6;
			this->btonReanudar->Text = L"Reanudar";
			this->btonReanudar->UseVisualStyleBackColor = true;
			this->btonReanudar->Visible = false;
			this->btonReanudar->Click += gcnew System::EventHandler(this, &Nivel2Form::btonReanudar_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(279, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(210, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Personas Vacunadas:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(136, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 28);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Tiempo:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Vidas:";
			this->label2->Click += gcnew System::EventHandler(this, &Nivel2Form::label2_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Nivel2Form::timer1_Tick);
			// 
			// timerJuego
			// 
			this->timerJuego->Enabled = true;
			this->timerJuego->Interval = 1000;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &Nivel2Form::timerJuego_Tick);
			// 
			// Nivel2Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 695);
			this->Controls->Add(this->panel1);
			this->Name = L"Nivel2Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Nivel2Form";
			this->Load += gcnew System::EventHandler(this, &Nivel2Form::Nivel2Form_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Nivel2Form::Nivel2Form_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		//TIMER DEL JUEGO
		void TimerTick(System::Object^ sender, System::EventArgs^ e) {
			//Clear
			buffer->Graphics->Clear(Color::White);//limpia el lienzo
			//Colision
			controladornivel2->colision(buffer->Graphics);
			//move
			controladornivel2->moverTodo(buffer->Graphics);
			//dibujar vida
			label2->Text = "Vidas: " + Convert::ToString(controladornivel2->getJugador()->getVida2());

			//dibujar personas vacunadas
			label3->Text = "Personas Vacunadas: " + Convert::ToString(controladornivel2->getJugador()->getVacuno());

			if (controladornivel2->getJugador()->getVida2() <= 0) {
				timer1->Enabled = false;
				timerJuego->Enabled = false; //tiempojuego
				musicnivel1->Stop();
				MyPerdisteInfectado^ forminfc = gcnew MyPerdisteInfectado();
				forminfc->ShowDialog();
				this->Close();
				isclose = true;
			}

			if (controladornivel2->getComprobar()==true) {
				timer1->Enabled = false;
				timerJuego->Enabled = false;
				musicnivel1->Stop();
				MyVictory^ formwin = gcnew MyVictory();
				formwin->ShowDialog();
				this->Close();
				isclose = true;
			}

			buffer->Graphics->DrawImage(bmpMapa, 0, 0, panel1->Width, panel1->Height);

			controladornivel2->dibujarTodo(buffer->Graphics, bmpJugador, bmpEnemigo, bmpAnimal, bmpVacuna);

			//Render
			if (isclose == false) {
				buffer->Render(g);
			}
		}

		//MOVIMIENTO JUGADOR
		void MovimientoJugadorNivel2(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			switch (e->KeyCode)
			{
			case Keys::Left:
				controladornivel2->getJugador()->mover(buffer->Graphics, 'A', controladornivel2->getMyRectangles()); break;
			case Keys::Right:
				controladornivel2->getJugador()->mover(buffer->Graphics, 'D', controladornivel2->getMyRectangles()); break;
			case Keys::Up:
				controladornivel2->getJugador()->mover(buffer->Graphics, 'W', controladornivel2->getMyRectangles()); break;
			case Keys::Down:
				controladornivel2->getJugador()->mover(buffer->Graphics, 'S', controladornivel2->getMyRectangles()); break;
			case Keys::Escape:
				btonCerrar->Enabled = true;
				btonPausa->Enabled = true;
				btonReanudar->Enabled = true;
				btonCerrar->Visible = true;
				btonPausa->Visible = true;
				btonReanudar->Visible = true;
				break;
			case Keys::Space:
				Vacuna* vacuna = new Vacuna(bmpVacuna->Width, bmpVacuna->Height, controladornivel2->getJugador()->getX(),
					controladornivel2->getJugador()->getY(), controladornivel2->getJugador()->getIdy());
				controladornivel2->agregarVacuna(vacuna, bmpVacuna);
				break;

			}
		}

		//TIEMPO DEL JUEGO (CRONOMETRO)
		void CronometroJuego(System::Object^ sender, System::EventArgs^ e) {
			tiempo -= 1;
			if (tiempo == 0) {
				timer1->Enabled = false;
				timerJuego->Enabled = false;
				musicnivel1->Stop();
				MyForm1^ frm2 = gcnew MyForm1();
				frm2->ShowDialog();
				this->Close();
			}
			label1->Text = "Tiempo: " + tiempo;
		}

		//BTON REANUDAR
		void BtonReanudar() {
			timer1->Start();
			timerJuego->Start();
			musicnivel1->Play();
			btonCerrar->Enabled = false;
			btonPausa->Enabled = false;
			btonReanudar->Enabled = false;
		}

		//BTON PAUSA
		void BtonPausa() {
			timer1->Stop();
			timerJuego->Stop();
			musicnivel1->Stop();
		}

		//BTON CERRAR
		void BtonCerrar() {
			timer1->Stop();
			timerJuego->Stop();
			musicnivel1->Stop();
			this->Close();
		}

		//PONER MUSICA
		void MusicaJuegoLevel2() {
			musicnivel1->PlayLooping();
		}


	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		TimerTick(sender, e);
	}
    private: System::Void Nivel2Form_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    	MovimientoJugadorNivel2(sender, e);
    }
    private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		CronometroJuego(sender, e);
	}
    private: System::Void btonReanudar_Click(System::Object^ sender, System::EventArgs^ e) {
		BtonReanudar();
    }
    private: System::Void btonPausa_Click(System::Object^ sender, System::EventArgs^ e) {
		BtonPausa();
    }
    private: System::Void btonCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		BtonCerrar();
    }
private: System::Void Nivel2Form_Load(System::Object^ sender, System::EventArgs^ e) {
	MusicaJuegoLevel2();
}
};
}
