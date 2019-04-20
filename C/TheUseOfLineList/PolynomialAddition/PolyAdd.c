#include <stdio.h>
#include <stdlib.h>
#include "PolyAdd.h"

//将结点插入到链表的适当位置,这是一个升幂排列的链表
void InsertList(PNode head, PNode pnode)
{
	PNode pPre = head;
	while (pPre -> next != NULL)
	{
		if (pPre->next->exp > pnode->exp)
		{
			pnode->next = pPre->next;//pnode放到指数大的结点之前
			pPre->next = pnode;//现在的第一个非空结点即为pnode
			break;
		}
		//进行下一个结点的插入,直到链表终止插入
		pPre = pPre->next;
	}
	//待插入结点的指数最大,直接插入结点到最后
	if (pPre->next == NULL)
	{
		pPre->next = pnode;
	}
}

void CreateList(PNode head)
{
	int exp;//指数
	float coef;//系数
	PNode pTemp = NULL;
	head->next = NULL;//分配好空间,指针域赋值为空
	//读入多项式
	printf("请输入要放入链表1中的数据,顺序为系数,指数,若多项式结束,则以0,0结尾:\n");
	//读入数据,以0,0结尾,把数据插入链表中
	scanf_s("%f,%d", &coef, &exp);
	while (coef != 0 || exp != 0)
	{
		pTemp = (PNode)malloc(sizeof(struct tagNode));
		pTemp->coef = coef;
		pTemp->exp = exp;
		pTemp->next = NULL;
		InsertList(head, pTemp);
		scanf_s("%f,%d", &coef, &exp);
	}
}

void printLinkedList(PNode head)
{
	//链表的第一个结点开始
	PNode temp = head->next;
	while (temp != NULL)
	{
		//输出系数和指数
		printf("%0.0f ", temp->coef);
		printf("%d,", temp->exp);
		//继续下一个结点
		temp = temp->next;
	}
	//当到最后一个结点时,结束
	printf("\n");
}

//两个多项式相加
void Add_Poly(PNode pa, PNode pb)
{
	PNode p = pa->next;//链表1,和多项式即此链表的完成部分
	PNode q = pb->next;//链表2
	PNode pre = pa;//前驱结点
	PNode u;//临时变量
	float x;
	//当两个链表都不为空,则进行相加
	while (p != NULL && q != NULL)
	{
		if (p->exp < q->exp)
		{
			//比较链表1和链表2当前节点的指数大小,存放结果至链表1
			pre = p;
			p = p->next;//p指向要比较的下一个节点,pre指向的是结果链表的最后一个结点
		}
		else if (p->exp == q->exp)
		{
			//假如链表1和链表2的指数相等,则系数相加
			x = p->coef + q->coef;
			if (x != 0)
			{
				//相加后的系数不为0,有必要保留一个结点
				p->coef = x;//改变系数
				pre = p;//插入和多项式中
			}
			else
			{
				//相加后结果为0,不需要保留任何一个结点,这里删除链表1结点,之后删除链表2的结点
				pre->next = p->next;
				free(p);
			}
			p = pre->next;//p指向要比较的下一个结点
			//删除链表2的结点,因为指数相同的只需要保留一个即可
			//链表1中的完成部分保存结果,所以删除链表2的结点
			u = q;
			q = q->next;
			free(u);
		}
		else
		{
			//如果链表2的当前结点指数小,那么要把链表2的当前结点加入到结果链表中(即链表1)
			//不论相加结果x是0还是不是0,都要删除q结点
			//相当于把结点插入到链表1中,用u作为临时变量,保存链表2的下一个当前结点位置
			u = q->next;

			q->next = p;
			pre->next = q;//pre-q-p
			//此时把q插入到了pre和p之间
			pre = q;//pre后挪一个位置
			//插入完成后返回继续向后比较
			q = u;//q往后挪一个位置
		}
		//然后继续进行循环,直到有一个p/q指到头为止
	}
	if (q)
	{
		//如果链表2比链表1长,则将链表2的剩余部分直接插入到和多项式中
		//链表1比链表2长,则什么都不用做
		pre->next = q;
	}
	free(pb);
}