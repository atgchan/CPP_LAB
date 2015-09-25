#pragma once

template <class T>
class Que
{
public:
	Que(int maxSize);
	~Que();
	void enQueue(T t);
	T deQueue();
	bool isFull();
	bool isEmpty();
	int size();
	int nextPosition(int n);

private:
	T* array;
	int mFirstPosition;
	int mLastPosition;
	int mCurrentSize;
	int mMaxSize;
};

