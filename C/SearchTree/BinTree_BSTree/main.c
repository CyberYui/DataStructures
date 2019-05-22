#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

//40 10 5 -1 -1 -1 55 45 -1 48 47 -1 -1 52 -1 -1 60 -1 70 -1 -1
void main()
{
	BinSearchTree bt;
	int n = 0;
	printf("�����������������������:\n");
	bt = create();
	printf("����Ҫ���ҵ�Ԫ��,���ڷ���1,�����ڷ���0,����:");
	scanf_s("%d", &n);
	printf("%d\n", BSTSearch(bt, n)->data);
	printf("����Ҫ�����Ԫ��,�ɹ����뷵��1,���򷵻�0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTInsert(bt, n));
	printf("�����������������������:\n");
	InOrder(bt);
	printf("\n��һ��ɾ������,����Ҫɾ����Ԫ��,�ɹ�����1,���ɹ�����0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTDelete1(&bt, n));
	printf("�����������������������:\n");
	InOrder(bt);
	printf("\n");

	printf("\n�ڶ���ɾ������,����Ҫɾ����Ԫ��,�ɹ�����1,���ɹ�����0:");
	scanf_s("%d", &n);
	printf("%d\n", BSTDelete2(&bt, n));
	printf("�����������������������:\n");
	InOrder(bt);
	printf("\n");

	BSTgetMax(bt);
	BSTgetMin(bt);
	printf("�����������������������:\n");
	InOrder(bt);
	printf("\n");
	BST_Destory(bt);
	printf("�����������������������:\n");
	InOrder(bt);
	printf("\n");
}

/*	
�������˾���warning C4047: ��=��:��BinSearchTree���롰BSTreeNode *���ļ�Ӽ���ͬʱ
A:��������ⲻ�󣬾���ͬһ�����������������ѡ�

�����쳣�Ľ����ʽ:
�������쳣: ��ȡ����Ȩ�޳�ͻ��
ptree �� 0xCDCDCDCD��

A:��������Ҫ������ڣ���ÿ����malloc�ڴ����ʱ��
û�и��ý��������ӽ��ָ�븳�գ�����Ұָ��ķ����쳣��

��VC��debug�»��δ��ʼ���Ķ��ڴ��ϵ�ָ��ȫ����� 0xCDCDCDCD��
���Կ��� 0xCDCDCDCD��ʱ����͸�֪������δ��ʼ���ķ���ռ��ˡ���

�����������ÿ����malloc����ڴ�ĵط����������ӽ��ָ�븳NULL����
*/