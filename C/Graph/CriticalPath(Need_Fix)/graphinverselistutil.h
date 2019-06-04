/*ͼ�����ڽӱ�����غ���*/
#ifndef GRAPHINVERSELISTUTIL_H
#define GRAPHINVERSELISTUTIL_H

//ͼ�Ľ������Ͷ���
typedef struct GRAPHINVERSELISTNODE_STRU
{
	int nodeno;	//ͼ�н��ı��
	int weight;	//ͼ����ص�Ȩֵ
	struct GRAPHINVERSELISTNODE_STRU * next;	//ָ����һ������ָ��
}GraphInverseListNode;

//ͼ�����Ͷ���
typedef struct GRAPHINVERSELIST_STRU
{
	int size;	//ͼ�н��ĸ���
	GraphInverseListNode * graphInverseListArray;	//ͼ�����ڽӱ�
}GraphInverseList;

/****************************************************************/
/* GraphInverseList* InitGraph(int num)							*/
/* ����:��ʼ��ͼ												*/
/* �������num:ͼ�н��ĸ���									*/
/* ����ֵ:�����ڽӱ��ʾ��ͼ									*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
GraphInverseList* InitInverseGraph(int num);

/****************************************************************/
/* void ReadInverseGraph(GraphInverseList* graphInverseList)	*/
/* ����:�����ݶ���ͼ��											*/
/* �������graphInverseList:ͼ									*/
/* ����ֵ:��													*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void ReadInverseGraph(GraphInverseList* graphInverseList);

/****************************************************************/
/* void WriteInverseGraph(GraphInverseList *graphInverseList)	*/
/* ����:��ͼ�Ľṹ��ʾ����										*/
/* �������graphInverseList:ͼ									*/
/* ����ֵ:��													*/
/* ��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void WriteInverseGraph(GraphInverseList *graphInverseList);

#endif	//	GRAPHINVERSELISTUTIL_H
