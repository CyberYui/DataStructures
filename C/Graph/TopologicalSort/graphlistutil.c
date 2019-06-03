#include <stdio.h>
#include <stdlib.h>
#include "graphlistutil.h"

/****************************************************************/
/* GraphList* InitGraph(int num)								*/
/* 功能:初始化图												*/
/* 输入参数num:图中结点的个数									*/
/* 返回值:用邻接表表示的图										*/
/* 创建日期:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
GraphList* InitGraph(int num)
{
	int i = 0;
	//首先申请图的空间,分配size,从而获得邻接表数组
	GraphList *graphList = (GraphList *)malloc(sizeof(GraphList));
	graphList->size = num;
	graphList->graphListArray = NULL;
	//按照size的大小申请结点空间,每一个数组位置都保存一个结点
	graphList->graphListArray = (GraphListNode*)malloc(sizeof(GraphListNode)*num);
	//给图中结点内容初始化,数据域按序,指针域为空
	for (i = 0; i < num; i++)
	{
		graphList->graphListArray[i].nodeno = -1;
		graphList->graphListArray[i].next = NULL;
	}
	return graphList;
}

/****************************************************************/
/* void ReadGraph(GraphList* graphList)							*/
/* 功能:将数据读入图中											*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphList* graphList)
{
	int vex1 = 0;	//起点
	int vex2 = 0;	//终点
	GraphListNode *tempNode = NULL;	//申请临时结点用于数据传输
	//输入方式为:点 点,意思为点->点,当点为-1时,输入结束
	printf("请输入内容,输入方式为:点 点,当点为-1时输入结束:\n");
	scanf_s("%d %d", &vex1, &vex2);
	//只要有一个值为-1循环就结束
	while (vex1 >= 0 && vex2 >= 0)
	{
		//插入结点的内容
		tempNode = (GraphListNode*)malloc(sizeof(GraphListNode));	//给临时结点申请空间
		tempNode->nodeno = vex2;
		tempNode->next = NULL;

		//插入相应结点,在头部插入结点,仅仅是为了方便,并不是必须的
		//将原数组内容的next赋给新结点,新结点变成邻接表第一个结点
		tempNode->next = graphList->graphListArray[vex1].next;
		//修改原数组内容的next,连接新的邻接表,从而实现tempNode的插入
		graphList->graphListArray[vex1].next = tempNode;
		scanf_s("%d %d", &vex1, &vex2);
	}
}

/****************************************************************/
/* void WriteGraph(GraphList* graphList)						*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-6-3						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphList* graphList)
{
	int i = 0;
	GraphListNode *tempNode = NULL;	//申请临时结点用于数据传输

	tempNode = (GraphListNode *)malloc(sizeof(GraphListNode));
	tempNode->next = NULL;
	tempNode->nodeno = 0;

	printf("图的结构如下:\n");
	while (i < graphList->size)	//数组是从0开始算的,但是保存的size=num=输入的值(比如测试的这里是4)
	{
		tempNode = graphList->graphListArray[i].next;
		//循环判断当前的顶点是否有邻接表,如果没有邻接表,则直接看下一个顶点,如此循环,直到找到有邻接表的顶点
		for (int k = 0; k < graphList->size; k++)
		{
			if (!tempNode)
			{
				i++;
				tempNode = graphList->graphListArray[i].next;
			}
			else
				break;
		}
		printf("结点%d与结点%d有边相连;\n", i, tempNode->nodeno);
		//遍历每一个数组内容的邻接表,全部输出出来
		for (int j = 0; j < graphList->size; j++)
		{
			if (tempNode->next != NULL)
			{
				tempNode = tempNode->next;
				printf("结点%d与结点%d有边相连;\n", i, tempNode->nodeno);
			}
			else
			{
				break;
			}
		}
		i++;
	}
}