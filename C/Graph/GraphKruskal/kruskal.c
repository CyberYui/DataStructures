#include <stdlib.h>
#include "kruskal.h"

/****************************************************************/
/* GraphMatrix* kruskal(GraphMatrix *graphMatrix)				*/
/* 功能:使用克鲁斯卡尔算法生成最小生成树						*/
/* 输入参数graphMatrix:											*/
/* 返回值tree:最小生成树										*/
/* 创建日期:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* kruskal(GraphMatrix *graphMatrix)
{
	//声明并初始化循环变量
	int i = 0;
	int j = 0;

	int edgeNum = 0;	//用于记录边数的计数器
	Edge *edge = NULL;	//边的数组
	Edge tempEdge;	//给边排序时使用的临时变量

	int pos = 0;	//用于记录添加到哪一条边了
	int *group;		//用于记录点是否属于同一连通分量的group数组
	int changeGroup = 0;	//记录要变化的连通值

	//存放结果并返回的图(最小生成树)
	GraphMatrix *tree = InitGraph(graphMatrix->size);

	//申请group数组空间,一共需要申请与结点相同的空间数
	group = (int*)malloc(sizeof(int) * graphMatrix->size);

	//初始化数组
	for (i = 0; i < graphMatrix->size; i++)
	{
		//初期点全部加入,但互不相连,每个点都是一个连通子图
		group[i] = i;
	}

	//统计一共有多少条边
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = i + 1; j < graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edgeNum++;
			}
		}
	}//end counting for edge number

	//根据刚刚计算出来的边数,分配边的数组的空间
	edge = (Edge *)malloc(sizeof(Edge) * edgeNum);

	int k = 0;	//给边赋值时使用的循环计数器

	//给边赋值
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = i + 1; j < graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = graphMatrix->graph[i][j];
				k++;
			}
		}
	}//end giving weight for every edges

	//对边进行排序,使用了冒泡算法
	for (i = 0; i < edgeNum; i++)
	{
		for (j = i + 1; j < edgeNum; j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				tempEdge = edge[i];
				edge[i] = edge[j];
				edge[j] = tempEdge;
			}
		}
	}//排序结束

	//对排序完的内容进行输出,看看同权值的边谁在前,谁在后
	/*printf("排序完的边顺序为:\n");
	for (i = 0; i < edgeNum; i++)
	{
		printf("%d %d %d\n", edge[i].begin, edge[i].end, edge[i].weight);
	}*/

	//此时边的数组已经排好顺序了
	//每次从边的数组中取出最小的一条边,判断是否能添加到最小生成树中
	for (i = 0; i < edgeNum; i++)
	{
		//只添加终点和起点属于两个不同连通分量的边
		if (group[edge[i].begin] != group[edge[i].end])
		{
			//添加到最小生成树中
			tree->graph[edge[i].begin][edge[i].end] = edge[i].weight;
			tree->graph[edge[i].end][edge[i].begin] = edge[i].weight;

			//更新所有与终点属于同一连通分量的点的连通值
			changeGroup = group[edge[i].end];
			for (j = 0; j < edgeNum; j++)
			{
				if (group[j] == changeGroup)
				{
					group[j] = group[edge[i].begin];
				}
			}//end for,结束更新连通值
		}//end if,仅对连通分量不同的边进行操作
	}//end for,结束循环,生成最小生成树
	return tree;	//实际也是个图
}