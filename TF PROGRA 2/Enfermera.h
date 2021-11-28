#pragma once
#include "Character.h"

class Enfermera : public Character {
public:
	Enfermera(int ancho, int alto) : Character(ancho, alto) {
		x = 635;
		y = 540;
	}

	~Enfermera(){}
};