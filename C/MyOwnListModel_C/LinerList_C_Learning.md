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

顺序表的插入
----------
1. 移动结点
2. 插入结点
3. 增加表长

先要检查表的空间是否满了,在表满的情况下是不能继续插入的,否则会产生溢出错误<br>
要检验插入位置的有效性,这里p的有效范围是:0<=p<=n,其中n为原表长<br>
注意数据的移动方向:从下标大的元素开始移动

```c++
int InsertPre_seq(SeqList slist,int p,DataType x)
{
    //在线性表slist的p位置之前插入x,成功返回1,否则返回0
    int q;
    if(slist->n >= slist->Max)
    {
        //顺序表满溢出
        printf("overflow");
        return(0);
    }
    if(p<0 || p>slist->n)
    {
        //不存在下标为p的元素
        printf("not exist!\n");
        return(0);
    }
    for(q = slist->n-1;q>=p;q--)
    {
        //插入位置以及之后的元素后移
        slist->elem[q+1]=slist->elem[q];
    }
    slist->elem[p] = x;//插入元素x
    slist->n = slist-> n+1;//顺序表长度加1
    return(1);
}
```

插入算法时间复杂度
----------------
算法的时间主要花费在结点的移动上,在表中第i个位置上插入一个结点的移动次数为<font color=red>(n-i)</font><br>
当i=n时,无需移动结点;<br>
即最好情况,时间复杂度为O(1)<br>
当i=0时,需要移动表中所有结点;<br>
即最坏情况,时间复杂度为O(n)<br>
<br>
平均的时间复杂度为<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnListModel_C/InsertF1.png)<br>
其中:<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnListModel_C/InsertF2.png)<br>
M<sub>i</sub>为第i个结点<br>
P<sub>i</sub>为在第i个位置上插入结点的概率<br>
<br>
结果为n/2,即平均时间复杂度为O(n)<br>

顺序表的删除
-----------
1. 移动结点
2. 减少表长

* 要检查删除位置的游戏O型0<=p<n
* 注意数据的移动方向:从下标小的元素开始

```c++
int Delindex_seq(SeqList slist,int p)
{
    //删除下标为p的元素
    int q;
    if(p<0||p>=slist->n)
    {
        //不存在下标为p的元素
        printf("Not exist\n");
        return 0;
    }
    for(q=p+1;q<slist->n-1;q++)
    {
        //p位置之后的元素向前移动
        slist->elem[q]=slist->elem[q+1];
    }
    slist->n=slist->n-1;//顺序表长度减1
    return 1;
}
```

删除算法的时间复杂度
-------------------
算法的时间主要花费在结点的移动上,子表中删除第i个位置上一个结点的移动次数为<font color=red>(n-i-1)</font><br>
当i=n-1时,即删除最后一个结点,无需移动;<br>
即最好情况,时间复杂度为O(1)<br>
当i=0时,须移动表中所有结点;<br>
即最坏情况,时间复杂度为O(n)<br>
<br>
平均的时间复杂度为<br>
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnListModel_C/DeleteF3.png)
<br>
其中:<br>
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnListModel_C/DeleteF4.png)
<br>
M<sub>d</sub>为第i个结点<br>
P<sub>i</sub>为在第i个位置上删除结点的概率<br>
<br>
结果为n-1/2,即平均时间复杂度为O(n)<br>

[思考]如果想要删除顺序表中所有值为x的元素,应该怎么设计算法呢?

顺序表的查找
-----------
从起始位置开始依次扫描,扫描到元素后返回下标,若整个表寻找完毕之后仍未找到,则返回-1
```c++
//查找值为x的元素,返回元素所在位置的下标
int LocateIndex_seq(SeqList slist,int x)
{
    int q;
    for(q=0;q<slist->n;q++)
    {
        //查找成功,返回对应的下标
        if(slist->elem[q]==x)
            return q;
    }
    return -1;
}
```
[注]不难看出,算法的时间复杂度为O(n)

使用二分查找算法进行顺序表的查找
-------------
[TOC] 二分查找---减而治之

减而治之,即策略为每次检索都将问题分为一半<br>
首先将一段数据分为两部分,最左侧设为Low,最右侧设为High<br>
中间设为Mid=(Low+High)/2<br>
![F5]CuttingTheSequence
如果现在要检索x的存在,首先要同中间的元素相比较,<br>
如果中间元素就是x,那么比较一次就成功,则返回<br>
如果中间元素不是x,那么有两种情况<br>
<1>小于x的,即前半区间进行递归检索,此时,Low不动,High变为Mid-1<br>
![F6]WhenLowerThanX
<2>大于x的,即后半区间进行递归检索,此时,High不动,Low变为Mid+1<br>
![F7]WhenHigherThanX
在此过程中,返回的情况有多种,以下给出只有两种的情况<br>
可以直接将返回设定为一直二分直到变成一次成功,即返回1<br>
此外,如果没有查找到,则返回-1即可<br>

```C++
//*pos用于记录如果查找失败的情况下,这个元素插入到顺序表中应当插入的位置
int Binsearch_seq(SeqList slist,int key,int *pos)
{
    int index=1;//用于记录比较次数
    int mid;
    int low=0;
    int high=slist->n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        //一次查找成功,返回1
        if(slist->elem[mid]==key)
        {
            *pos=mid;
            printf("找到元素,共进行了%d次比较\n",index);
            printf("要找的数据%d在位置%d上\n",key,mid);
            return 1;
        }
        //二分策略
        else if(slist->elem[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        //比较次数增加
        index++;
    }
    *pos=low;
    printf("没有找到元素,共进行了%d次比较\n",index-1);
    printf("可将此数插入到位置%d上\n",*pos);
    return -1;
}
```
[注]二分查找算法是基于顺序表进行的,顺序表必为按序排列的表
相关的具体实例见CH2-4顺序表的查找定位.pdf