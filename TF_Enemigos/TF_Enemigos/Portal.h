#pragma once

#define Portal_Width 15
#define Portal_Height 25

using namespace System::Drawing;

class Portal { // los portales no se mueven(posicion fija)

	int x, y; // posicion
	int indice; //para el sprite 0-3 (4 subimagenes)
  
public:
	Portal(int _x, int _y);
	void Mostrar(Graphics^ G, Bitmap^ bmp); // bmp debe ser un sprite
	bool Contact_Player(Rectangle* jugador_AreaDibujo); //El jugador toca el portal

};


