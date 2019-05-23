#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjMatrixUtil.h"

/****************************************************************/
/* GraphMatrix* InitGraph(int num)								*/
/* 功能:初始化图												*/
/* 输入参数num:图中结点的个数									*/
/* 返回值:用邻接矩阵表示的图									*/
/* 创建日期:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* InitGraph(int num)
{
	int i = 0;
	int j = 0;
	GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
	graphMatrix->size = num;    //图中结点的个数

	//给图分配空间
	graphMatrix->graph = (int**)malloc(sizeof(int*) * graphMatrix->size); //申请一维数组空间
	//这里循环申请的空间才是存放邻接矩阵的空间
	for (i = 0; i < graphMatrix->size; i++)
	{
		graphMatrix->graph[i] = (int*)malloc(sizeof(int) * graphMatrix->size);
	}

	//给图中所有元素设置初值
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = 0; j < graphMatrix->size; j++)
		{
			graphMatrix->graph[i][j] = INT_MAX;   //初始设置所有顶点不邻接
		}
	}
	return graphMatrix;
}

/****************************************************************/
/* void ReadGraph(GraphMatrix* graphMatrix)						*/
/* 功能:将数据读入图中											*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphMatrix* graphMatrix)
{
	int vex1 = 0;
	int vex2 = 0;
	int weight = 0;
	//输入方式为:点 点 权值,当权值为0时则输入结束
	printf("请输入,输入方式为:点 点 权值,权值为0,则输入结束\n");
	scanf_s("%d%d%d", &vex1, &vex2, &weight);

	while (weight != 0)
	{
		graphMatrix->graph[vex1][vex2] = weight;
		scanf_s("%d%d%d", &vex1, &vex2, &weight);
	}
}

/****************************************************************/
/* void WriteGraph(GraphMatrix* graphMatrix)					*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphMatrix* graphMatrix)
{
	int i = 0;
	int j = 0;
	printf("图的结构如下,输出方式为:点 点 权值\n");
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = 0; j < graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				printf("%d %d %d\n", i, j, graphMatrix->graph[i][j]);
			}
		}
	}
}