#include <stdio.h>
#include <stdlib.h>
#include "graphinverselistutil.h"

/****************************************************************/
/* GraphInverseList* InitGraph(int num)							*/
/* 功能:初始化图												*/
/* 输入参数num:图中结点的个数									*/
/* 返回值:用逆邻接表表示的图									*/
/* 创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
GraphInverseList* InitInverseGraph(int num)
{
	int i = 0;
	//首先申请图的空间,分配size,从而获得邻接表数组
	GraphInverseList *graphInverseList = (GraphInverseList *)malloc(sizeof(GraphInverseList));
	graphInverseList->size = num;
	graphInverseList->graphInverseListArray = NULL;
	//按照size的大小申请结点空间,每一个数组位置都保存一个结点
	graphInverseList->graphInverseListArray = (GraphInverseListNode*)malloc(sizeof(GraphInverseListNode)*num);
	//给图中结点内容初始化,数据域按序,权值为0,指针域为空
	for (i = 0; i < num; i++)
	{
		graphInverseList->graphInverseListArray[i].nodeno = -1;
		graphInverseList->graphInverseListArray[i].weight = 0;
		graphInverseList->graphInverseListArray[i].next = NULL;
	}
	return graphInverseList;
}

/****************************************************************/
/* void ReadInverseGraph(GraphInverseList* graphInverseList)	*/
/* 功能:将数据读入图中											*/
/* 输入参数graphInverseList:图									*/
/* 返回值:无													*/
/* 创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void ReadInverseGraph(GraphInverseList* graphInverseList)
{
	int vexBegin = 0;	//起点
	int vexEnd = 0;		//终点
	int weight = 0;		//边上权值
	GraphInverseListNode *tempNode = NULL;	//申请临时结点用于数据传输
	//输入方式为:起点 终点 权值,意思为起点--(权值)-->终点,当点为-1时,输入结束
	printf("请输入内容,输入方式为:起点 终点 边上权值,当点为-1时输入结束:\n");
	scanf_s("%d %d %d", &vexBegin, &vexEnd, &weight);

	while (vexBegin >= 0 && vexEnd >= 0)
	{
		tempNode = (GraphInverseListNode *)malloc(sizeof(GraphInverseListNode));
		tempNode->nodeno = vexBegin;
		tempNode->weight = weight;
		tempNode->next = NULL;

		//寻找需要插入结点的地方,这里为了方便就放在头部
		tempNode->next = graphInverseList->graphInverseListArray[vexEnd].next;
		graphInverseList->graphInverseListArray[vexEnd].next = tempNode;
		scanf_s("%d %d %d", &vexBegin, &vexEnd, &weight);
	}
}

/****************************************************************/
/* void WriteInverseGraph(GraphInverseList *graphInverseList)	*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphInverseList:图									*/
/* 返回值:无													*/
/* 创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void WriteInverseGraph(GraphInverseList *graphInverseList)
{
	int i = 0;
	GraphInverseListNode *tempNode = NULL;	//申请临时结点用于数据传输

	tempNode = (GraphInverseListNode *)malloc(sizeof(GraphInverseListNode));
	tempNode->next = NULL;
	tempNode->weight = 0;
	tempNode->nodeno = 0;

	printf("图的结构如下:\n");
	while (i < graphInverseList->size)	//数组是从0开始算的,但是保存的size=num=输入的值(比如测试的这里是4)
	{
		tempNode = graphInverseList->graphInverseListArray[i].next;
		//循环判断当前的顶点是否有邻接表,如果没有邻接表,则直接看下一个顶点,如此循环,直到找到有邻接表的顶点
		for (int k = 0; k < graphInverseList->size; k++)
		{
			if (!tempNode)
			{
				i++;
				tempNode = graphInverseList->graphInverseListArray[i].next;
			}
			else
				break;
		}
		printf("结点%d与结点%d有边相连,边的权值为%d;\n", i, tempNode->nodeno, tempNode->weight);
		//遍历每一个数组内容的邻接表,全部输出出来
		for (int j = 0; j < graphInverseList->size; j++)
		{
			if (tempNode->next != NULL)
			{
				tempNode = tempNode->next;
				printf("结点%d与结点%d有边相连,边的权值为%d;\n", i, tempNode->nodeno, tempNode->weight);
			}
			else
			{
				break;
			}
		}
		i++;
	}
}