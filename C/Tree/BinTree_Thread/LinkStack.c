#include <stdlib.h>
#include <stdio.h>
#include "LinkStack.h"

//创建带有头结点的空链栈
LinkStack SetNullStack_Link()
{
	//申请结点空间
	LinkStack lstack = (LinkStack)malloc(sizeof(struct Node));
	if (lstack != NULL)
	{
		lstack->next = NULL;	//头结点之后为NULL,因为是空栈
	}
	else
	{
		printf("Alloc failure!\n");
	}
	return lstack; //返回栈顶指针
}

//判断链栈是否为空
int IsNullStack_Link(LinkStack lstack)
{
	if (lstack->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//进栈
void Push_Link(LinkStack lstack, DataTypeStack x)
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
		p->next = lstack->next;    //指针域赋值
		lstack->next = p;          //修改栈顶
	}
}

//出栈栈顶元素
void Pop_Link(LinkStack lstack)
{
	PNode p;
	if (IsNullStack_Link(lstack))
	{
		printf("It is an empty stack!\n");
	}
	else
	{
		p = lstack->next;          //p指向待删除结点
		lstack->next = p->next;    //修改栈顶指针
		free(p);                //释放要删除的结点的空间,完成删除
	}
}

//取栈顶元素
DataTypeStack Pop_seq_return(LinkStack lstack)
{
	//判断栈是否为空
	if (IsNullStack_Link(lstack))
	{
		printf("It is an empty stack!\n");
		return 0;	//因为DataType即是int类型
	}
	else
	{
		return lstack->next->data;
	}
}