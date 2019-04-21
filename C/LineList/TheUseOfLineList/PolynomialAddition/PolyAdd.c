#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"

//�������뵽������ʵ�λ��,����һ���������е�����
void InsertList(PNode head, PNode pnode)
{
	PNode pPre = head;
	while (pPre -> next != NULL)
	{
		if (pPre->next->exp > pnode->exp)
		{
			pnode->next = pPre->next;//pnode�ŵ�ָ����Ľ��֮ǰ
			pPre->next = pnode;//���ڵĵ�һ���ǿս�㼴Ϊpnode
			break;
		}
		//������һ�����Ĳ���,ֱ��������ֹ����
		pPre = pPre->next;
	}
	//���������ָ�����,ֱ�Ӳ����㵽���
	if (pPre->next == NULL)
	{
		pPre->next = pnode;
	}
}

void CreateList(PNode head)
{
	int exp;//ָ��
	float coef;//ϵ��
	PNode pTemp = NULL;
	head->next = NULL;//����ÿռ�,ָ����ֵΪ��
	//�������ʽ
	printf("������Ҫ��������1�е�����,˳��Ϊϵ��,ָ��,������ʽ����,����0,0��β:\n");
	//��������,��0,0��β,�����ݲ���������
	scanf_s("%f,%d", &coef, &exp);
	while (coef != 0 || exp != 0)
	{
		pTemp = (PNode)malloc(sizeof(struct tagNode));
		pTemp->coef = coef;
		pTemp->exp = exp;
		pTemp->next = NULL;
		InsertList(head, pTemp);
		scanf_s("%f,%d", &coef, &exp);
	}
}

void printLinkedList(PNode head)
{
	//����ĵ�һ����㿪ʼ
	PNode temp = head->next;
	while (temp != NULL)
	{
		//���ϵ����ָ��
		printf("%0.0f ", temp->coef);
		printf("%d,", temp->exp);
		//������һ�����
		temp = temp->next;
	}
	//�������һ�����ʱ,����
	printf("\n");
}

//��������ʽ���
void Add_Poly(PNode pa, PNode pb)
{
	PNode p = pa->next;//����1,�Ͷ���ʽ�����������ɲ���
	PNode q = pb->next;//����2
	PNode pre = pa;//ǰ�����
	PNode u;//��ʱ����
	float x;
	//������������Ϊ��,��������
	while (p != NULL && q != NULL)
	{
		if (p->exp < q->exp)
		{
			//�Ƚ�����1������2��ǰ�ڵ��ָ����С,��Ž��������1
			pre = p;
			p = p->next;//pָ��Ҫ�Ƚϵ���һ���ڵ�,preָ����ǽ����������һ�����
		}
		else if (p->exp == q->exp)
		{
			//��������1������2��ָ�����,��ϵ�����
			x = p->coef + q->coef;
			if (x != 0)
			{
				//��Ӻ��ϵ����Ϊ0,�б�Ҫ����һ�����
				p->coef = x;//�ı�ϵ��
				pre = p;//����Ͷ���ʽ��
			}
			else
			{
				//��Ӻ���Ϊ0,����Ҫ�����κ�һ�����,����ɾ������1���,֮��ɾ������2�Ľ��
				pre->next = p->next;
				free(p);
			}
			p = pre->next;//pָ��Ҫ�Ƚϵ���һ�����
			//ɾ������2�Ľ��,��Ϊָ����ͬ��ֻ��Ҫ����һ������
			//����1�е���ɲ��ֱ�����,����ɾ������2�Ľ��
			u = q;
			q = q->next;
			free(u);
		}
		else
		{
			//�������2�ĵ�ǰ���ָ��С,��ôҪ������2�ĵ�ǰ�����뵽���������(������1)
			//������ӽ��x��0���ǲ���0,��Ҫɾ��q���
			//�൱�ڰѽ����뵽����1��,��u��Ϊ��ʱ����,��������2����һ����ǰ���λ��
			u = q->next;

			q->next = p;
			pre->next = q;//pre-q-p
			//��ʱ��q���뵽��pre��p֮��
			pre = q;//pre��Ųһ��λ��
			//������ɺ󷵻ؼ������Ƚ�
			q = u;//q����Ųһ��λ��
		}
		//Ȼ���������ѭ��,ֱ����һ��p/qָ��ͷΪֹ
	}
	if (q)
	{
		//�������2������1��,������2��ʣ�ಿ��ֱ�Ӳ��뵽�Ͷ���ʽ��
		//����1������2��,��ʲô��������
		pre->next = q;
	}
	free(pb);
}