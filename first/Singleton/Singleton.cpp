// Singleton.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance()
	{
		if (s == NULL)
			s = new Singleton();
		return s;
	}
	void ShowInfo()
	{
		cout << this << endl;
	}

private:
	static Singleton* s;
	Singleton(){}
};

Singleton* Singleton::s = new Singleton();

int main()
{
	Singleton* instance1 = Singleton::getInstance();
	Singleton* instance2 = Singleton::getInstance();

	instance1->ShowInfo();
	instance2->ShowInfo();

	getchar();
    return 0;
}

