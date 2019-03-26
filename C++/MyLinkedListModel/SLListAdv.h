#ifndef SLLISTADV_H
#define SLLISTADV_H
#include "NodeAdv.h"

/************************************************************************/
/* ��Ա����:
/*	 List();							//�������Ա�(������)
/*	 ~List();							//�������Ա�(������)
/*	 void ClearList();					//������Ա�(������)
/*	 bool ListEmpty();					//�ж����Ա�(������)�Ƿ�Ϊ��
/*	 int ListLength();					//��ȡ���Ա�(������)����
/*	 bool ListInsertHead(Node *pNode);	//��ͷ������
/*	 bool ListInsertTail(Node *pNode);	//��β������
/*	 bool GetElem(int i, Node *pNode);	//��ȡָ��λ�õĽ�㲢�����pNode
/*	 int LocateElem(Node *pNode);		//Ѱ�ҵ�һ������pNode�����ݽ���λ��
/*
/*	 //��ȡָ��Ԫ�ص�ǰ��
/*	 bool PriorElem(Node *pCurrentNode, Node *pPreNode);
/*
/*	 //��ȡָ��Ԫ�صĺ��
/*	 bool NextElem(Node *pCurrentNode, Node *pNextNode);
/*	 void ListTraverse();				 //�������Ա�(������)
/*	 bool ListInsert(int i, Node *pNode);//�ڵ�i��λ�ò�����
/*	 bool ListDelete(int i, Node *pNode);//ɾ����i��λ�õĽ��
/* ���ݳ�Ա:
/*	 Node *m_pList;
/*	 int m_iLength;
/************************************************************************/

class List
{
public:
	List();								//�������Ա�(������)
	~List();							//�������Ա�(������)
	void ClearList();					//������Ա�(������)
	bool ListEmpty();					//�ж����Ա�(������)�Ƿ�Ϊ��
	int ListLength();					//��ȡ���Ա�(������)����
	bool GetElem(int i, Node *pNode);	//��ȡָ��λ�õĽ�㲢�����pNode
	int LocateElem(Node *pNode);		//Ѱ�ҵ�һ������pNode�����ݽ���λ��

	//��ȡָ��Ԫ�ص�ǰ��
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);

	//��ȡָ��Ԫ�صĺ��
	bool NextElem(Node *pCurrentNode, Node *pNextNode);
	void ListTraverse();				 //�������Ա�(������)
	bool ListInsert(int i, Node *pNode); //�ڵ�i��λ�ò�����
	bool ListDelete(int i, Node *pNode); //ɾ����i��λ�õĽ��
	bool ListInsertHead(Node *pNode);	 //��ͷ������
	bool ListInsertTail(Node *pNode);	 //��β������
protected:
private:
	Node *m_pList;
	int m_iLength;
};
#endif // SLLISTADV_H
