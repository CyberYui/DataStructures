#include <stdlib.h>
#include <stdio.h>
#include "LinkedStack.h"

//����ջ�����л����㷨���в���
//Ҫ������һ������,ͨ����ջʵ�����з�ת
void main()
{
	LinkedStack p = SetNullStack_Link();//����һ������ջ
	int data = 0;
	printf("�������ջ��Ԫ��,��0����:");
	scanf_s("%d", &data);
	while (data)
	{
		Push_link(p, data);	//��ջ
		scanf_s("%d", &data);
	}
	printf("��ջԪ�ص�˳����:");
	while (!IsNullStack_link(p))
	{
		printf("%d ", Pop_seq_return(p));
		Pop_link(p);
	}
	printf("\n");
}