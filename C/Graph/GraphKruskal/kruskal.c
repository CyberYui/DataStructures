#include <stdlib.h>
#include "kruskal.h"

/****************************************************************/
/* GraphMatrix* kruskal(GraphMatrix *graphMatrix)				*/
/* ����:ʹ�ÿ�³˹�����㷨������С������						*/
/* �������graphMatrix:											*/
/* ����ֵtree:��С������										*/
/* ��������:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* kruskal(GraphMatrix *graphMatrix)
{
	//��������ʼ��ѭ������
	int i = 0;
	int j = 0;

	int edgeNum = 0;	//���ڼ�¼�����ļ�����
	Edge *edge = NULL;	//�ߵ�����
	Edge tempEdge;	//��������ʱʹ�õ���ʱ����

	int pos = 0;	//���ڼ�¼��ӵ���һ������
	int *group;		//���ڼ�¼���Ƿ�����ͬһ��ͨ������group����
	int changeGroup = 0;	//��¼Ҫ�仯����ֵͨ

	//��Ž�������ص�ͼ(��С������)
	GraphMatrix *tree = InitGraph(graphMatrix->size);

	//����group����ռ�,һ����Ҫ����������ͬ�Ŀռ���
	group = (int*)malloc(sizeof(int) * graphMatrix->size);

	//��ʼ������
	for (i = 0; i < graphMatrix->size; i++)
	{
		//���ڵ�ȫ������,����������,ÿ���㶼��һ����ͨ��ͼ
		group[i] = i;
	}

	//ͳ��һ���ж�������
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

	//���ݸոռ�������ı���,����ߵ�����Ŀռ�
	edge = (Edge *)malloc(sizeof(Edge) * edgeNum);

	int k = 0;	//���߸�ֵʱʹ�õ�ѭ��������

	//���߸�ֵ
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

	//�Ա߽�������,ʹ����ð���㷨
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
	}//�������

	//������������ݽ������,����ͬȨֵ�ı�˭��ǰ,˭�ں�
	/*printf("������ı�˳��Ϊ:\n");
	for (i = 0; i < edgeNum; i++)
	{
		printf("%d %d %d\n", edge[i].begin, edge[i].end, edge[i].weight);
	}*/

	//��ʱ�ߵ������Ѿ��ź�˳����
	//ÿ�δӱߵ�������ȡ����С��һ����,�ж��Ƿ�����ӵ���С��������
	for (i = 0; i < edgeNum; i++)
	{
		//ֻ����յ���������������ͬ��ͨ�����ı�
		if (group[edge[i].begin] != group[edge[i].end])
		{
			//��ӵ���С��������
			tree->graph[edge[i].begin][edge[i].end] = edge[i].weight;
			tree->graph[edge[i].end][edge[i].begin] = edge[i].weight;

			//�����������յ�����ͬһ��ͨ�����ĵ����ֵͨ
			changeGroup = group[edge[i].end];
			for (j = 0; j < edgeNum; j++)
			{
				if (group[j] == changeGroup)
				{
					group[j] = group[edge[i].begin];
				}
			}//end for,����������ֵͨ
		}//end if,������ͨ������ͬ�ı߽��в���
	}//end for,����ѭ��,������С������
	return tree;	//ʵ��Ҳ�Ǹ�ͼ
}