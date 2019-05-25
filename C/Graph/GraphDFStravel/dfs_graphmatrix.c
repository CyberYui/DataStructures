/*图的深度优先遍历实现,用邻接矩阵表示图*/
#include <stdio.h>
#include <stdlib.h>
#include "dfs_graphmatrix.h"

/****************************************************************/
/* void DFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* 功能:图的深度优先遍历递归算法,邻接矩阵表示图					*/
/* 输入参数graphMatrix:图										*/
/* 输入参数visited:做标记用(设置点是否被访问)的一位数组			*/
/* 输入参数i:遍历起始的结点编号									*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j = 0;
	//首先对顶点访问,标记为已访问过
	visited[i] = 1;
	printf("%d ", i);	//访问
	//递归实现深度优先遍历
	for (j = 0; j < graphMatrix->size; j++)
	{
		//如果i和j有边相连,并且j没有被访问过
		if (graphMatrix->graph[i][j] != INT_MAX && !visited[j])
		{
			DFS(graphMatrix, visited, j);	//对j进行深度优先遍历
		}
	}
}

/****************************************************************/
/* void DFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* 功能:深度遍历,邻接矩阵表示图									*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i = 0;
	//用于记录图中哪些结点已经被访问了
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	//初始化为点都没有被访问
	for (i = 0; i < graphMatrix->size; i++)
	{
		visited[i] = 0;
	}
	//从0出发开始访问结点,只要有没访问过的就对其进行深度优先遍历,
	//这样就能访问到所有的连通分量
	for (i = 0; i < graphMatrix->size; i++)
	{
		//对未访问过的顶点调用DFS,若是连通图,则只会执行一次
		if (!visited[i])
		{
			DFS(graphMatrix, visited, i);
		}
	}
}