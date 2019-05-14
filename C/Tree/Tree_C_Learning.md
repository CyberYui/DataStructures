关于树的相关知识<font color=brown>(C语言)</font>
=====
之前学习的都是线性结构,从本章开始都是非线性结构<br>
在树中,遍历以及递归的算法使用很广泛<br>
但在具体学习中,会使用非递归的实现来便于理解相应的递归算法(化简为繁--便于理解)<br>

二叉树是非线性结构,通过转化为线性结构从而简化问题<br>
此外,长子树转化为二叉树也是使用这种思想(化繁为简--简化结构)<br>

>本章中还会使用到栈和队列的内容<br>

二叉树的概念
---------
树是一种分层的结构,普通树可以有多个后继,但每个后继只能有一个前驱<br>

二叉树是每个结点最多有两个子树的树结构,或者说二叉树是结点的<font color=orange>有限集合</font>,这个集合或者为<font color=red>空集</font>,或者为一个称为<font color=red>根</font>和两棵不相交的分别为<font color=red>左子树(left subtree)</font>和<font color=red>右子树(right subtree)</font>的二叉树组成,其根的根也有相同的结构<br>

>从这个定义上看,二叉树是一种递归的定义:<br>
>即如果二叉树不为空,那么就是一个有左右子树的二叉树,而左右子树本身又遵循二叉树的结构

<font color=blue>[递归性]</font><br>
一棵二叉树由0,1,2棵子树构成,而子树又由更小的子树构成<br>
[注意]<font color=pink>树有层次关系,分之关系,但无环路的存在.</font><br>

二叉树的基本术语
----------
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG1.png)<br>
* 祖先,父结点,子结点,边
        在上图中,A是整个二叉树的祖先<br>
        父结点和子结点是相对的,例如A是B的父结点,B是A的子结点<br>
        A是B的父结点,A和B直接就是一条边<br>

* 兄弟结点
        在上图中,具有同一父母的结点是兄弟结点,例如B结点和C结点<br>

* 结点的度
        即该结点的孩子的个数,例如A结点的度为2,B结点的度为0<br>

* 树叶和分支结点
        一个结点的度为0,则是树叶结点(叶子结点)<br>
        一个结点的度不为0,则是分支结点<br>

* 路径,路径长度,内部路径长度
        路径指从根结点到一个子结点的路线<br>
        A是G的祖先,那么A->C->E->G就是一条路径,该路径长度为3,即边的个数<br>
        内部路径长度就是指所有结点的深度之和,比如上面的树深度为11<br>

* 结点的层数(这里约定根结点为0,有的会约定为1)
        即其他结点的层数为父结点的层数+1<br>

* 二叉树的高度(深度)
        在一个二叉树中结点的最大层数即是二叉树的深度<br>

特殊的二叉树
-------
1. 满二叉树<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG2.png)<br>
* 如果一个二叉树的除最后一层无任何子节点外,每一层上的所有结点都有两个子结点的二叉树,那么这个二叉树称为满二叉树<br>

2. 完全二叉树<br>
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG3.png)<br>
* 完全二叉树是由满二叉树而引出来的,对于深度为K的,有n个结点的二叉树,当且仅当其每一个结点都与深度为K的满二叉树中编号从1至n的结点壹壹对应时称之为完全二叉树<br>
* 即如果一棵二叉树<font color=green>只有最下面的两层结点的度小于2,其余各层结点的度都等于2</font>(即除了最后两层,其余层的结点必须满度),且最下面一层的结点都集中于左边,那么就称之为完全二叉树.(从上到下,从左到右)<br>

[注意]满二叉树不一定是完全二叉树;完全二叉树不一定是满二叉树
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG4.png)<br>

3. 扩充二叉树
* 对已有的二叉树进行扩充,使得扩充后的二叉树的结点都变为度为2的树,这样的树不一定是满二叉树,但一定不是完全二叉树.

