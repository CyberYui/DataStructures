/*图的广度优先遍历,用邻接表表示的图*/
#include "bfs_graphlist.h"
#include <stdio.h>
#include "LinkQueue.h"
/****************************************************************/
/* void BFS(GraphList* graphList, int * visited, int i)			*/
/* 功能:对邻接表表示的图进行广度优先遍历						*/
/* 输入参数graphList:图,邻接表表示								*/
/* 输入参数visited:用于标记结点是否被访问过的一位数组			*/
/* 输入参数i:结点编号											*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphList* graphList, int * visited, int i)
{
	int tempVex = 0;
	GraphListNode *tempNode = NULL;

	//广度优先遍历使用的队列是c++的STL(标准模版库)中的queue
	//很明显,C语言是无法使用标准模版库的,所以视频没有给出所有代码,因为她也跑不出来
	//还是用原先的链队列
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();

	//如果没有访问过,则访问
	if (!visited[i])
	{
		visited[i] = 1;	//设置标记,表明已经被访问过了
		printf("%d ", i);	//输出访问的结点的编号
		EnQueue_Link(waitingQueue,i);	//将刚访问的结点放入队列
		//开始广度优先遍历结点
		while (!IsNullQueue_Link(waitingQueue))
		{
			tempVex = FrontQueue_Link(waitingQueue);
			DeQueue_Link(waitingQueue);
			//依次访问与当前结点相邻的点
			tempNode = graphList->graphListArray[tempVex].next;
			while (tempNode!=NULL)
			{
				//如果其它顶点与当前顶点存在边且未被访问过
				if (!visited[tempNode->nodeno])
				{
					visited[tempNode->nodeno] = 1;	//做标记
					EnQueue_Link(waitingQueue, tempNode->nodeno);	//入队
					printf("%d ", tempNode->nodeno);	//输出
				}//end if

				//移动到下一个结点
				tempNode = tempNode->next;
			}//end while
		}//end while
	}//end if
}

/****************************************************************/
/* void BFSGraphList(GraphList* graphList)						*/
/* 功能:图的广度优先遍历,邻接表表示图							*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphList(GraphList* graphList)
{
	int i = 0;

	//用于记录图中哪些结点已经被访问过了
	int *visited = (int*)malloc(sizeof(int) * graphList->size);
	//这里会报警告,可以忽略
	//warning C4013: “malloc”未定义；假设外部返回 int

	//设置所有结点都没有被访问过
	for (i = 0; i < graphList->size; i++)
	{
		visited[i] = 0;
	}

	//从0号结点开始进行广度优先遍历
	for (i = 0; i < graphList->size; i++)
	{
		BFS(graphList, visited, i);
	}//end
}