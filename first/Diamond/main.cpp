#include "stdafx.h"
#include "Point.cpp"
#include "BoundCheckArray.h"
#include "BoundCheckArray.cpp"

int main()
{
	BoundCheckArray<int> iarr(10);

	for (int i = 0; i < iarr.GetArrayLen(); i++)
	{
		iarr[i] = (i + 1);
	}

	for (int i = 0; i < iarr.GetArrayLen(); i++)
	{
		cout << iarr[i] << endl;
	}

	//BoundCheckArray<Point<int>> ptrArr(3);

	getchar();
	return 0;
}
