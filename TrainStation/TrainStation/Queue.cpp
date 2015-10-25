#include "stdafx.h"
#include "Queue.h"

template <class T>
Queue<T>::Queue(int maxSize)
	:mMaxSize(maxSize), mCurrentSize(0), mFirstPosition(0), mLastPosition(0)
{
}


template <class T>
Queue<T>::~Queue()
{
}

template<class T>
void Queue<T>::enQueue(T* t)
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
T* Queue<T>::deQueue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty!" << endl;
		return nullptr;
	}
	else
	{
		int next = mFirstPosition;
		mCurrentSize--;
		mFirstPosition = nextPosition(mFirstPosition);
		return array[next];
	}
}

template<class T>
bool Queue<T>::isFull()
{
	if (mCurrentSize == mMaxSize)
	{
		return true;
	}
	return false;
}

template<class T>
bool Queue<T>::isEmpty()
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
int Queue<T>::size()
{
	return mCurrentSize;
}

template<class T>
int Queue<T>::nextPosition(int n)
{
	n++;
	if (n > mMaxSize)
	{
		n = 0;
	}
	return n;
}
