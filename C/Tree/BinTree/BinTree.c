#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

/****************************************************************/
/* BinTree CreateBinTree_Recursion()							*/
/* ����:�ݹ齨��������,�ر�ע������ķ���ֵ						*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion()
{
	char ch = 'a';//��ʼ��
	BinTree t;
	scanf_s("%c", &ch, sizeof(ch));
	//ʹ��scanf_s("%c", &ch);�ᱨ��
	//����Warning:C4473 ��scanf_s��: û��Ϊ��ʽ�ַ��������㹻�Ĳ���
	//����취
	//���չٷ�����,��Ҫ�������Ӧ�ı�����С
	//scanf_s("%9s", s, _countof(s)); // buffer size is 10, width specification is 9
	//scanf_s("%c", &ch);��Ϊscanf_s("%c", &ch, sizeof(ch));

	//����@��ʾNULL
	if (ch=='@')
	{
		t = NULL;
	}
	else
	{
		t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		t->data = ch;
		//�ݹ鸳ֵ������
		t->leftchild = CreateBinTree_Recursion();
		//�ݹ鸳ֵ������
		t->rightchild = CreateBinTree_Recursion();
	}
	//���ظ��ڵ�
	return t;
}

/****************************************************************/
/* void PreOrder_Recursion(BinTree t)							*/
/* ����:�ݹ��������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_Recursion(BinTree t)
{
	if (t==NULL)
	{
		return;
	}
	printf("%c", t->data);
	PreOrder_Recursion(t->leftchild);
	PreOrder_Recursion(t->rightchild);
}

/****************************************************************/
/* void InOrder_Recursion(BinTree t)							*/
/* ����:�ݹ��������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_Recursion(BinTree t)
{
	if (t==NULL)
	{
		return;
	}
	InOrder_Recursion(t->leftchild);
	printf("%c", t->data);
	InOrder_Recursion(t->rightchild);
}

/****************************************************************/
/* void PostOrder_Recursion(BinTree t)							*/
/* ����:�ݹ�������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_Recursion(BinTree t)
{
	if (t==NULL)
	{
		return;
	}
	PostOrder_Recursion(t->leftchild);
	PostOrder_Recursion(t->rightchild);
	printf("%c", t->data);
}

/****************************************************************/
/* void DestroyBinTree(BinTree t)								*/
/* ����:���ٶ�����												*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void DestroyBinTree(BinTree t)
{
	if (t!=NULL)
	{
		//��������,��ֹ����
		DestroyBinTree(t->leftchild);//�ݹ�����������
		DestroyBinTree(t->rightchild);//�ݹ�����������
		//��������ٸ�
		free(t);
	}
}