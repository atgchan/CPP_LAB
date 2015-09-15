#include "stdafx.h"
#include "RacingCar.h"

int main()
{
	RacingCar myCar;
	myCar.InitMember("Porche", 10);

	myCar.Accel();
	myCar.Accel();
	myCar.ShowCurrentState();

	myCar.Break();
	myCar.ShowCurrentState();

	getchar();
	return 0;
}
