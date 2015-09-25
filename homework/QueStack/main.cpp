// QueStack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Que.cpp"
#include "Stack.cpp"


int main()
{
	Que<int> que(5);

	for (int i = 0; i < 5; i++)
	{
		que.enQueue(i);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << que.deQueue() << endl;
	}

	Stack<int> stack(5);

	for (int i = 0; i < 5; i++)
	{
		stack.push(i);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << stack.pop() << endl;
	}

	getchar();
    return 0;
}

