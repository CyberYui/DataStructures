/*ͼ���ڽӱ�����غ���*/
#ifndef GRAPHADJLISTUTIL_H
#define GRAPHADJLISTUTIL_H

//ͼ�Ľ������Ͷ���
typedef struct GRAPHLISTNODE_STRU
{
	int nodeno;	//ͼ�н��ı��
	int weight;	//ͼ����ص�Ȩֵ
	struct GRAPHLISTNODE_STRU * next;	//ָ����һ������ָ��
}GraphListNode;

//ͼ�����Ͷ���
typedef struct GRAPHLIST_STRU
{
	int size;	//ͼ�н��ĸ���
	GraphListNode * graphListArray;	//ͼ���ڽӱ�
}GraphList;

/****************************************************************/
/* GraphList* InitGraph(int num)								*/
/* ����:��ʼ��ͼ												*/
/* �������num:ͼ�н��ĸ���									*/
/* ����ֵ:���ڽӱ��ʾ��ͼ										*/
/* ��������:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
GraphList* InitGraph(int num);

/****************************************************************/
/* void ReadGraph(GraphList* graphList)							*/
/* ����:�����ݶ���ͼ��											*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphList* graphList);

/****************************************************************/
/* void WriteGraph(GraphList* graphList)						*/
/* ����:��ͼ�Ľṹ��ʾ����										*/
/* �������graphList:ͼ											*/
/* ����ֵ:��													*/
/* ��������:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphList* graphList);

#endif	//	GRAPHADJLISTUTIL_H
