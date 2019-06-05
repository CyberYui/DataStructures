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

图的相关代码实现--邻接矩阵
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
        for(j=0;j<graphMatrix->size;j++)
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
这样就解释了下面一段代码的用处:<br>
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

图的读取
--------
```c
void ReadGraph(GraphMatrix* graphMatrix)
{
	int vex1 = 0;
	int vex2 = 0;
	int weight = 0;
	//输入方式为:点 点 权值,当权值为0时则输入结束
	printf("请输入,输入方式为:点 点 权值,权值为0,则输入结束\n");
	scanf_s("%d%d%d", &vex1, &vex2, &weight);

	while (weight != 0)
	{
		graphMatrix->graph[vex1][vex2] = weight;
		scanf_s("%d%d%d", &vex1, &vex2, &weight);
	}
}
```

图的遍历输出
-------
```c
void WriteGraph(GraphMatrix* graphMatrix)
{
	int i = 0;
	int j = 0;
	printf("图的结构如下,输出方式为:点 点 权值\n");
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = 0; j < graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				printf("%d %d %d\n", i, j, graphMatrix->graph[i][j]);
			}
		}
	}
}
```
>具体项目参照Graph_AdjMatrix

图的相关代码实现--邻接表
==========

图的类型定义
----------
```c
typedef struct GRAPHLISTNODE_STRU
{
    int nodeno; //图中结点的编号
    struct GRAPHLISTNODE_STRU * next; //指向下一个结点的指针
}GraphListNode;

typedef struct GRAPHLIST_STRU
{
    int size;   //图中结点的个数(和邻接矩阵一样)
    GraphListNode * graphListArray;  //一维数组,图的邻接表
}GraphList;
```

针对以下的图,在初始化图的时候,过程是这样的:
![F11](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic11.png)<br>
<br>
* (1)申请结构体GraphList空间<code>GraphList *graphList;</code>
* (2)申请一维数组空间,这个数组是用来保存结点的,从而能形成邻接表
![F12](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic12.png)<br>
<br>

图的初始化
------
```c
GraphList* InitGraph(int num)
{
	int i = 0;
	//首先申请图的空间,分配size,从而获得邻接表数组
	GraphList *graphList = (GraphList *)malloc(sizeof(GraphList));
	graphList->size = num;
	//按照size的大小申请结点空间,每一个数组位置都保存一个结点
	graphList->graphListArray = (GraphListNode*)malloc(sizeof(GraphListNode)*num);
	//给图中结点内容初始化,数据域按序,指针域为空
	for (i = 0; i < num; i++)
	{
		graphList->graphListArray[i].next = NULL;
		graphList->graphListArray[i].nodeno = i;
	}
	return graphList;
}
```

图的读取
------
```c
void ReadGraph(GraphList* graphList)
{
	int vex1 = 0;	//起点
	int vex2 = 0;	//终点
	GraphListNode *tempNode = NULL;	//申请临时结点用于数据传输
	//输入方式为:点 点,意思为点->点,当点为-1时,输入结束
	printf("请输入内容,输入方式为:点 点,当点为-1时输入结束:\n");
	scanf_s("%d %d", &vex1, &vex2);
	//只要有一个值为-1循环就结束
	while (vex1 >= 0 && vex2 >= 0)
	{
		//插入结点的内容
		tempNode = (GraphListNode *)malloc(sizeof(GraphListNode));	//给临时结点申请空间
		tempNode->nodeno = vex2;
		tempNode->next = NULL;

		//插入相应结点,在头部插入结点
		//将原数组内容的next赋给新结点,新结点变成邻接表第一个结点
		tempNode->next = graphList->graphListArray[vex1].next;
		//修改原数组内容的next,连接新的邻接表,从而实现tempNode的插入
		graphList->graphListArray[vex1].next = tempNode;
		scanf_s("%d %d", &vex1, &vex2);
	}
}
```

图的遍历输出
---------
```c
/****************************************************************/
/* void WriteGraph(GraphList* graphList)						*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-6-3						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphList* graphList)
{
	int i = 0;
	GraphListNode *tempNode = NULL;	//申请临时结点用于数据传输

	tempNode = (GraphListNode *)malloc(sizeof(GraphListNode));
	tempNode->next = NULL;
	tempNode->nodeno = 0;

	printf("图的结构如下:\n");
	while (i < graphList->size)	//数组是从0开始算的,但是保存的size=num=输入的值(比如测试的这里是4)
	{
		tempNode = graphList->graphListArray[i].next;
		//循环判断当前的顶点是否有邻接表,如果没有邻接表,则直接看下一个顶点,如此循环,直到找到有邻接表的顶点
		for (int k = 0; k < graphList->size; k++)
		{
			if (!tempNode)
			{
				i++;
				tempNode = graphList->graphListArray[i].next;
			}
			else
				break;
		}
		printf("结点%d与结点%d有边相连;\n", i, tempNode->nodeno);
		//遍历每一个数组内容的邻接表,全部输出出来
		for (int j = 0; j < graphList->size; j++)
		{
			if (tempNode->next != NULL)
			{
				tempNode = tempNode->next;
				printf("结点%d与结点%d有边相连;\n", i, tempNode->nodeno);
			}
			else
			{
				break;
			}
		}
		i++;
	}
}
```

>具体项目参照Graph_AdjList

图的周游
=========
>在二叉树中就提及过周游这个概念<br>
<br>
图的周游是指从图中<font color=brown>某个顶点出发</font>,按照某种方式系统地访问图中的<font color=red>所有顶点</font>,使每个顶点仅被访问<font color=purple>一次</font>.<br>

图的遍历通常有两种方法:<br>
* <font color=green>深度优先搜索</font><br>
* <font color=green>广度优先搜索</font><br>

之前对二叉树的周游就是通过一种方式,使得二叉树这种非线性结构变成线性结构,从而简化问题,图的周游也是类似的思想.<br>

通过深度优先搜索或者广度优先搜索,可以将图这种复杂的数据结构变成树这种较为简单的数据结构.<br>

图的周游:<font color=green>深度优先周游---DFS(v)</font>
--------------
* 首先给定一个起始的顶点v,从v出发,先<font color=orange>访问v</font>,并将其<font color=orange>标记为已访问过,记录下相应的边</font>;<br>
* 如果存在与v邻接的顶点没有被访问,则选择<font color=orange>其中的一个w</font>出发进行<font color=orange>递归地DFS</font>.<br>
* 如果已经不存在与v邻接的顶点,那就返回.<br>
[例如]
![F13](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic13.png)<br>
<br>
对于上述的无向图,假设从v1开始,将其标记访问,记录下相应的边,然后就要从v2和v3中选一个继续周游<br>
假设选择v2,首先访问v2,将其标记访问,记录下相应的边,再从v4和v5中选择一个<br>
再从v4访问,记录下相应的边,与v4相连的是v8,则访问v8,记录下相应的边,接着访问v5<br>
此时可见,与v5相连的v2已被访问过,则回退,返回v8,直到返回v1,再访问v3,记录边,再继续,从而完成遍历<br>
>将访问过的顶点和访问过的边描出,就是DFS生成树,即通过周游的形式,将图这种复杂的数据结构变成树这种较为简单的数据结构<br>

有的图中有不相连的连通分量,应该如何进行周游呢?<br>
[注]<font color=pink>如果图中还有未被访问的顶点,则从另一未被访问过的顶点出发重复上述过程,直到图中所有顶点都被访问过为止.</font><br>
[例如]<br>
![F14](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic14.png)<br>
<br>

图的DFS实现
--------
[邻接矩阵表示图]<br>
dfs_graphmatrix.c:<br>
```c
/*图的深度优先遍历实现,用邻接矩阵表示图*/
#include <stdio.h>
#include <stdlib.h>
#include "dfs_graphmatrix.h"

/****************************************************************/
/* void DFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* 功能:图的深度优先遍历递归算法,邻接矩阵表示图					*/
/* 输入参数graphMatrix:图										*/
/* 输入参数visited:做标记用(设置点是否被访问)的一位数组			*/
/* 输入参数i:遍历起始的结点编号									*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j = 0;
	//首先对顶点访问,标记为已访问过
	visited[i] = 1;
	printf("%d ", i);	//访问
	//递归实现深度优先遍历
	for (j = 0; j < graphMatrix->size; j++)
	{
		//如果i和j有边相连,并且j没有被访问过
		if (graphMatrix->graph[i][j] != INT_MAX && !visited[j])
		{
			DFS(graphMatrix, visited, j);	//对j进行深度优先遍历
		}
	}
}

/****************************************************************/
/* void DFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* 功能:深度遍历,邻接矩阵表示图									*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i = 0;
	//用于记录图中哪些结点已经被访问了
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	//初始化为点都没有被访问
	for (i = 0; i < graphMatrix->size; i++)
	{
		visited[i] = 0;
	}
	//从0出发开始访问结点,只要有没访问过的就对其进行深度优先遍历,
	//这样就能访问到所有的连通分量
	for (i = 0; i < graphMatrix->size; i++)
	{
		//对未访问过的顶点调用DFS,若是连通图,则只会执行一次
		if (!visited[i])
		{
			DFS(graphMatrix, visited, i);
		}
	}
}
```
//可见一个<font color=brown>用邻接矩阵表示的图</font>被完全遍历其算法时间复杂度为O(n<sup>2</sup>)<br>
>采用邻接矩阵表示的图的DFS实现参照GraphDFStravel项目<br>

[邻接表表示图]<br>
dfs_graphlist.c:<br>
```c
/*图的深度优先遍历算法,用邻接表表示的图*/
#include <stdio.h>
#include <stdlib.h>
#include "dfs_graphlist.h"

/****************************************************************/
/* void DFS(GraphList* graphList, int * visited, int i)			*/
/* 功能:图的深度优先遍历递归算法,邻接表表示图					*/
/* 输入参数graphList:图											*/
/* 输入参数visited:做标记用(设置点是否被访问过)的一维数组		*/
/* 输入参数i:结点编号											*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphList* graphList, int * visited, int i)
{
	int j = 0;
	GraphListNode *tempNode = NULL;
	visited[i] = 1;
	printf("%d ", i);

	tempNode = graphList->graphListArray[i].next;
	while (tempNode != NULL)
	{
		if (!visited[tempNode->nodeno])
		{
			DFS(graphList, visited, tempNode->nodeno);
		}
		tempNode = tempNode->next;	
	}
}

/****************************************************************/
/* void GFSGraphList(GraphList* graphList)						*/
/* 功能:深度遍历,邻接表表示图									*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphList(GraphList* graphList)
{
	int i = 0;
	//用于记录图中哪些结点已经被访问了
	int *visited = (int*)malloc(sizeof(int) * graphList->size);

	//初始化为点都没有被访问过
	for (i = 0; i < graphList->size; i++)
	{
		visited[i] = 0;
	}

	for (i = 0; i < graphList->size; i++)
	{
		//对未访问过的顶点调用DFS,若是连通图,只会执行一次
		if (!visited[i])
		{
			DFS(graphList, visited, i);
		}
	}
}
```
//可见一个<font color=brown>用邻接表表示的图</font>被完全遍历其算法时间复杂度为O(n+e)<br>
>采用邻接表表示的图的DFS实现参照GraphDFStravelL项目<br>

