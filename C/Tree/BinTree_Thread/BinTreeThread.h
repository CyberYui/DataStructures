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
/* ����:�ݹ齨��������											*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree();

/****************************************************************/
/* void Create_InOrderThread(BinTree bt)						*/
/* ����:�Զ�����bt�����������									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void Create_InOrderThread(BinTree bt);

/****************************************************************/
/* void InOrder_ThreadBinTree(BinTree bt)						*/
/* ����:���������������������									*/
/* �������:�����������ĸ�										*/
/* ����ֵ:��													*/
/* ��������:2019-5-15						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_ThreadBinTree(BinTree bt);

#endif // _BINTREETHREAD_H
