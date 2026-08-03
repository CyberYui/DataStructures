// 二叉树演示程序
// 展示二叉树的创建、遍历、统计、查找与镜像翻转等基本操作
//
// 编译命令 (Linux/g++):
//   g++ BinTreeNode.cpp BinTree.cpp BinTreeDemo.cpp -o bintree_demo
//   ./bintree_demo
//
// 示例输入（前序，-1 表示空）:
//   1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
// 对应二叉树结构:
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6

#include <iostream>
#include "BinTree.h"
using namespace std;

int main(void)
{
	BinTree tree;						//创建一棵空二叉树
	BinTreeNode *pResult = NULL;		//用于保存查找结果

	cout << "===== 二叉树演示 =====" << endl;

	// ---- 创建二叉树 ----
	// 输入前序序列（-1 表示空结点）
	// 示例输入: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
	tree.CreateByPreOrder();
	cout << endl;

	// ---- 检查是否为空 ----
	if (tree.IsEmpty())
	{
		cout << "当前二叉树为空！" << endl;
		return 0;
	}

	// ---- 四种遍历 ----
	tree.PreOrder();
	tree.InOrder();
	tree.PostOrder();
	tree.LevelOrder();
	cout << endl;

	// ---- 统计信息 ----
	cout << "结点总数: " << tree.NodeCount() << endl;
	cout << "叶子结点数: " << tree.LeafCount() << endl;
	cout << "树的高度: " << tree.Height() << endl;
	cout << endl;

	// ---- 查找结点 ----
	int searchVal = 5;
	pResult = tree.Search(searchVal);
	if (pResult != NULL)
	{
		cout << "查找值 " << searchVal << " 成功，找到结点数据: " << pResult->m_iData << endl;
	}
	else
	{
		cout << "查找值 " << searchVal << " 失败，树中不存在该值" << endl;
	}
	cout << endl;

	// ---- 镜像翻转 ----
	cout << "镜像翻转后：" << endl;
	tree.Mirror();
	tree.PreOrder();
	tree.InOrder();
	tree.LevelOrder();

	return 0;
}
