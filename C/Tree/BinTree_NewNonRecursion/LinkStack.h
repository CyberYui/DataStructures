#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "BinTreeStack.h"
//链栈的类型定义
typedef BinTree DataTypeStack;
struct Node
{
	DataTypeStack data;
	struct Node* next;
};
typedef struct Node *PNode;
typedef struct Node *LinkStack;

/****************************************/
/* 函数功能:创建空链栈					*/
/* 输入参数:无							*/
/* 返回值:空的链栈						*/
/****************************************/
LinkStack SetNullStack_Link();

/****************************************/
/* 函数功能:判断一个链栈是否为空		*/
/* 输入参数:链栈栈顶指针				*/
/* 返回值:若链栈为空则返回1,否则返回0	*/
/****************************************/
int IsNullStack_Link(LinkStack lstack);

/****************************************/
/* 函数功能:进栈						*/
/* 输入参数:lstack--链栈栈顶指针		*/
/* 输入参数:x--进栈元素					*/
/* 返回值:无							*/
/****************************************/
void Push_Link(LinkStack lstack, DataTypeStack x);

/****************************************/
/* 函数功能:出栈栈顶元素				*/
/* 输入参数:lstack--链栈栈顶指针		*/
/* 返回值:无							*/
/****************************************/
void Pop_Link(LinkStack lstack);

/****************************************/
/* 函数功能:取出栈顶元素				*/
/* 输入参数:lstack--链栈栈顶指针		*/
/* 返回值:栈顶元素的值					*/
/****************************************/
DataTypeStack Pop_seq_return(LinkStack lstack);

#endif // LINKSTACK_H
