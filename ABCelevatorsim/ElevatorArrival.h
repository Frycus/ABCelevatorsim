#ifndef ABCELEVATORSIM_TIME_EVENTS_ELEVATORARRIVAL_H_
#define ABCELEVATORSIM_TIME_EVENTS_ELEVATORARRIVAL_H_
//end of the elevator servce
/*
check through the passanger_list if destination_floor==current+elev_floor
remove approperiate customers from the passanger_list
if the current floor!=0
add those customers to the service_desk_queue
else
delete customer
make the elevator busy
get the leaving from the elevator time
//update all exe_times on FEL by the leaving from the elevator time
after that time make it free
*/

#include "event.h"
class ElevatorArrival :
	public Event
{
private:
	Elevator *elevator;
	
public:
	virtual void  Execute(EventList* eventlist_ptr, Building* building_ptr, RNG* rng, double start_stats, double stop_time);

	ElevatorArrival(double time, Elevator *ele_ptr);
	~ElevatorArrival();
};

#endif