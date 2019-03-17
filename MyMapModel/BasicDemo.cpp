#include <iostream>
#include <stdlib.h>

#include "MapBasic.h"
using namespace std;

/************************************************************************/
/*  项目名称:Project11
/*  项目描述:关于图的实验内容
/*  创建时间:2019-3-15
/*  Author:Cyber Kaka
/************************************************************************/

/************************************************************************/
/* 图的存储与图的遍历
/*						//邻接矩阵的存储方法
/*			 A			//图的深度优先遍历和广度优先遍历
/*		   /   \
/*		  B	    D		//左侧为有8个顶点的图
/*		 / \   / \		//可见是一个无向图
/*	    C	F G - H
/*		 \ /
/*        E
/*	//其邻接矩阵为:
/*	  |A|B|C|D|E|F|G|H|		//默认权值都为1
/*	A |\|1| |1| | | | |		//矩阵关于主对角线对称
/*	B |1|\|1| | |1| | |
/*	C | |1|\| |1|1| | |
/*	D |1| | |\| | |1|1|
/*	E | | |1| |\| | | |
/*	F | |1|1| | |\| | |
/*	G | | | |1| | |\|1|
/*	H | | | |1| | |1|\|		//'\'表示对称轴
/*
/************************************************************************/

int main(void)
{
	//创建图
	CMap *pMap = new CMap(8);
	//创建顶点
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');
	//将顶点添加进图中
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);
	//设置邻接矩阵,由于是无向图,写一半就好
	//一共九对边,要一一设置一条
	//注意行和边都是从0开始算的
	pMap->setValueToMatrixForUndirectedGraph(0, 1);//A->B
	pMap->setValueToMatrixForUndirectedGraph(0, 3);//A->D
	pMap->setValueToMatrixForUndirectedGraph(1, 2);//B->C
	pMap->setValueToMatrixForUndirectedGraph(1, 5);//B->F
	pMap->setValueToMatrixForUndirectedGraph(2, 4);//C->E
	pMap->setValueToMatrixForUndirectedGraph(2, 5);//C->F
	pMap->setValueToMatrixForUndirectedGraph(3, 6);//D->G
	pMap->setValueToMatrixForUndirectedGraph(3, 7);//D->H
	pMap->setValueToMatrixForUndirectedGraph(6, 7);//G->H
	//打印一下看效果
	pMap->printMatrix();//可见是一致的数组
	cout << endl;
	//调用深度优先遍历
	pMap->depthFirstTraverse(0);//指定起点,即A,索引为0
	cout << endl;
	//清理一次已访问标识
	pMap->resetNode();
	//调用广度优先遍历
	pMap->breadthFirstTraverse(0);//指定起点为A
	//测试结束

	system("pause");
	return 0;
}