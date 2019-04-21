#include <stdio.h>
#include <stdlib.h>

//����ṹ��
typedef int DataType;//����int����ΪDataType����
struct List
{
	int Max;		//���Ԫ�ظ���
	int n;			//ʵ��Ԫ�ظ���,���±���,��0��ʼ
	DataType *elem;	//�׵�ַ
};
typedef struct List *SeqList;//��˳������ͽ��ж���

//��ʼ������
SeqList setNullList_seq(int m)
{
	//����ṹ��ռ�
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	//�����п�,��Ϊ��֤�������ڴ�ɹ�
	if (slist != NULL)
	{
		//��������ռ�,��DataType��,Ҳ����int��
		//������m��DataType�͵��ڴ�ռ�
		slist->elem = (DataType*)malloc(sizeof(DataType)*m);
		//�ж��Ƿ����׵�ַ,����֤����Ч�ռ�
		if (slist->elem)
		{
			slist->Max = m;	//˳������ֵ
			slist->n = 0;	//˳�������Ԫ��,������Ϊ0
			return slist;
		}
		else
		{
			//����ֱ���ͷ�����ռ�
			free(slist);
		}
	}
	//���벻�ɹ�,���ؿ�ֵ,��������
	printf("out of space!\n");
	return NULL;
}

//�пպ���
int IsNullList(SeqList slist)
{
	//����ֵ��1��0,��Ϊint��
	return(slist->n == 0);
}

//���뺯��
int InsertPre_seq(SeqList slist, int p, DataType x)
{
	int q;
	//�ж�˳����Ƿ�����
	if (slist->n >= slist->Max)
	{
		printf("overflow!\n");
		return(0);
	}
	//�ж������λ���Ƿ�Ϸ�,���Ƿ��ܹ�ӵ���±�Ϊp��Ԫ��
	if (p<0 || p>slist->n)
	{
		printf("not exist!\n");
		return(0);
	}
	//ͨ���ж�,���в������
	for (q = slist->n - 1; q >= p; q--)
	{
		//����λ��֮���Ԫ���Ⱥ���,�ճ�λ��
		slist->elem[q + 1] = slist->elem[q];
	}
	//����Ԫ��x,˳�����+1
	slist->elem[p] = x;
	slist->n = slist->n + 1;
	return(1);
}

//ɾ��Ԫ�غ���
int DelIndex_seq(SeqList slist, int p)
{
	//ɾ���±�Ϊp��Ԫ��
	int q;
	if (p < 0 || p >= slist->n)
	{
		//�ж�p�Ƿ�Ϸ�
		printf("not exist!\n");
		return 0;
	}
	//ͨ���ж�,��ʼɾ������
	for (q = p; q < slist->n; q++)
	{
		//pλ��֮���ÿ��Ԫ����ǰ����
		slist->elem[q] = slist->elem[q + 1];
	}
	//˳�����-1
	slist->n = slist->n - 1;
	return 1;
}

//��ӡ˳���
void Print_seq(SeqList slist)
{
	int i;
	for (i=0;i<slist->n;i++)
	{
		//������λ��ָ�������ƶ������������
		printf("%d", slist->elem[i]);
		printf(" ");
	}
	printf("\n");
}

//����ֵΪx��Ԫ��,����Ԫ������λ�õ��±�
int LocateIndex_seq(SeqList slist, int x)
{
	int q;
	for (q = 0; q < slist->n; q++)
	{
		//���ҳɹ�,���ض�Ӧ���±�
		if (slist->elem[q] == x)
			return q;
	}
	return -1;
}

//���ֲ����㷨---������֮
//*pos���ڼ�¼�������ʧ�ܵ������,���Ԫ�ز��뵽˳�����Ӧ�������λ��
int Binsearch_seq(SeqList slist, int key, int *pos)
{
	int index = 1;//���ڼ�¼�Ƚϴ���
	int mid;
	int low = 0;
	int high = slist->n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//һ�β��ҳɹ�,����1
		if (slist->elem[mid] == key)
		{
			*pos = mid;
			printf("�ҵ�Ԫ��,��������%d�αȽ�\n", index);
			printf("Ҫ�ҵ�����%d��λ��%d��\n", key, mid);
			return 1;
		}
		//���ֲ���
		else if (slist->elem[mid] > key)
				high = mid - 1;
		else	low = mid + 1;
		//�Ƚϴ�������
		index++;
	}
	*pos = low;
	printf("û���ҵ�Ԫ��,��������%d�αȽ�\n", index - 1);
	printf("�ɽ��������뵽λ��%d��\n", *pos);
	return -1;
}

int main()
{
	//����һ��SeqList,��List�ṹ����
	SeqList seqlist;
	//��ʼ��˳���,����˳������Ϊ12
	seqlist = setNullList_seq(12);
	//���Ƚ����пպ�������
	printf("%d", IsNullList(seqlist));
	printf("\n");
	//��ȡ��������,����˳���
	printf("����˳����Ԫ��: \n");
	int i, x;
	//ѭ������7��Ԫ��
	for (i=0;i<7;i++)
	{
		scanf_s("%d", &x);
		InsertPre_seq(seqlist, i, x);
	}
	//˳��������,����һ��˳�����
	printf("%d", seqlist->n);
	printf("\n");
	//�ٴν����пղ���
	printf("˳����Ƿ�Ϊ��,1Ϊ��,0Ϊ�ǿ�: %d\n", IsNullList(seqlist));
	//����˳���,���Ԫ��
	printf("��ǰ˳����Ԫ����: ");
	Print_seq(seqlist);
	//����ɾ������
	DelIndex_seq(seqlist, 3);
	printf("ɾ���±�Ϊ3��Ԫ�غ��˳���Ϊ: ");
	//�ٴα����鿴���
	Print_seq(seqlist);
	//��2λ�ò���99��һԪ��
	InsertPre_seq(seqlist, 2, 99);
	printf("���±�2λ��֮ǰ����99��˳���Ϊ: ");
	//�ٴα����鿴���
	Print_seq(seqlist);
	//���Բ��Һ���
	int y = 3;
	int m = LocateIndex_seq(seqlist, y);
	printf("ֵΪ%d��Ԫ����˳����%dλ��", y, m);
	printf("\n");
	//���Զ��ֲ����㷨
	int key = 4;//֮ǰɾ�������λ�õ�Ԫ��,Ӧ����ʾ�޷�ƥ��
	int pos;
	Binsearch_seq(seqlist, key, &pos);
}