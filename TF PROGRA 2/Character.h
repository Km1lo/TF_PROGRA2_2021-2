#pragma once
#include <iostream>
using namespace System::Drawing;

class Character {
protected:
	int x;
	int y;
	int dx, dy;
	int ancho, alto;
	int idx, idy;
	bool visible;
	bool gano;
public:

	Character(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		idx = idy = 0;
		visible = true;
		gano = true;
	}

	~Character() {}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}


	Rectangle getRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}

	int getX() { return x; }
	int getY() { return y; }
	int getIdy() { return idy; }
	



	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	bool getGano() { return gano; }
	void setGano(bool g) { gano = g; }


	Rectangle getRectangulo(int x, int y) {
		return Rectangle(x, y, ancho, alto);
	}

};