#include <iostream>
#include "Simulation.h"
#include "Kernels.h"

int main()
{
	printf("------------------------------------------------------------------------\n");
	printf("                           START\n");
	printf("------------------------------------------------------------------------\n");

	Simulation *sim = new Simulation();
	sim->Execute();

	printf("------------------------------------------------------------------------\n");
	printf("                           FINISHED\n");
	printf("------------------------------------------------------------------------\n");
	sim->ShowStatistics();
	return 0;
}