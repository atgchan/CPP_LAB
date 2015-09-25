#include "stdafx.h"
#include "BoundCheckArray.h"

template<class T>
BoundCheckArray<T>::BoundCheckArray(int len)
	:arrlen(len)
{
	arr = new T[len];
}

template<class T>
T & BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array Index Out Of Bound Exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<class T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array Index Out Of Bound Exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<class T>
int BoundCheckArray<T>::GetArrayLen() const
{
	return arrlen;
}

template<class T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete []arr;
}