图的周游:<font color=green>广度优先周游---BFS(v)</font>
---------
* 首先给定一个起始的顶点v,从v出发,先<font color=orange>访问v</font>,并将其<font color=orange>标记为已访问过,记录下相应的边</font>;<br>
* 依次访问v的所有相邻结点w1,w2,...,wx,记录下相应的边.<br>
* 再依次访问与w1,w2,...,wx邻接的所有未被访问过的顶点,记录下相应的边<br>
* 以此类推,直到所有已访问顶点的相邻结点都被访问过,并记录下相应的边为止.<br>
[例如]<br>
![F15](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic15.png)<br>
<br>

* 如果有其他的连通分量,即图中还有未被访问过的顶点,则从某个未被访问过的顶点出发进行广度优先搜索,直到左右顶点都被访问过,并记录下相应的边为止.<br>
[例如]<br>
![F16](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic16.png)<br>
<br>

图的BFS实现
---------
在这里使用到了之前建立的链队列的内容,具体参照项目文件即可<br>

[邻接矩阵表示图]<br>
bfs_graphmatrix.c:<br>
```c
/*对用邻接矩阵表示的图进行广度优先遍历搜索*/
#include "bfs_graphmatrix.h"
#include <stdio.h>
#include <stdlib.h>

/****************************************************************/
/* void BFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* 功能:图的广度优先遍历,邻接矩阵表示图							*/
/* 输入参数graphMatrix:图										*/
/* 输入参数visited:用于保存访问状态的一位数组					*/
/* 输入参数i:结点编号											*/
/* 返回值:														*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphMatrix* graphMatrix, int * visited, int i)
{
	int j = 0;
	int tempVex = 0;
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();
	//如果没有访问过,则访问
	if (!visited[i])
	{
		visited[i] = 1;	//设置标记,表明已经被访问过
		printf("%d ", i);	//输出访问的结点编号
		EnQueue_Link(waitingQueue, i);	//将刚访问的结点放入队列
		while (!IsNullQueue_Link(waitingQueue))
		{
			tempVex = FrontQueue_Link(waitingQueue);
			DeQueue_Link(waitingQueue);
			for (j = 0; j < graphMatrix->size; j++)
			{
				//如果其它顶点与当前订单存在边且未访问过
				if (graphMatrix->graph[tempVex][j] != INT_MAX && !visited[j])
				{
					visited[j] = 1;	//做标记
					EnQueue_Link(waitingQueue, j);	//入队
					printf("%d ", j);	//输出
				}//end if
			}//end for
		}//end while
	}//end if
}//end function

/****************************************************************/
/* void BFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* 功能:图的广度优先遍历,邻接矩阵表示图							*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphMatrix(GraphMatrix* graphMatrix)
{
	int i = 0;

	//用于记录图中哪些结点已经被访问过了
	int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

	//设置所有结点都没有被访问过
	for (i = 0; i < graphMatrix->size; i++)
	{
		visited[i] = 0;
	}

	//从0号结点开始进行广度优先遍历
	for (i = 0; i < graphMatrix->size; i++)
	{
		BFS(graphMatrix, visited, i);
	}//end
}
```

>采用邻接矩阵表示的图的BFS实现参照GraphBFStravel项目<br>

[邻接表表示图]<br>
bfs_graphlist.c:<br>
```c
/*图的广度优先遍历,用邻接表表示的图*/
#include "bfs_graphlist.h"
#include <stdio.h>
#include "LinkQueue.h"
/****************************************************************/
/* void BFS(GraphList* graphList, int * visited, int i)			*/
/* 功能:对邻接表表示的图进行广度优先遍历						*/
/* 输入参数graphList:图,邻接表表示								*/
/* 输入参数visited:用于标记结点是否被访问过的一位数组			*/
/* 输入参数i:结点编号											*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphList* graphList, int * visited, int i)
{
	int tempVex = 0;
	GraphListNode *tempNode = NULL;

	//广度优先遍历使用的队列是c++的STL(标准模版库)中的queue
	//很明显,C语言是无法使用标准模版库的,所以视频没有给出所有代码,因为她也跑不出来
	//还是用原先的链队列
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link();

	//如果没有访问过,则访问
	if (!visited[i])
	{
		visited[i] = 1;	//设置标记,表明已经被访问过了
		printf("%d ", i);	//输出访问的结点的编号
		EnQueue_Link(waitingQueue,i);	//将刚访问的结点放入队列
		//开始广度优先遍历结点
		while (!IsNullQueue_Link(waitingQueue))
		{
			tempVex = FrontQueue_Link(waitingQueue);
			DeQueue_Link(waitingQueue);
			//依次访问与当前结点相邻的点
			tempNode = graphList->graphListArray[tempVex].next;
			while (tempNode!=NULL)
			{
				//如果其它顶点与当前顶点存在边且未被访问过
				if (!visited[tempNode->nodeno])
				{
					visited[tempNode->nodeno] = 1;	//做标记
					EnQueue_Link(waitingQueue, tempNode->nodeno);	//入队
					printf("%d ", tempNode->nodeno);	//输出
				}//end if

				//移动到下一个结点
				tempNode = tempNode->next;
			}//end while
		}//end while
	}//end if
}

/****************************************************************/
/* void BFSGraphList(GraphList* graphList)						*/
/* 功能:图的广度优先遍历,邻接表表示图							*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphList(GraphList* graphList)
{
	int i = 0;

	//用于记录图中哪些结点已经被访问过了
	int *visited = (int*)malloc(sizeof(int) * graphList->size);
	//这里会报警告,可以忽略
	//warning C4013: “malloc”未定义；假设外部返回 int

	//设置所有结点都没有被访问过
	for (i = 0; i < graphList->size; i++)
	{
		visited[i] = 0;
	}

	//从0号结点开始进行广度优先遍历
	for (i = 0; i < graphList->size; i++)
	{
		BFS(graphList, visited, i);
	}//end
}
```

>采用邻接表表示的图的BFS实现参照GraphBFStravelL项目<br>

连通图和连通分量---如何判断图的连通性
============
[连通图和连通分量]<br>
在无向图G中,若从顶点v<sub>i</sub>到顶点v<sub>j</sub>有路径,则称v<sub>i</sub>和v<sub>j</sub>是<font color=green>连通的</font>.<br>
若V(G)中任意两个不同的顶点v<sub>i</sub>和v<sub>j</sub>都连通(即有路径),则称G为<font color=green>连通图</font>.<br>
无向图G的极大连通子图称为G的<font color=green>连通分量</font>.<br>
<br>
在有向图G中,若对于V(G)中任意两个不同的顶点v<sub>i</sub>和v<sub>j</sub>以及v<sub>j</sub>和v<sub>i</sub>(即正反向),都存在从v<sub>i</sub>到v<sub>j</sub>和v<sub>j</sub>到v<sub>i</sub>的路径,则称G是<font color=green>强连通图</font>;有向图G的极大强连通子图称为G的<font color=green>强连通分量</font>.<br>
>即无向图相关的概念为连通图和连通分量,有向图相关的概念为强连通图和强连通分量.<br>

判断一个图是否为连通图,以及判断非连通图的连通分量个数都可以采用之前的图的遍历实现,无论是深度遍历还是广度遍历都可以.<br>
如果是一个连通图,则进行一次遍历即可.<br>
如果是一个非连通图,则需要多次调用,调用几次,就是几个连通分量.<br>

比如要用BFS,针对邻接矩阵表示的图<br>
修改的内容基本一致,参照以下代码相应修改即可<br>
修改之后的代码如下:<br>
```c
void BFSGraphMatrix(GraphMatrix* graphMatrix)
{
    int i = 0;
    int brance = 0; //用于记录连通分量个数的计数器

    //用于记录图中哪些结点已经被访问过了
    int *visited = (int*)malloc(sizeof(int) * graphMatrix->size);

    //设置所有结点都没有被访问过
    for(i = 0;i < graphMatrix->size; i++)
    {
        //如果是连通图,则只调用一次
        if(!visited[i])
        {
            brance++;
            BFS(graphMatrix,visited,i);
        }
    }//end for

    if(brance == 1)
    {
        //这是一个连通图
        printf("This graph is a connected graph!\n");
    }
    else
    {
        //这不是一个连通图,并输出连通分量个数
        printf("This graph is not a connected graph!\n");
        printf("The number of connected components is:%d \n",brance);
    }
}
```

图的层数的确定
========
我们知道,对一个图进行广度优先遍历时,BFS生成树是分层的,我们可以根据生成树的层数确定原图的层数<br>
和计算连通分量相同,我们只需要加一个计数器level即可.<br>
我们需要知道每一层最后一个结点出队的时机,在此时计数器+1即可<br>

[思路整理]<br>
使用广度优先搜索算法的框架,通过以下变量记录变化:<br>
<font color=green>增加变量level,用来记录层数</font><br>
增加变量<font color=blue>last,用于保存上一层最后入队的顶点</font><br>
增加变量<font color=blue>tail,用来记录当前层最后访问顶点</font>,每次循环时,将last更新为tail<br>
当<font color=red>出队顶点为last时,level加1</font><br>

