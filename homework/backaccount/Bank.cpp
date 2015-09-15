#include "stdafx.h"
#include "Bank.h"


Bank::Bank()
{
}

Bank::~Bank()
{
	for (int i = 0; i < mAccountSize; i++)
	{
		delete(mAccounts[i]);
	}
}

void Bank::CreateAccount(int accountNumber, int money, string accountName)
{
	Account *account = new Account(accountNumber, money, accountName);
	mAccounts[mAccountSize] = account;
	mAccountSize++;
}

void Bank::DeleteAccount(int accountNumber)
{
	Account* tmp = FindAccount(accountNumber);
	if (tmp != nullptr)
	{
		delete(tmp);
	}
	else
	{
		cout << "Cannot find the Account to delete" << endl;
	}
}

Account* Bank::FindAccount(int accountNumber)
{
	for (int i = 0; i < mAccountSize; i++)
	{
		if (accountNumber == mAccounts[i]->getAccountNumber())
		{
			return mAccounts[i];
		}
	}

	return nullptr;
}

int Bank::SetDepostie(int accountNumber, int money)
{
	Account* tmp = FindAccount(accountNumber);
	if (tmp != nullptr)
	{
		tmp->Deposite(money);
		return tmp->getMoney();
	}
	else
	{
		cout << "Cannot find the Account to set" << endl;
		return 0;
	}
}

int Bank::SetWithdraw(int accountNumber, int money)
{
	Account* tmp = FindAccount(accountNumber);
	if (tmp != nullptr)
	{
		tmp->Withdraw(money);
		return tmp->getMoney();
	}
	else
	{
		cout << "Cannot find the Account to set" << endl;
		return 0;
	}
}

void Bank::showAllAccount()
{
	for (int i = 0; i < mAccountSize; i++)
	{
		if (mAccounts[i] != nullptr)
		{
			cout << mAccounts[i]->getAccountName() << " : " << mAccounts[i]->getAccountNumber() << " : " << mAccounts[i]->getMoney() << endl;
		}
	}
}
