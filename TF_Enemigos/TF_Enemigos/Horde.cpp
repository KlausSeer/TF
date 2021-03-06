#include "Horde.h"

void Horde::deActive()
{
	for each (Enemigo* var in Enemies)
	{
		for each (Enemigo* var in Enemies)
		{
			var->SetActive(false);
		}
	}
}

Horde::Horde(int n, int width, int height)
{
	Initialize(n, width, height);
}

Horde::Horde(int nM, int nS, int width, int height)
{
	Enemies.reserve(nM + nS + 1);
	Enemigo* nuevo;
	nuevo = new TPEnemy(width, height);
	Enemies.emplace_back(nuevo);
	for (int i = 0; i < nM; i++)
	{
		nuevo = new Melee(width, height);
		Enemies.emplace_back(nuevo);
	}

	for (int i = 0; i < nS; i++)
	{
		nuevo = new Shooter(width, height);
		Enemies.emplace_back(nuevo);
	}
}

void Horde::Initialize(int n, int width, int height)
{
	Enemies.reserve(n + 1);
	Enemigo* nuevo;
	nuevo = new TPEnemy(width, height);
	Enemies.emplace_back(nuevo);
	for (int i = 0; i < n; i++)
	{
		if (rand()% 2 == 0)
			nuevo = new Melee(width, height);
		else
			nuevo = new Shooter(width, height);
		Enemies.emplace_back(nuevo);
	}
}

void Horde::Mostrar(Graphics ^ G, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT)
{
	for each (Enemigo* var in Enemies)
	{
		if (var->getActive())
		{
			if (var->getTag() == 0)
				var->Mostrar(G, bmpM);

			else if (var->getTag() == 1)
				var->Mostrar(G, bmpS, bmpB);

			else if (var->getTag() == 2)
				var->Mostrar(G, bmpT);
			}
		}
}

void Horde::CheckLive()
{
	for each (Shooter* var in Enemies)
	{
		if (var->getTag() == 1)
			var->CheckLive();
	}
}

void Horde::CheckLiveEnemies()
{
	std::vector<Enemigo*>::iterator i = Enemies.begin();
	while (i != Enemies.end())
	{
		if (!(*i)->GetVivo())
		{
			i = Enemies.erase(i);
		}
		else
			++i;
	}
}

std::vector<Enemigo*> Horde::getHorde()
{
	return Enemies;
}

int Horde::GetMele()
{
	int n = 0;
	for each (Enemigo* var in Enemies)
	{
		if (var->getTag() == 0)
			n++;
	}

	return n;
}

int Horde::GetShooter()
{
	int n = 0;
	for each (Enemigo* var in Enemies)
	{
		if (var->getTag() == 1)
			n++;
	}
	return n;
}


Horde::~Horde()
{
}
