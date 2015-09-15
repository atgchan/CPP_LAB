#include "stdafx.h"
#include "Account.h"


Account::Account(int accountNumber, int money, string accountName)
{
	mAccountNumber = accountNumber;
	mBalance = money;
	mAccountName = accountName;
}

Account::~Account()
{
}

int Account::Deposite(int money)
{
	mBalance += money;
	return mBalance;
}

int Account::Withdraw(int money)
{
	mBalance -= money;
	return mBalance;
}
