#include "Building.h"


Building::Building(int n_of_floors, int n_of_elevators, int n_desks_on_floor, int el_capacity, int el_speed)
{
	n_floors= n_of_floors;
	n_elevators = n_of_elevators;
	counter_of_served_customers_base = 0;

	for (int i=0; i < n_of_floors; i++)
	{
		ptr_to_floors.push_back(new Floor(i, n_desks_on_floor));
	}
	for (int i=0; i < n_of_elevators; i++)
	{
		ptr_to_elevator=new Elevator(el_capacity, el_speed);
	}// we have one elevator anyway
	for (int i = 0; i < (n_of_floors); i++) {
		std::queue<Customer*> q;
		queue_to_elevator.push_back(q);
	}
}


Building::~Building()
{
	for (int i=0; i < ptr_to_floors.size(); i++)
	{
		delete ptr_to_floors.at(i);
	}
	
	delete ptr_to_elevator;

}

bool Building::IsQueueEmpty(int i)
{
	
		if (queue_to_elevator[i].size() != 0) {
			return false;
	
	}
	return true;
}

void Building::AddCustomerToElQueue(Customer *customer, int floor)
{
	queue_to_elevator[floor].push(customer);
}

void Building::RemoveCustomerFromElQueue(int floor)
{
	queue_to_elevator[floor].pop();
}

int Building::GetListOfFloors()
{

	for (int i = 0; i < ptr_to_floors.size(); i++)
	{
	
		printf("%d \n", ptr_to_floors[i]->GetFloorNumber());
	}
	return 0;
}
