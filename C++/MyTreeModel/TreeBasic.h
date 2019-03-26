#ifndef TREEBASIC_H
#define TREEBASIC_H

/****************************************************************************/
/*  类名称:Tree(针对简单数据类型int)
/*
/*	Tree(int size);											//创建树
/*	~Tree();												//销毁树
/*	int *SearchNode(int nodeIndex);						//根据索引寻找结点
/*	bool AddNode(int nodeIndex, int direction, int *pNode);	//添加结点
/*	bool DeleteNode(int nodeIndex, int *pNode);				//删除结点
/*	void TreeTraverse();									//遍历结点
/* (C语言内容)
/*	   BOOL CreateTree(Tree **pTree,Node *pRoot);		//创建树
/*	   void DestroyTree(Tree *pTree);					//销毁树
/*	   Node *SearchNode(Tree *pTree,int nodeIndex);		//根据索引寻找节点
/*			//添加节点
/*	   BOOL AddNode(Tree *pTree,int nodeIndex,int direction,Node *pNode);
/*	   BOOL DeleteNode(Tree *pTree,int nodeIndex,Node *pNode);//删除节点
/*	   void TreeTraverse(Tree *pTree);					//遍历
/*  创建时间:2019-3-13
/*	Author:Cyber Kaka
/****************************************************************************/

class Tree
{
public:
	Tree(int size, int *pRoot);/*树的大小,根节点*/			//创建树
	~Tree();												//销毁树
	int *SearchNode(int nodeIndex);							//根据索引寻找结点
	bool AddNode(int nodeIndex, int direction, int *pNode);	//添加结点
	bool DeleteNode(int nodeIndex, int *pNode);				//删除结点
	void TreeTraverse();									//遍历结点
protected:
private:
	int *m_pTree;		//用于指向相应数组的指针
	int m_iSize;		//记录大小
};

#endif // TREEBASIC_H
