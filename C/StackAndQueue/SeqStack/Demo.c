#include <stdlib.h>
#include <stdio.h>
#include "SeqStack.h"

//��˳��ջ�����л����㷨���в���
//��Ҫ������һ������,ͨ��ջʵ�����з�ת

void main()
{
	SeqStack p = SetNullStack_seq(5);	//����һ����ջp
	int data = 0;
	printf("�������ջ��Ԫ��,��0����:");
	scanf_s("%d", &data);
	//��0������ԭ�����ж�ʱ0��Ϊ��,������ѭ��
	while (data)
	{
		Push_seq(p, data);	//�������ݽ�ջ
		scanf_s("%d", &data);
	}
	printf("��ջԪ�ص�˳����:");
	//��ӡ˳��ջ
	while (!IsNullStack_seq(p))
	{
		printf("%d ", Top_seq(p));	//ȡջ��Ԫ��
		Pop_seq(p);	//��ջ
	}
	//��ȡ�ٳ���ԭ����,�������ջ����ջ,���޷���ȡ�����������,ֻ��ջ����ջ,�Ż����µ�ջ��
	printf("\n");
}