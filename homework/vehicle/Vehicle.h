#pragma once
class Vehicle
{
public:
	Vehicle(double tripDistance, double fuelEfficiency);
	~Vehicle();

public:
	virtual double calcFuelNeeds() final;

	virtual double calcTripDistance() { return mTripDistance; }
	virtual double calcFuelEfficiency() { return mFuelEfficiency; }

protected:
	double mTripDistance;
	double mFuelEfficiency;
};

