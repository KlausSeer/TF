#pragma once
#include "Melee.h"
#include "Shooter.h"
#include "TPEnemy.h"
#include <vector>

class Horde
{
	std::vector<Enemigo*> Enemies;
public:
	void deActive();
	Horde(int n, int width, int height);
	Horde(int nM, int nS, int width, int height);
	void Initialize(int n, int width, int height);
	void Mostrar(Graphics^G, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT);
	void CheckLive();
	void CheckLiveEnemies();
	std::vector<Enemigo*>getHorde();
	~Horde();
};

