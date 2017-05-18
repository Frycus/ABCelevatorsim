#include "ElevatorArrival.h"


ElevatorArrival::ElevatorArrival(double time, Elevator *elevator_ptr) : Event(time)
{
	elevator = elevator_ptr;

}

ElevatorArrival::~ElevatorArrival()
{
}

void ElevatorArrival::Execute(EventList * eventlist_ptr, Building * building_ptr, RNG * rng, double start_stats, double stop_time)
{
	elevator->MakeEleNotBusy();
	elevator->SetCurrentFloor(elevator->GetDestinationFloor());
	printf("\n[EVENT] ElevatorArrival::Execute():\n");
	printf("Elevator arrived on the: %d floor\n", elevator->GetCurrentFloor());
	
	if (elevator->GetCurrentFloor() == 0)
	{
		double TPW = 30;
		int i = 0;
		while (!elevator->ElevatorEmpty())
		{
			TPW = TPW + rng->tpw->Rand(5, 15);
			Customer* deleted;
			deleted = elevator->RemoveOnGND();

			printf("Customer no. %d leaves the building\n", deleted->GetCustomerId());
			building_ptr->GetPointerToFloor(0)->SetTpwOnArrival(TPW);
		}

	}
	double TPW = 30;
	for (int i = 0; i < elevator->GetNumberOfPassangers(); i++)
	{
		
		if (elevator->GetNumberOfPassangers()==0)
		{
			break;
		}
		if (elevator->GerPtrToPassList(i)->GetDestinationFloor()==elevator->GetCurrentFloor())
		{
	
			elevator->GerPtrToPassList(i)->SetDestinationFloor(0);

			if (elevator->GetCurrentFloor()!=0)
			{
				TPW = TPW + rng->tpw->Rand(5, 15);
				printf("Customer no. %d left the elevator and join the queue to the service desk\n", elevator->GerPtrToPassList(i)->GetCustomerId());
				building_ptr->GetPointerToFloor(elevator->GetCurrentFloor())->GetPointerToServiceDesk()->AddCustomerToQueue(elevator->GerPtrToPassList(i));
				elevator->RemovePassanger(elevator->GerPtrToPassList(i));
				printf("Size of the queue to desk on the %d floor: %d\n", elevator->GetCurrentFloor(), building_ptr->GetPointerToFloor(elevator->GetCurrentFloor())->GetPointerToServiceDesk()->QueueSize());
				building_ptr->GetPointerToFloor(0)->SetTpwOnArrival(TPW);
			}
			
		}
	}
}
