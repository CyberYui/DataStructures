#include "MyListBasic.h"
#include <iostream>
using namespace std;

/************************************************************************/
/*构造函数List(int size)       功能:创建一个线性表     Author:Cyber Kaka*/
/************************************************************************/
List::List(int size)			//创建线性表(顺序表)
{
	//传入的参数size赋值给线性表容量
	m_iSize = size;
	//分配内存
	m_pList = new int[m_iSize];
	//初始化时没有元素在表
	m_iLength = 0;
}

/************************************************************************/
/*析构函数~List()          功能:销毁一个线性表         Author:Cyber Kaka*/
/************************************************************************/
List::~List()					//销毁线性表(顺序表)        
{
	delete m_pList;
	m_pList = NULL;
}

/************************************************************************/
/*清空函数ClearList()      功能:清空一个线性表         Author:Cyber Kaka*/
/************************************************************************/
void List::ClearList()			//清空线性表(顺序表)
{
	m_iLength = 0;
}

/************************************************************************/
/*判空函数ListEmpty()      功能:判断线性表是否为空     Author:Cyber Kaka*/
/************************************************************************/
bool List::ListEmpty()			//判断线性表(顺序表)是否为空(无元素)
{
	//判断当前的m_iLength是否为0,为0则证明线性表为空
	//return 0 == m_iLength ? true : false;
	if (0 == m_iLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/************************************************************************/
/*获取长度函数ListLength()   功能:判断线性表是否为空   Author:Cyber Kaka*/
/************************************************************************/
int List::ListLength()			//获取线性表(顺序表)长度(个数)
{
	return m_iLength;
}

/************************************************************************/
/*  获取元素函数GetElem(int i, Elem *e)									*/
/*    功能:获取指定元素								   Author:Cyber Kaka*/
/************************************************************************/
bool List::GetElem(int i, int *e)	//获取线性表(顺序表)的指定元素
{
	//在取元素时,要看索引i是否合法,i可能是小于0的,也可能是比容量大的
	if (i < 0 || i >= m_iSize)
	{
		return false;
	}
	else
	{
		*e = m_pList[i];
		return true;
	}
}

/************************************************************************/
/*  元素定位函数LocateElem(int *e)										*/
/*    功能:获取指定元素的位置						   Author:Cyber Kaka*/
/************************************************************************/
int List::LocateElem(int *e)		//寻找第一个满足e的数据元素的位置
{
	for (int i = 0; i < m_iLength; i++)
	{
		if (m_pList[i] == *e)
		{
			return i;
		}
		else
		{
			break;
		}
	}
	//返回-1表示没有找到对应元素
	return -1;
}

/************************************************************************/
/*  前驱获取函数PriorElem(int *currentElem, int *preElem)				*/
/*    功能:获取指定元素的前驱						   Author:Cyber Kaka*/
/************************************************************************/
bool List::PriorElem(int *currentElem, int *preElem)  //获取指定元素的前驱
{
	//可以借助之前编译的函数完成操作
	//如用LocateElem(int *e)找到当前元素的位置,并接收返回值
	int temp = LocateElem(currentElem);
	//对返回值进行判断,看它有没有前驱
	if (temp == -1)
	{
		//找不到就返回否
		return false;
	}
	//找到了又分两种情况
	//1.找到了,但是当前元素位置为0,则证明当前元素在顺序表首尾,不存在前驱,返回否
	//2.找到了,并且存在前驱的情况
	else
	{
		if (temp == 0)
		{
			return false;
		}
		else
		{
			//既不为0,也不为-1,有前驱
			//则将前驱的值赋给preElem
			*preElem = m_pList[temp - 1];
			return true;
		}
	}
}

/************************************************************************/
/*  后继获取函数NextElem(int *currentElem, int *nextElem)				*/
/*    功能:获取指定元素的后继						   Author:Cyber Kaka*/
/************************************************************************/
bool List::NextElem(int *currentElem, int *nextElem)  //获取指定元素的后继
{
	int temp = LocateElem(currentElem);
	if (temp == -1)
	{
		return false;
	}
	else
	{
		//检查temp的值是否为线性表的最后一个元素
		//线性表个数-1即代表线性表的最后一个元素
		if (temp == m_iLength - 1)
		{
			return false;
		}
		else
		{
			//当前元素不是最后一个元素
			//则temp+1即为其后继元素索引
			*nextElem = m_pList[temp + 1];
			return true;
		}
	}
}

/************************************************************************/
/*  线性表(顺序表)遍历函数ListTraverse()								*/
/*    功能:遍历线性表(顺序表),输出元素				   Author:Cyber Kaka*/
/************************************************************************/
void List::ListTraverse()
{
	for (int i = 0; i < m_iLength; i++)
	{
		cout << m_pList[i] << endl;
	}
}

/************************************************************************/
/*  线性表(顺序表)插入函数ListInsert(int i,int *e)						*/
/*    功能:向线性表(顺序表)中插入元素				   Author:Cyber Kaka*/
/************************************************************************/
bool List::ListInsert(int i, int *e)
{
	//要在i处插入e这个元素,并将i之后的各个元素后移一位
	//在操作时应该先移动,再赋值,否则会将i位置的元素覆盖
	//如果使用temp临时变量,则会增加计算量

	//对于i的值,它可能有小于0或者比length还要大
	if (i < 0 || i> m_iLength)
	{
		//如果i等于m_iLength,即i是当前表的最后一位
		return false;
	}
	else
	{
		//否则移动后置元素并插入e在i位置

		//在移动时,如果for (int k = i; k < m_iLength; k++)	
		//即从i开始移动,则会一步一步覆盖i之后的值
		//所以最好的方法是从后面开始后移,这样移动的每一个都是空位
		for (int k = m_iLength - 1; k >= i; k--)
		{
			//将每一个位置的元素放到其后面一位上去
			m_pList[k + 1] = m_pList[k];
			//如果i已经等于m_iLength了,那么k能否大于m_iLength呢
			//k的初值是m_iLength-1,此时k已经不满足k>=i了
			//由此直接跳出循环,执行m_pList[i] = *e;
		}
		//循环完成后插入i位置的元素
		m_pList[i] = *e;
		//插入一个元素就要将m_iLength加1,这样才能使其显示当前表有多少元素
		m_iLength++;

		return true;
	}
}

/************************************************************************/
/*  线性表(顺序表)移除元素函数ListInsert(int i,int *e)					*/
/*    功能:从线性表(顺序表)中移除元素				   Author:Cyber Kaka*/
/************************************************************************/
bool List::ListDelete(int i, int *e)
{
	//同样,需要先判断i的值是否合法
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}
	else
	{
		//此时要删除i位置的元素,并能返回它
		//与插入不同,这时的操作应该是先移除,再移动
		*e = m_pList[i];
		//将后面的元素依次前移,从离移除掉的位置最近的元素开始
		for (int k = i + 1; k < m_iLength; k++)
		{
			m_pList[k - 1] = m_pList[k];
		}
		//删除一个元素就要m_iLength减小1,这样才能保证元素个数不会越界
		m_iLength--;

		return true;
	}
}