#include <stdio.h>
#include "TreeAdv.h"
using namespace std;

/****************************************************************/
/* Tree()														*/
/* 功能:初始化一个树,仅仅有一个根节点							*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
Tree::Tree()
{
	//第一个结点的index就定义为0
	//在树的第一个结点一般不放值,数据域为0表示没有数据
	//并且它初试时并未挂载左右结点,且没有父节点,故三个指针都为NULL
	m_pRoot = new Node();//初始头结点
}


/****************************************************************/
/* ~Tree()														*/
/* 功能:销毁一个树,并删除指针,释放内存							*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
Tree::~Tree()
{
	//对于析构函数,其主要任务其实就是删除根节点
	//所以~Tree()与DeleteNode()是有联系的
	//而要删除结点,就需要先搜索到结点,即SearchNode()与其也有联系
	//添加结点,也是需要搜索到节点

	//析构函数说白了就是删除根节点
	//m_pRoot->DeleteNode();//虽然有同样效果
	//但是如果当前树中有其他数据成员指针,仅仅调用就不够了

	DeleteNode(0, NULL);//不用保存根节点内容

	//delete m_pRoot;
	//m_pRoot = NULL;
}


/****************************************************************/
/* Node *Tree::SearchNode(int nodeIndex)						*/
/* 功能:调用Node类中同名函数,对传入的索引在树中进行寻找结点操作	*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
Node *Tree::SearchNode(int nodeIndex)
{
	//对于析构函数,其主要任务其实就是删除根节点
	//所以~Tree()与DeleteNode()是有联系的
	//而要删除结点,就需要先搜索到结点,即SearchNode()与其也有联系
	//添加结点,也是需要搜索到节点,所以关键是寻找结点,先写

	//对于树来说,找一个结点的时候需要去考虑它左右两个孩子
	//由于无法确定,其子孙结点想必可能很多
	//对于这种情况,我们将此任务推给下一层的类Node来完成
	//对于Node,寻找结点就容易多了
	//Node本身先进行判断,之后对其左右进行判断,是则返回

	//借助Node的寻找函数,寻找nodeIndex对应的结点是否存在
	//无论是否存在,都可以作为树的SearchNode返回值直接返回
	return m_pRoot->SearchNode(nodeIndex);
}


/****************************************************************/
/* bool AddNode(int nodeIndex, int direction, Node *pNode)		*/
/* 功能:在指定索引为nodeIndex的地方作为根节点,以direction判断放	*/
/*		置于根节点哪边的位置,将pNode的数据挂载在树中			*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
	//在添加前,先判断这个索引的地方是否有存在且可操作的结点作为根
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	//不为空则将pNode的内容按direction进行挂载
	//但是不能直接用pNode,因为它是一个外部传入的内容
	//直接挂载会导致pNode在被修改之后导致整个树出错

	//所以先存一下pNode传入的内容
	Node *node = new Node();
	//判断申请的内容是否为空
	if (node == NULL)
	{
		return false;//申请失败
	}
	//申请成功,传入数据
	node->index = pNode->index;
	node->data = pNode->data;
	//将node的parent指向父节点
	node->pParent = temp;

	//判断direction的值
	if (direction == 0)//挂载左边
	{
		temp->pLChild = node;
	}
	if (direction == 1)//挂载右边
	{
		temp->pRChild = node;
	}
	//添加成功之后,给函数返回一下
	return true;
}


/****************************************************************/
/* bool DeleteNode(int nodeIndex, Node *pNode)					*/
/* 功能:删除索引为nodeIndex的结点,并将要删除的结点内容先保存在	*/
/*		pNode中,便于输出,借用了Node类中的同名函数				*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
	//要想删除结点,也是要先寻找到索引的节点
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	//如果找到节点了,就要放到pNode中
	//顺序是先取,后删
	if (pNode != NULL)
	{
		//如果pNode是空的,那就直接删除就好了
		//如果非空,就取一下值和索引好了
		pNode->index = temp->index;
		pNode->data = temp->data;//重要的是数据域,index并不重要
	}
	//无论pNode是否等于NULL,都要删节点
	//在树上做这个删除操作有些困难,所以需要在结点中进行此操作
	//相应的,Node类中也有这样的同名函数

	//存好值之后开始删除
	temp->DeleteNode();//递归调用,执行删除temp结点的各项操作
	return true;
}


/****************************************************************/
/*				PreorderTraversal()								*/
/* 功能:前序遍历,借助m_pRoot指针去调用Node的相关函数			*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Tree::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}


/****************************************************************/
/*				InorderTraversal()								*/
/* 功能:中序遍历,借助m_pRoot指针去调用Node的相关函数			*/
/*																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Tree::InorderTraversal()
{
	m_pRoot->InorderTraversal();
}


/****************************************************************/
/*			PostorderTraversal()								*/
/* 功能:后序遍历,借助m_pRoot指针去调用Node的相关函数			*/
/* 																*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Tree::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}