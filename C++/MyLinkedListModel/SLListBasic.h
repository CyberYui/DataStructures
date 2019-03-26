#ifndef SINGLELINKEDLISTBASIC_H
#define SINGLELINKEDLISTBASIC_H
#include "NodeBasic.h"

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
/*	 Node *m_pList;			//用于存放结点对象的指针
/*	 int m_iLength;			//用于统计链表长度的成员变量
/************************************************************************/

class List
{
public:
	//Node表示结点
	//无论是顺序表还是链表,其构造函数和析构函数都是必须的
	//对于链表,它从开始就需要一个复杂内容,即结点Node,所以需要临时申请Node对象
	List();				//创建线性表(单链表)
	~List();			//销毁线性表(单链表)

	//链表的清空则并不容易,需要将连在链表中的每一个结点都清除掉
	void ClearList();	//清空线性表(单链表)

	//判空和测长函数没有什么难度
	bool ListEmpty();	//判断线性表(单链表)是否为空
	int ListLength();	//获取线性表(单链表)长度

	//对于GetElem,需要拿着传入的指针域去按序寻找相应结点,
	//并将其数据域中的内容传给pNode,在按顺序寻找时需要使用头结点
	bool GetElem(int i, Node *pNode);	//获取指定位置的结点并保存给pNode

	//对于LocateElem,则是拿着pNode中的内容,在链表中按序搜索
	//当搜索到数据域与pNode相同的结点时,将其指针域传出
	//在按顺序寻找时需要使用头结点
	int LocateElem(Node *pNode);		//寻找第一个满足pNode的数据结点的位序

	//获取指定元素的前驱
	//通过使用头结点,按照给定的pCurrentNode的值去比对数据域
	//当找到相应结点之后,将其前驱结点传出
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);

	//获取指定元素的后继
	//通过使用头结点,按照给定的pCurrentNode的值去比对数据域
	//当找到相应结点之后,将其后继结点传出
	bool NextElem(Node *pCurrentNode, Node *pNextNode);

	//遍历时需要拿着头结点,对每一个结点进行访问,直到尾结点为止
	//尾结点的指针域指着NULL
	void ListTraverse();//便利线性表(单链表)

	//指定任何插入的位置,用途广泛
	//首先找到i-1个位置的结点,使其指针域指向新结点,
	//再让pNode的指针域指向原先i-1位置结点指向的结点即可
	bool ListInsert(int i, Node *pNode); //在第i个位置插入结点

	//删除结点需要先找到要删除的位置
	//然后找到删除位置的上一个结点,
	//用上一个结点的指针域指向被删除结点指针域指向的结点
	//再释放此被删除结点相应的内容,即可完成结点的删除操作
	bool ListDelete(int i, Node *pNode); //删除第i个位置的结点

	//从头结点插入结点,即将新的结点插入到头结点的后面
	//并使头结点指针域指向此新结点,
	//然后新结点的指针域指向原先头结点的指针域指向的结点
	bool ListInsertHead(Node *pNode);	 //从头插入结点

	//从尾结点插入结点,即将新的结点插入到尾结点的后面
	//首先先找到尾结点,其指针域指向NULL
	//新结点插入后,原先的尾结点指针域指向新的尾结点即可
	bool ListInsertTail(Node *pNode);	 //从尾插入结点
protected:
private:
	Node *m_pList;	//用于存放结点对象的指针
	int m_iLength;	//用于统计链表长度的成员变量
};
#endif // SINGLELINKEDLISTBASIC_H
