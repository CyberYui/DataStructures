#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "BinTreeStack.h"
//��ջ�����Ͷ���
typedef BinTree DataTypeStack;
struct Node
{
	DataTypeStack data;
	struct Node* next;
};
typedef struct Node *PNode;
typedef struct Node *LinkStack;

/****************************************/
/* ��������:��������ջ					*/
/* �������:��							*/
/* ����ֵ:�յ���ջ						*/
/****************************************/
LinkStack SetNullStack_Link();

/****************************************/
/* ��������:�ж�һ����ջ�Ƿ�Ϊ��		*/
/* �������:��ջջ��ָ��				*/
/* ����ֵ:����ջΪ���򷵻�1,���򷵻�0	*/
/****************************************/
int IsNullStack_Link(LinkStack lstack);

/****************************************/
/* ��������:��ջ						*/
/* �������:lstack--��ջջ��ָ��		*/
/* �������:x--��ջԪ��					*/
/* ����ֵ:��							*/
/****************************************/
void Push_Link(LinkStack lstack, DataTypeStack x);

/****************************************/
/* ��������:��ջջ��Ԫ��				*/
/* �������:lstack--��ջջ��ָ��		*/
/* ����ֵ:��							*/
/****************************************/
void Pop_Link(LinkStack lstack);

/****************************************/
/* ��������:ȡ��ջ��Ԫ��				*/
/* �������:lstack--��ջջ��ָ��		*/
/* ����ֵ:ջ��Ԫ�ص�ֵ					*/
/****************************************/
DataTypeStack Pop_seq_return(LinkStack lstack);

#endif // LINKSTACK_H
