#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct List
{
	int Max;
	int n;
	DataType *elem;
};
typedef struct List *SeqList;

SeqList setNullList_seq(int m)
{
	//����ṹ��ռ�
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	if (slist != NULL)
	{
		//��������ռ�
		slist->elem = (DataType*)malloc(sizeof(DataType)*m);
		if (slist->elem)
		{
			slist->Max = m;
			slist->n = 0;
			return slist;
		}
		else
		{
			printf("out of space!\n");
			free(slist);
			return NULL;
		}
	}
	else
	{
		printf("out of space!\n");
		free(slist);
		return NULL;
	}
}

int IsNullList(SeqList slist)
{
	return(slist->n == 0);
}

int InsertPre_seq(SeqList slist, int p, DataType x)
{
	int q;
	if (slist->n >= slist->Max)
	{
		printf("overflow!\n");
		return(0);
	}
	if (p<0 || p>slist->n)
	{
		printf("not exist!\n");
		return(0);
	}
	for (q = slist->n - 1; q >= p; q--)
	{
		slist->elem[q + 1] = slist->elem[q];
	}
	slist->elem[p] = x;
	slist->n = slist->n + 1;
	return(1);
}

int DelIndex_seq(SeqList slist, int p)
{
	int q;
	if (p < 0 || p >= slist->n)
	{
		printf("not exist!\n");
		return 0;
	}
	for (q = p; q < slist->n; q++)
	{
		slist->elem[q] = slist->elem[q + 1];
	}
	slist->n = slist->n - 1;
	return 1;
}

void Print_seq(SeqList slist)
{
	int i;
	for (i=0;i<slist->n;i++)
	{
		printf("%d", slist->elem[i]);
		printf(" ");
	}
	printf("\n");
}

int main()
{
	SeqList seqlist;

	seqlist = setNullList_seq(12);
	printf("%d", IsNullList(seqlist));
	printf("����˳����Ԫ��: \n");
	int i, x;
	//ѭ������6��Ԫ��
	for (i=0;i<6;i++)
	{
		scanf_s("%d", &x);
		InsertPre_seq(seqlist, i, x);
	}
	printf("˳����Ƿ�Ϊ��,1Ϊ��,0Ϊ�ǿ�: %d\n", IsNullList(seqlist));
	printf("��ǰ˳����Ԫ����: ");
	Print_seq(seqlist);
	DelIndex_seq(seqlist, 3);
	printf("ɾ���±�Ϊ3��Ԫ�غ��˳���Ϊ: ");
	Print_seq(seqlist);
	InsertPre_seq(seqlist, 2, 99);
	printf("���±�2λ��֮ǰ����99��˳���Ϊ: ");
	Print_seq(seqlist);
}