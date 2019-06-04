//计算一个带权有向图的关键路径

#include <stdio.h>
#include <stdlib.h>
#include "graphlistutil.h"
#include "graphinverselistutil.h"
#include "LinkedStack.h"

/****************************************************************/
/*int eventEarliestTime(GraphList *graphList, int *earliestTime)*/
/*	功能:求事件可能的最早发生时间								*/
/*	输入参数graphList:用邻接表表示的图							*/
/*	输入参数earliestTime:事件可能的最早发生时间					*/
/*	返回值success:1--成功	0--失败								*/
/*	创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
int eventEarliestTime(GraphList *graphList, int *earliestTime)
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
	for (i = 0; i < graphList->size; i++)
	{
		inPoint[i] = 0;
	}

	//循环计算各个顶点的初始入度,修改inPoint数组
	for (i = 0; i < graphList->size; i++)
	{
		//从图中提取顶点
		tempNode = graphList->graphListArray[i].next;

		//检查顶点的邻接表(出边表)
		while (tempNode != NULL)
		{
			//邻接表不为空,则入度加1
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//向后查询
		}
	}

	//首先循环将入度为0的顶点入栈,否则栈会为空直接退出函数
	for (i = 0; i < graphList->size; i++)
	{
		if (inPoint[i] == 0)
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
		//printf("%d ", nodeNum);	//输出顶点,此顶点算拓扑排序完成
		Pop_link(nodeStack);	//完成的顶点出栈
		cnt++;	//计数器+1

		//检查v的出边,将每条出边的终端顶点的入度减1
		//若此时该顶点入度为0,则将其入栈
		tempNode = graphList->graphListArray[nodeNum].next;	//检查
		while (tempNode != NULL)
		{
			//去掉入边
			inPoint[tempNode->nodeno]--;	//出边表中所有相关顶点入度-1
			//为每条出边的终点事件更新可能的最早发生时间
			if (earliestTime[tempNode->nodeno] < earliestTime[nodeNum] + tempNode->weight)
			{
				earliestTime[tempNode->nodeno] = earliestTime[nodeNum] + tempNode->weight;
			}

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
}//O(n+1)

/****************************************************************************/
/*	int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)*/
/*	功能:计算事件允许的最迟发生时间											*/
/*	输入参数graphInverseList:用逆邻接表表示的图								*/
/*	输入参数latestTime:事件允许的最迟发生时间数组							*/
/*	返回值success:1--成功	0--失败											*/
/*	创建日期:2019-6-4									Author:Cyber Kaka	*/
/****************************************************************************/
int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)
{
	int i = 0;	//初始化循环计数器
	int cnt = 0;	//记录拓扑排序中顶点个数的变量
	int nodeNum = 0;	//记录栈顶结点在图中序号的临时变量
	int success = 1;	//排序成功与否的flag

	LinkedStack nodeStack = NULL;	//用于保存从栈中提取的结点内容的临时结点
	GraphInverseListNode *tempNode = NULL;	//用于保存顶点内容的临时结点

	//申请用于保存各个顶点出度的数组空间
	int *outPoint = (int*)malloc(sizeof(int) * graphInverseList->size);
	nodeStack = SetNullStack_Link();	//创建一个空栈

	//初始化inPoint数组,即各个顶点初始出度为0
	for (i = 0; i < graphInverseList->size; i++)
	{
		outPoint[i] = 0;
	}

	//循环计算各个顶点的初始出度,修改outPoint数组
	for (i = 0; i < graphInverseList->size; i++)
	{
		//从图中提取顶点
		tempNode = graphInverseList->graphInverseListArray[i].next;

		//检查顶点的邻接表(出边表)
		while (tempNode != NULL)
		{
			//邻接表不为空,则入度加1
			outPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//向后查询
		}
	}

	//首先循环将出度为0的顶点入栈,否则栈会为空直接退出函数
	for (i = 0; i < graphInverseList->size; i++)
	{
		if (outPoint[i] == 0)
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
		//printf("%d ", nodeNum);	//输出顶点,此顶点算拓扑排序完成
		Pop_link(nodeStack);	//完成的顶点出栈
		cnt++;	//计数器+1

		//检查v的入边,将每条入边的终端顶点的出度减1
		//若此时该顶点出度为0,则将其入栈
		tempNode = graphInverseList->graphInverseListArray[nodeNum].next;	//检查
		while (tempNode != NULL)
		{
			//去掉出边
			outPoint[tempNode->nodeno]--;	//入边表中所有相关顶点出度-1
			//为每条出边的终点事件更新可能的最迟发生时间
			if (latestTime[tempNode->nodeno] < latestTime[nodeNum] + tempNode->weight)
			{
				latestTime[tempNode->nodeno] = latestTime[nodeNum] + tempNode->weight;
			}

			//检查出度是否为0,是0则入栈
			if (outPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//检查下一个顶点出度
			tempNode = tempNode->next;
		}
	}//栈为空时结束循环

	//若图中所有顶点有未拓扑排序的,则代表排序失败
	if (cnt != graphInverseList->size)
	{
		success = 0;
	}

	return success;	//返回flag
}//O(n+1)

/********************************************************************************/
/*	void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)	*/
/*	功能:根据一个图的邻接表和逆邻接表计算关键路径								*/
/*	输入参数graphList:用邻接表表示的图											*/
/*	输入参数graphInverseList:用逆邻接表表示的图									*/
/*	返回值:无																	*/
/*	创建日期:2019-6-4										Author:Cyber Kaka	*/
/********************************************************************************/
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)
{
	int i = 0;	//用于循环体的计数器
	int max = 0;	//用于保存最早发生时间的最大值的临时变量

	//申请最早发生时间数组的空间
	int* earliestTime = (int*)malloc(sizeof(int) * graphList->size);
	//申请最迟发生时间数组的空间
	int* latestTime = (int*)malloc(sizeof(int) * graphInverseList->size);

	int activityEarliestTime = 0;
	int activityLatestTime = 0;

	GraphListNode *tempNode = NULL;

	//初始化所有事件可能的最早发生时间为0
	for (i=0;i<graphList->size;i++)
	{
		earliestTime[i] = 0;
	}

	//调用算法,求每个事件可能的最早发生时间
	eventEarliestTime(graphList, earliestTime);

	//求事件最早发生时间的最大值,方便后面设置事件允许最迟发生时间的初值
	max = earliestTime[0];
	for (i=0;i<graphList->size;i++)
	{
		if (max<earliestTime[i])
		{
			max = earliestTime[i];
		}
	}

	//初始化所有事件允许的最迟发生时间为最大值
	for (i=0;i<graphInverseList->size;i++)
	{
		latestTime[i] = max;
	}

	//调用算法,求每个事件允许的最迟发生时间
	eventLatestTime(graphInverseList, latestTime);

	//初始化任务完成

	//遍历每条边,求每个活动的最早开始时间和最晚开始时间,并进行对比
	//相等即为关键路径上的边,也就是两者时间余量为0
	for (i=0;i<graphList->size;i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while (tempNode != NULL)
		{
			activityEarliestTime = earliestTime[i];
			activityLatestTime = latestTime[tempNode->nodeno] - tempNode->weight;

			if (activityEarliestTime == activityLatestTime)
			{
				printf("<v%2d,v%2d>", i, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}
}//O(n+1)