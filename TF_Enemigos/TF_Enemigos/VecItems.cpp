#include "VecItems.h"


VecItems::VecItems(int n, int width, int height)
{
	Initialize(n, width, height);
}

VecItems::VecItems(int nA, int nP, int nV, int width, int height)
{
	Items.reserve(nA + nP + nV);
	Objeto* nuevo;
	for (int i = 0; i < nA; i++)
	{
		nuevo = new ObjetoAmmo(width, height);
		Items.emplace_back(nuevo);
	}

	for (int i = 0; i < nP; i++)
	{
		nuevo = new ObjetoPunt(width, height);
		Items.emplace_back(nuevo);
	}

	for (int i = 0; i < nV; i++)
	{
		nuevo = new ObjetoVida(width, height);
		Items.emplace_back(nuevo);
	}
}

void VecItems::Initialize(int n, int width, int height)
{
	Items.reserve(n);
	Objeto* nuevo;
	for (int i = 0; i < n; i++)
	{
		int r = rand() % 3;
		if (r == 0)
			nuevo = new ObjetoAmmo(width, height);
		else if(r == 1)
			nuevo = new ObjetoPunt(width, height);
		else
			nuevo = new ObjetoVida(width, height);
		Items.emplace_back(nuevo);
	}
}

void VecItems::Mostrar(Graphics ^ G, Bitmap ^ bmpA, Bitmap ^ bmpP, Bitmap ^ bmpV)
{
	for each (Objeto* var in Items)
	{
		if (var->getTag() == 10)
			var->Mostrar(G, bmpA);
		else if (var->getTag() == 11)
			var->Mostrar(G, bmpP);
		else if (var->getTag() == 12)
			var->Mostrar(G, bmpV);
	}
}
