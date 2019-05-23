图(Graph)
=======
[关键词]遍历+应用<br>
* 图是最复杂的一种数据结构,也是应用最为广泛的一种数据结构<br>
* 图中的任何两个结点间都可能有关系,之前的队列,栈,树可以看做是图的一部分<br>

|综合应用|中国邮递员问题|
|:-----:|:-----:|
|应用|最小生成树,最短路径,<br>拓扑排序,关键路径|
|存储表示|邻接矩阵;邻接表|
|遍历|深度遍历;广度遍历|
>遍历是图的基本操作

图的概念
=======
&emsp;&emsp;图(Graph)是一种复杂的非线性结构,在图结构中,对结点(称为顶点,Vertex)的前驱和后继个数是不加限制的,图中任意两个顶点之间都可能相关<br>
&emsp;&emsp;图G由两个集合V(G)和E(G)所组成,记作:<font color=red>G=(V,E)</font><br>

无向图和有向图
-------
无向图:图中每条边都是<font color=blue>没有方向的</font><br>
&emsp;&emsp;用圆括号表示:<font color=green>(V<sub>i</sub>,V<sub>j</sub>)</font>---<font color=brown>邻接顶点(相邻结点)</font><br>
<br>
有向图:图中每条边都是<font color=blue>有方向的</font><br>
&emsp;&emsp;用尖括号表示:<font color=green><V<sub>i</sub>,V<sub>j</sub>></font>---[类似向量]<font color=brown>V<sub>i</sub>代表起点,V<sub>j</sub>代表终点</font><br>

完全图
---------
[注]n---顶点数,e---边数<br>
若G是一个无向图,则<font color=blue>0 ≤ e ≤ n(n-1)/2</font>恰好有<font color=blue>n(n-1)/2</font>条边的无向图称为<font color=orange>无向完全图</font>(即满连线)[C<sub>n</sub><sup>2</sup>]<br>
<br>
若G是一个有向图,则<font color=blue>0 ≤ e ≤ n(n-1)</font>恰好有<font color=blue>n(n-1)</font>条弧的有向图称为<font color=orange>有向完全图</font>(即满连线,由于有方向,则A-->B和B-->A是两条线)[P<sub>n</sub><sup>2</sup>]<br>
>显然,完全图具有最多的边数<br>

度
-----
<font color=green>度</font>:无向图中顶点v的度是关联与该顶点的边的数目,记为D(v)<br>
<font color=green>入度</font>:有向图中<font color=red>以顶点v为终点的边</font>的数目称为v的入度,记为ID(v)<br>
<font color=green>出度</font>:有向图中<font color=red>以顶点v为起点的边</font>的数目称为v的出度,记为OD(v)<br>

有向图中顶点V的度定义为该顶点的入度和出度之和,即<font color=blue>D(v)=ID(v)+OD(v)</font><br>
[注]无论是有向图还是无向图,顶点数n,边数e和度数之间都有如下的关系:<br>

![F1](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic1.png)<br>

>即边数等于所有顶点的度数之和除以2

子图
------
设G=(V,E)是一个图,若V'是V的子集,E'是E的子集,则G'=(V',E')也是一个图,并称其为<font color=brown>G的子图</font><br>

简单路径和简单回路
---------
&emsp;&emsp;邻接顶点构成的序列(v<sub>i0</sub>,<font color=green>v<sub>i1</sub></font>)(<font color=green>v<sub>i1</sub></font>,v<sub>i2</sub>)...(v<sub>in-1</sub>,v<sub>in</sub>),称为从v<sub>i0</sub>到v<sub>in</sub>的一条<font color=green>路径</font><br>
&emsp;&emsp;若一条路径上除了v<sub>i0</sub>和v<sub>in</sub>可以相同外,其余顶点均不相同,则称此路径为一条<font color=blue>简单路径</font><br>
&emsp;&emsp;起点和终点相同(v<sub>i0</sub>,v<sub>in</sub>)的简单路径称为<font color=orange>简单回路或简单环</font><br>
比如下面的图:<br>

