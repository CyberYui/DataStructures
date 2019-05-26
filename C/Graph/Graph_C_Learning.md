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
void WriteGraph(GraphList* graphList)
{
	int i = 0;
	GraphListNode *tempNode = NULL;	//申请临时结点用于数据传输

	tempNode = (GraphListNode *)malloc(sizeof(GraphListNode));
	tempNode->next = NULL;
	tempNode->nodeno = 0;

	printf("图的结构如下:\n");
	while(i < graphList->size - 1)	//数组是从0开始算的,但是保存的size=num=输入的值(比如测试的这里是4)
	{
		tempNode = graphList->graphListArray[i].next;
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