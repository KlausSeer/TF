#pragma once
#include "Arbol_Escenario.h"
#include "Player.h"

class Juego
{
	Arbol_Escenario* tree;
	int puntos;
public:
	void Mostrar(Graphics^G, Bitmap^ bg1, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV, Bitmap^bmpPlayer, Bitmap^bmpPro);
	void Mover(Graphics^G, Bitmap^bmp, Keys k);
	void CheckColisions();
	void Puntaje(int n);
	Juego();
	~Juego();
};

