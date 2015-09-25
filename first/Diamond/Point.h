#ifndef _POINT_H
#define _POINT_H

#include "stdafx.h"

template<class T>
class Point
{
private:
	T xPos, yPos;

public:
	Point(T x = 0, T y = 0);

	void ShowPosition() const;
};

#endif