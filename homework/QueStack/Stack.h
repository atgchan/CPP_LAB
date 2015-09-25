#pragma once

template <class T>
class Stack
{
public:
	Stack(int maxSize);
	~Stack();
	void push(T t);
	T pop();
	bool isFull();
	bool isEmpty();
	int size();

private:
	T* array;
	int mCurrentSize;
	int mMaxSize;
};

