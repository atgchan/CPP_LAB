#pragma once
#include "Customer.h"

class Clerk
{
public:
	Clerk();
	~Clerk();

	void setCustomer(Customer* customer);
	bool isOccupied();

	Customer* getCurrentCustomer();
	void emptyCustomer();

private:
	Customer* currentCustomer;
};

