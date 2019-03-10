#include <iostream>
#include <stdlib.h>

#include "MyStackModel.h"
#include "CoordinateModel.h"

using namespace std;

/************************************************************************/
/* 栈--类模板
	   要求:将普通栈改造为类模板栈,使其可以适用于任何数据类型
	   目的:灵活掌握栈机制,理解抽象数据类型在栈中的应用
*/
/************************************************************************/

int main(void)
{
	//由于是一个类模板,所以要具体化一下,写成一个模版类
	MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);
	cout << endl;//分隔符

	pStack->push(Coordinate(1, 2));//底
	pStack->push(Coordinate(3, 4));
	pStack->push(Coordinate(5, 6));
	pStack->push(Coordinate(7, 8));
	pStack->push(Coordinate(9, 10));//顶
	cout << endl;//分隔符

	pStack->stackTraverse(true);
	cout << endl;//分隔符

	delete pStack;
	pStack = NULL;
	//测试其他类型的数据能否放置
	cout << endl;//分隔符
	MyStack<char> *qStack = new MyStack<char>(6);
	cout << endl;//分隔符

	qStack->push('A');
	qStack->push('B');
	qStack->push('C');
	qStack->push('D');
	qStack->push('E');
	qStack->push('F');
	cout << endl;//分隔符

	qStack->stackTraverse(false);
	cout << endl;//分隔符


	delete qStack;
	qStack = NULL;

	system("pause");
	return 0;
}