具体实现只要在原先的BFS框架下做一些改动即可<br>
修改的代码参照以下内容,以下为针对邻接表表示的图的记录层数算法<br>
计算图的层数代码如下:<br>
```c
void BFS_Level(GraphList* graphList,int *visited,int source)
{
    int tempVex = 0;    //临时变量
    int level = 0;  //记录广度优先搜索树的层数
    int last = source;  //用last保存上一层最后访问的结点
    int tail = source;  //用tail来记录当前最后访问的结点
    GraphListNode *tempNode = NULL; //临时结点

    //同样,C语言中不允许C++的STL出现,使用之前建立的链队列
    //queue<int> waitingQueue;
	LinkedQueue waitingQueue = NULL;
	waitingQueue = SetNullQueue_Link(); //创建空队列

    visited[source] = 1;    //设置标记,表明已经被访问过了
    printf("%d ",source);   //输出访问的结点编号

    //waitingQueue.push(source);
    EnQueue_Link(waitingQueue,source);  //将刚访问的结点放入队列

    //广度优先访问结点
    //while(!waitingQueue.empty())
    while(!IsNullQueue_Link(waitingQueue))
    {

        //tempVex=waitingQueue.front();
        tempVex = FrontQueue_Link(waitingQueue);    //取队头元素

        //waitingQueue.pop();
        DeQueue_Link(waitingQueue); //出队队头元素

        //一次访问与当前结点相邻的点
        tempNode = graphList->graphListArray[tempVex].next; //开始访问邻接表内容
        while(tempNode != NULL)
        {

            //如果其他顶点与当前顶点存在边且未被访问过
            if(!visited[tempNode->nodeno])
            {
                visited[tempNode->nodeno] = 1;  //做标记

                //waitingQueue.push(tempNode->nodeno);  //入队
                EnQueue_Link(waitingQueue, tempNode->nodeno);	//入队
                
                printf("%d ",tempNode->nodeno); //输出
                tail = tempNode->nodeno;
            }
            tempNode = tempNode->next;  //移动到下一个结点
        }//end while

        //从队列中取出的结点的下一层都访问过后,再判断刚刚的这个结点是否是其所在层的最后结点
        if(tempVex == last)
        {
            level++;
            last = tail;    //移动last
            printf("The current level is %d\n",level);
        }//end if
    }//end while
}
```
>[思考]以上给出的是BFS判断层数和连通分量,那么如果是DFS的话应该怎么做呢?

最小生成树(MST---Minimum Spanning Tree)
=========
最小生成树有很多应用场景:<br>
如果将顶点作为城市,边作为城市之间的公路<br>
* N个城市之间建立通信网络,考虑成本最优<br>
* M个村庄之间建立村村通公路,考虑成本最优<br>
* ......<br>

之前我们对一个图进行DFS和BFS时,会生成两个不同的生成树<br>
那么如果换一个顶点出发进行DFS和BFS,则会再生成两个不同的生成树<br>
以此类推,其中代价最小的生成树就是我们需要的生成树<br>

最小生成树
-------
首先,最小生成树是通过某种算法生成的一棵树,即是一棵生成树,而不是凭空给出的<br>
其特点是:<br>
* 是生成树<br>
* 包含n个顶点和n-1条边的连通图<br>
* 无回路<br>
* DFS生成树和BFS生成树就满足上述的两条特点<br>
* (最小)各边权值之和最小<br>

构造最小生成树的算法
--------
* Prim(普利姆)算法<br>
* Kruskal(克鲁斯卡尔)算法<br>

普利姆算法(Prim)
----------
一个图是由顶点的集合V和边的集合E组成的,<br>
即G&nbsp;=&nbsp;(V,E)<br>
假设最小生成树叫T<sub>mst</sub>,它是由其顶点的集合V<sub>T</sub>和其边的集合E<sub>T</sub>组成的<br>
即T<sub>mst</sub>&nbsp;=&nbsp;(V<sub>T</sub>,E<sub>T</sub>)<br>
由之前的最小生成树定义可知,V&nbsp;=&nbsp;V<sub>T</sub>,即所有顶点都要包含起来<br>
而E<sub>T</sub>则应该是E的一个子集<br>

[算法思路]<br>
* (1)从图G中任意顶点V<sub>m</sub>(V<sub>m</sub>∈V)开始,将V<sub>m</sub>加入到最小生成树<br>
* (2)选择代价最小的边(V<sub>k</sub>,V<sub>j</sub>),将这条边加入到最小生成树中,同时将顶点V<sub>j</sub>加入到最小生成树,在选择这条边的时候要求:<br>
        ①&nbsp;两个顶点属于不同的集合,V<sub>k</sub>∈V<sub>T</sub>,V<sub>j</sub>∈V-V<sub>T</sub><br>
        ②&nbsp;加入的边不能使最小生成树产生回路<br>
* (3)重复这一过程,直到T<sub>mst</sub>中有n-1条边为止,即V<sub>T</sub>=V<br>
<br>
比如一棵树有5个顶点,分别记为ABCDE,Prim算法就是:<br>
* 首先将A放入最小生成树中然后在A->B,A->C,A->D,A->E中选择最小的边,<br>
* 假如当前全职最小的边是A->C,那么就将这条边放入最小生成树中,同时C也放入最小生成树中<br>
* 此时最小生成树中有A,C顶点以及A->C这条边<br>
* 接着,在A->B,A->D,A->E以及C->B,C->D,C->E这些边中再找权值最小的边,假设A->E最小<br>
* 则A->E这条边放入最小生成树,同时E也放入其中<br>
* 以此类推,直到最小生成树中有所有的顶点,并且能形成连通图,且无回路即可<br>
>规则:1.有边&emsp;&emsp;2.权值最小<br>

普利姆算法的实现
---------
在实现过程中,需要设置三个数组:<br>
* component[j]数组<br>
        用于记录已经加入最小生成树的顶点j,<br>
        初始化时component[j] = 0,当顶点j加入最小生成树之后,设置component[j] = 1<br>

* distance[j]数组<br>
        用来记录代价最小的边(V<sub>k</sub>,V<sub>j</sub>)的权值<br>
        (其中V<sub>k</sub>∈component[])<br>
        初始化时distance[j] = graphMatrix->graph[0][j]<br>

* neighbor[j]数组<br>
        用于记录代价最小的边(V<sub>k</sub>,V<sub>j</sub>)所对应的顶点V<sub>k</sub><br>
        初始化时neighbor[j] = 0<br>

[例子]<br>
![F17](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic17.png)<br>
<br>

以上面的带权图为例,用下表说明:<br>
假设一共有6个顶点,记为0&nbsp;1&nbsp;2&nbsp;3&nbsp;4&nbsp;5<br>
表格中每一格的数字表示为对应顶点的(component[],distance[],neighbor[])变化<br>
<font color=blue>蓝色</font>表示已加入最小生成树<br>
<font color=red>红色</font>表示数组有更新<br>
|  顶点  |   0   |   1   |    2   |    3   | 4      | 5      |
|:------:|:-----:|:-----:|:------:|:------:|:------:|:------:|
| 第一次 | <font color=blue>1,0,0</font> | 0,5,0 | 0,30,0 | 0,14,0 | 0,∞,0  | 0,∞,0  |
| 第二次 | <font color=blue>1,0,0</font> | <font color=blue>1,5,0</font> | <font color=red>0,24,1</font> | 0,14,0 | <font color=red>0,14,1</font> | <font color=red>0,10,1</font> |
| 第三次 | <font color=blue>1,0,0</font> | <font color=blue>1,5,0</font> | <font color=red>0,17,5</font> | <font color=red>0,8,5</font>  | 0,14,1 | <font color=blue>1,10,1</font> |
| 第四次 | <font color=blue>1,0,0</font> | <font color=blue>1,5,0</font> | 0,17,5 | <font color=blue>1,8,5</font>  | 0,14,1 | <font color=blue>1,10,1</font> |
| 第五次 | <font color=blue>1,0,0</font> | <font color=blue>1,5,0</font> | 0,17,5 |  <font color=blue>1,8,5</font> | <font color=blue>1,14,1</font> | <font color=blue>1,10,1</font> |
| 第六次 | <font color=blue>1,0,0</font> | <font color=blue>1,5,0</font> | <font color=blue>1,17,5</font> |  <font color=blue>1,8,5</font> | <font color=blue>1,14,1</font> | <font color=blue>1,10,1</font> |

* 第一次,V<sub>0</sub>进入最小生成树,并对distance判断,5最小<br>
* 第二次,由于V<sub>1</sub>对应的distance最小,所以V<sub>1</sub>和对应的(V<sub>0</sub>,V<sub>1</sub>)进入最小生成树,此时更新distance数组和neighbor数组,先对比V<sub>1</sub>到V<sub>2</sub>和V<sub>0</sub>到V<sub>2</sub>的权值(24)最小,所以更新distance中的内容为24,neighbor中的内容为1,继续对比V<sub>1</sub>到V<sub>3</sub>和V<sub>0</sub>到V<sub>3</sub>的权值,发现V<sub>1</sub>到V<sub>3</sub>是无穷(∞,即不相连),V<sub>0</sub>到V<sub>3</sub>是14,则不改变distance和neighbor,以此类推,完成此行的数组更新,对distance判断,10最小<br>
* 第三次,由于V<sub>5</sub>到V<sub>1</sub>的权值(10)最小,所以V<sub>5</sub>和对应的(V<sub>1</sub>,V<sub>5</sub>)进入最小生成树,此时更新distance数组和neighbor数组...<br>
* ...<br>
* 以此类推,直到最后生成最小生成树.<br>
>这个带权图的最小生成树并不唯一,比如刚刚我们得到的是左边的这个最小生成树,而也可以得到右边的这个最小生成树<br>

![F18](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic18.png)<br>
<br>

>原因是在加入3结点的时候,2结点对应的(component[],distance[],neighbor[])并没有更新,如果在这时更新(component[],distance[],neighbor[]),则会生成右边的这个最小生成树<br>

普利姆算法的代码实现
----------
```c
//无向图采用邻接矩阵表示
GraphMatrix* prim(int source,GraphMatrix *graphMatrix)
{
    int i = 0;
    int j = 0;
    int *component = (int*)malloc(sizeof(graphMatrix->size));   //新点集合
    int *distance = (int*)malloc(sizeof(graphMatrix->size));    //距离
    int *neighbor = (int*)malloc(sizeof(graphMatrix->size));    //邻居,例如neighbor[i]=j表示i的邻居是j
    GraphMatrix *tree = InitGraph(graphMatrix->size);   //存放结果的图

    //初始化
    for(i = 0; i<graphMatrix->size; i++)
    {
        component[i] = 0;
        distance[i] = graphMatrix->graph[source][i];
        neighbor[i] = source;
    }//O(n)

    //将起点放入新点集合
    component[source] = 1;

    //每次添加一个结点到新点集合中
    for(i = 1; i<graphMatrix->size; i++)
    {
        int v;  //v记录最小的distance[j]的下标
        int min = INT_MAX;  //min记录最小的distance

        //选择不是新点的集合中,距离新点集合最短的那个点
        for(j = 0; j<graphMatrix->size; j++)
        {
            if(!component[j])
            {
                //找最小值
                if(distance[j] < min)
                v = j;
                min = distance[j];
            }
        }//O(n)

        //将找到的点v加入新点集合中,并更新distance
        if(min < INT_MAX)
        {
            component[v] = 1;
            tree->graph[v][neighbor[v]] = distance[v];  //更新v到neighbor[v]的距离
            tree->graph[neighbor[v]][v] = distance[v];  //更新neighbor[v]到v的距离
            //更新非新点集合中的点到新点集合的距离
            for(j = 0; j<graphMatrix->size; j++)
            {
                if(!component[j])
                {
                    if(graphMatrix->graph[v][j] < distance[j])
                    {
                        distance[j] = graphMatrix->graph[v][j];
                        neighbor[j] = v;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }//O(n^2)
    return tree;
}
```
>普利姆算法的时间复杂度为O(n<sup>2</sup>)
>具体实现参照GraphPrim项目

