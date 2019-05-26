#ifndef BFS_GRAPHLIST_H
#define BFS_GRAPHLIST_H

#include "graphlistutil.h"

/****************************************************************/
/* void BFS(GraphList* graphList, int * visited, int i)			*/
/* ����:���ڽӱ��ʾ��ͼ���й�����ȱ���						*/
/* �������graphList:ͼ,�ڽӱ��ʾ								*/
/* �������visited:���ڱ�ǽ���Ƿ񱻷��ʹ���һλ����			*/
/* �������i:�����											*/
/* ����ֵ:��													*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphList* graphList, int * visited, int i);

/****************************************************************/
/* void BFSGraphList(GraphList* graphList)						*/
/* ����:ͼ�Ĺ�����ȱ���,�ڽӱ��ʾͼ							*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphList(GraphList* graphList);

#endif	//	BFS_GRAPHLIST_H
