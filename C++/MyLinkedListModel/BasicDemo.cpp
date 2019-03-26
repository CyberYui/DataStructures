#include <stdlib.h>
#include <iostream>
#include "SLListBasic.h"
#include "NodeBasic.h"
using namespace std;

/************************************************************************/
/* ���Ա� -- ������(C����)
/*   ��Ա����:
/*     BOOL InitList(List **list);	//�������Ա�(������)
/*     void DestroyList(List *list);//�������Ա�(������)
/*     void ClearList(List *list);  //������Ա�(������)
/*     BOOL ListEmpty(List *list);  //�ж����Ա�(������)�Ƿ�Ϊ��
/*     int ListLength(List *list);  //��ȡ���Ա�(������)����
/*     BOOL GetElem(List *list,int i,Elem *e);  //��ȡָ��Ԫ��
/*
/*     //Ѱ�ҵ�һ������e������Ԫ�ص�λ��
/*     int LocateElem(List *list,Elem *e);
/*
/*	   //��ȡָ��Ԫ�ص�ǰ��
/*     BOOL PriorElem(List *list,Elem *currentElem,Elem *preElem);
/*
/*	   //��ȡָ��Ԫ�صĺ��
/*     BOOL NextElem(List *list,Elem *currentElem,Elem *nextElem);
/*
/*     BOOL ListInsert(List *list,int i,Elem *e);    //�ڵ�i��λ�ò���Ԫ��
/*     BOOL ListDelete(List *list,int i,Elem *e);    //ɾ����i��λ�õ�Ԫ��
/*     void ListTraverse(List *list);                //�������Ա�(������)
/*
/*     BOOL ListInsertHead(List *list,Node *pNode);	 //��ͷ������
/*     BOOL ListInsertTail(List *list,Node *pNode);	 //��β������
/*
/* ѭ�������˫�����������
/************************************************************************/

int main(void)
{
	//��������
	//����һ������
	List *pList = new List();
	//�ж��Ƿ�Ϊ��
	cout << pList->ListEmpty() << endl;
	//�ָ���
	cout << "**************************" << endl;
	//����node1~5
	Node node1;
	node1.data = 3;
	Node node2;
	node2.data = 4;
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;
	Node node5;
	node5.data = 7;
	//��ͷ������
	pList->ListInsertHead(&node1);
	//�����鿴�Ƿ������
	pList->ListTraverse();
	//�ָ���
	cout << "**************************" << endl;
	//����������,�ǵ����Ǵ�ͷ���������
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node5);
	//�����鿴�Ƿ������
	pList->ListTraverse();//Ӧ���������ӡ,����ʱΪ7 6 5 4 3
	//�ָ���
	cout << "**************************" << endl;
	//�ж��Ƿ�Ϊ��
	cout << pList->ListEmpty() << endl;
	//�ָ���
	cout << "**************************" << endl;
	//����node6��node7,����β��������
	Node node6;
	node6.data = 2;
	Node node7;
	node7.data = 1;
	pList->ListInsertTail(&node6);
	pList->ListInsertTail(&node7);
	//�����鿴�Ƿ������
	pList->ListTraverse();
	//�ָ���
	cout << "**************************" << endl;//7 6 5 4 3 2 1
	//�����������м�����ܷ����
	Node node8;
	node8.data = 12;
	pList->ListInsert(3, &node8);//��5������������
	//�����鿴�Ƿ������
	pList->ListTraverse();
	//�ָ���
	cout << "**************************" << endl;
	//���ɾ�������Ƿ���Ч
	Node node9;
	pList->ListDelete(3, &node9);//ɾȥ�ոռ������
	node9.printNode();
	//�ָ���
	cout << "**************************" << endl;
	//�����鿴�Ƿ�ɾ��������
	pList->ListTraverse();
	//�ָ���
	cout << "**************************" << endl;
	//��ȡһ�����,��ӡ������������
	pList->GetElem(4, &node9);
	cout << "elem = " << node9.data;
	//�ָ���
	cout << endl << "**************************" << endl;//7 6 5 4 3 2 1
	//ȡ��3�����,��5��ǰ���ͺ��
	Node node10;
	pList->PriorElem(&node3, &node9);//ȡǰ��
	cout << "elem = " << node9.data << endl;
	pList->NextElem(&node3, &node10);//ȡ���
	cout << "elem = " << node10.data << endl;
	//�ָ���
	cout << endl << "**************************" << endl;//7 6 5 4 3 2 1
	//������պ����ܷ�ʹ��
	pList->ClearList();
	//��ͷ������
	pList->ListInsertHead(&node1);
	//�����鿴�Ƿ�ɾ��������
	pList->ListTraverse();
	//�ָ���
	cout << "**************************" << endl;
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node5);
	//�ָ���
	cout << "**************************" << endl;
	pList->ListTraverse();
	//�ָ���
	cout << "**************************" << endl;
	//���ܷ�λ
	cout << node3.data << "��λ����:";
	cout << pList->LocateElem(&node3) << endl;//ӦΪnode3=5


	delete pList;
	pList = NULL;

	system("pause");

	return 0;
}