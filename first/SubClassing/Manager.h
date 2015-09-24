#pragma once
#include "Employee.h"

class Manager : public Employee
{
public:
	Manager();
	Manager(char* name, char* dept, int number);
	~Manager();

private:
	char *department;

public:
	void ShowInfo() {
		Employee::ShowInfo();
		cout << "이름: " << name << endl;
		cout << "부서: " << department << endl;
	}

};

