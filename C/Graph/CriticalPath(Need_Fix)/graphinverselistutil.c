#include <stdio.h>
#include <stdlib.h>
#include "graphinverselistutil.h"

/****************************************************************/
/* GraphInverseList* InitGraph(int num)							*/
/* ����:��ʼ��ͼ												*/
/* �������num:ͼ�н��ĸ���									*/
/* ����ֵ:�����ڽӱ��ʾ��ͼ									*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
GraphInverseList* InitInverseGraph(int num)
{
	int i = 0;
	//��������ͼ�Ŀռ�,����size,�Ӷ�����ڽӱ�����
	GraphInverseList *graphInverseList = (GraphInverseList *)malloc(sizeof(GraphInverseList));
	graphInverseList->size = num;
	graphInverseList->graphInverseListArray = NULL;
	//����size�Ĵ�С������ռ�,ÿһ������λ�ö�����һ�����
	graphInverseList->graphInverseListArray = (GraphInverseListNode*)malloc(sizeof(GraphInverseListNode)*num);
	//��ͼ�н�����ݳ�ʼ��,��������,ȨֵΪ0,ָ����Ϊ��
	for (i = 0; i < num; i++)
	{
		graphInverseList->graphInverseListArray[i].nodeno = -1;
		graphInverseList->graphInverseListArray[i].weight = 0;
		graphInverseList->graphInverseListArray[i].next = NULL;
	}
	return graphInverseList;
}

/****************************************************************/
/* void ReadInverseGraph(GraphInverseList* graphInverseList)	*/
/* ����:�����ݶ���ͼ��											*/
/* �������graphInverseList:ͼ									*/
/* ����ֵ:��													*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void ReadInverseGraph(GraphInverseList* graphInverseList)
{
	int vexBegin = 0;	//���
	int vexEnd = 0;		//�յ�
	int weight = 0;		//����Ȩֵ
	GraphInverseListNode *tempNode = NULL;	//������ʱ����������ݴ���
	//���뷽ʽΪ:��� �յ� Ȩֵ,��˼Ϊ���--(Ȩֵ)-->�յ�,����Ϊ-1ʱ,�������
	printf("����������,���뷽ʽΪ:��� �յ� ����Ȩֵ,����Ϊ-1ʱ�������:\n");
	scanf_s("%d %d %d", &vexBegin, &vexEnd, &weight);

	while (vexBegin >= 0 && vexEnd >= 0)
	{
		tempNode = (GraphInverseListNode *)malloc(sizeof(GraphInverseListNode));
		tempNode->nodeno = vexBegin;
		tempNode->weight = weight;
		tempNode->next = NULL;

		//Ѱ����Ҫ������ĵط�,����Ϊ�˷���ͷ���ͷ��
		tempNode->next = graphInverseList->graphInverseListArray[vexEnd].next;
		graphInverseList->graphInverseListArray[vexEnd].next = tempNode;
		scanf_s("%d %d %d", &vexBegin, &vexEnd, &weight);
	}
}

/****************************************************************/
/* void WriteInverseGraph(GraphInverseList *graphInverseList)	*/
/* ����:��ͼ�Ľṹ��ʾ����										*/
/* �������graphInverseList:ͼ									*/
/* ����ֵ:��													*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void WriteInverseGraph(GraphInverseList *graphInverseList)
{
	int i = 0;
	GraphInverseListNode *tempNode = NULL;	//������ʱ����������ݴ���

	tempNode = (GraphInverseListNode *)malloc(sizeof(GraphInverseListNode));
	tempNode->next = NULL;
	tempNode->weight = 0;
	tempNode->nodeno = 0;

	printf("ͼ�Ľṹ����:\n");
	while (i < graphInverseList->size)	//�����Ǵ�0��ʼ���,���Ǳ����size=num=�����ֵ(������Ե�������4)
	{
		tempNode = graphInverseList->graphInverseListArray[i].next;
		//ѭ���жϵ�ǰ�Ķ����Ƿ����ڽӱ�,���û���ڽӱ�,��ֱ�ӿ���һ������,���ѭ��,ֱ���ҵ����ڽӱ�Ķ���
		for (int k = 0; k < graphInverseList->size; k++)
		{
			if (!tempNode)
			{
				i++;
				tempNode = graphInverseList->graphInverseListArray[i].next;
			}
			else
				break;
		}
		printf("���%d����%d�б�����,�ߵ�ȨֵΪ%d;\n", i, tempNode->nodeno, tempNode->weight);
		//����ÿһ���������ݵ��ڽӱ�,ȫ���������
		for (int j = 0; j < graphInverseList->size; j++)
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