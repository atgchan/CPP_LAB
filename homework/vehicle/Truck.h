#pragma once
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck(double tripDistance, double fuelEfficiency);
	~Truck();

	virtual double calcFuelEfficiency();
	virtual double calcTripDistance();

};

