#include <iostream>
#include <stdlib.h>
#include "MyStackBasic.h"
using namespace std;

int main(void)
{
	//构造函数是MyStack(int size)
	MyStack *pStack = new MyStack(5);//从堆中申请对象
	//检测stackEmpty()函数是否可用
	if (pStack->stackEmpty())
	{
		cout << "栈为空!" << endl;
	}
	//检测stackFull()函数是否可用
	if (pStack->stackFull())
	{
		cout << "栈为满!" << endl;
	}

	//输出栈长度
	cout << pStack->stackLength() << endl;
	//推入元素,在第一个元素入栈时检查栈长度
	pStack->push('A');//底
	cout << pStack->stackLength() << endl;
	pStack->push('B');
	pStack->push('C');
	pStack->push('D');
	pStack->push('E');//顶
	//再次检验栈是否为满
	if (pStack->stackFull())
	{
		cout << "栈为满!" << endl;
	}
	//遍历栈元素
	pStack->stackTraverse();
	//清空栈
	pStack->clearStack();
	//再次输出栈长度
	cout << pStack->stackLength() << endl;
	//再次遍历
	pStack->stackTraverse();
	//重新推入元素
	pStack->push('F');
	pStack->push('G');
	pStack->push('H');
	pStack->push('I');
	pStack->push('J');
	//检验移除元素函数是否可用
	char elem = 0;
	pStack->pop(elem);
	cout << elem << endl;
	cout << pStack->stackLength() << endl;
	//遍历栈
	pStack->stackTraverse();
	//清空栈
	pStack->clearStack();
	//移除指针,释放内存空间
	delete pStack;
	pStack = NULL;

	system("pause");
	return 0;
}