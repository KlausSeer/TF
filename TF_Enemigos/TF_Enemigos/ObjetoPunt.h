#pragma once
#include "Objeto.h"
class ObjetoPunt :
	public Objeto
{
public:
	ObjetoPunt();
	ObjetoPunt(int width, int height) : Objeto(width, height)
	{
		tag = 11;
	}
	~ObjetoPunt();
	void Mostrar(Graphics^ G, Bitmap^ bmp);
};

