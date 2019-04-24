#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"

//������˳��ջ
SeqStack SetNullStack_seq(int m)
{
	//�������sstack
	SeqStack sstack = (SeqStack)malloc(sizeof(struct SeqStack));
	if (sstack != NULL)
	{
		//����ṹ��ռ�ɹ�,��ʼ��������ռ�
		sstack->elem = (int*)malloc(sizeof(int)*m);
		if (sstack->elem != NULL)
		{
			//��������ռ�ɹ�,��ʼ��ʼ��
			sstack->MAX = m;	//˳��ջ�������
			sstack->top = -1;	//����ջ����ֵΪ-1,����ѹ��Ԫ�ؾͻ��0��ʼ
			return(sstack);		//���س�ʼ���˵�ջ
		}
		else
		{
			//����ṹ��ռ�ɹ�,����������ռ�ʧ��
			free(sstack);//�ͷŽṹ��ռ�
			return NULL;
		}
	}
	else
	{
		//����ռ�ʧ��
		printf("out of space!");
		return NULL;
	}
}

//�ж�˳��ջ�Ƿ�Ϊ��
int IsNullStack_seq(SeqStack sstack)
{
	return(sstack->top == -1);    //���ջ��top�Ƿ�Ϊ-1
}

//�ж�˳��ջ�Ƿ�Ϊ��
int IsFullStack_seq(SeqStack sstack)
{
	//���ջ���Ƿ��Ѿ��ﵽ�����ֵ,�����0��,������MAX-1
	return(sstack->top >= sstack->MAX - 1);
}

//��ջ
void Push_seq(SeqStack sstack, int x)
{
	//ѹ��xԪ�ؽ���ջ��
	if (IsFullStack_seq(sstack))
	{
		printf("Overflow!\n");
	}
	else
	{
		sstack->top++;                    //������,���޸�ջ������
		sstack->elem[sstack->top] = x;    //��Ԫ��x�ŵ�ջ��������λ����
	}
}

//��ջ
void Pop_seq(SeqStack sstack)
{
	//��ջ��Ԫ�س�ջ
	if (IsNullStack_seq(sstack))
	{
		//�ж�ջ�Ƿ�Ϊ��,Ϊ������ʾ
		printf("Underflow!\n");
	}
	else
	{
		//ջ�ǿ�,��ջջ��Ԫ��,ջ���߼�-1����,ԭ���ݻᱻ�´���ջ�����ǵ�
		sstack->top = sstack->top - 1;    //ջ����1
	}
}

//ȡջ��Ԫ��
DataType Top_seq(SeqStack sstack)
{
	if (IsNullStack_seq(sstack))
	{
		//�ж�ջ�Ƿ�Ϊ��,Ϊ������ʾ
		printf("It is an empty stack!\n");
		return 0;
	}
	else
	{
		return sstack->elem[sstack->top];
	}
}