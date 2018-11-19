#include "Task.h"


Task::Task(Player * pla, Keys key)
{
	player = pla;
	timeSpent = 0.0f;
	k = key;
}

void Task::doTask(float t)
{
	if (timeSpent > t)
	{
		player->movePlayer(k);
		enabled = false;
	}
	else
		timeSpent += 0.1f;
}

Task::~Task()
{
}
