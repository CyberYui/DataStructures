#ifndef MYLISTBASIC_H
#define MYLISTBASIC_H

/************************************************************************/
/* ˳�����:
/*   ��Ա����:
/*	   List(int size);
/*	   ~List();
/*	   void ClearList();
/*	   bool ListEmpty();
/*	   int ListLength();
/*	   bool GetElem(int i, int *e);
/*	   int LocateElem(int *e);
/*	   bool PriorElem(int *currentElem, int *preElem);
/*	   bool NextElem(int *currentElem, int *nextElem);
/*	   void ListTraverse();
/*	   bool ListInsert(int i, int *e);
/*	   bool ListDelete(int i, int *e);
/*	 ���ݳ�Ա:
/*	   int *m_pList;//������ڴ�洢���Ա�(˳���)
/*	   int m_iSize;//���Ա�(˳���)������
/*	   int m_iLength;//���Ա�(˳���)�Ѿ������Ԫ�ظ���
/*  ��������:2019-03-11								 Author:Cyber Kaka
/************************************************************************/

class List
{
public:
	//���캯��
	//������˵����ֱ�Ӳ������,��Ϊ��δ�����ڲ���,����һ������,���ڿ��Ʊ�
	//BOOL InitList(List **list);	//�������Ա�(˳���)
	List(int size);

	//void DestroyList(List *list);	//�������Ա�(˳���)
	~List();

	//void ClearList(List *list);	//������Ա�(˳���)
	//������Ա���������ڴ�,���ǰѵ�ǰ���Ա��ʵ�ʳ���m_iLength��ʼ��
	//����m_iLength��0,�պ��������������ʱ,�ͻḲ�ǵ�ԭ�е�����Ԫ��
	void ClearList();

	//BOOL ListEmpty(List *list);	//�ж����Ա�(˳���)�Ƿ�Ϊ��(��Ԫ��)
	//����C������˵,����û��bool��������,����Ҫ�궨��BOOL,�Ӷ�ʵ��bool����
	bool ListEmpty();

	//int ListLength(List *list);	//��ȡ���Ա�(˳���)����(����)
	int ListLength();

	//BOOL GetElem(List *list,int i,Elem *e);	//��ȡ���Ա�(˳���)��ָ��Ԫ��
	//ָ����ǰ�������±�i,Ԫ����Ӧ���ݸ�ֵ��e
	//Elem����ָ�������ݵ��������͵�,��Ҫ����ģ����,�����ж�Ϊint
	bool GetElem(int i, int *e);

	//int LocateElem(List *list,Elem *e);	//Ѱ�ҵ�һ������e������Ԫ�ص�λ��
	//Ѱ�ҵ�һ������e������Ԫ�ص�λ��,��e��Ƚ�,��list�������Ԫ��
	int LocateElem(int *e);

	//BOOL PriorElem(List *list,Elem *currentElem,Elem *preElem);
	//��ȡָ��Ԫ�ص�ǰ��
	//����˳���list,��ǰԪ��currentElem,ǰ������preElem,������
	bool PriorElem(int *currentElem, int *preElem);

	//BOOL NextElem(List *list,Elem *currentElem,Elem *nextElem);
	//��ȡָ��Ԫ�صĺ��
	//����˳���list,��ǰԪ��currentElem,��̸���nextElem,������
	bool NextElem(int *currentElem, int *nextElem);

	//void ListTraverse(List *list);				//�������Ա�(˳���)
	void ListTraverse();

	//BOOL ListInsert(List *list,int i,Elem *e);	//�ڵ�i��λ�ò���Ԫ��
	//��ָ��������Ϊi��λ�ò���Ԫ��e,����֮���Ԫ��ÿ��������һλ
	bool ListInsert(int i, int *e);

	//BOOL ListDelete(List *list,int i,Elem *e);	//��ɾ����i��λ�õ�Ԫ��
	//��ָ��������Ϊi��λ��ɾ��Ԫ��e,����֮���Ԫ��ǰ��һλ
	bool ListDelete(int i, int *e);

protected:
private:
	int *m_pList;//������ڴ�洢���Ա�(˳���)
	int m_iSize;//���Ա�(˳���)������
	int m_iLength;//���Ա�(˳���)�Ѿ������Ԫ�ظ���
};


#endif