#ifndef NODEADV_H
#define NODEADV_H

#include "PersonAdv.h"

class Node
{
public:
	void printNode();
	//Node������������һ��int���ͱ�����
	//Ӧ����һ��Person����
	Person data;
	Node *next;//ָ����,ָ����һ�����
};

#endif // NODEADV_H
