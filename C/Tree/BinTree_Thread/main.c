#include <stdio.h>
#include <stdlib.h>
#include "BinTreeThread.h"
#include "LinkStack.h"

//ABD@@EG@@@CF@@@#
void main()
{
	BinTreeNode *bt;
	printf("������������������н���������: \n");
	bt = CreateBinTree();
	printf("������������...");
	Create_InOrderThread(bt);
	printf("\n����������������:\n");
	InOrder_ThreadBinTree(bt);
}