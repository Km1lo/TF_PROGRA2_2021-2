#pragma once
#include "Character.h"

class Vacuna : public Character {
private:
	int direccion;
public:
	Vacuna(int ancho, int alto, int x, int y, int direccion) : Character(ancho, alto) {
		this->x = x;
		this->y = y;
		this->direccion = direccion;
		dx = 20;
		dy = 20;
	}

	~Vacuna() {}


	void dibujarVacuna(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.3, alto * 0.3);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}


	void mover(Graphics^ g) {
		switch (direccion)
		{
		case 0:
			idy = 3;
			if (y + alto * 0.3 <= g->VisibleClipBounds.Height) {
				y += dy; //movere para abajo
			}
			break;
		case 1:
			idy = 1;
			if (x >= 0) {
				x -= dx;
			}
			break;
		case 2: //derecha
			idy = 2;
			if (x + ancho * 0.3 <= g->VisibleClipBounds.Width) {
				x += dx;
			}
			break;
		case 3:
			idy = 0;
			if (y >= 0) {
				y -= dy;
			}
			break;
		}
	}



	Rectangle getRectanguloVacuna() {
		return Rectangle(x, y, ancho * 0.3, alto * 0.3);
	}


	int getDireccion() { return direccion; }

	int getXAncho() { return x + ancho * 0.3; }
	int getYAlto() { return y + alto * 0.3; }

};
