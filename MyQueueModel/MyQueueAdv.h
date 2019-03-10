#ifndef MYQUEUE_H
#define MYQUEUE_H
/************************************************************************/
/*			 环形队列C++实现代码                              2019/03/09*/
/************************************************************************/

//为实现对复杂类型的支持,包含头文件
#include "CustomerBasic.h"

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

	//Part2:如果是插入Customer对象,则使用重载
	bool EnQueue(Customer element);

	//令首元素出队,即处理完第一个元素,原队列第二位变为现队列第一位
	bool DeQueue(int &element); //DeQueue(&Q,&element) 首元素出队

	//Part2:如果是移除Customer对象,则使用重载
	bool DeQueue(Customer &element);

	//对当前队列的每一个元素访问,输出队列内容
	//visit方法是在处理复杂情况时不同的相关操作,这里只定义了int类型
	//对于简单的数据类型,并没必要专门去写访问函数,所以不用写了
	void QueueTraverse();		//QueueTraverse(Q,visit()) 遍历队列

	//Part2:对于Customer对象有专门的队列修改
	void QueueTraverseCus();
private:
	//指针用于指向队列(数组),这个队列是在构造函数中被实例化的
	//int *m_pQueue;			//Part1:队列数组指针
	Customer *m_pQueue;			//Part2:Customer类型指针

	//队列元素个数,也称队列长度
	int m_iQueueLen;			//队列元素个数

	//指示队列的排队容量,在初始化时即被定义
	int m_iQueueCapacity;		//队列数组容量

	//定义队头和队尾
	//由于是个数组,在创建前不能直接赋值,所以定义的是队头和队尾的索引
	int m_iHead;
	int m_iTail;
};

#endif