#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"

//对顺序栈的所有基本算法进行测试
//按要求输入一个序列,通过栈实现序列反转

void main()
{
	SeqStack p = SetNullStack_seq(5);	//创建一个空栈p
	int data = 0;
	printf("请输入进栈的元素,以0结束:");
	scanf_s("%d", &data);
	//以0结束的原因是判断时0视为否,会跳出循环
	while (data)
	{
		Push_seq(p, data);	//输入内容进栈
		scanf_s("%d", &data);
	}
	printf("出栈元素的顺序是:");
	//打印顺序栈
	while (!IsNullStack_seq(p))
	{
		printf("%d ", Top_seq(p));	//取栈顶元素
		Pop_seq(p);	//出栈
	}
	//先取再出的原因是,如果不将栈顶出栈,是无法读取到后面的数的,只有栈顶出栈,才会有新的栈顶
	printf("\n");
}