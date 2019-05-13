#ifndef _BINTREE_H
#define _BINTREE_H

typedef char DataType;
typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *leftchild;
	struct BTreeNode *rightchild;
}BinTreeNode;
typedef BinTreeNode *BinTree;

/****************************************************************/
/* BinTree CreateBinTree_NonRecursion()							*/
/* 功能:非递归建立二叉树										*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_NonRecursion();

/****************************************************************/
/* void LevelOrder(BinTree bt)									*/
/* 功能:使用队列层次遍历二叉树									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void LevelOrder(BinTree bt);

#endif // _BINTREE_H
