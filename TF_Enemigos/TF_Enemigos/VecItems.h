#pragma once
#include <vector>
#include "ObjetoAmmo.h"
#include "ObjetoPunt.h"
#include "ObjetoVida.h"


class VecItems
{
	std::vector<Objeto*>Items;
public:
	VecItems(int n, int width, int height);
	VecItems(int nA, int nP, int nV, int width, int height);
	void Initialize(int n, int width, int height);
	void Mostrar(Graphics^G, Bitmap^bmpA, Bitmap^bmpP, Bitmap^bmpV);
};

