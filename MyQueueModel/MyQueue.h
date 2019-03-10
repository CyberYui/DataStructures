/************************************************************************/
/*    文件名:MyQueue.h                    用途:环形队列的模版           */
/*    作者:Cyber Kaka                     邮箱:YuiNozomi@vip.qq.com     */
/*    程序语言:C++                        编译环境:VS2017               */
/*                                        生成日期:2019年3月9日         */
/************************************************************************/
#ifndef MYQUEUE_H
#define MYQUEUE_H


#include <iostream>
#include <string>
using namespace std;


template<typename T>
class MyQueue
{
public:
	MyQueue(int queueCapacity);	//创建队列
	virtual ~MyQueue();			//销毁队列
	void ClearQueue();			//清空队列
	bool QueueEmpty()const;		//判空队列
	bool QueueFull()const;		//判满队列
	int QueueLength()const;		//队列长度
	bool EnQueue(T element);	//新元素入队
	bool DeQueue(T &element);	//首元素出队
	void QueueTraverse();		//遍历队列
private:
	T *m_pQueue;				//类型指针
	int m_iQueueLen;			//队列元素个数
	int m_iQueueCapacity;		//队列数组容量
	int m_iHead;
	int m_iTail;
};


/************************************************************************/
/*  构造函数MyQueue       功能:创建一个环形队列      Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
MyQueue<T>::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;//将用户传入的容量赋值给内部数据成员
	m_iHead = 0;//环形队列初始化过程中队头和队尾都是0
	m_iTail = 0;
	m_iQueueLen = 0;//初始状态下,队列无元素,即元素个数为0
	m_pQueue = new T[m_iQueueCapacity];
	if (NULL==m_pQueue)
	{
		cout << "Memory distributed fail !" << endl;
		system("pause");
		system("exit");
	} 
	cout << "创建成功!" << endl;
}


/************************************************************************/
/*  析构函数~MyQueue      功能:销毁一个环形队列,销毁指针,释放内存       */
/*                                                   Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
MyQueue<T>::~MyQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
	cout << "销毁队列成功!" << endl;
	cout << endl;
}


/************************************************************************/
/*清空队列函数ClearQueue()                                              */
/*        功能:清空队列,使队列变回初始状态,首尾和长度标记全部初始化为0, */
/*             此操作不用修改容量,不用修改内存指针                      */
/*                                                   Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
void MyQueue<T>::ClearQueue()
{
	cout << "*********清空队列中..*********" << endl;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	cout << "***********清空成功***********" << endl;
	cout << endl;
}


/************************************************************************/
/*  判空函数QueueEmpty()    功能:判断队列是否为空    Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::QueueEmpty()const
{
	//return m_iQueueLen == 0 ? true : false;
	if (m_iQueueLen == 0)
	{
		cout << "队列为空!" << endl;
		return true;
	}
	else
	{
		cout << endl;
		return false;
	}
}


/************************************************************************/
/*  判满函数QueueFull()     功能:判断队列是否为满    Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::QueueFull()const
{
	//return m_iQueueLen == m_iQueueCapacity ? true : false;
	if (m_iQueueLen == m_iQueueCapacity)
	{
		cout << "队列已满!" << endl;
		cout << endl;
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************/
/*  判长函数QueueLength()    功能:获取队列长度       Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
int MyQueue<T>::QueueLength()const
{
	return m_iQueueLen;
}


/************************************************************************/
/*  入队函数EnQueue(T element)      功能:给队列中插入元素               */
/*                                                   Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::EnQueue(T element)
{
	if (QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}


/************************************************************************/
/*  出队函数DeQueue(T &element)                  功能:给队列中移除元素  */
/*  注意:element必须是一个引用,不能是一个参数        Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::DeQueue(T &element)
{
	if (QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}


/************************************************************************/
/*遍历函数QueueTraverse()   功能:遍历队列并输出元素    Author:Cyber Kaka*/
/************************************************************************/
template<typename T>
void MyQueue<T>::QueueTraverse()
{
	cout << endl;
	cout << "***********开始遍历***********" << endl;
	if (QueueEmpty()==true)
	{
		cout << "队列为空!没有数据!" << endl;
	}
	else
	{	
		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
		{
			cout << m_pQueue[i%m_iQueueCapacity] << endl;
		}
	}
	cout << "*********本次遍历结束*********" << endl;
	cout << endl;
}


#endif
