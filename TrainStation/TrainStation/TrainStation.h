#pragma once
#include "Counter.h"
#include "Customer.h"
#include "Queue.cpp"
#include "Strategy.h"

class TrainStation
{
public:
	static TrainStation* getInstance()
	{ 
		if (inst == 0) inst = new TrainStation();
		return inst;
	}
	void openTrainStation();
	void printCustomerList();
	void startTrainStation(string strategy);
	void PrintFileHead();

private:
	TrainStation();
	~TrainStation(); // �ܺο��� �̱��� ��ü�� ������ delete �ϴ°��� ���� ���� �ʿ���.
	TrainStation(const TrainStation& other);
	static TrainStation* inst;

	Counter* counter;
	Queue<Customer> *customerList;
	Queue<Customer> *waitLine;
	Queue<Customer> *trainLine;

	int currentTime;
	Strategy* strategy;
};

