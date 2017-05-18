#ifndef ABCELEVATORSIM_SIMULATION_EVENTLIST_H_
#define ABCELEVATORSIM_SIMULATION_EVENTLIST_H_

#include "Event.h">
#include <set>
class EventList
{
public:
	EventList();
	~EventList();
	void AddEvent(Event *ev);
	Event* DeleteEvent();
	double FirstEventTime();
	int GetSize() { return eventlist_.size(); }
private:
	std::multiset<Event*, TimeComparator> eventlist_;
};

#endif
