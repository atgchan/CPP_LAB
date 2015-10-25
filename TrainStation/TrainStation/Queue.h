#pragma once

template <class T>
class Queue
{
public:
	Queue(int maxSize);
	~Queue();
	void enQueue(T* t);
	T* deQueue();
	bool isFull();
	bool isEmpty();
	int size();
	int nextPosition(int n);
	
	T* get(int i)
	{
		if (i >= mCurrentSize)
		{
			return nullptr;
		}
		else
		{
			int tmp = mFirstPosition;
			for (int j = 0; j < i; j++)
			{
				tmp = nextPosition(tmp);
			}
			return array[tmp];
		}
	}

private:
	T* array[100];
	int mFirstPosition;
	int mLastPosition;
	int mCurrentSize;
	int mMaxSize;
};

