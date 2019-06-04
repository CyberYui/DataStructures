#include <stdio.h>
#include <stdlib.h>
#include "graphlistutil.h"

/****************************************************************/
/* GraphList* InitGraph(int num)								*/
/* ����:��ʼ��ͼ												*/
/* �������num:ͼ�н��ĸ���									*/
/* ����ֵ:���ڽӱ��ʾ��ͼ										*/
/* ��������:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
GraphList* InitGraph(int num)
{
	int i = 0;
	//��������ͼ�Ŀռ�,����size,�Ӷ�����ڽӱ�����
	GraphList *graphList = (GraphList *)malloc(sizeof(GraphList));
	graphList->size = num;
	graphList->graphListArray = NULL;
	//����size�Ĵ�С������ռ�,ÿһ������λ�ö�����һ�����
	graphList->graphListArray = (GraphListNode*)malloc(sizeof(GraphListNode)*num);
	//��ͼ�н�����ݳ�ʼ��,��������,ȨֵΪ0,ָ����Ϊ��
	for (i = 0; i < num; i++)
	{
		graphList->graphListArray[i].nodeno = -1;
		graphList->graphListArray[i].weight = 0;
		graphList->graphListArray[i].next = NULL;
	}
	return graphList;
}

/****************************************************************/
/* void ReadGraph(GraphList* graphList)							*/
/* ����:�����ݶ���ͼ��											*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphList* graphList)
{
	int vex1 = 0;	//���
	int vex2 = 0;	//�յ�
	int weight = 0;	//����Ȩֵ
	GraphListNode *tempNode = NULL;	//������ʱ����������ݴ���
	//���뷽ʽΪ:��� �յ� Ȩֵ,��˼Ϊ���--(Ȩֵ)-->�յ�,����Ϊ-1ʱ,�������
	printf("����������,���뷽ʽΪ:��� �յ� ����Ȩֵ,����Ϊ-1ʱ�������:\n");
	scanf_s("%d %d %d", &vex1, &vex2, &weight);
	//ֻҪ��һ��ֵΪ-1ѭ���ͽ���
	while (vex1 >= 0 && vex2 >= 0)
	{
		//�����������
		tempNode = (GraphListNode*)malloc(sizeof(GraphListNode));	//����ʱ�������ռ�
		tempNode->nodeno = vex2;
		tempNode->weight = weight;
		tempNode->next = NULL;

		//������Ӧ���,��ͷ��������,������Ϊ�˷���,�����Ǳ����
		//��ԭ�������ݵ�next�����½��,�½�����ڽӱ��һ�����
		tempNode->next = graphList->graphListArray[vex1].next;
		//�޸�ԭ�������ݵ�next,�����µ��ڽӱ�,�Ӷ�ʵ��tempNode�Ĳ���
		graphList->graphListArray[vex1].next = tempNode;
		scanf_s("%d %d %d", &vex1, &vex2, &weight);
	}
}

/****************************************************************/
/* void WriteGraph(GraphList* graphList)						*/
/* ����:��ͼ�Ľṹ��ʾ����										*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-6-3						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphList* graphList)
{
	int i = 0;
	GraphListNode *tempNode = NULL;	//������ʱ����������ݴ���

	tempNode = (GraphListNode *)malloc(sizeof(GraphListNode));
	tempNode->next = NULL;
	tempNode->weight = 0;
	tempNode->nodeno = 0;

	printf("ͼ�Ľṹ����:\n");
	while (i < graphList->size)	//�����Ǵ�0��ʼ���,���Ǳ����size=num=�����ֵ(������Ե�������4)
	{
		tempNode = graphList->graphListArray[i].next;
		//ѭ���жϵ�ǰ�Ķ����Ƿ����ڽӱ�,���û���ڽӱ�,��ֱ�ӿ���һ������,���ѭ��,ֱ���ҵ����ڽӱ�Ķ���
		for (int k = 0; k < graphList->size; k++)
		{
			if (!tempNode)
			{
				i++;
				tempNode = graphList->graphListArray[i].next;
			}
			else
				break;
		}
		printf("���%d����%d�б�����,�ߵ�ȨֵΪ%d;\n", i, tempNode->nodeno , tempNode->weight);
		//����ÿһ���������ݵ��ڽӱ�,ȫ���������
		for (int j = 0; j < graphList->size; j++)
		{
			if (tempNode->next != NULL)
			{
				tempNode = tempNode->next;
				printf("���%d����%d�б�����,�ߵ�ȨֵΪ%d;\n", i, tempNode->nodeno, tempNode->weight);
			}
			else
			{
				break;
			}
		}
		i++;
	}
}