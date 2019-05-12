#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

/****************************************************************/
/* BinTree CreateBinTree_Recursion()							*/
/* 功能:递归建立二叉树,特别注意这里的返回值						*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion()
{
	char ch = 'a';//初始化
	BinTree t;
	scanf_s("%c", &ch, sizeof(ch));
	//使用scanf_s("%c", &ch);会报错
	//关于Warning:C4473 “scanf_s”: 没有为格式字符串传递足够的参数
	//解决办法
	//参照官方定义,需要添加上相应的变量大小
	//scanf_s("%9s", s, _countof(s)); // buffer size is 10, width specification is 9
	//scanf_s("%c", &ch);改为scanf_s("%c", &ch, sizeof(ch));

	//定义@表示NULL
	if (ch=='@')
	{
		t = NULL;
	}
	else
	{
		t = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		t->data = ch;
		//递归赋值左子树
		t->leftchild = CreateBinTree_Recursion();
		//递归赋值右子树
		t->rightchild = CreateBinTree_Recursion();
	}
	//返回根节点
	return t;
}

/****************************************************************/
/* void PreOrder_Recursion(BinTree t)							*/
/* 功能:递归先序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
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
/* 功能:递归中序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
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
/* 功能:递归后序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
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
/* 功能:销毁二叉树												*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void DestroyBinTree(BinTree t)
{
	if (t!=NULL)
	{
		//逆着销毁,防止链断
		DestroyBinTree(t->leftchild);//递归销毁左子树
		DestroyBinTree(t->rightchild);//递归销毁右子树
		//最后再销毁根
		free(t);
	}
}