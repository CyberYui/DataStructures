#ifndef _LINKQUEUE_H
#define _LINKQUEUE_H
#include "BinTreeQueue.h"

typedef BinTreeNode *DataTypeQueue;//��������Ͷ�����֮ǰ�������в�ͬ
struct Node
{
	DataTypeQueue data;//������
	struct Node *next;//ָ����
};
typedef struct Node *PNode;//PNode���Ͷ���

struct Queue
{
	//ͷ����β���
	PNode f;
	PNode r;
};
typedef struct Queue *LinkQueue;

/****************************************************************/
/* LinkQueue SetNullQueue_Link()								*/
/* ����:�����ն���												*/
/* �������:��													*/
/* ����ֵ:�յ�������											*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
LinkQueue SetNullQueue_Link();

/****************************************************************/
/* int IsNullQueue_Link(LinkQueue lqueue)						*/
/* ����:�ж�һ���������Ƿ�Ϊ��									*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:�ն��з���1,���򷵻�0									*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_Link(LinkQueue lqueue);

/****************************************************************/
/* void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x)			*/
/* ����:����													*/
/* �������:lqueue--����ָ��	x--���ӽ��						*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x);

/****************************************************************/
/* void DeQueue_Link(LinkQueue lqueue)							*/
/* ����:����													*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_Link(LinkQueue lqueue);

/****************************************************************/
/* DataType FrontQueue_Link(LinkQueue lqueue)					*/
/* ����:ȡ��ͷԪ�ص�ֵ											*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
DataTypeQueue FrontQueue_Link(LinkQueue lqueue);

#endif // _LINKQUEUE_H
