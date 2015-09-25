#include "stdafx.h"
#include "Que.h"

template <class T>
Que<T>::Que(int maxSize)
	:mMaxSize(maxSize), mCurrentSize(0)
{
	array = new T[maxSize];
}


template <class T>
Que<T>::~Que()
{
	delete[] array;
}

template<class T>
void Que<T>::enQueue(T t)
{
	if (isFull())
	{
		cout << "Queue is Full!" << endl;
	}
	else
	{
		array[mLastPosition] = t;
		mLastPosition = nextPosition(mLastPosition);
		mCurrentSize++;
	}
}

template<class T>
T Que<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty!" << endl;
		return NULL;
	}
	else
	{
		T next = mFirstPosition;
		mCurrentSize--;
		mFirstPosition = nextPosition(mFirstPosition);
		return array[next];
	}
}

template<class T>
bool Que<T>::isFull()
{
	if (mCurrentSize == mMaxSize)
	{
		return true;
	}
	return false;
}

template<class T>
bool Que<T>::isEmpty()
{
	if (mCurrentSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
int Que<T>::size()
{
	return mCurrentSize;
}

template<class T>
int Que<T>::nextPosition(int n)
{
	n++;
	if (n > mMaxSize)
	{
		n = 0;
	}
	return n;
}
