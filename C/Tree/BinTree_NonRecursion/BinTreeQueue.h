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
/* ����:�ǵݹ齨��������										*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_NonRecursion();

/****************************************************************/
/* void LevelOrder(BinTree bt)									*/
/* ����:ʹ�ö��в�α���������									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void LevelOrder(BinTree bt);

#endif // _BINTREE_H
