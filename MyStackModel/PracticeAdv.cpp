#include <iostream>
#include <stdlib.h>
#include "MyStackAdv.h"
using namespace std;

int main(void)
{
	//���캯����MyStack(int size)
	MyStack *pStack = new MyStack(5);//�Ӷ����������

	//�������Ͷ���ջ��
	pStack->push(Coordinate(1, 2));//��
	pStack->push(Coordinate(3, 4));
	pStack->push(Coordinate(5, 6));
	pStack->push(Coordinate(7, 8));
	pStack->push(Coordinate(9, 10));//��

	pStack->stackTraverse(true);
	cout << endl;
	pStack->stackTraverse(false);

	pStack->stackLength();


	//�Ƴ�ָ��,�ͷ��ڴ�ռ�
	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}