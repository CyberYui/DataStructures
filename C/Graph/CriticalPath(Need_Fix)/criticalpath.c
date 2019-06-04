//����һ����Ȩ����ͼ�Ĺؼ�·��

#include <stdio.h>
#include <stdlib.h>
#include "graphlistutil.h"
#include "graphinverselistutil.h"
#include "LinkedStack.h"

/****************************************************************/
/*int eventEarliestTime(GraphList *graphList, int *earliestTime)*/
/*	����:���¼����ܵ����緢��ʱ��								*/
/*	�������graphList:���ڽӱ��ʾ��ͼ							*/
/*	�������earliestTime:�¼����ܵ����緢��ʱ��					*/
/*	����ֵsuccess:1--�ɹ�	0--ʧ��								*/
/*	��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
int eventEarliestTime(GraphList *graphList, int *earliestTime)
{
	int i = 0;	//��ʼ��ѭ��������
	int cnt = 0;	//��¼���������ж�������ı���
	int nodeNum = 0;	//��¼ջ�������ͼ����ŵ���ʱ����
	int success = 1;	//����ɹ�����flag

	LinkedStack nodeStack = NULL;	//���ڱ����ջ����ȡ�Ľ�����ݵ���ʱ���
	GraphListNode *tempNode = NULL;	//���ڱ��涥�����ݵ���ʱ���

	//�������ڱ������������ȵ�����ռ�
	int *inPoint = (int*)malloc(sizeof(int) * graphList->size);
	nodeStack = SetNullStack_Link();	//����һ����ջ

	//��ʼ��inPoint����,�����������ʼ���Ϊ0
	for (i = 0; i < graphList->size; i++)
	{
		inPoint[i] = 0;
	}

	//ѭ�������������ĳ�ʼ���,�޸�inPoint����
	for (i = 0; i < graphList->size; i++)
	{
		//��ͼ����ȡ����
		tempNode = graphList->graphListArray[i].next;

		//��鶥����ڽӱ�(���߱�)
		while (tempNode != NULL)
		{
			//�ڽӱ�Ϊ��,����ȼ�1
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//����ѯ
		}
	}

	//����ѭ�������Ϊ0�Ķ�����ջ,����ջ��Ϊ��ֱ���˳�����
	for (i = 0; i < graphList->size; i++)
	{
		if (inPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}

	//[Core]�����¼����ջ��Ϊ��
	cnt = 0;	//��ʼʱ��������õĶ�����Ϊ0
	while (!IsNullStack_link(nodeStack))
	{
		//ȡջ��Ԫ��v
		nodeNum = Pop_seq_return(nodeStack);
		//printf("%d ", nodeNum);	//�������,�˶����������������
		Pop_link(nodeStack);	//��ɵĶ����ջ
		cnt++;	//������+1

		//���v�ĳ���,��ÿ�����ߵ��ն˶������ȼ�1
		//����ʱ�ö������Ϊ0,������ջ
		tempNode = graphList->graphListArray[nodeNum].next;	//���
		while (tempNode != NULL)
		{
			//ȥ�����
			inPoint[tempNode->nodeno]--;	//���߱���������ض������-1
			//Ϊÿ�����ߵ��յ��¼����¿��ܵ����緢��ʱ��
			if (earliestTime[tempNode->nodeno] < earliestTime[nodeNum] + tempNode->weight)
			{
				earliestTime[tempNode->nodeno] = earliestTime[nodeNum] + tempNode->weight;
			}

			//�������Ƿ�Ϊ0,��0����ջ
			if (inPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//�����һ���������
			tempNode = tempNode->next;
		}
	}//ջΪ��ʱ����ѭ��

	//��ͼ�����ж�����δ���������,���������ʧ��
	if (cnt != graphList->size)
	{
		success = 0;
	}

	return success;	//����flag
}//O(n+1)

/****************************************************************************/
/*	int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)*/
/*	����:�����¼��������ٷ���ʱ��											*/
/*	�������graphInverseList:�����ڽӱ��ʾ��ͼ								*/
/*	�������latestTime:�¼��������ٷ���ʱ������							*/
/*	����ֵsuccess:1--�ɹ�	0--ʧ��											*/
/*	��������:2019-6-4									Author:Cyber Kaka	*/
/****************************************************************************/
int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)
{
	int i = 0;	//��ʼ��ѭ��������
	int cnt = 0;	//��¼���������ж�������ı���
	int nodeNum = 0;	//��¼ջ�������ͼ����ŵ���ʱ����
	int success = 1;	//����ɹ�����flag

	LinkedStack nodeStack = NULL;	//���ڱ����ջ����ȡ�Ľ�����ݵ���ʱ���
	GraphInverseListNode *tempNode = NULL;	//���ڱ��涥�����ݵ���ʱ���

	//�������ڱ������������ȵ�����ռ�
	int *outPoint = (int*)malloc(sizeof(int) * graphInverseList->size);
	nodeStack = SetNullStack_Link();	//����һ����ջ

	//��ʼ��inPoint����,�����������ʼ����Ϊ0
	for (i = 0; i < graphInverseList->size; i++)
	{
		outPoint[i] = 0;
	}

	//ѭ�������������ĳ�ʼ����,�޸�outPoint����
	for (i = 0; i < graphInverseList->size; i++)
	{
		//��ͼ����ȡ����
		tempNode = graphInverseList->graphInverseListArray[i].next;

		//��鶥����ڽӱ�(���߱�)
		while (tempNode != NULL)
		{
			//�ڽӱ�Ϊ��,����ȼ�1
			outPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//����ѯ
		}
	}

	//����ѭ��������Ϊ0�Ķ�����ջ,����ջ��Ϊ��ֱ���˳�����
	for (i = 0; i < graphInverseList->size; i++)
	{
		if (outPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}

	//[Core]�����¼����ջ��Ϊ��
	cnt = 0;	//��ʼʱ��������õĶ�����Ϊ0
	while (!IsNullStack_link(nodeStack))
	{
		//ȡջ��Ԫ��v
		nodeNum = Pop_seq_return(nodeStack);
		//printf("%d ", nodeNum);	//�������,�˶����������������
		Pop_link(nodeStack);	//��ɵĶ����ջ
		cnt++;	//������+1

		//���v�����,��ÿ����ߵ��ն˶���ĳ��ȼ�1
		//����ʱ�ö������Ϊ0,������ջ
		tempNode = graphInverseList->graphInverseListArray[nodeNum].next;	//���
		while (tempNode != NULL)
		{
			//ȥ������
			outPoint[tempNode->nodeno]--;	//��߱���������ض������-1
			//Ϊÿ�����ߵ��յ��¼����¿��ܵ���ٷ���ʱ��
			if (latestTime[tempNode->nodeno] < latestTime[nodeNum] + tempNode->weight)
			{
				latestTime[tempNode->nodeno] = latestTime[nodeNum] + tempNode->weight;
			}

			//�������Ƿ�Ϊ0,��0����ջ
			if (outPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//�����һ���������
			tempNode = tempNode->next;
		}
	}//ջΪ��ʱ����ѭ��

	//��ͼ�����ж�����δ���������,���������ʧ��
	if (cnt != graphInverseList->size)
	{
		success = 0;
	}

	return success;	//����flag
}//O(n+1)

/********************************************************************************/
/*	void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)	*/
/*	����:����һ��ͼ���ڽӱ�����ڽӱ����ؼ�·��								*/
/*	�������graphList:���ڽӱ��ʾ��ͼ											*/
/*	�������graphInverseList:�����ڽӱ��ʾ��ͼ									*/
/*	����ֵ:��																	*/
/*	��������:2019-6-4										Author:Cyber Kaka	*/
/********************************************************************************/
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)
{
	int i = 0;	//����ѭ����ļ�����
	int max = 0;	//���ڱ������緢��ʱ������ֵ����ʱ����

	//�������緢��ʱ������Ŀռ�
	int* earliestTime = (int*)malloc(sizeof(int) * graphList->size);
	//������ٷ���ʱ������Ŀռ�
	int* latestTime = (int*)malloc(sizeof(int) * graphInverseList->size);

	int activityEarliestTime = 0;
	int activityLatestTime = 0;

	GraphListNode *tempNode = NULL;

	//��ʼ�������¼����ܵ����緢��ʱ��Ϊ0
	for (i=0;i<graphList->size;i++)
	{
		earliestTime[i] = 0;
	}

	//�����㷨,��ÿ���¼����ܵ����緢��ʱ��
	eventEarliestTime(graphList, earliestTime);

	//���¼����緢��ʱ������ֵ,������������¼�������ٷ���ʱ��ĳ�ֵ
	max = earliestTime[0];
	for (i=0;i<graphList->size;i++)
	{
		if (max<earliestTime[i])
		{
			max = earliestTime[i];
		}
	}

	//��ʼ�������¼��������ٷ���ʱ��Ϊ���ֵ
	for (i=0;i<graphInverseList->size;i++)
	{
		latestTime[i] = max;
	}

	//�����㷨,��ÿ���¼��������ٷ���ʱ��
	eventLatestTime(graphInverseList, latestTime);

	//��ʼ���������

	//����ÿ����,��ÿ��������翪ʼʱ�������ʼʱ��,�����жԱ�
	//��ȼ�Ϊ�ؼ�·���ϵı�,Ҳ��������ʱ������Ϊ0
	for (i=0;i<graphList->size;i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while (tempNode != NULL)
		{
			activityEarliestTime = earliestTime[i];
			activityLatestTime = latestTime[tempNode->nodeno] - tempNode->weight;

			if (activityEarliestTime == activityLatestTime)
			{
				printf("<v%2d,v%2d>", i, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}
}//O(n+1)