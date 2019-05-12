#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

void main()
{
	BinTree bt = NULL;
	printf("请输入二叉树的先序序列:\n");
	//在建立时一定要保证输入的先序序列是正确的,否则函数无法返回
	bt = CreateBinTree_Recursion();//在本行设置断点[F9]进行调试[F5],更易于理解递归
	//逐语句执行的快捷键为[F11]

	printf("二叉树的链式存储结构建立完成!\n");
	printf("该二叉树的先序遍历序列为:\n");
	PreOrder_Recursion(bt);
	printf("\n");
	printf("该二叉树的中序遍历序列为:\n");
	InOrder_Recursion(bt);
	printf("\n");
	printf("该二叉树的后序遍历序列为:\n");
	PostOrder_Recursion(bt);
	printf("\n");
	DestroyBinTree(bt);
}