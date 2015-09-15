#include "stdafx.h"
#include "FruitSeller.h"


FruitSeller::FruitSeller()
{
}


FruitSeller::~FruitSeller()
{
}

void FruitSeller::InitMembers(int price, int num, int money)
{
	APPLE_PRICE = price;
	numberOfApples = num;
	myMoney = money;
}

int FruitSeller::SaleApples(int money)
{	
	myMoney += money;
	numberOfApples -= money / APPLE_PRICE;
	return money / APPLE_PRICE;
}

void FruitSeller::ShowResult()
{
	cout << "내돈: " << myMoney << "사과개수: " << numberOfApples << endl;
}