* <font color=red>"外部路径长度"&nbsp;E</font>:在扩充的二叉树里从根到每个外部结点的路径长度之和,外部结点就是扩充的结点
* <font color=red>"内部路径长度"&nbsp;I</font>:在扩充的二叉树里从根到每个内部结点的路径长度之和,内部结点就是原有的结点

二叉树的性质
--------
1. 在非空二叉树的第i层上至多有2<sup>i</sup>个结点(i≥0)<br>
[例如]第0层,最多有2<sup>0</sup>=1个结点,第二层最多有2<sup>2</sup>=4个结点<br>

2. 深度为k的二叉树至多有2<sup>k+1</sup>-1个结点(k≥0)<br>
[推导]<font color=orange>M=∑m<sub>i</sub>≤∑2<sup>i</sup>=2<sup>0</sup>+2<sup>1</sup>+2<sup>2</sup>+...+2<sup>k</sup>=2<sup>k+1</sup>-1</font><br>
[例如]一个有4层的二叉树,第一层定为第0层,那么这个二叉树的深度为3,最多有2<sup>4</sup>-1=15个结点<br>

3. 对于任何一棵非空的二叉树T,如果叶结点数为n<sub>0</sub>,度为2的结点数为n<sub>2</sub>,则<font color=red>n<sub>0</sub>=n<sub>2</sub>+1</font><br>
[证明]一棵二叉树,最多一个结点也就只有三种度的情况,即0,1,2<br>
<1>首先求出二叉树的结点数之和,n=n<sub>0</sub>+n<sub>1</sub>+n<sub>2</sub><br>
<2>除根结点之外,每个结点都有父结点,设B为分支(边)总数,那么n=B+1<br>
<3>二叉树的分支总数都是由度为1和2的结点发出去的,所以B=n<sub>1</sub>+2*n<sub>2</sub><br>
<4>回代B,得到n<sub>0</sub>+n<sub>1</sub>+n<sub>2</sub>=n<sub>1</sub>+2*n<sub>2</sub>+1&nbsp;==>&nbsp;<font color=blue>n<sub>0</sub>=n<sub>2</sub>+1</font><br>
>[注]按照这一思想可以解决很多类似的问题

[思考]<br>
**A**.在一棵度数为4的树T中,若有20个度为4的结点,10个度为3的结点,1个度为2的结点,10个度为1的结点,则树T的树叶结点有多少个?<br>
n=n<sub>0</sub>+n<sub>1</sub>+n<sub>2</sub>+n<sub>3</sub>+n<sub>4</sub><br>
n=n<sub>0</sub>+10+1+10+20<br>
n=B+1<br>
B=n<sub>1</sub>+2*n<sub>2</sub>+3*n<sub>3</sub>+4*n<sub>4</sub><br>
B=10+2+30+80<br>
n<sub>0</sub>=122-41=81<br>

[归纳]
**B**.已知一棵度为m的树中有n<sub>1</sub>个度为1的结点,n<sub>2</sub>个度为2的结点,...,n<sub>m</sub>个度为m的结点,问该树有多少个叶子结点?<br>

n=n<sub>0</sub>+n<sub>1</sub>+n<sub>2</sub>+...+n<sub>m-1</sub>+n<sub>m</sub><br>
n=B+1=n<sub>1</sub>+2*n<sub>2</sub>+3*n<sub>3</sub>+...+m*n<sub>m</sub>+1<br>
联立可得n<sub>0</sub>=n<sub>2</sub>+2*n<sub>3</sub>+...+(m-1)n<sub>m</sub>+1<br>

完全二叉树的性质
--------
(1)叶子结点只可能在层次最大的两层上出现<br>
(2)对任一结点,若其右分支下的最大层次为m,则其左分支下的子孙的最大层次必为m或m+1<br>

