#include "MyString.h"
#include <string.h>

/****************************************************************/
/*  项目名称:MyOwnString
/*  项目描述:关于串的C++实现
/*  类名称:MyString
/*  创建时间:2019-3-21	
/*  Author:Cyber Kaka
/****************************************************************/


/****************************************************************/
/* MyString(const char *str)									*/
/* 功能:初始化一个字符串										*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString::MyString(const char *str)
{
	//首先判断初始化中str是否为空
	if (str == NULL)
	{
		m_pStr = new char[1];//为空则自动申请存放结束标志
		*m_pStr = '\0';
	}
	else
	{
		//str内容不为空,保存其长度
		m_iLen = strlen(str);
		//从堆中申请char数组
		m_pStr = new char[m_iLen + 1];
		//查看是否申请成功
		if (NULL == m_pStr)
		{
			//失败则直接返回
			return;
		}
		//申请成功,将str的内容复制给m_pStr
		strcpy_s(m_pStr, m_iLen+1 , str);
	}
}


/****************************************************************/
/* ~MyString()													*/
/* 功能:销毁一个串												*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString::~MyString()
{
	//直接删除指针即可
	delete[]m_pStr;
	m_pStr = NULL;
}


/****************************************************************/
/* MyString(const MyString &str)								*/
/* 功能:拷贝构造函数,从一个已知对象初始化MyString对象			*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString::MyString(const MyString &str)
{
	//传入str,对其修饰const,不修改其内容
	m_iLen = strlen(str.m_pStr);
	m_pStr = new char[m_iLen + 1];
	if (NULL == m_pStr)
	{
		return;
	}
	strcpy_s(m_pStr, m_iLen+1 , str.m_pStr);
}


/****************************************************************/
/* MyString operator=(const MyString &str)						*/
/* 功能:赋值运算符重载											*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString & MyString::operator=(const MyString &str)
{
	//若传入的串与原串相同,直接输出原串即可
	if (this == &str)
	{
		return *this;
	}
	//两串不同,原串不为空,先清空原串
	if (m_pStr)
	{
		//与队列等不同,串是有长度限定的
		//可以设定串长度动态增长,另其多余空间由特殊符号占据
		delete[]m_pStr;
		m_pStr = NULL;
	}
	//将传入的串内容存入原串中
	m_iLen = strlen(str.m_pStr);
	m_pStr = new char[m_iLen + 1];
	strcpy_s(m_pStr, m_iLen+1 , str.m_pStr);
	//将修改好的原串返回
	return *this;
}


/****************************************************************/
/* MyString operator+(const MyString &str)						*/
/* 功能:加号运算符重载,将传入的str添加到原串之后				*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString & MyString::operator+(const MyString &str)
{
	char *temp;
	temp = new char[strlen(m_pStr) + strlen(str.m_pStr) + 1];
	int tempLen = strlen(m_pStr) + strlen(str.m_pStr) + 1;

	strcpy_s(temp, tempLen, m_pStr);

	delete[]m_pStr;
	m_pStr = NULL;

	
	strcat_s(temp, tempLen, str.m_pStr);

	m_pStr = temp;

	return *this;
}


/****************************************************************/
/* MyString operator==(const MyString &aStr)					*/
/* 功能:判断两个串是否相等										*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
bool MyString::operator==(const MyString &aStr)
{
	for (int i=0;i!=m_iLen;++i)
	{
		if (*(m_pStr + i) != *(aStr.m_pStr + i))
		{
			//指针不断指向下一个进行匹配,只要有字符不等则输出错误
			return false;
		}
	}
	return true;
}


/****************************************************************/
/* getLength()													*/
/* 功能:返回当前串的长度										*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
int MyString::getLength()
{
	if (NULL == m_pStr)
	{
		return 0;
	}
	return m_iLen;
}


/****************************************************************/
/* violentMatch(MyString &str, MyString &pre)					*/
/* 功能:一个简单的串匹配,传入主串souStr和要找的串subStr,查询	*/
/*		subStr是否存在于subStr,存在则返回下标,否则返回-1		*/
/* 																*/
/* 创建日期:2019-3-22						Author:Cyber Kaka	*/
/****************************************************************/
int MyString::violentMatch(MyString &str, MyString &pre)
{
	//两个迭代器
	int i = 0;
	int j = 0;
	//开始循环进行匹配
	while (i < str.m_iLen&&j < pre.m_iLen)
	{
		//如果当前字符匹配成功,则继续下去
		if (str.m_pStr[i] == pre.m_pStr[j])
		{
			i++;
			j++;
		}
		//当前字符不匹配,则str从前一个匹配组的第二位开始进行新匹配
		//j用于pre串,其重新开始匹配
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	//当匹配成功,输出index+1,即在串中的位置
	if (j == pre.m_iLen)
	{
		//即使是从第一位匹配的,也不会显示数组下标0
		return i - j + 1;
	}
	//匹配不成功,输出-1
	else
	{
		return -1;
	}
}


/****************************************************************/
/* getNext(MyString &pre, int array[])							*/
/* 功能:KMP算法的辅助函数,用于测量主串和模式串的next[]数列		*/
/* 																*/
/* 创建日期:2019-3-22						Author:Cyber Kaka	*/
/****************************************************************/
void MyString::getNext(MyString &pre, int next[])
{
	//首先给next数组第一位放-1
	next[0] = -1;
	int i = 0, j = -1;
	//逐步通过PMT保存next数列
	while (i < pre.m_iLen)
	{
		if (j == -1 || pre.m_pStr[i] == pre.m_pStr[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}


/****************************************************************/
/* KMP(MyString &str, MyString &pre)							*/
/* 功能:KMP算法的具体实现										*/
/* 																*/
/* 创建日期:2019-3-23						Author:Cyber Kaka	*/
/****************************************************************/
int MyString::KMP(MyString &str, MyString &pre,int next[])
{
	//KMP匹配算法
	int i = 0;
	int j = 0;
	while ((i < str.m_iLen) && (j < pre.m_iLen))
	{
		if (j == -1 || str.m_pStr[i] == pre.m_pStr[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == pre.m_iLen)
	{
		//匹配成功,输出位置,数组计算从0开始,所以+1
		return i - j + 1;
	}
	else
	{
		//若匹配失败,输出-1
		return -1;
	}
}


/****************************************************************/
/* friend ostream &operator<<(ostream &out, const MyString &str)*/
/* 功能:输出运算符重载,用于使串也可以使用<<						*/
/* 																*/
/* 创建日期:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
ostream &operator<<(ostream &out, const MyString &str)
{
	out << str.m_pStr;
	return out;
}

/*
可能会在运行时遇到这样的警告
This function or variable may be unsafe. 
Consider using strcpy_s instead. 
To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
See online help for details.

这种微软的警告，主要因为那些C库的函数，很多函数内部是不进行参数检测的（包括越界类的），
微软担心使用这些会造成内存异常，所以就改写了同样功能的函数，
改写了的函数进行了参数的检测，使用这些新的函数会更安全和便捷。
关于这些改写的函数你不用专门去记忆，因为编译器对于每个函数在给出警告时，
都会告诉你相应的安全函数，查看警告信息就可以获知，在使用时也再查看一下MSDN详细了解。
*/
