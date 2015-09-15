#pragma once

class FruitSeller
{
public:
	FruitSeller();
	~FruitSeller();

private:
	int APPLE_PRICE;
	int numberOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money);
	int SaleApples(int money);
	void ShowResult();
};

