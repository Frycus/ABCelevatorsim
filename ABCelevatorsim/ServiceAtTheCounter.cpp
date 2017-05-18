#include "ServiceAtTheCounter.h"


ServiceAtTheCounter::ServiceAtTheCounter(int floor)
{
	desk_id = floor;
}


ServiceAtTheCounter::~ServiceAtTheCounter()
{
}

void ServiceAtTheCounter::Execute(EventList * eventlist_ptr, Building * building_ptr, RNG * rng, double start_stats, double stop_time)
{
	printf("\n[EVENT] ServiceAtTheCounter::Execute():\n");
	
		building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->MakeDeskBusy();
		printf("Desk busy? %d\n", building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->DeskBusy());
		printf("Is the queue to the desk empty: %d\n", building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->QueueEmpty());
		Customer *next = building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->GetPointerToFirstCustomerInQueue();
		printf("[EVENT] Customer no %d is removed from the queue to the counter and will be served\n", next->GetCustomerId());
		building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->NextCustomerServed(next);
		building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->RemoveCustomerFromQueue();
		double new_event_time = eventlist_ptr->FirstEventTime() + rng->tzs->Rand(900, 2700);
		next->SetServiceComletionTime(new_event_time);
		double curre_time = eventlist_ptr->FirstEventTime();
		printf("New departure from the counter is being scheduled at: %f\n\n", new_event_time);
		eventlist_ptr->AddEvent(new DepartureFromTheCounter(new_event_time, desk_id));
	/*	if (start_stats<eventlist_ptr->FirstEventTime())
		{
			double wtm1 = building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->GetSumOfWaitingTime();
			double ct = eventlist_ptr->FirstEventTime();
			building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->IncSumOfWaitingTime(new_event_time - curre_time);
			double wtm2 = building_ptr->GetPointerToFloor(desk_id)->GetPointerToServiceDesk()->GetSumOfWaitingTime();

		} */
	
	
}
