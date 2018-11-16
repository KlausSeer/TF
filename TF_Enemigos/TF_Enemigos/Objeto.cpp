#include "Objeto.h"



Objeto::Objeto()
{
}

Objeto::Objeto(int width, int height)
{
	x = rand() % ((7 * width) / 8);
	y = rand() % ((7 * height) / 8);

	r = 40;

	activo = true;
	vivo = true;
}


Objeto::~Objeto()
{
}

int Objeto::getX()
{
	return x;
}

int Objeto::getY()
{
	return y;
}

int Objeto::getR()
{
	return r;
}

short Objeto::getTag()
{
	return tag;
}

bool Objeto::getActivo()
{
	return activo;
}

bool Objeto::getVivo()
{
	return vivo;
}

void Objeto::setActive(bool b)
{
	activo = b;
}

void Objeto::setLive(bool b)
{
	vivo = b;
}
