#include "BinTree.h"
#include <iostream>
#include <queue>
using namespace std;

/****************************************************************/
/* BinTree()													*/
/* 功能:构造函数，创建一棵空二叉树								*/
/* 																*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTree::BinTree()
{
	m_pRoot = NULL;	//空树，根节点指针初始化为空
}

/****************************************************************/
/* ~BinTree()													*/
/* 功能:析构函数，递归释放所有结点内存							*/
/* 																*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTree::~BinTree()
{
	//调用私有辅助函数递归释放
	destroyTree(m_pRoot);
	m_pRoot = NULL;
}

/****************************************************************/
/* destroyTree(BinTreeNode *pNode)								*/
/* 功能:递归释放以 pNode 为根的所有结点（后序）					*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::destroyTree(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	//先递归释放左右子树，再删除根节点（后序）
	destroyTree(pNode->m_pLChild);
	destroyTree(pNode->m_pRChild);
	delete pNode;
	pNode = NULL;
}

/****************************************************************/
/* createHelper()												*/
/* 功能:从标准输入前序递归创建二叉树结点						*/
/*   输入 -1 表示该位置为空结点（NULL）						*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTreeNode* BinTree::createHelper()
{
	int val = 0;
	cin >> val;

	if (val == -1)
	{
		return NULL;	//-1 表示该结点为空
	}

	//创建新结点
	BinTreeNode *pNode = new BinTreeNode(val);

	//递归创建左子树和右子树
	pNode->m_pLChild = createHelper();
	pNode->m_pRChild = createHelper();

	return pNode;
}

/****************************************************************/
/* BinTreeNode* CreateByPreOrder()								*/
/* 功能:前序输入方式创建二叉树									*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTreeNode* BinTree::CreateByPreOrder()
{
	cout << "请按前序输入各结点的值（-1 表示空结点）：" << endl;
	m_pRoot = createHelper();
	return m_pRoot;
}

/****** 遍历实现 ******/

/****************************************************************/
/* preOrderHelper(BinTreeNode *pNode)							*/
/* 功能:递归前序遍历（根-左-右）								*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::preOrderHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	cout << pNode->m_iData << " ";	//访问根节点
	preOrderHelper(pNode->m_pLChild);	//递归遍历左子树
	preOrderHelper(pNode->m_pRChild);	//递归遍历右子树
}

/****************************************************************/
/* void PreOrder()												*/
/* 功能:前序遍历入口												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::PreOrder()
{
	cout << "前序遍历：";
	preOrderHelper(m_pRoot);
	cout << endl;
}

/****************************************************************/
/* inOrderHelper(BinTreeNode *pNode)							*/
/* 功能:递归中序遍历（左-根-右）								*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::inOrderHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	inOrderHelper(pNode->m_pLChild);	//递归遍历左子树
	cout << pNode->m_iData << " ";	//访问根节点
	inOrderHelper(pNode->m_pRChild);	//递归遍历右子树
}

/****************************************************************/
/* void InOrder()												*/
/* 功能:中序遍历入口												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::InOrder()
{
	cout << "中序遍历：";
	inOrderHelper(m_pRoot);
	cout << endl;
}

/****************************************************************/
/* postOrderHelper(BinTreeNode *pNode)							*/
/* 功能:递归后序遍历（左-右-根）								*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::postOrderHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	postOrderHelper(pNode->m_pLChild);	//递归遍历左子树
	postOrderHelper(pNode->m_pRChild);	//递归遍历右子树
	cout << pNode->m_iData << " ";	//访问根节点
}

/****************************************************************/
/* void PostOrder()												*/
/* 功能:后序遍历入口											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::PostOrder()
{
	cout << "后序遍历：";
	postOrderHelper(m_pRoot);
	cout << endl;
}

/****************************************************************/
/* void LevelOrder()											*/
/* 功能:层次遍历（广度优先），借助 STL queue 实现				*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::LevelOrder()
{
	if (m_pRoot == NULL)
	{
		cout << "层次遍历：（空树）" << endl;
		return;
	}

	cout << "层次遍历：";
	queue<BinTreeNode*> q;	//借助队列进行层次遍历
	q.push(m_pRoot);

	while (!q.empty())
	{
		BinTreeNode *pNode = q.front();
		q.pop();
		cout << pNode->m_iData << " ";	//输出当前结点

		//将左右孩子依次入队（不为空时）
		if (pNode->m_pLChild != NULL)
		{
			q.push(pNode->m_pLChild);
		}
		if (pNode->m_pRChild != NULL)
		{
			q.push(pNode->m_pRChild);
		}
	}
	cout << endl;
}

/****** 统计实现 ******/

