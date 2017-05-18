#include "Service_desk.h"


Service_desk::Service_desk(int id)
{
	desk_id = id;
	desk_busy = false;
	current_customer = nullptr;
	queue_to_counter = {};
	counter_of_served_customers = 0;
}


Service_desk::~Service_desk(void)
{
}

void Service_desk::IncCountOfServedCustomers() {
	counter_of_served_customers++;
}


int Service_desk::GetCountOfServedCustomers() {
	return counter_of_served_customers;
}

void Service_desk::AddCustomerToQueue(Customer *cust)
{
	queue_to_counter.push(cust);
}

void Service_desk::RemoveCustomerFromQueue()
{
	queue_to_counter.pop();

}
