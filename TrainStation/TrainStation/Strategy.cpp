#include "stdafx.h"
#include "Strategy.h"


Strategy::Strategy()
{
}


Strategy::~Strategy()
{
}

Customer* Strategy::getNextCustomer(Queue<Customer>* waitLine, int currentTime, Counter* counter)
{
	cout << "Please select  a strategy" << endl;
	return nullptr;
}
