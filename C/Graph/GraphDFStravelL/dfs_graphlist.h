#ifndef DFS_GRAPHLIST_H
#define DFS_GRAPHLIST_H

#include "graphlistutil.h"

/****************************************************************/
/* void DFS(GraphList* graphList, int * visited, int i)			*/
/* ����:ͼ��������ȱ����ݹ��㷨,�ڽӱ��ʾͼ					*/
/* �������graphList:ͼ											*/
/* �������visited:�������(���õ��Ƿ񱻷��ʹ�)��һά����		*/
/* �������i:�����											*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphList* graphList, int * visited, int i);

/****************************************************************/
/* void GFSGraphList(GraphList* graphList)						*/
/* ����:��ȱ���,�ڽӱ��ʾͼ									*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphList(GraphList* graphList);

#endif	//	DFS_GRAPHLIST_H
