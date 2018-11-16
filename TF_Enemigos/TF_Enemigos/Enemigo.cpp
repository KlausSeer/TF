#include "Enemigo.h"



Enemigo::Enemigo()
{
}

Enemigo::Enemigo(int width, int height)
{
	x = rand() % ((7 * width) / 8);
	y = rand() % ((7 *height) / 8);
	rx = rand() % 5 + 10;
	ry = rand() % 5 + 10;

	l = 40;

	dx = 0;
	dy = 5;

	col = 0;

	dir = 0;
	pasos = 0;

	activo = true;
	vivo = true;
}


Enemigo::~Enemigo()
{
}

bool Enemigo::GetVivo()
{
	return vivo;
}

void Enemigo::setVivo(bool b)
{
	vivo = b;
}

int Enemigo::getTag()
{
	return tag;
}

int Enemigo::getX()
{
	return x;
}

int Enemigo::getY()
{
	return y;
}

int Enemigo::getL()
{
	return l;
}

bool Enemigo::getActive()
{
	return activo;
}

void Enemigo::SetActive(bool b)
{
	activo = false;
}

