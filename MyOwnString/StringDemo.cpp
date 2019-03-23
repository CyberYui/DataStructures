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
	MyString str2 = "CDEF";
	
	//MyString temp = 
	//cout << str1 + str2 << endl;
	//cout << temp;
	/*int temp=0;
	temp = str1.violentMatch(str1, str2);
	if (temp == -1)
	{
		cout << "不匹配内容!" << endl;
	}
	else
	{
		cout << "匹配成功!位置从第" << temp << "开始" << endl;
	}*/

	//根据模式串的长度设定next数组
	int next[5];//防止报错,数组空间+1
	str1.getNext(str2, next);
	cout << "模式串在主串的第" << str1.KMP(str1, str2, next) << "位开始" << endl;


	system("pause");
	return 0;
}