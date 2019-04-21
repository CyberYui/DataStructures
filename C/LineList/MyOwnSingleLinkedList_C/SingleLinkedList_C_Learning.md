关于单链表的相关知识<font color=brown>(C语言)</font>
================
&emsp;&emsp;单链表是一种链式存取的数据结构,不同于顺序表,单链表使用一组地址任意的存储单元存放线性表中的数据元素.<br>
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
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/InsertFromHead.png)<br>
1. 首先申请结点空间<br>
<code>p=malloc(sizeof(struct Node)) //申请的大小是struct Node这样的大小</code><br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/NodeSpaceHead.png)<br>
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
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/InsertFromEnd.png)<br>
可见开始时有一个尾指针q指向终端结点,尾插法即从终端结点之后插入<br>
1. 首先申请结点空间<br>
<code>p = malloc(sizeof(struct Node))</code><br>
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/NodeSpaceEnd.png)<br>
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

单链表的查找:按值查找
--------------
&emsp;&emsp;按值查找是在链表中查找是否有结点值等于<font color=red>给定值x</font>的结点,若有的话,则返回首次找到的其值为x的结点的<font color=red>存储位置</font>;否则返回<font color=red>NULL</font>.<br>
&emsp;&emsp;查找过程从<font color=purple>开始结点</font><code>p=head->next</code>出发,<font color=orange>顺着链</font><code>p=p->next</code>逐个将结点的值与给定值x作<font color=green>比较</font><code>p->data == x</code>.<br>

```c
//在linkedlist链表中查找值为x的结点,并返回在内存中的位置
//传入单链表和要查找的值,返回的类型为PNode
PNode Locate_LinkTValue(LinkList linkedlist,DataType x)
{
    PNode p;
    if(linkedlist==NULL)
        return NULL;
    p=linkedlist->next;
    //核心语句
    while(p!=NULL && p->data!=x)
        p=p->next;
    //不论是否找到,都能返回p
    return p;
}
```

单链表的查找:按序号查找
------------
&emsp;&emsp;按序号查找是在链表中查找<font color=red>第i个</font>结点,若有的话,则返回该结点的<font color=red>存储位置</font>;否则返回<font color=red>NULL</font><br>
&emsp;&emsp;查找过程从<font color=purple>开始结点</font><code>p=head->next</code>出发,<font color=orange>顺着链</font><code>p=p->next;</code><code>count++</code>逐个计数和给定值i作<font color=green>比较</font><code>count==i</code>.<br>

```c
PNode Locate_LinkTNo(LinkList linkedlist,DataType i)
{
    PNode p;
    int count=1;//头结点无内容,必定会跳过头结点,故从1开始算
    if(linkedlist==NULL)
        return NULL;
    p=linkedlist->next;//count从1开始算,这里不用加1
    //核心语句
    while(p!=NULL && count!=i)
    {
        p=p->next;
        count++;
    }
    //返回p
    return p;
}
```

单链表的插入:后插法
------------
例如建立这样一个链表:<br>
![F5](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/InsertFromEnd2.png)<br>
1. 首先申请结点空间<br>
<code>q = malloc(sizeof(struct Node))</code><br>
![F6](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/NodeInsertEnd.png)<br>
2. 对数据域进行赋值<br>
<code>q->data=data;</code><br>
3. 对指针域进行赋值<br>
<code>q->next=p->next;</code><br>
4. 新结点作为p的后继被插入<br>
<code>p->next=q</code><br>
<font color=pink>第三步和第四步不能交换</font><br>

```c
//在linkedlist链表中的p位置之后插入值为x的结点
//传入链表,新结点q插入在哪个结点p后,结点数据域
int InsertPost_link(LinkList linkedlist,PNode p,DataType x)
{
    PNode q;//
    if(p==NULL)
    {
        printf("out of space!\n");
        return 0;
    }
    else
    {
        q->data=x;
        q->next=p->next;
        p->next=q;
        return 1;
    }
}//算法时间复杂度O(1)
```

