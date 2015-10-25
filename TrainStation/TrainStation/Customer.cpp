#include "stdafx.h"
#include "Customer.h"
#include <fstream>


Customer::Customer()
	:enterCounterTime(0), waitingTime(0), arrivalTime(0), counterTime(0), travellingTime(0)
{
}


Customer::~Customer()
{
}

void Customer::SetCustomerName(string s)
{
	customerName = s;
}

void Customer::SetArrivalTime(int i)
{
	arrivalTime = i;
}

void Customer::SetCounterTime(int i)
{
	counterTime = i;
}

void Customer::SetDepartName(string s)
{
	departName = s;
}

void Customer::SetDestiName(string s)
{
	destiName = s;
}

void Customer::SetTravellingTime(int i)
{
	travellingTime = i;
}

void Customer::PrintStatus()
{
	cout << customerName << arrivalTime << counterTime << departName << destiName << travellingTime << endl;
}

std::string Customer::GetCustomerName()
{
	return customerName;
}

int Customer::GetArrivalTime()
{
	return arrivalTime;
}

int Customer::GetCounterTime()
{
	return counterTime;
}

std::string Customer::GetDepartName()
{
	return departName;
}

std::string Customer::GetDestiName()
{
	return destiName;
}

int Customer::GetTravellingTime()
{
	return travellingTime;
}

int Customer::GetEnterCounterTime()
{
	return enterCounterTime;
}

void Customer::increaseWaitingTime()
{
	waitingTime++;
}

void Customer::RecordStatus(int currentTime)
{
	ofstream outFile("result.txt", ios::app);
	outFile.width(10); outFile.fill(); outFile << customerName;
	outFile.width(20); outFile.fill(); outFile << arrivalTime;
	outFile.width(10); outFile.fill(); outFile << waitingTime;
	outFile.width(20); outFile.fill(); outFile << currentTime;
	outFile.width(20); outFile.fill(); outFile << currentTime + travellingTime;
	outFile << endl;
}

void Customer::SetEnterCounterTime(int currentTime)
{
	enterCounterTime = currentTime;
}

void Customer::SetLeavingTime(int currentTime)
{
	leavingTime = currentTime;
}

