#include "stdafx.h"
#include "Manager.h"


Manager::Manager()
{
	cout << "Manager() called" << endl;
}

Manager::Manager(char * name, char * dept, int number): Employee(name, number)
{
	int len = strlen(dept) + 1;
	department = new char[len];
	strcpy_s(department, len, dept);
}


Manager::~Manager()
{
	cout << "manager dddd" << endl;
}
