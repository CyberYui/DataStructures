//��ѭ�����е����ݽ��в���
//����һ������,����һ��Ԫ��,�����Ԫ��
#include <stdio.h>
#include <stdlib.h>
#include "SeqQueue.h"

void main()
{
	SeqQueue squeue = SetNullQueue_seq(5);//�����ն���
	int data;
	printf("��������ӵ�Ԫ��,��0����: ");
	scanf_s("%d", &data);
	//ѭ�����,ע�����ﲢû���жϸ���,���������ʱ��ֱ�ӱ���
	while (data)
	{
		//��data=0ʱ����ѭ��,�����һֱ����ѭ��
		EnQueue_seq(squeue, data);//����
		scanf_s("%d,", &data);
	}
	printf("����Ԫ�ص�˳����: ");
	while (!IsNullQueue_seq(squeue))
	{
		printf("%d", FrontQueue_seq(squeue));//�����ͷԪ��
		DeQueue_seq(squeue);//���һ���ͳ���һ��
	}
	printf("\n");
}