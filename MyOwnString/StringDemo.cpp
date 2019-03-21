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
	MyString str2 = "HIJKLMN";
	
	//MyString temp = 
	cout << str1 + str2 << endl;
	//cout << temp;

	system("pause");
	return 0;
}