4. **[针对完全二叉树]**<br>
具有n个结点的<font color=blue>完全二叉树</font>的深度k为<font color=red>└log<sub>2</sub>n┘</font><br>
>[注]└x┘是指对x下取整,例如若x=3.5,则上取整就是4,下取整就是3

[证明]<br>
深度为K的完全二叉树(从0开始算),则深度为K-1层是满的,深度为K-2层的结点是满度的<br>
从而有如下关系(m<sub>k</sub>指第k层的结点数,至少等于1):<br>
n=2<sup>0</sup>+2<sup>1</sup>+2<sup>2</sup>+...+2<sup>k-1</sup>+m<sub>k</sub>=2<sup>k</sup>-1+m<sub>k</sub><br>
2<sup>k</sup>-1<n≤2<sup>k+1</sup>-1(2<sup>k+1</sup>-1即k层也满)<br>
2<sup>k</sup>≤n<2<sup>k+1</sup><br>
k≤log<sub>2</sub>n<k+1<br>
k=└log<sub>2</sub>n┘<br>

5. **[针对完全二叉树]**<br>
**如果一棵有n个结点的<font color=blue>完全二叉树</font>按层次次序从0开始编号,则对任一结点i(0≤i≤n-1),有**:<br>
* i=0,序号节点i是根;i>0,其双亲结点是<font color=red>└(i-1)/2┘</font><br>
* 2i+1≤n-1,序号为i的结点的左子女结点的序号为<font color=red>2i+1</font><br>
2i+1>n-1,序号为i的结点无左子女<br>
* 2i+2≤n-1,序号为i的结点的右子女结点的序号为<font color=red>2i+2</font><br>
2i+2>n-1,序号为i的结点无右子女<br>

在下图中给出了一些例子:<br>
![F5](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG5.png)<br>

满二叉树的性质
----------
6. **[针对满二叉树]**<br>
在满二叉树中,叶结点的个数比分支结点个数多1<br>
根据性质3的<font color=red>n<sub>0</sub>=n<sub>2</sub>+1</font>可得<br>

扩充二叉树的性质
-----------
7. **[针对扩充二叉树]**<br>
在扩充二叉树中,外部结点的个数比内部结点的个数多1<br>
扩充二叉树中,外部结点都是度为0的结点,内部结点都是度为2的,即<font color=red>n<sub>0</sub>=n<sub>2</sub>+1</font><br>
扩充的二叉树是没满二叉树,所以根据性质6,其叶结点的个数比分支结点个数多1,即外部结点的个数比内部结点的个数多1<br>

[随堂作业]<br>
将一棵有100个结点的完全二叉树从上到下，从左到右依次进行编号，根结点的编号为0，则度为2的结点有(49)个<br>
[过程]<br>
n=100&nbsp;==>K=6&nbsp;<br>
那么该完全二叉树有6层,6层的树最多有2<sup>6+1</sup>-1=127个结点<br>
第6层最多有2<sup>6</sup>=64个结点<br>
因为只有100个结点,所以第6层有64-(127-100)=37个结点是存在的<br>
按从左往右排列,则第5层有┌37/2┐=19个结点有边<br>
第5层最多有2<sup>5</sup>=32个结点<br>
那么第5层度为0的结点数为32-19=13<br>
则该完全二叉树n<sub>0</sub>=37+13=50<br>
由<font color=red>n<sub>0</sub>=n<sub>2</sub>+1</font>可得n<sub>2</sub>=49<br>

二叉树的深度优先遍历
----------
[二叉树的遍历]<br>
* 沿某条搜索路径访问二叉树,对二叉树中的每个结点<font color=red>访问且仅访问一次</font>
>这样就将二叉树这样的非线性结构点线性化处理了

三种访问形式<br>
**1--**<font color=red>先根次序遍历二叉树DLR[前序遍历]</font><br>
若二叉树非空,则:<br>
1. 访问根结点<br>
2. <font color=red>先根次序遍历</font>左子树<br>
3. <font color=red>先根次序遍历</font>右子树<br>

