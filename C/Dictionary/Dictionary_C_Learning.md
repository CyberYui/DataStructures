字典
=========
关键词:时空折中和查找校验<br>

跳跃链表---空间换取时间<br>
散列表---解决同义词冲突<br>
Merkle树---查找完整性校验<br>

字典的基本概念
---------
在计算机科学领域,字典通常被抽象为符号表(Symbol table)来表示<br>
从抽象的数据类型角度来看,[字典]=[关键码(key)]+[属性(attribute)](或[值(value)])<br>

* 应用场合<br>
        *分类词汇表,汇编程序和编译程序产生中的符号表,OS中inode(操作系统中的inode)<br>
        *分类词汇表=单词+该词的同义词表<br>
        *编译程序中的符号表=标识符+初始值以及使用该标识符的行号表<br>
* 操作:<font color=green>检索</font>,<font color=green>插入元素和删除元素</font>,其中最主要的运算是进行<font color=red>检索</font><br>
        *检索:给定一个key,在字典中找出关键码等于key的元素<br>

字典分类:<br>
静态字典:一旦建立好,基本不动<br>
动态字典:经常需要更新<br>

字典常用的存储形式有:<br>
* 顺序存储<br>
* 链式存储:跳跃链表,之前提到的各种树形结构(二叉排序树,红黑树)<br>
* 散列表示<br>

无论采用什么存储形式,都要保证有效地实现基本操作<br>

[综合考虑]时间效率,空间效率和计算开销,甚至算法的复杂性<br>

[评价标准]**平均检索长度**(<font color=red>A</font>verage <font color=red>S</font>earch <font color=red>L</font>ength)<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic1.png)<br>

跳跃链表基本概念
----------
之前学习的链表缺点是只能顺序查找,即使是有序的链表也不能实现二分查找操作.<br>
跳跃链表(SkipList)则是有序链表的变种,它能够达到O(log n)的查找性能,是一种高效的字典结构<br>

在单链表中只有一个指向直接后继的指针,而在跳跃链表中增加指向其他后继结点的指针,使得访问链表的过程中可以交替的跳过他的直接后继结点.<br>

如下图所示,就是一个跳跃链表:<br>
每一个横向链称为一层,同一层的结点是有序的,分别相互标记后继,并且有前驱的展现<br>
每一个纵向有多层的结点称为一个塔,一个塔可以有多个后继,且包括高层和低层<br>
一个跳跃链表,所有高层链表的结点都是整个链表最底层结点集的一个子集<br>
跳跃链表在查找时,先从高层开始检索,失败则跳至下一层开始检索,以此类推<br>
最坏的情况就是在最底层查找,时间复杂度为O(n)<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic2.png)<br>
>比如7这个结点,它有4个指针,那么在实际使用时,就可以通过其第3层指针跳过9和12这两个结点从而直接查找18这个结点

跳跃链表的数据结构定义
-----------
>跳跃链表的实现参照SkipList项目

```c
#define MAX_LEVEL 6 //定义最大层数
typedef int KeyType;
//跳跃链表结点结构定义
typedef struct node
{
    int level;  //结点层数
    KeyType key;    //结点的值
    struct node *next[MAX_LEVEL];   //指针数组
	//struct node *next[1];   //指针数组
}*PNode;
```
跳跃链表的结点结构示意图如下:
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic3.png)<br>
```c
//跳跃链表结构定义
typedef struct SKIPLIST_STRU
{
    int num;    //跳跃链表数据个数
    int maxLevel;   //跳跃链表最大层数
    PNode head; //跳跃链表的头指针
}*SkipList;
```
跳跃链表的结构示意图如下:
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic4.png)<br>

空跳跃链表的建立
-----------
```c
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
```
相关的结点创建函数如下:
```c
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
```
生成的空跳跃链表像这样:
![F5](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic5.png)<br>

跳跃链表的查找:成功情况
---------
[查找算法]<br>
&emsp;&emsp;假设要查找元素key,从最高层的指针开始,如果找到该元素,则返回结点指针.如果到达了链表的末尾,或者找到大于key的某个元素elem,接着降低一层,从包含elem的那个结点的前一个结点重新开始查找.重复该过程直到找到key,或者在第一层查找达到了链表末尾,或者找到了一个大于key的元素.<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic2.png)<br>
[例如]查找关键码12:<br>
&emsp;&emsp;先在第四层查找,这一层只有7,查找失败.<br>
&emsp;&emsp;接着从第三层查找,这一层有7和18,查找失败.<br>
&emsp;&emsp;然后从第二层查找,7-->9-->12,查找成功<br>

跳跃链表的查找:失败情况
---------
[查找算法]<br>
&emsp;&emsp;假设要查找元素key,从最高层的指针开始,如果找到该元素,则返回结点指针.如果到达了链表的末尾,或者找到大于key的某个元素elem,接着降低一层,从包含elem的那个结点的前一个结点重新开始查找.重复该过程直到找到key,或者在第一层查找达到了链表末尾,或者找到了一个大于key的元素.<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic2.png)<br>
[例如]查找关键码23:<br>
&emsp;&emsp;先在第四层查找,这一层只有7,查找失败.<br>
&emsp;&emsp;接着从第三层查找,这一层有7和18,查找失败.<br>
&emsp;&emsp;然后从第二层查找,7-->9-->12-->18-->30,30>23,查找失败<br>
&emsp;&emsp;然后从最底层查找,查到25时,25>23,查找失败,查找结束<br>

跳跃链表的查找算法具体实现
------------
```c
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
				printf("%d\n", n);
				return p;   //查找成功,返回p
			}
		}
	}
	return NULL;    //查找失败,返回NULL
}
```

跳跃链表的插入
---------
* [插入过程]:
        首先进行查找,
        <font color=green>查找成功</font>,<font color=green>返回0</font>(因为在这里约定不能有相同的key),故不再插入.
        <font color=blue>查找失败</font>,<font color=blue>则创建一个结点</font>,<font color=red>接着,逐层修改关联的指针</font>,<font color=purple>跳跃链表的计数器+1</font>.

&emsp;&emsp;创建结点的层数根据投币产生,在算法中使用逻辑表达式rand() % 2来模拟投币过程,通过(伪)随机数的奇偶来模拟一次理想的投币过程.根据RandomLevel的返回值插入到相应的层

像这样:
![F6](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic6.png)<br>

```c
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
/* int RandomLevel(int maxlevel)								*/
/* 功能:产生随机层数(伪),在各塔中自底向上逐层生长		    	*/
/* 输入参数maxLevel:允许的最大层数							   	*/
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

```

跳跃链表的删除
--------
* [删除过程]:
        首先进行查找,
        <font color=green>查找不成功返回0</font>,
        <font color=blue>查找成功则逐层修改关联的指针</font>,<font color=blue>释放结点</font>,<font color=brown>跳跃链表的计数器-1</font>.

[例如]
要删除30,需要修改30的前驱结点18和27的指针,其中虚线表示要修改的指针.
像这样:
![F7](https://github.com/CyberYui/DataStructures/blob/master/C/Dictionary/Dictionary_Pic7.png)<br>

```c
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
```

跳跃链表的遍历输出
-------
```c
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
```

>跳跃链表的实现参照SkipList项目