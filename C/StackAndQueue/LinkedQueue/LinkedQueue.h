#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

typedef int DataType;
struct Node
{
	DataType data;//������
	struct Node *next;//ָ����
};
typedef struct Node *PNode;//PNode���Ͷ���

struct Queue
{
	//ͷ����β���
	PNode f;
	PNode r;
};
typedef struct Queue *LinkedQueue;

/****************************************************************/
/* LinkedQueue SetNullQueue_Link()								*/
/* ����:�����ն���												*/
/* �������:��													*/
/* ����ֵ:�յ�������											*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
LinkedQueue SetNullQueue_Link();

/****************************************************************/
/* int IsNullQueue_Link(LinkedQueue lqueue)						*/
/* ����:�ж�һ���������Ƿ�Ϊ��									*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:�ն��з���1,���򷵻�0									*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_Link(LinkedQueue lqueue);

/****************************************************************/
/* void EnQueue_Link(LinkedQueue lqueue, DataType x)			*/
/* ����:����													*/
/* �������:lqueue--����ָ��	x--����Ԫ��						*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_Link(LinkedQueue lqueue, DataType x);

/****************************************************************/
/* void DeQueue_Link(LinkedQueue lqueue)						*/
/* ����:����													*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_Link(LinkedQueue lqueue);

/****************************************************************/
/* DataType FrontQueue_Link(LinkedQueue lqueue)					*/
/* ����:ȡ��ͷԪ�ص�ֵ											*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
DataType FrontQueue_Link(LinkedQueue lqueue);

#endif // LINKEDQUEUE_H
