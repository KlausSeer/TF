#include "Melee.h"



Melee::Melee()
{
}


Melee::~Melee()
{
}

void Melee::Mostrar(Graphics ^ G, Bitmap ^ bmp, Bitmap ^ bmpS)
{
}

void Melee::Mostrar(Graphics ^ G, Bitmap ^ bmp)
{
	Mover(G);
	Rectangle cut(col * bmp->Width/ncol, dir* bmp->Height/nrow, bmp->Width/ncol, bmp->Height/nrow);
	G->DrawImage(bmp, x, y, cut, GraphicsUnit::Pixel);
	col++;
	col %= ncol;
}

void Melee::Mover(Graphics^ G)
{
	if(pasos == 0)
		dir = rand() % 4;
	switch (dir)
	{
	case 0:
		if (y + 5 < G->VisibleClipBounds.Bottom)
			y += 5;
		pasos++;
		pasos %= ry;
		break;
	case 1:
		if (x - 5 > G->VisibleClipBounds.Left)
			x -= 5;
		pasos++;
		pasos %= rx;
		break;
	case 2:
		if (x + 5 < G->VisibleClipBounds.Right)
			x += 5;
		pasos++;
		pasos %= rx;
		break;
	case 3:
		if (y - 5 > G->VisibleClipBounds.Top)
			y -= 5;
		pasos++;
		pasos %= ry;
		break;
	default:
		break;
	}
}
