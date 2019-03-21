/************************************************************************/
/*  二叉树:链表实现
/*
/*	Tree();							//创建树
/*	~Tree();							//销毁树
/*	Node *SearchNode(int nodeIndex);				//搜索结点
/*	bool AddNode(int nodeIndex, int direction, Node *pNode);//添加结点
/*	bool DeleteNode(int nodeIndex, Node *pNode);			//删除结点
/*	void PreorderTraversal();					//前序遍历
/*	void InorderTraversal();					//中序遍历
/*	void PostorderTraversal();					//后序遍历
/*
/*	结点要素:索引  数据(int类型)  左孩子指针(叶子节点没有)右孩子指针
/*	              父节点指针(最顶层节点没有)
/*					//添加结点要知道挂载的结点的索引
/*	             (0)			//并将其挂载的左右搞清楚
/*					//三个遍历的区别
/*	    5(1)	     8(2)			//前:根左右
/*					//中:左根右
/*	2(3)   6(4)   9(5)   7(6)			//后:左右根
/*
/*	//以这棵树为例,创建头结点,其数据域可以没有意义,但是一定要指定其左右指针域
/*	//如果要给已经挂载在左右的结点再挂载左右结点,则需要先从根结点索引,
/*	//找到要挂载的结点,然后在其左右两边进行挂载,由此,搜索操作就显得很重要了
/*
/*	//删除结点时,不仅要删除这一个结点,还要删除其连接的各个子节点等内容
/*
/*	//销毁一棵树的时候,也需要一级一级的销毁叶子节点,否则也会造成内存泄漏
/*
/*	//比如上面这棵树,对于前序遍历,应该是根左右
/*	//先找根(0),找其左5(1),而5(1)本身也是个根,则再找其左,找到2(3),再找右
/*	//6(4),以此类推,即(0)->5(1)->2(3)->6(4)->8(2)->9(5)->7(6)
/*
/*	//同理,中序遍历是左根右
/*	//拿到(0)开始,从左开始,即5(1),而5(1)本身是个根,所以再找其左,即2(3)
/*	//以此类推,即2(3)->5(1)->6(4)->(0)->9(5)->8(2)->7(6)
/*
/*	//后序遍历即左右根
/*	//拿到(0)开始,找其左,即5(1),而5(1)本身是个根,故找其左,即2(3),再找其右
/*	//即6(4),以此类推,即2(3)->6(4)->5(1)->9(5)->7(6)->8(2)->(0)
/*
/*	//无论做什么,都需要找到一个结点的唯一索引,这是关键
/************************************************************************/
#include <iostream>
#include <stdlib.h>
#include "TreeAdv.h"
using namespace std;

//				(0)						
//										
//		5(1)			8(2)			
//										
//	2(3)	6(4)	9(5)	7(6)	

int main(void)
{
	//检测函数是否成功
	//创建树
	Tree *tree = new Tree();
	//创建结点
	Node *node1 = new Node();
	node1->index = 1;
	node1->data = 5;

	Node *node2 = new Node();
	node2->index = 2;
	node2->data = 8;

	Node *node3 = new Node();
	node3->index = 3;
	node3->data = 2;

	Node *node4 = new Node();
	node4->index = 4;
	node4->data = 6;

	Node *node5 = new Node();
	node5->index = 5;
	node5->data = 9;

	Node *node6 = new Node();
	node6->index = 6;
	node6->data = 7;
	//结点创建完成
	//插入结点
	tree->AddNode(0, 0, node1);//要在0的左边添加node1
	tree->AddNode(0, 1, node2);//在0的右边添加node2

	tree->AddNode(1, 0, node3);//在1的左边添加node3
	tree->AddNode(1, 1, node4);//在1的右边添加node4

	tree->AddNode(2, 0, node5);//在2的左边添加node5
	tree->AddNode(2, 1, node6);//在2的右边添加node6
	//自此形成了上述的二叉树
	//前序遍历,应为(0)->5(1)->2(3)->6(4)->8(2)->9(5)->7(6)->
	tree->PreorderTraversal();
	cout << endl;
	//中序遍历,应为2(3)->5(1)->6(4)->(0)->9(5)->8(2)->7(6)->
	tree->InorderTraversal();
	cout << endl;
	//后序遍历,应为2(3)->6(4)->5(1)->9(5)->7(6)->8(2)->(0)->
	tree->PostorderTraversal();
	cout << endl;
	//成功运行
	//尝试删除结点
	tree->DeleteNode(6, NULL);//不保留值
	tree->PreorderTraversal();
	cout << endl;
	//可见已删除
	tree->DeleteNode(2, NULL);//不保留值
	tree->PreorderTraversal();
	cout << endl;


	delete tree;
	tree = NULL;

	system("pause");
	return 0;
}