**2--**<font color=green>对称次序遍历二叉树LDR[中序遍历]</font><br>
若二叉树非空,则:<br>
1. <font color=green>对称次序遍历</font>左子树<br>
2. 访问根结点<br>
3. <font color=green>对称次序遍历</font>右子树<br>

**2--**<font color=purple>后根次序遍历二叉树LRD[后序遍历]</font><br>
若二叉树非空,则:<br>
1. <font color=purple>后根次序遍历</font>左子树<br>
2. <font color=purple>后根次序遍历</font>右子树<br>
3. 访问根结点<br>

![F6](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG6.png)<br>

二叉树深度优先遍历的算法
---------
对于二叉树的遍历,有递归和非递归两种方式,递归的方式简单但较难理解<br>
非递归的方式需要使用到栈,并且有两种迭代的形式<br>

<font color=red>递归遍历算法--前序遍历DLR</font><br>
```c(伪)
//前序遍历二叉树
void PreOrder(BinTree t)
{
    //递归调用的结束条件
    if(t==NULL)
        return  //返回
    //遍历,遵循DLR的形式
    Visit(root(t))//非空则访问结点的数据域
    //递归调用
    PreOrder(LeftChild(t))//前序遍历t的左子树
    //左子树遍历完毕,调用右子树
    PreOrder(RightChild(t))
}
```

例如下图,展示了上一节的二叉树的前序遍历路径,其中紫色和黑色箭头表示访问,蓝色箭头表示返回<br>
![F7](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG7.png)<br>

<font color=green>递归遍历算法--中序遍历LDR</font><br>
```c(伪)
//中序遍历二叉树
void InOrder(BinTree t)
{
    //递归调用的结束条件
    if(t==NULL)
        return  //返回
    //递归调用,遵循LDR的形式
    InOrder(LeftChild(t))//中序遍历t的左子树
    Visit(root(t))//访问结点的数据域
    //左子树遍历完毕,调用右子树
    InOrder(RightChild(t))
}
```

<font color=purple>递归遍历算法--后序遍历LRD</font><br>
```c(伪)
//后序遍历二叉树
void PostOrder(BinTree t)
{
    //递归调用的结束条件
    if(t==NULL)
        return  //返回
    //递归调用,遵循LDR的形式
    PostOrder(LeftChild(t))//中序遍历t的左子树
    //左子树遍历完毕,调用右子树
    PostOrder(RightChild(t))
    Visit(root(t))//访问结点的数据域
}
```

>三种遍历算法,经过的路径相同,但是访问各个结点的时机不同

二叉树的广度优先遍历---层次遍历
----------
[二叉树的遍历]<br>
* 沿某条搜索路径访问二叉树,对二叉树中的每个结点<font color=red>访问且仅访问一次</font>
>这样就将二叉树这样的非线性结构点线性化处理了

二叉树的广度优先遍历(周游),是指<font color=red>从二叉树的第一层(根结点)开始,从上至下逐层遍历,在同一层中,则按照从左到右的顺序对结点逐个访问</font><br>
>具体可以用队列进行实现,之前的农夫问题就是一种广度优先遍历<br>

二叉树广度优先遍历的算法<br>
--------
```c(伪)
//使用队列层次遍历二叉树
void LevelOrder(BinTree bt)
{
    初始化队列 q;
    if (bt==NULL)
        return;  //返回
    bt入队q;
    while(队列不空)
    {
        出队元素p;
        visit(p);   //访问队头结点的数据域
        if (LeftChild(p) != NULL)
            LeftChild(p) 入队 q;    //左孩子不空,则入队
        if (RightChild(p) != NULL)
            RightChild(p) 入队 q;   //右孩子不空,则入队
    }
}
```

