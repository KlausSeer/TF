#pragma once
#include <list>
#include "Task.h"
class TaskList
{
	std::list<Task*>tasks;
public:
	TaskList();
	~TaskList();
	void newTask(Task*nueva);
	void doTasks(float time);
	void CheckLive();
};

