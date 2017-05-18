#include "Elevator.h"


Elevator::Elevator(int el_capacity, int el_speed)
{
	capacity = el_capacity;
	velocity = el_speed;
	current_floor = 0;
	current_state = IDLE;
	min_waiting_time = 30;
	default_floor = 0;
	busy = false;
}


Elevator::~Elevator(void)
{
}

void Elevator::AddPassanger(Customer * passanger)
{
	passanger_list.push_back(passanger);
}

void Elevator::RemovePassanger(Customer * passanger)
{
	for (auto it = passanger_list.begin(); it < passanger_list.end(); ++it) {
		if (*it == passanger) {
			passanger_list.erase(it);
			break;
		}
	}
}

void Elevator::SortPassList()
{
	bool swap=true;
	for (unsigned j = 1; swap && j < passanger_list.size(); ++j) {
		swap = false;
		for (unsigned i = 0; i < passanger_list.size() - j; ++i) {
			if (passanger_list[i]->GetDestinationFloor() > passanger_list[i + 1]->GetDestinationFloor()) {
				swap = true;
				Customer * tempObj = passanger_list[i]; 
				passanger_list[i] = passanger_list[i + 1];     
				passanger_list[i + 1] = tempObj;    
			}
		}
	}
}
