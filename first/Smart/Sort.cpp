
#include "stdafx.h"

class SortRule
{
public:
	virtual bool operator()(int num1, int num2) = 0;
};

class AscendingSort : public SortRule
{
public:
	bool operator()(int num1, int num2)
	{
		if (num1 > num2)
			return true;
		else
			return false;
	}
};

class DescendingSort : public SortRule
{
public:
	bool operator()(int num1, int num2)
	{
		if (num1 < num2)
			return true;
		else
			return false;
	}
};

class DataStorage
{
private:
	int * arr;
	int idx;
	const int MAX_LEN;
public:
	DataStorage(int count):MAX_LEN(count), idx(0)
	{
		arr = new int[count];
	}

	void AddElement(int num)
	{
		if (idx >= MAX_LEN)
		{
			cout << "Error: Array is full" << endl;
			return;
		}
		arr[idx++] = num;
	}

	void SortElement(SortRule& sr)
	{
		for (int i = 0; i < idx-1; i++)
		{
			for (int j = 0; j < idx - 1; j++)
			{
				if (sr(arr[j], arr[j + 1]))
				{
					int tmp;
					tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
	
	void ShowElement()
	{
		for (int i = 0; i < idx; i++)
		{
			cout << arr[i] << endl;
		}
	}
};

int main(void)
{
	DataStorage ds(10);
	ds.AddElement(3);
	ds.AddElement(6);
	ds.AddElement(10);
	ds.AddElement(1);
	ds.AddElement(50);
	ds.AddElement(3);

	AscendingSort asc;
	DescendingSort dsc;

	ds.SortElement(asc);
	ds.ShowElement();
	ds.SortElement(dsc);
	ds.ShowElement();

}