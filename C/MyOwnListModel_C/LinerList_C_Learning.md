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

<code>typedef int DataType;<br></code>
<code>struct List<br></code>
<code>{<br></code>
<code>　　int Max;//最大元素个数<br></code>
<code>　　int n;//实际元素个数<br></code>
<code>　　DataType *elem;//首地址<br></code>
<code>};<br></code>
<code>typedef struct List *SeqList;<br></code>
<code>//顺序表类型定义<br></code>
<br>

>链表

<code>typedef int DataType;<br></code>
<code>struct Node<br></code>
<code>{<br></code>
<code>　　DataType data;//数据域<br></code>
<code>　　struct Node* next;//指针域<br></code>
<code>}<br></code>
<code>typedef struct Node *PNode;<br></code>
<code>//结点类型定义<br></code>
<code>typedef struct Node *LinkList;<br></code>
<code>//单链表类型定义<br></code>
<br>

********************************