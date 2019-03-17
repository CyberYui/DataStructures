#include <iostream>
#include <stdlib.h>

#include "MapAdvPrim.h"
using namespace std;

/************************************************************************/
/*  项目名称:Project11
/*  项目描述:关于图的实验内容
/*  创建时间:2019-3-15
/*  Author:Cyber Kaka
/************************************************************************/

/************************************************************************/
/* 图的最小生成树之普里姆算法
/*
/*		A			//这个图中涉及到了边的权值,相对于普通的图来说,复杂了
/*	 /  |  \		//因此声明了Edge.h+.cpp
/*	B---F---E
/*	 \ / \ /
/*	  C---D
/*
/*	A B C D E F		//顶点
/*	0 1 2 3 4 5		//对应索引
/*
/*	A-B(6)	A-E(5)	A-F(1)
/*	B-C(3)	B-F(2)
/*	C-F(8)	C-D(7)
/*	D-F(4)	D-E(2)
/*	E-F(9)
/*
/************************************************************************/

int main(void)
{
	//顶点和对应序号进行介绍
	cout << "顶点为:A B C D E F" << endl;
	cout << "序号为:0 1 2 3 4 5" << endl;
	//创建图
	CMap *pMap = new CMap(6);
	//创建顶点,记得修改输出函数printMatrix()
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	//将顶点添加进图中
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	//设置邻接矩阵,由于是无向图,写一半就好,即十条边
	pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);//A->B
	pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);//A->E
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);//A->F
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);//B->C
	pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);//B->F
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);//C->F
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);//C->D
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);//D->F
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);//D->E
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);//E->F
	//调用普里姆生成树,应为A->F->B->C->D->E
	//边为:A-F(1),F-B(2),B-C(3),F-D(4),D-E(2)
	pMap->primTree(0);//从0开始,即从A开始
	//测试结束

	system("pause");
	return 0;
}