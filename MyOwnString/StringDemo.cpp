#include <iostream>
#include <stdlib.h>
#include "MyString.h"
using namespace std;

int main(void)
{
	cout << sizeof(char) << endl;
	MyString str1 = "ABCDEFG";
	//int n = str1.getLength();
	//cout << n << endl;
	MyString str2 = "CDE";
	
	//MyString temp = 
	//cout << str1 + str2 << endl;
	//cout << temp;
	int temp=0;
	temp = str1.violentMatch(str1, str2);
	if (temp == -1)
	{
		cout << "��ƥ������!" << endl;
	}
	else
	{
		cout << "ƥ��ɹ�!λ�ôӵ�" << temp << "��ʼ" << endl;
	}
	system("pause");
	return 0;
}