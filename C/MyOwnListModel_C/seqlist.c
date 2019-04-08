#include <stdio.h>
#include <stdlib.h>

//定义结构体
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
	//申请结构体空间
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	if (slist != NULL)
	{
		//申请数组空间
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

int LocateIndex_seq(SeqList slist, int x)
{
	int q;
	for (q = 0; q < slist->n; q++)
	{
		//查找成功,返回对应的下标
		if (slist->elem[q] == x)
			return q;
	}
	return -1;
}

int main()
{
	SeqList seqlist;

	seqlist = setNullList_seq(12);
	printf("%d", IsNullList(seqlist));
	printf("输入顺序表的元素: \n");
	int i, x;
	//循环输入6个元素
	for (i=0;i<6;i++)
	{
		scanf_s("%d", &x);
		InsertPre_seq(seqlist, i, x);
	}
	printf("顺序表是否为空,1为空,0为非空: %d\n", IsNullList(seqlist));
	printf("当前顺序表的元素是: ");
	Print_seq(seqlist);
	DelIndex_seq(seqlist, 3);
	printf("删除下标为3的元素后的顺序表为: ");
	Print_seq(seqlist);
	InsertPre_seq(seqlist, 2, 99);
	printf("在下标2位置之前插入99后顺序表为: ");
	Print_seq(seqlist);
	int y = 3;
	int m = LocateIndex_seq(seqlist, y);
	printf("值为%d的元素在顺序表的%d位置", y, m);
}