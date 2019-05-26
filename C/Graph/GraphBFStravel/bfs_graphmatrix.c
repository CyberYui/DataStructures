/*对用邻接矩阵表示的图进行广度优先遍历搜索*/

#include "bfs_graphmatrix.h"
#include <stdio.h>
#include <stdlib.h>

/****************************************************************/
/* void BFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* 功能:图的广度优先遍历,邻接矩阵表示图							*/
/* 输入参数graphMatrix:图										*/
/* 输入参数visited:用于保存访问状态的一位数组					*/
/* 输入参数i:结点编号											*/
/* 返回值:														*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j = 0;
	int tempVex = 0;
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();
	//如果没有访问过,则访问
	if (!visited[i])
	{
		visited[i] = 1;	//设置标记,表明已经被访问过
		printf("%d ", i);	//输出访问的结点编号
		EnQueue_Link(waitingQueue, i);	//将刚访问的结点放入队列
		while (!IsNullQueue_Link(waitingQueue))
		{
			tempVex = FrontQueue_Link(waitingQueue);
			DeQueue_Link(waitingQueue);
			for (j = 0; j < graphMatrix->size; j++)
			{
				//如果其它顶点与当前订单存在边且未访问过
				if (graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j])
				{
					visited[j] = 1;	//做标记
					EnQueue_Link(waitingQueue, j);	//入队
					printf("%d ", j);	//输出
				}//end if
			}//end for
		}//end while
	}//end if
}//end function

/****************************************************************/
/* void BFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* 功能:图的广度优先遍历,邻接矩阵表示图							*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i = 0;

	//用于记录图中哪些结点已经被访问过了
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	//设置所有结点都没有被访问过
	for (i = 0; i < graphMatrix->size; i++)
	{
		visited[i] = 0;
	}

	//从0号结点开始进行广度优先遍历
	for (i = 0; i < graphMatrix->size; i++)
	{
		BFS(graphMatrix, visited, i);
	}//end
}