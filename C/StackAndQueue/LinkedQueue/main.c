#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

void main()
{
	//��������ջ,��������غ���
	LinkedQueue lqueue = SetNullQueue_Link();
	int data;
	printf("��������ӵ�Ԫ��,��0����: ");
	scanf_s("%d", &data);
	while (data)
	{
		EnQueue_Link(lqueue, data);
		scanf_s("%d", &data);
	}
	printf("����Ԫ�ص�˳����:");
	while (!IsNullQueue_Link(lqueue))
	{
		printf("%d", FrontQueue_Link(lqueue));
		DeQueue_Link(lqueue);
	}
	printf("\n");
}