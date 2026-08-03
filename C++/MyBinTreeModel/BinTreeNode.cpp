#include "BinTreeNode.h"
#include <cstddef>		// for NULL

/****************************************************************/
/* BinTreeNode()												*/
/* 功能:默认构造函数，将数据域初始化为0，子指针初始化为NULL		*/
/* 																*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTreeNode::BinTreeNode()
{
	m_iData = 0;
	m_pLChild = NULL;
	m_pRChild = NULL;
}

/****************************************************************/
/* BinTreeNode(int val)											*/
/* 功能:带初值的构造函数，将数据域初始化为 val					*/
/* 																*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTreeNode::BinTreeNode(int val)
{
	m_iData = val;
	m_pLChild = NULL;
	m_pRChild = NULL;
}
