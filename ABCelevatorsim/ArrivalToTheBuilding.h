#ifndef ABCELEVATORSIM_TIME_EVENTS_ARRIVALTOTHEBUILDING_H_
#define ABCELEVATORSIM_TIME_EVENTS_ARRIVALTOTHEBUILDING_H_

#include "Event.h"
#include "EventList.h"
/*
1. Create Customer object
2. Add to the queue_to_elevatore[0]
3. Schedule new ArrivalToTheBuilding
*/
class ArrivalToTheBuilding :
	public Event
{
public:
	virtual void  Execute(EventList* eventlist_ptr, Building* building_ptr, RNG* rng, double start_stats, double stop_time);
	ArrivalToTheBuilding(double time);
	~ArrivalToTheBuilding();

};

#endif