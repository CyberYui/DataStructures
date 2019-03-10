#include <iostream>
#include <stdlib.h>
#include "MyStackBasic.h"
using namespace std;

int main(void)
{
	//���캯����MyStack(int size)
	MyStack *pStack = new MyStack(5);//�Ӷ����������
	//���stackEmpty()�����Ƿ����
	if (pStack->stackEmpty())
	{
		cout << "ջΪ��!" << endl;
	}
	//���stackFull()�����Ƿ����
	if (pStack->stackFull())
	{
		cout << "ջΪ��!" << endl;
	}

	//���ջ����
	cout << pStack->stackLength() << endl;
	//����Ԫ��,�ڵ�һ��Ԫ����ջʱ���ջ����
	pStack->push('A');//��
	cout << pStack->stackLength() << endl;
	pStack->push('B');
	pStack->push('C');
	pStack->push('D');
	pStack->push('E');//��
	//�ٴμ���ջ�Ƿ�Ϊ��
	if (pStack->stackFull())
	{
		cout << "ջΪ��!" << endl;
	}
	//����ջԪ��
	pStack->stackTraverse();
	//���ջ
	pStack->clearStack();
	//�ٴ����ջ����
	cout << pStack->stackLength() << endl;
	//�ٴα���
	pStack->stackTraverse();
	//��������Ԫ��
	pStack->push('F');
	pStack->push('G');
	pStack->push('H');
	pStack->push('I');
	pStack->push('J');
	//�����Ƴ�Ԫ�غ����Ƿ����
	char elem = 0;
	pStack->pop(elem);
	cout << elem << endl;
	cout << pStack->stackLength() << endl;
	//����ջ
	pStack->stackTraverse();
	//���ջ
	pStack->clearStack();
	//�Ƴ�ָ��,�ͷ��ڴ�ռ�
	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}