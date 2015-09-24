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
		cout << "�̸�: " << name << endl;
		cout << "�μ�: " << department << endl;
	}

};

