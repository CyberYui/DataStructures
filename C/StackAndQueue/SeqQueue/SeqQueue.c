#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

/****************************************************************/
/* SeqQueue SetNullQueue_seq(int m)								*/
/* 功能:创建空的循环队列										*/
/* 输入参数:无													*/
/* 返回值:空的循环队列											*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
SeqQueue SetNullQueue_seq(int m)
{
	SeqQueue squeue;
	squeue = (SeqQueue)malloc(sizeof(struct Queue));
	//如果申请失败则报错
	if (squeue == NULL)
	{
		printf("Alloc failure\n");
		return NULL;
	}
	//申请空间成功,申请m个元素空间
	squeue->elem = (int*)malloc(sizeof(DataType)*m);
	//创建空队列
	if (squeue->elem != NULL)
	{
		squeue->MAX = m;
		squeue->f = 0;
		squeue->r = 0;
		return squeue;
	}
	//如果都没有用,就直接返回空
	return NULL;
}

/****************************************************************/
/* int IsNullQueue_seq(SeqQueue squeue)							*/
/* 功能:判断一个循环队列是否为空								*/
/* 输入参数:squeue--循环队列指针								*/
/* 返回值:空队列返回1,否则返回0									*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_seq(SeqQueue squeue)
{
	//队头队尾重合则为空,注意循环队列的判空和判满的区别
	return(squeue->f == squeue->r);
}

/****************************************************************/
/* void EnQueue_seq(SeqQueue squeue, DataType x)				*/
/* 功能:进队													*/
/* 输入参数:squeue--循环队列指针	x--进队元素					*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_seq(SeqQueue squeue, DataType x)
{
	//首先判断是否为满队列,注意这里放弃了一格内存空间
	//也就是说如果你要一个5格的循环队列,max=6才对
	//否则你输入1 2 3 4 5的时候只会出队1 2 3 4
	if ((squeue->r + 1) % squeue->MAX == squeue->f)
	{
		printf("It is a full queue!\n");
	}
	else
	{
		squeue->elem[squeue->r] = x;
		squeue->r = (squeue->r + 1) % (squeue->MAX);
	}
}

/****************************************************************/
/* void DeQueue_seq(SeqQueue squeue)							*/
/* 功能:出队													*/
/* 输入参数:squeue--循环队列指针								*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_seq(SeqQueue squeue)
{
	//出队时首先判空,判空可以通过调用函数实现
	//if (squeue->f == squeue->r)
	//{
	//	printf("It is an empty queue!\n");
	//}
	if (IsNullQueue_seq(squeue))
	{
		printf("It is an empty queue!\n");
	}
	else
	{
		squeue->f = (squeue->f + 1) % (squeue->MAX);
	}
}

/****************************************************************/
/* DataType FrontQueue_seq(SeqQueue squeue)						*/
/* 功能:求队头元素的值											*/
/* 输入参数:squeue--循环队列指针								*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
DataType FrontQueue_seq(SeqQueue squeue)
{
	//取元素的时候先判空
	if (squeue->f == squeue->r)
	{
		printf("It is an empty queue!\n");
	}
	else
	{
		return(squeue->elem[squeue->f]);
	}
}