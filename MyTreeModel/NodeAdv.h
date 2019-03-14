#ifndef NODEADV_H
#define NODEADV_H

class Node
{
public:
	Node();//构造函数,用于初始化

	//为了寻找结点,定义一个用于递归的函数,也是寻找Node函数
	Node *SearchNode(int nodeIndex);

	//由于调用着SearchNode,所以不需要在删除的时候做烦琐判断了
	//因为能到删除这一步的,一定是被找到了的结点
	//与Tree中bool DeleteNode(int nodeIndex, Node *pNode)不同
	//由于没有判断,所以不需要再有返回值了
	//并且索引之类的操作是在Tree的同名函数中进行的
	void DeleteNode();

	//前序遍历的功能实现
	void PreorderTraversal();

	//中序遍历的功能实现
	void InorderTraversal();

	//后序遍历的功能实现
	void PostorderTraversal();

	int index;//定义索引
	int data;//定义数据域
	Node *pLChild;//左孩子指针
	Node *pRChild;//右孩子指针
	Node *pParent;//父亲结点指针
};

#endif // NODEADV_H
