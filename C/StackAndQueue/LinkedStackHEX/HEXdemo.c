#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

//实现8进制的转换
void OctConversion(LinkedStack ps, int n)
{
	int temp = 0;//初始化temp
	while (n)
	{
		//将n除以8的余数压入栈中
		Push_link(ps, n % 8);
		//新的n = 原n / 8  (的商)
		n /= 8;
	}
	printf("转换为八进制之后,结果为:");
	//只要不空就一直出栈,直到栈为空为止
	while (!IsNullStack_link(ps))
	{
		//在这里修改了8进制的出栈调用函数
		//temp = Pop_seq_return(ps);
		temp = PopWithReturn_link(ps);
		printf("%d", temp);
		//Pop_link(ps);
	}
	printf("\n");
	//End OCTONARY
}

//实现16进制的转换
void HexConversion(LinkedStack ps, int n)
{
	//在16进制中,有ABCDEF的显示,需要加一个switch句段
	int temp = 0;//初始化temp
	while (n)
	{
		//对16求模,赋值给temp,经过判断之后再压入栈中
		temp = n % 16;
		switch (temp)
		{
		case 10:
		{
			temp = 'A';
			break;
		}
		case 11:
		{
			temp = 'B';
			break;
		}
		case 12:
		{
			temp = 'C';
			break;
		}
		case 13:
		{
			temp = 'D';
			break;
		}
		case 14:
		{
			temp = 'E';
			break;
		}
		case 15:
		{
			temp = 'F';
			break;
		}
		default:
			break;
		}
		//进栈
		Push_link(ps, temp);
		//n = n/16
		n /= 16;
	}
	printf("转换为十六进制后的结果为:");
	while (!IsNullStack_link(ps))
	{
		//在这里修改了16进制的出栈调用函数
		temp = PopWithReturn_link(ps);
		//temp = Pop_seq_return(ps);
		if (temp<10)
		{
			printf("%d", temp);
		}
		else
		{
			printf("%c", temp);
		}
		//输出一个数就出一次栈,直到栈为空
		//Pop_link(ps);
	}
	printf("\n");
	//End HEXADECIMAL
}

//实现2进制的转换
void BinConversion(LinkedStack ps, int n)
{
	int temp = 0;//初始化temp
	while (n)
	{
		//将n除以2的余数压入栈中
		Push_link(ps, n % 2);
		//新的n = 原n / 2  (的商)
		n /= 2;
	}
	printf("转换为二进制之后,结果为:");
	//只要不空就一直出栈,直到栈为空为止
	while (!IsNullStack_link(ps))
	{
		//在这里修改了2进制的出栈调用函数
		temp = PopWithReturn_link(ps);
		//temp = Pop_seq_return(ps);
		printf("%d", temp);
		//Pop_link(ps);
	}
	printf("\n");
	//End BINARY
}

int main()
{
	//创建空栈
	LinkedStack mystack = SetNullStack_Link();
	int n = 0;
	printf("*************************************************\n");
	printf("请输入需要转换的十进制数:");
	scanf_s("%d", &n);
	printf("\n");
	printf("请输入需要显示哪种进制的结果:\n");
	printf("1.2进制\n");
	printf("2.8进制\n");
	printf("3.16进制\n");
	printf("4.全部进制显示\n");
	printf("*************************************************\n");
	int i = 0;//switch的判断值
	scanf_s("%d", &i);
	if (i>4)
	{
		printf("输入错误!即将结束程序!\n");
		return 0;
	}
	switch (i)
	{
		case 1:
		{
			BinConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		case 2:
		{
			OctConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		case 3:
		{
			HexConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		case 4:
		{
			printf("你输入的十进制数为:%d", n);
			printf("\n");
			BinConversion(mystack, n);
			OctConversion(mystack, n);
			HexConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		default:
			break;
	}

	system("pause");
}