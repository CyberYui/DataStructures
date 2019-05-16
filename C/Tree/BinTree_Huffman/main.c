#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"

void main()
{
	int *text;	//������������
	int num = 8;	//����������Ҷ�ӽ�����
	int i = 0;
	HuffTree pht;	//�����������
	printf("���ļ�����Ľ����Ϣ:\n");
	text = GetFrequency();
	printf("������������ǰ,�����������������̬:\n");
	printf("weight    leftchild    rightchild    parent\n");
	for (i = 0; i < num; i++)
	{
		printf("%2d           -1            -1          -1\n", text[i]);
	}
	printf("\n");
	pht = CreateHuffTree(num, text);	//������������
	//�����������
	printf("��������������,������������������̬:\n");
	printf("weight    leftchild    rightchild    parent\n");
	for (i = 0; i < num * 2 - 1; i++)
	{
		printf("%2d           %2d            %2d          %2d\n",
			pht->ht[i].weight,
			pht->ht[i].leftchild,
			pht->ht[i].rightchild,
			pht->ht[i].parent);
	}
}