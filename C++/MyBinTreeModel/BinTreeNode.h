// 二叉树结点类定义头文件
//
// BinTreeNode 类:
//   构造/析构:
//     BinTreeNode(int val);     // 带初值的构造函数
//     BinTreeNode();            // 默认构造函数
//   数据成员:
//     int m_iData;              // 数据域
//     BinTreeNode *m_pLChild;   // 左孩子指针
//     BinTreeNode *m_pRChild;   // 右孩子指针
//
// 创建日期: 2024-1-1
// Author: Cyber Kaka
//****************************************************************************

#ifndef BINTREENODE_H
#define BINTREENODE_H

class BinTreeNode
{
public:
	BinTreeNode();					//默认构造函数，初始化数据域为0
	BinTreeNode(int val);			//带初值的构造函数

public:
	int m_iData;					//数据域（存储结点的值）
	BinTreeNode *m_pLChild;			//左孩子指针
	BinTreeNode *m_pRChild;			//右孩子指针
};

#endif // BINTREENODE_H
