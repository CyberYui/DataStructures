#ifndef MYSTACKMODEL_H
#define MYSTACKMODEL_H

#include "CoordinateModel.h"
/************************************************************************/
/* 栈类(模版类):template<typename T>                                    */
/*     MyStack(int size);   //分配内存初始化栈空间,设定栈容量,栈顶      */
/*     ~MyStack();          //回收栈空间内存                            */
/*     bool stackEmpty();   //判定栈是否为空,为空返回true,非空返回false */
/*     bool stackFull();    //判定栈是否为满,为满返回true,不满返回false */
/*     void clearStack();   //清空栈                                    */
/*     int stackLength();   //统计已有元素的个数                        */
/*     void push(T elem);	//元素入栈,栈顶上升                         */
/*     char pop(T &elem);   //元素出栈,栈顶下降                         */
/*     void stackTraverse(bool isFromButtom);    //遍历栈中所有元素     */
/*                                                                      */
/* 目的:掌握栈的实现原理和运行机制               创建日期:2019-03-10    */
/************************************************************************/
//类模板改造
//.cpp文件内容由于类模板的要求,将内容都放置在了.h文件中
//原有的.cpp文件已经被销毁
//1.首先使用关键字template对类内的数据类型进行模板化操作
template <typename T>
class MyStack
{
public:
	MyStack(int size);		//分配内存初始化栈空间,设定栈容量,栈顶      
	~MyStack();				//回收栈空间内存                            
	bool stackEmpty();		//判定栈是否为空,为空返回true,非空返回false 
	bool stackFull();		//判定栈是否为满,为满返回true,不满返回false 
	void clearStack();		//清空栈                                    
	int stackLength();		//统计已有元素的个数 

	//面对T类型进行相应的改造,由于可能复杂可能简单,所以要用到运算符重载
	//这里放入一个T对象,由于要传入的类对象包含复杂内容,如实例化指针等
	//因此需要应用到拷贝构造函数和运算符重载等内容
	//2.修改这里的类型
	bool push(T elem);	   //元素入栈,栈顶上升
	bool pop(T &elem);     //元素出栈,栈顶下降 
	void stackTraverse(bool isFromButtom);   //遍历栈中所有元素
private:
	//2.修改这里的类型
	T *m_pBuffer;		  //栈空间指针,指针指向T类型栈空间
	int m_iSize;		  //栈容量
	int m_iTop;			  //栈顶,栈中元素个数
	//栈底不用写,因为栈底永远都是0,不可能变化
};




//逐一实现上述的各个函数
//3.遵循类模板的语法,给每一个函数头前都加上template <typename T>
//4.在类名之后写上<T>

/************************************************************************/
/*构造函数MyStack(int size)       功能:创建一个栈      Author:Cyber Kaka*/
/************************************************************************/
//5.修改构造函数
template <typename T>
MyStack<T>::MyStack(int size)    //分配内存初始化栈空间,设定栈容量,栈顶   
{
	//首先将容量传给数据成员
	m_iSize = size;
	//申请内存
	m_pBuffer = new T[m_iSize];  //构造函数需要修改成对应T类型的模版
	//初始化栈顶
	m_iTop = 0;//当前栈是一个空栈
	cout << "初始化内存空间成功" << endl;
}


/************************************************************************/
/*析构函数~MyStack()         功能:回收一个栈空间       Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
MyStack<T>::~MyStack()			  //回收栈空间内存    
{
	delete[]m_pBuffer;
	m_pBuffer = NULL;//将指针置空,否则会跳入else语句
	//判断一下是否回收成功
	if (NULL == m_pBuffer)
	{
		cout << "回收栈空间成功..." << endl;
	}
	else
	{
		cout << "回收栈空间失败!请检查代码";
		system("pause");
		system("exit");
	}
}


/************************************************************************/
/*判空函数stackEmpty()     功能:判断栈空间是否为空     Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
bool MyStack<T>::stackEmpty()	   //判定栈是否为空,为空返回true,非空返回false 
{
	//看看m_iTop是否为0
	if (0 == m_iTop)
	{//if(m_iTop == 0)虽然也是判断,但如果只写了一个=则不会报错,不利于寻找原因
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************/
/*判满函数stackFull()     功能:判断栈空间是否为满      Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
bool MyStack<T>::stackFull()	   //判定栈是否为满,为满返回true,不满返回false 
{
	//判满不仅仅要判断m_iTop,而应该判断的是m_iSize是否与m_iTop相等
	//因为只有这样,当m_iTop和m_iSize相等时,栈显示满
	if (m_iTop == m_iSize)//if (m_iTop >= m_iSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************/
