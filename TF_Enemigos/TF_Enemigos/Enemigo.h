#pragma once
#include <iostream>

using namespace System::Drawing;

class Enemigo
{
protected:
	int x, y;
	int l;
	int dx, dy;
	int rx, ry;
	int col;
	int pasos;
	bool activo;
	bool vivo;
	int dir;
	int tag;
	int nrow, ncol;
public:
	Enemigo();
	Enemigo(int width, int height);
	~Enemigo();
	virtual void Mostrar(Graphics^ G, Bitmap^ bmp) = 0;
	virtual void Mostrar(Graphics^ G, Bitmap^ bmp, Bitmap^ bmpB) = 0;
	virtual void Mover(Graphics^ G) = 0;
	bool GetVivo();
	void setVivo(bool b);
	int getTag();
	int getX();
	int getY();
	int getL();
};

