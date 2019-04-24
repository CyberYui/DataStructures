#include <stdlib.h>
#include <stdio.h>
#include "LinkedStack.h"

//创建带有头结点的空链栈
LinkedStack SetNullStack_Link()
{
	//申请结点空间
	LinkedStack top = (LinkedStack)malloc(sizeof(struct Node));
	if (top != NULL)
	{
		top->next = NULL;	//头结点之后为NULL,因为是空栈
	}
	else
	{
		printf("Alloc failure!\n");
	}
	return top; //返回栈顶指针
}

//判断链栈是否为空
int IsNullStack_link(LinkedStack top)
{
	if (top->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//进栈
void Push_link(LinkedStack top, DataType x)
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node)); //申请结点空间
	if (p == NULL)
	{
		printf("Alloc failure!\n");
	}
	else
	{
		p->data = x;            //数据域赋值
		p->next = top->next;    //指针域赋值
		top->next = p;          //修改栈顶
	}
}

//出栈栈顶元素
void Pop_link(LinkedStack top)
{
	PNode p;
	if (IsNullStack_link(top))
	{
		printf("It is an empty stack!\n");
	}
	else
	{
		p = top->next;          //p指向待删除结点
		top->next = p->next;    //修改栈顶指针
		free(p);                //释放要删除的结点的空间,完成删除
	}
}

//取栈顶元素
DataType Pop_seq_return(LinkedStack top)
{
	//判断栈是否为空
	if (IsNullStack_link(top))
	{
		printf("It is an empty stack!\n");
		return 0;	//因为DataType即是int类型
	}
	else
	{
		return top->next->data;
	}
}