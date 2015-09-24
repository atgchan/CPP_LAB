// vehicle.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Company.h"
#include "Truck.h"
#include "RiverBarge.h"


int main()
{
	Company* company = Company::getInstance();
	
	company->addVehicle(new Truck(300, 30));
	company->addVehicle(new Truck(100, 20));
	company->addVehicle(new Truck(200, 10));

	company->addVehicle(new RiverBarge(100, 5));
	company->addVehicle(new RiverBarge(500, 5));

	company->FuelNeedsReport();

	getchar();

    return 0;
}

