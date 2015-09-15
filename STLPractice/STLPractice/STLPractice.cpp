// STLPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include "MyVector.h"
#include <list>
#include "MyList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> intVector;
	intVector.push_back(2);
	int value = intVector[0];
	intVector[0] = 1;

	MyStd::MyVector<char> myVector;
	myVector.push_back('a');
	char data = myVector[0];
	printf("%c", data);
	myVector[0] = 'b';
	printf("%c", myVector[0]);

	std::list<int> intList;
	intList.push_front(3);
	intList.push_back(6);
	printf("\n %d \n", *(intList.begin()));

	MyStd::MyList<int> myList;
	myList.push_front(3);

	getchar();
	return 0;
}

