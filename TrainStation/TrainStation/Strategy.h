#pragma once
#include "Customer.h"
#include "Queue.h"
#include "Counter.h"

class Strategy
{
public:
	Strategy();
	~Strategy();

	virtual Customer* getNextCustomer(Queue<Customer>* waitLine, int currentTime, Counter* counter);
};

