#ifndef SLLISTADV_H
#define SLLISTADV_H
#include "NodeAdv.h"

/************************************************************************/
/* 成员函数:
/*	 List();							//创建线性表(单链表)
/*	 ~List();							//销毁线性表(单链表)
/*	 void ClearList();					//清空线性表(单链表)
/*	 bool ListEmpty();					//判断线性表(单链表)是否为空
/*	 int ListLength();					//获取线性表(单链表)长度
/*	 bool ListInsertHead(Node *pNode);	//从头插入结点
/*	 bool ListInsertTail(Node *pNode);	//从尾插入结点
/*	 bool GetElem(int i, Node *pNode);	//获取指定位置的结点并保存给pNode
/*	 int LocateElem(Node *pNode);		//寻找第一个满足pNode的数据结点的位序
/*
/*	 //获取指定元素的前驱
/*	 bool PriorElem(Node *pCurrentNode, Node *pPreNode);
/*
/*	 //获取指定元素的后继
/*	 bool NextElem(Node *pCurrentNode, Node *pNextNode);
/*	 void ListTraverse();				 //便利线性表(单链表)
/*	 bool ListInsert(int i, Node *pNode);//在第i个位置插入结点
/*	 bool ListDelete(int i, Node *pNode);//删除第i个位置的结点
/* 数据成员:
/*	 Node *m_pList;
/*	 int m_iLength;
/************************************************************************/

class List
{
public:
	List();								//创建线性表(单链表)
	~List();							//销毁线性表(单链表)
	void ClearList();					//清空线性表(单链表)
	bool ListEmpty();					//判断线性表(单链表)是否为空
	int ListLength();					//获取线性表(单链表)长度
	bool GetElem(int i, Node *pNode);	//获取指定位置的结点并保存给pNode
	int LocateElem(Node *pNode);		//寻找第一个满足pNode的数据结点的位序

	//获取指定元素的前驱
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);

	//获取指定元素的后继
	bool NextElem(Node *pCurrentNode, Node *pNextNode);
	void ListTraverse();				 //便利线性表(单链表)
	bool ListInsert(int i, Node *pNode); //在第i个位置插入结点
	bool ListDelete(int i, Node *pNode); //删除第i个位置的结点
	bool ListInsertHead(Node *pNode);	 //从头插入结点
	bool ListInsertTail(Node *pNode);	 //从尾插入结点
protected:
private:
	Node *m_pList;
	int m_iLength;
};
#endif // SLLISTADV_H
