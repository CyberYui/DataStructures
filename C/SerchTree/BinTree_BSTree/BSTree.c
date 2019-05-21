#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

/****************************************************************/
/* BinSearchTree create()										*/
/* ����:��������������,ע�����������Ӧ������������,���ұ�֤��һ*/
/*		����������������������									*/
/* �������:��													*/
/* ����ֵ:����������											*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BinSearchTree create()
{
	int ch = 0;//��ʼ��
	BinSearchTree bt;
	scanf_s("%d", &ch);
	if (ch == -1)
	{
		bt = NULL;
	}
	else
	{
		bt = (BSTreeNode *)malloc(sizeof(struct BinSearchTreeNode));
		bt->data = ch;
		//�ݹ鸳ֵ������
		bt->leftchild = create();
		//�ݹ鸳ֵ������
		bt->rightchild = create();
	}
	//���ظ��ڵ�
	return bt;
}

/****************************************************************/
/* void InOrder(BinSearchTree ptree)							*/
/* ����:�����������������										*/
/* �������ptree:����������										*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder(BinSearchTree ptree)
{
	if (ptree == NULL)
	{
		return;
	}
	InOrder(ptree->leftchild);
	printf("%d", ptree->data);
	InOrder(ptree->rightchild);
}

/****************************************************************/
/* BSTreeNode BSTSearch(BinSearchTree bt, DataType key)			*/
/* ����:��������������											*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫ������Ԫ��										*/
/* ����ֵ:�ɹ�����NULL,ʧ�ܷ���Ԫ�ز���ĸ����λ��				*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BSTreeNode BSTSearch(BinSearchTree bt, DataType key)
{
	BSTreeNode p, parent;
	p = bt;
	parent = p; //��¼��������ĸ����
	while (p)
	{
		parent = p;
		//�����ҵ�ʱ��ʾ,����NULL
		if (p->data == key)
		{
			printf("Exist this key\n");
			return NULL;
		}
		//��������Ҫ��Ľ��,�������֧����
		if (p->data > key)
		{
			p = p->leftchild;
		}
		//�����С��Ҫ��Ľ��,�����ҷ�֧����
		else
		{
			p = p->rightchild;
		}
	}//p=NULL,����ѭ��
	return parent;  //����ʧ��,����parent
}//return NULL��parent��Ϊ�˱���֮��Ĳ���

/****************************************************************/
/* int BSTInsert(BinSearchTree bt, DataType key)				*/
/* ����:�ڶ����������в���Ԫ��key								*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫ�����Ԫ��										*/
/* ����ֵ:�ɹ����뷵��1,���򷵻�0								*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTInsert(BinSearchTree bt, DataType key)
{
	BSTreeNode p, temp;
	temp = BSTSearch(bt, key);   //temp�������֮��Ľ��
	//�Ѵ���,����0
	if (temp == NULL)
	{
		printf("Exist this key\n");
		return 0;
	}
	//��������ڴ�ռ�
	p = (BSTreeNode *)malloc(sizeof(struct BinSearchTreeNode));
	//����ʧ����ʾ
	if (p == NULL)
	{
		printf("Alloc Failure!\n");
		return 0;
	}
	p->data = key;  //������ֵ,����ָ����Ĭ��Ϊ��
	//p->leftchild = NULL;  //������ָ����ֵ
	//p->rightchild = NULL; //������ָ����ֵ
	if (key < temp->data)
	{
		temp->leftchild = p;    //��Ϊ����������
	}
	else
	{
		temp->rightchild = p;   //��Ϊ����������
	}
	return 1;
}

/****************************************************************/
/* int BSTgetMax(BinSearchTree bt)								*/
/* ����:���Ҷ��������������ֵ									*/
/* �������bt:�����������ĸ�									*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMax(BinSearchTree *bt)
{
	BSTreeNode temp;
	temp = bt;
	if (temp)
	{
		while (temp->leftchild)
		{
			temp = temp->leftchild;
		}
		printf("%d", temp->data);
	}
}

/****************************************************************/
/* int BSTgetMin(BinSearchTree bt)								*/
/* ����:���Ҷ�������������Сֵ									*/
/* �������bt:�����������ĸ�									*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMin(BinSearchTree *bt)
{
	BSTreeNode temp;
	temp = bt;
	if (temp)
	{
		while (temp->rightchild)
		{
			temp = temp->rightchild;
		}
		printf("%d", temp->data);
	}
}

/****************************************************************/
/* int BSTDelete1(BinSearchTree *bt, DataType key)				*/
/* ����:ɾ�������������е�Ԫ��key,����1							*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫɾ����Ԫ��										*/
/* ����ֵ:�ɹ�ɾ������1,���򷵻�0								*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete1(BinSearchTree *bt, DataType key)
{
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	//���ұ�ɾ���Ľ��
	while (p != NULL)
	{
		if (p->data == key)
			break;  //���ҵ���,����ѭ��
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//��ѯ����
	if (p == NULL)
	{
		printf("%d not exist\n", key);
		return 0;
	}
	//ֻ�������������
	if (p->leftchild == NULL)
	{
		//�����ɾ���Ľ���Ǹ����,�Ǿ�Ҫ�޸ĵ��Ƕ����������ĸ�
		if (parent == NULL)
			*bt = p->rightchild;
		//��������ӻ����Һ���
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		else
			parent->rightchild = p->rightchild;
	}
	//����������Ҳ��������
	if (p->leftchild != NULL)
	{
		BSTreeNode parentp; //parentp��¼maxpl�ĸ����
		parentp = p;
		maxpl = p->leftchild;
		//�ԳƱ�����,�Ҳ�����Ǵ����
		//��λp���������е������maxpl
		while (maxpl->rightchild != NULL)
		{
			parentp = maxpl;
			maxpl = maxpl->rightchild;
		}
		p->data = maxpl->data;  //�޸�p��������Ϊmaxpl��ֵ
		if (parentp == p)    //���maxpl�ĸ������p
			p->leftchild = maxpl->leftchild;    //�޸�p������ָ��
		else
			parentp->rightchild = maxpl->leftchild; //�޸ĸ�������ָ��
		p = maxpl;  //����pָ��Ϊmaxpl����Ա�ɾ��
	}
	//�ͷſռ�
	free(p);
	return 1;
}

/****************************************************************/
/* int BSTDelete2(BinSearchTree *bt, DataType key)				*/
/* ����:ɾ�������������е�Ԫ��key,����2							*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫɾ����Ԫ��										*/
/* ����ֵ:�ɹ�ɾ������1,���򷵻�0								*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete2(BinSearchTree *bt, DataType key)
{
	//parent��¼p�ĸ����,maxpl��¼p���������еĹؼ��������
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	//���ұ�ɾ���Ľ��
	while (p != NULL)
	{
		if (p->data == key)
			break;  //���ҵ���,����ѭ��
		parent = p; //ע����һ��
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//���ҽ���
	if (p == NULL)
	{
		printf("%d not exist!\n", key);
		return 0;
	}
	//ֻ�������������
	if (p->leftchild == NULL)
	{
		//ɾ�����Ǹ����,�����⴦��
		if (parent == NULL)
			*bt = p->rightchild;
		//p�Ǹ����parent������,���޸ĸ�������ָ��
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		else
			parent->rightchild = p->rightchild;
	}
	//���Ϻͷ���1������ȫ��ͬ

	//����������������
	if (p->leftchild != NULL)
	{
		maxpl = p->leftchild;
		//��λ�������е������maxpl
		while (maxpl->rightchild != NULL)
			maxpl = maxpl->rightchild;
		maxpl->rightchild = p->rightchild;
		if (parent == NULL)
			*bt = p->leftchild;
		//p�Ǹ����parent������,���޸ĸ�������ָ��
		else if (parent->leftchild == p)
			parent->leftchild = p->leftchild;
		//p�Ǹ����parent���Һ���,���޸ĸ�������ָ��
		else
			parent->rightchild = p->leftchild;
	}
	free(p);    //�ͷŽ��p
	return 1;
}

/****************************************************************/
/* void BST_Destory(BinSearchTree *bt)							*/
/* ����:�ݹ����ٶ���������										*/
/* �������bt:�����������ĸ�									*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BST_Destory(BinSearchTree bt)
{
	if (bt)
	{
		BST_Destory(bt->leftchild);
		BST_Destory(bt->rightchild);
		free(bt);
	}
}