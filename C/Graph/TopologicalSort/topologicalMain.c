#include <stdio.h>
#include <stdlib.h>

#include "graphlistutil.h"
#include "LinkedStack.h"

/****************************************************************/
/* int topologicalsort(GraphList *graphList)					*/
/* 功能:拓扑排序一个图											*/
/* 输入参数graphList:邻接表表示的图								*/
/* 返回值:1--成功	0--失败										*/
/* 创建日期:2019-6-3						Author:Cyber Kaka	*/
/****************************************************************/
int topologicalsort(GraphList *graphList)
{
	int i = 0;	//初始化循环计数器
	int cnt = 0;	//记录拓扑排序中顶点个数的变量
	int nodeNum = 0;	//记录栈顶结点在图中序号的临时变量
	int success = 1;	//排序成功与否的flag

	LinkedStack nodeStack = NULL;	//用于保存从栈中提取的结点内容的临时结点
	GraphListNode *tempNode = NULL;	//用于保存顶点内容的临时结点

	//申请用于保存各个顶点入度的数组空间
	int *inPoint = (int*)malloc(sizeof(int) * graphList->size);
	nodeStack = SetNullStack_Link();	//创建一个空栈

	//初始化inPoint数组,即各个顶点初始入度为0
	for (i = 0;i<graphList->size;i++)
	{
		inPoint[i] = 0;
	}

	//循环计算各个顶点的初始入度,修改inPoint数组
	for (i = 0; i < graphList->size; i++)
	{
		//从图中提取顶点
		tempNode = graphList->graphListArray[i].next;

		//检查顶点的邻接表(出边表)
		while (tempNode!=NULL)
		{
			//邻接表不为空,则入度加1
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//向后查询
		}
	}

	//首先循环将入度为0的顶点入栈,否则栈会为空直接退出函数
	for (i=0;i<graphList->size;i++)
	{
		if (inPoint[i]==0)
		{
			Push_link(nodeStack, i);
		}
	}

	//[Core]如果记录结点的栈不为空
	cnt = 0;	//初始时拓扑排序好的顶点数为0
	while (!IsNullStack_link(nodeStack))
	{
		//取栈顶元素v
		nodeNum = Pop_seq_return(nodeStack);
		printf("%d ", nodeNum);	//输出顶点,此顶点算拓扑排序完成
		Pop_link(nodeStack);	//完成的顶点出栈
		cnt++;	//计数器+1

		//检查v的出边,将每条出边的终端顶点的入度减1
		//若此时该顶点入度为0,则将其入栈
		tempNode = graphList->graphListArray[nodeNum].next;	//检查
		while (tempNode != NULL)
		{
			inPoint[tempNode->nodeno]--;	//出边表中所有相关顶点入度-1
			//检查入度是否为0,是0则入栈
			if (inPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//检查下一个顶点入度
			tempNode = tempNode->next;
		}
	}//栈为空时结束循环

	//若图中所有顶点有未拓扑排序的,则代表排序失败
	if (cnt != graphList->size)
	{
		success = 0;
	}

	return success;	//返回flag
}

//主程序
/*
0 1
0 2
0 3
1 2
1 4
1 5
2 5
4 5
5 3
-1 -1
//图的具体图像参照本目录下的Graph_6.png文件
*/
int main()
{
	GraphList *graphList = InitGraph(6);
	int result = 0;

	ReadGraph(graphList);
	WriteGraph(graphList);

	result = topologicalsort(graphList);
	if (result == 1)
	{
		printf("拓扑排序成功\n");
	}
	else
	{
		printf("拓扑排序失败\n");
	}

	return 0;
}