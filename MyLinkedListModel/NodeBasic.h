#ifndef NODEBASIC_H
#define NODEBASIC_H

//如果用struct定义类,则不需要再写public,因为默认的就是public
class Node
{
	//重载输出运算符
	/*friend ostream &operator<<(ostream &out, Node &node);*/
public:
	//写一个函数用于输出内容
	void printNode();
	//将数据域和指针域写在public的原因是这样便于修改内容
	//而不需要像private那样需要写专门的函数用于访问操作
	int data;//数据域
	Node *next;//指针域,指向下一个结点
};

#endif // NODEBASIC_H
