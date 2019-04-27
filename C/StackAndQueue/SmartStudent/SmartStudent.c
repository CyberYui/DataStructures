#include <stdlib.h>
#include <stdio.h>
//找出t2-->t1最小提问次数
int step(int t1, int t2)
{
	if (t2 > t1)
	{
		//一轮之内回答
		return t2 - t1;
	}
	else
	{
		//进行一轮提问之后才能回答
		return 3 + t2 - t1;
	}
}
//打印一次数组的内容
void array_print(int temp[3])
{
	int z;
	for (z = 0; z < 3; z++)
	{
		printf("%d ", temp[z]);
	}
}
//假设每次数最大的人坐在t3这个位置上
//教授提问多少次t3能正确回答问题
//i代表t1的数,j代表t2的数,定义t1,t2,t3
int times(int i, int j, int t1, int t2, int t3)
{
	int k;
	k = i - j;//定义i-j的结果
	int temp[3] = { 0 };
	//如果i-j==0,即代表数值最大人的数确定
	if (k == 0)
	{
		return t3;
	}
	//无法一轮得出结论,需要递归
	if (k > 0)
	{
		//
		temp[t2 - 1] = j;
		temp[t3 - 1] = i - j;
		temp[t1 - 1] = i;
		//打印本次递归的问题转化
		array_print(temp);
		printf("\n");
		//继续递归
		return times(j, i - j, t2, t3, t1) + step(t1, t3);//此时t1最大,加上t1到t3的步数,
	}
	//无法一轮得出结论,需要递归
	if (k < 0)
	{
		//
		temp[t2 - 1] = j;
		temp[t3 - 1] = j - i;
		temp[t1 - 1] = i;
		//打印本次递归的问题转化
		array_print(temp);
		printf("\n");
		//继续递归
		return times(i, j - i, t1, t3, t2) + step(t2, t3);//此时t2最大,加上t2到t3的步数,
	}
}

int main()
{
	int result;//定义结果
	int a = 1, b = 2, c = 3;//学生顺序
	int arr[3] = { 3,8,5 }; //存三个学生的数的数组
	//定义下标
	int index = 0;
	//存储第一大和一个不是最大的数
	int max_num = -1;
	int mid_num = -1;
	//存储第一大和一个不是最大的数的下标
	int max_index = -1;
	int mid_index = -1;
	//循环,找出最大的数
	for (index = 0; index < 3; index++)
	{
		//当最大数小于数组中的某个数时,更换最大数及其下标
		if (max_num < arr[index])
		{
			max_num = arr[index];
			max_index = index;
		}
	}
	//循环,找出一个不是最大的数
	for (index = 0; index < 3; index++)
	{
		//将这个数保存下来
		if (mid_num < arr[index] && arr[index] != max_num)
		{
			mid_num = arr[index];
			mid_index = index;
		}
	}
	//t3占有最大的数
	c = max_index + 1;
	//t2占据一个数
	b = mid_index + 1;
	//交换位置,使得学生顺序a,b,c总是排位c的学生所持数最大
	if ((c == 1 && b == 2) || (c == 2 && b == 1))
	{
		a = 3;
	}
	else if ((c == 2 && b == 3) || (c == 3 && b == 2))
	{
		a = 1;
	}
	else
	{
		a = 2;
	}
	//开始输出
	printf("推导过程:\n");
	array_print(arr);//首先输出一次原始问题
	printf("\n");
	//保证c是最大的数,将t1和t2的数与相应的数组内元素对应即可
	//即无论是(3,5,8)还是(5,3,8)都可以
	//ab谁前谁后无所谓，只要找到正确的最大值和ab正确坐标即可
	result = times(arr[a - 1], arr[b - 1], a, b, c);
	//得到结果
	printf("第%d位学生", c);
	printf("在第%d次提问时回答正确\n", result);
	return 0;
}