二叉树的重构:即由遍历序列恢复二叉树
----------
由二叉树的遍历知道,任意一棵二叉树结点的前序,中序和后序遍历都是唯一的.<br>
那么如果已知结点的前序,中序和后序遍历序列中的两项,能否确定二叉树呢?这样子的二叉树是否唯一呢?<br>
>显然是不一定能确定出唯一的二叉树的,主要在于先根序列和后根序列已知的情况有难度

[例如]先根序列:ABCDEFGHI&emsp;对称序列:BCAEDGHFI<br>
A必为祖先结点,且在中序遍历序列中,A将二叉树分为两部分,即BC位于左侧,EDGHFI位于右侧<br>
由对称序列的BC可知,B为根,C为右叶子结点<br>
以此类推,D必为右子树的祖先结点,E位于左侧,GHFI位于右侧<br>
接着,F必为右子树的右子树的祖先结点,GH位于左侧,I位于右侧<br>
由对称序列的GH可知,G为根,H为右叶子结点<br>
从而得到的二叉树为:<br>
![F8](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG8.png)<br>

[总结--二叉树重构方法]
* 在先根序列中,第一个结点一定是二叉树的根结点
* 根结点在对称序列中必然将对称序列分割为两个子序列,前一个子序列是左子树的对称序列,后一个子序列是右子树的对称序列
* 根据这两个子序列,在先根序列中找到对应的左子序列和右子序列.在先序序列中,左子序列的第一个结点是左子树的根结点,右子序列的第一个结点是右子树的根结点.如此便可确定一个子二叉树的三个结点
* 递归上述操作,从而重构出二叉树
>同样,已知后根序列和对称序列也能恢复重构

[注意]已知先根序列和后跟序列,<font color=red>对于一般的二叉树是无法恢复的</font>,但是对于一些特定的二叉树--满二叉树,也是能够重构的<br>
[例如]先根序列:ABDECFHIG&emsp;后根序列:DEBHIFGCA<br>
很明显可以确定祖先结点A,且B为A的左子树的根<br>
在后根序列中,紧跟着A的必定为A的右子树的根,即C<br>
以此类推,D为B的左子树,E为B的右子树,即BDE在A的左侧,CFHIG在A的右侧<br>
F为C的左子树的根,G为C的右子树的根<br>
H为F的左子树的根,I为F的右子树的根<br>
从而得到一个满二叉树<br>
[总结--仅针对满二叉树]
* 在先根序列中寻找左孩子结点
* 在后根序列中寻找右孩子结点

二叉树的交叉遍历
---------
观察以下代码,具体思考:<br>
* 什么时候调用进去<br>
* 什么时候调用返回<br>

```c(伪)
//PreOrder和InOrder调用的彼此,而不是递归调用自己
void PreOrder(BinTree t)
{
    if(t==NULL)
        return;
    printf("%c",t->info);
    InOrder(t->lchild);
    InOrder(t->rchild);
}
void InOrder(BinTree t)
{
    if(t==NULL)
        return;
    PreOrder(t->lchild);
    printf("%c",t->info);
    PreOrder(t->rchild);
}
//给出一个二叉树,思考这样产生的序列是什么样呢
void main()
{
    BinTree bt=NULL;
    bt=CreateBinTree();
    PreOrder(bt);
}
```

例如如下的二叉树,要使用上述代码交叉遍历<br>
![F9](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG9.png)<br>
其流程如下:<br>
```c(伪)
Preorder(bt)
访问1
Inorder(1->lchild)-->return
Inorder(1->rchild)-->2
    Preorder(2->lchild)
        访问3
        Inorder(3->lchild)-->return
        Inorder(3->rchild)-->4
            Preorder(4->lchild)
                访问5
                Inorder(5->lchild)-->return
                Inorder(5->rchild)-->return
            访问4
            Preorder(4->rchild)-->return
    访问2
    Preorder(2->rchild)-->return
//遍历完毕
```

二叉树的存储
---------
二叉树的存储形式有三种:<br>
<1>顺序存储&emsp;&emsp;<2>链式存储&emsp;&emsp;<3>线索二叉树

