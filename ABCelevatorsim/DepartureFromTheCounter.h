#ifndef ABCELEVATORSIM_TIME_EVENTS_DEPARTUREFROMTHECOUNTER_H_
#define ABCELEVATORSIM_TIME_EVENTS_DEPARTUREFROMTHECOUNTER_H_
//end of the servce at the counter

/*

make the desk free
add customer to the queue_to_elevator (from current_customer)

*/
#pragma once
#include "event.h"
class DepartureFromTheCounter :
	public Event
{
private:
	int floor_id;
public:
	DepartureFromTheCounter(double time, int floor);
	~DepartureFromTheCounter();
	virtual void  Execute(EventList* eventlist_ptr, Building* building_ptr, RNG* rng, double start_stats, double stop_time);
};

#endif
// tzs