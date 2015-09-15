#include "stdafx.h"
#include "FruitBuyer.h"
#include "FruitSeller.h"

int main()
{
	FruitBuyer buyer;
	buyer.InitMembers(10000);

	FruitSeller seller1;
	seller1.InitMembers(500, 10, 0);

	buyer.BuyApples(seller1, 1000);
	buyer.ShowResult();
	seller1.ShowResult();

	getchar();
}