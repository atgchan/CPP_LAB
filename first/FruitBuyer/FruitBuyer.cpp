// FruitBuyer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	cout << "내돈: " << myMoney << "사과개수: " << numberOfApples << endl;
}
