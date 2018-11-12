#pragma once
#include<vector>
#include "Portal.h"


#define Form_Width 1200 
#define Form_Height 670 

class VectPortales {

	std::vector<Portal*> portales;

public:

	VectPortales(int n);

	void inicializarPortales(int n);

	void Mostrar(Graphics^ G, Bitmap^ bmpPor);

	int ver_Contact_con_Portales(Rectangle UbicacionJugador);
};
