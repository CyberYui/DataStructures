#include <stdio.h>
#include <stdlib.h>
#include "BinTreeStack.h"
#include "LinkStack.h"

//ABC@@D@@E@FG@@@
void main()
{
	BinTreeNode *bt;
	printf("�������������������:");
	bt = CreateBinTree_Recursion();
	printf("�ö������������������Ϊ:");
	//PreOrder_NRecursion1(bt);	//����1
	PreOrder_NRecursion2(bt);	//����2
	printf("\n");
	printf("�ö������������������Ϊ:");
	InOrder_NRecursion(bt);
	printf("\n");
	printf("�ö������ĺ����������Ϊ:");
	PostOrder_NRecursion(bt);
	printf("\n");
}