#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"

void main()
{
	PNode head1 = (PNode)malloc(sizeof(struct tagNode));//������1��ͷָ�����ռ�
	PNode head2 = (PNode)malloc(sizeof(struct tagNode));//������2��ͷָ�����ռ�
	CreateList(head1);
	CreateList(head2);
	printf("\n");
	printLinkedList(head1);
	printLinkedList(head2);
	printf("\n");
	Add_Poly(head1, head2);//����ʽ���
	printf("����ʽ��ӵĽ��Ϊ:\n");
	printLinkedList(head1);
	printf("\n");
}