#include "stdafx.h"
#include "Counter.h"
#include "Queue.h"


Counter::Counter(int num)
	:numberOfClerk(num), strategy("fifo")
{
	for (int i = 0; i < num; i++)
	{
		clerkList[i] = new Clerk();
	}
}


Counter::~Counter()
{
	delete[] *clerkList;
}

void Counter::setStrategy(string st)
{
	strategy = st;
}

Clerk* Counter::getAvailableClerk()
{
	for (int i = 0; i < 3; i++)
	{
		if (!(clerkList[i]->isOccupied()))
		{
			return clerkList[i];
		}
	}
	return nullptr;
}

void Counter::releaseCustomer(int currentTime, Queue<Customer>* trainLine)
{
	for (int i = 0; i < 3; i++)
	{
		if (clerkList[i]->getCurrentCustomer() == nullptr) continue;

		if ((clerkList[i]->getCurrentCustomer()->GetEnterCounterTime() + clerkList[i]->getCurrentCustomer()->GetCounterTime()) == currentTime)
		{
			trainLine->enQueue(clerkList[i]->getCurrentCustomer());
			clerkList[i]->emptyCustomer();
		}
	}
}
