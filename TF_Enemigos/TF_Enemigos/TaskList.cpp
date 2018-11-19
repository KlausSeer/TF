#include "TaskList.h"



TaskList::TaskList()
{
}


TaskList::~TaskList()
{
}

void TaskList::newTask(Task * nueva)
{
	tasks.push_back(nueva);
}

void TaskList::doTasks(float time)
{
	for each (Task* var in tasks)
	{
		var->doTask(time);
	}
}

void TaskList::CheckLive()
{
	std::list<Task*>::iterator i = tasks.begin();
	while (i != tasks.end())
	{
		if (!(*i)->getEnabled())
		{
			tasks.erase(i++);
		}
		else ++i;
	}
}
