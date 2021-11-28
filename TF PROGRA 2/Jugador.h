#pragma once
#include "Character.h"
#include "Estructura.h"
#include <vector>
using namespace std;


class Jugador : public Character {
private:
	int vacuno;
	int gano;
	int vida;
	int vida2;
	int gano2;
	int indexRec;

public:

	Jugador(int ancho, int alto) : Character(ancho, alto) {
		dx = dy = 5;
		x = 155;
		y = 310;
		vida = 3;
		gano = 1;
		vida2 = 5;
		gano = 1;
		vacuno = 0;
		indexRec = -1;
	}

	~Jugador() {}

	void mover(Graphics^ g, char i, vector<Estructura*> estructura) {
		switch(i)
		{
		case 'A':
			idy = 1;
			for (int i = 0; i < estructura.size(); i++) {
				if (this->getRectangulo(x - dx, y).IntersectsWith(estructura[i]->getRectangulo())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (x > 0 && !this->getRectangulo(x - dx, y).IntersectsWith(estructura[indexRec]->getRectangulo())) {
					x -= dx;
				}
			}
			else {
				if (x > 0) {
					x -= dx;
				}
			}
			break;

		case 'D':
			idy = 2;
			for (int i = 0; i < estructura.size(); i++) {
				if (this->getRectangulo(x + dx, y).IntersectsWith(estructura[i]->getRectangulo())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (x + ancho * 1.0 < g->VisibleClipBounds.Width && !this->getRectangulo(x + dx, y).IntersectsWith(estructura[indexRec]->getRectangulo())) {
					x += dx;
				}
			}
			else {
				if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
					x += dx;
				}
			}
			break;

		case 'W':
			idy = 3;
			for (int i = 0; i < estructura.size(); i++) {
				if (this->getRectangulo(x, y - dy).IntersectsWith(estructura[i]->getRectangulo())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (y > 0 && !this->getRectangulo(x, y - dy).IntersectsWith(estructura[indexRec]->getRectangulo())) {
					y -= dy;
				}
			}
			else {
				if (y > 0) {
					y -= dy;
				}
			}
			break;

		case 'S':
			idy = 0;
			for (int i = 0; i < estructura.size(); i++) {
				if (this->getRectangulo(x, y + dy).IntersectsWith(estructura[i]->getRectangulo())) {
					indexRec = i;
					break;
				}
			}

			if (indexRec != -1) {
				if (y + alto * 1.0 < g->VisibleClipBounds.Height && !this->getRectangulo(x, y + dy).IntersectsWith(estructura[indexRec]->getRectangulo())) {
					y += dy;
				}
			}
			else {
				if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
					y += dy;
				}
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}
	//NIVEL 1
	int getGano() { return gano; }
	void restarGano() { gano--; }

	int getVida() { return vida; }
	void restarVida() { vida--; }

	int getVacuno() { return vacuno; }
	void aumentarVacuno() { vacuno++; }

	//NIVEL 2
	int getGano2() { return gano2; }
	void restarGano2() { gano2--; }

	int getVida2() { return vida2; }
	void restarVida2() { vida2--; }

};