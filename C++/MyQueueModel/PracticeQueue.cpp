#include <iostream>
#include <stdlib.h>
#include "MyQueue.h"
using namespace std;


int main(void)
{
	//����һ��int���͵Ĵ�СΪ4�Ķ���
	MyQueue<int> que1(4);
	que1.EnQueue(11);
	que1.EnQueue(12);
	que1.EnQueue(17);
	que1.EnQueue(22);
	que1.QueueTraverse();

	int e = 0;
	que1.DeQueue(e);
	que1.QueueTraverse();

	//����һ��double���͵Ĵ�СΪ6�Ķ���
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