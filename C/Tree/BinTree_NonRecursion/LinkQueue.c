#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/****************************************************************/
/* LinkQueue SetNullQueue_Link()								*/
/* ����:�����ն���												*/
/* �������:��													*/
/* ����ֵ:�յ�������											*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
LinkQueue SetNullQueue_Link()
{
	LinkQueue lqueue;
	lqueue = (LinkQueue)malloc(sizeof(struct Queue));
	if (lqueue != NULL)
	{
		lqueue->f = NULL;
		lqueue->r = NULL;
	}
	else
	{
		printf("Alloc Failure!\n");
	}
	return lqueue;
}

/****************************************************************/
/* int IsNullQueue_Link(LinkQueue lqueue)						*/
/* ����:�ж�һ���������Ƿ�Ϊ��									*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:�ն��з���1,���򷵻�0									*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
int IsNullQueue_Link(LinkQueue lqueue)
{
	return(lqueue->f == NULL);
}

/****************************************************************/
/* void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x)			*/
/* ����:����													*/
/* �������:lqueue--����ָ��	x--���ӽ��						*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void EnQueue_Link(LinkQueue lqueue, DataTypeQueue x)
{
	PNode p;//��ʱ���
	p = (PNode)malloc(sizeof(struct Node));
	//����ʧ���򱨴�
	if (p == NULL)
	{
		printf("Alloc Failure!\n");
	}
	//����ɹ�
	else
	{
		//������ʱ�����������ָ����,���ڴ������
		p->data = x;
		p->next = NULL;
		//�ж϶����Ƿ�ǿ�
		if (lqueue->f == NULL)
		{
			lqueue->f = p;
			lqueue->r = p;
		}
		else
		{
			lqueue->r->next = p;
			lqueue->r = p;
		}
	}
}

/****************************************************************/
/* void DeQueue_Link(LinkQueue lqueue)							*/
/* ����:����													*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void DeQueue_Link(LinkQueue lqueue)
{
	//���ӻ��漰����ͷ�Ĳ���

	struct Node *p;//��ʱ���ָ��,���ڹ۲�����
	//�����ж϶����Ƿ�Ϊ��
	if (lqueue->f == NULL)
	{
		printf("It is an empty queue!\n");
	}
	else
	{
		p = lqueue->f;
		lqueue->f = lqueue->f->next;
		//�ͷ���ʱ���ָ��
		free(p);
	}
}

/****************************************************************/
/* DataTypeQueue FrontQueue_Link(LinkQueue lqueue)				*/
/* ����:ȡ��ͷԪ�ص�ֵ											*/
/* �������:lqueue--����ָ��									*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
DataTypeQueue FrontQueue_Link(LinkQueue lqueue)
{
	if (lqueue->f == NULL)
	{
		printf("It is an empty queue!\n");
		return 0;
	}
	else
		return(lqueue->f->data);
}