#include "ObjetoPunt.h"



ObjetoPunt::ObjetoPunt()
{
}


ObjetoPunt::~ObjetoPunt()
{
}

void ObjetoPunt::Mostrar(Graphics ^ G, Bitmap ^ bmp)
{
	G->DrawImage(bmp, x, y, r, r);
}
