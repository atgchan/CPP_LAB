// Overloading.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class Point
{
private:
		int xPos, yPos;

public:
	Point(int n1 = 0, int n2 = 0):xPos(n1), yPos(n2)
	{}

	~Point()
	{
		cout << "Destructor Called" << endl;
	}

	void ShowData()
	{
		cout << "[" << xPos << ", " << yPos << "]" << endl;
	}

	Point& operator+(Point& ref)
	{
		Point pos(xPos + ref.xPos, yPos + ref.yPos);

		return pos;
	}

	friend Point& operator+(Point& ref1, Point& ref2);
	friend ostream& operator<<(ostream& os, Point& ref);

	Point& operator++()
	{
		xPos += 1;
		yPos += 1;

		return *this;
	}

	Point& operator++(int)
	{
		Point p(xPos, yPos);
		xPos += 1;
		yPos += 1;

		return p;
	}

	Point& operator=(const Point &ref)
	{
		xPos = ref.xPos;
		yPos = ref.yPos;

		return *this;
	}

	Point& operator+(const Point &ref)
	{
		Point p;
		p.xPos = xPos + ref.xPos;
		p.yPos = yPos + ref.yPos;

		return p;
	}
};

Point& operator+(Point& ref1, Point& ref2)
{
	Point pos(ref1.xPos + ref2.xPos, ref2.yPos + ref2.yPos);
	return pos;
}

ostream& operator<<(ostream& os, Point& ref)
{
	cout << "[" << ref.xPos << ", " << ref.yPos << "]" << endl;
	return os;
}

class SmartPtr
{
private:
	Point* posPtr;
	int refCount;
public:
	SmartPtr():refCount(-1)
	{}

	SmartPtr(Point* ptr):posPtr(ptr), refCount(0)
	{}

	Point* operator->()
	{
		return posPtr;
	}

	Point& operator*()
	{
		return *posPtr;
	}

	SmartPtr& operator=(SmartPtr &ref)
	{
		posPtr = ref.posPtr;
		ref.AddRef();
			
		return *this;
	}

	void AddRef()
	{
		refCount++;
	}

	void release()
	{
		refCount--;
	}

	~SmartPtr()
	{
		cout << refCount << endl;
		if (refCount == 0)
		{
			delete posPtr;
		}
	}
};

//int main()
//{
//	Point *pointPtr = new Point(3, 5);
//	delete pointPtr;
//
//	SmartPtr sptr1(new Point(3, 5));
//	sptr1->ShowData();
//
//	cout << *sptr1;
//
//	SmartPtr sptr2;
//	sptr2 = sptr1;
//
//	sptr1.release();
//}

//int main()
//{
//	Point p1(3, 5);
//	Point p2(5, 7);
//
//	Point p3 = p1.operator+(p2);
//	Point p4 = operator+(p1, p2);
//
//	p1.ShowData();
//	p2.ShowData();
//	p3.ShowData();
//
//	++p1;
//	p1.ShowData();
//
//	Point p5 = p1++;
//	p5.ShowData(); // 4, 6
//	p1.ShowData(); // 5, 7
//
//	cout << "!!" << p1 << p2;
//
//	getchar();
//    return 0;
//}

class Adder
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}

	double operator()(double num1, double num2)
	{
		return num1 + num2;
	}



	Point& operator()(Point& p1, const Point& p2)
	{
		return p1 + p2;
	}
};

int main()
{
	Adder adder;
	int i = adder(1, 3);
	cout << i << endl;

	double d = adder(1.0, 4.3);
	cout << d << endl;

	Point p = adder(Point(1, 2), Point(4, 5));
	cout << p << endl;
}