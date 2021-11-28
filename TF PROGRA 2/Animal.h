#pragma once
#include "Character.h"

class Animal : public Character {
private:
	int tipo;
public:

	Animal(int ancho, int alto, int tipo) : Character(ancho, alto) {
		this->tipo = tipo;
		x = 300;
		y = 200;

		dx = dy = 5;
	}
	~Animal() {}

	void mover(Graphics^ g) {

		switch (tipo)
		{
		case 0: //Horizontal
			if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0)dx *= -1;
			if (dx > 0) {
				idy = 2;
			}
			else {
				idy = 1;
			}
			x += dx;
			break;
		case 1: //Vertical
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
		if (idx > 2)idx = 0;
	}
};