//对循环队列的内容进行测试
//输入一个队列,出队一个元素,再输出元素
#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

void main()
{
	SeqQueue squeue = SetNullQueue_seq(5);//创建空队列
	int data;
	printf("请输入进队的元素,以0结束: ");
	scanf_s("%d", &data);
	//循环入队,注意这里并没有判断个数,当输入过量时会直接报错
	while (data)
	{
		//当data=0时跳出循环,否则会一直进行循环
		EnQueue_seq(squeue, data);//进队
		scanf_s("%d,", &data);
	}
	printf("出队元素的顺序是: ");
	while (!IsNullQueue_seq(squeue))
	{
		printf("%d", FrontQueue_seq(squeue));//输出队头元素
		DeQueue_seq(squeue);//输出一个就出队一个
	}
	printf("\n");
}