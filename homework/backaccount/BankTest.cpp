// backaccount.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Bank.h"

int main()
{
	Bank bank;
	bank.CreateAccount(1234, 10000, "acc1");
	bank.CreateAccount(1235, 20000, "acc2");
	bank.CreateAccount(1236, 30000, "acc3");

	bank.showAllAccount();

	bank.FindAccount(1234)->Deposite(1000);
	bank.FindAccount(1235)->Withdraw(1000);
	bank.FindAccount(1236)->Deposite(10000);

	bank.showAllAccount();

	getchar();
	return 0;
}
