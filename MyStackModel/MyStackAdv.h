#ifndef MYSTACKADV_H
#define MYSTACKADV_H

#include "CoordinateAdv.h"
/************************************************************************/
/* 栈类:                                                                */
/*     MyStack(int size);   //分配内存初始化栈空间,设定栈容量,栈顶      */
/*     ~MyStack();          //回收栈空间内存                            */
/*     bool stackEmpty();   //判定栈是否为空,为空返回true,非空返回false */
/*     bool stackFull();    //判定栈是否为满,为满返回true,不满返回false */
/*     void clearStack();   //清空栈                                    */
/*     int stackLength();   //统计已有元素的个数                        */
/*     void push(char elem);	//元素入栈,栈顶上升                     */
/*     char pop(char &elem);    //元素出栈,栈顶下降                     */
/*     void stackTraverse();    //遍历栈中所有元素                      */
/*                                                                      */
/* 目的:掌握栈的实现原理和运行机制               创建日期:2019-03-10    */
/************************************************************************/

class MyStack
{
public:
	MyStack(int size);		//分配内存初始化栈空间,设定栈容量,栈顶      
	~MyStack();				//回收栈空间内存                            
	bool stackEmpty();		//判定栈是否为空,为空返回true,非空返回false 
	bool stackFull();		//判定栈是否为满,为满返回true,不满返回false 
	void clearStack();		//清空栈                                    
	int stackLength();		//统计已有元素的个数 

	//面对Coordinate类型进行相应的改造
	//这里放入一个Coordinate对象,由于对象包含的内容是有关于简单数据类型的,
	//因此这里可以直接传入对象,如果要传入的类对象包含复杂内容,如实例化指针等
	//则应用到拷贝构造函数等内容
	bool push(Coordinate elem);	//元素入栈,栈顶上升
	bool pop(Coordinate &elem);   //元素出栈,栈顶下降 
	void stackTraverse(bool isFromButtom);   //遍历栈中所有元素
private:
	//指向Coordinate类型的栈空间
	Coordinate *m_pBuffer;	//栈空间指针,指针指向栈空间
	int m_iSize;			//栈容量
	int m_iTop;				//栈顶,栈中元素个数
	//栈底不用写,因为栈底永远都是0,不可能变化
};

#endif