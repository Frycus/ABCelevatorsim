#include "Floor.h"


Floor::Floor(int id, int n_of_counters)
{
	tpw_on_arrival = 0.00;
	floor_number = id;
	n_servicedesks = n_of_counters;
	service_desk = new  Service_desk(id);
	sum_waiting_time = 0.00;

}

void Floor::IncSumOfWaitingTime(double time) {
	sum_waiting_time + time;
}
double Floor::GetSumOfWaitingTime() {
	return sum_waiting_time;
}

Floor::~Floor()
{
		delete service_desk;
}
