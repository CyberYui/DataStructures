#ifndef NODEADV_H
#define NODEADV_H

#include "PersonAdv.h"

class Node
{
public:
	void printNode();
	//Node的数据域不再是一个int类型变量了
	//应该是一个Person类型
	Person data;
	Node *next;//指针域,指向下一个结点
};

#endif // NODEADV_H
