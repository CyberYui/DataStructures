#include <stdio.h>
#include <stdlib.h>

#include "graphlistutil.h"
#include "LinkedStack.h"

/****************************************************************/
/* int topologicalsort(GraphList *graphList)					*/
/* ����:��������һ��ͼ											*/
/* �������graphList:�ڽӱ��ʾ��ͼ								*/
/* ����ֵ:1--�ɹ�	0--ʧ��										*/
/* ��������:2019-6-3						Author:Cyber Kaka	*/
/****************************************************************/
int topologicalsort(GraphList *graphList)
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
	for (i = 0;i<graphList->size;i++)
	{
		inPoint[i] = 0;
	}

	//ѭ�������������ĳ�ʼ���,�޸�inPoint����
	for (i = 0; i < graphList->size; i++)
	{
		//��ͼ����ȡ����
		tempNode = graphList->graphListArray[i].next;

		//��鶥����ڽӱ�(���߱�)
		while (tempNode!=NULL)
		{
			//�ڽӱ�Ϊ��,����ȼ�1
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//����ѯ
		}
	}

	//����ѭ�������Ϊ0�Ķ�����ջ,����ջ��Ϊ��ֱ���˳�����
	for (i=0;i<graphList->size;i++)
	{
		if (inPoint[i]==0)
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
		printf("%d ", nodeNum);	//�������,�˶����������������
		Pop_link(nodeStack);	//��ɵĶ����ջ
		cnt++;	//������+1

		//���v�ĳ���,��ÿ�����ߵ��ն˶������ȼ�1
		//����ʱ�ö������Ϊ0,������ջ
		tempNode = graphList->graphListArray[nodeNum].next;	//���
		while (tempNode != NULL)
		{
			inPoint[tempNode->nodeno]--;	//���߱���������ض������-1
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
}

//������
/*
0 1
0 2
0 3
1 2
1 4
1 5
2 5
4 5
5 3
-1 -1
//ͼ�ľ���ͼ����ձ�Ŀ¼�µ�Graph_6.png�ļ�
*/
int main()
{
	GraphList *graphList = InitGraph(6);
	int result = 0;

	ReadGraph(graphList);
	WriteGraph(graphList);

	result = topologicalsort(graphList);
	if (result == 1)
	{
		printf("��������ɹ�\n");
	}
	else
	{
		printf("��������ʧ��\n");
	}

	return 0;
}