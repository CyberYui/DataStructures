#include <stdio.h>
#include <stdlib.h>
#include "graphmatrixutil.h"
#include "dijkstrashortdistance.h"

/*
0 1 5
0 2 30
0 3 35
1 2 24
1 5 10
1 4 29
2 5 17
3 0 15
4 5 25
5 4 12
5 3 8
0 0 0
//具体的图的相关图片见本目录中的Graph_6.png
*/
int main()
{
	//dijkstra最短路径测试
	GraphMatrix *graphMatrix = NULL;
	int *distance = NULL;	//用于接收返回数组内容的数组
	int i = 0;	//循环计数器

	graphMatrix = InitGraph(6);
	ReadGraph(graphMatrix);

	distance = dijkstra(0, graphMatrix);

	for (i = 0; i < graphMatrix->size; i++)
	{
		if (distance[i]<INT_MAX)
		{
			printf("0号结点到%d号结点的最短距离为%d \n",i,distance[i]);
			//一个函数是无法返回两个返回值的,所以在函数中循环输出path数组即可
			//printf("0号结点到%d号结点的前驱结点为%d \n",i,path[i]);
		}
		else
		{
			printf("0号结点到%d号结点无法连通 \n", i);
		}
	}

	return 0;
}