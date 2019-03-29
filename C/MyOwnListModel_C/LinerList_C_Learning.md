关于线性表的相关知识<font color=brown>(C语言)</font>
=====
线性结构是一个<font color=Red>数据元素</font>的<font color=Red>有序集</font>,其基本特征是:
* 集合中存在唯一的第一个元素
* 集合中存在唯一的最后一个元素
* 除第一个元素外,都存在唯一的直接前驱
* 除最后一个元素外,都存在唯一的直接后继<br>

>线性表,栈和队列都是线性结构
***************************

线性表的特点是:
--------------
1.有限序列<br>
2.所有元素的性质相同<br>
3.元素箭关系是线性的(即唯一前驱和唯一后继)
**************************

线性表的逻辑特点
---------------
对于非空线性表(k<sub>0</sub>,k<sub>1</sub>,...,k<sub>n-1</sub>),其逻辑特点是:
* <font color=green>唯一一个"第一个"</font>:<br>有且仅有一个开始结点<font color=red>k<sub>0</sub></font>,它没有直接前驱,而仅有一个直接后继<font color=red>k<sub>1</sub></font>;
* <font color=green>唯一一个"最后一个"</font>:<br>有且仅有一个终端结点<font color=red>k<sub>n-1</sub></font>,它没有直接后继,而仅有一个直接前驱<font color=red>k<sub>n-2</sub></font>
* <font color=green>其余的内部结点</font><font color=blue>k<sub>i</sub>(1≤i≤n-2)</font>:<br>都有且仅有一个直接前驱和一个直接后继
********************************

<font color=darkblue>线性表的ADT(抽象数据类型)<br>
operations</font><br>
　List SetNullList(void)<br>
　int IsNull(List list)<br>
　int InsertPre(List list,position p,Datatype x)<br>
　int InsertPost(List list,position p,Datatype x)<br>
　int DelIndex(List list,position p)<br>
　int DelValue(List list,Datatype x)<br>
　int LocateIndex(List list,Datatype x)<br>
　int LocatePos(List list,Datatype x)<br>
<font color=darkblue>End ADT List</font><br>
><font color=darblue>可写成模版类</font>
********************************

线性表操作的基本类型
------------------
<font color=darred>动态操作</font><br>
1>结构的初始化<br>
　无初始条件,操作结果构造一个空的线性表<br>
2>销毁结构<br>
　初始条件:线性表存在<br>
　操作结果:线性表被销毁,内存空间被释放<br>
3>加工型操作<br>
　改变了线性表的结构<br>
<font color=darred>静态操作</font><br>
4>引用型操作<br>
　不改变线性表的结构<br>

>动态结构与静态结构的区别:<font color=dark>是否改变线性表的结构</font>
********************************

线性表在内存中有两种存储方式:
----------------------------
><font color=dark>即顺序表(顺序存储)和链表(链式存储)</font><br>

顺序表的特点:<br>
　用一组<font color=red>地址连续的存储单元</font>依次存储线性表中各元素,<br>通过<font color=red>位置</font>表示结点之间的逻辑关系<br>

链表的特点:<br>
　用一组<font color=red>任意的存储单元</font>存储线性表中各元素,<br>通过<font color=red>指针</font>来表示数据元素之间的逻辑关系

>两者的主要区别:指针
********************************

一个简单的例子
----
如果已知<font color=red>k<sub>0</sub></font>的位置,知道每一个元素占<font color=whiteblue>C</font>个存储单元,如何计算<font color=red>k<sub>i</sub></font>元素所在的位置?<br>
　　　　公式:<font color=purple>LOC(k<sub>i</sub>)=LOC(k<sub>0</sub>)+i*c</font><br>
********************************

对顺序表和链表的总结
----------------------------
顺序表 | 链表
------------ | -------------
每个数据元素占用相同数量的存储空间 | 每个数据元素占用相同数量的存储空间
逻辑上相邻的数据元素物理次序上也相邻 | 数据元素的逻辑顺序域物理顺序不一致
相邻两个数据元素<font color=red>k<sub>i</sub></font>与<font color=red>k<sub>i+1</sub></font>存储的位置关系:<font color=purple>LOC(k<sub>i+1</sub>)=LOC(k<sub>i</sub>)+C</font>|数据元素之间的逻辑关系由结点中的指针来指示
第<font color=red>i</font>个元素<font color=red>k<sub>i</sub></font>的存储位置为:<font color=purple>LOC(k<sub>i</sub>)=LOC(k<sub>0</sub>)+i*c</font>| 

********************************

关于顺序表和链表的伪代码
----------------------
>顺序表

```c++
typedef int DataType;
struct List
{
    int Max;//最大元素个数
    int n;//实际元素个数
    DataType *elem;//首地址
};
typedef struct List *SeqList;
//顺序表类型定义
```
<br>

>链表

```c++
typedef int DataType;
struct Node
{
    DataType data;//数据域
    struct Node* next;//指针域
}
typedef struct Node *PNode;
//结点类型定义
typedef struct Node *LinkList;
//单链表类型定义
```
<br>

********************************

顺序表建立和判空
---------------
首先定义顺序表类型为int型,封装三个成员在结构体中<br>
最后定义结构体为SeqList类型<br>

```c++
//伪代码
typedef int DataType;
struct List
{
    int Max;//最大元素个数
    int n;//实际元素个数
    DataType *elem;//首地址
};
typedef struct List *SeqList;
//顺序表类型定义

//使用的时候,首先定义对象
SeqList slist;
//给对象的数据成员赋初始值
slist -> Max = 12;
slist -> n = 0;
slist -> elem;
//判空则通过检查顺序表的长度即可
if(n = 0)
    return false;
```

创建顺序表的具体实现
---------

```c++
SeqList SetNullList_seq(int m)//创建空顺序表
{
    SeqList slist = (SeqList)malloc(sizeof(struct List));
    //申请结构体List空间
    if(slist != NULL)
    {
        slist -> elem = (DataType*)malloc(sizeof(DataType)*m);
        //申请顺序表空间,大小为m个DataType空间,这里DataType应为int
        if(slist -> elem)
        {
            slist -> Max = m;//顺序表的最大值
            slist -> n = 0;//顺序表长度赋值为0,即首位无元素
            return(slist);
        }
        else free(slist);
    }
    printf("out of space!!\n");
    return NULL;
    //申请不成功,返回空,跳出函数
}
```

顺序表判空的具体实现
-------------------
```c++
int IsNullList_seq(SeqList slist)//判断顺序表是否为空
{
    return(slist -> n == 0);
    //返回值是1或0,故为int型
}
```

