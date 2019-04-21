#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct Node
{
	DataType data;
	struct Node * next;
};
typedef struct Node Node;

//函数功能:给出具体条件下Josephus问题的解表
//输入参数:n-->总人数,s-->起始位置,k-->间隔
//返回值:无
void Josephus(int n, int s, int k)
{
	Node *current = (Node *)malloc(sizeof(Node));
	Node *prev = (Node *)malloc(sizeof(Node));
	Node *head = (Node *)malloc(sizeof(Node));
	prev = head;
	//尾插法建立循环链表
	for (int i = 1; i <= n; i++)
	{
		current = (Node *)malloc(sizeof(Node));
		current->data = i;
		prev->next = current;
		prev = current;
	}
	//最后一个结点的next指向开头,构成循环链表
	prev->next = head->next;

	current = head->next;
	for (int i = 1; i < s; i++)
	{
		//current指针移动s-1次,指向第s个结点
		prev = prev->next;
		current = current->next;
	}
	//循环出列显示,并删除结点
	while (current->next != current)
	{
		for (int i = 1; i < k; i++)
		{
			prev = prev->next;
			current = current->next;//current指针移动k-1次,指向要删除的结点
		}
		prev->next = current->next;
		printf("当前出列的序号是%d\n", current->data);
		free(current);//删除已出列的结点
		current = prev->next;
	}
	//当current->next = current时,即剩最后一个元素
	printf("最后一个出列的序号是%d\n", current->data);
}

void main()
{
	int n, k, s, answer;//n为总人数,s为起始位置,k为间隔
	//第s个人从1开始报数,报到k的人出列,下一个人再从1开始报数
	printf("请输入总人数n,起始位置s,间隔k\n");
	scanf_s("%d,%d,%d", &n, &s, &k);
	Josephus(n, s, k);
}

//这个算法有很多需要改进的地方,例如有些结点没有被删除(比如最后一个结点)