#include <stdio.h>
#include <stdlib.h>
#include "BinTreeThread.h"
#include "LinkStack.h"

/****************************************************************/
/* BinTree CreateBinTree()										*/
/* 功能:递归建立二叉树											*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-15						Author:Cyber Kaka	*/
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
		bt->lthread = 0;	//初始设置左标志位为0
		bt->leftchild = CreateBinTree();	//递归建立左子树
		bt->rthread = 0;	//初始设置右标志位为0
		bt->rightchild = CreateBinTree();	//递归建立右子树
	}
	return bt;
}

/****************************************************************/
/* void Create_InOrderThread(BinTree bt)						*/
/* 功能:对二叉树bt添加中序线索									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void Create_InOrderThread(BinTree bt)
{
	LinkStack st = SetNullStack_Link();
	BinTreeNode *p, *pr, *q;
	//二叉树为空,直接返回
	if (bt == NULL)
		return;
	//初始化p指针和pr指针
	p = bt;
	pr = NULL;
	//循环
	do
	{
		//当p非空,就进栈p结点,一直找左子树,直到底
		while (p != NULL)
		{
			Push_Link(st, p);
			p = p->leftchild;
		}
		//p无左子树,取栈顶元素
		p = Pop_seq_return(st);   //取栈顶元素
		Pop_Link(st);   //出栈栈顶元素
		//判断当前p的前驱pr,处理线索
		if (pr != NULL)
		{
			if (pr->rightchild == NULL)
			{
				//pr的右子树为空,设置rthread线索
				pr->rightchild = p;
				pr->rthread = 1;
			}
			if (p->leftchild == NULL)
			{
				//p的左子树为空,设置lthread线索
				p->leftchild = pr;
				p->lthread = 1;
			}
		}
		//继续处理下一个结点,保存当前的p给pr,作为下个结点的前驱
		pr = p;
		p = p->rightchild;
	} while (!IsNullStack_Link(st) || p != NULL);

	//中序穿线树建立时的特殊处理,第一个和最后一个结点
	p = bt;
	q = bt;
	//找到第一个结点
	while (p->leftchild != NULL)
	{
		p = p->leftchild;
	}//第一个结点是没有前驱的
	p->lthread = 1;   //对中序遍历的第一个结点特殊处理
	//找到最后一个结点
	while (q->rightchild != NULL)
	{
		q = q->rightchild;
	}//最后一个结点是没有后继的
	q->rthread = 1;  //对中序遍历的最后一个结点特殊处理
}

/****************************************************************/
/* void InOrder_ThreadBinTree(BinTree bt)						*/
/* 功能:中序遍历中序线索二叉树									*/
/* 输入参数:线索二叉树的根										*/
/* 返回值:无													*/
/* 创建日期:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_ThreadBinTree(BinTree bt)
{
	BinTreeNode *p;
	if (bt == NULL)
		return;
	p = bt;
	//沿着左子树一直向下寻找,直到找到第一个结点
	while (p->leftchild != NULL && p->lthread == 0)
		p = p->leftchild;
	while (p != NULL)
	{
		printf("%c ", p->data);
		printf("%d ", p->lthread);
		printf("%d \n", p->rthread);
		//rightchild指针不是线索而是右子树
		if (p->rightchild != NULL && p->rthread == 0)
		{
			p = p->rightchild;
			//顺其右子树的左子树一直向下,直到最左下结点
			while (p->leftchild != NULL && p->lthread == 0)
				p = p->leftchild;
		}
		//rightchild是线索
		else
			p = p->rightchild;  //顺着线索寻找
	}
}