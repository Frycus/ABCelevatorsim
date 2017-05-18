#include "Customer.h"
//#include <random>



int Customer::pass_counter = 1;
Customer::Customer(double arr_time, RNG *rng)
{
	id = pass_counter++;
	time_of_arrival = arr_time;
	current_floor = 0;
	destination_floor = static_cast<int>(rng->tpa->Rand(1, 11));
	waiting_in_the_queue_base = 0.00;
	waiting_in_the_queue_floor = 0.00;
}


Customer::~Customer(void)
{
}
