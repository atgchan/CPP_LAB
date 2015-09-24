#pragma once
#include "Vehicle.h"

class RiverBarge : public Vehicle
{
public:
	RiverBarge(double tripDistance, double fuelEfficiency);
	~RiverBarge();

	virtual double calcFuelEfficiency();
	virtual double calcTripDistance();
};

