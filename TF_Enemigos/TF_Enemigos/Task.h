#pragma once
#include "Player.h"
using namespace System::Windows::Forms;

class Task
{
	Keys k;
	float timeSpent;
	Player* player;
	bool enabled = true;
public:
	Task(Player* pla, Keys key);
	void doTask(float t);
	~Task();
	bool getEnabled() { return enabled; };
};

