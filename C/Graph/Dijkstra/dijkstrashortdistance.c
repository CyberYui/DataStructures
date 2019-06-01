#include "dijkstrashortdistance.h"
#include <stdlib.h>

/****************************************************************/
/* int* dijkstra(int source, GraphMatrix *graphMatrix)			*/
/* ����:���ڽӾ����ʾ��ͼʹ��dijkstra�㷨�ҳ�һ�����㵽��������*/
/*		�����·��												*/
/* �������source:���											*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:������·����һά����distance						*/
/* ��������:2019-6-1						Author:Cyber Kaka	*/
/****************************************************************/
int* dijkstra(int source, GraphMatrix *graphMatrix)
{
	int i = 0;	//ѭ��������1
	int j = 0;	//ѭ��������2
	int vex = 0;	//���ڴ�Ŷ����ŵ���ʱ����
	int min = 0;	//������Сֵ����ʱ��ű���

	//found���������ڼ�¼��Щ������·���Ѿ�ȷ��,�����ڱ��
	int* found = (int*)malloc(sizeof(int) * graphMatrix->size);

	//��������,�㷨�����л᲻�ϸ���,���յĽ��Ҳ���������
	int* distance = (int*)malloc(sizeof(int) * graphMatrix->size);

	//path����,���ڼ�¼��Ӧ���������·���е�ǰ������
	int* path = (int*)malloc(sizeof(int) * graphMatrix->size);

	//��ʼ��
	for (i = 0; i < graphMatrix->size; i++)
	{
		found[i] = 0;	//���н������·����û��ȷ��
		distance[i] = graphMatrix->graph[source][i];	//Ȩֵ
		path[i] = 0;	//Ĭ��ÿ������ʼ����ֱ��ǰ��
	}//end for

	//���������µ㼯����
	found[source] = 1;
	distance[source] = 0;	//���㵽����ľ���Ϊ0

	//ѭ��ȷ��ÿ����������·��
	for (i=0;i<graphMatrix->size;i++)
	{
		//Ѱ�Ҿ�����С�ĵ�
		min = INT_MAX;
		for (j = 0; j < graphMatrix->size; j++)
		{
			//���j���û��ȷ�������·��,�������С��min
			if ((!found[j]) && (distance[j] < min))
			{
				//��¼j���㵽vex,��¼�����,������̵�
				vex = j;
				min = distance[j];
			}//end if
		}//end for(j) 1

		//�ҵ��ĵ���Ϊ��ȷ�����·��
		found[vex] = 1;

		//��ʱ��vexΪ����������ݸ���
		//���Ƿ���Ҫ���������Ķ����distance��path
		for (j = 0; j < graphMatrix->size; j++)
		{
			//����jδȷ�����·��,��vex��j֮���б�����
			if (!found[j] && graphMatrix->graph[vex][j] != INT_MAX)
			{
				//�ж�֮ǰ�����·��������������vex��j�ľ����Ƿ�С��Դ�㵽j�ľ���
				//��С���������·��
				if (min + graphMatrix->graph[vex][j] < distance[j])
				{
					//����Ȩֵ
					distance[j] = min + graphMatrix->graph[vex][j];
					path[j] = vex;	//��¼ǰ�����
				}//end if
			}//end if
		}//end for(j) 2
	}//end for(i)

	//�����޷�ͬʱ����distance��path����,�ڴ����path����(�����Ҫ�Ļ�)
	//for (j = 0; j < graphMatrix->size; j++)
	//{
	//	if (distance[j]<INT_MAX)
	//	{
	//		printf("0�Ž�㵽%d�Ž���ǰ�����Ϊ%d \n", j, path[j]);
	//	}
	//}

	//��������path�����ѭ���и�����,����ֻ�����ֱ��ǰ��
	//������������·��ʱҪ"˳������"�����ҵ�����ǰ��
	//for (j=0;j<graphMatrix->size;j++)
	//{
	//	if (distance[j]<INT_MAX)
	//	{
	//		i = j;
	//		printf("\n0�Ž�㵽%d�Ž���ǰ���������Ϊ:", j);
	//		while (path[i] != 0)
	//		{
	//			printf("%d ", path[i], i);
	//			i = path[i];
	//		}
	//		printf("%d", 0);	//���Ҫ����Դ��
	//	}
	//}
	//printf("\n");

	return distance;
}//end dijkstra