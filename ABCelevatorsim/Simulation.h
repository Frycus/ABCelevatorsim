#ifndef ABCELEVATORSIM_SIMULATION_SIMULATION_H_
#define ABCELEVATORSIM_SIMULATION_SIMULATION_H_

#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Event.h"
#include "Building.h"
#include "Customer.h"
#include "EventList.h"
#include "RNG.h"
#include "Kernels.h"

#include "ArrivalToTheBuilding.h"
#include "ServiceAtTheCounter.h"
#include "ElevatorDeparture.h"


class Simulation
{
private:
	double stop_time;
	double current_time;
	double start_statistics;
	double avg_waiting_time;
	double avg_waiting_time_base;
	double avg_queue_length_base;
	double avg_queue_length_other;
	Building* building;
	EventList* eventlist;
	RNG* rng_ptr;
	int customer_counter;

public:
	void Execute();
	Simulation();
	~Simulation() ;
	void ShowStatistics();
	void QueueSizes(Event* closest_event);


};

#endif