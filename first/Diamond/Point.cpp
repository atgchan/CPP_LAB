#include "stdafx.h"
#include <iostream>
#include "Point.h"

template <class T>
Point<T>::Point(T x, T y) :xPos(x), yPos(y) 
{
	
}

template <class T>
void Point<T>::ShowPosition() const
{
	cout << "[" << xPos << ", " << yPos << "]" << endl;
}
