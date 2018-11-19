#pragma once
#include "Arbol_Escenario.h"
#include "Player.h"
#include "TaskList.h"

class Juego
{
	TaskList* tasks;
	Arbol_Escenario* tree;
	int puntos;
public:
	void Mostrar(Graphics^G, Bitmap^ bg1, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV, Bitmap^bmpPlayer, Bitmap^bmpPro);
	void Mover(Keys k);
	void MoverT(Keys k);
	void CheckColisions();
	void Puntaje(int n);
	void doTasks();
	Juego();
	~Juego();
};

