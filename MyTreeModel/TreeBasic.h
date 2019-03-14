#ifndef TREEBASIC_H
#define TREEBASIC_H

/****************************************************************************/
/*  ������:Tree(��Լ���������int)
/*
/*	Tree(int size);											//������
/*	~Tree();												//������
/*	int *SearchNode(int nodeIndex);						//��������Ѱ�ҽ��
/*	bool AddNode(int nodeIndex, int direction, int *pNode);	//��ӽ��
/*	bool DeleteNode(int nodeIndex, int *pNode);				//ɾ�����
/*	void TreeTraverse();									//�������
/* (C��������)
/*	   BOOL CreateTree(Tree **pTree,Node *pRoot);		//������
/*	   void DestroyTree(Tree *pTree);					//������
/*	   Node *SearchNode(Tree *pTree,int nodeIndex);		//��������Ѱ�ҽڵ�
/*			//��ӽڵ�
/*	   BOOL AddNode(Tree *pTree,int nodeIndex,int direction,Node *pNode);
/*	   BOOL DeleteNode(Tree *pTree,int nodeIndex,Node *pNode);//ɾ���ڵ�
/*	   void TreeTraverse(Tree *pTree);					//����
/*  ����ʱ��:2019-3-13
/*	Author:Cyber Kaka
/****************************************************************************/

class Tree
{
public:
	Tree(int size, int *pRoot);/*���Ĵ�С,���ڵ�*/			//������
	~Tree();												//������
	int *SearchNode(int nodeIndex);							//��������Ѱ�ҽ��
	bool AddNode(int nodeIndex, int direction, int *pNode);	//��ӽ��
	bool DeleteNode(int nodeIndex, int *pNode);				//ɾ�����
	void TreeTraverse();									//�������
protected:
private:
	int *m_pTree;		//����ָ����Ӧ�����ָ��
	int m_iSize;		//��¼��С
};

#endif // TREEBASIC_H
