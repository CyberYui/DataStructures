/*ͼ�Ĺ�����ȱ���,���ڽӱ��ʾ��ͼ*/
#include "bfs_graphlist.h"
#include <stdio.h>
#include "LinkQueue.h"
/****************************************************************/
/* void BFS(GraphList* graphList, int * visited, int i)			*/
/* ����:���ڽӱ��ʾ��ͼ���й�����ȱ���						*/
/* �������graphList:ͼ,�ڽӱ��ʾ								*/
/* �������visited:���ڱ�ǽ���Ƿ񱻷��ʹ���һλ����			*/
/* �������i:�����											*/
/* ����ֵ:��													*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphList* graphList, int * visited, int i)
{
	int tempVex = 0;
	GraphListNode *tempNode = NULL;

	//������ȱ���ʹ�õĶ�����c++��STL(��׼ģ���)�е�queue
	//������,C�������޷�ʹ�ñ�׼ģ����,������Ƶû�и������д���,��Ϊ��Ҳ�ܲ�����
	//������ԭ�ȵ�������
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();

	//���û�з��ʹ�,�����
	if (!visited[i])
	{
		visited[i] = 1;	//���ñ��,�����Ѿ������ʹ���
		printf("%d ", i);	//������ʵĽ��ı��
		EnQueue_Link(waitingQueue,i);	//���շ��ʵĽ��������
		//��ʼ������ȱ������
		while (!IsNullQueue_Link(waitingQueue))
		{
			tempVex = FrontQueue_Link(waitingQueue);
			DeQueue_Link(waitingQueue);
			//���η����뵱ǰ������ڵĵ�
			tempNode = graphList->graphListArray[tempVex].next;
			while (tempNode!=NULL)
			{
				//������������뵱ǰ������ڱ���δ�����ʹ�
				if (!visited[tempNode->nodeno])
				{
					visited[tempNode->nodeno] = 1;	//�����
					EnQueue_Link(waitingQueue, tempNode->nodeno);	//���
					printf("%d ", tempNode->nodeno);	//���
				}//end if

				//�ƶ�����һ�����
				tempNode = tempNode->next;
			}//end while
		}//end while
	}//end if
}

/****************************************************************/
/* void BFSGraphList(GraphList* graphList)						*/
/* ����:ͼ�Ĺ�����ȱ���,�ڽӱ��ʾͼ							*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphList(GraphList* graphList)
{
	int i = 0;

	//���ڼ�¼ͼ����Щ����Ѿ������ʹ���
	int *visited = (int*)malloc(sizeof(int) * graphList->size);
	//����ᱨ����,���Ժ���
	//warning C4013: ��malloc��δ���壻�����ⲿ���� int

	//�������н�㶼û�б����ʹ�
	for (i = 0; i < graphList->size; i++)
	{
		visited[i] = 0;
	}

	//��0�Ž�㿪ʼ���й�����ȱ���
	for (i = 0; i < graphList->size; i++)
	{
		BFS(graphList, visited, i);
	}//end
}