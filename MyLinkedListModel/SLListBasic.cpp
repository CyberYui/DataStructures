#include <iostream>
#include "SLListBasic.h"
using namespace std;

/************************************************************************/
/* 构造函数List()														*/
/*     对于链表来说,它不像顺序表一样需要规定大小,而是临时申请地址,并将地*/
/* 址挂载到当前的链表中													*/
/*																		*/
/* 功能:创建一个初始化的链表,里面有一个指针域为NULL,数值域为0的头结点	*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
List::List()
{
	//创建结点
	m_pList = new Node;
	m_pList->data = 0;//数值域为0
	m_pList->next = NULL;//指针域为NULL
	//这样就定义出了一个头结点,在链表中,头结点是没有意义的
	m_iLength = 0;//长度为0
}


/************************************************************************/
/* 析构函数~List()														*/
/*     对于链表来说,它的析构函数就是将申请的所有结点全部释放,包括第一个 */
/* 结点,与清空函数ClearList()对比,就是析构函数释放了第一个结点			*/
/*																		*/
/* 功能:释放一个链表的所有申请内容,删除指针,释放内存空间				*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
List::~List()
{
	//利用ClearList,先清理掉非首的结点
	ClearList();
	//清理掉首结点
	delete m_pList;
	m_pList = NULL;
}


/************************************************************************/
/* 清空函数ClearList()													*/
/*     对于链表来说,它的清空函数就是将申请的结点全部释放,但是不包括第一 */
/* 个结点,与析构函数~List()对比,就是析构函数释放了第一个结点,清空函数没	*/
/* 有																	*/
/*																		*/
/* 功能:清空一个链表的非首申请内容										*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
void List::ClearList()
{
	//类似于抓特务,首先找到一个特务,然后对其进行拷问,找出其下线
	//之后再抓其下线,然后顺藤摸瓜,直到捣毁整个窝点
	Node *tempNode = m_pList->next;//先找一个人进行审问
	//首先找到首结点,进行判断
	while (tempNode != NULL)
	{
		//非空则找其下线,获取信息,之后清理它,因为它已经没有利用价值了
		Node *temp = tempNode->next;//保存指针域所指的下一个结点
		delete tempNode;//删除原结点
		tempNode = temp;//保留新结点,回到迭代头继续审问
	}
	//所有皆清理完成,即tempNode=NULL
	//收尾,这样下次收集内容的时候就又有新内容了
	m_pList->next = NULL;
}


/************************************************************************/
/* 判空函数ListEmpty()													*/
/*     对于链表来说,它的判空函数就是对整个链表进行判断,如果为空,则返回一*/
/* 个true值,如果非空,则返回false										*/
/*																		*/
/* 功能:判断一个链表是否为空											*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************/
/* 测长函数ListLength()													*/
/*     同顺序表,对链表来说,它的测长函数就是对整个链表的长度进行返回即可	*/
/*																		*/
/* 功能:返回一个链表的长度												*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
int List::ListLength()
{
	return m_iLength;
}


/************************************************************************/
/* 从头插入结点函数ListInsertHead(Node *pNode)							*/
/*																		*/
/* 功能:将一个结点pNode插入到头结点的后面								*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListInsertHead(Node *pNode)
{
	//首先要找到头结点指针域指向的结点,即m_pList->next
	//它是原先的第二个结点,当结束后会变成新的第三个结点
	Node *secondNode = m_pList->next;
	//再需要把要插入的结点的内容保存下来,即pNode->data
	Node *newNode = new Node;
	//在申请新的结点的时候,可能会遇到申请内存失败的情况,此时返回false
	if (newNode == NULL)//这里是判断,一定要看是不是两个==,否则会编译无错误,但是输出有错误
	{
		return false;
	}
	newNode->data = pNode->data;//保存数值域内容
	//再让头结点指向这个新的结点,即newNode
	m_pList->next = newNode;
	//再让新结点的指针域,指向原头结点指针域指向的结点被保存在temp中
	newNode->next = secondNode;
	//插入成功了,返回true,此时链表长度+1
	m_iLength++;
	return true;
}


/************************************************************************/
/* 从尾插入结点函数ListInsertTail(Node *pNode)							*/
/*																		*/
/* 功能:将一个结点pNode插入到尾结点的后面								*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListInsertTail(Node *pNode)
{
	//首先要找到链表头结点,从而才能按序找到尾结点
	//不可能修改头结点,所以建立一个临时结点,这个结点会作为旧的尾结点
	Node *currentTailNode = m_pList;
	//判断临时结点是否指向NULL,如果不是,就一直往后找
	while (currentTailNode->next != NULL)
	{
		currentTailNode = currentTailNode->next;
	}
	//此时tempNode=NULL
	//挂载最后一个结点,即尾结点
	Node *newNode = new Node;
	//在申请新的结点的时候,可能会遇到申请内存失败的情况,此时返回false
	if (newNode == NULL)
	{
		return false;
	}
	//把传入的结点数据域和指针域都设定好
	newNode->data = pNode->data;
	newNode->next = NULL;
	//现在新的结点就是尾结点了
	currentTailNode->next = newNode;
	//插入成功了,返回true,此时链表长度+1
	m_iLength++;
	return true;
}


/************************************************************************/
/* 插入结点函数ListInsert(int i, Node *pNode)							*/
/*																		*/
/* 功能:将一个结点pNode插入到链表的任意i结点之后						*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListInsert(int i, Node *pNode)
{
	//对于i的值,如果非法,则不允许插入,直接返回false
	if (i < 0 || i > m_iLength)
	{
		return false;
	}
	//虽然说加上下面的判断会更利于逻辑解释,但是实际的操作并没有区别
	//if (i==0)
	//{
	//	ListInsertHead(pNode);
	//	return true;
	//}
	//if (i==m_iLength)
	//{
	//	ListInsertTail(pNode);
	//	return true;
	//}
	else
	{
		//首先还是找头结点并保存一下它
		Node *iNode = m_pList;
		//通过for循环找到第i个结点
		for (int k = 0; k < i; k++)
		{
			iNode = iNode->next;
		}
		//申请新结点
		Node *newNode = new Node;
		//在申请新的结点的时候,可能会遇到申请内存失败的情况,此时返回false
		if (newNode == NULL)
		{
			return false;
		}
		//把传入的结点数据域赋给新结点
		newNode->data = pNode->data;
		//i结点的下一个结点现在是newNode的下一个结点
		newNode->next = iNode->next;
		//此时把新结点插入到i结点之后
		iNode->next = newNode;
		m_iLength++;
		return true;
	}
}


/************************************************************************/
/* 删除结点函数ListDelete(int i, Node *pNode)							*/
/*																		*/
/* 功能:将一个i结点删除,并将其数据传给pNode								*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListDelete(int i, Node *pNode)
{
	//要删除一个结点,首先要求它有前一个结点
	//这样在删除的时候先找其前驱结点,然后找其后继结点
	//让前驱结点链接后继结点,释放当前结点,就完成了对结点的删除

	//首先判断i的值是否合法,不合法则直接返回false
	//除了头结点之前和尾结点之后不存在的结点没法删,其余的结点都可以删除
	if (i < 0 || i >= m_iLength)
	{
		//由于使用的是for循环,所以i不能等于m_iLength,
		//否则是在删除尾结点之后不存在的结点
		return false;
	}
	//还是先找头结点
	Node *currentNode = m_pList;
	//将以前的结点临时保存在currentNodeBefore中
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		//保存原先的结点
		currentNodeBefore = currentNode;
		//后移结点,此时currentNodeBefore保存的结点已经是现在结点的前驱结点了
		currentNode = currentNode->next;
		//现在currentNode保存的结点是现在结点的后继结点
	}
	//将结点前驱结点指针域指向后继结点,完成对结点的分离
	currentNodeBefore->next = currentNode->next;
	//将结点的数据域保存给pNode
	pNode->data = currentNode->data;
	//删除结点,释放内存
	delete currentNode;
	currentNode = NULL;
	//链表长度-1
	m_iLength--;
	return true;
	/************************************************************/
	/* 对于 ListDelete(int i, Node *pNode) 的解释               */
	/*   currentNode(CN)   currentNodeBefore(CNB)   pNode(PN)   */
	/* 比如有这么一个链表:						                */
	/*     1|A      //如果想要删除结点2|B,则调用函数	        */
	/*     2|B      //此时为开始,CN->1|A,即头结点               */
	/*     3|C                   CNB->NULL PN=NULL  开始循环:   */
	/*     4|D      <1>k=0 k<=2? √  CNB->1|A  CN->2|B  k++ = 1 */
	/*     5|E		<2>k=1 k<=2? √  CNB->2|B  CN->3|C  k++ = 2 */
	/*              <3>k=2 k<=2? √  CNB->3|C  CN->4|D  k++ = 3 */
	/*              <4>k=3 k<=2? ×								*/
	/*              循环结束:     此时      CNB->3|C  CN->4|D   */
	/*			执行currentNodeBefore->next = currentNode->next	*/
	/*				即CNB -> 3|C        而 CNB.next -> 5|E		*/
	/*				  PN.data = CN.data = 4						*/
	/*				即完成了 3|C 指向 5|E pNode中保存4这个数据	*/
	/*		而4|D已经被删除出链表了	delete currentNode			*/
	/************************************************************/
}



