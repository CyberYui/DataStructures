#include <iostream>
#include <string>

#include "MyStackAdv.h"

using namespace std;
//逐一实现头文件中的函数

/************************************************************************/
/*构造函数MyStack(int size)       功能:创建一个栈      Author:Cyber Kaka*/
/************************************************************************/
MyStack::MyStack(int size)	  //分配内存初始化栈空间,设定栈容量,栈顶   
{
	//首先将容量传给数据成员
	m_iSize = size;
	//申请内存
	m_pBuffer = new Coordinate[m_iSize];//构造函数指针为Coordinate类型的
	//初始化栈顶
	m_iTop = 0;//当前栈是一个空栈
}


/************************************************************************/
/*析构函数~MyStack()         功能:回收一个栈空间       Author:Cyber Kaka*/
/************************************************************************/
MyStack::~MyStack()			  //回收栈空间内存    
{
	delete[]m_pBuffer;
	m_pBuffer = NULL;//将指针置空,否则会直接跳入else语句
	//判断一下是否回收成功
	if (NULL == m_pBuffer)
	{
		cout << "回收栈空间成功!" << endl;
	}
	else
	{
		cout << "回收栈空间失败!请检查代码" << endl;
		system("pause");
		system("exit");
	}
}


/************************************************************************/
/*判空函数stackEmpty()     功能:判断栈空间是否为空     Author:Cyber Kaka*/
/************************************************************************/
bool MyStack::stackEmpty()	   //判定栈是否为空,为空返回true,非空返回false 
{
	//看看m_iTop是否为0
	if (0 == m_iTop)
	{//if(m_iTop == 0)虽然也是判断,但如果只写了一个=则不会报错
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
bool MyStack::stackFull()	   //判定栈是否为满,为满返回true,不满返回false 
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
void MyStack::clearStack()	  //清空栈                                    
{
	//要清空一个栈,不需要把每个位置的内容都清空
	//只需要让栈顶复原,之后每次赋值会覆盖掉之前位置的内容
	m_iTop = 0;//这样标记着栈中所有内容无效
}


/************************************************************************/
/*计数函数stackLength() 功能:统计一个栈现有的元素个数  Author:Cyber Kaka*/
/************************************************************************/
int MyStack::stackLength()	  //统计已有元素的个数    
{
	//当前栈放的元素个数,刚刚好就是栈顶的计数,即m_iTop
	return m_iTop;
}


//以下函数为重要函数
/******************************************************************************/
/*入栈函数push(Coordinate elem) 功能:将传入的元素传入栈空间  Author:Cyber Kaka*/
/******************************************************************************/
bool MyStack::push(Coordinate elem)
{
	if (stackFull())
	{
		return false;
	}
	else
	{
		//这里赋值也是需要多加考虑的,由于当前的Coordinate类是简单数据类型的
		//所以只需要值复制即可,即默认的拷贝构造函数,
		//以及默认的拷贝运算符重载就能满足要求
		//不需要再另写拷贝构造函数和对运算符进行重载
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
		return true;
	}
}


/******************************************************************************/
/*出栈函数pop(Coordinate &elem) 功能:将标记的元素传出栈空间  Author:Cyber Kaka*/
/******************************************************************************/
bool MyStack::pop(Coordinate &elem)
{
	if (stackEmpty())
	{
		return false;
	}
	else
	{
		m_iTop--;
		elem = m_pBuffer[m_iTop];//注意点同push函数
		return true;
	}
}


/************************************************************************/
/*  遍历函数stackTraverse(bool isFromButtom)                            */
/*      功能:遍历栈空间,打印所有元素                   Author:Cyber Kaka*/
/************************************************************************/
//void MyStack::stackTraverse(bool isFromButtom)
//当为true时,即从栈底开始遍历
//当为false时,即从栈顶开始遍历,即将上面的两种循环放进一个判断体中
void MyStack::stackTraverse(bool isFromButtom)//遍历栈中所有元素
{
	if (isFromButtom)
	{
		for (int i = 0; i < m_iTop; i++)	 //i从0开始,实际上是从栈底往栈顶做遍历
		{
			//【注意】使用cout不能实现输出的原因是没有对<<进行运算符重载操作
			//因此只能使用调用printCoordinate()函数的方式输出内容
			m_pBuffer[i].printCoordinate();
		}
	}
	else
	{
		for (int i = m_iTop - 1; i >= 0; i--)//i从顶开始,实际上是从栈顶往栈底做遍历
		{
			m_pBuffer[i].printCoordinate();
		}
	}
}