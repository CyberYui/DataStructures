单链表的改进和扩充:循环链表
-----------
对于单链表来说,要想操作,必须从头结点开始,顺着链表进行操作<br>
明显的缺点是,已知一个结点,仅能访问其后继结点,无法访问其前驱结点<br>
改进的方式有两种:<br>
* 改造为循环链表
* 改造为双链表

循环链表与单链表的不同:<br>
循环链表其最后一个结点的指针域指回第一个结点<br>

实际中多采用<font color=red>尾指针(rear)</font>表示单循环链表<br>
例如下图这样:<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/TailPointerREAR.png)<br>

<font color=purple>例:将两个线性表(a<sub>1</sub>,a<sub>2</sub>,...,a<sub>n</sub>)和(b<sub>1</sub>,b<sub>2</sub>,...,b<sub>m</sub>)链接成一个线性表(a<sub>1</sub>,a<sub>2</sub>,...,a<sub>n</sub>,b<sub>1</sub>,b<sub>2</sub>,...,b<sub>m</sub>),两个线性表都用下图的循环链表表示,其中r<sub>a</sub>为第一个线性表的尾指针,r<sub>b</sub>为第二个线性表的尾指针.</font><br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/LineList/MyOwnSingleLinkedList_C/ExampleGraph1.png)<br>
<font color=blue>[分析]:a<sub>n</sub>的后继是b<sub>1</sub>,b<sub>m</sub>的后继是a<sub>1</sub></font><br>
1. <font color=blue>p=ra->next;//指针指向第一个链表的头结点,即尾指针的next</font>
2. <font color=blue>ra->next=rb->next->next;//链接两个线性表,第二个链表的头结点可以去除了,因为没有意义</font>
3. <font color=blue>free(rb->next);//释放第二个链表的头结点</font>
4. <font color=blue>rb->next=p;//第二个链表的终端结点指针域指向第一个链表的头结点,链表连接成功</font>
><font color=pink>[注]第一步不能省去,因为需要p来指定头结点,否则执行完二三步之后第一个链表的头结点无法表示
</font>

两个单循环链表合并算法
----------------
```c
//创建单循环链表
CLinkList createListRearCircle()
{
    //具体自行百度...
}

LinkList Combine(LinkList ra,LinkList rb)
{
    //由于ra带有头结点,所以从ra的next开始
    LinkList p=ra->next;
    //ra的尾部链接rb的除去头结点的第一个结点
    ra->next=rb->next->next;
    //释放rb链表的头结点
    free(rb->next);
    //rb的尾部链接ra的头结点
    rb->next=p;
    return rb;
}
```