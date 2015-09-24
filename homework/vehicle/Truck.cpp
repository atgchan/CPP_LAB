#include "stdafx.h"
#include "Truck.h"

Truck::Truck(double tripDistance, double fuelEfficiency)
	:Vehicle(tripDistance, fuelEfficiency)
{
}

Truck::~Truck()
{
}

double Truck::calcFuelEfficiency()
{
	return Vehicle::mFuelEfficiency * 1.1;
}

double Truck::calcTripDistance()
{
	return Vehicle::mTripDistance;
}