二叉树的顺序存储
---------
即用一组地址连续的存储单元按层次次序依次存储的结点<br>

完全二叉树适合用顺序存储表示,如以下二叉树可以用下表显示的顺序存储方式存储:<br>
![F10](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG10.png)<br>

|      | A | B | C | D | E | F | G | H | I | J |
|------|---|---|---|---|---|---|---|---|---|---|
| 下标 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |

[为什么说完全二叉树采用顺序存储比较合适呢?]<br>
* 依据完全二叉树的性质,结点的序号可以唯一地反映出结点之间的逻辑关系
[优点:]<br>
* 能够最大可能地节省存储空间
* 利用数组元素的下标值确定结点在二叉树中的位置(之前有提过计算方式)
* 利用数组元素的下标值确定结点之间的关系

[一般二叉树及其顺序表示]<br>
* 对于一般二叉树,数组元素下标之间的关系不能反应结点之间的逻辑关系
* 可以将其改造成完全二叉树(增加不存在的结点),然后用一维数组存储
如下图所示:<br>
![F11](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG11.png)<br>
>显然,对于一般的二叉树,使用链式存储的方式更为合适

二叉树的链式存储
-------
链式存储是对二叉树最常用的一种存储方式

在二叉树的链式存储中,一个结点由三部分构成:leftchild&nbsp;+&nbsp;data&nbsp;+&nbsp;rightchild
* 一个二叉链表由头指针唯一确定
* 若二叉树为空,则bt=NULL
* 若结点的某个孩子不存在,则相应的指针为空
```c
typedef char DataType;//可以用整形定义
typedef struct BTreeNode
{
    DataType data;
    struct BTreeNode *leftchild;
    struct BTreeNode *rightchild;
}BinTreeNode;
typedef BinTreeNode *BinTree;
```
<font color=red>优点</font>:二叉链表结构灵活,操作方便<br>
<font color=red>缺点</font>:在二叉链表中无法由结点直接找到其双亲<br>
* 具有n个结点的二叉树中,一共有<font color=red>2n</font>个指针域,其中只有<font color=red>n-1</font>个用来指示结点的左,右孩子,其余的<font color=red>n+1</font>个指针域为空<br>
[思考]如何利用这些空的指针域呢?<br>---<font color=red>线索二叉树</font>

可以使用三叉链表改进,从而建立二叉树
即一个结点由三部分构成:leftchild&nbsp;+&nbsp;data&nbsp;+&nbsp;rightchild&nbsp;+&nbsp;parent
* 每个结点由四个域组成,parent域为指向该结点双亲结点的指针
* 既便于查找孩子结点,又便于查找双亲结点
* 相对于二叉链表存储结构而言,它增加了空间的开销
>综上,我们一般使用二叉链表建立二叉树,除非对父结点的访问十分频繁,才会建立三叉链表

递归建立二叉树---按照先根序列
--------
```c
TreeNode *CreateBinTree()
{
    char ch;
    BinTreeNode *BT=NULL;
    scanf("%c",&ch);
    if(ch=='@')
    {
        BT=NULL;
    }
    else
    {
        BT=(BinTreeNode *)malloc(sizeof(BinTreeNode));
        BT->info=ch;
        BT->lchild=CreateBinTree();//构建左子树
        BT->rchild=CreateBinTree();//构建右子树
    }
    return BT;
}
```
>具体的代码实现参见BinTree项目

