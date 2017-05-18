#include "Simulation.h"

#include "Event.h"


Simulation::Simulation() :avg_queue_length_base(0), avg_queue_length_other(0)
{
}


void Simulation::Execute()
{
	building = new Building(11, 1, 10, 20, 30);
	//////
	building->GetListOfFloors();
	////
	////
	printf("%d \n", building->GetPointerToElevator()->GetCurrentFloor());
	////
	////
	
	printf("%d \n", building->GetPointerToFloor(0)->GetPointerToServiceDesk()->QueueSize());
	printf("%d \n", building->GetPointerToFloor(8)->GetPointerToServiceDesk()->GetDeskId());

	///

	eventlist = new EventList();
	std::cout << "Set end of the simulation time: " << std::endl;
	std::cin >> stop_time;
	std::cout << "Set the start time for statistics: " << std::endl;
	std::cin >> start_statistics;
	Kernels *kernels = new Kernels();
	kernels->ReadKernels("kernels.txt");

	rng_ptr = new RNG();
	rng_ptr->Initialize(kernels, 0, 0.034);

	eventlist->AddEvent(new ArrivalToTheBuilding(rng_ptr->tpg->Rand()));



	current_time = eventlist->FirstEventTime();
	building->GetPointerToElevator()->SetNextState(Elevator::GOING_UP);
	do
	{

		printf("----------------------------------------------------------------------\n");
		printf("CLOCK = %f \n\n", current_time);

		auto closest_event = eventlist->DeleteEvent();
		closest_event->Execute(eventlist, building, rng_ptr, start_statistics, stop_time);
		current_time = eventlist->FirstEventTime();
		QueueSizes(closest_event);

		bool no_eventtrig;
		

		do
		{
			no_eventtrig = true;
			for (int i = 0; i < building->QueuesVectorSize(); i++)
			{
				if (!building->IsQueueEmpty(i) && !building->GetPointerToElevator()->ElevatorFull() && !building->GetPointerToElevator()->IsElevatorBusy())
				{
					ElevatorDeparture* dep = new ElevatorDeparture(building->GetPointerToElevator());
					dep->Execute(eventlist, building, rng_ptr, start_statistics, stop_time);
					no_eventtrig = false;
				}
			}
			
			for (int i = 1; i <= 10; i++)
			{
				int queueSize = building->GetPointerToFloor(i)->GetPointerToServiceDesk()->QueueSize();
				bool busy = building->GetPointerToFloor(i)->GetPointerToServiceDesk()->DeskBusy();
				if ((queueSize>0) && !busy)
				{
		
					ServiceAtTheCounter *serv = new ServiceAtTheCounter(i);
					serv->Execute(eventlist, building, rng_ptr, start_statistics, stop_time);
					no_eventtrig = false;
					
				}
			}
			
		} while (!no_eventtrig);

	} while ((current_time <= stop_time) && eventlist->GetSize() != 0 );

}

Simulation::~Simulation()
{
	delete building;
	delete rng_ptr;
	delete eventlist;
}


void Simulation::QueueSizes(Event* closest_event)
{
	if (current_time > start_statistics)
	{

		avg_queue_length_base += ((current_time - closest_event->GetExeTime())*building->GerPtrToElevatorQueue(0).size());

		for (int i = 1; i < 11; i++)
		{
			avg_queue_length_other += ((current_time - closest_event->GetExeTime())*building->GetPointerToFloor(i)->GetPointerToServiceDesk()->QueueSize());
		}
	}
}


void Simulation::ShowStatistics()
{
	double sercust = building->GetCountOfServedCustomersBase();
	double swt = building->GetPointerToFloor(0)->GetSumOfWaitingTime();
	avg_waiting_time_base = building->GetPointerToFloor(0)->GetSumOfWaitingTime() / building->GetCountOfServedCustomersBase();
	printf("The average waiting time in the queue on the ground: %d\n", avg_waiting_time_base);

//	printf("The average elevator working time: %f \n");//, (building_->GetPointer2Elev(0)->GetWorkingTime() / (stop_time_ - start_statistics_)) * 100);
	printf("The average length of the ground floor queue: %f \n", avg_queue_length_base/(stop_time-start_statistics));
	printf("The average length of the counters queues on the floors from 1 to 10: %f \n", avg_queue_length_other/ (stop_time - start_statistics));
	
	/*The following functionality requires ajustments

	for (int i = 1; i < 11; i++)
	{
		int c = building->GetPointerToFloor(i)->GetPointerToServiceDesk()->GetCountOfServedCustomers();
	//	double wtm2 = building->GetPointerToFloor(i)->GetPointerToServiceDesk()->GetSumOfWaitingTime();
		
		avg_waiting_time = building->GetPointerToFloor(i)->GetSumOfWaitingTime() / building->GetPointerToFloor(i)->GetPointerToServiceDesk()->GetCountOfServedCustomers();
		printf("The average waiting time in the queue to elevator on the floor %d: %d\n", i, avg_waiting_time); 
	}*/
}

