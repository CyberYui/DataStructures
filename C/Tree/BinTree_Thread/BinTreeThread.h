#ifndef _BINTREETHREAD_H
#define _BINTREETHREAD_H

typedef char DataType;
typedef struct BTreeNode
{
	DataType data;
	struct BTreeNode *leftchild;
	struct BTreeNode *rightchild;
	int lthread;
	int rthread;
}BinTreeNode;
typedef BinTreeNode *BinTree;

/****************************************************************/
/* BinTree CreateBinTree()										*/
/* 功能:递归建立二叉树											*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree();

/****************************************************************/
/* void Create_InOrderThread(BinTree bt)						*/
/* 功能:对二叉树bt添加中序线索									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void Create_InOrderThread(BinTree bt);

/****************************************************************/
/* void InOrder_ThreadBinTree(BinTree bt)						*/
/* 功能:中序遍历中序线索二叉树									*/
/* 输入参数:线索二叉树的根										*/
/* 返回值:无													*/
/* 创建日期:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_ThreadBinTree(BinTree bt);

#endif // _BINTREETHREAD_H
