#ifndef SEQQUEUE_H
#define SEQQUEUE_H

typedef int DataType;

struct Queue
{
	int MAX;	//ѭ�����е��������
	int f;		//��ͷ
	int r;		//��β
	DataType *elem;	//����Ԫ����ʼλ��
};
typedef struct Queue *SeqQueue;

/****************************************************************/
/* SeqQueue SetNullQueue_seq(int m)								*/
/* ����:�����յ�ѭ������										*/
/* �������:��													*/						
/* ����ֵ:�յ�ѭ������											*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
SeqQueue SetNullQueue_seq(int m);

/****************************************************************/
/* int IsNullQueue_seq(SeqQueue squeue)							*/
/* ����:�ж�һ��ѭ�������Ƿ�Ϊ��								*/
/* �������:squeue--ѭ������ָ��								*/
/* ����ֵ:�ն��з���1,���򷵻�0									*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_seq(SeqQueue squeue);

/****************************************************************/
/* void EnQueue_seq(SeqQueue squeue, DataType x)				*/
/* ����:����													*/
/* �������:squeue--ѭ������ָ��	x--����Ԫ��					*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_seq(SeqQueue squeue, DataType x);

/****************************************************************/
/* void DeQueue_seq(SeqQueue squeue)							*/
/* ����:����													*/
/* �������:squeue--ѭ������ָ��								*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_seq(SeqQueue squeue);

/****************************************************************/
/* DataType FrontQueue_seq(SeqQueue squeue)						*/
/* ����:���ͷԪ�ص�ֵ											*/
/* �������:squeue--ѭ������ָ��								*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
DataType FrontQueue_seq(SeqQueue squeue);

#endif	// SEQQUEUE_H
