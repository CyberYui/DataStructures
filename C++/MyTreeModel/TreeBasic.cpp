#include <iostream>
#include "TreeBasic.h"
using namespace std;

/****************************************************************/
/* Tree(int size,int *pRoot)									*/
/* 功能:创建一个树,并对树进行初始化操作							*/
/* 																*/
/* 创建日期:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
Tree::Tree(int size, int *pRoot)			//创建树
{
	m_iSize = size;
	m_pTree = new int[size];//从堆中分配内存
	//给数组初始状态
	for (int i = 0; i < size; i++)
	{
		//按理说应该对分配内存的指针进行判空,这里略过
		m_pTree[i] = 0;
	}
	//插入根节点
	m_pTree[0] = *pRoot;//传入的指针值即为根节点的值
}


/****************************************************************/
/* ~Tree()														*/
/* 功能:销毁在构造函数中创建的树								*/
/* 																*/
/* 创建日期:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
Tree::~Tree()					//销毁树
{
	delete[]m_pTree;
	m_pTree = NULL;
}


/****************************************************************/
/* int *SearchNode(int nodeIndex)								*/
/* 功能:根据给定的索引寻找相应结点								*/
/* 																*/
/* 创建日期:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
int *Tree::SearchNode(int nodeIndex)	//根据索引寻找结点
{
	//判断传入索引的合法性
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return NULL;
	}
	//在树中,如果值为0,代表这里不是一个叶子节点/子节点
	if (m_pTree[nodeIndex] == 0)
	{
		return NULL;
	}
	return &m_pTree[nodeIndex];
}


/****************************************************************/
/* bool AddNode(int nodeIndex, int direction, int *pNode)		*/
/* 功能:添加结点												*/
/*																*/
/* 创建日期:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
bool Tree::AddNode(int nodeIndex, int direction, int *pNode)
{
	//判断传入索引的合法性
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	//在树中,如果值为0,代表这里不是一个叶子节点/子节点
	if (&m_pTree[nodeIndex] == 0)
	{
		return false;
	}
	//结点有意义,看要放左孩子还是右孩子
	if (direction == 0)		//等于0即往左插入
	{
		//判断传入索引的合法性
		//如果nodeIndex!<0,那么就不可能还有(nodeIndex*2+1)<0的情况
		if ((nodeIndex * 2 + 1) >= m_iSize)
		{
			return false;
		}
		//在树中查看原本这里是否有值,有值则不传,否则放入传入的值
		if (m_pTree[nodeIndex * 2 + 1] != 0)
		{
			return false;
		}
		m_pTree[nodeIndex * 2 + 1] = *pNode;
	}

	if (direction == 1)		//等于1即往右插入,+1是左,则+2是右
	{
		//判断传入索引的合法性
		//如果nodeIndex!<0,那么就不可能还有(nodeIndex*2+2)<0的情况
		if ((nodeIndex * 2 + 2) >= m_iSize)
		{
			return false;
		}
		//在树中查看原本这里是否有值,有值则不传,否则放入传入的值
		if (m_pTree[nodeIndex * 2 + 2] != 0)
		{
			return false;
		}
		m_pTree[nodeIndex * 2 + 2] = *pNode;
	}
	//所有情况都不满足了,也就是插入了,返回真即可
	return true;
}


/****************************************************************/
/* bool DeleteNode(int nodeIndex, int *pNode)					*/
/* 功能:删除结点												*/
/* 																*/
/* 创建日期:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
bool Tree::DeleteNode(int nodeIndex, int *pNode)
{
	//还是先判断索引的合法性
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	//判断该处的值是否为0,为0表示树节点这里没有值
	if (m_pTree[nodeIndex] == 0)
	{
		return false;
	}
	//将要删除的值传给pNode,并删除此树节点,即赋0
	*pNode = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = 0;
	return true;
}


/****************************************************************/
/* void TreeTraverse()											*/
/* 功能:遍历树结点												*/
/*																*/
/* 创建日期:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
void Tree::TreeTraverse()		//遍历结点
{
	//遍历就是遍历数组,只需要用一个循环即可
	for (int i = 0; i < m_iSize; i++)
	{
		cout << m_pTree[i] << ",";
	}
}