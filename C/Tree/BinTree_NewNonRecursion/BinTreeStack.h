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
/* ����:�ݹ齨��������											*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_Recursion();

/****************************************************************/
/* void PreOrder_NRecursion1(BinTree bt)						*/
/* ����:�ǵݹ��������[����1]									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion1(BinTree bt);

/****************************************************************/
/* void PreOrder_NRecursion2(BinTree bt)						*/
/* ����:�ǵݹ��������[����2]									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PreOrder_NRecursion2(BinTree bt);

/****************************************************************/
/* void InOrder_NRecursion(BinTree bt)							*/
/* ����:�ǵݹ��������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder_NRecursion(BinTree bt);

/****************************************************************/
/* void PostOrder_NRecursion(BinTree bt)						*/
/* ����:�ǵݹ�������											*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-14						Author:Cyber Kaka	*/
/****************************************************************/
void PostOrder_NRecursion(BinTree bt);

#endif // BINTREESTACK_H
