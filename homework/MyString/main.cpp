// MyString.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	MyString s1;
	MyString s2("hahaha");
	MyString s3(s2);

	cout << s2 << s3;

	s1 = s2;
	if (s2 == s1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << s1 << s2 << endl;
	}

	s2 += "hoho";
	s3 += s2;

	cout << s2 << s3;

	s1 = s2 + "...";

	cout << s1;

	cin >> s1;

	cout << s1;

    return 0;
}

