#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

/****************************************************************/
/* BinSearchTree create()										*/
/* 功能:创建二叉排序树,注意这里输入的应该是先序序列,并且保证是一*/
/*		个二叉排序树的先序序列									*/
/* 输入参数:无													*/
/* 返回值:二叉排序树											*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BinSearchTree create()
{
	int ch = 0;//初始化
	BinSearchTree bt;
	scanf_s("%d", &ch);
	if (ch == -1)
	{
		bt = NULL;
	}
	else
	{
		bt = (BSTreeNode *)malloc(sizeof(struct BinSearchTreeNode));
		bt->leftchild = NULL;
		bt->rightchild = NULL;
		bt->data = ch;
		//递归赋值左子树
		bt->leftchild = create();
		//递归赋值右子树
		bt->rightchild = create();
	}
	//返回根节点
	return bt;
}

/****************************************************************/
/* void InOrder(BinSearchTree ptree)							*/
/* 功能:中序遍历二叉排序树										*/
/* 输入参数ptree:二叉排序树										*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder(BinSearchTree ptree)
{
	if (ptree == NULL)
	{
		return;
	}
	InOrder(ptree->leftchild);
	printf("%d ", ptree->data);
	InOrder(ptree->rightchild);
}

/****************************************************************/
/* BSTreeNode BSTSearch(BinSearchTree bt, DataType key)			*/
/* 功能:检索二叉排序树											*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要检索的元素										*/
/* 返回值:成功返回NULL,失败返回元素插入的父结点位置				*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BSTreeNode BSTSearch(BinSearchTree bt, DataType key)
{
	BSTreeNode p, parent;
	p = bt;
	parent = p; //记录待插入结点的父结点
	while (p)
	{
		parent = p;
		//当查找到时提示,返回NULL
		if (p->data == key)
		{
			printf("Exist this key\n");
			return NULL;
		}
		//根结点大于要查的结点,进入左分支查找
		if (p->data > key)
		{
			p = p->leftchild;
		}
		//根结点小于要查的结点,进入右分支查找
		else
		{
			p = p->rightchild;
		}
	}//p=NULL,跳出循环
	return parent;  //查找失败,返回parent
}//return NULL和parent是为了便于之后的操作

/****************************************************************/
/* int BSTInsert(BinSearchTree bt, DataType key)				*/
/* 功能:在二叉排序树中插入元素key								*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要插入的元素										*/
/* 返回值:成功插入返回1,否则返回0								*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTInsert(BinSearchTree bt, DataType key)
{
	BSTreeNode p, temp;
	temp = BSTSearch(bt, key);   //temp保存查找之后的结果
	//已存在,返回0
	if (temp == NULL)
	{
		printf("Exist this key\n");
		return 0;
	}
	//申请结点的内存空间
	p = (BSTreeNode *)malloc(sizeof(struct BinSearchTreeNode));
	//左右子树初始化
	p->leftchild = NULL;
	p->rightchild = NULL;
	//申请失败提示
	if (p == NULL)
	{
		printf("Alloc Failure!\n");
		return 0;
	}
	p->data = key;  //数据域赋值,左右指针域默认为空
	//p->leftchild = NULL;  //左子树指针域赋值
	//p->rightchild = NULL; //右子树指针域赋值
	if (key < temp->data)
	{
		temp->leftchild = p;    //作为左子树插入
	}
	else
	{
		temp->rightchild = p;   //作为右子树插入
	}
	return 1;
}

/****************************************************************/
/* int BSTgetMax(BinSearchTree bt)								*/
/* 功能:查找二叉排序树的最大值									*/
/* 输入参数bt:二叉排序树的根									*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMax(BinSearchTree bt)
{
	BSTreeNode temp;
	temp = bt;
	if (temp)
	{
		while (temp->leftchild)
		{
			temp = temp->leftchild;
		}
		printf("%d \n", temp->data);
	}
}

/****************************************************************/
/* int BSTgetMin(BinSearchTree bt)								*/
/* 功能:查找二叉排序树的最小值									*/
/* 输入参数bt:二叉排序树的根									*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMin(BinSearchTree bt)
{
	BSTreeNode temp;
	temp = bt;
	if (temp)
	{
		while (temp->rightchild)
		{
			temp = temp->rightchild;
		}
		printf("%d \n", temp->data);
	}
}

/****************************************************************/
/* int BSTDelete1(BinSearchTree *bt, DataType key)				*/
/* 功能:删除二叉排序树中的元素key,方法1							*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要删除的元素										*/
/* 返回值:成功删除返回1,否则返回0								*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete1(BinSearchTree *bt, DataType key)
{
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	//查找被删除的结点
	while (p != NULL)
	{
		if (p->data == key)
			break;  //查找到了,跳出循环
		parent = p; //注意这一句
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//查询结束
	if (p == NULL)
	{
		printf("%d not exist\n", key);
		return 0;
	}
	//只有右子树的情况
	if (p->leftchild == NULL)
	{
		//如果被删除的结点是根结点,那就要修改的是二叉排序树的根
		if (parent == NULL)
			*bt = p->rightchild;
		//检查是左孩子还是右孩子
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		else
			parent->rightchild = p->rightchild;
	}
	//既有左子树也有右子树
	if (p->leftchild != NULL)
	{
		BSTreeNode parentp; //parentp记录maxpl的父结点
		parentp = p;
		maxpl = p->leftchild;
		//对称遍历中,右侧的总是大的数
		//定位p的左子树中的最大结点maxpl
		while (maxpl->rightchild != NULL)
		{
			parentp = maxpl;
			maxpl = maxpl->rightchild;
		}
		p->data = maxpl->data;  //修改p的数据域为maxpl的值
		if (parentp == p)    //如果maxpl的父结点是p
			p->leftchild = maxpl->leftchild;    //修改p结点的左指针
		else
			parentp->rightchild = maxpl->leftchild; //修改父结点的右指针
		p = maxpl;  //更新p指针为maxpl结点以便删除
	}
	//释放空间
	free(p);
	return 1;
}

/****************************************************************/
/* int BSTDelete2(BinSearchTree *bt, DataType key)				*/
/* 功能:删除二叉排序树中的元素key,方法2							*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要删除的元素										*/
/* 返回值:成功删除返回1,否则返回0								*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete2(BinSearchTree *bt, DataType key)
{
	//parent记录p的父结点,maxpl记录p的左子树中的关键码最大结点
	BSTreeNode parent, p, maxpl;
	p = *bt;
	parent = NULL;
	//查找被删除的结点
	while (p != NULL)
	{
		if (p->data == key)
			break;  //查找到了,跳出循环
		parent = p; //注意这一句
		if (p->data > key)
			p = p->leftchild;
		else
			p = p->rightchild;
	}//查找结束
	if (p == NULL)
	{
		printf("%d not exist!\n", key);
		return 0;
	}
	//只有右子树的情况
	if (p->leftchild == NULL)
	{
		//删除的是根结点,做特殊处理
		if (parent == NULL)
			*bt = p->rightchild;
		//p是父结点parent的左孩子,则修改父结点的左指针
		else if (parent->leftchild == p)
			parent->leftchild = p->rightchild;
		else
			parent->rightchild = p->rightchild;
	}
	//以上和方法1几乎完全相同

	//有左子树和右子树
	if (p->leftchild != NULL)
	{
		maxpl = p->leftchild;
		//定位左子树中的最大结点maxpl
		while (maxpl->rightchild != NULL)
			maxpl = maxpl->rightchild;
		maxpl->rightchild = p->rightchild;
		if (parent == NULL)
			*bt = p->leftchild;
		//p是父结点parent的左孩子,则修改父结点的左指针
		else if (parent->leftchild == p)
			parent->leftchild = p->leftchild;
		//p是父结点parent的右孩子,则修改父结点的右指针
		else
			parent->rightchild = p->leftchild;
	}
	free(p);    //释放结点p
	return 1;
}

/****************************************************************/
/* void BST_Destory(BinSearchTree *bt)							*/
/* 功能:递归销毁二叉排序树										*/
/* 输入参数bt:二叉排序树的根									*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
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