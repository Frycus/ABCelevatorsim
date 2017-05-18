#ifndef ABCELEVATORSIM_CONDITIONAL_EVENTS_SERVICEATTHECOUNTER_H_
#define ABCELEVATORSIM_CONDITIONAL_EVENTS_SERVICEATTHECOUNTER_H_
//beginning of the service at the counter
/*
check if the counter is free and queue_to_counter not empty
remove first person from the queue_to_counter
add that person to service_desk.current_customer
make the desk busy
schedul new departure from the counter at service_completion_time+sim_time
*/

#include "event.h"
#include "DepartureFromTheCounter.h"
#include "EventList.h"

class ServiceAtTheCounter /*:
	public Event*/
{
private: 
	int desk_id;
public:
	ServiceAtTheCounter(int floor);
	~ServiceAtTheCounter();
	void  Execute(EventList * eventlist_ptr, Building* building_ptr, RNG * rng, double start_stats, double stop_time);
};
#endif
