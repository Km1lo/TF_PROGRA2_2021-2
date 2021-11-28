#pragma once
#include <vector>
#include "Animal.h"
#include "Enemigo.h"
#include "Jugador.h"
#include "Vacuna.h"


using namespace std;
class ControladorNivel2 {
private:
	Jugador* jugador;
	vector<Vacuna*> vacuna;
	vector<Enemigo*> enemigos;
	vector<Animal*> animal;
	vector<Estructura*> estructura;
	bool comprobar;
public:
	ControladorNivel2(Bitmap^ bmpJugador, Bitmap^ bmpEnemigo, Bitmap^ bmpAnimal) {
		comprobar = false;
		//
	    //ESTRUCTURA

		estructura.push_back(new Estructura(5, 5, 230, 300));
		//falta estructura
		estructura.push_back(new Estructura(390, 5, 500, 300));
		estructura.push_back(new Estructura(5, 650, 800, 10));

		//
		//JUGADOR
		//
		jugador = new Jugador(bmpJugador->Width / 4, bmpJugador->Height / 4);

		//
		//ANIMAL (ADORNO AVE)
		//
		animal.push_back(new Animal(bmpAnimal->Width / 3, bmpAnimal->Height / 4, 1)); //VERTICAL
		animal.push_back(new Animal(bmpAnimal->Width / 3, bmpAnimal->Height / 4, 0)); //HORIZONTAL

		//
        //ENEMIGOS
        //
		enemigos.push_back(new Enemigo(100, 550, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(240, 400, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 2));
		enemigos.push_back(new Enemigo(260, 200, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 2));
		enemigos.push_back(new Enemigo(250, 600, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 2));
		enemigos.push_back(new Enemigo(652, 450, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));
		enemigos.push_back(new Enemigo(352, 500, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(400, 500, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(300, 100, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 2));
		enemigos.push_back(new Enemigo(250, 450, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(600, 400, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));
		enemigos.push_back(new Enemigo(450, 500, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(750, 550, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 1));
		enemigos.push_back(new Enemigo(700, 530, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));
		enemigos.push_back(new Enemigo(600, 450, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));
		enemigos.push_back(new Enemigo(450, 350, bmpEnemigo->Width / 4, bmpEnemigo->Height / 4, 0));
	}

	~ControladorNivel2(){}


	void agregarVacuna(Vacuna* vacunita, Bitmap^ bmpVacuna) {
		vacuna.push_back(new Vacuna(bmpVacuna->Width, bmpVacuna->Height/4, getJugador()->getX(), 
			getJugador()->getY(), vacunita->getDireccion()));
	}


	void dibujarTodo(Graphics^ g, Bitmap^ bmpJugador, Bitmap^ bmpEnemigo, Bitmap^ bmpAnimal, Bitmap^ bmpVacuna) {

		jugador->dibujar(g, bmpJugador);


		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->dibujar(g, bmpEnemigo);
		}

		for (int i = 0; i < animal.size(); i++) {
			animal[i]->dibujar(g, bmpAnimal);
		}

		for (int i = 0; i < vacuna.size(); i++) {
			vacuna[i]->dibujarVacuna(g, bmpVacuna);
		}

	}


	void moverTodo(Graphics^ g) {
		for (int i = 0; i < enemigos.size(); i++) {
			enemigos[i]->mover(g, jugador, estructura);
		}

		for (int i = 0; i < animal.size(); i++) {
			animal[i]->mover(g);
		}
		
		for (int i = 0; i < vacuna.size(); i++) {
			vacuna[i]->mover(g);
		}
	}

	void colision(Graphics^ g) {
		//Verificacion

		// 
		//COLISION CON ENEMIGO
		for (int i = 0; i < enemigos.size(); i++) {
			if (jugador->getRectangulo().IntersectsWith(enemigos[i]->getRectangulo())) {
				jugador->restarVida2();
				enemigos[i]->setVisible(false);
			}
		}

		for (int i = 0; i < vacuna.size(); i++) {
			if (vacuna[i]->getX() <= 0 || vacuna[i]->getXAncho() >= g->VisibleClipBounds.Width ||
				vacuna[i]->getY() <= 0 || vacuna[i]->getYAlto() >= g->VisibleClipBounds.Height) {
				vacuna[i]->setVisible(false);
			}
		}


		for (int i = 0; i < enemigos.size(); i++) {
			for (int j = 0; j < vacuna.size(); j++) {
				if (enemigos[i]->getRectangulo().IntersectsWith(vacuna[j]->getRectanguloVacuna())) {
					enemigos[i]->setVisible(false);
					vacuna[j]->setVisible(false);
					jugador->aumentarVacuno();
				}
			}
		}

		if (enemigos.size() == 0) {
			comprobar = true;
		}


		// 
		//Eliminacion
		//

		for (int i = 0; i < enemigos.size(); i++) {
			if (!enemigos[i]->getVisible()) { //si enemies es False (!)
				enemigos.erase(enemigos.begin() + i);
			}
		}


		for (int i = 0; i < vacuna.size(); i++) {
			if (!vacuna[i]->getVisible()) {
				vacuna.erase(vacuna.begin() + i);
			}
		}

	}

	Jugador* getJugador() { return jugador; }

	vector<Estructura*> getMyRectangles() { return estructura; }
	bool getComprobar() { return comprobar; }
};