#include "stdafx.h"
#include "strategyFIFO.h"


strategyFIFO::strategyFIFO()
{
}


strategyFIFO::~strategyFIFO()
{
}

Customer* strategyFIFO::getNextCustomer(Queue<Customer>* waitLine, int currentTime, Counter* counter)
{
	waitLine->get(0)->SetEnterCounterTime(currentTime);
	counter->getAvailableClerk()->setCustomer(waitLine->deQueue());
	return nullptr;
}
