#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MyListAdv.h"
using namespace std;

int main(void)
{
	//3 5 7 2 9 1 8
	Coordinate e1(3, 5);
	Coordinate e2(5, 7);
	Coordinate e3(4, 6);
	Coordinate e4(1, 2);
	Coordinate e5(2, 3);
	Coordinate e6(7, 9);
	Coordinate e7(9, 8);
	//检测函数
	List *list1 = new List(10);
	//查看元素个数
	cout << "length:" << list1->ListLength() << endl;

	list1->ListInsert(0, &e1);
	list1->ListInsert(1, &e2);
	list1->ListInsert(2, &e3);
	list1->ListInsert(3, &e4);
	list1->ListInsert(4, &e5);
	list1->ListInsert(5, &e6);
	list1->ListInsert(6, &e7);
	//查看元素个数
	cout << "length:" << list1->ListLength() << endl;
	//遍历线性表(顺序表)
	list1->ListTraverse();


	delete list1;
	list1 = NULL;

	system("pause");
	return 0;
}