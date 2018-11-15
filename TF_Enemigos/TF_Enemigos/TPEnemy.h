#pragma once
#include "Melee.h"
class TPEnemy :
	public Melee
{
public:
	TPEnemy();
	TPEnemy(int width, int height) : Melee(width, height)
	{
		tag = 2;
		nrow = 4;
		ncol = 3;
	}
	~TPEnemy();
};
