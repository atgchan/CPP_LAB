// First.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "First.h"

using namespace std;
int main()
{
	int x = 100;
	int y = 200;

	int &a = x;
	int &b = y;

	int t = a;
	a = b;
	b = t;

	cout << x << b << endl;

	getchar();

    return 0;
}

