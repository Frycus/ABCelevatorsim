#include "EventList.h"


EventList::EventList()
{
}


EventList::~EventList()
{
}
void EventList::AddEvent(Event* event)
{
	eventlist_.insert(event);
}

Event* EventList::DeleteEvent()
{
	Event* res = *eventlist_.begin();
	eventlist_.erase(res);
	return res;
}

double EventList::FirstEventTime()
{
	return (*eventlist_.begin())->GetExeTime();
}