#include "MyString.h"
#include <string.h>

/****************************************************************/
/*  ��Ŀ����:MyOwnString
/*  ��Ŀ����:���ڴ���C++ʵ��
/*  ������:MyString
/*  ����ʱ��:2019-3-21	
/*  Author:Cyber Kaka
/****************************************************************/


/****************************************************************/
/* MyString(const char *str)									*/
/* ����:��ʼ��һ���ַ���										*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString::MyString(const char *str)
{
	//�����жϳ�ʼ����str�Ƿ�Ϊ��
	if (str == NULL)
	{
		m_pStr = new char[1];//Ϊ�����Զ������Ž�����־
		*m_pStr = '\0';
	}
	else
	{
		//str���ݲ�Ϊ��,�����䳤��
		m_iLen = strlen(str);
		//�Ӷ�������char����
		m_pStr = new char[m_iLen + 1];
		//�鿴�Ƿ�����ɹ�
		if (NULL == m_pStr)
		{
			//ʧ����ֱ�ӷ���
			return;
		}
		//����ɹ�,��str�����ݸ��Ƹ�m_pStr
		strcpy_s(m_pStr, m_iLen+1 , str);
	}
}


/****************************************************************/
/* ~MyString()													*/
/* ����:����һ����												*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString::~MyString()
{
	//ֱ��ɾ��ָ�뼴��
	delete[]m_pStr;
	m_pStr = NULL;
}


/****************************************************************/
/* MyString(const MyString &str)								*/
/* ����:�������캯��,��һ����֪�����ʼ��MyString����			*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString::MyString(const MyString &str)
{
	//����str,��������const,���޸�������
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
/* ����:��ֵ���������											*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
MyString & MyString::operator=(const MyString &str)
{
	//������Ĵ���ԭ����ͬ,ֱ�����ԭ������
	if (this == &str)
	{
		return *this;
	}
	//������ͬ,ԭ����Ϊ��,�����ԭ��
	if (m_pStr)
	{
		//����еȲ�ͬ,�����г����޶���
		//�����趨�����ȶ�̬����,�������ռ����������ռ��
		delete[]m_pStr;
		m_pStr = NULL;
	}
	//������Ĵ����ݴ���ԭ����
	m_iLen = strlen(str.m_pStr);
	m_pStr = new char[m_iLen + 1];
	strcpy_s(m_pStr, m_iLen+1 , str.m_pStr);
	//���޸ĺõ�ԭ������
	return *this;
}


/****************************************************************/
/* MyString operator+(const MyString &str)						*/
/* ����:�Ӻ����������,�������str��ӵ�ԭ��֮��				*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
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
/* ����:�ж��������Ƿ����										*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
bool MyString::operator==(const MyString &aStr)
{
	for (int i=0;i!=m_iLen;++i)
	{
		if (*(m_pStr + i) != *(aStr.m_pStr + i))
		{
			//ָ�벻��ָ����һ������ƥ��,ֻҪ���ַ��������������
			return false;
		}
	}
	return true;
}


/****************************************************************/
/* getLength()													*/
/* ����:���ص�ǰ���ĳ���										*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
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
/* friend ostream &operator<<(ostream &out, const MyString &str)*/
/* ����:������������,����ʹ��Ҳ����ʹ��<<						*/
/* 																*/
/* ��������:2019-3-21						Author:Cyber Kaka	*/
/****************************************************************/
ostream &operator<<(ostream &out, const MyString &str)
{
	out << str.m_pStr;
	return out;
}

/*
���ܻ�������ʱ���������ľ���
This function or variable may be unsafe. 
Consider using strcpy_s instead. 
To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
See online help for details.

����΢��ľ��棬��Ҫ��Ϊ��ЩC��ĺ������ܶຯ���ڲ��ǲ����в������ģ�����Խ����ģ���
΢����ʹ����Щ������ڴ��쳣�����Ծ͸�д��ͬ�����ܵĺ�����
��д�˵ĺ��������˲����ļ�⣬ʹ����Щ�µĺ��������ȫ�ͱ�ݡ�
������Щ��д�ĺ����㲻��ר��ȥ���䣬��Ϊ����������ÿ�������ڸ�������ʱ��
�����������Ӧ�İ�ȫ�������鿴������Ϣ�Ϳ��Ի�֪����ʹ��ʱҲ�ٲ鿴һ��MSDN��ϸ�˽⡣
*/
