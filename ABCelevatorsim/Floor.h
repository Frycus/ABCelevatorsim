#ifndef ABCELEVATORSIM_SYSTEM_OBJECTS_FLOOR_H_
#define ABCELEVATORSIM_SYSTEM_OBJECTS_FLOOR_H_
#include "Service_desk.h"
#include "Customer.h"
#include <vector>


using namespace std;

#pragma once
class Floor
{
private:
	int floor_number;
	int n_servicedesks;
	Service_desk *service_desk;
	double tpw_on_arrival;
	double sum_waiting_time;

	
public:

	

	int GetTpwOnArrival() { return tpw_on_arrival; };
	void SetTpwOnArrival(double time) { tpw_on_arrival = time; };
	Floor(int id, int n_of_counters);
	~Floor(void);
	int GetFloorNumber() { 
		return floor_number; 
	}
	Service_desk* GetPointerToServiceDesk() {
		return service_desk;
	}
	void IncSumOfWaitingTime(double time);
	double GetSumOfWaitingTime();
};

#endif