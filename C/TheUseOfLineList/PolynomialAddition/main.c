#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"

void main()
{
	PNode head1 = (PNode)malloc(sizeof(struct tagNode));//给链表1的头指针分配空间
	PNode head2 = (PNode)malloc(sizeof(struct tagNode));//给链表2的头指针分配空间
	CreateList(head1);
	CreateList(head2);
	printf("\n");
	printLinkedList(head1);
	printLinkedList(head2);
	printf("\n");
	Add_Poly(head1, head2);//多项式相加
	printf("多项式相加的结果为:\n");
	printLinkedList(head1);
	printf("\n");
}