/************************************************************************/
/* 获取指定结点函数GetElem(int i, Node *pNode)							*/
/*																		*/
/* 功能:获取指定位置i的结点,并将其数据提取给pNode						*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::GetElem(int i, Node *pNode)
{
	//在ListDelete中也是要找i的结点,可以借用思想
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}
	//还是先找头结点
	Node *currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}


/************************************************************************/
/* 定位结点函数LocateElem(Node *pNode)									*/
/*																		*/
/* 功能:获取指定结点pNode,在链表中查找是否有和其数据域相同的结点,如果有 */
/*      则返回这个结点在链表中的位置i,否则返回0,即找不到				*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
int List::LocateElem(Node *pNode)
{
	//要拿整个链表去和pNode对比
	//还是要先找头结点
	Node *currentNode = m_pList;//头结点的数据域是没有意义的,因为是0
	//判断临时结点是否指向NULL,如果不是,就一直往后找
	int count = 1;//计数器,不计数头结点,所以从1开始算
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		//对比数据域
		if (currentNode->data == pNode->data)
		{
			//如果找到数据域相同的结点,就返回第一个匹配的结点编号
			return count;
			//链表中有可能有很多与pNode数据域相同的结点,这里只返回第一个匹配的
		}
		//没有找到就计数器+1,继续遍历
		count++;
	}
	//遍历全部链表之后还没有找到,就返回-1
	return -1;
}


/************************************************************************/
/* 前驱寻找函数PriorElem(Node *pCurrentNode, Node *pPreNode)			*/
/*																		*/
/* 功能:获取指定结点pCurrentNode,在链表中查找是否有和其数据域相同的结点,*/
/*      如果有则返回这个结点在链表中的前驱结点pPreNode的数据域			*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	//可以借鉴LocateElem函数的内容,但还是要先找头结点
	Node *currentNode = m_pList;//头结点的数据域是没有意义的,因为是0
	Node *tempNode = NULL;//定义临时节点,保存当前结点的上一个结点
	//判断结点是否指向NULL,如果不是,就一直往后找
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		//保存结点内容,当前结点后移一位,从而tempNode保存的是前驱结点
		currentNode = currentNode->next;
		//对比数据域
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
			{
				//判断tempNode是不是头结点本身,如果是,
				//则currentNode是第一个结点
				//它的前驱结点是头结点,是没有意义的
				return false;
			}
			//正确找到之后就返回当前结点的前驱结点内容
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	//遍历全部链表之后还没有找到,就返回false
	return false;
}


/************************************************************************/
/* 后继寻找函数NextElem(Node *pCurrentNode, Node *pNextNode)			*/
/*																		*/
/* 功能:获取指定结点pCurrentNode,在链表中查找是否有和其数据域相同的结点,*/
/*      如果有则返回这个结点在链表中的后继结点的数据域赋给pNextNode		*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	//还是要先找头结点
	Node *currentNode = m_pList;//头结点的数据域是没有意义的,因为是0
	//对于找后继结点,不需要再像对前驱进行保存那样保存后继了
	//因为next就指向下一个结点
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		//对比数据域
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == NULL)
			{
				//判断currentNode是不是尾结点本身,如果是,
				//则currentNode是最后一个结点,没有后继结点
				return false;
			}
			//正确找到之后就返回当前结点的后继结点的数据域
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	//遍历全部链表之后还没有找到,就返回false
	return false;
}


/************************************************************************/
/* 遍历函数ListTraverse()												*/
/*																		*/
/* 功能:遍历整个链表,完成对链表内容的输出								*/
/*																		*/
/* 创建日期:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
void List::ListTraverse()
{
	//还是要先找头结点
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		//由于头结点是无意义的,所以直接从第二个结点找起
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}