![F2](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic2.png)<br>

>A B D C--简单路径<br>
><font color=green>A</font> B D <font color=green>A</font> C---非简单路径<br>
><font color=green>A</font> B D <font color=green>A</font>---简单回路<br>

连通图和连通分量
---------
&emsp;&emsp;在无向图G中,若从顶点v<sub>i</sub>到顶点v<sub>j</sub>有路径,则称v<sub>i</sub>和v<sub>j</sub>是<font color=blue>连通的</font><br>
&emsp;&emsp;若V(G)中任意两个不同的顶点v<sub>i</sub>和v<sub>j</sub>都连通(即有路径),则称G为<font color=blue>连通图</font><br>
无向图G的极大连通子图称为G的<font color=blue>连通分量</font>(连通分量是定义在非连通图中的)<br>

在有向图G中,若对于V(G)中任意两个不同的顶点v<sub>i</sub>和v<sub>j</sub>,都存在从v<sub>i</sub>到v<sub>j</sub>和从v<sub>j</sub>到v<sub>i</sub>的路径,则称G是<font color=blue>强连通图</font>;有向图G的极大强连通子图称为G的<font color=blue>强连通分量</font><br>

![F3](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic3.png)<br>

>强连通图只有一个强连通分量,就是其自身;<br>
>非强连通图有多个连通分量.<br>

图的存储表示
=========
* <font color=orange>邻接矩阵表示法</font><br>
* <font color=orange>邻接表表示法</font><br>
* 邻接多重表表示法*<br>
* 图的十字链表*<br>

邻接矩阵表示法
--------
邻接矩阵是表示顶点之间邻接关系的矩阵<br>
<br>
设G=(V,E)是具有n个顶点的图,则G的邻接矩阵是具有如下性质的n阶方阵:<br>

![F4](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic4.png)<br>
<br>

[无向图的邻接矩阵表示]<br>

![F5](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic5.png)<br>
<br>
<font color=purple>**无向图邻接矩阵特点**</font><br>
* 无向图的邻接矩阵是对称的,因此可以只存储下三角或上三角的信息<br>
* 由其邻接矩阵可以断定图有几个顶点,判定任意两个顶点之间是否有边,并容易求得各个顶点的度.即:对于无向图或无向网络,顶点v<sub>i</sub>的度D(v<sub>i</sub>)就是其邻接矩阵第i行或第i列的元素之和.<br>

[有向图的邻接矩阵表示]<br>

![F6](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic6.png)<br>
<br>
<font color=purple>**有向图邻接矩阵特点**</font><br>
* 有向图的邻接矩阵不一定是对称的,但<font color=blue>完全有向图</font>或<font color=blue>完全有向网格</font>的邻接矩阵是对称的<br>
* 由其邻接矩阵很容易判定图的顶点数,顶点之间是否邻接和顶点的入度和出度<br>
+ 顶点的v<sub>i</sub><font color=green>出度OD(v<sub>i</sub>)</font>就是其邻接矩阵<font color=green>第i</font><font color=red>行</font><font color=green>元素个数之和</font><br>
+ 顶点的v<sub>i</sub><font color=orange>入度ID(v<sub>i</sub>)</font>就是其邻接矩阵<font color=orange>第i</font><font color=red>列</font><font color=orange>元素个数之和</font><br>

邻接表表示法
----------
* 无向图的邻接表表示法中,需要有两个部分:<br>
* (1)<font color=green>顺序表</font>:存储图中的n个顶点<br>
* (2)<font color=green>链表(邻接表)</font>:是一个单链表,存储和该顶点相邻的所有顶点.表中的每个结点包括:<font color=blue>顶点域和指针域</font><br>

![F7](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic7.png)<br>
<br>

