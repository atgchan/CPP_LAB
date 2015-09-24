#include "stdafx.h"
#include "Vehicle.h"


Vehicle::Vehicle(double tripDistance, double fuelEfficiency)
{
	mTripDistance = tripDistance;
	mFuelEfficiency = fuelEfficiency;
}

Vehicle::~Vehicle()
{
}

double Vehicle::calcFuelNeeds()
{
	return calcTripDistance() / calcFuelEfficiency();
}
