双链表
----------
对于单链表来说,要想操作,必须从头结点开始,顺着链表进行操作<br>
明显的缺点是,已知一个结点,仅能访问其后继结点,无法访问其前驱结点<br>
改进的方式有两种:<br>
* 改造为循环链表
* 改造为双链表

双链表与单链表的不同是:<br>
* 双链表一个结点有两个指针域,一个指向其前驱结点,另一个指向其后继结点<br>
* 此外,双链表还封装着一个包括头指针和尾指针的结构体,头指针指向头结点,尾指针指向尾结点<br>

```c
//双向链表类型声明
struct DoubleNode;
typedef struct DoubleNode *PDoubleNode;

//双链表结点结构体
struct DoubleNode
{
    DataType info;
    PDoubleNode leftlink,rightlink;
};

//双链表类型
struct DoubleList
{
    PDoubleNode head;//头指针
    PDoubleNode rear;//尾指针
};

typedef struct DoubleList * PDoubleList;
PDoubleList pdlist;//pdlist是指向双链表类型的指针变量
```

例如下图这样:<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/DoubleLinkedListDemo.png)<br>

双链表以牺牲空间为代价达到了便于查找的形式.<br>

双链表的删除操作
----------
假设现在要删除k<sub>i</sub>结点(即p结点)<br>
首先观察其前驱结点和后继结点的两个指针域的逻辑变化<br>
即p的前驱结点的后继指针指向p的后继结点,<br>
p的后继结点的前驱指针指向p的前驱结点,这样就提取出(k<sub>i</sub>)p结点了<br>
<code>p->leftlink->rightlink = p->rightlink;</code><br>
<code>p->rightlink->leftlink = p->leftlink;</code><br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/DoubleLinkedListDeleteDemo.png)<br>


双链表的插入操作
----------
假设要在k<sub>i</sub>结点(即p结点)之后插入x结点(即q结点)<br>
首先观察p的后继结点及其前驱结点和q的前驱结点以及后继结点这些指针域的逻辑变化<br>
即p的后继结点变为q的后继结点,<br>
p的后继结点的前驱结点变为q,<br>
p变为q的前驱结点,<br>
q变为p的后继结点,这样就插入了q结点<br>
<code>p->rightlink = q->rightlink;</code><br>
<code>p->rightlink->leftlink = q;</code><br>
<code>q->leftlink = p;</code><br>
<code>p->rightlink = q;</code><br>

[注]后两步的顺序一定不能变化,具体看图即可
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/DoubleLinkedListInsertDemo.png)<br>
