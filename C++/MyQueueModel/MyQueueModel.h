#ifndef MYQUEUEMODEL_H
#define MYQUEUEMODEL_H
/************************************************************************/
/*			 环形队列C++实现代码                              2019/03/09*/
/************************************************************************/

//为实现对复杂类型的支持,包含头文件
#include "CustomerTest.h"

//类模版改造
template <typename T>
class MyQueue
{
public:							//后置注释中显示的是如何在C语言中定义相关函数
	//创建一个队列,要求一定要有一个指针指向这个队列,使得队列有一定的资源(内存空间)
	//queueCapacity是定义的容量大小变量
	MyQueue(int queueCapacity);	//InitQueue(&Q)    创建队列

	//销毁队列函数,用于编译完成后的处理工作
	//析构函数,将申请的指针销毁,释放相应的内存
	virtual ~MyQueue();			//DestroyQueue(&Q) 销毁队列

	//清空队列,使得队列仅占内存空间,但不包含实际数据内容
	//C++通过自己的数据成员就能维护起类似于C语言的全局变量了
	void ClearQueue();			//ChearQueue(&Q)   清空队列

	//判断当前队列是否为空,若队列为空,则无法再删元素,相对的应有判满函数
	//常成员函数,与bool QueueEmpty(const MyQueue *this)同理解
	//判断m_pQueue指针指向的数组是否为空
	bool QueueEmpty()const;		//QueueLength(Q)   判空队列

	bool QueueFull()const;		//QueueFull(Q)	   判满队列

	//用于判断当前队列元素个数,即队列长度
	//常成员函数,与int QueueLength(const MyQueue *this)同理解
	int QueueLength()const;		//QueueLength(Q)   队列长度

	//将新元素入队,由于队列无法插队,所以新元素被排入队列尾部
	bool EnQueue(int element);	//EnQueue(&Q,element)  新元素入队

	//Part2:如果是插入T对象,则使用重载
	bool EnQueue(T element);

	//令首元素出队,即处理完第一个元素,原队列第二位变为现队列第一位
	bool DeQueue(int &element); //DeQueue(&Q,&element) 首元素出队

	//Part2:如果是移除T对象,则使用重载
	bool DeQueue(T &element);

	//对当前队列的每一个元素访问,输出队列内容
	//visit方法是在处理复杂情况时不同的相关操作,这里只定义了int类型
	//对于简单的数据类型,并没必要专门去写访问函数,所以不用写了
	void QueueTraverse();		//QueueTraverse(Q,visit()) 遍历队列

	//Part2:对于Customer对象有专门的队列修改
	void QueueTraverseCus();
private:
	//指针用于指向队列(数组),这个队列是在构造函数中被实例化的
	//int *m_pQueue;			//Part1:队列数组指针
	T *m_pQueue;			//Part2:T类型指针

	//队列元素个数,也称队列长度
	int m_iQueueLen;			//队列元素个数

	//指示队列的排队容量,在初始化时即被定义
	int m_iQueueCapacity;		//队列数组容量

	//定义队头和队尾
	//由于是个数组,在创建前不能直接赋值,所以定义的是队头和队尾的索引
	int m_iHead;
	int m_iTail;
};

//逐一实现头文件中的函数
//每个函数前都需要写明template <typename T>
/************************************************************************/
/*构造函数MyQueue       功能:创建一个环形队列          Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
MyQueue<T>::MyQueue(int queueCapacity)
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
	//在这里有一个遗漏,因为从堆中申请内存是可能申请失败的,在这里不做处理
	//m_pQueue = new int[m_iQueueCapacity];

	//if (NULL==m_pQueue)
	//{
	//	cout << "Memory distributed fail !" << endl;
	//}
	//申请T内存
	m_pQueue = new T[m_iQueueCapacity];

}

/************************************************************************/
/*析构函数~MyQueue      功能:销毁一个环形队列,销毁指针,释放内存         */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
MyQueue<T>::~MyQueue()
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
template <typename T>
void MyQueue<T>::ClearQueue()
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
template <typename T>
bool MyQueue<T>::QueueEmpty()const
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
template <typename T>
bool MyQueue<T>::QueueFull()const
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
template <typename T>
int MyQueue<T>::QueueLength()const
{
	return m_iQueueLen;
}

