#pragma once
class Employee
{
public:
	Employee();
	Employee(char *str, int n);
	virtual ~Employee();

protected:
	char name[100];
	int sabun;

public:
	int num;

	virtual void ShowInfo()
	{
		cout << "�̸�: " << name << endl;
		cout << "���: " << sabun << endl;
	}

};

