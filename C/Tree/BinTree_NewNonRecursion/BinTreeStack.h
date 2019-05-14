#ifndef BINTREESTACK_H
#define BINTREESTACK_H

typedef char DataType;
typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *leftchild;
	struct BTreeNode *rightchild;
}BinTreeNode;
typedef BinTreeNode *BinTree;

/****************************************************************/
/* BinTree CreateBinTree_Recursion()							*/
/* 功能:递归建立二叉树											*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion();

/****************************************************************/
/* void PreOrder_NRecursion1(BinTree bt)						*/
/* 功能:非递归先序遍历[迭代1]									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion1(BinTree bt);

/****************************************************************/
/* void PreOrder_NRecursion2(BinTree bt)						*/
/* 功能:非递归先序遍历[迭代2]									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion2(BinTree bt);

/****************************************************************/
/* void InOrder_NRecursion(BinTree bt)							*/
/* 功能:非递归中序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_NRecursion(BinTree bt);

/****************************************************************/
/* void PostOrder_NRecursion(BinTree bt)						*/
/* 功能:非递归后序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_NRecursion(BinTree bt);

#endif // BINTREESTACK_H
