#include <stdio.h>
#include <stdlib.h>
#include "BinTreeQueue.h"
#include "LinkQueue.h"

//ʹ�ö��и������ݽṹ,���÷ǵݹ�ķ�������������
//ABC@DE@@@@F#

/****************************************************************/
/* BinTree CreateBinTree_NonRecursion()							*/
/* ����:�ǵݹ齨��������										*/
/* �������:��													*/
/* ����ֵ:�������ĸ�											*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_NonRecursion()
{
	LinkQueue queue = SetNullQueue_Link();
	BinTreeNode *s, *p, *bt;
	char ch = '0';
	int count = -1;
	printf("���ղ������������Ľ��,��#����:\n");
	ch = getchar();
	bt = NULL;//�ÿն�����
	//�������data�ǵ����ַ�,#Ϊ�����ַ�
	while (ch != '#')
	{
		//s���ڱ����½��
		s = NULL;
		//�������@�ͱ�ʾ������,����ռ�
		if (ch != '@')
		{
			s = (BinTreeNode *)malloc(sizeof(BinTreeNode));//�����½��
			//�½�㸳ֵ
			s->data = ch;
			s->leftchild = NULL;
			s->rightchild = NULL;
		}
		EnQueue_Link(queue, s);//���½���ַ�������ַ���
		count++;//������+1
		//��countΪ0,�������Ǹ��ڵ�,��btָ����
		if (count == 0)
		{
			bt = s;
		}
		//���ڵ�֮��,����������Ϊ0,��ʼ����������
		else
		{
			//��ͷ����ʾ���Ǹ����,ȡ�������ж�
			p = FrontQueue_Link(queue);
			//����½��Ͷ�ͷ��㶼��Ϊ��,��ʼ����
			//����½���ǿ�,��ch��@,�ǾͲ��ø�ֵ
			if (s != NULL && p != NULL)
			{
				//��ǰ����˫�׽�㶼������ڵ�ʱ,�ж���ż��
				//�������Һ���
				if (count % 2 == 1)
				{
					//countΪ����,�½����Ϊ���Ӳ���
					p->leftchild = s;
				} 
				else
				{
					//����countΪż��,�½����Ϊ�Һ��Ӳ���
					p->rightchild = s;
				}
			}
			//ÿ�����Һ��Ӳ������֮��,�����Ƿ��ܲ���,count��ӦΪһ��ż��
			if (count % 2 == 0)
			{
				//�ٴ��ж�,���countΪż��,˵���������Ӵ������,frontָ����һ��˫��
				DeQueue_Link(queue);//��ͷ������ϵĽ�����
			}
		}
		ch = getchar();//��ȡ��һ������ֵ
	}
	return bt;//��ch��#ʱ,���������,���ض������ĸ�
}

/****************************************************************/
/* void LevelOrder(BinTree bt)									*/
/* ����:ʹ�ö��в�α���������									*/
/* �������:�������ĸ�											*/
/* ����ֵ:��													*/
/* ��������:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void LevelOrder(BinTree bt)
{
	//���ڲ�α�����Ҳʹ�õ��˶���,����д������
	BinTree p;//������ʱ���,��֤bt��p��������ͬ
	LinkQueue queue = SetNullQueue_Link();//�����ն���
	//�������Ķ�����Ϊ��,ֱ�ӽ���
	if (bt==NULL)
	{
		return;
	}
	//����Ķ�������Ч,��ʼ����
	p = bt;
	//ͷ������
	EnQueue_Link(queue, bt);
	//�ж϶����Ƿ�Ϊ��,��Ϊ�������ѭ��
	while (!IsNullQueue_Link(queue))
	{
		//�Ӷ�ͷȡ����㸳ֵ��p
		p = FrontQueue_Link(queue);
		//��ͷ������
		DeQueue_Link(queue);
		//��ӡ���ӵĽ����ַ�
		printf("%c ", p->data);
		//�ж������ӽ��������Ƿ�Ϊ��
		if (p->leftchild!=NULL)
		{
			//���ӽ�㲻Ϊ��,���
			EnQueue_Link(queue, p->leftchild);
		}
		if (p->rightchild!=NULL)
		{
			//�Һ��ӽ�㲻Ϊ��,���
			EnQueue_Link(queue, p->rightchild);
		}
		//ѭ��,��Ҫ���������Ƿ��н��
	}//����Ϊ��,����ѭ��
	printf("\n");
}