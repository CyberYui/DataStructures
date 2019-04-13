关于单链表的相关知识<font color=brown>(C语言)</font>
================
单链表是一种链式存取的数据结构,不同于顺序表,单链表使用一组地址任意的存储单元存放线性表中的数据元素.<br>
* 数据元素以结点(Node)表示,每个结点包括数据域和指针域(元素和指针)<br>
```c
struct Node
{
    //数据域,即数据元素的映像
    int data;
    //指针域,指示后继元素的存储位置
    struct Node *next;
}
```
><font color=gray>单链表是链式结构</font>
***************************

单链表的特点是
-----------
* 链表存在头指针head,且链表由头指针唯一确定
* 链表中存在头结点,头结点内无数据域(或者说数据域的数据无意义)
* 终端结点无后继,即指针域为空(NULL)
* 存储单元是任意的,可以连续也可以不连续
* 链表的逻辑次序和物理次序不一定相同
**************************

单链表的基本算法
---------
|  建立  |  插入  |    删除   |   查找   |   输出   |
|:------:|:------:|:---------:|:--------:|:--------:|
| 头插法 | 前插法 | 删除P后继 | 序号查找 | 顺序打印 |
| 尾插法 | 后插法 | 删除P本身 | 值查找   |          |
| 递归法 |        |           |          |          |

建立空的单链表
----------
创建带有<font color=red>头结点</font>的空链表
```c
//创建带有头结点的空链表
LinkList SetNullList_Lind()
{
    //申请头结点空间
    LinkList head=(LinkList)malloc(sizeof(struct Node));
    //判断申请空间是否成功
    if(head!=NULL)
        //不为空则证明分配成功,是头结点也是终端结点
        head->next=NULL;
    else
        //为空证明分配失败
        printf("allocate failure");
    return head;//返回头指针
}
```

判断链表是否为空
----------
```c
int IsNull_Link(LinkList head)
{
    return(head->next==NULL);
}
```

头插法建立单链表
-----------
例如建立这样一个链表:<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnSingleLinkedList_C/InsertFromHead.png)<br>
1. 首先申请结点空间<br>
<code>p=malloc(sizeof(struct Node)) //申请的大小是struct Node这样的大小</code><br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnSingleLinkedList_C/NodeSpaceHead.png)<br>
2. 对数据域进行赋值<br>
<code>p->data = data;//后面的data即具体数值</code><br>
3. 对指针域进行赋值<br>
<code>p->next = head->next;<br>
4. 接下来修改头结点的指针域,因为插入了p这一新结点在最头部<br>
<code>head->next = p;</code><br>
<font color=pink>第三步和第四步不能交换,原因可以自己想想</font>
>[注]由此可见,头插法申请的链表,和我们输入的数据顺序正好相反,先输入哪个,它的位置就会越来越靠后

```c
void CreateList_Head(struct Node *head)//头插法建立单链表
{
    PNode p=NULL;//临时使用
    int data;
    printf("请输入整型数据建立链表,以-1结束\n");
    scanf("%d",&data);
    while(data!=-1)
    {
        p=(struct Node*)malloc(sizeof(struct Node));//分配空间
        p->data=data;//对数据域赋值
        p->next=head->next;//指针域赋值
        head->next=p;
        scanf("%d",&data);//再输入数据进行循环
    }
}
```

尾插法建立单链表
-------------
与头插法不同,尾插法是从最后开始插入的,例如插入这样一个链表:<br>
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnSingleLinkedList_C/InsertFromEnd.png)<br>
可见开始时有一个尾指针q指向终端结点,尾插法即从终端结点之后插入<br>
1. 首先申请结点空间<br>
<code>p = malloc(sizeof(struct Node))</code><br>
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/MyOwnSingleLinkedList_C/NodeSpaceEnd.png)<br>
2. 对数据域进行赋值<br>
<code>p->data=data;</code><br>
3. 对指针域进行赋值<br>
<code>p->next=NULL;</code><br>
4. 前一个结点指针域指向插入的结点<br>
<code>q->next=p;</code><br>
5. 尾指针指向终端结点,现在即为p<br>
<code>q=p;</code><br>
<font color=pink>第四步和第五步不能交换</font><br>
如果颠倒,<code>q->next=p;</code>会变成p自己指向自己

>[注]由此可见,尾插法申请的链表,和我们输入的数据顺序正好相同,先输入哪个,它的位置就会越来越靠前

```c
//因为是创建单链表,所以开始的头指针和尾指针是指向一个地方的
void CreateList_Tail(struct Node* head)//尾插法建立单链表,head也可以为end
{
    struct Node *p=NULL;
    struct Node *q=head;//头(尾)结点
    int data;
    printf("请输入整型数据建立链表,以-1结束\n");
    scanf("%d",&data);
    while(data!=-1)
    {
        p=(struct Node*)malloc(sizeof(struct Node));//分配空间
        p->data=data;//数据域赋值
        p->next=NULL;//指针域赋值
        q->next=p;
        q=p;
        scanf("%d",&data);//再输入数据进行循环
    }
}
```