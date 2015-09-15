#pragma once

namespace MyStd
{
	template<typename T>
	class MyList
	{
	public:
		class Node
		{
			T mData;
			Node* mNext;
			Node* mPrev;
		};
		
		class Iterator
		{
			Node* mNode;
		};

		MyList()
		{
			mHead = new Node();
			mTail = new Node();
			mHead->mNext = mTail;
			mHead->mPrev = nullptr;
			mTail->mPrev = mHead;
			mTail->mNext = nullptr;
		};
		~MyList()
		{

		};

		void push_back(T newValue)
		{
			Node * newNode = new Node();
			Node * prevNode = mTail->mPrev;
			prevNode->mNext = newNode;
			mTail->mPrev = newNode;
			newNode->mPrev = prevNode;
			newNode->mNext = mTail;
		}

		void pop()
		{
			Node* popNode = mHead->mNext;
			mHead->mNext = popNode->mNext;
			popNode->mPrev = mHead;
			delete popNode;
		}
		
	private:
		Node mHead;
		Node mTail;
	};
}

