#include <stdlib.h>
#include <stdio.h>
#include "LinkedStack.h"

//��������ͷ���Ŀ���ջ
LinkedStack SetNullStack_Link()
{
	//������ռ�
	LinkedStack top = (LinkedStack)malloc(sizeof(struct Node));
	if (top != NULL)
	{
		top->next = NULL;	//ͷ���֮��ΪNULL,��Ϊ�ǿ�ջ
	}
	else
	{
		printf("Alloc failure!\n");
	}
	return top; //����ջ��ָ��
}

//�ж���ջ�Ƿ�Ϊ��
int IsNullStack_link(LinkedStack top)
{
	if (top->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//��ջ
void Push_link(LinkedStack top, DataType x)
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
		p->next = top->next;    //ָ����ֵ
		top->next = p;          //�޸�ջ��
	}
}

//��ջջ��Ԫ��
void Pop_link(LinkedStack top)
{
	PNode p;
	if (IsNullStack_link(top))
	{
		printf("It is an empty stack!\n");
	}
	else
	{
		p = top->next;          //pָ���ɾ�����
		top->next = p->next;    //�޸�ջ��ָ��
		free(p);                //�ͷ�Ҫɾ���Ľ��Ŀռ�,���ɾ��
	}
}

//ȡջ��Ԫ��
DataType Pop_seq_return(LinkedStack top)
{
	//�ж�ջ�Ƿ�Ϊ��
	if (IsNullStack_link(top))
	{
		printf("It is an empty stack!\n");
		return 0;	//��ΪDataType����int����
	}
	else
	{
		return top->next->data;
	}
}