* 对于有向图,邻接表表示可以有两种形式:<font color=brown>邻接表</font>和<font color=brown>逆邻接表</font>,邻接表即是以A为起点的相关弧组成的表,逆邻接表即以A为终点的相关弧组成的表<br>
<br>
* 由图的邻接表很容易确定图的顶点数,一个顶点与哪几个顶点有弧相连以及弧的方向<br>
* 在图的邻接表中,任一个顶点的出度OD(v<sub>i</sub>)正好就是第i个顶点出边表中结点的个数<br>
* 在图的逆邻接表中,任一个顶点的入度ID(v<sub>i</sub>)正好就是第i个顶点入边表中结点的个数<br>

![F8](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic8.png)<br>
<br>

两种表示方法的比较
---------
[空间开销]<br>
无论有向图还是无向图,其<font color=brown>邻接矩阵</font>表示的空间代价都是<font color=red>O(n<sup>2</sup>)</font><br>
* 如果G为无向图,其<font color=green>邻接表</font>的空间代价为<font color=red>O(n+2e)</font><br>
* 如果G为有向图,其<font color=green>邻接表</font>的空间代价为<font color=red>O(n+e)</font><br>
<font color=blue>邻接矩阵只与顶点数有关;邻接表与顶点数和边数有关.</font><br>
如果e远小于n<sup>2</sup>,采用邻接表较为节省空间开销.<br>
如果e接近n<sup>2</sup>,采用邻接矩阵更省空间(因为邻接表中要有指针域的开销).<br>

[操作的实现]
对于无向图来说:
* 判断两个顶点之间是否有边相连
        对于邻接矩阵来说,就看对应的矩阵中的一项是否为1即可
        对于邻接表来说,需要遍历整个链表(较为复杂)
* 求顶点的度
        对于邻接矩阵来说,看对应的一行中1的个数即可
        对于邻接表来说,需要遍历链表,并配有计数器(较为复杂)
>如果是有向图,则既有邻接表还有逆邻接表,空间开销较大

图的相关代码实现
=========

图的类型定义
------
```c
typedef struct GRAPHMATRIX_STRU
{
    int size;       //图中结点的个数
    int **graph;    //二维数组保存图
}GraphMatrix;
```

初始化一个图(邻接矩阵)
----------
```c
//邻接矩阵初始化图,num即顶点个数,返回结构体指针类型
//常量INT_MAX和INT_MIN分别表示最大和最小整数
GraphMatrix* InitGraph(int num)
{
    int i = 0;
    int j = 0;
    GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
    graphMatrix->size = num;    //图中结点的个数

    //给图分配空间
    graphMatrix->graph = (int**)malloc(sizeof(int*)*graphMatrix->size); //申请一维数组空间
    //这里循环申请的空间才是存放邻接矩阵的空间
    for(i=0;i<graphMatrix->size;i++)
        graphMatrix->graph[i] = (int*)malloc(sizeof(int)*graphMatrix->size);
    
    //给图中所有元素设置初值
    for(i=0;i<graphMatrix->size;i++)
    {
        for(j=0;j<graphMatrix->size;i++)
            graphMatrix->graph[i][j]=INT_MAX;   //初始设置所有顶点不邻接
    }
    return graphMatrix;
}
```
在申请二维数组空间时,实际的情况是:<br>
首先创建好图的类型定义,然后申请变量,<code>GraphMatrix *graphMatrix</code><br>
(1)申请结构体GraphMatrix空间,对其size赋值<br>
![F9](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic9.png)<br>
<br>
(2)申请一维数组空间<br>
(3)申请二维数组空间<br>
![F10](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic10.png)<br>
<br>
这样就解释了下面一段代码的用处:
```c
//start
...
GraphMatrix* graphMatrix = (GraphMatrix*)malloc(sizeof(GraphMatrix));
...
//给图分配空间
//申请一维数组空间,存放指针内容
graphMatrix->graph = (int**)malloc(sizeof(int*)*graphMatrix->size); 

//这里循环申请的空间才是存放邻接矩阵的空间
for(i=0;i<graphMatrix->size;i++)
    //申请了size个一维数组空间
    graphMatrix->graph[i] = (int*)malloc(sizeof(int)*graphMatrix->size);    

//end
```