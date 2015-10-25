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
	~TrainStation(); // 외부에서 싱글톤 객체를 강제로 delete 하는것을 막기 위해 필요함.
	TrainStation(const TrainStation& other);
	static TrainStation* inst;

	Counter* counter;
	Queue<Customer> *customerList;
	Queue<Customer> *waitLine;
	Queue<Customer> *trainLine;

	int currentTime;
	Strategy* strategy;
};

