/************************************************************************/
/* ���Ա� -- ˳���														*/
/*																		*/
/*   3 5 7 2 9 1 8														*/
/*																		*/
/*	 (ǰ��)Ԫ�ص�ǰһ��Ԫ��<---Ԫ��--->(���)Ԫ�صĺ�һ��Ԫ��			*/
/*																		*/
/* ˳���Ļ�������(C����)												*/
/*	 [ע]C�����е�*list��C++����ȫ������thisָ�����,					*/
/*		 �Ӷ����������ĳ�Ա����Ҳ����ֻ��Ҫ����������					*/
/*																		*/
/*	 BOOL InitList(List **list);	//�������Ա�(˳���)	���캯��	*/
/*	 void DestroyList(List *list);	//�������Ա�(˳���)	��������	*/
/*	 void ClearList(List *list);	//������Ա�(˳���)				*/
/*   BOOL ListEmpty(List *list);	//�ж����Ա�(˳���)�Ƿ�Ϊ��(��Ԫ��)*/
/*   int ListLength(List *list);	//��ȡ���Ա�(˳���)����(����)		*/
/*																		*/
/*	 //����һ��˳���list,�±�i,Ԫ�����ݸ�e,������e						*/
/*   BOOL GetElem(List *list,int i,Elem *e);	//��ȡָ��Ԫ��			*/
/*																		*/
/*	 //Ѱ�ҵ�һ������e������Ԫ�ص�λ��									*/
/*	 //����e,��list�������Ԫ��											*/
/*   int LocateElem(List *list,Elem *e);								*/
/*																		*/
/*	 //��ȡָ��Ԫ�ص�ǰ��												*/
/*	 //����˳���list,��ǰԪ��currentElem,ǰ������preElem,������		*/
/*   BOOL PriorElem(List *list,Elem *currentElem,Elem *preElem);		*/
/*																		*/
/*	 //��ȡָ��Ԫ�صĺ��												*/
/*	 //����˳���list,��ǰԪ��currentElem,��̸���nextElem,������		*/
/*   BOOL NextElem(List *list,Elem *currentElem,Elem *nextElem);		*/
/*																		*/
/*	 //��ָ��������Ϊi��λ�ò���Ԫ��e,����֮���Ԫ�غ���һλ			*/
/*   BOOL ListInsert(List *list,int i,Elem *e);	//�ڵ�i��λ�ò���Ԫ��	*/
/*																		*/
/*	 //��ָ��������Ϊi��λ��ɾ��Ԫ��e,����֮���Ԫ��ǰ��һλ			*/
/*   BOOL ListDelete(List *list,int i,Elem *e);	//��ɾ����i��λ�õ�Ԫ��	*/
/*																		*/
/*   void ListTraverse(List *list);				//�������Ա�(˳���)	*/
/*																		*/
/* ��������:2019-03-11								 Author:Cyber Kaka  */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MyListBasic.h"
using namespace std;

int main(void)
{
	//3 5 7 2 9 1 8
	int e1 = 3;
	int e2 = 5;
	int e3 = 7;
	int e4 = 2;
	int e5 = 9;
	int e6 = 1;
	int e7 = 8;
	//��⺯��
	List *list1 = new List(10);
	//�鿴Ԫ�ظ���
	cout << "length:" << list1->ListLength() << endl;

	list1->ListInsert(0, &e1);
	list1->ListInsert(1, &e2);
	list1->ListInsert(2, &e3);
	list1->ListInsert(3, &e4);
	list1->ListInsert(4, &e5);
	list1->ListInsert(5, &e6);
	list1->ListInsert(6, &e7);
	//�鿴Ԫ�ظ���
	cout << "length:" << list1->ListLength() << endl;
	//�������Ա�(˳���)
	list1->ListTraverse();
	//�ָ���
	cout << "*********************************" << endl;
	//����Ѱ��Ԫ�غ���
	int temp1 = 0;
	list1->GetElem(0, &temp1);
	cout << "Temp: " << temp1 << endl;
	//�ָ���
	cout << "*********************************" << endl;
	//���ö�λԪ���±꺯��
	temp1 = 5;
	cout << "Temp: " << list1->LocateElem(&temp1) << endl;
	//�ָ���
	cout << "*********************************" << endl;
	//����ǰ���ͺ�̺���
	list1->PriorElem(&e4, &temp1);
	cout << "Temp: " << temp1 << endl;
	list1->NextElem(&e5, &temp1);
	cout << "Temp: " << temp1 << endl;
	//�ָ���
	cout << "*********************************" << endl;
	//������ʱ����,����ɾ��������
	int temp = 0;
	//�Ƴ�һ�����ݲ���ӡ��
	list1->ListDelete(0, &temp);
	cout << "# " << temp << endl;
	//����ǰ���Ա�(˳���)��״̬
	if (!list1->ListEmpty())
	{
		cout << "List is not empty!" << endl;
	}
	//������Ա�
	list1->ClearList();
	//�ٴα���
	list1->ListTraverse();
	//�ٴβ鿴��ǰ���Ա�(˳���)��״̬
	if (list1->ListEmpty())
	{
		cout << "List is empty!" << endl;
	}


	delete list1;
	list1 = NULL;

	system("pause");
	return 0;
}