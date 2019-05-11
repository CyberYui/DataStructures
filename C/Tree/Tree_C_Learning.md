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

二叉树的遍历
----------
