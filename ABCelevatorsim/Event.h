#ifndef ABCELEVATORSIM_TIME_EVENTS_EVENT_H_
#define ABCELEVATORSIM_TIME_EVENTS_EVENT_H_
#include <vector>
#include"Building.h"
#include "Floor.h"
#include "Customer.h"
#include "Service_desk.h"
#include "RNG.h"

class EventList;
using namespace std;

class Event
{
protected:
	double executionTime;
public:

	Event(double);
	~Event();
	double GetExeTime() const { return executionTime; };
	void UpdateExeTime(Event*, double);
	virtual void Execute(EventList* eventlist_ptr, Building* building_ptr, RNG* rng, double start_stats, double stop_time) = 0;

};
class TimeComparator
{
public:
	bool operator()(const Event* a, const Event* b) const;
};
#endif
