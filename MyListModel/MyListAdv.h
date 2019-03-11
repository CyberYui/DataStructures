#ifndef MYLISTADV_H
#define MYLISTADV_H

#include "ListCoordinate.h"

/************************************************************************/
/* 顺序表类:
/*   成员函数:
/*	   List(int size);
/*	   ~List();
/*	   void ClearList();
/*	   bool ListEmpty();
/*	   int ListLength();
/*	   bool GetElem(int i, Coordinate *e);
/*	   int LocateElem(Coordinate *e);
/*	   bool PriorElem(Coordinate *currentElem, Coordinate *preElem);
/*	   bool NextElem(Coordinate *currentElem, Coordinate *nextElem);
/*	   void ListTraverse();
/*	   bool ListInsert(int i, Coordinate *e);
/*	   bool ListDelete(int i, Coordinate *e);
/*	 数据成员:
/*	   Coordinate *m_pList;	//用这块内存存储线性表(顺序表)
/*	   int m_iSize;			//线性表(顺序表)的容量
/*	   int m_iLength;		//线性表(顺序表)已经放入的元素个数
/*  创建日期:2019-03-11								 Author:Cyber Kaka
/************************************************************************/

class List
{
public:
	//构造函数
	//理论上说可以直接不填参数,但为了未来便于操作,则传入一个长度,便于控制表长
	//BOOL InitList(List **list);	//创建线性表(顺序表)
	List(int size);

	//void DestroyList(List *list);	//销毁线性表(顺序表)
	~List();

	//void ClearList(List *list);	//清空线性表(顺序表)
	//清空线性表并不是清空内存,而是把当前线性表的实际长度m_iLength初始化
	//即将m_iLength赋0,日后再往里添加数据时,就会覆盖掉原有的数据元素
	void ClearList();

	//BOOL ListEmpty(List *list);	//判断线性表(顺序表)是否为空(无元素)
	//对于C语言来说,由于没有bool类型数据,所以要宏定义BOOL,从而实现bool类型
	bool ListEmpty();

	//int ListLength(List *list);	//获取线性表(顺序表)长度(个数)
	int ListLength();

	//BOOL GetElem(List *list,int i,Elem *e);	//获取线性表(顺序表)的指定元素
	//指定当前的数组下标i,元素相应数据赋值给e
	//Elem是特指所给数据的数据类型的,主要用于模版类,本例中都为int
	bool GetElem(int i, Coordinate *e);

	//int LocateElem(List *list,Elem *e);	//寻找第一个满足e的数据元素的位置
	//寻找第一个满足e的数据元素的位置,与e相比较,在list中找这个元素
	int LocateElem(Coordinate *e);

	//BOOL PriorElem(List *list,Elem *currentElem,Elem *preElem);
	//获取指定元素的前驱
	//传入顺序表list,当前元素currentElem,前驱赋给preElem,并返回
	bool PriorElem(Coordinate *currentElem, Coordinate *preElem);

	//BOOL NextElem(List *list,Elem *currentElem,Elem *nextElem);
	//获取指定元素的后继
	//传入顺序表list,当前元素currentElem,后继赋给nextElem,并返回
	bool NextElem(Coordinate *currentElem, Coordinate *nextElem);

	//void ListTraverse(List *list);				//遍历线性表(顺序表)
	void ListTraverse();

	//BOOL ListInsert(List *list,int i,Elem *e);	//在第i个位置插入元素
	//在指定的索引为i的位置插入元素e,并将之后的元素每个都后移一位
	bool ListInsert(int i, Coordinate *e);

	//BOOL ListDelete(List *list,int i,Elem *e);	//在删除第i个位置的元素
	//在指定的索引为i的位置删除元素e,并将之后的元素前移一位
	bool ListDelete(int i, Coordinate *e);

protected:
private:
	Coordinate *m_pList;//用这块内存存储线性表(顺序表)
	int m_iSize;//线性表(顺序表)的容量
	int m_iLength;//线性表(顺序表)已经放入的元素个数
};


#endif