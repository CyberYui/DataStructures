#include <stdio.h>
#include <stdlib.h>
#include "BinTreeThread.h"
#include "LinkStack.h"

/****************************************************************/
/* BinTree CreateBinTree()										*/
/* ����:�ݹ齨��������											*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree()
{
	char ch = 'a';
	BinTree bt;
	scanf_s("%c", &ch, sizeof(char));
	if (ch == '@')
	{
		bt = NULL;
	}
	else
	{
		bt = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		bt->data = ch;
		bt->lthread = 0;	//��ʼ�������־λΪ0
		bt->leftchild = CreateBinTree();	//�ݹ齨��������
		bt->rthread = 0;	//��ʼ�����ұ�־λΪ0
		bt->rightchild = CreateBinTree();	//�ݹ齨��������
	}
	return bt;
}

/****************************************************************/
/* void Create_InOrderThread(BinTree bt)						*/
/* ����:�Զ�����bt�����������									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void Create_InOrderThread(BinTree bt)
{
	LinkStack st = SetNullStack_Link();
	BinTreeNode *p, *pr, *q;
	//������Ϊ��,ֱ�ӷ���
	if (bt == NULL)
		return;
	//��ʼ��pָ���prָ��
	p = bt;
	pr = NULL;
	//ѭ��
	do
	{
		//��p�ǿ�,�ͽ�ջp���,һֱ��������,ֱ����
		while (p != NULL)
		{
			Push_Link(st, p);
			p = p->leftchild;
		}
		//p��������,ȡջ��Ԫ��
		p = Pop_seq_return(st);   //ȡջ��Ԫ��
		Pop_Link(st);   //��ջջ��Ԫ��
		//�жϵ�ǰp��ǰ��pr,��������
		if (pr != NULL)
		{
			if (pr->rightchild == NULL)
			{
				//pr��������Ϊ��,����rthread����
				pr->rightchild = p;
				pr->rthread = 1;
			}
			if (p->leftchild == NULL)
			{
				//p��������Ϊ��,����lthread����
				p->leftchild = pr;
				p->lthread = 1;
			}
		}
		//����������һ�����,���浱ǰ��p��pr,��Ϊ�¸�����ǰ��
		pr = p;
		p = p->rightchild;
	} while (!IsNullStack_Link(st) || p != NULL);

	//������������ʱ�����⴦��,��һ�������һ�����
	p = bt;
	q = bt;
	//�ҵ���һ�����
	while (p->leftchild != NULL)
	{
		p = p->leftchild;
	}//��һ�������û��ǰ����
	p->lthread = 1;   //����������ĵ�һ��������⴦��
	//�ҵ����һ�����
	while (q->rightchild != NULL)
	{
		q = q->rightchild;
	}//���һ�������û�к�̵�
	q->rthread = 1;  //��������������һ��������⴦��
}

/****************************************************************/
/* void InOrder_ThreadBinTree(BinTree bt)						*/
/* ����:���������������������									*/
/* �������:�����������ĸ�										*/
/* ����ֵ:��													*/
/* ��������:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_ThreadBinTree(BinTree bt)
{
	BinTreeNode *p;
	if (bt == NULL)
		return;
	p = bt;
	//����������һֱ����Ѱ��,ֱ���ҵ���һ�����
	while (p->leftchild != NULL && p->lthread == 0)
		p = p->leftchild;
	while (p != NULL)
	{
		printf("%c ", p->data);
		printf("%d ", p->lthread);
		printf("%d \n", p->rthread);
		//rightchildָ�벻����������������
		if (p->rightchild != NULL && p->rthread == 0)
		{
			p = p->rightchild;
			//˳����������������һֱ����,ֱ�������½��
			while (p->leftchild != NULL && p->lthread == 0)
				p = p->leftchild;
		}
		//rightchild������
		else
			p = p->rightchild;  //˳������Ѱ��
	}
}