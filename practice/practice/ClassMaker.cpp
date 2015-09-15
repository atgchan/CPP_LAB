#include "car.h"
#include "SportsCar.h"
#include <iostream>

int main()
{
	Car car;
	car.Drive();

	double dd = car.getDrivedDistance();

	SportsCar scar;
	scar.Drive();
	scar.getDrivedDistance();

	getchar();
	return 0;
}