/*清空函数clearStack()          功能:清空一个栈        Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
void MyStack<T>::clearStack()	  //清空栈                                    
{
	//要清空一个栈,不需要把每个位置的内容都清空
	//只需要让栈顶复原,之后每次赋值会覆盖掉之前位置的内容
	m_iTop = 0;//这样标记着栈中所有内容无效
}


/************************************************************************/
/*计数函数stackLength() 功能:统计一个栈现有的元素个数  Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
int MyStack<T>::stackLength()	  //统计已有元素的个数    
{
	//当前栈放的元素个数,刚刚好就是栈顶的计数,即m_iTop
	return m_iTop;
}


//以下函数为重要函数
/************************************************************************/
/*入栈函数push(char elem) 功能:将传入的元素传入栈空间  Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
//6.修改push传入参数对象的类型
bool MyStack<T>::push(T elem)
{
	if (stackFull())
	{
		return false;
	}
	else
	{
		cout << "传入数据:" << elem << "中..." << endl;
		//这里赋值也是需要多加考虑的,由于当前的T类型是模版类的
		//所以需要对运算符进行重载设置,保证输出
		//由于作为例子的Coordinate类中数据较为简单
		//故不需要再另写拷贝构造函数,使用默认的拷贝构造函数即可
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
		return true;
	}
}


/************************************************************************/
/*出栈函数pop(T &elem)   功能:将标记的元素传出栈空间   Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
//7.修改pop传入参数对象的类型
bool MyStack<T>::pop(T &elem)
{
	if (stackEmpty())
	{
		return false;
	}
	else
	{
		m_iTop--;
		elem = m_pBuffer[m_iTop];//注意原因同上
		return true;
	}
}


/************************************************************************/
/*  遍历函数stackTraverse(bool isFromButtom)                            */
/*    void MyStack::stackTraverse(bool isFromButtom)                    */
/*    1.当为true时,即从栈底开始遍历                                     */
/*    2.当为false时,即从栈顶开始遍历,即将两种循环放进一个判断体中即可   */
/*    功能:遍历栈空间,打印所有元素                   Author:Cyber Kaka  */
/************************************************************************/
template <typename T>
void MyStack<T>::stackTraverse(bool isFromButtom)//遍历栈中所有元素
{
	if (isFromButtom)
	{
		cout << "开始从栈底打印数据..." << endl;
		for (int i = 0; i < m_iTop; i++)	//i从0开始,实际上是从栈底往栈顶做遍历
		{
			//【注意】使用cout不能实现输出的原因是没有对<<进行运算符重载操作
			//8.在这里修改成通用的输出方式
			//对于Coordinate类型的对象,使用cout显然是不可以的,所以需要对<<进行运算符重载
			cout << m_pBuffer[i] << endl;
		}
		cout << "从栈底打印数据结束..." << endl;
	}
	else
	{
		cout << "开始从栈顶打印数据..." << endl;
		for (int i = m_iTop - 1; i >= 0; i--)//i从顶开始,实际上是从栈顶往栈底做遍历
		{
			//9.在这里修改成通用的输出方式
			//由于类模板需要写在同一个文件中,所以需要把Cpp文件内容放置于.h文件中
			cout << m_pBuffer[i] << endl;
		}
		cout << "从栈顶打印数据结束..." << endl;
	}
}

#endif