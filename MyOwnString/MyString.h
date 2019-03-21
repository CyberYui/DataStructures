#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class MyString
{
	//const指明了函数不会修改该类的任何成员数据的值，称为常量成员函数
public:
	MyString(const char *str = NULL);			//构造函数
	MyString(const MyString &str);				//拷贝构造函数
	~MyString();								//析构函数
	MyString & operator=(const MyString &str);	//=号的运算符重载
	MyString & operator+(const MyString &str);	//+号的运算符重载
	bool operator==(const MyString &aStr);		//判断相等
	int getLength();							//用于获取长度
	//输出运算符重载
	friend ostream &operator<<(ostream &out, const MyString &str);
protected:
private:
	char *m_pStr;								//用于保存字符串的指针
	int m_iLen;									//用于保存字符串长度的数据成员
};

#endif // MYSTRING_H
