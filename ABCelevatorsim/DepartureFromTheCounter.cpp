#include "DepartureFromTheCounter.h"
#include "Customer.h"

DepartureFromTheCounter::DepartureFromTheCounter(double time, int floor) : Event(time)
{
	floor_id = floor;
}


DepartureFromTheCounter::~DepartureFromTheCounter()
{
}

void DepartureFromTheCounter::Execute(EventList * eventlist_ptr, Building * building_ptr, RNG * rng, double start_stats, double stop_time)
{
	printf("[EVENT] DepartureFromTheCounter::Execute():\n");
	Customer* removed = building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->GetPointerToServedCustomer();
	printf("Customer no. %d is leaving the counter and joing the elevator queue\n", removed->GetCustomerId());
	printf("Customer is waiting on floor: %d\n", floor_id);
	building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->MakeDeskFree();
	building_ptr->AddCustomerToElQueue(removed, floor_id);
	if (start_stats<executionTime)
	{
		int count2 = building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->GetCountOfServedCustomers();
		building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->IncCountOfServedCustomers();
//		building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->SetCountOfServedCustomers(count2);
//		int count1 = building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->GetCountOfServedCustomers();
//		double sum_waiting = building_ptr->GetPointerToFloor(floor_id)->GetPointerToServiceDesk()->GetSumOfWaitingTime();
	}
	
}