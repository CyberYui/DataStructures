#include <iostream>
#include "NodeAdv.h"
#include "PersonAdv.h"
using namespace std;

void Node::printNode()
{
	//要使用<<直接完成对person的信息输出,需要包含其头文件
	//并在其头文件中对输出运算符进行重载
	cout << data << endl;
}