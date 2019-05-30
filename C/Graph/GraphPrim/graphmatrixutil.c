#include <stdio.h>
#include <stdlib.h>
#include "graphmatrixutil.h"

/****************************************************************/
/* GraphMatrix* InitGraph(int num)								*/
/* ����:��ʼ��ͼ												*/
/* �������num:ͼ�н��ĸ���									*/
/* ����ֵ:���ڽӾ����ʾ��ͼ									*/
/* ��������:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* InitGraph(int num)
{
	int i = 0;
	int j = 0;
	GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
	graphMatrix->size = num;    //ͼ�н��ĸ���

	//��ͼ����ռ�
	graphMatrix->graph = (int**)malloc(sizeof(int*) * graphMatrix->size); //����һά����ռ�
	//����ѭ������Ŀռ���Ǵ���ڽӾ���Ŀռ�
	for (i = 0; i < graphMatrix->size; i++)
	{
		graphMatrix->graph[i] = (int*)malloc(sizeof(int) * graphMatrix->size);
	}

	//��ͼ������Ԫ�����ó�ֵ
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = 0; j < graphMatrix->size; j++)
		{
			graphMatrix->graph[i][j] = INT_MAX;   //��ʼ�������ж��㲻�ڽ�
		}
	}
	return graphMatrix;
}

/****************************************************************/
/* void ReadGraph(GraphMatrix* graphMatrix)						*/
/* ����:�����ݶ���ͼ��											*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphMatrix* graphMatrix)
{
	int vex1 = 0;
	int vex2 = 0;
	int weight = 0;
	//���뷽ʽΪ:�� �� Ȩֵ,��ȨֵΪ0ʱ���������
	printf("������,���뷽ʽΪ:�� �� Ȩֵ,ȨֵΪ0,���������\n");
	scanf_s("%d%d%d", &vex1, &vex2, &weight);

	while (weight != 0)
	{
		graphMatrix->graph[vex1][vex2] = weight;
		scanf_s("%d%d%d", &vex1, &vex2, &weight);
	}
}

/****************************************************************/
/* void WriteGraph(GraphMatrix* graphMatrix)					*/
/* ����:��ͼ�Ľṹ��ʾ����										*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphMatrix* graphMatrix)
{
	int i = 0;
	int j = 0;
	printf("ͼ�Ľṹ����,�����ʽΪ:�� �� Ȩֵ\n");
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

/****************************************************************/
/* GraphMatrix* prim(int source, GraphMatrix *graphMatrix)		*/
/* ����:����ķ�㷨������С������								*/
/* �������source:��ʼλ��										*/
/* �������graphMatrix:�ڽӾ����ʾ��ͼ							*/
/* ����ֵtree:��С������										*/
/* ��������:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* prim(int source, GraphMatrix *graphMatrix)
{
	int i = 0;
	int j = 0;
	int *component = (int*)malloc(sizeof(graphMatrix->size));   //�µ㼯��
	int *distance = (int*)malloc(sizeof(graphMatrix->size));    //����
	int *neighbor = (int*)malloc(sizeof(graphMatrix->size));    //�ھ�,����neighbor[i]=j��ʾi���ھ���j
	GraphMatrix *tree = InitGraph(graphMatrix->size);   //��Ž����ͼ

	//��ʼ��
	for (i = 0; i < graphMatrix->size; i++)
	{
		component[i] = 0;
		distance[i] = graphMatrix->graph[source][i];
		neighbor[i] = source;
	}

	//���������µ㼯��
	component[source] = 1;

	//ÿ�����һ����㵽�µ㼯����
	for (i = 1; i < graphMatrix->size; i++)
	{
		int v;  //v��¼��С��distance[j]���±�
		int min = INT_MAX;  //min��¼��С��distance

		//ѡ�����µ�ļ�����,�����µ㼯����̵��Ǹ���
		for (j = 0; j < graphMatrix->size; j++)
		{
			if (!component[j])
			{
				//����Сֵ
				if (distance[j] < min)
					v = j;
				min = distance[j];
			}
		}

		//���ҵ��ĵ�v�����µ㼯����,������distance
		if (min < INT_MAX)
		{
			component[v] = 1;
			tree->graph[v][neighbor[v]] = distance[v];  //����v��neighbor[v]�ľ���
			tree->graph[neighbor[v]][v] = distance[v];  //����neighbor[v]��v�ľ���
			//���·��µ㼯���еĵ㵽�µ㼯�ϵľ���
			for (j = 0; j < graphMatrix->size; j++)
			{
				if (!component[j])
				{
					if (graphMatrix->graph[v][j] < distance[j])
					{
						distance[j] = graphMatrix->graph[v][j];
						neighbor[j] = v;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	return tree;
}