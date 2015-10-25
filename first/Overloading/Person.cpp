#include "stdafx.h"

class Person
{
private:
	char* name;
	int age;

public:
	Person(char* name_s, int iage):age(iage)
	{
		int len = strlen(name_s) + 1;
		name = new char[len];
		strcpy(name, name_s);
	}

	~Person()
	{
		delete[] name;
	}

	Person& operator=(const Person& pref)
	{
		delete[] name;
		int len = strlen(pref.name) + 1;
		name = new char[len];
		strcpy(name, pref.name);
		age = pref.age;

		return *this;
	}

	friend ostream& operator<<(ostream& os, Person& p);
};

ostream& operator<<(ostream& os, Person& p)
{
	cout << p.name << endl;
	cout << p.age << endl;

	return os;
}

//int main(void)
//{
//	Person p1("James", 20);
//	Person p2("Tomas", 30);
//	p2 = p1;
//	cout << p1 << p2;
//
//	getchar();
//	return 0;
//}