克鲁斯卡尔算法(Kruskal)
----------
[算法过程]<br>
还是对于上一节说到的图,这次使用克鲁斯卡尔算法建立最小生成树:<br>
<br>
![F17](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic17.png)<br>
<br>

* 原图和最小生成树的顶点数是一样的,所以先将所有的顶点看做一个连通子图,加入到最小生成树中<br>
* 对集合E中的边按权递增排序,排列为:<br>
        (v<sub>0</sub>,v<sub>1</sub>) = 5<br>
        (v<sub>3</sub>,v<sub>5</sub>) = 8<br>
        (v<sub>1</sub>,v<sub>5</sub>) = 10<br>
        (v<sub>0</sub>,v<sub>3</sub>) = 14<br>
        (v<sub>1</sub>,v<sub>4</sub>) = 14<br>
        (v<sub>2</sub>,v<sub>3</sub>) = 17<br>
        (v<sub>2</sub>,v<sub>5</sub>) = 17<br>
        (v<sub>1</sub>,v<sub>2</sub>) = 24<br>
        (v<sub>4</sub>,v<sub>8</sub>) = 25<br>
        (v<sub>0</sub>,v<sub>2</sub>) = 30<br>

如下表这样建立一个表,显示各边排列后的结果:<br>
![F19](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic19.png)<br>
<br>

* 选择权值最小的边加入到最小生成树中,每选一条边就要判断一次是否构成回路,能够构成回路的边是不需要的<br>
* 循环往复,直到加入了n-1条边使得整个生成树变为一个连通子图为止,即为最小生成树<br>

建立一个Group数组,用于记录各个顶点归属的连通分量,当所有顶点的连通分量相同时,即最小生成树生成<br>
在加入1到5的这条边的时候,修改了5结点的连通分量为与1相同,即0,但是在上一步添加5到3这条边时修改了3的连通分量和5相同,为3,则在此时需要将3与5同步修改,即也改为0<br>
由此可见,修改一个顶点时,需要同时修改与其相同的连通分量的顶点<br>
判断是否构成环也可以看看是否两个顶点的连通分量相同<br>
最终的各边表为:<br>
![F21](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic21.png)<br>
<br>
即加入了n-1条边<br>
在加入过程中Group数组的更新如下:<br>
![F20](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic20.png)<br>
<br>

克鲁斯卡尔算法的实现
----------
同样,也是针对邻接矩阵表示的图进行实现<br>
```c
/****************************************************************/
/* GraphMatrix* kruskal(GraphMatrix *graphMatrix)				*/
/* 功能:使用克鲁斯卡尔算法生成最小生成树						*/
/* 输入参数graphMatrix:											*/
/* 返回值tree:最小生成树										*/
/* 创建日期:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* kruskal(GraphMatrix *graphMatrix)
{
	//声明并初始化循环变量
	int i = 0;
	int j = 0;

	int edgeNum = 0;	//用于记录边数的计数器
	Edge *edge = NULL;	//边
	Edge tempEdge;	//给边排序时使用的临时变量

	int pos = 0;	//用于记录添加到哪一条边了
	int *group;		//用于记录点是否属于同一连通分量的group数组
	int changeGroup = 0;	//记录要变化的连通值

	//存放结果并返回的图(最小生成树)
	GraphMatrix *tree = InitGraph(graphMatrix->size);

	//申请group数组空间,一共需要申请与结点相同的空间数
	group = (int*)malloc(sizeof(int) * graphMatrix->size);

	//初始化数组
	for (i = 0; i < graphMatrix->size; i++)
	{
		//初期点全部加入,但互不相连,每个点都是一个连通子图
		group[i] = i;
	}

	//统计一共有多少条边
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = i + 1; j < graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edgeNum++;
			}
		}
	}//end counting for edge number

	//根据刚刚计算出来的边数,分配边的空间
	edge = (Edge *)malloc(sizeof(Edge) * edgeNum);

	int k = 0;	//给边赋值时使用的循环计数器

	//给边赋值
	for (i = 0; i < graphMatrix->size; i++)
	{
		for (j = i + 1; j < graphMatrix->size; j++)
		{
			if (graphMatrix->graph[i][j] < INT_MAX)
			{
				edge[k].begin = i;
				edge[k].end = j;
				edge[k].weight = graphMatrix->graph[i][j];
				k++;
			}
		}
	}//end giving weight for every edges

	//对边进行排序,使用了冒泡算法
	for (i = 0; i < edgeNum; i++)
	{
		for (j = i + 1; j < edgeNum; j++)
		{
			if (edge[i].weight > edge[j].weight)
			{
				tempEdge = edge[i];
				edge[i] = edge[j];
				edge[j] = tempEdge;
			}
		}
	}//排序结束

    //对排序完的内容进行输出,看看同权值的边谁在前,谁在后
    printf("排序完的边顺序为:\n");
    for(i = 0; i < edgeNum; i++)
    {
        printf("%d %d %d\n",edge[i].begin,edge[i].end,edge[i].weight);
    }

	//此时边的数组已经排好顺序了
	//每次从边的数组中取出最小的一条边,判断是否能添加到最小生成树中
	for (i = 0; i < edgeNum; i++)
	{
		//只添加终点和起点属于两个不同连通分量的边
		if (group[edge[i].begin] != group[edge[i].end])
		{
			//添加到最小生成树中
			tree->graph[edge[i].begin][edge[i].end] = edge[i].weight;
			tree->graph[edge[i].end][edge[i].begin] = edge[i].weight;

			//更新所有与终点属于同一连通分量的点的连通值
			changeGroup = group[edge[i].end];
			for (j = 0; j < edgeNum; j++)
			{
				if (group[j] == changeGroup)
				{
					group[j] = group[edge[i].begin];
				}
			}//end for,结束更新连通值
		}//end if,仅对连通分量不同的边进行操作
	}//end for,结束循环,生成最小生成树
	return tree;	//实际也是个图
}
```
>具体项目参照GraphKruskal项目<br>

[注]<br>
普利姆算法和克鲁斯卡尔算法对于同一个图生成的最小生成树不同<br>
原因是:克鲁斯卡尔算法中对边进行了排序,排序之后2&nbsp;5&nbsp;17在2&nbsp;3&nbsp;17之前<br>

最短路径(Shortest Path)
==========
[最短路径问题有两类]<br>
* 1.从某个源点到其余各顶点的最短路径(可以用Dijkstra算法解决)<br>
* 2.每一对顶点之间的最短路径(可以用Floyd算法解决)<br>

有这样一个带权有向图,要求其中的V<sub>0</sub>到其他各个顶点的最短路径:<br>
![F22](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic22.png)<br>
<br>
由图可见,V<sub>0</sub>和V<sub>1</sub>,V<sub>2</sub>以及V<sub>3</sub>是直接相连的,到V<sub>4</sub>和V<sub>5</sub>没有直接边相连,视其路径为无穷(∞)<br>
显然,V<sub>0</sub>到V<sub>1</sub>的最短路径为5<br>
[有没有可能V<sub>0</sub>绕道到V<sub>1</sub>成为最短路径呢?在特殊情况下这是可能的,但在本图中是不可能的.]<br>
确定了V<sub>0</sub>到V<sub>1</sub>的最短路径,接着判断以V<sub>1</sub>为跳板的路径到其他地方是否比V<sub>0</sub>直接到要短,并相应更新<br>
可以看出V<sub>1</sub>到V<sub>5</sub>路径最短,此时以V<sub>5</sub>为跳板进行...<br>
以此类推,直到得到V<sub>0</sub>到其他个各个顶点的最短路径.<br>
<br>
以V<sub>0</sub>为源点,可以依次得到V<sub>0</sub>到其他各个顶点的最短路径如下:<br>
* V<sub>0</sub>-->V<sub>1</sub>:最短路径为(V<sub>0</sub>,V<sub>1</sub>),最短路径长度为5<br>
* V<sub>0</sub>-->V<sub>2</sub>:最短路径为(V<sub>0</sub>,V<sub>1</sub>,V<sub>2</sub>),最短路径长度为29<br>
* V<sub>0</sub>-->V<sub>3</sub>:最短路径为(V<sub>0</sub>,V<sub>1</sub>,V<sub>5</sub>,V<sub>3</sub>),最短路径长度为23<br>
* V<sub>0</sub>-->V<sub>4</sub>:最短路径为(V<sub>0</sub>,V<sub>1</sub>,V<sub>5</sub>,V<sub>4</sub>),最短路径长度为27<br>
* V<sub>0</sub>-->V<sub>5</sub>:最短路径为(V<sub>0</sub>,V<sub>1</sub>,V<sub>5</sub>),最短路径长度为15<br>

迪杰斯特拉(Dijkstra)算法思路
-----------
主要设置两个数组:<br>
distance[]:记录V<sub>0</sub>到各个顶点的最短路径<br>
path[]:记录V<sub>0</sub>到该顶点的直接前驱,比如V<sub>0</sub>-->V<sub>5</sub>中,V<sub>1</sub>就是这里V<sub>5</sub>的直接前驱<br>
<br>
以下表作为演示:<br>
![F23](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic23.png)<br>
<br>
>通过最后的distance数组提取出V<sub>0</sub>到各个顶点的最短距离<br>
>通过最后的path数组得到V<sub>0</sub>到一个顶点的最短路径<br>

