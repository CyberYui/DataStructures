此目录的文件皆关于一种独特的数据结构-----图(Graph/Map)
===========================
目录包含19个文件(待定),一共三组(待定)
------------------------
* 第一组:BasicDemo.cpp<br>
　　　　MapBasic.h+MapBasic.cpp<br>
　　　　NodeBasic.h+NodeBasic.cpp

        这五个文件是关于无向图的存储及遍历的内容,
        定义了一个无向图的相关邻接矩阵,并进行了测试
        BasicDemo.cpp
        内容:
        包含主函数,以及一个简单的图,注释中展示了图的样子
        代码中对其进行设置等操作,测试了MapBasic.h中写的函数

        MapBasic.h
        内容:
        包含CMap类(由于Map是关键字)及相关成员函数,以及一些注释说明
        简要介绍了函数声明的原因和相关内容的功能

        MapBasic.cpp
        内容:
        对于MapBasic.h文件各个函数的具体声明,以及逻辑思想
        附有相关代码的注释,以及各个函数体的操作说明和解释

        NodeBasic.h
        内容:
        一个很简单的结点类,用来声明顶点的相关函数

        NodeBasic.cpp
        内容:
        包括了对NodeBasic.h中的构造函数的书写,很简单的一个函数

* 第二组:AdvPrimDemo.cpp<br>
　　　　MapAdvPrim.h+MapAdvPrim.cpp<br>
　　　　MapAdvPrimNode.h+MapAdvPrimNode.cpp<br>
　　　　MapAdvPrimEdge.h+MapAdvPrimEdge.cpp

        这七个文件是关于无向图的普里姆算法生成最小生成树的内容,
        定义了一个无向图,并进行了简单的生成树测试
        AdvPrimDemo.cpp
        内容:
        关于实验内容的表示,以及对普里姆生成树的测试,
        附有简单的注释内容

        MapAdvPrim.h
        内容:
        在MapBasic.h的基础上增加了内容,定义了普利姆算法的成员函数

        MapAdvPrim.cpp
        内容:
        对MapBasic.h的相关函数的实现及修改,实现了普里姆生成树算法

        MapAdvPrimNode.h
        内容:
        结点类用于初始化顶点,声明了相关内容

        MapAdvPrimNode.cpp
        内容:
        对MapAdvPrimNode.h的内容的实现

        MapAdvPrimEdge.h
        内容:
        定义相关的边的构造函数以及相应的成员变量

        MapAdvPrimEdge.cpp
        内容:
        对MapAdvPrimEdge.h中构造函数的实现

* 第三组:AdvKruskalDemo.cpp<br>
　　　　MapAdvKruskal.h+MapAdvKruskal.cpp<br>
　　　　MapAdvKruskalNode.h+MapAdvKruskalNode.cpp<br>
　　　　MapAdvKruskalEdge.h+MapAdvKruskalEdge.cpp

        这七个文件是关于无向图的克鲁斯卡尔算法生成最小生成树的内容,
        定义了一个无向图,并进行了简单的测试
        AdvKruskalDemo.cpp
        内容:
        介绍关于实验的内容,并建立了一个无向图进行测试

        MapAdvKruskal.h
        内容:
        基于之前的MapAdvPrim.h基础上,添加了关于克鲁斯卡尔算法的内容,
        并对声明进行了简要的解释

        MapAdvKruskal.cpp
        内容:
        对于MapAdvKruskal.h声明内容的实现,附有大量的注释解释内容

        MapAdvKruskalNode.h
        内容:
        定义顶点相关的内容声明

        MapAdvKruskalNode.cpp
        内容:
        对构造函数进行函数体实现

        MapAdvKruskalEdge.h
        内容:
        定义相关的边的内容声明

        MapAdvKruskalEdge.cpp
        内容:
        对边的构造函数的函数体实现

[PS]关于图的知识:<br>
　　图（Graph）是由顶点的有穷非空集合和顶点之间边的集合组成，通常表示为：G(V,E)，其中，G表示一个图，V是图G中顶点的集合，E是图G中边的集合。<br>
　　比如下面这样:<br>
　　图（Graph）是一种复杂的非线性结构，在图结构中，每个元素都可以有零个或多个前驱，也可以有零个或多个后继，也就是说，元素之间的关系是任意的。<br>
　　在计算机科学中，一个图就是一些顶点的集合，这些顶点通过一系列边结对（连接）。顶点用圆圈表示，边就是这些圆圈之间的连线。顶点之间通过边连接。<br>
　　线性表和树两类数据结构，线性表中的元素是“一对一”的关系，树中的元素是“一对多”的关系，本章所述的图结构中的元素则是“多对多”的关系。<br>

>本文件编写完成于2019-03-17-12:49