#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef int DataType;//定义int类型为DataType类型
struct List
{
	int Max;		//最大元素个数
	int n;			//实际元素个数,按下标走,从0开始
	DataType *elem;	//首地址
};
typedef struct List *SeqList;//对顺序表类型进行定义

//初始化函数
SeqList setNullList_seq(int m)
{
	//申请结构体空间
	SeqList slist = (SeqList)malloc(sizeof(struct List));
	//首先判空,不为空证明申请内存成功
	if (slist != NULL)
	{
		//申请数组空间,即DataType型,也就是int型
		//申请了m个DataType型的内存空间
		slist->elem = (DataType*)malloc(sizeof(DataType)*m);
		//判断是否有首地址,有则证明有效空间
		if (slist->elem)
		{
			slist->Max = m;	//顺序表最大值
			slist->n = 0;	//顺序表内无元素,即长度为0
			return slist;
		}
		else
		{
			//否则直接释放申请空间
			free(slist);
		}
	}
	//申请不成功,返回空值,跳出函数
	printf("out of space!\n");
	return NULL;
}

//判空函数
int IsNullList(SeqList slist)
{
	//返回值是1或0,故为int型
	return(slist->n == 0);
}

//插入函数
int InsertPre_seq(SeqList slist, int p, DataType x)
{
	int q;
	//判断顺序表是否已满
	if (slist->n >= slist->Max)
	{
		printf("overflow!\n");
		return(0);
	}
	//判断输入的位置是否合法,即是否能够拥有下标为p的元素
	if (p<0 || p>slist->n)
	{
		printf("not exist!\n");
		return(0);
	}
	//通过判断,进行插入操作
	for (q = slist->n - 1; q >= p; q--)
	{
		//插入位置之后的元素先后移,空出位置
		slist->elem[q + 1] = slist->elem[q];
	}
	//插入元素x,顺序表长度+1
	slist->elem[p] = x;
	slist->n = slist->n + 1;
	return(1);
}

//删除元素函数
int DelIndex_seq(SeqList slist, int p)
{
	//删除下标为p的元素
	int q;
	if (p < 0 || p >= slist->n)
	{
		//判断p是否合法
		printf("not exist!\n");
		return 0;
	}
	//通过判断,开始删除操作
	for (q = p; q < slist->n; q++)
	{
		//p位置之后的每个元素向前覆盖
		slist->elem[q] = slist->elem[q + 1];
	}
	//顺序表长度-1
	slist->n = slist->n - 1;
	return 1;
}

//打印顺序表
void Print_seq(SeqList slist)
{
	int i;
	for (i=0;i<slist->n;i++)
	{
		//依靠首位置指针慢慢移动进行输出即可
		printf("%d", slist->elem[i]);
		printf(" ");
	}
	printf("\n");
}

//查找值为x的元素,返回元素所在位置的下标
int LocateIndex_seq(SeqList slist, int x)
{
	int q;
	for (q = 0; q < slist->n; q++)
	{
		//查找成功,返回对应的下标
		if (slist->elem[q] == x)
			return q;
	}
	return -1;
}

//二分查找算法---减而治之
//*pos用于记录如果查找失败的情况下,这个元素插入到顺序表中应当插入的位置
int Binsearch_seq(SeqList slist, int key, int *pos)
{
	int index = 1;//用于记录比较次数
	int mid;
	int low = 0;
	int high = slist->n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		//一次查找成功,返回1
		if (slist->elem[mid] == key)
		{
			*pos = mid;
			printf("找到元素,共进行了%d次比较\n", index);
			printf("要找的数据%d在位置%d上\n", key, mid);
			return 1;
		}
		//二分策略
		else if (slist->elem[mid] > key)
				high = mid - 1;
		else	low = mid + 1;
		//比较次数增加
		index++;
	}
	*pos = low;
	printf("没有找到元素,共进行了%d次比较\n", index - 1);
	printf("可将此数插入到位置%d上\n", *pos);
	return -1;
}

int main()
{
	//定义一个SeqList,即List结构对象
	SeqList seqlist;
	//初始化顺序表,给定顺序表最大为12
	seqlist = setNullList_seq(12);
	//首先进行判空函数测试
	printf("%d", IsNullList(seqlist));
	printf("\n");
	//读取输入内容,建立顺序表
	printf("输入顺序表的元素: \n");
	int i, x;
	//循环输入7个元素
	for (i=0;i<7;i++)
	{
		scanf_s("%d", &x);
		InsertPre_seq(seqlist, i, x);
	}
	//顺序表建立完成,返回一下顺序表长度
	printf("%d", seqlist->n);
	printf("\n");
	//再次进行判空操作
	printf("顺序表是否为空,1为空,0为非空: %d\n", IsNullList(seqlist));
	//遍历顺序表,输出元素
	printf("当前顺序表的元素是: ");
	Print_seq(seqlist);
	//测试删除函数
	DelIndex_seq(seqlist, 3);
	printf("删除下标为3的元素后的顺序表为: ");
	//再次遍历查看结果
	Print_seq(seqlist);
	//在2位置插入99这一元素
	InsertPre_seq(seqlist, 2, 99);
	printf("在下标2位置之前插入99后顺序表为: ");
	//再次遍历查看结果
	Print_seq(seqlist);
	//测试查找函数
	int y = 3;
	int m = LocateIndex_seq(seqlist, y);
	printf("值为%d的元素在顺序表的%d位置", y, m);
	printf("\n");
	//测试二分查找算法
	int key = 4;//之前删掉了这个位置的元素,应该显示无法匹配
	int pos;
	Binsearch_seq(seqlist, key, &pos);
}