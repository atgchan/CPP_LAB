// RacingCar.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	cout << "������ :" << gameID << endl;
	cout << "�⸧�� :" << fuelGuage << endl;
	cout << "���� �ӵ� :" << curSpeed << endl;
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

