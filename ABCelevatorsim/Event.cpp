#include "Event.h"


Event::Event(double time)
{
	executionTime = time;
}


Event::~Event()
{
}

void Event::UpdateExeTime(Event* event, double time)
{ 
	event->executionTime = executionTime + time;
}

bool TimeComparator::operator()(const Event* a, const Event* b) const
{
	return a->GetExeTime() < b->GetExeTime();
}