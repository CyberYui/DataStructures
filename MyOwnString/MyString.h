#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class MyString
{
	//constָ���˺��������޸ĸ�����κγ�Ա���ݵ�ֵ����Ϊ������Ա����
public:
	MyString(const char *str = NULL);			//���캯��
	MyString(const MyString &str);				//�������캯��
	~MyString();								//��������
	MyString & operator=(const MyString &str);	//=�ŵ����������
	MyString & operator+(const MyString &str);	//+�ŵ����������
	bool operator==(const MyString &aStr);		//�ж����
	int getLength();							//���ڻ�ȡ����
	//������������
	friend ostream &operator<<(ostream &out, const MyString &str);
protected:
private:
	char *m_pStr;								//���ڱ����ַ�����ָ��
	int m_iLen;									//���ڱ����ַ������ȵ����ݳ�Ա
};

#endif // MYSTRING_H
