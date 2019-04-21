关于线性表的相关知识<font color=brown>(C语言)</font>
=====
线性结构是一个<font color=Red>数据元素</font>的<font color=Red>有序集</font>,其基本特征是:
* 集合中存在唯一的第一个元素
* 集合中存在唯一的最后一个元素
* 除第一个元素外,都存在唯一的直接前驱
* 除最后一个元素外,都存在唯一的直接后继<br>

><font color=gray>线性表,栈和队列都是线性结构</font>
***************************

线性表的特点是:
--------------
1. 有限序列
2. 所有元素的性质相同
3. 元素箭关系是线性的(即唯一前驱和唯一后继)
**************************

线性表的逻辑特点
---------------
对于非空线性表(k<sub>0</sub>,k<sub>1</sub>,...,k<sub>n-1</sub>),其逻辑特点是:
* <font color=green>唯一一个"第一个"</font>:<br>
&emsp;有且仅有一个开始结点<font color=red>k<sub>0</sub></font>,它没有直接前驱,而仅有一个直接后继<font color=red>k<sub>1</sub></font>;
* <font color=green>唯一一个"最后一个"</font>:<br>
&emsp;有且仅有一个终端结点<font color=red>k<sub>n-1</sub></font>,它没有直接后继,而仅有一个直接前驱<font color=red>k<sub>n-2</sub></font>
* <font color=green>其余的内部结点</font><font color=blue>k<sub>i</sub>(1≤i≤n-2)</font>:<br>
&emsp;都有且仅有一个直接前驱和一个直接后继
********************************

<font color=darkblue>线性表的ADT(抽象数据类型)<br>
operations</font><br>
&emsp;List SetNullList(void)<br>
&emsp;int IsNull(List list)<br>
&emsp;int InsertPre(List list,position p,Datatype x)<br>
&emsp;int InsertPost(List list,position p,Datatype x)<br>
&emsp;int DelIndex(List list,position p)<br>
&emsp;int DelValue(List list,Datatype x)<br>
&emsp;int LocateIndex(List list,Datatype x)<br>
&emsp;int LocatePos(List list,Datatype x)<br>
<font color=darkblue>End ADT List</font><br>
><font color=darblue>可写成模版类</font>
********************************

线性表操作的基本类型
------------------
<font color=darred>动态操作</font><br>
1>结构的初始化<br>
&emsp;无初始条件,操作结果构造一个空的线性表<br>
2>销毁结构<br>
&emsp;初始条件:线性表存在<br>
&emsp;操作结果:线性表被销毁,内存空间被释放<br>
3>加工型操作<br>
&emsp;改变了线性表的结构<br>
<font color=darred>静态操作</font><br>
4>引用型操作<br>
&emsp;不改变线性表的结构<br>

>动态结构与静态结构的区别:<font color=dark>是否改变线性表的结构</font>
********************************

线性表在内存中有两种存储方式:
----------------------------
><font color=dark>即顺序表(顺序存储)和链表(链式存储)</font><br>

顺序表的特点:<br>
&emsp;用一组<font color=red>地址连续的存储单元</font>依次存储线性表中各元素,通过<font color=red>位置</font>表示结点之间的逻辑关系<br>

链表的特点:<br>
&emsp;用一组<font color=red>任意的存储单元</font>存储线性表中各元素,通过<font color=red>指针</font>来表示数据元素之间的逻辑关系

>两者的主要区别:指针
********************************

一个简单的例子
----
&emsp;如果已知<font color=red>k<sub>0</sub></font>的位置,知道每一个元素占<font color=whiteblue>C</font>个存储单元,如何计算<font color=red>k<sub>i</sub></font>元素所在的位置?<br>
&emsp;&emsp;&emsp;&emsp;&emsp;公式:<font color=purple>LOC(k<sub>i</sub>)=LOC(k<sub>0</sub>)+i*c</font><br>
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

```c
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

```c
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
&emsp;首先定义顺序表类型为int型,封装三个成员在结构体中<br>
&emsp;最后定义结构体为SeqList类型<br>

