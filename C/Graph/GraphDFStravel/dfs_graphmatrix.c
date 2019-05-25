/*ͼ��������ȱ���ʵ��,���ڽӾ����ʾͼ*/
#include <stdio.h>
#include <stdlib.h>
#include "dfs_graphmatrix.h"

/****************************************************************/
/* void DFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* ����:ͼ��������ȱ����ݹ��㷨,�ڽӾ����ʾͼ					*/
/* �������graphMatrix:ͼ										*/
/* �������visited:�������(���õ��Ƿ񱻷���)��һλ����			*/
/* �������i:������ʼ�Ľ����									*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j = 0;
	//���ȶԶ������,���Ϊ�ѷ��ʹ�
	visited[i] = 1;
	printf("%d ", i);	//����
	//�ݹ�ʵ��������ȱ���
	for (j = 0; j < graphMatrix->size; j++)
	{
		//���i��j�б�����,����jû�б����ʹ�
		if (graphMatrix->graph[i][j] != INT_MAX && !visited[j])
		{
			DFS(graphMatrix, visited, j);	//��j����������ȱ���
		}
	}
}

/****************************************************************/
/* void DFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* ����:��ȱ���,�ڽӾ����ʾͼ									*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i = 0;
	//���ڼ�¼ͼ����Щ����Ѿ���������
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	//��ʼ��Ϊ�㶼û�б�����
	for (i = 0; i < graphMatrix->size; i++)
	{
		visited[i] = 0;
	}
	//��0������ʼ���ʽ��,ֻҪ��û���ʹ��ľͶ������������ȱ���,
	//�������ܷ��ʵ����е���ͨ����
	for (i = 0; i < graphMatrix->size; i++)
	{
		//��δ���ʹ��Ķ������DFS,������ͨͼ,��ֻ��ִ��һ��
		if (!visited[i])
		{
			DFS(graphMatrix, visited, i);
		}
	}
}