#include "dijkstrashortdistance.h"
#include <stdlib.h>

/****************************************************************/
/* int* dijkstra(int source, GraphMatrix *graphMatrix)			*/
/* 功能:对邻接矩阵表示的图使用dijkstra算法找出一个顶点到其它顶点*/
/*		的最短路径												*/
/* 输入参数source:起点											*/
/* 输入参数graphMatrix:图										*/
/* 返回值:存放最短路径的一维数组distance						*/
/* 创建日期:2019-6-1						Author:Cyber Kaka	*/
/****************************************************************/
int* dijkstra(int source, GraphMatrix *graphMatrix)
{
	int i = 0;	//循环计数器1
	int j = 0;	//循环计数器2
	int vex = 0;	//用于存放顶点编号的临时变量
	int min = 0;	//距离最小值的临时存放变量

	//found数组是用于记录哪些点的最短路径已经确定,即用于标记
	int* found = (int*)malloc(sizeof(int) * graphMatrix->size);

	//距离数组,算法过程中会不断更新,最终的结果也会放于其中
	int* distance = (int*)malloc(sizeof(int) * graphMatrix->size);

	//path数组,用于记录相应顶点在最短路径中的前驱顶点
	int* path = (int*)malloc(sizeof(int) * graphMatrix->size);

	//初始化
	for (i = 0; i < graphMatrix->size; i++)
	{
		found[i] = 0;	//所有结点的最短路径都没有确定
		distance[i] = graphMatrix->graph[source][i];	//权值
		path[i] = 0;	//默认每个结点初始都无直接前驱
	}//end for

	//将起点加入新点集合中
	found[source] = 1;
	distance[source] = 0;	//顶点到自身的距离为0

	//循环确定每个顶点的最短路径
	for (i=0;i<graphMatrix->size;i++)
	{
		//寻找距离最小的点
		min = INT_MAX;
		for (j = 0; j < graphMatrix->size; j++)
		{
			//如果j结点没有确定过最短路径,且其距离小于min
			if ((!found[j]) && (distance[j] < min))
			{
				//记录j顶点到vex,记录其距离,这是最短的
				vex = j;
				min = distance[j];
			}//end if
		}//end for(j) 1

		//找到的点标记为已确定最短路径
		found[vex] = 1;

		//此时以vex为跳板进行数据更新
		//看是否需要更新其他的顶点的distance和path
		for (j = 0; j < graphMatrix->size; j++)
		{
			//顶点j未确定最短路径,且vex和j之间有边相连
			if (!found[j] && graphMatrix->graph[vex][j] != INT_MAX)
			{
				//判断之前的最短路径加上现在跳板vex到j的距离是否小于源点到j的距离
				//若小于则更新其路径
				if (min + graphMatrix->graph[vex][j] < distance[j])
				{
					//更新权值
					distance[j] = min + graphMatrix->graph[vex][j];
					path[j] = vex;	//记录前驱结点
				}//end if
			}//end if
		}//end for(j) 2
	}//end for(i)

	//由于无法同时返回distance和path数组,在此输出path数组(如果需要的话)
	//for (j = 0; j < graphMatrix->size; j++)
	//{
	//	if (distance[j]<INT_MAX)
	//	{
	//		printf("0号结点到%d号结点的前驱结点为%d \n", j, path[j]);
	//	}
	//}

	//上面的输出path数组的循环有个问题,那样只能输出直接前驱
	//往往我们在找路径时要"顺藤摸瓜"才能找到所有前驱
	//for (j=0;j<graphMatrix->size;j++)
	//{
	//	if (distance[j]<INT_MAX)
	//	{
	//		i = j;
	//		printf("\n0号结点到%d号结点的前驱结点依次为:", j);
	//		while (path[i] != 0)
	//		{
	//			printf("%d ", path[i], i);
	//			i = path[i];
	//		}
	//		printf("%d", 0);	//最后不要忘记源点
	//	}
	//}
	//printf("\n");

	return distance;
}//end dijkstra