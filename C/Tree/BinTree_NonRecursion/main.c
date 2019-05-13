#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
#include "BinTreeQueue.h"

void main()
{
	//创建一个二叉树,对二叉树进行层次遍历
	BinTreeNode *t;
	printf("二叉树的非递归建立:\n");
	t = CreateBinTree_NonRecursion();
	printf("层次遍历序列为:");
	LevelOrder(t);
}