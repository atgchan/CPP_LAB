#include "stdafx.h"
#include "Company.h"

Company* Company::inst;

Company::Company()
{
}

Company::~Company()
{
}

Company * Company::getInstance()
{
	if (inst == 0) {
		inst = new Company();
	}
	return inst;
}

void Company::addVehicle(Vehicle * v)
{
	vehicleList.push_back(v);
}

void Company::FuelNeedsReport()
{
	for (auto vehicle : vehicleList)
	{
		cout << vehicle->calcFuelNeeds() << endl;
	}
}

