#ifndef NODEADV_H
#define NODEADV_H

class Node
{
public:
	Node();//���캯��,���ڳ�ʼ��

	//Ϊ��Ѱ�ҽ��,����һ�����ڵݹ�ĺ���,Ҳ��Ѱ��Node����
	Node *SearchNode(int nodeIndex);

	//���ڵ�����SearchNode,���Բ���Ҫ��ɾ����ʱ���������ж���
	//��Ϊ�ܵ�ɾ����һ����,һ���Ǳ��ҵ��˵Ľ��
	//��Tree��bool DeleteNode(int nodeIndex, Node *pNode)��ͬ
	//����û���ж�,���Բ���Ҫ���з���ֵ��
	//��������֮��Ĳ�������Tree��ͬ�������н��е�
	void DeleteNode();

	//ǰ������Ĺ���ʵ��
	void PreorderTraversal();

	//��������Ĺ���ʵ��
	void InorderTraversal();

	//��������Ĺ���ʵ��
	void PostorderTraversal();

	int index;//��������
	int data;//����������
	Node *pLChild;//����ָ��
	Node *pRChild;//�Һ���ָ��
	Node *pParent;//���׽��ָ��
};

#endif // NODEADV_H
