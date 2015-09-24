#pragma once
#include "Vehicle.h"

class Company
{
public:
	~Company();

private:
	Company();
	static Company* inst;
	vector<Vehicle*> vehicleList;

public:
	static Company* getInstance();

	void addVehicle(Vehicle* v);

	void FuelNeedsReport();
};

