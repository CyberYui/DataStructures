#include <stdio.h>
#include <stdlib.h>
#include "BinTreeThread.h"
#include "LinkStack.h"

//ABD@@EG@@@CF@@@#
void main()
{
	BinTreeNode *bt;
	printf("输入二叉树的先序序列建立二叉树: \n");
	bt = CreateBinTree();
	printf("建立中序穿线树...");
	Create_InOrderThread(bt);
	printf("\n中序线索化二叉树:\n");
	InOrder_ThreadBinTree(bt);
}