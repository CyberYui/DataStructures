#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

//括号匹配算法
int BracketMatch(LinkedStack top)
{
	int flag = 1;//标志
	//定义并初始化输入的表达式和临时变量
	char ch = "a";
	char temp = "b";
	printf("请输入要判断的表达式,用#号结束:");
	//直接输入表达式之后用#表示结束即可
	scanf_s("%c", &ch);
	while (ch != '#')
	{
		//小括号
		if (ch == '(')//是左括号,压入栈中
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch == ')')//右括号,检查是否出栈
			{
				//先取出栈顶元素,看是不是匹配
				temp = Pop_seq_return(top);//如果有右括号多现象,虽然栈空,但flag=0
				if (temp == '(')
				{
					//括号匹配,栈顶出栈
					Pop_link(top);
				} 
				else
				{
					//不匹配,flag=0,跳出循环
					flag = 0;//右括号不是期望的右括号
					break;
				}
			} 
		}
		//中括号
		if (ch == '[')//是左括号,压入栈中
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch == ']')//右括号,检查是否出栈
			{
				//先取出栈顶元素,看是不是匹配
				temp = Pop_seq_return(top);//如果有右括号多现象,虽然栈空,但flag=0
				if (temp == '[')
				{
					//括号匹配,栈顶出栈
					Pop_link(top);
				}
				else
				{
					//不匹配,flag=0,跳出循环
					flag = 0;//右括号不是期望的右括号
					break;
				}
			}
		}
		//大括号
		if (ch == '{')//是左括号,压入栈中
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch == '}')//右括号,检查是否出栈
			{
				//先取出栈顶元素,看是不是匹配
				temp = Pop_seq_return(top);//如果有右括号多现象,虽然栈空,但flag=0
				if (temp == '{')
				{
					//括号匹配,栈顶出栈
					Pop_link(top);
				}
				else
				{
					//不匹配,flag=0,跳出循环
					flag = 0;//右括号不是期望的右括号
					break;
				}
			}
		}
		scanf_s("%c", &ch);
	}//while end
	//循环结束后
	if (!flag || !IsNullStack_link(top))
	{
		//如果有不期望现象,或者有左括号多现象,则不匹配
		printf("\n不匹配!\n");
		return 0;
	} 
	else
	{
		printf("\n匹配!\n");
		return 1;
	}
}

int main()
{
	LinkedStack sstack = SetNullStack_Link();//创建一个空链栈
	BracketMatch(sstack);

	system("pause");
	return 0;
}