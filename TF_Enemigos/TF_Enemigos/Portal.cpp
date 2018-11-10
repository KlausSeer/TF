#include "Portal.h"

Portal::Portal(int _x, int _y) {
	this->x = _x;
	this->y = _y;
	this->indice = 0;
}

void Portal::Mostrar(Graphics^ G, Bitmap^ bmp) {

	Rectangle areaDibujo(x, y, Portal_Width, Portal_Height);
	Rectangle cut(indice*(bmp->Width/4), 0, bmp->Width / 4, bmp->Height);
	G->DrawImage(bmp, areaDibujo, cut, GraphicsUnit::Pixel);

	this->indice < 3 ? indice += 1 : indice = 0;


}

bool Portal::Contact_Player(Rectangle jugador_AreaDibujo) {
	Rectangle areaDibujo(this->x, this->y, Portal_Width, Portal_Height);

	if (areaDibujo.IntersectsWith(jugador_AreaDibujo)) {
		return true;
	}

	return false;
}
