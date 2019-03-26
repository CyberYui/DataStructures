#include <iostream>
#include <stdlib.h>
#include "MyQueue.h"
using namespace std;


int main(void)
{
	//创建一个int类型的大小为4的队列
	MyQueue<int> que1(4);
	que1.EnQueue(11);
	que1.EnQueue(12);
	que1.EnQueue(17);
	que1.EnQueue(22);
	que1.QueueTraverse();

	int e = 0;
	que1.DeQueue(e);
	que1.QueueTraverse();

	//创建一个double类型的大小为6的队列
	MyQueue<double> que2(6);
	que2.EnQueue(3.22);
	que2.EnQueue(13.11);
	que2.EnQueue(22.78);
	que2.EnQueue(0.83);
	que2.EnQueue(32.22);
	que2.EnQueue(45.33);
	que2.QueueTraverse();

	system("pause");
	return 0;
}