/************************************************************************/
/*入队函数EnQueue(int element)    功能:给队列中插入元素                 */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
//Part1:
//bool MyQueue::EnQueue(int element)
//{
//	if (QueueFull())
//	{
//		return false;
//	}
//	else
//	{
//		//初始状态下,队头和队尾都是0,当空间富余时,队头不用移动
//		//每插入一个元素之后,队尾向后指一个位置,以此类推
//		//插入的数据类型要和数组数据类型一致
//		m_pQueue[m_iTail] = element;
//		m_iTail++;//队尾++,就像是个指针一样,指示队列位置
//		//如果插入到了队头所在的位置时,m_iTail再加就不可以了
//		//所以使用判断或对数组容量取余,从而使m_iTail合法
//		m_iTail = m_iTail % m_iQueueCapacity;
//		//if (m_iTail >= m_iQueueCapacity)
//		//{
//		//	m_iTail = 0;
//		//}
//		//else
//		//{
//		//	m_iQueueLen++;
//		//}
//		m_iQueueLen++;//每插入一个元素,就要将长度+1
//		cout << "插入数据:" << element << endl;
//		return true;
//	}
//}

/************************************************************************/
/*入队函数EnQueue(Customer element)    功能:给队列中插入Customer类型元素*/
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
//Part2
template <typename T>
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
		//cout << "插入数据:" << element << endl;
		return true;
	}
}

/************************************************************************/
/*出队函数DeQueue(Customer &element)   功能:给队列中移除Customer类型元素*/
/*注意:element必须是一个引用,不能是一个参数            Author:Cyber Kaka*/
/************************************************************************/
//Part2:
template <typename T>
bool MyQueue<T>::DeQueue(T &element)
{
	if (QueueEmpty())
	{
		cout << "队列为空!" << endl;
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
/*出队函数DeQueue(int &element)    功能:给队列中移除元素                */
/*注意:element必须是一个引用,不能是一个参数            Author:Cyber Kaka*/
/************************************************************************/
//Part1:
//bool MyQueue::DeQueue(int &element)
//{
//	if (QueueEmpty())
//	{
//		cout << "队列为空!" << endl;
//		return false;
//	}
//	else
//	{
//		//在环形队列中,如果空间为满,那么每进一个新元素,就要出一个旧元素
//		//相应的,队头就要后移一位,尾部则指向原位
//		element = m_pQueue[m_iHead];
//		m_iHead++;//现在这是一个空位置,队头变为下一个元素
//		//如果队头指到了原先队尾所在的位置时,m_iHead再加就不可以了
//		//所以使用判断或对数组容量取余,从而使m_iHead合法
//		m_iHead = m_iHead % m_iQueueCapacity;
//		//if (m_iHead>=m_iQueueCapacity)
//		//{
//		//	m_iHead = 0;
//		//} 
//		//else
//		//{
//		//	m_iHead++;
//		//}
//		m_iQueueLen--;//每删去一个元素,就要将长度-1
//		return true;
//	}
//}

/************************************************************************/
/*遍历函数QueueTraverse()   功能:遍历队列并输出元素    Author:Cyber Kaka*/
/************************************************************************/
//Part1
//void MyQueue::QueueTraverse()
//{
//	cout << endl;
//	cout << "***********开始遍历***********" << endl;
//	//判断队列是否为空,若为空则不用遍历
//	if (QueueEmpty()==true)
//	{
//		cout << "队列为空!没有数据!" << endl;
//	}
//	else
//	{	
//		//使用循环遍历数组
//		//将头的值加上长度的值,保证无论头如何增长,循环时的次数不会受到影响
//		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
//		{
//			//由于i++在做i<m_iQueueCapacity的判断最后一步也是做了i++的
//			//此时i等于m_iQueueCapacity,则执行最后一次循环体内容
//			//但若是直接传i会导致数组越界,所以i也应该取余
//			//这样,比m_iQueueCapacity小的数是直接算余数
//			//i等于m_iQueueCapacity则会显示第一个数
//			//Part1:
//			//cout << m_pQueue[i%m_iQueueCapacity] << endl;
//			//m_pQueue[i%m_iQueueCapacity].printInfo();
//		}
//	}
//	cout << "*********本次遍历结束*********" << endl;
//	cout << endl;
//}

/************************************************************************/
/*遍历函数QueueTraverseCus()   功能:遍历队列并输出元素  Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
void MyQueue<T>::QueueTraverseCus()
{
	cout << endl;
	cout << "***********开始遍历***********" << endl;
	if (QueueEmpty() == true)
	{
		cout << "队列为空!没有数据!" << endl;
	}
	else
	{
		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
		{
			cout << m_pQueue[i%m_iQueueCapacity];
			cout << "前面还有" << (i - m_iHead) << "个人" << endl;
		}
	}
	cout << "*********本次遍历结束*********" << endl;
	cout << endl;
}


#endif // MYQUEUEMODEL_H