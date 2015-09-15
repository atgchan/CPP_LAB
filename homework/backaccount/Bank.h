#pragma once
#include "Account.h"

const int MAX_ACC_SIZE = 255;

class Bank
{
public:
	Bank();
	~Bank();

public:
	void CreateAccount(int accountNumber, int money, string accountName);
	void DeleteAccount(int accountNumber);
	Account* FindAccount(int accountNumber);
	int SetDepostie(int accountNumber, int money);
	int SetWithdraw(int accountNumber, int money);
	void showAllAccount();

private:
	Account* mAccounts[MAX_ACC_SIZE];
	int mAccountSize = 0;

};

