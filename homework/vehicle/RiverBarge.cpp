#include "stdafx.h"
#include "RiverBarge.h"


RiverBarge::RiverBarge(double tripDistance, double fuelEfficiency)
	:Vehicle(tripDistance, fuelEfficiency)
{
}

RiverBarge::~RiverBarge()
{
}

double RiverBarge::calcFuelEfficiency()
{
	return Vehicle::mFuelEfficiency * 1.2;
}

double RiverBarge::calcTripDistance()
{
	return Vehicle::mTripDistance;
}
