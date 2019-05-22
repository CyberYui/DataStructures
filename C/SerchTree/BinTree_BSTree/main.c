#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

//40 10 5 -1 -1 -1 55 45 -1 48 47 -1 -1 52 -1 -1 60 -1 70 -1 -1
void main()
{
	BinSearchTree bt;
	int n = 0;
	printf("输入二叉排序树的先序序列:\n");
	bt = create();
	printf("输入要查找的元素,存在返回1,不存在返回0,插入:");
	scanf_s("%d", &n);
	printf("%d\n", BSTSearch(bt, n)->data);
	printf("输入要插入的元素,成功插入返回1,否则返回0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTInsert(bt, n));
	printf("二叉排序树的中序遍历序列:\n");
	InOrder(bt);
	printf("\n第一种删除方法,输入要删除的元素,成功返回1,不成功返回0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTDelete1(&bt, n));
	printf("二叉排序树的中序遍历序列:\n");
	InOrder(bt);
	printf("\n");

	printf("\n第二种删除方法,输入要删除的元素,成功返回1,不成功返回0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTDelete2(&bt, n));
	printf("二叉排序树的中序遍历序列:\n");
	InOrder(bt);
	printf("\n");

	BSTgetMax(bt);
	BSTgetMin(bt);
	printf("二叉排序树的中序遍历序列:\n");
	InOrder(bt);
	printf("\n");
	BST_Destory(bt);
	printf("二叉排序树的中序遍历序列:\n");
	InOrder(bt);
	printf("\n");
}

/*	
在遇到了警告warning C4047: “=”:“BinSearchTree”与“BSTreeNode *”的间接级别不同时
A:警告的问题不大，就是同一个类型两个别名而已。

引发异常的解决方式:
引发了异常: 读取访问权限冲突。
ptree 是 0xCDCDCDCD。

A:你代码的主要问题就在，你每次在malloc内存结点的时候，
没有给该结点的左右子结点指针赋空，导致野指针的访问异常。

（VC的debug下会把未初始化的堆内存上的指针全部填成 0xCDCDCDCD，
所以看到 0xCDCDCDCD的时候你就该知道存在未初始化的分配空间了。）

解决方法，在每次你malloc结点内存的地方，给左右子结点指针赋NULL即可
*/