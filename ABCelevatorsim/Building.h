#ifndef ABCELEVATORSIM_SYSTEM_OBJECTS_BUILDING_H_
#define ABCELEVATORSIM_SYSTEM_OBJECTS_BUILDING_H_
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Elevator.h"
#include "Floor.h"
#include "Customer.h"

using namespace std;
class Building
{
private:
	int n_floors;
	int n_elevators;
	Elevator *ptr_to_elevator;
	vector <Floor *> ptr_to_floors;
	vector<std::queue<Customer*>>  queue_to_elevator;
	int counter_of_served_customers_base;

public:

	void IncCountOfServedCustomersBase() {
		counter_of_served_customers_base++;
	}
	int GetCountOfServedCustomersBase() {
		return counter_of_served_customers_base;
	}

	Building(int, int, int, int, int);
	~Building(void);
	Elevator *GetPointerToElevator() {
		return ptr_to_elevator;
	}
	queue<Customer*> GerPtrToElevatorQueue(int i) {
		return queue_to_elevator.at(i);
	}
	Floor *GetPointerToFloor(int id) {
		return ptr_to_floors[id];
	}
	
	bool IsQueueEmpty(int id);
	void AddCustomerToElQueue(Customer *customer, int floor); 
	void RemoveCustomerFromElQueue(int floor);
	int QueuesVectorSize() { return queue_to_elevator.size(); }
	int GetListOfFloors();


};

#endif