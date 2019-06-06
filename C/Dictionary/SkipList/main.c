#include "SkipList.h"

/*

��������:
3
1
20
13
5
8
4
7
21
34
55
89
-1

*/
int main()
{
	SkipList zrxSkipList;
	KeyType data;
	zrxSkipList = SetNullSkipList(3);
	scanf_s("%d", &data);
	while (data != -1)
	{
		SkipListInsert(zrxSkipList, data);
		scanf_s("%d", &data);
	}
	printf("��Ծ����ǰ��%d������\n", zrxSkipList->num);
	PrintSkipList(zrxSkipList);
	SkipListSearch(zrxSkipList, 13);
	SkipListDelete(zrxSkipList, 13);
	printf("��Ծ����ǰ��%d������\n", zrxSkipList->num);
	PrintSkipList(zrxSkipList);
	printf("%d\n", SkipListSearch(zrxSkipList, 13));
	return 0;
}
/*
[���ڲ���13�Ĺ���]
�����ڵ�2�����,3��7������13,�Ƚ�����
�ڵ�һ�����,ֱ������3��7,20>13,ֱ�ӽ�����һ��,�Ƚ���һ��
��ײ����,ֱ�Ӵ�20��ǰ����㿪ʼ,��13=13,���Ƚ����Ĵ�
*/