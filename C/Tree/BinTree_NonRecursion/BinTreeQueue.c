#include <stdio.h>
#include <stdlib.h>
#include "BinTreeQueue.h"
#include "LinkQueue.h"

//使用队列辅助数据结构,利用非递归的方法建立二叉树
//ABC@DE@@@@F#

/****************************************************************/
/* BinTree CreateBinTree_NonRecursion()							*/
/* 功能:非递归建立二叉树										*/
/* 输入参数:无													*/
/* 返回值:二叉树的根											*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
BinTree CreateBinTree_NonRecursion()
{
	LinkQueue queue = SetNullQueue_Link();
	BinTreeNode *s, *p, *bt;
	char ch = '0';
	int count = -1;
	printf("按照层次输入二叉树的结点,以#结束:\n");
	ch = getchar();
	bt = NULL;//置空二叉树
	//假设结点的data是单个字符,#为结束字符
	while (ch != '#')
	{
		//s用于保存新结点
		s = NULL;
		//如果不是@就表示有内容,申请空间
		if (ch != '@')
		{
			s = (BinTreeNode *)malloc(sizeof(BinTreeNode));//申请新结点
			//新结点赋值
			s->data = ch;
			s->leftchild = NULL;
			s->rightchild = NULL;
		}
		EnQueue_Link(queue, s);//将新结点地址或虚结点地址入队
		count++;//计数器+1
		//若count为0,则现在是根节点,用bt指向它
		if (count == 0)
		{
			bt = s;
		}
		//根节点之后,计数器不再为0,开始建立二叉树
		else
		{
			//队头结点表示的是父结点,取出进行判断
			p = FrontQueue_Link(queue);
			//如果新结点和队头结点都不为空,则开始插入
			//如果新结点是空,即ch是@,那就不用赋值
			if (s != NULL && p != NULL)
			{
				//当前结点和双亲结点都不是虚节点时,判断奇偶性
				//插入左右孩子
				if (count % 2 == 1)
				{
					//count为奇数,新结点作为左孩子插入
					p->leftchild = s;
				} 
				else
				{
					//否则count为偶数,新结点作为右孩子插入
					p->rightchild = s;
				}
			}
			//每次左右孩子插入完毕之后,不论是否能插入,count都应为一个偶数
			if (count % 2 == 0)
			{
				//再次判断,如果count为偶数,说明两个孩子处理完毕,front指向下一个双亲
				DeQueue_Link(queue);//队头处理完毕的结点出队
			}
		}
		ch = getchar();//读取下一个结点的值
	}
	return bt;//当ch是#时,即输入完毕,返回二叉树的根
}

/****************************************************************/
/* void LevelOrder(BinTree bt)									*/
/* 功能:使用队列层次遍历二叉树									*/
/* 输入参数:二叉树的根											*/
/* 返回值:无													*/
/* 创建日期:2019-5-13						Author:Cyber Kaka	*/
/****************************************************************/
void LevelOrder(BinTree bt)
{
	//由于层次遍历中也使用到了队列,所以写在这里
	BinTree p;//建立临时结点,保证bt和p的类型相同
	LinkQueue queue = SetNullQueue_Link();//建立空队列
	//如果传入的二叉树为空,直接结束
	if (bt==NULL)
	{
		return;
	}
	//传入的二叉树有效,开始遍历
	p = bt;
	//头结点入队
	EnQueue_Link(queue, bt);
	//判断队列是否为空,不为空则进行循环
	while (!IsNullQueue_Link(queue))
	{
		//从队头取出结点赋值给p
		p = FrontQueue_Link(queue);
		//队头结点出队
		DeQueue_Link(queue);
		//打印出队的结点的字符
		printf("%c ", p->data);
		//判断左右子结点的内容是否为空
		if (p->leftchild!=NULL)
		{
			//左孩子结点不为空,入队
			EnQueue_Link(queue, p->leftchild);
		}
		if (p->rightchild!=NULL)
		{
			//右孩子结点不为空,入队
			EnQueue_Link(queue, p->rightchild);
		}
		//循环,主要看队列里是否还有结点
	}//队列为空,结束循环
	printf("\n");
}