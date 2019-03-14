/************************************************************************/
/* 二叉树(数组表示)
/*	   要求:完成树的基本操作
/*			1.树的创建和销毁
/*			2.树中节点的搜索
/*			3.树中节点的添加与删除
/*			4.树中节点的遍历
/* (C语言内容)
/*	   BOOL CreateTree(Tree **pTree,Node *pRoot);				//创建树
/*	   void DestroyTree(Tree *pTree);							//销毁树
/*	   Node *SearchNode(Tree *pTree,int nodeIndex);				//根据索引寻找节点
/*
/*	   //添加节点
/*	   BOOL AddNode(Tree *pTree,int nodeIndex,int direction,Node *pNode);
/*	   BOOL DeleteNode(Tree *pTree,int nodeIndex,Node *pNode);	//删除节点
/*	   void TreeTraverse(Tree *pTree);							//遍历
/*
/* 关于数组与树之间的算法转换
/*
/*	   int tree[n]   3    			[二叉树的规律]:
/*					5 8				父亲节点下标*2+1=该节点左
/*				  2 6 9 7			父亲节点下标*2+2=该节点右
/*
/* 二叉树的排列如下:   方式:值(索引)
/*----索引是数组天生具有的属性
/*			   3(0)
/*
/*		5(1)			8(2)
/*
/*	2(3)	6(4)	9(5)	7(6)
/*----对于只有一侧孩子的情况,将其另一侧孩子值设为0,即成了单侧有节点情况
/*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "TreeBasic.h"
using namespace std;

int main(void)
{
	int root = 3;//根节点
	//通过调用检查二叉树的代码是否无误
	Tree *pTree = new Tree(10, &root);
	int note1 = 5;//左节点
	int note2 = 8;//右节点
	pTree->AddNode(0, 0, &note1);//note1插入到3(0)的左边
	pTree->AddNode(0, 1, &note2);//note2插入到3(0)的右边

	int note3 = 2;
	int note4 = 6;
	pTree->AddNode(1, 0, &note3);//note3插入到5(1)的左边
	pTree->AddNode(1, 1, &note4);//note4插入到5(1)的右边

	int note5 = 9;
	int note6 = 7;
	pTree->AddNode(2, 0, &note5);//note5插入到8(2)的左边
	pTree->AddNode(2, 1, &note6);//note6插入到8(2)的右边

	pTree->TreeTraverse();

	int *p = pTree->SearchNode(2);//从栈上申请指针,是不需要释放操作的
	cout << endl << "Node= " << *p << endl;

	pTree->TreeTraverse();
	pTree->DeleteNode(6, p);
	cout << endl << "Node= " << *p << endl;
	pTree->TreeTraverse();


	delete pTree;
	pTree = NULL;

	system("pause");
	return 0;
}