/****************************************************************/
/* nodeCountHelper(BinTreeNode *pNode)							*/
/* 功能:递归统计以 pNode 为根的子树的结点总数					*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int BinTree::nodeCountHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return 0;
	}
	//总数 = 左子树结点数 + 右子树结点数 + 1（当前结点）
	return nodeCountHelper(pNode->m_pLChild)
		+ nodeCountHelper(pNode->m_pRChild)
		+ 1;
}

/****************************************************************/
/* int NodeCount()												*/
/* 功能:统计二叉树结点总数										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int BinTree::NodeCount()
{
	return nodeCountHelper(m_pRoot);
}

/****************************************************************/
/* leafCountHelper(BinTreeNode *pNode)							*/
/* 功能:递归统计叶子结点数										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int BinTree::leafCountHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return 0;
	}
	//叶子结点：左右孩子均为空
	if (pNode->m_pLChild == NULL && pNode->m_pRChild == NULL)
	{
		return 1;
	}
	//否则继续递归统计左右子树的叶子数
	return leafCountHelper(pNode->m_pLChild)
		+ leafCountHelper(pNode->m_pRChild);
}

/****************************************************************/
/* int LeafCount()												*/
/* 功能:统计叶子结点数											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int BinTree::LeafCount()
{
	return leafCountHelper(m_pRoot);
}

/****************************************************************/
/* heightHelper(BinTreeNode *pNode)								*/
/* 功能:递归计算以 pNode 为根的子树高度							*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int BinTree::heightHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return 0;	//空树高度为0
	}

	int leftHeight = heightHelper(pNode->m_pLChild);	//左子树高度
	int rightHeight = heightHelper(pNode->m_pRChild);	//右子树高度

	//当前树高 = max(左子树高, 右子树高) + 1（当前结点）
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/****************************************************************/
/* int Height()													*/
/* 功能:计算二叉树高度											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int BinTree::Height()
{
	return heightHelper(m_pRoot);
}

/****** 查找实现 ******/

/****************************************************************/
/* searchHelper(BinTreeNode *pNode, int val)					*/
/* 功能:前序递归查找第一个值等于 val 的结点						*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTreeNode* BinTree::searchHelper(BinTreeNode *pNode, int val)
{
	if (pNode == NULL)
	{
		return NULL;
	}

	//先判断当前结点
	if (pNode->m_iData == val)
	{
		return pNode;
	}

	//在左子树中查找
	BinTreeNode *result = searchHelper(pNode->m_pLChild, val);
	if (result != NULL)
	{
		return result;
	}

	//在右子树中查找
	return searchHelper(pNode->m_pRChild, val);
}

/****************************************************************/
/* BinTreeNode* Search(int val)									*/
/* 功能:查找第一个值等于 val 的结点								*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
BinTreeNode* BinTree::Search(int val)
{
	return searchHelper(m_pRoot, val);
}

/****** 其他操作 ******/

/****************************************************************/
/* mirrorHelper(BinTreeNode *pNode)								*/
/* 功能:递归将以 pNode 为根的子树镜像翻转						*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::mirrorHelper(BinTreeNode *pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	//交换当前结点的左右子树指针
	BinTreeNode *temp = pNode->m_pLChild;
	pNode->m_pLChild = pNode->m_pRChild;
	pNode->m_pRChild = temp;

	//递归翻转左右子树
	mirrorHelper(pNode->m_pLChild);
	mirrorHelper(pNode->m_pRChild);
}

/****************************************************************/
/* void Mirror()												*/
/* 功能:将整棵二叉树镜像翻转									*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void BinTree::Mirror()
{
	mirrorHelper(m_pRoot);
}

/****************************************************************/
/* bool IsEmpty()												*/
/* 功能:判断二叉树是否为空										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
bool BinTree::IsEmpty()
{
	return m_pRoot == NULL;
}
