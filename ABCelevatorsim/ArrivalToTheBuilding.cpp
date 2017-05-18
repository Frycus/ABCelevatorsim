#include "ArrivalToTheBuilding.h"



ArrivalToTheBuilding::ArrivalToTheBuilding(double time) : Event(time)
{

}


ArrivalToTheBuilding::~ArrivalToTheBuilding()
{
}

void ArrivalToTheBuilding::Execute(EventList* eventlist_ptr, Building * building_ptr, RNG * rng, double start_stats, double stop_time)
{
	printf("[EVENT] ArrivalToTheBuilding::Execute():\n");
	//new customer created
	Customer *new_customer = new Customer(executionTime, rng);
	new_customer->SetTimeOfArrival(executionTime);
	//customer added to the queue to the elevator
	building_ptr->AddCustomerToElQueue(new_customer, 0);
	printf("\n New customer no. %d added to queue", new_customer->GetCustomerId());

	//scheduling new arrival
	double new_event_time = executionTime + rng->tpg->Rand();
	eventlist_ptr->AddEvent(new ArrivalToTheBuilding(new_event_time));
	printf("\nNew CustomerArrival Event at %f\n", new_event_time);
	printf("Size of the queue: %d\n", building_ptr->GerPtrToElevatorQueue(0).size());





}
