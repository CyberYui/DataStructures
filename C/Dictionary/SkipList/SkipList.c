#include <stdio.h>
#include <stdlib.h>
//产生随机层需要用random,故引入time.h
#include <time.h>
#include "SkipList.h"

/****************************************************************/
/* PNode CreateNode(int level, KeyType key)						*/
/* 功能:创建结点												*/
/* 输入参数level:结点所在层数									*/
/* 输入参数key:结点的值											*/
/* 返回值p:结点													*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
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
/* 功能:创建带有头结点的空跳跃链表								*/
/* 输入参数level:层数											*/
/* 返回值list:跳跃链表											*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
SkipList SetNullSkipList(int level)
{
	SkipList list = (SkipList)malloc(sizeof(SkipList));
	//申请内存失败则返回NULL
	if (list == NULL)
	{
		return NULL;
	}
	list->num = 0;  //空跳跃链表计数器赋值0
	list->maxLevel = level; //跳跃链表的层数
	list->head = CreateNode(level, -1);  //头结点的数据域赋值为-1
	//如果头结点创建失败,则释放链表空间,返回NULL
	if (list->head == NULL)
	{
		free(list);
		return NULL;
	}
	//给头结点的每一层后继设置为空
	for (int i = 0; i < level; i++)
	{
		list->head->next[i] = NULL;
	}
	return list;
}

/****************************************************************/
/* int RandomLevel(int maxlevel)								*/
/* 功能:产生随机层数(伪),在各塔中自底向上逐层生长		    	*/
/* 输入参数maxLevel:允许的最大层数								*/
/* 返回值i:层数													*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int RandomLevel(int maxlevel)
{
	int i = 1;
	//生成的层数i>=1 && i<=maxlevel
	while (rand() % 2)    //出现偶数
		i++;
	i = (i > maxlevel) ? maxlevel : i;
	return i;   //i就是产生的层数
}

/****************************************************************/
/* int SkipListInsert(SkipList list, KeyType key)				*/
/* 功能:插入结点												*/
/* 输入参数list:要插入的跳跃链表								*/
/* 输入参数key:结点值											*/
/* 返回值:1--成功插入	0--插入失败								*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListInsert(SkipList list, KeyType key)
{
	int level = 0;
	PNode Pre[MAX_LEVEL];   //记录每层的前驱结点位置
	PNode p = NULL;
	PNode q = NULL;
	p = list->head; //从头结点开始

	//查找位置,记录前驱结点信息
	for (int i = list->maxLevel - 1; i >= 0; i--)    //纵向控制层
	{
		//横向查找插入位置,而for循环时纵向移动查找位置
		while ((q = p->next[i]) && (q->key < key))
			//注意这两句,可能有问题
			p = q;
		Pre[i] = p;
	}

	//已经存在相同的key,不能插入
	if ((q != NULL) && (q->key == key))
		return 0;   //查找成功,不插入

	//使用RandomLevel投币
	level = RandomLevel(list->maxLevel);    //产生一个随机层数
	p = CreateNode(level, key);  //创建新结点
	if (p == NULL)
	{
		return 0;   //创建新结点不成功
	}

	//纵向逐层修改指针
	for (int i = 0; i < level; i++)
	{
		p->next[i] = Pre[i]->next[i];
		Pre[i]->next[i] = p;
	}

	//新结点添加成功
	list->num++;    //跳跃链表的计数器+1
	return 1;   //插入成功
}

/****************************************************************/
/* PNode SkipListSearch(SkipList list, KeyType key)				*/
/* 功能:按值查找结点											*/
/* 输入参数list:跳跃链表										*/
/* 输入参数key:查找的结点的值									*/
/* 返回值:p--查找成功的结点的位置		NULL--查找失败			*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode SkipListSearch(SkipList list, KeyType key)
{
	int n = 0;
	PNode p = NULL;
	PNode q = NULL;
	p = list->head;

	//从高层开始,纵向逐层比较
	for (int i = list->maxLevel - 1; i >= 0; i--)
	{
		//横向比较
		//q=p->next[i]是检查是否到达链表尾部
		//q->key<=key是检查是否找到了比查询的key大的元素
		while ((q = p->next[i]) && (q->key <= key))
		{
			p = q;
			n++;    //记录比较次数
			if (p->key == key)
			{
				printf("在第%d层查找到了%d\n", i, key);
				printf("共比较了%d次\n", n);
				return p;   //查找成功,返回p
			}
		}
	}
	return NULL;    //查找失败,返回NULL
}

/****************************************************************/
/* int SkipListDelete(SkipList list, KeyType key)				*/
/* 功能:按值删除结点											*/
/* 输入参数list:跳跃链表										*/
/* 输入参数key:要删除的结点的值(默认链表中无重复元素)			*/
/* 返回值:1--成功删除	0--删除失败								*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
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
			//注意这两句,可能有问题
			p = q;
		Pre[i] = p;
	}

	//存在key则进行删除操作
	if (q && q->key == key)
	{
		for (int i = 0; i < list->maxLevel; i++)
		{
			if (Pre[i]->next[i] == q)
				Pre[i]->next[i] = q->next[i];
		}
		free(q);    //删除结点
		list->num--;    //跳跃链表的计数器-1
		return 1;   //删除成功
	}
	return 0;   //删除失败
}

/****************************************************************/
/* void PrintSkipList(SkipList list)							*/
/* 功能:输出跳跃链表											*/
/* 输入参数list:跳跃链表										*/
/* 返回值:无													*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
void PrintSkipList(SkipList list)
{
	PNode p = list->head;
	PNode q = NULL;
	int i = 0;
	for (i=0;i<list->maxLevel;i++)
	{
		q = p->next[i];
		printf("\n第%d层的结点分别是: ", i);
		while (q)
		{
			printf("%d ", q->key);
			q = q->next[i];
		}
	}
	printf("\n");
}