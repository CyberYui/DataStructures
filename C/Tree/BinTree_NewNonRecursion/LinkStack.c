#include <stdlib.h>
#include <stdio.h>
#include "LinkStack.h"

//��������ͷ���Ŀ���ջ
LinkStack SetNullStack_Link()
{
	//������ռ�
	LinkStack lstack = (LinkStack)malloc(sizeof(struct Node));
	if (lstack != NULL)
	{
		lstack->next = NULL;	//ͷ���֮��ΪNULL,��Ϊ�ǿ�ջ
	}
	else
	{
		printf("Alloc failure!\n");
	}
	return lstack; //����ջ��ָ��
}

//�ж���ջ�Ƿ�Ϊ��
int IsNullStack_Link(LinkStack lstack)
{
	if (lstack->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//��ջ
void Push_Link(LinkStack lstack, DataTypeStack x)
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node)); //������ռ�
	if (p == NULL)
	{
		printf("Alloc failure!\n");
	}
	else
	{
		p->data = x;            //������ֵ
		p->next = lstack->next;    //ָ����ֵ
		lstack->next = p;          //�޸�ջ��
	}
}

//��ջջ��Ԫ��
void Pop_Link(LinkStack lstack)
{
	PNode p;
	if (IsNullStack_Link(lstack))
	{
		printf("It is an empty stack!\n");
	}
	else
	{
		p = lstack->next;          //pָ���ɾ�����
		lstack->next = p->next;    //�޸�ջ��ָ��
		free(p);                //�ͷ�Ҫɾ���Ľ��Ŀռ�,���ɾ��
	}
}

//ȡջ��Ԫ��
DataTypeStack Pop_seq_return(LinkStack lstack)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (IsNullStack_Link(lstack))
	{
		printf("It is an empty stack!\n");
		return 0;	//��ΪDataType����int����
	}
	else
	{
		return lstack->next->data;
	}
}