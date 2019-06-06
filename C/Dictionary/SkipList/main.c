#include "SkipList.h"

/*

输入内容:
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
	printf("跳跃链表当前共%d个数据\n", zrxSkipList->num);
	PrintSkipList(zrxSkipList);
	SkipListSearch(zrxSkipList, 13);
	SkipListDelete(zrxSkipList, 13);
	printf("跳跃链表当前共%d个数据\n", zrxSkipList->num);
	PrintSkipList(zrxSkipList);
	printf("%d\n", SkipListSearch(zrxSkipList, 13));
	return 0;
}
/*
[关于查找13的过程]
首先在第2层查找,3和7都不是13,比较两次
在第一层查找,直接跳过3和7,20>13,直接进入下一层,比较了一次
最底层查找,直接从20的前驱结点开始,即13=13,共比较了四次
*/