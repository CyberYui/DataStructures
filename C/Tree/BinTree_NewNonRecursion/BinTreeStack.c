#include <stdio.h>
#include <stdlib.h>
#include "BinTreeStack.h"
#include "LinkStack.h"

/****************************************************************/
/* BinTree CreateBinTree_Recursion()							*/
/* ����:�ݹ齨��������											*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion()
{
	char ch = 'a';//��ʼ��
	BinTree bt;
	scanf_s("%c", &ch, sizeof(ch));
	//ʹ��scanf_s("%c", &ch);�ᱨ��
	//����Warning:C4473 ��scanf_s��: û��Ϊ��ʽ�ַ��������㹻�Ĳ���
	//����취
	//���չٷ�����,��Ҫ�������Ӧ�ı�����С
	//scanf_s("%9s", s, _countof(s)); // buffer size is 10, width specification is 9
	//scanf_s("%c", &ch);��Ϊscanf_s("%c", &ch, sizeof(ch));

	//����@��ʾNULL
	if (ch == '@')
	{
		bt = NULL;
	}
	else
	{
		bt = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		bt->data = ch;
		//�ݹ鸳ֵ������
		bt->leftchild = CreateBinTree_Recursion();
		//�ݹ鸳ֵ������
		bt->rightchild = CreateBinTree_Recursion();
	}
	//���ظ��ڵ�
	return bt;
}

/****************************************************************/
/* void PreOrder_NRecursion1(BinTree bt)						*/
/* ����:�ǵݹ��������[����1]									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion1(BinTree bt)
{
	LinkStack lstack;   //������ջ
	lstack = SetNullStack_Link();   //��ʼ��ջ
	BinTreeNode *p;
	Push_Link(lstack, bt);   //�������ջ
	//ѭ�������˵ݹ�ľ���ʵ������,����Ҳ�ܿ���ָ�������
	while (!IsNullStack_Link(lstack))
	{
		p = Pop_seq_return(lstack);
		Pop_Link(lstack);
		printf("%c", p->data);   //���ʽ��
		//��Ϊ��ջ,�Ǻ���ȳ�,�����Ƚ��Һ���,�������
		if (p->rightchild)
			Push_Link(lstack, p->rightchild);    //����������,��ջ
		if (p->leftchild)
			Push_Link(lstack, p->leftchild);     //����������,��ջ
	}
}

/****************************************************************/
/* void PreOrder_NRecursion2(BinTree bt)						*/
/* ����:�ǵݹ��������[����2]									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion2(BinTree bt)
{
	LinkStack lstack;   //������ջ
	BinTreeNode *p = bt;
	lstack = SetNullStack_Link();   //��ʼ��ջ
	if (bt == NULL)
		return;
	Push_Link(lstack, bt);
	//���ջ����,��ѭ������ջ
	while (!IsNullStack_Link(lstack))
	{
		//ȡջ�����,Ȼ�����
		p = Pop_seq_return(lstack);
		Pop_Link(lstack);   //��ջ
		while (p)
		{
			printf("%c", p->data);   //���ʽ��
			if (p->rightchild)
				//���Һ���Ϊ��,�򲻽�ջ
				Push_Link(lstack, p->rightchild); //�Һ��ӽ�ջ
			p = p->leftchild;
		}
	}
}

/****************************************************************/
/* void InOrder_NRecursion(BinTree bt)							*/
/* ����:�ǵݹ��������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_NRecursion(BinTree bt)
{
	LinkStack lstack;   //������ջ
	lstack = SetNullStack_Link();   //��ʼ��ջ
	BinTree p;
	p = bt;
	if (p == NULL)
		return;
	Push_Link(lstack, bt);   //�������ջ
	//һֱѰ��������,ֱ���ײſ�ʼ
	p = p->leftchild;   //����������
	//ֻҪp����ջ�ǿ�,�͵���
	while (p || !IsNullStack_Link(lstack))
	{
		//p��Ϊ��,һֱ��������,����ջ����
		while (p != NULL)
		{
			Push_Link(lstack, p);
			p = p->leftchild;
		}
		//�ҵ��׵�ʱ��ʼ��ջ,��ջһ�����Ӿ�ɨ���Һ���
		p = Pop_seq_return(lstack);
		Pop_Link(lstack);
		printf("%c", p->data);   //���ʽ��
		p = p->rightchild;  //�������ǿ�,ɨ��������
		//ѭ��Ѱ����������������
	}
	//��������:ջ��
}//�㷨ʱ�临�Ӷ�O(n)

/****************************************************************/
/* void PostOrder_NRecursion(BinTree bt)						*/
/* ����:�ǵݹ�������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_NRecursion(BinTree bt)
{
	BinTree p = bt;
	LinkStack lstack;   //������ջ
	//������Ϊ��,ֱ�ӷ���
	if (bt == NULL)
		return;
	lstack = SetNullStack_Link();   //��ʼ��ջ
	//p�ǿջ���ջ�ǿ�,��ʼѭ��
	while (p != NULL || !IsNullStack_Link(lstack))
	{
		//���p����,��һֱ����ȥ
		while (p != NULL)
		{
			Push_Link(lstack, p);
			p = p->leftchild ? p->leftchild : p->rightchild;    //�������о�ѹ��,����ѹ�ҽ�ջ
		}
		//�ձ�ʾΪҶ�ӽ��,���Ҷ�û��
		p = Pop_seq_return(lstack);   //ջ����ջ
		Pop_Link(lstack);
		printf("%c", p->data);   //���ʽ��
		//���ջ�ǿ���ջ�����������Ǹոճ�ջ�Ľ��
		if (!IsNullStack_Link(lstack) && (Pop_seq_return(lstack)->leftchild == p))
			//��Ϊ����,���Ի�Ҫ���ұߵ�
			p = (Pop_seq_return(lstack))->rightchild; //���������˻�,����������
		else
			p = NULL;   //���������˻�,������һ��
	}//ѭ����������:ջ�ջ�p��
}