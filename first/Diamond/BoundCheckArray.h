#pragma once

template<class T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;

public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrayLen() const;

	~BoundCheckArray();
};

