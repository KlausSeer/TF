#include "ObjetoAmmo.h"



ObjetoAmmo::ObjetoAmmo()
{
}


ObjetoAmmo::~ObjetoAmmo()
{
}

void ObjetoAmmo::Mostrar(Graphics ^ G, Bitmap ^ bmp)
{
	G->DrawImage(bmp, x, y, r, r);
}