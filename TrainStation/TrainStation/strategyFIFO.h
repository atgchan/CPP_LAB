#pragma once
#include "Strategy.h"

class strategyFIFO : public Strategy
{
public:
	strategyFIFO();
	~strategyFIFO();

	Customer* getNextCustomer(Queue<Customer>* waitLine, int currentTime, Counter* counter);
};

