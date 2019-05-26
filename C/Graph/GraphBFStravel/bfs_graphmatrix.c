/*�����ڽӾ����ʾ��ͼ���й�����ȱ�������*/

#include "bfs_graphmatrix.h"
#include <stdio.h>
#include <stdlib.h>

/****************************************************************/
/* void BFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* ����:ͼ�Ĺ�����ȱ���,�ڽӾ����ʾͼ							*/
/* �������graphMatrix:ͼ										*/
/* �������visited:���ڱ������״̬��һλ����					*/
/* �������i:�����											*/
/* ����ֵ:														*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j = 0;
	int tempVex = 0;
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();
	//���û�з��ʹ�,�����
	if (!visited[i])
	{
		visited[i] = 1;	//���ñ��,�����Ѿ������ʹ�
		printf("%d ", i);	//������ʵĽ����
		EnQueue_Link(waitingQueue, i);	//���շ��ʵĽ��������
		while (!IsNullQueue_Link(waitingQueue))
		{
			tempVex = FrontQueue_Link(waitingQueue);
			DeQueue_Link(waitingQueue);
			for (j = 0; j < graphMatrix->size; j++)
			{
				//������������뵱ǰ�������ڱ���δ���ʹ�
				if (graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j])
				{
					visited[j] = 1;	//�����
					EnQueue_Link(waitingQueue, j);	//���
					printf("%d ", j);	//���
				}//end if
			}//end for
		}//end while
	}//end if
}//end function

/****************************************************************/
/* void BFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* ����:ͼ�Ĺ�����ȱ���,�ڽӾ����ʾͼ							*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i = 0;

	//���ڼ�¼ͼ����Щ����Ѿ������ʹ���
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	//�������н�㶼û�б����ʹ�
	for (i = 0; i < graphMatrix->size; i++)
	{
		visited[i] = 0;
	}

	//��0�Ž�㿪ʼ���й�����ȱ���
	for (i = 0; i < graphMatrix->size; i++)
	{
		BFS(graphMatrix, visited, i);
	}//end
}