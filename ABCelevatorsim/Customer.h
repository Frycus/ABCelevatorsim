#ifndef ABCELEVATORSIM_SYSTEM_OBJECTS_CUSTOMER_H_
#define ABCELEVATORSIM_SYSTEM_OBJECTS_CUSTOMER_H_
#include "Generator.h"
#include "RNG.h"
#include <vector>

struct RNG;
class Customer
{
private:
	int id;
	double time_of_arrival; //TPG
	double service_completion_time;// TZS service time at the counter
	double waiting_in_the_queue_floor;
	double waiting_in_the_queue_base;
    int current_floor;
    int destination_floor;
	static int pass_counter;

public:
	double GetWaitingInTheQueueFloor() {
		return waiting_in_the_queue_floor;
	}
	double GetWaitingInTheQueueBase() {
		return waiting_in_the_queue_base;
	}
	void SetWaitingInTheQueueFloor(double time) {
		waiting_in_the_queue_floor = time;
	}
	void SetWaitingInTheQueueBase(double time) {
		waiting_in_the_queue_base = time;
	}

	Customer(double time_of_arrival, RNG* rng);
	~Customer(void);



	int GetCustomerId() {
		return id;
	}
	double GetTimeOfArrival() {
		return time_of_arrival;
	}
	void SetTimeOfArrival(double time) {
		time_of_arrival = time;
	}
	int GetCurrentFloor() {
		return current_floor;
	}
	int GetDestinationFloor() {
		return destination_floor;
	}
	void SetDestinationFloor(int flooor) {
		destination_floor = flooor;
	}
	double GetServiceComletionTime() {
		return service_completion_time;
	}
	void SetServiceComletionTime(int time) {
		service_completion_time = time;
	}
	int GetCustomerCounter() { return pass_counter; }

};

#endif