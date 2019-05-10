#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

/****************************************************************/
/* SeqQueue SetNullQueue_seq(int m)								*/
/* ����:�����յ�ѭ������										*/
/* �������:��													*/
/* ����ֵ:�յ�ѭ������											*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
SeqQueue SetNullQueue_seq(int m)
{
	SeqQueue squeue;
	squeue = (SeqQueue)malloc(sizeof(struct Queue));
	//�������ʧ���򱨴�
	if (squeue == NULL)
	{
		printf("Alloc failure\n");
		return NULL;
	}
	//����ռ�ɹ�,����m��Ԫ�ؿռ�
	squeue->elem = (int*)malloc(sizeof(DataType)*m);
	//�����ն���
	if (squeue->elem != NULL)
	{
		squeue->MAX = m;
		squeue->f = 0;
		squeue->r = 0;
		return squeue;
	}
	//�����û����,��ֱ�ӷ��ؿ�
	return NULL;
}

/****************************************************************/
/* int IsNullQueue_seq(SeqQueue squeue)							*/
/* ����:�ж�һ��ѭ�������Ƿ�Ϊ��								*/
/* �������:squeue--ѭ������ָ��								*/
/* ����ֵ:�ն��з���1,���򷵻�0									*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_seq(SeqQueue squeue)
{
	//��ͷ��β�غ���Ϊ��,ע��ѭ�����е��пպ�����������
	return(squeue->f == squeue->r);
}

/****************************************************************/
/* void EnQueue_seq(SeqQueue squeue, DataType x)				*/
/* ����:����													*/
/* �������:squeue--ѭ������ָ��	x--����Ԫ��					*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_seq(SeqQueue squeue, DataType x)
{
	//�����ж��Ƿ�Ϊ������,ע�����������һ���ڴ�ռ�
	//Ҳ����˵�����Ҫһ��5���ѭ������,max=6�Ŷ�
	//����������1 2 3 4 5��ʱ��ֻ�����1 2 3 4
	if ((squeue->r + 1) % squeue->MAX == squeue->f)
	{
		printf("It is a full queue!\n");
	}
	else
	{
		squeue->elem[squeue->r] = x;
		squeue->r = (squeue->r + 1) % (squeue->MAX);
	}
}

/****************************************************************/
/* void DeQueue_seq(SeqQueue squeue)							*/
/* ����:����													*/
/* �������:squeue--ѭ������ָ��								*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_seq(SeqQueue squeue)
{
	//����ʱ�����п�,�пտ���ͨ�����ú���ʵ��
	//if (squeue->f == squeue->r)
	//{
	//	printf("It is an empty queue!\n");
	//}
	if (IsNullQueue_seq(squeue))
	{
		printf("It is an empty queue!\n");
	}
	else
	{
		squeue->f = (squeue->f + 1) % (squeue->MAX);
	}
}

/****************************************************************/
/* DataType FrontQueue_seq(SeqQueue squeue)						*/
/* ����:���ͷԪ�ص�ֵ											*/
/* �������:squeue--ѭ������ָ��								*/
/* ����ֵ:��													*/
/* ��������:2019-5-10						Author:Cyber Kaka	*/
/****************************************************************/
DataType FrontQueue_seq(SeqQueue squeue)
{
	//ȡԪ�ص�ʱ�����п�
	if (squeue->f == squeue->r)
	{
		printf("It is an empty queue!\n");
	}
	else
	{
		return(squeue->elem[squeue->f]);
	}
}