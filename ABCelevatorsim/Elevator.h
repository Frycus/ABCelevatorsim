#ifndef ABCELEVATORSIM_SYSTEM_OBJECTS_ELEVATOR_H_
#define ABCELEVATORSIM_SYSTEM_OBJECTS_ELEVATOR_H_
#include <vector>
#include "Customer.h"
using namespace std;
class Elevator
{
private:
	
	int capacity;
	int velocity;
	bool busy;
	int current_floor; 
	int destination_floor;  
	int default_floor;
	vector <Customer *> passanger_list;    
	int min_waiting_time;
//	int inactivity_time;
	
	

public:
	//////
	enum ElevatorState
	{
		GOING_UP,
		GOING_DOWN,
		IDLE,
	};
	ElevatorState current_state;
	ElevatorState next_state;
	////////

	Elevator(int, int);
	~Elevator(void);

	void AddPassanger(Customer *passanger);
	void RemovePassanger(Customer *passanger);

	int GetCurrentFloor() {
		return current_floor;
	}
	void SetCurrentFloor(int floor){
		current_floor = floor;
	}
	int GetDestinationFloor(){
		return destination_floor;
	}
	void SetTheDestiny(int floor) {
		destination_floor = floor;
	}
	double GetVelocity() {
		return velocity;
	}
	int GetNumberOfPassangers() {
		return passanger_list.size();
	}
	Customer *GerPtrToPassList(int n) {
		return passanger_list[n];
	}
	Customer* Elevator::RemoveOnGND()
	{
		if (!passanger_list.empty())
		{
			Customer* p = passanger_list.back();
			passanger_list.pop_back();
			return p;
		}
		return nullptr;
	}
	void SortPassList();
	ElevatorState GetElevatorState() {
		return current_state;
	}
	ElevatorState GetElevatorNextState() {
		return next_state;
	}
	void SetCurrentState(ElevatorState state) {
		current_state = state;
	}
	void SetNextState(ElevatorState state) {
		next_state = state;
	}

	bool ElevatorFull() {
		return passanger_list.size() == capacity;
	}
	bool ElevatorEmpty() {
		return passanger_list.size() == 0;
	}
	bool IsElevatorBusy() {
		return busy;
	}
	void MakeEleBusy() {
		busy = true;
	}
	void MakeEleNotBusy() {
		busy = false;
	}


};

#endif