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
	printf("\n第二种删除方法,输入要删除的元素,成功返回1,不成功返回0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTDelete2(&bt, n));
	printf("二叉排序树的中序遍历序列:\n");
	InOrder(bt);
	
}