#pragma once

class Car
{
public:
	void Drive();
	double getDrivedDistance()
	{
		return drivedDistance;
	}

private:
	double drivedDistance;
};