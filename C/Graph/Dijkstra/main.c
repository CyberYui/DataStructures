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
//�����ͼ�����ͼƬ����Ŀ¼�е�Graph_6.png
*/
int main()
{
	//dijkstra���·������
	GraphMatrix *graphMatrix = NULL;
	int *distance = NULL;	//���ڽ��շ����������ݵ�����
	int i = 0;	//ѭ��������

	graphMatrix = InitGraph(6);
	ReadGraph(graphMatrix);

	distance = dijkstra(0, graphMatrix);

	for (i = 0; i < graphMatrix->size; i++)
	{
		if (distance[i]<INT_MAX)
		{
			printf("0�Ž�㵽%d�Ž�����̾���Ϊ%d \n",i,distance[i]);
			//һ���������޷�������������ֵ��,�����ں�����ѭ�����path���鼴��
			//printf("0�Ž�㵽%d�Ž���ǰ�����Ϊ%d \n",i,path[i]);
		}
		else
		{
			printf("0�Ž�㵽%d�Ž���޷���ͨ \n", i);
		}
	}

	return 0;
}