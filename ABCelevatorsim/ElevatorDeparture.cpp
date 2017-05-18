#include "ElevatorDeparture.h"


ElevatorDeparture::ElevatorDeparture(Elevator *elevator_ptr)
{
	elevator = elevator_ptr;
}


ElevatorDeparture::~ElevatorDeparture()
{
}



void ElevatorDeparture::Execute(EventList * eventlist_ptr, Building * building_ptr, RNG * rng, double start_stats, double stop_time)
{
	
	printf("\n[EVENT] ElevatorDeparture::Execute():\n");
	elevator->SetCurrentState(elevator->GetElevatorNextState());
	elevator->MakeEleBusy();
	curr_floor = elevator->GetCurrentFloor();
	//going up
	printf("Elevator departs from %d floor\n", curr_floor);
	double TPW_A = building_ptr->GetPointerToFloor(curr_floor)->GetTpwOnArrival();
	if (elevator->GetElevatorState() == Elevator::GOING_UP)
	{
		if (curr_floor == 0)
		{
			double TPW = 30.00+ TPW_A;
			if (building_ptr->GerPtrToElevatorQueue(0).size() > 0)
			{
				for (int i = 0; i < building_ptr->GerPtrToElevatorQueue(curr_floor).size(); i++)
				{
					if (elevator->ElevatorFull())
					{
						break;
					}
					if (curr_floor == 0) {
						TPW = TPW + rng->tpw->Rand(5, 15);
						elevator->AddPassanger(building_ptr->GerPtrToElevatorQueue(0).front());
						///////
						double ta = building_ptr->GerPtrToElevatorQueue(0).front()->GetTimeOfArrival();
						building_ptr->GerPtrToElevatorQueue(0).front()->SetWaitingInTheQueueBase(eventlist_ptr->FirstEventTime() - ta);
						double wt = building_ptr->GerPtrToElevatorQueue(0).front()->GetWaitingInTheQueueBase();
						building_ptr->GetPointerToFloor(0)->IncSumOfWaitingTime(wt);
						double swt = building_ptr->GetPointerToFloor(0)->GetSumOfWaitingTime();
						building_ptr->IncCountOfServedCustomersBase();
						////
						building_ptr->RemoveCustomerFromElQueue(0);
					}
				}
				elevator->SortPassList();
				int dest = elevator->GerPtrToPassList(0)->GetDestinationFloor();
				elevator->SetTheDestiny(dest);
				elevator->SetNextState(Elevator::GOING_UP);
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}
			else
			{
				for (int i = 0; i < 11; i++) {
					if (building_ptr->GerPtrToElevatorQueue(i).size() > 0 && curr_floor < i)
					{
						elevator->SetTheDestiny(i);
						elevator->SetNextState(Elevator::GOING_UP);
						double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
						eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
						break;
					}

				}
			}

		}
		else if (curr_floor == 10)
		{
			elevator->SetCurrentState(Elevator::GOING_DOWN);

		}
		else
		{
			double TPW = 30.00+ TPW_A;
			if (!elevator->ElevatorEmpty())
			{
				elevator->SortPassList();
				elevator->SetTheDestiny(elevator->GerPtrToPassList(0)->GetDestinationFloor());
				elevator->SetNextState(Elevator::GOING_UP);
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}
			else
			{
				elevator->SetCurrentState(Elevator::GOING_DOWN);
				elevator->SetTheDestiny(0);
				for (int i = curr_floor; i < 11; i++) {
					if (building_ptr->GerPtrToElevatorQueue(i).size() > 0 && curr_floor < i)
					{
						elevator->SetTheDestiny(i);
						elevator->SetCurrentState(Elevator::GOING_UP);
						elevator->SetNextState(Elevator::GOING_UP);

						break;
					}

				}
				double new_event_time = TPW+eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}

		}
	}
	
	////////////////////////
	//going down

	if (elevator->GetElevatorState() == Elevator::GOING_DOWN)
	{
		if (!elevator->ElevatorEmpty())
		{
			if (curr_floor==10)
			{
				double TPW = 30.00+ TPW_A;
				elevator->SetTheDestiny(0);
				elevator->SetNextState(Elevator::GOING_DOWN);
				for (int i = 0; i < building_ptr->GerPtrToElevatorQueue(curr_floor).size(); i++)
				{
					if (elevator->ElevatorFull())
					{
						break;
					}
					else
					{
						TPW = TPW + rng->tpw->Rand(5, 15);
						elevator->AddPassanger(building_ptr->GerPtrToElevatorQueue(curr_floor).front());
						building_ptr->RemoveCustomerFromElQueue(curr_floor);
					}

				}
				for (int i = 9; i > 0; i--)
				{
					if (building_ptr->GerPtrToElevatorQueue(i).size()>0 && !elevator->ElevatorFull())
					{
						elevator->SetTheDestiny(i);
					}
				}
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(curr_floor - elevator->GetDestinationFloor()));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));

			}
			else if (curr_floor==0)
			{
				elevator->SetCurrentState(Elevator::GOING_UP);
			}
			else
			{
				double TPW = 30.00+ TPW_A;
				elevator->SetTheDestiny(0);
				elevator->SetNextState(Elevator::GOING_DOWN);
				for (int i = 0; i < building_ptr->GerPtrToElevatorQueue(curr_floor).size(); i++)
				{
					if (elevator->ElevatorFull())
					{
						break;
					}
					else
					{
						TPW = TPW + rng->tpw->Rand(5, 15);
						elevator->AddPassanger(building_ptr->GerPtrToElevatorQueue(curr_floor).front());
						building_ptr->RemoveCustomerFromElQueue(curr_floor);
					}

				}
				for (int i = curr_floor-1; i > 0; i--)
				{
					if (building_ptr->GerPtrToElevatorQueue(i).size()>0 && !elevator->ElevatorFull())
					{
						elevator->SetTheDestiny(i);
					}
				}
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(curr_floor - elevator->GetDestinationFloor()));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}
		}
		else
		{
			if (curr_floor == 10)
			{
				double TPW = 30.00+ TPW_A;
				elevator->SetTheDestiny(0);
				elevator->SetNextState(Elevator::GOING_DOWN);
				for (int i = 0; i < building_ptr->GerPtrToElevatorQueue(curr_floor).size(); i++)
				{
					if (elevator->ElevatorFull())
					{
						break;
					}
					else
					{
						TPW = TPW + rng->tpw->Rand(5, 15);
						elevator->AddPassanger(building_ptr->GerPtrToElevatorQueue(curr_floor).front());
						building_ptr->RemoveCustomerFromElQueue(curr_floor);
					}

				}
				for (int i = 9; i > 0; i--)
				{
					if (building_ptr->GerPtrToElevatorQueue(i).size()>0 && !elevator->ElevatorFull())
					{
						elevator->SetTheDestiny(i);
					}
				}
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(curr_floor - elevator->GetDestinationFloor()));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}
			else if(curr_floor == 0)
			{
				elevator->SetCurrentState(Elevator::GOING_UP);
			}
			else
			{
				double TPW = 30.00+ TPW_A;
				elevator->SetTheDestiny(0);
				elevator->SetNextState(Elevator::GOING_DOWN);
				for (int i = 0; i < building_ptr->GerPtrToElevatorQueue(curr_floor).size(); i++)
				{
					if (elevator->ElevatorFull())
					{
						break;
					}
					else
					{
						TPW = TPW + rng->tpw->Rand(5, 15);
						elevator->AddPassanger(building_ptr->GerPtrToElevatorQueue(curr_floor).front());
						building_ptr->RemoveCustomerFromElQueue(curr_floor);
					}

				}
				for (int i = curr_floor - 1; i > 0; i--)
				{
					if (building_ptr->GerPtrToElevatorQueue(i).size()>0 && !elevator->ElevatorFull())
					{
						elevator->SetTheDestiny(i);
					}
				}
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(curr_floor - elevator->GetDestinationFloor()));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
				
			}
		}
	}

	/////



	if (elevator->GetElevatorState() == Elevator::GOING_UP)
	{
		if (curr_floor == 0)
		{
			double TPW = 30.00+ TPW_A;
			if (building_ptr->GerPtrToElevatorQueue(0).size() > 0)
			{
				for (int i = 0; i < building_ptr->GerPtrToElevatorQueue(curr_floor).size(); i++)
				{
					if (elevator->ElevatorFull())
					{
						break;
					}
					if (curr_floor == 0) {
						TPW = TPW + rng->tpw->Rand(5, 15);
						elevator->AddPassanger(building_ptr->GerPtrToElevatorQueue(0).front());
						///////
						double ta = building_ptr->GerPtrToElevatorQueue(0).front()->GetTimeOfArrival();
						building_ptr->GerPtrToElevatorQueue(0).front()->SetWaitingInTheQueueBase(eventlist_ptr->FirstEventTime() - ta);
						double wt = building_ptr->GerPtrToElevatorQueue(0).front()->GetWaitingInTheQueueBase();
						building_ptr->GetPointerToFloor(0)->IncSumOfWaitingTime(wt);
						double swt = building_ptr->GetPointerToFloor(0)->GetSumOfWaitingTime();
						building_ptr->IncCountOfServedCustomersBase();
						////
						building_ptr->RemoveCustomerFromElQueue(0);
					}
				}
				elevator->SortPassList();
				int dest = elevator->GerPtrToPassList(0)->GetDestinationFloor();
				elevator->SetTheDestiny(dest);
				elevator->SetNextState(Elevator::GOING_UP);
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}
			else
			{
				for (int i = 0; i < 11; i++) {
					if (building_ptr->GerPtrToElevatorQueue(i).size() > 0 && curr_floor < i)
					{
						elevator->SetTheDestiny(i);
						elevator->SetNextState(Elevator::GOING_UP);
						double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
						eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
						break;
					}

				}
			}

		}
		else if (curr_floor == 10)
		{
			elevator->SetCurrentState(Elevator::GOING_DOWN);

		}
		else
		{
			double TPW = 30.00+ TPW_A;
			if (!elevator->ElevatorEmpty())
			{
				elevator->SortPassList();
				elevator->SetTheDestiny(elevator->GerPtrToPassList(0)->GetDestinationFloor());
				elevator->SetNextState(Elevator::GOING_UP);
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}
			else
			{
				elevator->SetCurrentState(Elevator::GOING_DOWN);
				elevator->SetTheDestiny(0);
				for (int i = curr_floor; i < 11; i++) {
					if (building_ptr->GerPtrToElevatorQueue(i).size() > 0 && curr_floor < i)
					{
						elevator->SetTheDestiny(i);
						elevator->SetCurrentState(Elevator::GOING_UP);
						elevator->SetNextState(Elevator::GOING_UP);

						break;
					}

				}
				double new_event_time = TPW + eventlist_ptr->FirstEventTime() + ((4.00 / elevator->GetVelocity())*(elevator->GetDestinationFloor() - curr_floor));
				eventlist_ptr->AddEvent(new ElevatorArrival(new_event_time, elevator));
			}

		}
	}




	///////
		
	building_ptr->GetPointerToFloor(curr_floor)->SetTpwOnArrival(0);
	printf("Elevator departs to %d floor\n", elevator->GetDestinationFloor());
	printf("Elevator state %d\n", elevator->GetElevatorState());
	printf("Number of passangers on board: %d \n\n", elevator->GetNumberOfPassangers());
}
