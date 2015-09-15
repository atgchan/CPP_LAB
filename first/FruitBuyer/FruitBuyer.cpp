// FruitBuyer.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "FruitBuyer.h"

void FruitBuyer::InitMembers(int money)
{
	myMoney = money;
	numberOfApples = 0;
}

void FruitBuyer::BuyApples(FruitSeller& seller, int money)
{
	myMoney -= money;
	numberOfApples += seller.SaleApples(money);
}

void FruitBuyer::ShowResult()
{
	cout << "����: " << myMoney << "�������: " << numberOfApples << endl;
}
