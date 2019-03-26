#include <iostream>
#include <string>

#include "MyStackBasic.h"

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
	//m_pBuffer = new char[size];
	m_pBuffer = new char[m_iSize];
	//初始化栈顶
	m_iTop = 0;//当前栈是一个空栈
}


/************************************************************************/
/*析构函数~MyStack()         功能:回收一个栈空间       Author:Cyber Kaka*/
/************************************************************************/
MyStack::~MyStack()			  //回收栈空间内存    
{
	delete[]m_pBuffer;
	m_pBuffer = NULL;//将指针置空,否则会跳入else语句
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
/************************************************************************/
/*入栈函数push(char elem) 功能:将传入的元素传入栈空间  Author:Cyber Kaka*/
/************************************************************************/
void MyStack::push(char elem)  //元素入栈,栈顶上升    
{
	//入栈即将当前元素放到栈顶,入栈前判断一下是否为满
	if (stackFull())
	{//如果栈已满,则抛出异常,或设定函数返回值为bool类型
		throw string("栈已满!无法操作!");
		system("pause");
		system("exit");
	}
	else
	{
		cout << "插入数据:" << elem << "中..." << endl;
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
	}
}
//bool类型函数,如要使用,记得在头文件中加上声明【推荐】
//bool MyStack::push(char elem)
//{
//	//if (!stackFull())
//	//{
//	//	m_pBuffer[m_iTop] = elem;
//	//	m_iTop++;
//	//	return true;
//	//} 
//	//else
//	//{
//	//	return false;
//	//}
//	if (stackFull())
//	{
//		return false;
//	} 
//	else
//	{
//		m_pBuffer[m_iTop] = elem;
//		m_iTop++;
//		return true;
//	}
//}


/************************************************************************/
/*出栈函数pop(char &elem) 功能:将标记的元素传出栈空间  Author:Cyber Kaka*/
/************************************************************************/
char MyStack::pop(char &elem)  //元素出栈,栈顶下降          
{
	if (stackEmpty())
	{//如果栈已为空,则无元素可以出栈
		throw string("栈为空栈!无元素可出栈!");
		system("pause");
		system("exit");
	}
	else//即使是满栈,也可以出栈
	{
		//在入栈时将传入的elem的值赋值给m_pBuffer[m_iTop]之后,
		//m_iTop执行了++操作,也就是说它标记的是一个空位置,
		//因此在出栈的时候需要对其进行-1操作,使其指向栈顶的非空位置
		m_iTop--;
		cout << "移除数据:" << m_pBuffer[m_iTop] << "中..." << endl;
		elem = m_pBuffer[m_iTop];
		//当没有传入参数的时候可以这样写:
		//m_iTop--;
		//return m_pBuffer[m_iTop];
		return elem;
	}
}
//bool类型函数,如要使用,记得在头文件中加上声明【推荐】
//bool MyStack::pop(char &elem)
//{
//	/*if (!stackEmpty())
//	{
//		m_iTop--;
//		elem = m_pBuffer[m_iTop];
//		return true;
//	}
//	else
//	{
//		return false;
//	}*/
//	if (stackEmpty())
//	{
//		return false;
//	} 
//	else
//	{
//		m_iTop--;
//		elem = m_pBuffer[m_iTop];
//		return true;
//	}
//}


/************************************************************************/
/*遍历函数stackTraverse() 功能:遍历栈空间,打印所有元素 Author:Cyber Kaka*/
/************************************************************************/
void MyStack::stackTraverse(/*visit()*/)  //遍历栈中所有元素
{	//visit()函数其实就是一个函数指针
	//当一个栈是一个较为复杂的对象元素栈的时候,
	//需要有这样的一个专有visit()函数来访问每一个栈中元素

	//对于当前情况,只需要一个for循环即可
	//for (int i=0;i<m_iTop;i++)	//i从0开始,实际上是从栈底往栈顶做遍历
	//{
	//	cout << "输出第" << i << "个元素: " ;
	//	cout << m_pBuffer[i] << endl;
	//}

	for (int i = m_iTop - 1; i >= 0; i--)//i从顶开始,实际上是从栈顶往栈底做遍历
	{
		cout << "输出第" << i << "个元素: ";
		cout << m_pBuffer[i] << endl;
	}
}
//关于stackTraverse()函数的延伸
//可以写成这样:有一个布尔值做标记的函数,记得在头文件中加函数声明
//void MyStack::stackTraverse(bool isFromButtom)
//当为true时,即从栈底开始遍历
//当为false时,即从栈顶开始遍历,即将上面的两种循环放进一个判断体中
//void MyStack::stackTraverse(bool isFromButtom)
//{
//	if (isFromButtom)
//	{
//		for (int i=0;i<m_iTop;i++)	//i从0开始,实际上是从栈底往栈顶做遍历
//		{
//			cout << m_pBuffer[i] << ",";
//		}
//	} 
//	else
//	{
//		for (int i = m_iTop - 1; i >= 0; i--)//i从顶开始,实际上是从栈顶往栈底做遍历
//		{
//			cout << m_pBuffer[i] << ",";
//		}
//	}
//}