#include "MyQueueBasic.h"
#include <iostream>
using namespace std;
//逐一实现头文件中的函数

/************************************************************************/
/*构造函数MyQueue       功能:创建一个环形队列          Author:Cyber Kaka*/
/************************************************************************/
MyQueue::MyQueue(int queueCapacity)
{
	//将用户传入的容量赋值给内部数据成员
	m_iQueueCapacity = queueCapacity;
	//环形队列初始化过程中队头和队尾都是0
	m_iHead = 0;
	m_iTail = 0;
	//初始状态下,队列无元素,即元素个数为0
	m_iQueueLen = 0;
	//ClearQueue();
	//给环形队列分配内存
	//因为从堆中申请内存是可能申请失败的,所以需要进行判断
	m_pQueue = new int[m_iQueueCapacity];
	if (NULL==m_pQueue)
	{
		cout << "Memory distributed fail !" << endl;
		system("pause");
		system("exit");
	}

}

/************************************************************************/
/*析构函数~MyQueue      功能:销毁一个环形队列,销毁指针,释放内存         */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
MyQueue::~MyQueue()
{
	//由于申请的是一个数组,所以销毁时也要用销毁数组指针的方式销毁
	delete[]m_pQueue;
	m_pQueue = NULL;
	cout << "销毁队列成功!" << endl;
	cout << endl;
}

/************************************************************************/
/*清空队列函数ClearQueue()                                              */
/*        功能:清空队列,使队列变回初始状态,不用修改容量,不用修改内存指针*/
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
void MyQueue::ClearQueue()
{
	cout << "*********清空队列中..*********" << endl;
	//即首尾为0,元素个数为0
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	cout << "***********清空成功***********" << endl;
	cout << endl;
}

/************************************************************************/
/*判空函数QueueEmpty()  功能:判断队列是否为空          Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::QueueEmpty()const
{
	//return m_iQueueLen == 0 ? true : false;
	if (m_iQueueLen == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/************************************************************************/
/*判满函数QueueFull()  功能:判断队列是否为满           Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::QueueFull()const
{
	//return m_iQueueLen == m_iQueueCapacity ? true : false;
	if (m_iQueueLen == m_iQueueCapacity)
	{
		cout << "队列已满!" << endl;
		return true;
	}
	else
	{
		cout << "队列未满,开始操作!" << endl;
		return false;
	}
}

/************************************************************************/
/*判长函数QueueLength()  功能:获取队列长度             Author:Cyber Kaka*/
/************************************************************************/
int MyQueue::QueueLength()const
{
	return m_iQueueLen;
}

/************************************************************************/
/*入队函数EnQueue(int element)    功能:给队列中插入元素                 */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::EnQueue(int element)
{
	if (QueueFull())
	{
		return false;
	}
	else
	{
		//初始状态下,队头和队尾都是0,当空间富余时,队头不用移动
		//每插入一个元素之后,队尾向后指一个位置,以此类推
		//插入的数据类型要和数组数据类型一致
		m_pQueue[m_iTail] = element;
		m_iTail++;//队尾++,就像是个指针一样,指示队列位置
		//如果插入到了队头所在的位置时,m_iTail再加就不可以了
		//所以使用判断或对数组容量取余,从而使m_iTail合法
		m_iTail = m_iTail % m_iQueueCapacity;
		//if (m_iTail >= m_iQueueCapacity)
		//{
		//	m_iTail = 0;
		//}
		//else
		//{
		//	m_iQueueLen++;
		//}
		m_iQueueLen++;//每插入一个元素,就要将长度+1
		cout << "插入数据:" << element << endl;
		return true;
	}
}

/************************************************************************/
/*出队函数DeQueue(int &element)    功能:给队列中移除元素                */
/*注意:element必须是一个引用,不能是一个参数            Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::DeQueue(int &element)
{
	if (QueueEmpty())
	{
		cout << "队列为空!" << endl;
		return false;
	}
	else
	{
		//在环形队列中,如果空间为满,那么每进一个新元素,就要出一个旧元素
		//相应的,队头就要后移一位,尾部则指向原位
		element = m_pQueue[m_iHead];
		m_iHead++;//现在这是一个空位置,队头变为下一个元素
		//如果队头指到了原先队尾所在的位置时,m_iHead再加就不可以了
		//所以使用判断或对数组容量取余,从而使m_iHead合法
		m_iHead = m_iHead % m_iQueueCapacity;
		//if (m_iHead>=m_iQueueCapacity)
		//{
		//	m_iHead = 0;
		//} 
		//else
		//{
		//	m_iHead++;
		//}
		m_iQueueLen--;//每删去一个元素,就要将长度-1
		return true;
	}
}

/************************************************************************/
/*遍历函数QueueTraverse()   功能:遍历队列并输出元素    Author:Cyber Kaka*/
/************************************************************************/
void MyQueue::QueueTraverse()
{
	cout << endl;
	cout << "***********开始遍历***********" << endl;
	//判断队列是否为空,若为空则不用遍历
	if (QueueEmpty()==true)
	{
		cout << "队列为空!没有数据!" << endl;
	}
	else
	{	
		//使用循环遍历数组
		//将头的值加上长度的值,保证无论头如何增长,循环时的次数不会受到影响
		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
		{
			//由于i++在做i<m_iQueueCapacity的判断最后一步也是做了i++的
			//此时i等于m_iQueueCapacity,则执行最后一次循环体内容
			//但若是直接传i会导致数组越界,所以i也应该取余
			//这样,比m_iQueueCapacity小的数是直接算余数
			//i等于m_iQueueCapacity则会显示第一个数
			//Part1:
			//cout << m_pQueue[i%m_iQueueCapacity] << endl;
			//m_pQueue[i%m_iQueueCapacity].printInfo();
		}
	}
	cout << "*********本次遍历结束*********" << endl;
	cout << endl;
}
