#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"

//创建空顺序栈
SeqStack SetNullStack_seq(int m)
{
	//定义变量sstack
	SeqStack sstack = (SeqStack)malloc(sizeof(struct SeqStack));
	if (sstack != NULL)
	{
		//申请结构体空间成功,开始申请数组空间
		sstack->elem = (int*)malloc(sizeof(int)*m);
		if (sstack->elem != NULL)
		{
			//申请数组空间成功,开始初始化
			sstack->MAX = m;	//顺序栈最大容量
			sstack->top = -1;	//设置栈顶初值为-1,这样压入元素就会从0开始
			return(sstack);		//返回初始化了的栈
		}
		else
		{
			//申请结构体空间成功,但申请数组空间失败
			free(sstack);//释放结构体空间
			return NULL;
		}
	}
	else
	{
		//申请空间失败
		printf("out of space!");
		return NULL;
	}
}

//判断顺序栈是否为空
int IsNullStack_seq(SeqStack sstack)
{
	return(sstack->top == -1);    //检查栈顶top是否为-1
}

//判断顺序栈是否为满
int IsFullStack_seq(SeqStack sstack)
{
	//检查栈顶是否已经达到了最大值,数组从0数,所以是MAX-1
	return(sstack->top >= sstack->MAX - 1);
}

//进栈
void Push_seq(SeqStack sstack, int x)
{
	//压入x元素进入栈中
	if (IsFullStack_seq(sstack))
	{
		printf("Overflow!\n");
	}
	else
	{
		sstack->top++;                    //若不满,先修改栈顶变量
		sstack->elem[sstack->top] = x;    //把元素x放到栈顶变量的位置中
	}
}

//出栈
void Pop_seq(SeqStack sstack)
{
	//将栈首元素出栈
	if (IsNullStack_seq(sstack))
	{
		//判断栈是否为空,为空则提示
		printf("Underflow!\n");
	}
	else
	{
		//栈非空,出栈栈顶元素,栈顶逻辑-1即可,原内容会被下次入栈给覆盖掉
		sstack->top = sstack->top - 1;    //栈顶减1
	}
}

//取栈顶元素
DataType Top_seq(SeqStack sstack)
{
	if (IsNullStack_seq(sstack))
	{
		//判断栈是否为空,为空则提示
		printf("It is an empty stack!\n");
		return 0;
	}
	else
	{
		return sstack->elem[sstack->top];
	}
}