二叉树的建立和遍历---非递归算法
----------
使用非递归的形式建立二叉树,需要使用到队列以及完全二叉树的相关知识<br>
我们知道在对完全二叉树结点编号之后,每个子二叉树有这样的关系:<br>
![F12](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG12.png)<br>
<br>
在本例中,我们的输入序列是<font color=red>ABC@DE@@@@F#</font><br>
[程序设计]<br>
(1)将二叉树用@扩充为完全二叉树,输入<font color=blue>完全二叉树序列</font>,以#作为结束的标志,设置计数器count为-1,用于标识结点的序号.<br>
(2)如果输入的不是@,则产生一个新结点s,并对结点的数据域赋值为输入的字符,结点的左右指针赋值为空,然后结点s入队,<font color=green>计数器count+1</font><br>
(3)如果计数器<font color=darred>count等于0</font>,这个结点就是根结点,设置二叉树的根<font color=darred>bt=s</font><br>
&emsp;如果计数器count是<font color=purple>奇数</font>,则是父结点p(队头结点)的左孩子,即<font color=purple>p->leftchild=s</font><br>
&emsp;&emsp;如果计数器count是<font color=green>偶数</font>,<br>
&emsp;&emsp;&emsp;父结点p(队头结点)的右孩子,即<font color=green>p->rightchild=s</font><br>
&emsp;&emsp;&emsp;<font color=pink>队头结点的左右孩子已经处理完毕,出队</font><br>

>很明显,在真正入队时,并不是入ABCD@,入队的是结点,且结点是有指针域的<br>
>具体代码实现参见BinTree_NonRecursion项目

二叉树的先根遍历---非递归遍历方式
----------
**[迭代 1]先序遍历的非递归实现**<br>
仔细观察,和之前的层级遍历的非递归算法很类似,但之前用的可是队列<br>

```c
//先序遍历的非递归实现,迭代1
void PreOrder_NRecursion1(BinTree bt)
{
    LinkStack lstack;   //定义链栈
    lstack = SetNullStack_Link();   //初始化栈
    BinTreeNode *p;
    Push_Link(lstack,bt);   //根结点入栈
    //循环表现了递归的具体实现内容,这里也能看到指针的妙用
    while(!IsNullStack_Link(lstack))
    {
        p = Pop_seq_return(lstack);
        Pop_Link(lstack);
        printf("%c",p->data);   //访问结点
        //因为是栈,是后进先出,所以先进右孩子,后进左孩子
        if(p->rightchild)
            Push_Link(lstack,p->rightchild);    //右子树不空,进栈
        if(p->leftchild)
            Push_Link(lstack,p->leftchild);     //左子树不空,进栈
    }
}
```

即根结点首先入栈,然后进入循环<br>
栈顶结点(根结点)出栈,并被访问<br>
根结点的右孩子进栈,然后左孩子进栈<br>
进入第二轮循环<br>
栈顶结点(根结点的左孩子)出栈,并被访问<br>
根结点的左孩子的右孩子进栈,然后根结点的左孩子的左孩子进栈<br>
...(如此循环)<br>
当访问至叶子结点,判断栈非空<br>
则栈顶结点(上一个结点的右孩子)出栈<br>
...(以此类推)<br>
[结束条件]栈空<br>
<br>

**[迭代 2]先序遍历的非递归实现**<br>
对于迭代一中,每次左孩子都要先入栈,称为栈顶<br>
然后再被取出来访问,能否直接访问,不用入栈这样的操作呢?<br>
--这就是迭代&nbsp;2的思路了<br>

```c
//先序遍历的非递归实现,迭代2
void PreOrder_NRecursion2(BinTree bt)
{
    LinkStack lstack;   //定义链栈
    BinTreeNode *p = bt;
    lstack = SetNullStack_Link();   //初始化栈
    if(bt == NULL)
        return;
    Push_Link(lstack,bt);
    //如果栈不空,则循环访问栈
    while(!IsNullStack_Link(lstack))
    {
        //取栈顶结点,然后访问
        p = Pop_seq_return(lstack);
        Pop_Link(lstack);   //出栈
        while(p)
        {
            printf("%c",p->data);   //访问结点
            if(p->rightchild)
                //若右孩子为空,则不进栈
                Push_Link(lstack,p->rightchild); //右孩子进栈
            p = p->leftchild;
        }
    }
}
```

