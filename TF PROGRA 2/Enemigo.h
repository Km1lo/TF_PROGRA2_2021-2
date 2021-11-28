#pragma once
#include "Jugador.h"
#include "Character.h"
#include "Estructura.h"
using namespace std;

class Enemigo : public Character {
private:
	int type;
public:
	Enemigo(int x, int y, int ancho, int alto, int type) : Character(ancho, alto) {
		this->type = type;
		this->x = x;
		this->y = y;
		//dx = dy = 2;
		dx = dy = rand() % 5 + 3;
	}

	~Enemigo() {}

	void mover(Graphics^ g, Jugador* jugador, vector<Estructura*> estructura) {

		switch (type)
		{
		case 0: //PERSEGUIR
			if (x == jugador->getX()) {
				x += 0;
			}
			else if (x > jugador->getX()) {
				x -= dx;
				idy = 1;
			}
			else if (x < jugador->getX()) {
				x += dx;
				idy = 2;
			}
			//en Y
			if (y == jugador->getY()) {
				y += 0;
			}
			else if (y > jugador->getY()) {
				y -= dy;
				idy = 3;
			}
			else if (y < jugador->getY()) {
				y += dy;
				idy = 0;
			}
			break;
		case 1: //Horizontal
			if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0)dx *= -1;
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 1;
			}
			x += dx;
			break;
		case 2: //Vertical
			if (y + alto * 1.0 > g->VisibleClipBounds.Height || y < 0)dy *= -1;
			if (dy > 0) {
				idy = 0;
			}
			else {
				idy = 3;
			}
			y += dy;
			break;
		}
		idx++;
		if (idx > 3)idx = 0;
	}

};