迪杰斯特拉(Dijkstra)算法的实现
-----------
```c
/****************************************************************/
/* int* dijkstra(int source, GraphMatrix *graphMatrix)			*/
/* 功能:对邻接矩阵表示的图使用dijkstra算法找出一个顶点到其它顶点*/
/*		的最短路径												*/
/* 输入参数source:起点											*/
/* 输入参数graphMatrix:图										*/
/* 返回值:存放最短路径的一维数组distance						*/
/* 创建日期:2019-6-1						Author:Cyber Kaka	*/
/****************************************************************/
int* dijkstra(int source, GraphMatrix *graphMatrix)
{
	int i = 0;	//循环计数器1
	int j = 0;	//循环计数器2
	int vex = 0;	//用于存放顶点编号的临时变量
	int min = 0;	//距离最小值的临时存放变量

	//found数组是用于记录哪些点的最短路径已经确定,即用于标记
	int* found = (int*)malloc(sizeof(int) * graphMatrix->size);

	//距离数组,算法过程中会不断更新,最终的结果也会放于其中
	int* distance = (int*)malloc(sizeof(int) * graphMatrix->size);

	//path数组,用于记录相应顶点在最短路径中的前驱顶点
	int* path = (int*)malloc(sizeof(int) * graphMatrix->size);

	//初始化
	for (i = 0; i < graphMatrix->size; i++)
	{
		found[i] = 0;	//所有结点的最短路径都没有确定
		distance[i] = graphMatrix->graph[source][i];	//权值
		path[i] = 0;	//默认每个结点初始都无直接前驱
	}//end for

	//将起点加入新点集合中
	found[source] = 1;
	distance[source] = 0;	//顶点到自身的距离为0

	//循环确定每个顶点的最短路径
	for (i=0;i<graphMatrix->size;i++)
	{
		//寻找距离最小的点
		min = INT_MAX;
		for (j = 0; j < graphMatrix->size; j++)
		{
			//如果j结点没有确定过最短路径,且其距离小于min
			if ((!found[j]) && (distance[j] < min))
			{
				//记录j顶点到vex,记录其距离,这是最短的
				vex = j;
				min = distance[j];
			}//end if
		}//end for(j) 1

		//找到的点标记为已确定最短路径
		found[vex] = 1;

		//此时以vex为跳板进行数据更新
		//看是否需要更新其他的顶点的distance和path
		for (j = 0; j < graphMatrix->size; j++)
		{
			//顶点j未确定最短路径,且vex和j之间有边相连
			if (!found[j] && graphMatrix->graph[vex][j] != INT_MAX)
			{
				//判断之前的最短路径加上现在跳板vex到j的距离是否小于源点到j的距离
				//若小于则更新其路径
				if (min + graphMatrix->graph[vex][j] < distance[j])
				{
					//更新权值
					distance[j] = min + graphMatrix->graph[vex][j];
					path[j] = vex;	//记录前驱结点
				}//end if
			}//end if
		}//end for(j) 2
	}//end for(i)

	//由于无法同时返回distance和path数组,在此输出path数组(如果需要的话)
	//for (j = 0; j < graphMatrix->size; j++)
	//{
	//	if (distance[j]<INT_MAX)
	//	{
	//		printf("0号结点到%d号结点的前驱结点为%d \n", j, path[j]);
	//	}
	//}

	//上面的输出path数组的循环有个问题,那样只能输出直接前驱
	//往往我们在找路径时要"顺藤摸瓜"才能找到所有前驱
	//for (j=0;j<graphMatrix->size;j++)
	//{
	//	if (distance[j]<INT_MAX)
	//	{
	//		i = j;
	//		printf("\n0号结点到%d号结点的前驱结点依次为:", j);
	//		while (path[i] != 0)
	//		{
	//			printf("%d ", path[i], i);
	//			i = path[i];
	//		}
	//		printf("%d", 0);	//最后不要忘记源点
	//	}
	//}
	//printf("\n");

	return distance;
}//end dijkstra
```
>算法的时间复杂度为O(n<sup>2</sup>)<br>
>空间复杂度为O(n),即一维数组<br>

图的典型应用:拓扑排序(topological sorting)
==============
图中的拓扑排序并不是比较关键码的大小,而是指一种先后的约束关系<br>
<br>
研究内容:<font color=green>AOV</font>网:顶点活动网(<font color=green>A</font>ctivity <font color=green>O</font>n <font color=green>V</font>ertex network)<br>
AOV网:<br>
* 首先它是一个<font color=red>有向图</font><br>
* 并且图中<font color=red>无环存在</font><br>
* 图中的<font color=red>顶点表示活动</font><br>
* 图中的<font color=red>边表示活动间的先后关系</font><br>

例如下面这个图就是一个AOV网:<br>
![F24](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic24.png)<br>
<br>
图中的顶点表示知识点<br>
图中的边表示依赖关系<br>
例如:Linux链表依赖的知识是单循环链表和双链表,没有这两个知识,是无法理解Linux链表的<br>

拓扑排序的方法
---------
* 从AOV网中选择一个<font color=red>入度为0</font>的顶点将其输出
* 在AOV网中<font color=red>删除</font>此顶点及其所有的出边
* 反复执行以上两步,直到所有顶点都已经输出为止

以下面的AVO网为例:
![F25](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic25.png)<br>
<br>

[假设我们每次都从序号小的顶点开始]<br>
入度为0的顶点为C<sub>1</sub>和C<sub>9</sub><br>
假设选择C<sub>1</sub>输出,则此时受C<sub>1</sub>约束的C<sub>4</sub>,C<sub>2</sub>,C<sub>12</sub>都可以删去与其相连的边,不再受其约束<br>
此时C<sub>4</sub>,C<sub>2</sub>,C<sub>9</sub>都是入度为0的顶点,假设选择C<sub>2</sub>输出,则删除其出边,即C<sub>3</sub>不再受其约束<br>
以此类推...<br>
如此便线性输出了C<sub>1</sub>到C<sub>12</sub>这样的一个拓扑序列<br>
>即也是一种将非线性结构转化为线性结构的过程<br>

[注]<br>
一个AOV网的拓扑序列不是唯一的,主要取决于从哪个顶点开始<br>
AOV网中如果出现回路则一定不能完成拓扑排序,否则会产生死锁的现象<br>

拓扑排序算法思路
--------
对邻接表表示的图进行拓扑排序<br>
回忆下之前邻接表表示图的定义:<br>
```c
typedef struct GRAPHLISTNODE_STRU
{
    int nodeno; //图中结点的编号
    struct GRAPHLISTNODE_STRU * next;
}GraphListNode;

typedef struct GRAPHLIST_STRU
{
    int size;   //图中实际的结点个数
    GraphListNode * graphListArray; //图的顶点表,用二维数组表示
}GraphList;
```
例如这样的图和邻接表:<br>
![F27](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic27.png)<br>
<br>
在这里,邻接表就是出边表<br>
<br>
算法核心过程:<br>
* <font color=red><1>计算各个顶点的入度</font><br>
* <font color=red><2>将入度为0的顶点入栈</font><br>
* <font color=purple><3>如果栈不空,则从栈中取出一个元素v,输出到拓扑序列中</font><br>
* <font color=green><4>检查顶点v的出边表,将出边表中的每个顶点w的入度减1(即删除顶点v为弧头的边表),如果w的入度为0,则顶点w入栈</font><br>
* <font color=blue><5>重复第三步和第四步,直到栈为空为止</font><br>
>请注意,这里使用了栈(后进先出)<br>

在拓扑排序的具体实现中,需要建立一个inPoint数组,这个数组用于保存各个顶点的入度<br>
同时还需要一个栈nodeStack,每当一个顶点的入度为0时,就入栈<br>

下表显示了实际的排序过程:<br>
![F26](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic26.png)<br>
<br>
>初始各个顶点入度需要先通过循环计算得出,之后再进行拓扑排序<br>
>一般更新的顶点入度是和之前输出的顶点有联系的顶点,而不是所有的顶点入度都更新<br>
>V<sub>2</sub>和V<sub>4</sub>入栈的顺序,要看哪一个顶点在邻接表中先出现<br>
>请注意在入栈时顶点是头插法,要想栈输出5,2,1,就需要输入的顺序为1,2,5<br>

拓扑排序的代码实现
----------
针对邻接表表示的图,有以下的代码实现:
```c
/****************************************************************/
/* int topologicalsort(GraphList *graphList)					*/
/* 功能:拓扑排序一个图											*/
/* 输入参数graphList:邻接表表示的图								*/
/* 返回值:1--成功	0--失败										*/
/* 创建日期:2019-6-3						Author:Cyber Kaka	*/
/****************************************************************/
int topologicalsort(GraphList *graphList)
{
	int i = 0;	//初始化循环计数器
	int cnt = 0;	//记录拓扑排序中顶点个数的变量
	int nodeNum = 0;	//记录栈顶结点在图中序号的临时变量
	int success = 1;	//排序成功与否的flag

	LinkedStack nodeStack = NULL;	//用于保存从栈中提取的结点内容的临时结点
	GraphListNode *tempNode = NULL;	//用于保存顶点内容的临时结点

	//申请用于保存各个顶点入度的数组空间
	int *inPoint = (int*)malloc(sizeof(int) * graphList->size);
	nodeStack = SetNullStack_Link();	//创建一个空栈

	//初始化inPoint数组,即各个顶点初始入度为0
	for (i = 0;i<graphList->size;i++)
	{
		inPoint[i] = 0;
	}

	//循环计算各个顶点的初始入度,修改inPoint数组
	for (i = 0; i < graphList->size; i++)
	{
		//从图中提取顶点
		tempNode = graphList->graphListArray[i].next;

		//检查顶点的邻接表(出边表)
		while (tempNode!=NULL)
		{
			//邻接表不为空,则入度加1
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//向后查询
		}
	}

	//首先循环将入度为0的顶点入栈,否则栈会为空直接退出函数
	for (i=0;i<graphList->size;i++)
	{
		if (inPoint[i]==0)
		{
			Push_link(nodeStack, i);
		}
	}

	//[Core]如果记录结点的栈不为空
	cnt = 0;	//初始时拓扑排序好的顶点数为0
	while (!IsNullStack_link(nodeStack))
	{
		//取栈顶元素v
		nodeNum = Pop_seq_return(nodeStack);
		printf("%d ", nodeNum);	//输出顶点,此顶点算拓扑排序完成
		Pop_link(nodeStack);	//完成的顶点出栈
		cnt++;	//计数器+1

		//检查v的出边,将每条出边的终端顶点的入度减1
		//若此时该顶点入度为0,则将其入栈
		tempNode = graphList->graphListArray[nodeNum].next;	//检查
		while (tempNode != NULL)
		{
			inPoint[tempNode->nodeno]--;	//出边表中所有相关顶点入度-1
			//检查入度是否为0,是0则入栈
			if (inPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//检查下一个顶点入度
			tempNode = tempNode->next;
		}
	}//栈为空时结束循环

	//若图中所有顶点有未拓扑排序的,则代表排序失败
	if (cnt != graphList->size)
	{
		success = 0;
	}

	return success;	//返回flag
}
```
>具体参照TopologicalSort项目
>可以使用队列替代链栈来保存内容,注意队列是"先进先出"

图的典型应用:关键路径(critical path)
==========
关键路径通常决定项目工期的进度活动序列,通常是项目中最长的路径.<br>
研究内容:<font color=green>AOE</font>网(<font color=green>A</font>ctivity <font color=green>O</font>n <font color=green>E</font>dge network):<br>
* 首先它是一个<font color=red>带权的有向图</font><br>
* 在有向图中,<font color=blue>顶点表示事件</font>,<font color=brown>有向边表示活动</font><br>
* 边上的<font color=purple>权值表示活动持续的时间</font><br>
* 顶点所表示的事件实际上就是它的<font color=red>入边所表示的活动都完成后</font>,<font color=red>开始其出边所表示的活动</font>,这样一种状态<br>
* <font color=orange>只有一个入度为0的顶点</font><br>
* <font color=orange>只有一个出度为0的顶点</font><br>
>

