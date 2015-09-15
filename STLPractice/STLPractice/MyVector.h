#pragma once

namespace MyStd
{
	template<typename T>
	class MyVector
	{
	public:
		MyVector() 
			:mDatas(nullptr), mCapacity(INITIAL_CAPACITY), mSize(0)
		{
			mDatas = new T[mCapacity]; //(T*)malloc(sizeof(T)*mCapacity);

		};
		~MyVector() 
		{
			if (mDatas != nullptr)
			{
				delete[] mDatas;
				mDatas = nullptr;
			}
		};

		void push_back(T newValue)
		{
			if (mSize == mCapacity)
			{
				EnlargeCapacity();
			}
			mDatas[mSize++] = newValue;
		}

		void clear()
		{
			mSize = 0;
		}

		int size()
		{
			return mSize;
		}

		T& operator[](size_t index)
		{
			assert(index < mSize);
			return mDatas[index];
		}

	private:
		void EnlargeCapacity()
		{
			mCapacity = (mCapacity + 1) * 2;
			T* newDatas = new T[mCapacity];
			
			if (mDatas != nullptr)
			{
				for (size_t i = 0; i < mCapacity; i++)
				{
					newDatas[i] = mDatas[i];
				}
				delete[] mDatas;
				mDatas = newDatas;
			}
		}

	private:
		T*		mDatas;
		size_t	mCapacity;
		size_t	mSize;
		static const int INITIAL_CAPACITY = 10;
	};
}

