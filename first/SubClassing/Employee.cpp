#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
	cout << "Employee() called" << endl;
}

Employee::Employee(char * str, int n) :sabun(n)
{
	strcpy_s(name, str);
	cout << "Emplyee(int) called" << endl;
}


Employee::~Employee()
{
	cout << "Employee() Destructor" << endl;
}