例如下面这个图就是一个AOE网:<br>
![F28](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic28.png)<br>
<br>
由图可见,此工程有11项活动(11条边),9个事件(9个顶点),V<sub>0</sub>是工程开始的事件(入度为0),V<sub>8</sub>是工程结束的事件(出度为0)<br>
从V<sub>0</sub>到V<sub>8</sub>有多条路径,其相关的权值为:<br>
* 1.<font color=green>V<sub>0</sub></font>--><font color=green>V<sub>1</sub></font>--><font color=green>V<sub>4</sub></font>--><font color=green>V<sub>6</sub></font>--><font color=green>V<sub>8</sub></font>&nbsp;<font color=red>(18)</font><br>
* 2.<font color=green>V<sub>0</sub></font>--><font color=green>V<sub>1</sub></font>--><font color=green>V<sub>4</sub></font>--><font color=green>V<sub>7</sub></font>--><font color=green>V<sub>8</sub></font>&nbsp;<font color=red>(18)</font><br>
* 3.V<sub>0</sub>-->V<sub>2</sub>-->V<sub>4</sub>-->V<sub>6</sub>-->V<sub>8</sub>&nbsp;(16)<br>
* 4.V<sub>0</sub>-->V<sub>2</sub>-->V<sub>4</sub>-->V<sub>7</sub>-->V<sub>8</sub>&nbsp;(16)<br>
* 5.V<sub>0</sub>-->V<sub>3</sub>-->V<sub>5</sub>-->V<sub>7</sub>-->V<sub>8</sub>&nbsp;(15)<br>
>其中1和2路径是关键路径,其权值最大,即耗时最久

要实现的AOE网的例子
--------
某建筑公司的工程活动计划表如下:<br>
| 活动名称 | 符号 | 活动时间(天) | 依赖活动 |
|:--------:|:----:|:------------:|:--------:|
|   框架   |  C<sub>0</sub>  |      14      |    --    |
|   屋面   |  C<sub>1</sub>  |      22      |    C<sub>0</sub>    |
|   外墙   |  C<sub>2</sub>  |      25      |    C<sub>0</sub>    |
|   门窗   |  C<sub>3</sub>  |      17      |    C<sub>2</sub>    |
| 卫生管道 |  C<sub>4</sub>  |      34      |    C<sub>2</sub>    |
| 各种电器 |  C<sub>5</sub>  |      35      |    C<sub>1</sub>    |
| 内部装修 |  C<sub>6</sub>  |      12      |   C<sub>4</sub>,C<sub>5</sub>  |
| 外部粉刷 |  C<sub>7</sub>  |      24      |    C<sub>3</sub>    |
| 工程验收 |  C<sub>8</sub>  |      13      |   C<sub>6</sub>,C<sub>7</sub>  |

相应的AOE网为:<br>
![F29](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic29.png)<br>
<br>
该AOE网作为一个图,其逆邻接表和邻接表为:<br>
![F30](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic30.png)<br>
<br>
>因为需要两个表,那么在输入方式相同时,邻接表可以像原先那样创建,但是创建逆邻接表的时候就需要多加考虑了<br>

[注]同之前的逆邻接表和邻接表不同,AOE图中的邻接表每个结点有三部分,除了对应的链接顶点和顶点的指针之外,还有相关的权值(即活动持续时间)<br>

求关键路径的步骤
---------
* 求事件的最早发生时间earliestTime(j)--之后用eT表示<br>
* 求事件的最迟发生时间latestTime(i)--之后用lT表示<br>
* 求活动的最早发生时间activityEarliestTime(k)--之后用aET表示<br>
* 求活动的最迟发生时间activityLatestTime(k)--之后用aLT表示<br>
* 计算活动的时间余量reminder = activityLatestTime(k) - activityEarliestTime(k)<br>
* <font color=red>Reminder = 0 的即为关键活动</font><br>

求事件的最早发生时间
----------
&emsp;&emsp;比如事件V<sub>i</sub>,其最早可能的开始时间,是从开始顶点V<sub>0</sub>到顶点V<sub>i</sub>的最长路径的长度.由此计算事件的最早发生时间.<br>
<br>
<font color=blue>采用正向递推方式</font>:<br>
&emsp;初始时earliestTime[0] = 0;<br>
&emsp;之后的earliestTime[j] = max{earliestTime[i] + weight<vi,vj>}<br>
&emsp;&emsp;>><font color=gray>其中,<vi,vj>是以顶点vj为终点的所有有向边</font><br>
[比如]<br>
&emsp;&emsp;V<sub>2</sub>的最早发生时间就是V<sub>1</sub>的最小发生时间加上V<sub>1</sub>到V<sub>2</sub>的活动持续时间,即14+25=39<br>
&emsp;&emsp;V<sub>6</sub>的最早发生时间就是在<font color=green>V<sub>5</sub>的最小发生时间加上V<sub>5</sub>到V<sub>6</sub>的活动持续时间</font>和<font color=brown>V<sub>2</sub>的最小发生时间加上V<sub>2</sub>到V<sub>6</sub>的活动持续时间</font>两者之间取最大值,即73<br>
<br>
![F29](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic29.png)<br>
<br>
由此得到eT的表如下:<br>
||V<sub>0</sub>|V<sub>1</sub>|V<sub>2</sub>|V<sub>3</sub>|V<sub>4</sub>|V<sub>5</sub>|V<sub>6</sub>|V<sub>7</sub>|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|eT|0|14|39|56|85|36|73|98|

求事件的最迟发生时间
-----------
&emsp;&emsp;比如事件V<sub>i</sub>,其最迟发生时间即为其允许的最迟开始时间,是指在不推迟整个工期的前提下,事件V<sub>i</sub>允许的最晚发生时间.<br>
<font color=blue>采用反向递推方式</font>:<br>
&emsp;初始时latestTime[n-1] = earliestTime[n-1];<br>
&emsp;之后的latestTime[j] = min{latestTime[i] - weight<vj,vi>}<br>
&emsp;&emsp;>><font color=gray>其中,<vi,vj>是以顶点vj为起点的所有有向边</font><br>
[比如]<br>
&emsp;&emsp;V<sub>4</sub>的最迟发生时间为V<sub>7</sub>的最迟发生时间减去V<sub>4</sub>到V<sub>7</sub>的活动持续时间,即85<br>
&emsp;&emsp;V<sub>2</sub>的最迟发生时间为在<font color=green>V<sub>3</sub>的最迟发生时间减去V<sub>2</sub>到V<sub>3</sub>的活动持续时间</font>和<font color=brown>V<sub>6</sub>的最迟发生时间减去V<sub>2</sub>到V<sub>6</sub>的活动持续时间</font>两者之间取最小值,即39<br>
![F29](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic29.png)<br>
<br>
由此得到的lT的表如下:<br>
||V<sub>0</sub>|V<sub>1</sub>|V<sub>2</sub>|V<sub>3</sub>|V<sub>4</sub>|V<sub>5</sub>|V<sub>6</sub>|V<sub>7</sub>|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|eT|0|14|39|56|85|36|73|98|
|lT|0|14|39|61|85|38|73|98|

活动的最早发生时间计算<font color=red>activityEarliestTime</font>
------------
&emsp;&emsp;设C<sub>k</sub>是边<V<sub>i</sub>,V<sub>j</sub>>上的活动,则activityEarliestTime是源点V<sub>0</sub>到起始顶点V<sub>i</sub>的最长路径长度,即为:<br>
activityEarliestTime[k] = earliestTime[i]<br>
<font color=red>即活动的最早发生时间,就是其起始顶点V<sub>i</sub>的最早发生时间</font><br>

![F29](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic29.png)<br>
<br>
由此得到eT和aET的对比表如下:<br>
||V<sub>0</sub>|V<sub>1</sub>|V<sub>2</sub>|V<sub>3</sub>|V<sub>4</sub>|V<sub>5</sub>|V<sub>6</sub>|V<sub>7</sub>|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|aET|0|14|14|39|39|36|73|56|85|
|eT|0|14|39|56|85|36|73|98|

活动的最迟发生时间计算<font color=red>activityLatestTime</font>
------------
&emsp;&emsp;设C<sub>k</sub>是边<V<sub>i</sub>,V<sub>j</sub>>上的活动,则activityLatestTime[k]是在不引起时间延误的前提下,活动C<sub>k</sub>允许的最迟时间,也就是顶点V<sub>j</sub>的最迟发生时间减去活动C<sub>k</sub>持续的时间weight<V<sub>i</sub>,V<sub>j</sub>>,即为:<br>
activityLatestTime[k] = latestTime[j] - weight<V<sub>i</sub>,V<sub>j</sub>><br>
<font color=red>即活动的最迟发生时间,就是其终止顶点V<sub>j</sub>的最迟发生时间减去活动的持续时间</font><br>

![F29](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic29.png)<br>
<br>
由此得到lT和aLT的对比表如下:<br>
||V<sub>0</sub>|V<sub>1</sub>|V<sub>2</sub>|V<sub>3</sub>|V<sub>4</sub>|V<sub>5</sub>|V<sub>6</sub>|V<sub>7</sub>|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|lT|0|14|39|61|85|38|73|98|
|aLT|0|16|14|44|39|38|93|61|85|

活动的时间余量计算<font color=red>reminder</font>
-------------
&emsp;&emsp;reminder[k]表示活动C<sub>k</sub>的最早发生时间和最迟发生时间的时间余量<br>
即:reminder[k] = activityLatestTime[k] - activityEarliestTime[k]<br>
当activityLatestTime[k] = activityEarliestTime[k]时,reminder[k] = 0<br>
表示该活动C<sub>k</sub>的<font color=red>时间余量为0</font>,<font color=red>即该活动为关键活动</font>,关键活动的延期与否直接影响到项目的工期,这是项目经理需要重点关注的内容<br>
<font color=red>即活动的时间余量是其最迟发生时间和最早发生时间的差值</font><br>

![F29](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic29.png)<br>
<br>
由此得到reminder和aLT以及aET的对比表如下:<br>
||V<sub>0</sub>|V<sub>1</sub>|V<sub>2</sub>|V<sub>3</sub>|V<sub>4</sub>|V<sub>5</sub>|V<sub>6</sub>|V<sub>7</sub>|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|aET|0|14|14|39|39|36|73|56|85|
|aLT|0|16|14|44|39|38|93|61|85|
|reminder|0|2|0|5|0|2|0|5|0|
|是否为关键活动|T|F|T|F|T|F|T|F|T|

使用代码计算事件的eT和lT
------------
* 事件V<sub>j</sub>可能的<font color=green>最早发生时间</font>earliestTime(j)<br>
        <font color=red>初始earliestTime[0] = 0;</font><br>
        <font color=red>earliestTime[j] = max{ earliestTime[i] + weight<vi,vj>}</font><br>
