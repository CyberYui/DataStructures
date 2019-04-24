#include <stdlib.h>
#include <stdio.h>
#include "LinkedStack.h"

//对链栈的所有基本算法进行测试
//要求输入一个序列,通过链栈实现序列反转
void main()
{
	LinkedStack p = SetNullStack_Link();//创建一个空链栈
	int data = 0;
	printf("请输入进栈的元素,以0结束:");
	scanf_s("%d", &data);
	while (data)
	{
		Push_link(p, data);	//进栈
		scanf_s("%d", &data);
	}
	printf("出栈元素的顺序是:");
	while (!IsNullStack_link(p))
	{
		printf("%d ", Pop_seq_return(p));
		Pop_link(p);
	}
	printf("\n");
}