// RacingCar.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "RacingCar.h"

void RacingCar::InitMember(char *ID, int fuel)
{
	strcpy_s(gameID, ID);
	fuelGuage = fuel;
	curSpeed = 0;
}

void RacingCar::ShowCurrentState()
{
	cout << "소유자 :" << gameID << endl;
	cout << "기름양 :" << fuelGuage << endl;
	cout << "현재 속도 :" << curSpeed << endl;
}

void RacingCar::Accel()
{
	if (fuelGuage < CAR_CONST::FUEL_STEP)
	{
		return;
	}
	fuelGuage -= CAR_CONST::FUEL_STEP;
	curSpeed += CAR_CONST::SPEED_STEP;
}

void RacingCar::Break()
{
	if (curSpeed >= 10)
	{
		curSpeed -= 10;
	}
}

