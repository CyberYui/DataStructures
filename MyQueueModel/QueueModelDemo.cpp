#include <iostream>
#include <stdlib.h>
#include "MyQueueModel.h"
#include "CustomerTest.h"
using namespace std;


int main(void)
{
	MyQueue<Customer> *p = new MyQueue<Customer>(4);
	cout << endl;

	Customer cus1 = Customer("Jim", 18);
	Customer cus2 = Customer("Dark", 22);
	Customer cus3 = Customer("CYber", 24);
	Customer cus4 = Customer("Funck", 22);

	p->EnQueue(cus1);
	p->EnQueue(cus2);
	p->EnQueue(cus3);
	p->EnQueue(cus4);

	p->QueueTraverseCus();
	cout << endl;
	Customer cus5 = Customer("", 0);//������ʱ���ݴ洢ɾ��������
	p->DeQueue(cus5);
	p->QueueTraverseCus();
	cout << endl;
	cus5.printInfo();//����ɾ����һ��
	cout << p->QueueLength() << endl;
	cout << endl;
	p->ClearQueue();
	p->QueueTraverseCus();

	delete p;
	p = NULL;


	system("pause");
	return 0;
}

//�ܽ�:һ�������ǿ��Էźܶ������͵����ݵ�,����һ�������ȳ�����ʽ