#ifndef BSTREE_H
#define BSTREE_H

typedef int DataType;
//二叉排序树节点定义
struct BinSearchTreeNode
{
	DataType data;
	struct BinSearchTreeNode *leftchild;
	struct BinSearchTreeNode *rightchild;
};
typedef struct BinSearchTreeNode *BSTreeNode;
typedef struct BinSearchTreeNode *BinSearchTree;

/****************************************************************/
/* BinSearchTree *create()										*/
/* 功能:创建二叉排序树											*/
/* 输入参数:无													*/
/* 返回值:二叉排序树											*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BinSearchTree create();

/****************************************************************/
/* void InOrder(BinSearchTree ptree)							*/
/* 功能:中序遍历二叉排序树										*/
/* 输入参数ptree:二叉排序树										*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder(BinSearchTree ptree);

/****************************************************************/
/* BSTreeNode BSTSearch(BinSearchTree bt, DataType key)			*/
/* 功能:检索二叉排序树											*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要检索的元素										*/
/* 返回值:成功返回NULL,失败返回元素插入的父结点位置				*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BSTreeNode BSTSearch(BinSearchTree bt, DataType key);

/****************************************************************/
/* int BSTInsert(BinSearchTree bt, DataType key)				*/
/* 功能:在二叉排序树中插入元素key								*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要插入的元素										*/
/* 返回值:成功插入返回1,否则返回0								*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTInsert(BinSearchTree bt, DataType key);

/****************************************************************/
/* int BSTgetMax(BinSearchTree *bt)								*/
/* 功能:查找二叉排序树的最大值									*/
/* 输入参数bt:二叉排序树的根									*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMax(BinSearchTree bt);

/****************************************************************/
/* int BSTgetMin(BinSearchTree *bt)								*/
/* 功能:查找二叉排序树的最小值									*/
/* 输入参数bt:二叉排序树的根									*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMin(BinSearchTree bt);

/****************************************************************/
/* int BSTDelete1(BinSearchTree *bt, DataType key)				*/
/* 功能:删除二叉排序树中的元素key,方法1							*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要删除的元素										*/
/* 返回值:成功删除返回1,否则返回0								*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete1(BinSearchTree *bt, DataType key);

/****************************************************************/
/* int BSTDelete2(BinSearchTree *bt, DataType key)				*/
/* 功能:删除二叉排序树中的元素key,方法2							*/
/* 输入参数bt:二叉排序树的根									*/
/* 输入参数key:要删除的元素										*/
/* 返回值:成功删除返回1,否则返回0								*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete2(BinSearchTree *bt, DataType key);

/****************************************************************/
/* void BST_Destory(BinSearchTree bt)							*/
/* 功能:销毁二叉排序树											*/
/* 输入参数bt:二叉排序树的根									*/
/* 返回值:无													*/
/* 创建日期:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BST_Destory(BinSearchTree bt);

#endif	// BSTREE_H
