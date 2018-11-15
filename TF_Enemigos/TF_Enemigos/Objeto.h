#pragma once
#include <iostream>
using namespace System::Drawing;
class Objeto
{
protected:
	int x, y;
	int r;
	short tag;
	bool activo;
	bool vivo;
public:
	Objeto();
	Objeto(int width, int height);
	~Objeto();
	virtual void Mostrar(Graphics^ G, Bitmap^ bmp) = 0;
	int getX();
	int getY();
	int getR();
	short getTag();
	bool getActivo();
	bool getVivo();
	void setActive(bool b);
	void setLive(bool b);
};