```c
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

```c
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
```c
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

&emsp;先要检查表的空间是否满了,在表满的情况下是不能继续插入的,否则会产生溢出错误<br>
&emsp;要检验插入位置的有效性,这里p的有效范围是:0<=p<=n,其中n为原表长<br>
&emsp;注意数据的移动方向:从下标大的元素开始移动

```c
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
&emsp;算法的时间主要花费在结点的移动上,在表中第i个位置上插入一个结点的移动次数为<font color=red>(n-i)</font><br>
&emsp;&emsp;当i=n时,无需移动结点;<br>
&emsp;&emsp;&emsp;即最好情况,时间复杂度为O(1)<br>
&emsp;&emsp;当i=0时,需要移动表中所有结点;<br>
&emsp;&emsp;&emsp;即最坏情况,时间复杂度为O(n)<br>
<br>
&emsp;平均的时间复杂度为<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/InsertF1.png)<br>
&emsp;其中:<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/InsertF2.png)<br>
&emsp;M<sub>i</sub>为第i个结点<br>
&emsp;P<sub>i</sub>为在第i个位置上插入结点的概率<br>
<br>
&emsp;结果为n/2,即平均时间复杂度为O(n)<br>

顺序表的删除
-----------
1. 移动结点
2. 减少表长

* 要检查删除位置的游戏O型0<=p<n
* 注意数据的移动方向:从下标小的元素开始

```c
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
&emsp;算法的时间主要花费在结点的移动上,子表中删除第i个位置上一个结点的移动次数为<font color=red>(n-i-1)</font><br>
&emsp;&emsp;当i=n-1时,即删除最后一个结点,无需移动;<br>
&emsp;&emsp;&emsp;即最好情况,时间复杂度为O(1)<br>
&emsp;&emsp;当i=0时,须移动表中所有结点;<br>
&emsp;&emsp;&emsp;即最坏情况,时间复杂度为O(n)<br>
<br>
&emsp;平均的时间复杂度为<br>
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/DeleteF3.png)
<br>
&emsp;其中:<br>
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/DeleteF4.png)
<br>
&emsp;M<sub>d</sub>为第i个结点<br>
&emsp;P<sub>i</sub>为在第i个位置上删除结点的概率<br>
<br>
&emsp;结果为n-1/2,即平均时间复杂度为O(n)<br>

>[思考]如果想要删除顺序表中所有值为x的元素,应该怎么设计算法呢?

顺序表的查找
-----------
&emsp;从起始位置开始依次扫描,扫描到元素后返回下标,若整个表寻找完毕之后仍未找到,则返回-1
```c
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
>[注]不难看出,算法的时间复杂度为O(n)

使用二分查找算法进行顺序表的查找
-------------
* 二分查找---减而治之

&emsp;减而治之,即策略为每次检索都将问题分为一半<br>
&emsp;首先将一段数据分为两部分,最左侧设为Low,最右侧设为High<br>
&emsp;中间设为Mid=(Low+High)/2<br>
![F5](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/CuttingTheSequence.png)<br>
&emsp;如果现在要检索x的存在,首先要同中间的元素相比较,<br>
&emsp;如果中间元素就是x,那么比较一次就成功,则返回<br>
&emsp;如果中间元素不是x,那么有两种情况<br>
&emsp;&emsp;<1>小于x的,即前半区间进行递归检索,此时,Low不动,High变为Mid-1<br>
![F6](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/WhenLowerThanX.png)<br>
&emsp;&emsp;<2>大于x的,即后半区间进行递归检索,此时,High不动,Low变为Mid+1<br>
![F7](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSequenceListModel_C/WhenHigherThanX.png)<br>
&emsp;在此过程中,返回的情况有多种,以下给出只有两种的情况<br>
&emsp;&emsp;可以直接将返回设定为一直二分直到变成一次成功,即返回1<br>
&emsp;&emsp;此外,如果没有查找到,则返回-1即可<br>

