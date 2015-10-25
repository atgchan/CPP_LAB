#include "stdafx.h"
#include "Clerk.h"


Clerk::Clerk()
	:currentCustomer(nullptr)
{
}


Clerk::~Clerk()
{
}

bool Clerk::isOccupied()
{
	if (currentCustomer != nullptr)
		return true;
	else return false;
}

void Clerk::setCustomer(Customer* customer)
{
	currentCustomer = customer;
}

Customer* Clerk::getCurrentCustomer()
{
	return currentCustomer;
}

void Clerk::emptyCustomer()
{
	currentCustomer = nullptr;
}