即首先直接访问根结点,然后其右孩子进栈<br>
接着,直接访问左孩子,然后左孩子的右孩子进栈<br>
...(如此循环)<br>
当访问至叶子结点,判断栈非空<br>
则取栈顶结点(上一个结点的右孩子)出栈<br>
...(以此类推)<br>
[结束条件]栈空<br>
<br>
[思考]迭代1和迭代2对于同一个二叉树,其栈的不同在哪里?<br>
例如下面的二叉树:<br>
![F13](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG13.png)<br>
<br>
[迭代 1]<br>
![F14](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG14.png)<br>
<br>
[迭代 2]<br>
![F15](https://github.com/CyberYui/DataStructures/blob/master/C/Tree/BinaryTreeG15.png)<br>


二叉树的对称遍历---非递归遍历方式
----------
先序遍历是---根左右
对称遍历是---左根右
那么也就是说要先从左边到底才开始访问,刚刚好可以利用栈的后进先出的特性

**对称遍历的非递归实现**<br>
中序遍历只有一种非递归实现的迭代方式<br>
```c
//中序遍历非递归实现
void InOrder_NRecursion1(BinTree bt)
{
    LinkStack lstack;   //定义链栈
    lstack = SetNullStack_Link();   //初始化栈
    BinTree p;
    p = bt;
    if(p == NULL)
        return;
    Push_Link(lstack,bt);   //根结点入栈
    //一直寻找左子树,直到底才开始
    p = p->leftchild;   //进入左子树
    //只要p或者栈非空,就迭代
    while(p || !IsNullStack_Link(lstack))
    {
        //p不为空,一直找左子树,并进栈左孩子
        while(p != NULL)
        {
            Push_Link(lstack,p);
            p = p->leftchild;
        }
        //找到底的时候开始出栈,出栈一个左孩子就扫描右孩子
        p = Pop_seq_return(lstack);
        Pop_Link(lstack);
        printf("%c",p->data);   //访问结点
        p = p->rightchild;  //右子树非空,扫描右子树
        //循环寻找右子树的左子树
    }
    //结束条件:栈空
}//算法时间复杂度O(n)
```

二叉树的后序遍历---非递归遍历方式
----------
后序遍历也是要先从左边到底才开始访问,之后访问右孩子,最后才访问一个二叉树的根结点
实际中,就是一个叶子结点从左返回,从右返回,然后访问自己
回到二叉树时就是左叶子已经访问过自己,右叶子也已访问过自己,根结点只需要访问自己就好
刚刚好可以利用栈的后进先出的特性

**后序遍历的非递归实现**<br>
```c
//后序遍历的非递归实现
void PostOrder_NRecursion(BinTree bt)
{
    BinTree p = bt;
    LinkStack lstack;   //定义链栈
    //二叉树为空,直接返回
    if(bt == NULL)
        return;
    lstack = SetNullStack_Link();   //初始化栈
    //p非空或者栈非空,开始循环
    while(p != NULL || !IsNullStack_Link(lstack))
    {
        //如果p不空,就一直找下去
        while(p!=NULL)
        {
            Push_Link(lstack,p);
            p = p->leftchild ? p->leftchild : p->rightchild;    //左子树有就压左,否则压右进栈
        }
        //空表示为叶子结点,左右都没有
        p = Pop_seq_return(lstack);   //栈顶出栈
        Pop_Link(lstack);
        printf("%c",p->data);   //访问结点
        //如果栈非空且栈顶结点的左孩子是刚刚出栈的结点
        if(!IsNullStack_Link(lstack) && (Pop_seq_return(lstack)->leftchild == p))
            //因为是左,所以还要看右边的
            p = (Pop_seq_return(lstack))->rightchild; //从左子树退回,进入右子树
        else
            p = NULL;   //从右子树退回,返回上一层
    }//循环结束条件:栈空或p空
}
```

>二叉树各种遍历的非递归实现参照BinTree_NewNonRecursion项目