* 事件V<sub>i</sub>允许的<font color=green>最迟发生时间</font>latestTime(i)<br>
        <font color=red>初始latestTime[n-1] = earliestTime[n-1];</font><br>
        <font color=red>latestTime[j] = min{ latestTime[i] - weight<vj,vi>}</font><br>
>在计算最早发生时间时,要判断事件的入度,需要使用邻接表<br>
>而在计算最迟发生时间时,要判断事件的出度,需要使用逆邻接表<br>

![F30](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic30.png)<br>
<br>

回忆拓扑排序时的操作,我们就已经做了每个事件的入度-1操作,并且有入栈和出栈的操作,这里则需要计算每一个事件的最早发生时间,因此可以在拓扑排序的基础上进行拓展来计算事件的最早发生时间,同样的,也可以借此来计算事件的最迟发生时间<br>

```c
/****************************************************************/
/*int eventEarliestTime(GraphList *graphList, int *earliestTime)*/
/*	功能:求事件可能的最早发生时间								*/
/*	输入参数graphList:用邻接表表示的图							*/
/*	输入参数earliestTime:事件可能的最早发生时间					*/
/*	返回值success:1--成功	0--失败								*/
/*	创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
int eventEarliestTime(GraphList *graphList, int *earliestTime)
{
	int i = 0;	//初始化循环计数器
	int cnt = 0;	//记录拓扑排序中顶点个数的变量
	int nodeNum = 0;	//记录栈顶结点在图中序号的临时变量
	int success = 1;	//排序成功与否的flag

	LinkedStack nodeStack = NULL;	//用于保存从栈中提取的结点内容的临时结点
	GraphListNode *tempNode = NULL;	//用于保存顶点内容的临时结点

	//申请用于保存各个顶点入度的数组空间
	int *inPoint = (int*)malloc(sizeof(int) * graphList->size);
	nodeStack = SetNullStack_Link();	//创建一个空栈

	//初始化inPoint数组,即各个顶点初始入度为0
	for (i = 0; i < graphList->size; i++)
	{
		inPoint[i] = 0;
	}

	//循环计算各个顶点的初始入度,修改inPoint数组
	for (i = 0; i < graphList->size; i++)
	{
		//从图中提取顶点
		tempNode = graphList->graphListArray[i].next;

		//检查顶点的邻接表(出边表)
		while (tempNode != NULL)
		{
			//邻接表不为空,则入度加1
			inPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//向后查询
		}
	}

	//首先循环将入度为0的顶点入栈,否则栈会为空直接退出函数
	for (i = 0; i < graphList->size; i++)
	{
		if (inPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}

	//[Core]如果记录结点的栈不为空
	cnt = 0;	//初始时拓扑排序好的顶点数为0
	while (!IsNullStack_link(nodeStack))
	{
		//取栈顶元素v
		nodeNum = Pop_seq_return(nodeStack);
		//printf("%d ", nodeNum);	//输出顶点,此顶点算拓扑排序完成
		Pop_link(nodeStack);	//完成的顶点出栈
		cnt++;	//计数器+1

		//检查v的出边,将每条出边的终端顶点的入度减1
		//若此时该顶点入度为0,则将其入栈
		tempNode = graphList->graphListArray[nodeNum].next;	//检查
		while (tempNode != NULL)
		{
			//去掉入边
			inPoint[tempNode->nodeno]--;	//出边表中所有相关顶点入度-1
			//为每条出边的终点事件更新可能的最早发生时间
			if (earliestTime[tempNode->nodeno] < earliestTime[nodeNum] + tempNode->weight)
			{
				earliestTime[tempNode->nodeno] = earliestTime[nodeNum] + tempNode->weight;
			}

			//检查入度是否为0,是0则入栈
			if (inPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//检查下一个顶点入度
			tempNode = tempNode->next;
		}
	}//栈为空时结束循环

	//若图中所有顶点有未拓扑排序的,则代表排序失败
	if (cnt != graphList->size)
	{
		success = 0;
	}

	return success;	//返回flag
}//O(n+1)

/****************************************************************************/
/*	int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)*/
/*	功能:计算事件允许的最迟发生时间											*/
/*	输入参数graphInverseList:用逆邻接表表示的图								*/
/*	输入参数latestTime:事件允许的最迟发生时间数组							*/
/*	返回值success:1--成功	0--失败											*/
/*	创建日期:2019-6-4									Author:Cyber Kaka	*/
/****************************************************************************/
int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)
{
	int i = 0;	//初始化循环计数器
	int cnt = 0;	//记录拓扑排序中顶点个数的变量
	int nodeNum = 0;	//记录栈顶结点在图中序号的临时变量
	int success = 1;	//排序成功与否的flag

	LinkedStack nodeStack = NULL;	//用于保存从栈中提取的结点内容的临时结点
	GraphInverseListNode *tempNode = NULL;	//用于保存顶点内容的临时结点

	//申请用于保存各个顶点出度的数组空间
	int *outPoint = (int*)malloc(sizeof(int) * graphInverseList->size);
	nodeStack = SetNullStack_Link();	//创建一个空栈

	//初始化inPoint数组,即各个顶点初始出度为0
	for (i = 0; i < graphInverseList->size; i++)
	{
		outPoint[i] = 0;
	}

	//循环计算各个顶点的初始出度,修改outPoint数组
	for (i = 0; i < graphInverseList->size; i++)
	{
		//从图中提取顶点
		tempNode = graphInverseList->graphInverseListArray[i].next;

		//检查顶点的邻接表(出边表)
		while (tempNode != NULL)
		{
			//邻接表不为空,则入度加1
			outPoint[tempNode->nodeno]++;
			tempNode = tempNode->next;	//向后查询
		}
	}

	//首先循环将出度为0的顶点入栈,否则栈会为空直接退出函数
	for (i = 0; i < graphInverseList->size; i++)
	{
		if (outPoint[i] == 0)
		{
			Push_link(nodeStack, i);
		}
	}

	//[Core]如果记录结点的栈不为空
	cnt = 0;	//初始时拓扑排序好的顶点数为0
	while (!IsNullStack_link(nodeStack))
	{
		//取栈顶元素v
		nodeNum = Pop_seq_return(nodeStack);
		//printf("%d ", nodeNum);	//输出顶点,此顶点算拓扑排序完成
		Pop_link(nodeStack);	//完成的顶点出栈
		cnt++;	//计数器+1

		//检查v的入边,将每条入边的终端顶点的出度减1
		//若此时该顶点出度为0,则将其入栈
		tempNode = graphInverseList->graphInverseListArray[nodeNum].next;	//检查
		while (tempNode != NULL)
		{
			//去掉出边
			outPoint[tempNode->nodeno]--;	//入边表中所有相关顶点出度-1
			//为每条出边的终点事件更新可能的最迟发生时间
			if (latestTime[tempNode->nodeno] < latestTime[nodeNum] + tempNode->weight)
			{
				latestTime[tempNode->nodeno] = latestTime[nodeNum] + tempNode->weight;
			}

			//检查出度是否为0,是0则入栈
			if (outPoint[tempNode->nodeno] == 0)
			{
				Push_link(nodeStack, tempNode->nodeno);
			}
			//检查下一个顶点出度
			tempNode = tempNode->next;
		}
	}//栈为空时结束循环

	//若图中所有顶点有未拓扑排序的,则代表排序失败
	if (cnt != graphInverseList->size)
	{
		success = 0;
	}

	return success;	//返回flag
}//O(n+1)
```
>具体实现参照CriticalPath项目<br>

计算关键路径的实现
---------
```c
/********************************************************************************/
/*	void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)	*/
/*	功能:根据一个图的邻接表和逆邻接表计算关键路径								*/
/*	输入参数graphList:用邻接表表示的图											*/
/*	输入参数graphInverseList:用逆邻接表表示的图									*/
/*	返回值:无																	*/
/*	创建日期:2019-6-4										Author:Cyber Kaka	*/
/********************************************************************************/
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)
{
	int i = 0;	//用于循环体的计数器
	int max = 0;	//用于保存最早发生时间的最大值的临时变量

	//申请最早发生时间数组的空间
	int* earliestTime = (int*)malloc(sizeof(int) * graphList->size);
	//申请最迟发生时间数组的空间
	int* latestTime = (int*)malloc(sizeof(int) * graphInverseList->size);

	int activityEarliestTime = 0;
	int activityLatestTime = 0;

	GraphListNode *tempNode = NULL;

	//初始化所有事件可能的最早发生时间为0
	for (i=0;i<graphList->size;i++)
	{
		earliestTime[i] = 0;
	}

	//调用算法,求每个事件可能的最早发生时间
	eventEarliestTime(graphList, earliestTime);

	//求事件最早发生时间的最大值,方便后面设置事件允许最迟发生时间的初值
	max = earliestTime[0];
	for (i=0;i<graphList->size;i++)
	{
		if (max<earliestTime[i])
		{
			max = earliestTime[i];
		}
	}

	//初始化所有事件允许的最迟发生时间为最大值
	for (i=0;i<graphInverseList->size;i++)
	{
		latestTime[i] = max;
	}

	//调用算法,求每个事件允许的最迟发生时间
	eventLatestTime(graphInverseList, latestTime);

	//初始化任务完成

	//遍历每条边,求每个活动的最早开始时间和最晚开始时间,并进行对比
	//相等即为关键路径上的边,也就是两者时间余量为0
	for (i=0;i<graphList->size;i++)
	{
		tempNode = graphList->graphListArray[i].next;

		while (tempNode != NULL)
		{
			activityEarliestTime = earliestTime[i];
			activityLatestTime = latestTime[tempNode->nodeno] - tempNode->weight;

			if (activityEarliestTime == activityLatestTime)
			{
				printf("<v%2d,v%2d>", i, tempNode->nodeno);
			}
			tempNode = tempNode->next;
		}
	}
}//O(n+1)
```
>具体实现参照CriticalPath项目<br>
>该算法的算法时间复杂度为O(n+1)<br>

<font color=red>**[注]CriticalPath项目仍有许多需要修改的地方,甚至有遗留问题内容,请注意在结课后修改**</font><br>

图的应用--六度空间 (Six Degrees of Separation)
=========
&emsp;&emsp;六度空间理论是一个数学领域的猜想,又称为<font color=red>六度分割理论或者小世界理论</font>.在社交网络中,通过6个人可以找到一个陌生人,也就是最多通过5个中间人你就能找到一个陌生人.<br>

[如何实现呢?]<br>
在之前,我们通过广度优先搜索遍历能够记录<font color=red>图的层数</font>,因而可以记录层数level=6的顶点个数.我们可以在其基础上进行修改:<br>
* 设置变量cnt,用来记录满足六度空间的顶点个数,将其作为此时BFS()算法的返回值.<br>
* 从每个顶点出发进行BFS,记录满足六层的结点个数cnt,然后计算cnt占总顶点个数的百分比.<br>

