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
/* ����:�ݹ齨��������											*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion();//Recursion n.�ݹ�

/****************************************************************/
/* void PreOrder_Recursion(BinTree t)							*/
/* ����:�ݹ��������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_Recursion(BinTree t);

/****************************************************************/
/* void InOrder_Recursion(BinTree t)							*/
/* ����:�ݹ��������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_Recursion(BinTree t);

/****************************************************************/
/* void PostOrder_Recursion(BinTree t)							*/
/* ����:�ݹ�������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_Recursion(BinTree t);

/****************************************************************/
/* void DestroyBinTree(BinTree t)								*/
/* ����:���ٶ�����												*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-12						Author:Cyber Kaka	*/
/****************************************************************/
void DestroyBinTree(BinTree t);

#endif // BINTREE_H
