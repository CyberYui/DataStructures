#include <iostream>
#include <stdlib.h>
#include "MyQueueAdv.h"
#include "CustomerBasic.h"
using namespace std;


int main(void)
{
	MyQueue *p = new MyQueue(4);
	Customer c1("Jim", 15);
	Customer c2("Brown", 25);
	Customer c3("Cyber", 24);
	Customer c4("Wanghe", 45);

	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);
	p->EnQueue(c4);
	p->QueueTraverseCus();

	Customer c5("", 0);
	p->DeQueue(c5);
	c5.printInfo();
	p->QueueTraverseCus();

	system("pause");

	return 0;
}