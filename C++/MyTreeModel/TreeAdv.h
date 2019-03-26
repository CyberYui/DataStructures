#ifndef TREEADV_H
#define TREEADV_H

#include "NodeAdv.h"

class Tree
{
public:
	Tree();														//������
	~Tree();													//������
	Node *SearchNode(int nodeIndex);							//�������
	bool AddNode(int nodeIndex, int direction, Node *pNode);	//��ӽ��
	bool DeleteNode(int nodeIndex, Node *pNode);				//ɾ�����
	void PreorderTraversal();									//ǰ�����
	void InorderTraversal();									//�������
	void PostorderTraversal();									//�������
protected:
private:
	Node *m_pRoot;
};

#endif // TREEADV_H
