#include <stdio.h>
#include <stdlib.h>
//�����������Ҫ��random,������time.h
#include <time.h>
#include "SkipList.h"

/****************************************************************/
/* PNode CreateNode(int level, KeyType key)						*/
/* ����:�������												*/
/* �������level:������ڲ���									*/
/* �������key:����ֵ											*/
/* ����ֵp:���													*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode CreateNode(int level, KeyType key)
{
	PNode p = (PNode)malloc(sizeof(struct node) + sizeof(PNode) * level);
	if (p == NULL)
	{
		return NULL;
	}
	p->level = level;
	p->key = key;
	return p;
}

/****************************************************************/
/* SkipList SetNullSkipList(int level)							*/
/* ����:��������ͷ���Ŀ���Ծ����								*/
/* �������level:����											*/
/* ����ֵlist:��Ծ����											*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
SkipList SetNullSkipList(int level)
{
	SkipList list = (SkipList)malloc(sizeof(SkipList));
	//�����ڴ�ʧ���򷵻�NULL
	if (list == NULL)
	{
		return NULL;
	}
	list->num = 0;  //����Ծ�����������ֵ0
	list->maxLevel = level; //��Ծ����Ĳ���
	list->head = CreateNode(level, -1);  //ͷ����������ֵΪ-1
	//���ͷ��㴴��ʧ��,���ͷ�����ռ�,����NULL
	if (list->head == NULL)
	{
		free(list);
		return NULL;
	}
	//��ͷ����ÿһ��������Ϊ��
	for (int i = 0; i < level; i++)
	{
		list->head->next[i] = NULL;
	}
	return list;
}

/****************************************************************/
/* int RandomLevel(int maxlevel)								*/
/* ����:�����������(α),�ڸ������Ե������������		    	*/
/* �������maxLevel:�����������								*/
/* ����ֵi:����													*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int RandomLevel(int maxlevel)
{
	int i = 1;
	//���ɵĲ���i>=1 && i<=maxlevel
	while (rand() % 2)    //����ż��
		i++;
	i = (i > maxlevel) ? maxlevel : i;
	return i;   //i���ǲ����Ĳ���
}

/****************************************************************/
/* int SkipListInsert(SkipList list, KeyType key)				*/
/* ����:������												*/
/* �������list:Ҫ�������Ծ����								*/
/* �������key:���ֵ											*/
/* ����ֵ:1--�ɹ�����	0--����ʧ��								*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListInsert(SkipList list, KeyType key)
{
	int level = 0;
	PNode Pre[MAX_LEVEL];   //��¼ÿ���ǰ�����λ��
	PNode p = NULL;
	PNode q = NULL;
	p = list->head; //��ͷ��㿪ʼ

	//����λ��,��¼ǰ�������Ϣ
	for (int i = list->maxLevel - 1; i >= 0; i--)    //������Ʋ�
	{
		//������Ҳ���λ��,��forѭ��ʱ�����ƶ�����λ��
		while ((q = p->next[i]) && (q->key < key))
			//ע��������,����������
			p = q;
		Pre[i] = p;
	}

	//�Ѿ�������ͬ��key,���ܲ���
	if ((q != NULL) && (q->key == key))
		return 0;   //���ҳɹ�,������

	//ʹ��RandomLevelͶ��
	level = RandomLevel(list->maxLevel);    //����һ���������
	p = CreateNode(level, key);  //�����½��
	if (p == NULL)
	{
		return 0;   //�����½�㲻�ɹ�
	}

	//��������޸�ָ��
	for (int i = 0; i < level; i++)
	{
		p->next[i] = Pre[i]->next[i];
		Pre[i]->next[i] = p;
	}

	//�½����ӳɹ�
	list->num++;    //��Ծ����ļ�����+1
	return 1;   //����ɹ�
}

/****************************************************************/
/* PNode SkipListSearch(SkipList list, KeyType key)				*/
/* ����:��ֵ���ҽ��											*/
/* �������list:��Ծ����										*/
/* �������key:���ҵĽ���ֵ									*/
/* ����ֵ:p--���ҳɹ��Ľ���λ��		NULL--����ʧ��			*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode SkipListSearch(SkipList list, KeyType key)
{
	int n = 0;
	PNode p = NULL;
	PNode q = NULL;
	p = list->head;

	//�Ӹ߲㿪ʼ,�������Ƚ�
	for (int i = list->maxLevel - 1; i >= 0; i--)
	{
		//����Ƚ�
		//q=p->next[i]�Ǽ���Ƿ񵽴�����β��
		//q->key<=key�Ǽ���Ƿ��ҵ��˱Ȳ�ѯ��key���Ԫ��
		while ((q = p->next[i]) && (q->key <= key))
		{
			p = q;
			n++;    //��¼�Ƚϴ���
			if (p->key == key)
			{
				printf("�ڵ�%d����ҵ���%d\n", i, key);
				printf("���Ƚ���%d��\n", n);
				return p;   //���ҳɹ�,����p
			}
		}
	}
	return NULL;    //����ʧ��,����NULL
}

/****************************************************************/
/* int SkipListDelete(SkipList list, KeyType key)				*/
/* ����:��ֵɾ�����											*/
/* �������list:��Ծ����										*/
/* �������key:Ҫɾ���Ľ���ֵ(Ĭ�����������ظ�Ԫ��)			*/
/* ����ֵ:1--�ɹ�ɾ��	0--ɾ��ʧ��								*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListDelete(SkipList list, KeyType key)
{
	PNode Pre[MAX_LEVEL];
	PNode p = NULL;
	PNode q = NULL;
	p = list->head;

	int k = list->maxLevel;

	for (int i = k - 1; i >= 0; i--)
	{
		while ((q = p->next[i]) && (q->key < key))
			//ע��������,����������
			p = q;
		Pre[i] = p;
	}

	//����key�����ɾ������
	if (q && q->key == key)
	{
		for (int i = 0; i < list->maxLevel; i++)
		{
			if (Pre[i]->next[i] == q)
				Pre[i]->next[i] = q->next[i];
		}
		free(q);    //ɾ�����
		list->num--;    //��Ծ����ļ�����-1
		return 1;   //ɾ���ɹ�
	}
	return 0;   //ɾ��ʧ��
}

/****************************************************************/
/* void PrintSkipList(SkipList list)							*/
/* ����:�����Ծ����											*/
/* �������list:��Ծ����										*/
/* ����ֵ:��													*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
void PrintSkipList(SkipList list)
{
	PNode p = list->head;
	PNode q = NULL;
	int i = 0;
	for (i=0;i<list->maxLevel;i++)
	{
		q = p->next[i];
		printf("\n��%d��Ľ��ֱ���: ", i);
		while (q)
		{
			printf("%d ", q->key);
			q = q->next[i];
		}
	}
	printf("\n");
}