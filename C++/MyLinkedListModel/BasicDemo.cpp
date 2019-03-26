#include <stdlib.h>
#include <iostream>
#include "SLListBasic.h"
#include "NodeBasic.h"
using namespace std;

/************************************************************************/
/* 线性表 -- 单链表(C语言)
/*   成员函数:
/*     BOOL InitList(List **list);	//创建线性表(单链表)
/*     void DestroyList(List *list);//销毁线性表(单链表)
/*     void ClearList(List *list);  //清空线性表(单链表)
/*     BOOL ListEmpty(List *list);  //判断线性表(单链表)是否为空
/*     int ListLength(List *list);  //获取线性表(单链表)长度
/*     BOOL GetElem(List *list,int i,Elem *e);  //获取指定元素
/*
/*     //寻找第一个满足e的数据元素的位序
/*     int LocateElem(List *list,Elem *e);
/*
/*	   //获取指定元素的前驱
/*     BOOL PriorElem(List *list,Elem *currentElem,Elem *preElem);
/*
/*	   //获取指定元素的后继
/*     BOOL NextElem(List *list,Elem *currentElem,Elem *nextElem);
/*
/*     BOOL ListInsert(List *list,int i,Elem *e);    //在第i个位置插入元素
/*     BOOL ListDelete(List *list,int i,Elem *e);    //删除第i个位置的元素
/*     void ListTraverse(List *list);                //便利线性表(单链表)
/*
/*     BOOL ListInsertHead(List *list,Node *pNode);	 //从头插入结点
/*     BOOL ListInsertTail(List *list,Node *pNode);	 //从尾插入结点
/*
/* 循环链表和双链表自行设计
/************************************************************************/

int main(void)
{
	//测试链表
	//创建一个链表
	List *pList = new List();
	//判断是否为空
	cout << pList->ListEmpty() << endl;
	//分隔符
	cout << "**************************" << endl;
	//定义node1~5
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
	//从头结点插入
	pList->ListInsertHead(&node1);
	//遍历查看是否能输出
	pList->ListTraverse();
	//分隔符
	cout << "**************************" << endl;
	//连续插入结点,记得这是从头结点后插入结点
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node5);
	//遍历查看是否能输出
	pList->ListTraverse();//应该是逆序打印,即此时为7 6 5 4 3
	//分隔符
	cout << "**************************" << endl;
	//判断是否为空
	cout << pList->ListEmpty() << endl;
	//分隔符
	cout << "**************************" << endl;
	//定义node6和node7,并从尾部插入结点
	Node node6;
	node6.data = 2;
	Node node7;
	node7.data = 1;
	pList->ListInsertTail(&node6);
	pList->ListInsertTail(&node7);
	//遍历查看是否能输出
	pList->ListTraverse();
	//分隔符
	cout << "**************************" << endl;//7 6 5 4 3 2 1
	//接下来看从中间插入能否可以
	Node node8;
	node8.data = 12;
	pList->ListInsert(3, &node8);//从5后面插入这个数
	//遍历查看是否能输出
	pList->ListTraverse();
	//分隔符
	cout << "**************************" << endl;
	//检查删除函数是否有效
	Node node9;
	pList->ListDelete(3, &node9);//删去刚刚加入的数
	node9.printNode();
	//分隔符
	cout << "**************************" << endl;
	//遍历查看是否删掉了内容
	pList->ListTraverse();
	//分隔符
	cout << "**************************" << endl;
	//获取一个结点,打印出它的数据域
	pList->GetElem(4, &node9);
	cout << "elem = " << node9.data;
	//分隔符
	cout << endl << "**************************" << endl;//7 6 5 4 3 2 1
	//取第3个结点,即5的前驱和后继
	Node node10;
	pList->PriorElem(&node3, &node9);//取前驱
	cout << "elem = " << node9.data << endl;
	pList->NextElem(&node3, &node10);//取后继
	cout << "elem = " << node10.data << endl;
	//分隔符
	cout << endl << "**************************" << endl;//7 6 5 4 3 2 1
	//测试清空函数能否使用
	pList->ClearList();
	//从头结点插入
	pList->ListInsertHead(&node1);
	//遍历查看是否删掉了内容
	pList->ListTraverse();
	//分隔符
	cout << "**************************" << endl;
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);
	pList->ListInsertHead(&node4);
	pList->ListInsertHead(&node5);
	//分隔符
	cout << "**************************" << endl;
	pList->ListTraverse();
	//分隔符
	cout << "**************************" << endl;
	//看能否定位
	cout << node3.data << "的位置是:";
	cout << pList->LocateElem(&node3) << endl;//应为node3=5


	delete pList;
	pList = NULL;

	system("pause");

	return 0;
}