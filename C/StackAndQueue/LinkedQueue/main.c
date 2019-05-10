#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

void main()
{
	//创建空链栈,并测试相关函数
	LinkedQueue lqueue = SetNullQueue_Link();
	int data;
	printf("请输入进队的元素,以0结束: ");
	scanf_s("%d", &data);
	while (data)
	{
		EnQueue_Link(lqueue, data);
		scanf_s("%d", &data);
	}
	printf("出队元素的顺序是:");
	while (!IsNullQueue_Link(lqueue))
	{
		printf("%d", FrontQueue_Link(lqueue));
		DeQueue_Link(lqueue);
	}
	printf("\n");
}