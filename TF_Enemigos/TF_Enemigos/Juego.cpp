#include "Juego.h"



void Juego::Mostrar(Graphics ^ G, Bitmap ^ bg1, Bitmap ^ bmpM, Bitmap ^ bmpS, Bitmap ^ bmpB, Bitmap ^ bmpT, Bitmap ^ bmpPor, Bitmap ^ bmpA, Bitmap ^ bmpP, Bitmap ^ bmpV, Bitmap ^ bmpPlayer, Bitmap ^ bmpPro)
{
	tree->Mostrar(G, bg1, bmpM, bmpS, bmpB, bmpT, bmpPor, bmpA, bmpP, bmpV, bmpPlayer, bmpPro);
}

void Juego::Mover(Graphics ^ G, Bitmap ^ bmp, Keys k)
{
	tree->GetPLayer()->movePlayer(G, bmp, k);
}

void Juego::CheckColisions()
{
	tree->CheckColision();
	tree->manage_Tree(tree->GetPLayer()->getPlayerImagen());
}

void Juego::Puntaje(int n)
{
	puntos += n;
}

Juego::Juego()
{
	tree = new Arbol_Escenario();
}



Juego::~Juego()
{
}
