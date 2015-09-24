// SubClassing.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

