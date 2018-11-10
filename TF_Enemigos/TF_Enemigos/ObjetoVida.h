#pragma once
#include "Objeto.h"
class ObjetoVida :
	public Objeto
{
public:
	ObjetoVida();
	ObjetoVida(int width, int height) : Objeto(width, height)
	{
		tag = 12;
	}
	~ObjetoVida();
	void Mostrar(Graphics^ G, Bitmap^ bmp);
};

