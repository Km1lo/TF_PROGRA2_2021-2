#pragma once
#include "Jugador.h"
#include "Enemigo.h"
#include "Enfermera.h"
#include "Animal.h"
#include <vector>

#include "Estructura.h"

using namespace std;

class Controlador {
private:

	Jugador* jugador;
	vector<Enemigo*> enemigos;
	vector<Enfermera*> enfermera;
	vector<Animal*> animal;
	vector<Estructura*> estructura;

public:
	Controlador(Bitmap^ bmpJugador, Bitmap^ bmpEnemigo, Bitmap^ bmpEnfermera, Bitmap^ bmpAnimal) {
		//
		//ESTRUCTURA
		//
		//CASA BLANCA
		estructura.push_back(new Estructura(5, 5, 195, 130));
		//CASA DE ABAJO
		estructura.push_back(new Estructura(680, 530, 140, 100));
		estructura.push_back(new Estructura(95, 295, 3, 3));
		estructura.push_back(new Estructura(400, 160, 3, 3));
		estructura.push_back(new Estructura(470, 70, 3, 3));
		estructura.push_back(new Estructura(263, 230, 3, 3));
		estructura.push_back(new Estructura(310, 330, 3, 3));
		estructura.push_back(new Estructura(405, 560, 3, 3));
		estructura.push_back(new Estructura(230, 440, 3, 3));
		estructura.push_back(new Estructura(120, 545, 3, 3));
		estructura.push_back(new Estructura(500, 385, 3, 3));
		estructura.push_back(new Estructura(535, 285, 3, 3));
		estructura.push_back(new Estructura(600, 470, 3, 3));
		estructura.push_back(new Estructura(614, 175, 3, 3));
		estructura.push_back(new Estructura(740, 70, 3, 3));
		estructura.push_back(new Estructura(750, 375, 3, 3));
		estructura.push_back(new Estructura(735, 235, 3, 3));
		//
		estructura.push_back(new Estructura(5, 140, 30, 110));
		//
		estructura.push_back(new Estructura(5, 250, 10, 400));
		estructura.push_back(new Estructura(30, 580, 10, 50));
		estructura.push_back(new Estructura(40, 631, 600, 10));


		//
		//JUGADOR
		//
		jugador = new Jugador(bmpJugador->Width / 4, bmpJugador->Height / 4); //divide en cuatro, xq el sprite es 4x4

		//
		//ANIMAL (ADORNO AVE)
		//
		animal.push_back(new Animal(bmpAnimal->Width / 3, bmpAnimal->Height / 4, 1)); //VERTICAL
		animal.push_back(new Animal(bmpAnimal->Width / 3, bmpAnimal->Height / 4, 0)); //HORIZONTAL

		//
		//ENEMIGOS
		//
		enemigos.push_back(new Enemigo(400,300,bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));  //PERSEGUIR
		enemigos.push_back(new Enemigo(500,400,bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));	//PERSEGUIR
		enemigos.push_back(new Enemigo(150,500,bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));	//PERSEGUIR
		enemigos.push_back(new Enemigo(552,600,bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));	//PERSEGUIR
		enemigos.push_back(new Enemigo(652, 500, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));	//PERSEGUIR
		enemigos.push_back(new Enemigo(352, 600, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));	//PERSEGUIR

		//
		//ENFERMERA
		//
		enfermera.push_back(new Enfermera(bmpEnemigo->Width / 4, bmpEnemigo->Height / 4));
	}



	~Controlador() {}



	void dibujarTodo(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo, Bitmap^ bmpEnfermera, Bitmap^ bmpAnimal) {

		jugador->dibujar(g, bmpJugador);



		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->dibujar(g, bmpEnemigo);
		}

		for (int i = 0; i < enfermera.size(); i++) {
			enfermera[i]->dibujar(g, bmpEnfermera);
		}

		for (int i = 0; i < animal.size(); i++) {
			animal[i]->dibujar(g, bmpAnimal);
		}
	}




	void moverTodo(Graphics^ g) {
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->mover(g, jugador, estructura);
		}
		
		for (int i = 0; i < animal.size(); i++) {
			animal[i]->mover(g);
		}
	}



	void colision() {
		//Verificacion



		// 
		//COLISION CON ENEMIGO
		for (int i = 0; i < enemigos.size(); i++) {
			if (jugador->getRectangulo().IntersectsWith(enemigos[i]->getRectangulo())) {
				jugador->restarVida();
				enemigos[i]->setVisible(false);
			}
		}
		


		//
		//COLISION CON ENFERMERA
		//
		for (int i = 0; i < enfermera.size(); i++) {
			if (jugador->getRectangulo().IntersectsWith(enfermera[i]->getRectangulo())) {
				jugador->restarGano();
				enfermera[i]->setGano(false);
			}
		}



		// 
		//Eliminacion
		//

		for (int i = 0; i < enemigos.size(); i++) {
			if (!enemigos[i]->getVisible()) { //si enemies es False (!)
				enemigos.erase(enemigos.begin() + i);
			}
		}

	}
	
	Jugador* getJugador() { return jugador; }

	vector<Estructura*> getMyRectangles() { return estructura; }
};