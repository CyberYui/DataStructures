#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjMatrixUtil.h"

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