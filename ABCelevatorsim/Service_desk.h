#ifndef ABCELEVATORSIM_SYSTEM_OBJECTS_SERVICE_DESK_H_
#define ABCELEVATORSIM_SYSTEM_OBJECTS_SERVICE_DESK_H_
#include <queue>
#include "Customer.h"

using namespace std;
class Service_desk
{
private:
	int desk_id;
	queue <Customer *> queue_to_counter;
	Customer *current_customer;
	bool desk_busy;
	int counter_of_served_customers;

public:
	Service_desk(int);
	~Service_desk();

	void IncCountOfServedCustomers();
	int GetCountOfServedCustomers();

	void SetCountOfServedCustomers(double val) {
		counter_of_served_customers = val;
	}

	int GetDeskId() {
		return desk_id;
	}
	bool QueueEmpty() {
		return queue_to_counter.size() == 0;
	}
	int QueueSize() {
		return queue_to_counter.size();
	}
	bool DeskBusy() {
		return desk_busy;
	}
	void MakeDeskBusy() {
		desk_busy = true;
	}
	void MakeDeskFree() {
		desk_busy = false;
	}
	Customer *GetPointerToFirstCustomerInQueue() {
		return queue_to_counter.front();
	}
	Customer *GetPointerToServedCustomer() {
		return current_customer;
	}
	void NextCustomerServed(Customer* next) {
		current_customer = next;
	}
	void AddCustomerToQueue(Customer *customer);
	void RemoveCustomerFromQueue();
};

#endif