#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

void main()
{
	BinTree bt = NULL;
	printf("���������������������:\n");
	//�ڽ���ʱһ��Ҫ��֤�����������������ȷ��,�������޷�����
	bt = CreateBinTree_Recursion();//�ڱ������öϵ�[F9]���е���[F5],���������ݹ�
	//�����ִ�еĿ�ݼ�Ϊ[F11]

	printf("����������ʽ�洢�ṹ�������!\n");
	printf("�ö������������������Ϊ:\n");
	PreOrder_Recursion(bt);
	printf("\n");
	printf("�ö������������������Ϊ:\n");
	InOrder_Recursion(bt);
	printf("\n");
	printf("�ö������ĺ����������Ϊ:\n");
	PostOrder_Recursion(bt);
	printf("\n");
	DestroyBinTree(bt);
}