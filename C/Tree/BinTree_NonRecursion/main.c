#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"
#include "BinTreeQueue.h"

void main()
{
	//����һ��������,�Զ��������в�α���
	BinTreeNode *t;
	printf("�������ķǵݹ齨��:\n");
	t = CreateBinTree_NonRecursion();
	printf("��α�������Ϊ:");
	LevelOrder(t);
}