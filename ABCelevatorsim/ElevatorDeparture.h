#ifndef ABCELEVATORSIM_CONDITIONAL_EVENTS_ELEVATORDEPARTURE_H_
#define ABCELEVATORSIM_CONDITIONAL_EVENTS_ELEVATORDEPARTURE_H_


#include "event.h"
#include "EventList.h"
#include "ElevatorArrival.h"
class ElevatorDeparture/* :
	public Event*/
{
private:
	Elevator *elevator;
	int curr_floor;
public:
	ElevatorDeparture(Elevator *elevator_ptr);
	~ElevatorDeparture();
	inline void ElevatorDepartureUp(Building *build_ptr, EventList *ev_ls);
	void  Execute(EventList * eventlist_ptr, Building* building_ptr, RNG * rng, double start_stats, double stop_time);
};
#endif