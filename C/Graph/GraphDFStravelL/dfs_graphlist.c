/*ͼ��������ȱ����㷨,���ڽӱ��ʾ��ͼ*/

#include <stdio.h>
#include <stdlib.h>
#include "dfs_graphlist.h"

/****************************************************************/
/* void DFS(GraphList* graphList, int * visited, int i)			*/
/* ����:ͼ��������ȱ����ݹ��㷨,�ڽӱ��ʾͼ					*/
/* �������graphList:ͼ											*/
/* �������visited:�������(���õ��Ƿ񱻷��ʹ�)��һά����		*/
/* �������i:�����											*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphList* graphList, int * visited, int i)
{
	int j = 0;
	GraphListNode *tempNode = NULL;
	visited[i] = 1;
	printf("%d ", i);

	tempNode = graphList->graphListArray[i].next;
	while (tempNode != NULL)
	{
		if (!visited[tempNode->nodeno])
		{
			DFS(graphList, visited, tempNode->nodeno);
		}
		tempNode = tempNode->next;	
	}
}

/****************************************************************/
/* void GFSGraphList(GraphList* graphList)						*/
/* ����:��ȱ���,�ڽӱ��ʾͼ									*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphList(GraphList* graphList)
{
	int i = 0;
	//���ڼ�¼ͼ����Щ����Ѿ���������
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	//��ʼ��Ϊ�㶼û�б����ʹ�
	for (i = 0; i < graphList->size; i++)
	{
		visited[i] = 0;
	}

	for (i = 0; i < graphList->size; i++)
	{
		//��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ��
		if (!visited[i])
		{
			DFS(graphList, visited, i);
		}
	}
}