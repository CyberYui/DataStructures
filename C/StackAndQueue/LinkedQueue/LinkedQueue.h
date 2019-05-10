#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

typedef int DataType;
struct Node
{
	DataType data;//数据域
	struct Node *next;//指针域
};
typedef struct Node *PNode;//PNode类型定义

struct Queue
{
	//头结点和尾结点
	PNode f;
	PNode r;
};
typedef struct Queue *LinkedQueue;

/****************************************************************/
/* LinkedQueue SetNullQueue_Link()								*/
/* 功能:创建空队列												*/
/* 输入参数:无													*/
/* 返回值:空的链队列											*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
LinkedQueue SetNullQueue_Link();

/****************************************************************/
/* int IsNullQueue_Link(LinkedQueue lqueue)						*/
/* 功能:判断一个链队列是否为空									*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:空队列返回1,否则返回0									*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_Link(LinkedQueue lqueue);

/****************************************************************/
/* void EnQueue_Link(LinkedQueue lqueue, DataType x)			*/
/* 功能:进队													*/
/* 输入参数:lqueue--链队指针	x--进队元素						*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_Link(LinkedQueue lqueue, DataType x);

/****************************************************************/
/* void DeQueue_Link(LinkedQueue lqueue)						*/
/* 功能:出队													*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_Link(LinkedQueue lqueue);

/****************************************************************/
/* DataType FrontQueue_Link(LinkedQueue lqueue)					*/
/* 功能:取队头元素的值											*/
/* 输入参数:lqueue--链队指针									*/
/* 返回值:无													*/
/* 创建日期:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
DataType FrontQueue_Link(LinkedQueue lqueue);

#endif // LINKEDQUEUE_H
