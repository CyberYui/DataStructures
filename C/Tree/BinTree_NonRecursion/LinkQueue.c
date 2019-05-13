#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/****************************************************************/
/* LinkQueue SetNullQueue_Link()								*/
/* 功能:创建空队列												*/
/* 输入参数:无													*/
/* 返回值:空的链队列											*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
LinkQueue SetNullQueue_Link()
{
	LinkQueue lqueue;
	lqueue = (LinkQueue)malloc(sizeof(struct Queue));
	if (lqueue != NULL)
	{
		lqueue->f = NULL;
		lqueue->r = NULL;
	}
	else
	{
		printf("Alloc Failure!\n");
	}
	return lqueue;
}

/****************************************************************/
/* int IsNullQueue_Link(LinkQueue lqueue)						*/
/* 功能:判断一个链队列是否为空									*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:空队列返回1,否则返回0									*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_Link(LinkQueue lqueue)
{
	return(lqueue->f == NULL);
}

/****************************************************************/
/* void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x)			*/
/* 功能:进队													*/
/* 输入参数:lqueue--链队指针	x--进队结点						*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x)
{
	PNode p;//临时结点
	p = (PNode)malloc(sizeof(struct Node));
	//申请失败则报错
	if (p == NULL)
	{
		printf("Alloc Failure!\n");
	}
	//申请成功
	else
	{
		//定义临时结点的数据域和指针域,用于存放内容
		p->data = x;
		p->next = NULL;
		//判断队列是否非空
		if (lqueue->f == NULL)
		{
			lqueue->f = p;
			lqueue->r = p;
		}
		else
		{
			lqueue->r->next = p;
			lqueue->r = p;
		}
	}
}

/****************************************************************/
/* void DeQueue_Link(LinkQueue lqueue)							*/
/* 功能:出队													*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_Link(LinkQueue lqueue)
{
	//出队会涉及到队头的操作

	struct Node *p;//临时结点指针,用于观测数据
	//首先判断队列是否为空
	if (lqueue->f == NULL)
	{
		printf("It is an empty queue!\n");
	}
	else
	{
		p = lqueue->f;
		lqueue->f = lqueue->f->next;
		//释放临时结点指针
		free(p);
	}
}

/****************************************************************/
/* DataTypeQueue FrontQueue_Link(LinkQueue lqueue)				*/
/* 功能:取队头元素的值											*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
DataTypeQueue FrontQueue_Link(LinkQueue lqueue)
{
	if (lqueue->f == NULL)
	{
		printf("It is an empty queue!\n");
		return 0;
	}
	else
		return(lqueue->f->data);
}