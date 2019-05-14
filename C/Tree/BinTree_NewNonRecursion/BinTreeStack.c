#include <stdio.h>
#include <stdlib.h>
#include "BinTreeStack.h"
#include "LinkStack.h"

/****************************************************************/
/* BinTree CreateBinTree_Recursion()							*/
/* 功能:递归建立二叉树											*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion()
{
	char ch = 'a';//初始化
	BinTree bt;
	scanf_s("%c", &ch, sizeof(ch));
	//使用scanf_s("%c", &ch);会报错
	//关于Warning:C4473 “scanf_s”: 没有为格式字符串传递足够的参数
	//解决办法
	//参照官方定义,需要添加上相应的变量大小
	//scanf_s("%9s", s, _countof(s)); // buffer size is 10, width specification is 9
	//scanf_s("%c", &ch);改为scanf_s("%c", &ch, sizeof(ch));

	//定义@表示NULL
	if (ch == '@')
	{
		bt = NULL;
	}
	else
	{
		bt = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		bt->data = ch;
		//递归赋值左子树
		bt->leftchild = CreateBinTree_Recursion();
		//递归赋值右子树
		bt->rightchild = CreateBinTree_Recursion();
	}
	//返回根节点
	return bt;
}

/****************************************************************/
/* void PreOrder_NRecursion1(BinTree bt)						*/
/* 功能:非递归先序遍历[迭代1]									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion1(BinTree bt)
{
	LinkStack lstack;   //定义链栈
	lstack = SetNullStack_Link();   //初始化栈
	BinTreeNode *p;
	Push_Link(lstack, bt);   //根结点入栈
	//循环表现了递归的具体实现内容,这里也能看到指针的妙用
	while (!IsNullStack_Link(lstack))
	{
		p = Pop_seq_return(lstack);
		Pop_Link(lstack);
		printf("%c", p->data);   //访问结点
		//因为是栈,是后进先出,所以先进右孩子,后进左孩子
		if (p->rightchild)
			Push_Link(lstack, p->rightchild);    //右子树不空,进栈
		if (p->leftchild)
			Push_Link(lstack, p->leftchild);     //左子树不空,进栈
	}
}

/****************************************************************/
/* void PreOrder_NRecursion2(BinTree bt)						*/
/* 功能:非递归先序遍历[迭代2]									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion2(BinTree bt)
{
	LinkStack lstack;   //定义链栈
	BinTreeNode *p = bt;
	lstack = SetNullStack_Link();   //初始化栈
	if (bt == NULL)
		return;
	Push_Link(lstack, bt);
	//如果栈不空,则循环访问栈
	while (!IsNullStack_Link(lstack))
	{
		//取栈顶结点,然后访问
		p = Pop_seq_return(lstack);
		Pop_Link(lstack);   //出栈
		while (p)
		{
			printf("%c", p->data);   //访问结点
			if (p->rightchild)
				//若右孩子为空,则不进栈
				Push_Link(lstack, p->rightchild); //右孩子进栈
			p = p->leftchild;
		}
	}
}

/****************************************************************/
/* void InOrder_NRecursion(BinTree bt)							*/
/* 功能:非递归中序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_NRecursion(BinTree bt)
{
	LinkStack lstack;   //定义链栈
	lstack = SetNullStack_Link();   //初始化栈
	BinTree p;
	p = bt;
	if (p == NULL)
		return;
	Push_Link(lstack, bt);   //根结点入栈
	//一直寻找左子树,直到底才开始
	p = p->leftchild;   //进入左子树
	//只要p或者栈非空,就迭代
	while (p || !IsNullStack_Link(lstack))
	{
		//p不为空,一直找左子树,并进栈左孩子
		while (p != NULL)
		{
			Push_Link(lstack, p);
			p = p->leftchild;
		}
		//找到底的时候开始出栈,出栈一个左孩子就扫描右孩子
		p = Pop_seq_return(lstack);
		Pop_Link(lstack);
		printf("%c", p->data);   //访问结点
		p = p->rightchild;  //右子树非空,扫描右子树
		//循环寻找右子树的左子树
	}
	//结束条件:栈空
}//算法时间复杂度O(n)

/****************************************************************/
/* void PostOrder_NRecursion(BinTree bt)						*/
/* 功能:非递归后序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_NRecursion(BinTree bt)
{
	BinTree p = bt;
	LinkStack lstack;   //定义链栈
	//二叉树为空,直接返回
	if (bt == NULL)
		return;
	lstack = SetNullStack_Link();   //初始化栈
	//p非空或者栈非空,开始循环
	while (p != NULL || !IsNullStack_Link(lstack))
	{
		//如果p不空,就一直找下去
		while (p != NULL)
		{
			Push_Link(lstack, p);
			p = p->leftchild ? p->leftchild : p->rightchild;    //左子树有就压左,否则压右进栈
		}
		//空表示为叶子结点,左右都没有
		p = Pop_seq_return(lstack);   //栈顶出栈
		Pop_Link(lstack);
		printf("%c", p->data);   //访问结点
		//如果栈非空且栈顶结点的左孩子是刚刚出栈的结点
		if (!IsNullStack_Link(lstack) && (Pop_seq_return(lstack)->leftchild == p))
			//因为是左,所以还要看右边的
			p = (Pop_seq_return(lstack))->rightchild; //从左子树退回,进入右子树
		else
			p = NULL;   //从右子树退回,返回上一层
	}//循环结束条件:栈空或p空
}