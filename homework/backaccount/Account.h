#pragma once
class Account
{
public:
	Account(int accountNumber, int money, string accountName);
	~Account();

public:
	int Deposite(int money);
	int Withdraw(int money);
	int getAccountNumber() { return mAccountNumber; }
	int getMoney() { return mBalance; }
	string getAccountName() { return mAccountName; }

private:
	string mAccountName;
	int mAccountNumber;
	int mBalance;
};

