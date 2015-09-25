#include "stdafx.h"
#include "Stack.h"

template <class T>
Stack<T>::Stack(int maxSize)
	:mMaxSize(maxSize), mCurrentSize(0)
{
	array = new T[maxSize];
}


template <class T>
Stack<T>::~Stack()
{
	delete[] array;
}

template<class T>
void Stack<T>::push(T t)
{
	if (isFull()) {
		cout << "Stack is Full!" << endl;
	}
	else
	{
		array[mCurrentSize] = t;
		mCurrentSize++;
	}
}

template<class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is Empty!" << endl;
		return NULL;
	}
	else
	{
		mCurrentSize--;
		return array[mCurrentSize];
	}
}

template<class T>
bool Stack<T>::isFull()
{
	if (mCurrentSize == mMaxSize)
	{
		return true;
	}
	return false;
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (mCurrentSize == 0)
	{
		return true;
	}
	return false;
}

template<class T>
int Stack<T>::size()
{
	return mCurrentSize;
}
