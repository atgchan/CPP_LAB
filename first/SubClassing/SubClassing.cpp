// SubClassing.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Employee.h"
#include "Manager.h"

int main()
{
	Employee *e = new Manager("Lee", "Personal", 100);
	e->ShowInfo();

	delete(e);

	getchar();
    return 0;
}

