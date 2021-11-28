#pragma once
#include "Character.h"
using namespace System::Drawing;

class Estructura : public Character{
public:
	Estructura(int x, int y, int ancho, int alto) : Character(ancho, alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
	}


	~Estructura() {}


	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::Red, 3);
		g->DrawRectangle(p, x, y, ancho, alto);
	}


};

