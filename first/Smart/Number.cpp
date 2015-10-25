#include "stdafx.h"
class Number
{
private:
	int num;
public:
	Number(int n) : num(n)
	{}

	Number* operator->()
	{
		return this;
	}

	Number& operator*()
	{
		return *this;
	}

	int GetNumber() const
	{
		return num;
	}
};

//int main(void)
//{
//	Number num1(3);
//	int i = num1->GetNumber();
//
//	cout << i << endl;
//}

