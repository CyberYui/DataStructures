#include <iostream>
#include <stdlib.h>
#include "MyQueueBasic.h"
using namespace std;


int main(void)
{
	MyQueue *p = new MyQueue(4);

	p->EnQueue(11);
	p->EnQueue(12);
	p->EnQueue(17);
	p->EnQueue(22);
	p->EnQueue(20);
	p->QueueTraverse();

	int e = 0;
	p->DeQueue(e);
	cout << "取出的值为" << e << endl;

	p->DeQueue(e);
	cout << "取出的值为" << e << endl;

	p->QueueTraverse();
	p->ClearQueue();
	p->QueueTraverse();

	p->EnQueue(20);
	p->EnQueue(30);
	p->QueueTraverse();

	delete p;
	p = NULL;

	system("pause");
	return 0;
}