我们同样使用队列完成,以下为sixdegree.cpp的代码:<br>
>实际上,这里的visited数组是可以省略的,因为这里仅仅是计算个数,并不需要判断一个结点是否仅被访问了一次<br>
```c
#include "bfs_graphlist.h"
#include <stdio.h>
#include <stdlib.h>
//如果是C++则可以使用STL也可以使用自己定义的队列
//如果是C则只能使用自己定义的队列
#include <queue>
using namespace std;

//修改之后的BFS_level
int BFS_level(GraphList* graphList,int *visited,int source)
{
    int tempVex = 0;    //临时变量
    int level = 0;  //记录广度优先搜索树的层数
    int last = source;  //用last保存上一层最后访问的结点
    int tail = source;  //用tail来记录当前最后访问的结点
    int cnt = 1;    //记录满足六度空间的结点个数
    GraphListNode *tempNode = NULL;
    queue<int> waitingQueue;
    //注意,在这里对每个结点调用时需要重新初始化visited
    //因为在六度空间中并不是遍历一次图,而是要遍历多次
    for(int i = 0;i<graphlist->size;i++)
    {
        visited[i] = 0;
    }
    visited[source] = 1;    //设置标记,表明已经被访问
    printf("%d ",source);   //输出访问的结点编号
    waitingQueue.push(source);  //将刚访问的结点放入队列
    //广度优先访问结点
    while(!waitingQueue.empty())
    {
        tempVex = waitingQueue.front();
        waitingQueue.pop();
        //依次访问与当前结点相邻的点
        tempNode = graphList->graphListArray[tempVex].next;
        while(tempNode != NULL)
        {
            //如果其他顶点与当前顶点存在边且未访问过
            if(!visited[tempNode->nodeno])
            {
                visited[tempNode->nodeno] = 1;  //做标记
                waitingQueue.push(tempNode->nodeno);    //入队
                // printf("%d ",tempNode->nodeno);  //输出
                cnt++;
                tail = tempNode->nodeno;
            }
            tempNode = tempNode->next;  //移动到下一个结点
        }
        //从队列中取出的结点的下一层都访问后
        //再判断该结点是否是其所在层的最后结点
        if(tempVex == last)
        {
            level++;
            last = tail;
            //  printf("The current level is %d\n", level);
        }

        if(level == 6)
        {
            break;
        }
    }
    return cnt;
}

//六度空间的过程
void SixDegreeofSeperation(GraphList* graphList)
{
    int i = 0;
    int cnt = 0;
    //用于记录图中哪些结点已经被访问了
    int *visited = (int*)malloc(sizeof(int) * graphList->size);
    //从0号结点开始进行广度优先遍历
    for(i = 0;i<graphList->size;i++)
    {
        cnt = BFS_level(graphList,visited,i);
        printf("%d:%.2f\n",i,cnt*100.0/graphList->size);
    }
}

```

相关的主程序代码为:<br>
```c
#include "dfs_graphlist.h"
#include "bfs_graphlist.h"
#include "sixdegree.h"
#include <stdio.h>
#include <stdlib.h>

/*
0 1
1 0
1 2
2 1
2 3
3 2
3 4
4 3
4 5
5 4
5 6
6 5
6 7
7 6
7 8
8 7
8 9
9 8
-1 -1
*/
//计算邻接表表示的图的六度空间百分比
//从每一个结点出发进行遍历,其满足六度空间的结点占总结点个数的百分比
int main(void)
{
    GraphList *graphList = NULL;

    graphList = InitGraph(10);

    ReadGraph(graphList);

    SixDegreeofSeperation(graphList);

    printf("\n");

    return 0;
}
```
>具体项目略<br>
>在这里不用邻接矩阵表示的图的原因是,当关系网过大之后,其消耗的空间很多,而边的个数e是远远小于n<sup>2</sup>的,即考虑到空间的消耗,使用邻接表是更为稳妥的办法<br>

图的综合应用--中国邮递员问题
==========
相关知识点:<br>
* 图的存储表示 (邻接矩阵,邻接表)<br>
* 顶点的度数 (遍历)<br>
* 图的连通性 (拓扑排序)<br>
* 顶点间的最短路径 (迪杰斯特拉算法)<br>
* 欧拉图的判断,欧拉回路输出<br>

问题提出:我做数学家管梅谷先生在20世纪60年代提出<br>
[问题描述]<br>
一个邮递员从邮局出发走遍每条街道,最后返回邮局,请找到一条最短的行走路线.<br>
以下图表示,绿点为邮局,红点为各个街区的信箱,边表示街道,现在的问题就是如何找到最短的行走线路.<br>
![F31](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic31.png)<br>
<br>
>前两个图的走法没有什么问题,可以很容易地找到最短路径<br>
>第三个图中,先走完五角星,然后走完五边形,则会多出两条街道,走回邮局需要多走一条线路<br>

那么这种路线是如何找到的呢?这就是一个<font color=red>最短欧拉回路</font>问题.<br>
>其实就是一笔画的游戏而已.<br>

[例子]<br>
![F32](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic32.png)<br>
<br>
[总结]<br>
满足"一笔画":<br>
* 凡是由偶点组成的连通图,一定可以一笔画成,画时可以把任一偶点作为起点,最后一定能以这个点为终点画完此图<br>
* 凡是只有两个奇点的连通图(其余都为偶点),一定可以一笔画成.画时必须把一个奇点作为起点,另一个奇点作为终点<br>
* 除上述两种,其他情况的图都不能一笔画出<br>
[知识回顾]<br>
偶点:结点的度为偶数<br>
奇点:结点的度为奇数<br>
>度:结点拥有的子结点的个数<br>

中国邮递员问题实例
--------
[例]一个邮递员投递信件要走的街道如图所示,图中的数字表示各条街道的距离(km),他从邮局出发,要走遍各街道,最后回到邮局.怎样走才能使所走的行程最短?全程一共多少千米?<br>
![F33](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic33.png)<br>
<br>

首先要判断这个图是否为欧拉图,如果不是,<font color=brown>怎么样能使其变为欧拉图</font>.<br>
解决方式很简单,除去<font color=blue>奇点</font>即可,可以加边或减边,这里以重复走某些边为例.<br>

[分析]<br>
![F34](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic34.png)<br>
<br>
图中共有8个奇点,不可能不重复地走遍所有的路.必须在8个奇点间添加4条线,才能消除所有奇点,从而成为能从邮局出发最后返回邮局的一笔画.当然,要在<font color=green>距离最近的两个奇点间添加一条连线</font>,如图中所示,共添加了4条线,这4条线表示要重复走的路,显然,这样重复走的路程最短,全程34千米,但走法可以是不唯一的.<br>

[相关内容]<br>
* 建立街区无向图的邻接矩阵<br>
* 求各顶点的度数<br>
* 求出所有奇度点<br>
* 图的连通性的判断<br>
* <font color=purple>求出每一个奇度点到其他奇度结点的最短路径</font><br>
* <font color=purple>根据最佳方案添加边,对图进行修改,使其满足一笔画</font><br>
* <font color=purple>对图进行一笔画,并输出</font><br>

* 1."添加"哪些边<br>
        * 添加的边所依附的顶点必须都是<font color=red>奇度顶点</font><br>
        * 添加的边必须是<font color=red>已有</font>的边,也就是重复走图中的边<br>
* 2.如何选择代价最小的边<br>
        * 奇数顶点之间的最短路径<br>
        &emsp;<1>Dijkstra算法<br>
        &emsp;<2>Floyd算法<br>
* 3.如何输出一笔画<br>
        * FE算法 (<font color=pink>F</font>leury <font color=pink>E</font>uler)<br>

中国邮递员问题具体实例
----------
[完备匹配]<br>
给定一个图G,M为G边集的一个子集,如果M满足当中的任意两条边都不依附于同一个顶点,则称M是一个<font color=red>匹配</font><br>
如果任意一个匹配中,图中的每个顶点都和图中某条边相关联,则称此匹配为<font color=blue>完全匹配</font>,也称作<font color=blue>完备匹配</font><br>

![F35](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic35.png)<br>
<br>
>假设上图中V<sub>1</sub>为邮局<br>

[内容]<br>
* 1.求奇度点的最短路径<br>
* 2.构造奇度点之间的完全加权图,V表示奇度点,U表示偶度点<br>
* 3.求图的最佳(总权最小)完备匹配M={1,4;2,3},即(V<sub>1</sub>-->U<sub>1</sub>-->V<sub>4</sub>)和(V<sub>2</sub>-->U<sub>4</sub>-->V<sub>3</sub>)需要重复走<br>
* 4.求1和4之间的最短轨V<sub>1</sub>&nbsp;U<sub>1</sub>&nbsp;V<sub>4</sub>;2和3之间的最短轨V<sub>2</sub>&nbsp;U<sub>4</sub>&nbsp;V<sub>3</sub>;<br>
* 5.加同权边即可<br>

[使用FE算法输出欧拉回路]<br>
* 1.取G中的起始顶点V<sub>0</sub>,令P<sub>0</sub>=V<sub>0</sub><br>
* 2.假设沿着P<sub>i</sub>=v<sub>0</sub>e<sub>1</sub>v<sub>1</sub>e<sub>2</sub>...e<sub>i</sub>v<sub>i</sub>走到顶点V<sub>i</sub>,按下面方法从E(G)-{e<sub>1</sub>,e<sub>2</sub>,...,e<sub>i</sub>}中选e<sub>i+1</sub>这条边<br>
&emsp;① e<sub>i+1</sub>与V<sub>i</sub>相关联<br>
&emsp;② 除非没有别的边可供选择,否则e<sub>i+1</sub>不应该是G<sub>i</sub>=G-{e<sub>1</sub>,e<sub>2</sub>,...,e<sub>i</sub>}中的桥<br>
* 3.当2不能再进行时算法停止<br>

例如下图中V<sub>5</sub>-->V<sub>6</sub>就是一个桥,一般先选不是桥的边,如V<sub>5</sub>-->V<sub>2</sub><br>
![F36](https://github.com/CyberYui/DataStructures/blob/master/C/Graph/GraphPic36.png)<br>
<br>

[总结步骤]
* 1.求图中奇度结点集合Vo={v}
* 2.对Vo中的每个顶点对(u,v),用Dijkstra算法求距离d(u,v)
* 3.构造加权完全图
* 4.求加权图的总权最小的完备匹配M
* 5.在G中求M中同一边的结点间的最短轨
* 6.把G中在上一步求得的每条最短轨之边变成同权倍边,得到欧拉图G1
* 7.用FE算法求G1的一条欧拉回路W,W即为解,W不唯一