#pragma once
#include "Objeto.h"
class ObjetoAmmo :
	public Objeto
{
public:
	ObjetoAmmo();
	ObjetoAmmo(int width, int height) : Objeto(width, height)
	{
		tag = 10;
	}
	~ObjetoAmmo();
	void Mostrar(Graphics^ G, Bitmap^ bmp);
};

