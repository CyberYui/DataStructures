#include <iostream>
#include <stdlib.h>
#include "MyStackAdv.h"
using namespace std;

int main(void)
{
	//构造函数是MyStack(int size)
	MyStack *pStack = new MyStack(5);//从堆中申请对象

	//推入类型对象到栈中
	pStack->push(Coordinate(1, 2));//底
	pStack->push(Coordinate(3, 4));
	pStack->push(Coordinate(5, 6));
	pStack->push(Coordinate(7, 8));
	pStack->push(Coordinate(9, 10));//顶

	pStack->stackTraverse(true);
	cout << endl;
	pStack->stackTraverse(false);

	pStack->stackLength();


	//移除指针,释放内存空间
	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}