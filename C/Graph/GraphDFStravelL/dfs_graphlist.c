/*图的深度优先遍历算法,用邻接表表示的图*/

#include <stdio.h>
#include <stdlib.h>
#include "dfs_graphlist.h"

/****************************************************************/
/* void DFS(GraphList* graphList, int * visited, int i)			*/
/* 功能:图的深度优先遍历递归算法,邻接表表示图					*/
/* 输入参数graphList:图											*/
/* 输入参数visited:做标记用(设置点是否被访问过)的一维数组		*/
/* 输入参数i:结点编号											*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphList* graphList, int * visited, int i)
{
	int j = 0;
	GraphListNode *tempNode = NULL;
	visited[i] = 1;
	printf("%d ", i);

	tempNode = graphList->graphListArray[i].next;
	while (tempNode != NULL)
	{
		if (!visited[tempNode->nodeno])
		{
			DFS(graphList, visited, tempNode->nodeno);
		}
		tempNode = tempNode->next;	
	}
}

/****************************************************************/
/* void GFSGraphList(GraphList* graphList)						*/
/* 功能:深度遍历,邻接表表示图									*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphList(GraphList* graphList)
{
	int i = 0;
	//用于记录图中哪些结点已经被访问了
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	//初始化为点都没有被访问过
	for (i = 0; i < graphList->size; i++)
	{
		visited[i] = 0;
	}

	for (i = 0; i < graphList->size; i++)
	{
		//对未访问过的顶点调用DFS,若是连通图,只会执行一次
		if (!visited[i])
		{
			DFS(graphList, visited, i);
		}
	}
}