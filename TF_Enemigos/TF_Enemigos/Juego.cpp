#include "Juego.h"



void Juego::Mostrar(Graphics ^ G, Bitmap ^ bg1, Bitmap ^ bmpM, Bitmap ^ bmpS, Bitmap ^ bmpB, Bitmap ^ bmpT, Bitmap ^ bmpPor, Bitmap ^ bmpA, Bitmap ^ bmpP, Bitmap ^ bmpV, Bitmap ^ bmpPlayer, Bitmap ^ bmpPro)
{
	tree->Mostrar(G, bg1, bmpM, bmpS, bmpB, bmpT, bmpPor, bmpA, bmpP, bmpV, bmpPlayer, bmpPro);
}

void Juego::MoverT(Keys k)
{
	Task* nueva = new Task(tree->GetPLayer(), k);
	tasks->newTask(nueva);
}

void Juego::Mover(Keys k)
{
	tree->GetPLayer()->movePlayer(k);
}

void Juego::CheckColisions()
{
	tree->CheckColision();
	tree->CheckProyectiles();
	tree->manage_Tree(tree->GetPLayer()->getPlayerImagen());
}

void Juego::doTasks()
{
	tasks->CheckLive();
	tasks->doTasks(0.2f);
}

void Juego::Lose(Graphics^G, Bitmap^bmp)
{
	if (!tree->getVivo())
	{
		//Funcion Destruir 
		G->Clear(Color::Black);
		G->DrawImage(bmp, Rectangle(0, 0, Form_Width, Form_Height));
		Play = false;
	}
}

bool Juego::getPlay()
{
	return Play;
}

void Juego::CheckProyectiles()
{
	tree->GetPLayer()->CheckPVivos();
}

Juego::Juego()
{
	tree = new Arbol_Escenario();
	tasks = new TaskList();
}



Juego::~Juego()
{
}
