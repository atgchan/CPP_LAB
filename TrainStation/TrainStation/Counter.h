#pragma once
#include "Clerk.h"
#include "Queue.h"

class Counter
{
public:
	Counter(int num);
	~Counter();
	void setStrategy(string st);
	Clerk* getAvailableClerk();
	void releaseCustomer(int currentTime, Queue<Customer>* trainLine);
private:
	Clerk* clerkList[3];
	int numberOfClerk;
	string strategy;
};

