#include "stdafx.h"
#include "MyString.h"


MyString::MyString()
{
	str = new char[1];
	len = 0;
}

MyString::MyString(const char * s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

MyString::MyString(const MyString & s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
}


MyString::~MyString()
{
	delete[] str;
}

MyString & MyString::operator=(const MyString & s)
{
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);

	return *this;
}

MyString & MyString::operator+=(const MyString & s)
{
	len += s.len;
	char* tmp = new char[len + 1];

	strcpy(tmp, str);
	strcat(tmp, s.str);

	delete[] str;
	str = tmp;
	return *this;
}

bool MyString::operator==(const MyString & s)
{
	if (strcmp(str, s.str) == 0)
	{
		return true;
	}
	return false;
}

MyString MyString::operator+(const MyString & s)
{
	char* tmp = new char[len + s.len + 1];

	strcpy(tmp, str);
	strcat(tmp, s.str);

	MyString tmpMyStr(tmp);
	return tmpMyStr;
}

ostream& operator<<(ostream& os, const MyString& s)
{

	cout << s.str << endl;
	return os;
}
istream& operator>>(istream& is, MyString& s)
{
	char tmp[255];
	is >> tmp;
	s += MyString(tmp);
	return is;
}