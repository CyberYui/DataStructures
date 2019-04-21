#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Node
{
	DataType data;
	struct Node * next;
};
typedef struct Node Node;

//��������:��������������Josephus����Ľ��
//�������:n-->������,s-->��ʼλ��,k-->���
//����ֵ:��
void Josephus(int n, int s, int k)
{
	Node *current = (Node *)malloc(sizeof(Node));
	Node *prev = (Node *)malloc(sizeof(Node));
	Node *head = (Node *)malloc(sizeof(Node));
	prev = head;
	//β�巨����ѭ������
	for (int i = 1; i <= n; i++)
	{
		current = (Node *)malloc(sizeof(Node));
		current->data = i;
		prev->next = current;
		prev = current;
	}
	//���һ������nextָ��ͷ,����ѭ������
	prev->next = head->next;

	current = head->next;
	for (int i = 1; i < s; i++)
	{
		//currentָ���ƶ�s-1��,ָ���s�����
		prev = prev->next;
		current = current->next;
	}
	//ѭ��������ʾ,��ɾ�����
	while (current->next != current)
	{
		for (int i = 1; i < k; i++)
		{
			prev = prev->next;
			current = current->next;//currentָ���ƶ�k-1��,ָ��Ҫɾ���Ľ��
		}
		prev->next = current->next;
		printf("��ǰ���е������%d\n", current->data);
		free(current);//ɾ���ѳ��еĽ��
		current = prev->next;
	}
	//��current->next = currentʱ,��ʣ���һ��Ԫ��
	printf("���һ�����е������%d\n", current->data);
}

void main()
{
	int n, k, s, answer;//nΪ������,sΪ��ʼλ��,kΪ���
	//��s���˴�1��ʼ����,����k���˳���,��һ�����ٴ�1��ʼ����
	printf("������������n,��ʼλ��s,���k\n");
	scanf_s("%d,%d,%d", &n, &s, &k);
	Josephus(n, s, k);
}

//����㷨�кܶ���Ҫ�Ľ��ĵط�,������Щ���û�б�ɾ��(�������һ�����)