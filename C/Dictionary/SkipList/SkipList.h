#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 3	//定义最大层为三层
typedef int KeyType;

//跳跃链表的结点结构定义
typedef struct node
{
	int level;				//结点层数
	KeyType key;			//结点的值
	struct node *next[1];   //指针数组
}*PNode;

//跳跃链表结构定义
typedef struct SKIPLIST_STRU
{
	int num;		//跳跃链表数据个数
	int maxLevel;   //跳跃链表最大层数
	PNode head;		//跳跃链表的头指针
}*SkipList;

/****************************************************************/
/* PNode CreateNode(int level, KeyType key)						*/
/* 功能:创建结点												*/
/* 输入参数level:结点所在层数									*/
/* 输入参数key:结点的值											*/
/* 返回值p:结点													*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode CreateNode(int level, KeyType key);

/****************************************************************/
/* SkipList SetNullSkipList(int level)							*/
/* 功能:创建带有头结点的空跳跃链表								*/
/* 输入参数level:层数											*/
/* 返回值list:跳跃链表											*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
SkipList SetNullSkipList(int level);

/****************************************************************/
/* int RandomLevel(int maxlevel)								*/
/* 功能:产生随机层数(伪),在各塔中自底向上逐层生长		    	*/
/* 输入参数maxLevel:允许的最大层数								*/
/* 返回值i:层数													*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int RandomLevel(int maxlevel);

/****************************************************************/
/* int SkipListInsert(SkipList list, KeyType key)				*/
/* 功能:插入结点												*/
/* 输入参数list:要插入的跳跃链表								*/
/* 输入参数key:结点值											*/
/* 返回值:1--成功插入	0--插入失败								*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListInsert(SkipList list, KeyType key);

/****************************************************************/
/* PNode SkipListSearch(SkipList list, KeyType key)				*/
/* 功能:按值查找结点											*/
/* 输入参数list:跳跃链表										*/
/* 输入参数key:查找的结点的值									*/
/* 返回值:p--查找成功的结点的位置		NULL--查找失败			*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode SkipListSearch(SkipList list, KeyType key);

/****************************************************************/
/* int SkipListDelete(SkipList list, KeyType key)				*/
/* 功能:按值删除结点											*/
/* 输入参数list:跳跃链表										*/
/* 输入参数key:要删除的结点的值(默认链表中无重复元素)			*/
/* 返回值:1--成功删除	0--删除失败								*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListDelete(SkipList list, KeyType key);

/****************************************************************/
/* void PrintSkipList(SkipList list)							*/
/* 功能:输出跳跃链表											*/
/* 输入参数list:跳跃链表										*/
/* 返回值:无													*/
/* 创建日期:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
void PrintSkipList(SkipList list);

#endif	//	SKIPLIST_H
