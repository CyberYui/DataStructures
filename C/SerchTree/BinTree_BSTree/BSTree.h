#ifndef BSTREE_H
#define BSTREE_H

typedef int DataType;
//�����������ڵ㶨��
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
/* ����:��������������											*/
/* �������:��													*/
/* ����ֵ:����������											*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BinSearchTree create();

/****************************************************************/
/* void InOrder(BinSearchTree ptree)							*/
/* ����:�����������������										*/
/* �������ptree:����������										*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void InOrder(BinSearchTree ptree);

/****************************************************************/
/* BSTreeNode BSTSearch(BinSearchTree bt, DataType key)			*/
/* ����:��������������											*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫ������Ԫ��										*/
/* ����ֵ:�ɹ�����NULL,ʧ�ܷ���Ԫ�ز���ĸ����λ��				*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
BSTreeNode BSTSearch(BinSearchTree bt, DataType key);

/****************************************************************/
/* int BSTInsert(BinSearchTree bt, DataType key)				*/
/* ����:�ڶ����������в���Ԫ��key								*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫ�����Ԫ��										*/
/* ����ֵ:�ɹ����뷵��1,���򷵻�0								*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTInsert(BinSearchTree bt, DataType key);

/****************************************************************/
/* int BSTgetMax(BinSearchTree *bt)								*/
/* ����:���Ҷ��������������ֵ									*/
/* �������bt:�����������ĸ�									*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMax(BinSearchTree *bt);

/****************************************************************/
/* int BSTgetMin(BinSearchTree *bt)								*/
/* ����:���Ҷ�������������Сֵ									*/
/* �������bt:�����������ĸ�									*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BSTgetMin(BinSearchTree *bt);

/****************************************************************/
/* int BSTDelete1(BinSearchTree *bt, DataType key)				*/
/* ����:ɾ�������������е�Ԫ��key,����1							*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫɾ����Ԫ��										*/
/* ����ֵ:�ɹ�ɾ������1,���򷵻�0								*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete1(BinSearchTree *bt, DataType key);

/****************************************************************/
/* int BSTDelete2(BinSearchTree *bt, DataType key)				*/
/* ����:ɾ�������������е�Ԫ��key,����2							*/
/* �������bt:�����������ĸ�									*/
/* �������key:Ҫɾ����Ԫ��										*/
/* ����ֵ:�ɹ�ɾ������1,���򷵻�0								*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
int BSTDelete2(BinSearchTree *bt, DataType key);

/****************************************************************/
/* void BST_Destory(BinSearchTree bt)							*/
/* ����:���ٶ���������											*/
/* �������bt:�����������ĸ�									*/
/* ����ֵ:��													*/
/* ��������:2019-5-21						Author:Cyber Kaka	*/
/****************************************************************/
void BST_Destory(BinSearchTree bt);

#endif	// BSTREE_H
