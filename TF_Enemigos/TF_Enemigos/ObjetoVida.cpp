#include "ObjetoVida.h"



ObjetoVida::ObjetoVida()
{
}


ObjetoVida::~ObjetoVida()
{
}

void ObjetoVida::Mostrar(Graphics ^ G, Bitmap ^ bmp)
{
	G->DrawImage(bmp, x, y, r, r);
}
