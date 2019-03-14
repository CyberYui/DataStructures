#include <iostream>
#include "NodeAdv.h"
using namespace std;

Node::Node()
{
	index = 0;//初始索引为0
	data = 0;//初始数据域为0
	pLChild = NULL;//三个指针皆为空
	pRChild = NULL;
	pParent = NULL;
}


/****************************************************************/
/*				SearchNode(int nodeIndex)						*/
/* 功能:寻找传入索引nodeIndex相对应的结点,若存在,则返回,否则返回*/
/*		NULL,在树中有同名函数,对其进行调用						*/
/* 重点:在何时递归调用,在何时返回空值							*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
Node *Node::SearchNode(int nodeIndex)
{
	//SearchNode与Tree下面的函数同名
	//功能是基本一样的,只不过是在Node中实现,Tree中调用

	if (this->index == nodeIndex)
	{
		//如果和要找的索引相同,那就是自己
		return this;
	}
	//定义临时变量接受
	Node *temp = NULL;
	//自己不是了,就看左右,看之前先判断一下是不是为空
	if (this->pLChild != NULL)
	{
		//如果不为空,则看索引是不是相同
		if (this->pLChild->index == nodeIndex)
		{
			//如果索引相同,则就是这个左节点
			return this->pLChild;
		}
		else
		{
			//如果没找到左节点,那就继续向下找
			//如果找到了,就接受他,并返回出去
			temp = this->pLChild->SearchNode(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	//自己和左边的都不是了,就右,看之前先判断一下是不是为空
	if (this->pRChild != NULL)
	{
		//如果不为空,则看索引是不是相同
		if (this->pRChild->index == nodeIndex)
		{
			//如果索引相同,则就是这个右节点
			return this->pRChild;
		}
		else
		{
			//如果没找到右节点,那就继续向下找
			//如果找到了,就接受他,并返回出去
			temp = this->pRChild->SearchNode(nodeIndex);
			//由于这是最后一步,所以也不用判断了,直接返回即可
			//if (temp != NULL)
			//{
			//	return temp;
			//}
			return temp;
		}
	}
	//如果都不是了,就只能证明要找的结点不在树中
	return NULL;
}

/****************************************************************/
/* void DeleteNode()											*/
/* 功能:通过递归调用删除结点									*/
/* 重点:SearchNode函数											*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::DeleteNode()
{
	//在删除的时候,想好结点具体应该如何删除
	//首先,如果它有子结点,那就先删除它的各个子结点
	//然后对于它的根节点,要看它在根节点的哪一个方位
	//如果是左侧,则将根节点的左孩子指针置为NULL,然后要删除的子节点自杀
	//如果是右侧,则将根节点的右孩子指针置为NULL,然后要删除的子节点自杀

	//先杀其左右孩子,使用递归
	if (this->pLChild != NULL)//判左
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL)//判右
	{
		this->pRChild->DeleteNode();
	}
	//接着判断自己的父节点指针
	if (this->pParent != NULL)
	{
		if (this->pParent->pLChild == this)
		{
			//如果自己父节点的左孩子是自己,则将左指针置为NULL
			this->pParent->pLChild = NULL;
		}
	}
	if (this->pParent != NULL)
	{
		if (this->pParent->pRChild == this)
		{
			//如果自己父节点的右孩子是自己,则将右指针置为NULL
			this->pParent->pRChild = NULL;
		}
	}
	//完成后删除自己的内容
	delete this;
}


/****************************************************************/
/*				PreorderTraversal()								*/
/* 功能:前序遍历												*/
/* 重点:递归操作												*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::PreorderTraversal()
{
	//对于一个结点来说,其前序遍历就是,先自己,然后左,之后右
	//先输出自己的内容  数据域(索引)
	cout << this->data << "(" << this->index << ")" << "->";
	//之后是自己的左侧孩子结点
	//先判断是否存在左节点,若存在则递归调用
	if (this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();//递归调用前序遍历
	}
	//再判断右节点,若存在则再递归调用,
	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
	//结束的标志是叶子节点的左右孩子指针都为NULL
}


/****************************************************************/
/*				InorderTraversal()								*/
/* 功能:中序遍历												*/
/* 重点:递归操作												*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::InorderTraversal()
{
	//中序遍历即先左,后自己,然后右
	//借用前序遍历的内容,更换位置即可

	//先判断是否存在左子树,若存在则递归调用
	if (this->pLChild != NULL)
	{
		this->pLChild->InorderTraversal();//递归调用中序遍历
	}

	//输出自己的内容  数据域(索引)
	cout << this->data << "(" << this->index << ")" << "->";

	//最后判断右子树,若存在则再递归调用,
	if (this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
	//结束的标志是叶子节点的左右孩子指针都为NULL
}



/****************************************************************/
/*			PostorderTraversal()								*/
/* 功能:后序遍历												*/
/* 重点:递归操作												*/
/* 创建日期:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::PostorderTraversal()
{
	//后序遍历即先左,后右,最后
	//借用前序遍历的内容,更换位置即可

	//先判断是否存在左子树,若存在则递归调用
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();//递归调用后序遍历
	}
	//再判断右子树,若存在则再递归调用,
	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	//输出自己的内容  数据域(索引)
	cout << this->data << "(" << this->index << ")" << "->";
	//结束的标志是叶子节点的左右孩子指针都为NULL
}