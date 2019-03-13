#ifndef SINGLELINKEDLISTBASIC_H
#define SINGLELINKEDLISTBASIC_H
#include "NodeBasic.h"

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
/*	 Node *m_pList;			//���ڴ�Ž������ָ��
/*	 int m_iLength;			//����ͳ�������ȵĳ�Ա����
/************************************************************************/

class List
{
public:
	//Node��ʾ���
	//������˳���������,�乹�캯���������������Ǳ����
	//��������,���ӿ�ʼ����Ҫһ����������,�����Node,������Ҫ��ʱ����Node����
	List();				//�������Ա�(������)
	~List();			//�������Ա�(������)

	//���������򲢲�����,��Ҫ�����������е�ÿһ����㶼�����
	void ClearList();	//������Ա�(������)

	//�пպͲⳤ����û��ʲô�Ѷ�
	bool ListEmpty();	//�ж����Ա�(������)�Ƿ�Ϊ��
	int ListLength();	//��ȡ���Ա�(������)����

	//����GetElem,��Ҫ���Ŵ����ָ����ȥ����Ѱ����Ӧ���,
	//�������������е����ݴ���pNode,�ڰ�˳��Ѱ��ʱ��Ҫʹ��ͷ���
	bool GetElem(int i, Node *pNode);	//��ȡָ��λ�õĽ�㲢�����pNode

	//����LocateElem,��������pNode�е�����,�������а�������
	//����������������pNode��ͬ�Ľ��ʱ,����ָ���򴫳�
	//�ڰ�˳��Ѱ��ʱ��Ҫʹ��ͷ���
	int LocateElem(Node *pNode);		//Ѱ�ҵ�һ������pNode�����ݽ���λ��

	//��ȡָ��Ԫ�ص�ǰ��
	//ͨ��ʹ��ͷ���,���ո�����pCurrentNode��ֵȥ�ȶ�������
	//���ҵ���Ӧ���֮��,����ǰ����㴫��
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);

	//��ȡָ��Ԫ�صĺ��
	//ͨ��ʹ��ͷ���,���ո�����pCurrentNode��ֵȥ�ȶ�������
	//���ҵ���Ӧ���֮��,�����̽�㴫��
	bool NextElem(Node *pCurrentNode, Node *pNextNode);

	//����ʱ��Ҫ����ͷ���,��ÿһ�������з���,ֱ��β���Ϊֹ
	//β����ָ����ָ��NULL
	void ListTraverse();//�������Ա�(������)

	//ָ���κβ����λ��,��;�㷺
	//�����ҵ�i-1��λ�õĽ��,ʹ��ָ����ָ���½��,
	//����pNode��ָ����ָ��ԭ��i-1λ�ý��ָ��Ľ�㼴��
	bool ListInsert(int i, Node *pNode); //�ڵ�i��λ�ò�����

	//ɾ�������Ҫ���ҵ�Ҫɾ����λ��
	//Ȼ���ҵ�ɾ��λ�õ���һ�����,
	//����һ������ָ����ָ��ɾ�����ָ����ָ��Ľ��
	//���ͷŴ˱�ɾ�������Ӧ������,������ɽ���ɾ������
	bool ListDelete(int i, Node *pNode); //ɾ����i��λ�õĽ��

	//��ͷ��������,�����µĽ����뵽ͷ���ĺ���
	//��ʹͷ���ָ����ָ����½��,
	//Ȼ���½���ָ����ָ��ԭ��ͷ����ָ����ָ��Ľ��
	bool ListInsertHead(Node *pNode);	 //��ͷ������

	//��β��������,�����µĽ����뵽β���ĺ���
	//�������ҵ�β���,��ָ����ָ��NULL
	//�½������,ԭ�ȵ�β���ָ����ָ���µ�β��㼴��
	bool ListInsertTail(Node *pNode);	 //��β������
protected:
private:
	Node *m_pList;	//���ڴ�Ž������ָ��
	int m_iLength;	//����ͳ�������ȵĳ�Ա����
};
#endif // SINGLELINKEDLISTBASIC_H