单链表的插入:前插法
---------------
与后插法不同,要在一个结点p之前插入结点,要知道其前驱结点pre的情况<br>
例如建立这样一个链表:<br>
![F7](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/InsertFromHead2.png)<br>
1. 首先申请结点空间<br>
<code>q = malloc(sizeof(struct Node))</code><br>
![F8](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/NodeInsertHead.png)<br>
2. 对数据域进行赋值<br>
<code>q->data=data;</code><br>
3. 对指针域进行赋值<br>
<code>q->next=p;</code><br>
4. 新结点作为pre的后继被插入<br>
<code>pre->next=q</code><br>
<font color=pink>第三步和第四步能交换,因为指针的指向并不会互相影响</font><br>
```c
int InsertPre_link(LinkList linkedlist,PNode p,DataType x)
{
    //在linkedlist链表中的p位置之前插入值为x的结点
    PNode pre=linkedlist;
    PNode q=NULL;
    if(p==NULL)
    {
        printf("para failure!\n");
        return 0;
    }
    //主要消耗时间在while循环中
    while(pre->next != p)
    {
        //定位p的前驱结点
        pre = pre->next;
    }
    q=(PNode)malloc(sizeof(struct Node));
    q->data=x;
    q->next=p;
    pre->next=q;
    return 1;
}//算法时间复杂度O(n)
```
>插入的两种算法相比,如果能做后插法,尽量使用后插法,因为时间复杂度较低

单链表的倒置
-----------
依次取出原链表中的每一个结点,然后将其作为第一个结点插入新链表中<br>
当取到了终端结点时,其特征为指针域为空<br>
```c
void reverse(LinkList linkedlist)
{
    PNode p,q;
    p=head->next;//p指向第一个数据结点
    head->next=NULL;//将原链表置空
    //只要p结点的指针域不为空,则一直进行循环
    while(p)
    {
        q=p;//保存当前结点
        p=p->next;//p继续指向下一个结点
        q->next=head->next;//将当前结点插入到头结点的后面
        head->next=q;
    }
}
```


单链表的删除:删除r结点的后继
------------
例如有这样一个链表,要删除r结点的后继结点:<br>
![F9](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/DeleteTheNext.png)<br>
1. 首先提取出后继结点<br>
<code>p=r->next;</code><br>
2. p的后继变成r的后继<br>
<code>r->next=p->next;</code>
3. 释放提取出的结点<br>
<code>free(p);</code>
```c
//删除r指针所指结点的后继结点
void DelPostlonNext_Link(LinkList head,PNode r)
{
    PNode p;
    if(r->next)
    {
        p=r->next;
        r->next=p->next;
    }
    free(p);
}
```

单链表的删除:删除r结点本身
--------------
与删除后继不同,这种方式要寻找r结点的前驱结点<br>
例如有这样的一个链表,要删除r结点:<br>
![F10](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/DeleteRSelf.png)<br>
1. 找到前驱结点,并提取出r结点<br>
<code>pre->next=r->next;</code><br>
2. 释放r结点<br>
<code>free(r);</code><br>
```c
//删除r指针所指结点
void DelPostlon_Link(LinkList head,PNode r)
{
    PNode pre=head;
    while(pre->next!=r)
    {
        //定位r的前驱结点
        pre=pre->next;
    }
    pre->next=r->next;
    free(r);
}
```

单链表的删除:按值删除结点
---------------
[注]以下给出一个较为直接的方法,可以通过调用之前的查找函数进行删除操作<br>
```c
void DelValue_Link(struct Node *head,int data)
{
    //删除第一个与输入参数data相等的值的结点
    struct Node* p=head->next;
    struct Node* beforeP=head;
    while(p!=NULL)
    {
        if(p->data==data)
        {
            //找到值相同的结点,并删除结点
            beforeP->next=p->next;
            free(p);
            break;
        }
        else
        {
            //否则继续向后移动查找
            beforeP=p;
            p=p->next;
        }
    }
}
```

单链表的删除:删除一个单链表的重复结点
-----------------
从开头开始进行对比,找到与其值相同的结点就删除,以此类推,最后只会剩下一个该值结点<br>
```c
void pur_LinkList(LinkList linkedlist)
{
    PNode p,q,s;
    p=head->next;//p指向第一个结点
    if(p==NULL)
        return;
    while(p->next)
    {
        s=p;
        q=p->next;
        while(q)
        {
            //从p的后继开始寻找与p值相同的结点
            if(q->data==p->data)
            {
                //找到重复结点,删除
                s->next=q->next;
                free(q);
                q=s->next;
            }
            else
            {
                s=q;
                q=q->next;
            }
            //删除一种,继续进行下一种
            p=p->next;
        }
    }
}
```

>关于循环链表见同目录下的另两个markdown文件