```C
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
>[注]二分查找算法是基于顺序表进行的,顺序表必为按序排列的表<br>
>相关的具体实例见CH2-4顺序表的查找定位.pdf

**********************************************

关于代码中使用到的一些知识
==============
<1> 结构体
---------
&emsp;在C语言中，可以使用结构体（Struct）来存放一组不同类型的数据。结构体的定义形式为：
```c
struct 结构体名{
    结构体所包含的变量或数组
};
```
&emsp;在调用这一结构体时,必须像下面这样
```c
类型    结构体名 实例化对象名       其他内容
struct  Point   oPoint1         ={100，100，0};
struct  Point   oPoint2;
```


&emsp;本例中有这样一段代码
```c
typedef int DataType;
struct List
{
    int Max;//最大元素个数
    int n;//实际元素个数
    DataType *elem;//首地址
};
typedef struct List *SeqList;
```
&emsp;其中以下内容就是一个结构体
```c
struct List
{
    int Max;//最大元素个数
    int n;//实际元素个数
    DataType *elem;//首地址
};
```
&emsp;即一个顺序表包含了3个成员,分别是max,n,elem<br>
&emsp;结构体成员的定义方式与变量和数组的定义方式相同，只是不能初始化

<2> typedef的用法
---------------
其用法主要有四种:
1. 为基本数据类型定义新的类型名,如

        typedef unsigned int COUNT;
        typedef double REAL;

&emsp;&emsp;这样做便于跨平台移植程序,具体见百度.

2. 为自定义数据类型（结构体、共用体和枚举类型）定义简洁的类型名称,如

```c
typedef struct tagPoint
{
    double x;
    double y;
    double z;
} Point;
```
&emsp;&emsp;在这段代码中,实际上完成了两个操作:<br>
&emsp;&emsp;定义了一个新的结构类型,即
```c
struct tagPoint
{
    double x;
    double y;
    double z;
} ;
```
&emsp;&emsp;使用 typedef 为这个新的结构起了一个别名，叫Point,即
```c
typedef struct tagPoint Point
```
&emsp;&emsp;这样之后就可以使用<code>Point oPoint1={100，100，0};</code>之类的形式调用结构体了

&emsp;&emsp;即标准的定义名称格式为类似于这样的代码:
```c
struct tagNode
{
    char *pItem;
    struct tagNode *pNext;
};
typedef struct tagNode *pNode;
```

3. 为数组定义简洁的类型名称<br>

&emsp;&emsp;它的定义方法很简单，与为基本数据类型定义新的别名方法一样，示例代码如下所示：
```c
typedef int INT_ARRAY_100[100];
INT_ARRAY_100 arr;
```

4. 为指针定义简洁的名称<br>

&emsp;&emsp;对于指针，我们同样可以使用下面的方式来定义一个新的别名:
```c
typedef char* PCHAR;
PCHAR pa;
```

&emsp;&emsp;在上段代码中,有以下两句
```c
typedef int DataType;
typedef struct List *SeqList;
```
&emsp;顺序表代码中的<code>typedef int DataType;</code>就是<font color=red>用法1</font>,即对int型定义为DataType型.<br>
&emsp;顺序表代码中的<code>typedef struct List *SeqList;</code>就是<font color=red>用法2</font>,即对List结构体起了一个SeqList的别名.<br>

<3> malloc函数和free函数
-------------

&emsp;&emsp;&emsp;&emsp;void *malloc(long NumBytes)：<br>
&emsp;&emsp;该函数分配了NumBytes个字节，并返回了指向这块内存的指针。如果分配失败，则返回一个空指针（NULL）。<br>

&emsp;&emsp;&emsp;&emsp;void free(void *FirstByte)：<br>
&emsp;&emsp;该函数是将之前用malloc分配的空间还给程序或者是操作系统，也就是释放了这块内存，让它重新得到自由。<br>

&emsp;在顺序表代码中,有这样两行代码
```c
SeqList slist = (SeqList)malloc(sizeof(struct List));
..........//略去一些内容
free(slist);
```
&emsp;&emsp;第一行<code>(SeqList)malloc(sizeof(struct List))</code><br>
&emsp;是申请了一个List结构体大小的内存空间给slist,slist的类型是(SeqList),这是用于告诉malloc函数的,不是定义<br>

&emsp;之后这行<code>free(slist);</code>即释放了malloc申请到的内存空间<br>
