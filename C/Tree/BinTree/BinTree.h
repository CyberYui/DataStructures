#ifndef BINTREE_H
#define BINTREE_H

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
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion();//Recursion n.递归

/****************************************************************/
/* void PreOrder_Recursion(BinTree t)							*/
/* 功能:递归先序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_Recursion(BinTree t);

/****************************************************************/
/* void InOrder_Recursion(BinTree t)							*/
/* 功能:递归中序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_Recursion(BinTree t);

/****************************************************************/
/* void PostOrder_Recursion(BinTree t)							*/
/* 功能:递归后序遍历											*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_Recursion(BinTree t);

/****************************************************************/
/* void DestroyBinTree(BinTree t)								*/
/* 功能:销毁二叉树												*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void DestroyBinTree(BinTree t);

#endif // BINTREE_H
