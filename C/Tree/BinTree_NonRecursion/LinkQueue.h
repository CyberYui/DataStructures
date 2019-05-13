#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H
#include "BinTreeQueue.h"

typedef BinTreeNode *DataTypeQueue;//这里的类型定义与之前的链队列不同
struct Node
{
	DataTypeQueue data;//数据域
	struct Node *next;//指针域
};
typedef struct Node *PNode;//PNode类型定义

struct Queue
{
	//头结点和尾结点
	PNode f;
	PNode r;
};
typedef struct Queue *LinkQueue;

/****************************************************************/
/* LinkQueue SetNullQueue_Link()								*/
/* 功能:创建空队列												*/
/* 输入参数:无													*/
/* 返回值:空的链队列											*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
LinkQueue SetNullQueue_Link();

/****************************************************************/
/* int IsNullQueue_Link(LinkQueue lqueue)						*/
/* 功能:判断一个链队列是否为空									*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:空队列返回1,否则返回0									*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_Link(LinkQueue lqueue);

/****************************************************************/
/* void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x)			*/
/* 功能:进队													*/
/* 输入参数:lqueue--链队指针	x--进队结点						*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x);

/****************************************************************/
/* void DeQueue_Link(LinkQueue lqueue)							*/
/* 功能:出队													*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_Link(LinkQueue lqueue);

/****************************************************************/
/* DataType FrontQueue_Link(LinkQueue lqueue)					*/
/* 功能:取队头元素的值											*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
DataTypeQueue FrontQueue_Link(LinkQueue lqueue);

#endif // _LINKQUEUE_H
