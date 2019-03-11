#include <iostream>
#include <stdlib.h>
#include <string>
#include "StackParentMatch.h"

using namespace std;

/*****************************************************************************/
/*	栈应用---括号匹配														 */
/*																			 */
/*	描述:输入任意一组括号,可以判断括号是否匹配								 */
/*		   		     			   											 */
/*	字符串示例:[()]   [()()]  {[][()()]}  [[(())]}}							 */
/*																			 */
/*	实验目的:通过此例灵活掌握栈机制的使用技巧								 */
/*																			 */
/*  创建日期:2019-03-11          Author:Cyber Kaka							 */
/*****************************************************************************/

//具体逻辑:
//以第一组字符串[()]为例
//首先栈中是空的,扫描字符串,找到了[,会从栈中找另一半,发现没有,就入栈
//接着继续扫描字符串,找到(,从栈中未找到另一半,继续入栈,此时(为栈顶
//接着继续扫描字符串,找到),从栈中扫描到了(,则将栈中的(出栈,从而匹配了一个括弧
//接着扫描字符串,找到],从栈中扫描到了[,则将栈中的[出栈,从而匹配了另一个括弧
//继续扫描,发现字符串已经结束
//判断栈中是否还有元素,发现没有元素,从而判断字符串的括弧匹配
//反之,以第四组为例,在最后栈中剩下元素,从而判断字符串的括弧不匹配

int main(void)
{
	//我们需要定义一个栈,存放无法匹配的字符
	//这个字符有另一半需要与其匹配,对于需要匹配的另一半也存入一个栈中
	//未来就使用这个另一半存放的栈和字符串对比,如果没有相同的,
	//就继续扫描字符串,存放于第一个栈中,再进行另一半栈的对比
	//以此类推

	//定义两个栈,用char类型即可
	MyStack<char> *pStack = new MyStack<char>(30);//存放字符

	MyStack<char> *pNeedStack = new MyStack<char>(30);//存放所需字符

	//定义字符数组
	char str[] = "[[(())]}}";//不用写数组长度的原因是这样可以由计算机自由分配数组

	//定义变量表示当前所需的字符
	char currentNeed = 0;//给其的值须为不可见的字符的ASCII码值
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (str[i] != currentNeed)
		{
			//如果字符串中没有与匹配栈对应的内容,则将字符推入括弧栈
			pStack->push(str[i]);
			//进行比对,判断是哪一种括号,之后将对应所需括号给currentNeed赋值
			//首先应对currentNeed进行判断,如果它里面有内容,则将内容推给匹配栈
			//把判断写在分支内部的原因是为了日后拓展好细分内容
			switch (str[i])
			{
			case '[':
				if (currentNeed != 0)
				{
					//如果currentNeed已经有内容,则将内容放到匹配栈中
					//如果没有内容,则将相对应的匹配括弧赋值给currentNeed
					pNeedStack->push(currentNeed);
					currentNeed = ']';
				}
				else
				{
					currentNeed = ']';
				}
				break;
				//if (currentNeed!=0)
				//{
				//	//如果currentNeed已经有内容,则将内容放到匹配栈中
				//	//如果没有内容,则将相对应的匹配括弧赋值给currentNeed
				//	pNeedStack->push(currentNeed);
				//}
				//currentNeed = ']';
				//break;
			case '(':
				if (currentNeed != 0)
				{
					pNeedStack->push(currentNeed);
					currentNeed = ')';
				}
				else
				{
					currentNeed = ')';
				}
				break;
			case '{':
				if (currentNeed != 0)
				{
					pNeedStack->push(currentNeed);
					currentNeed = '}';
				}
				else
				{
					currentNeed = '}';
				}
				break;
			default:
				cout << "字符串不匹配" << endl;
				system("pause");

				delete pStack;
				pStack = NULL;

				delete pNeedStack;
				pNeedStack = NULL;

				return 0;
			}
		}
		else
		{
			//如果字符串有与匹配栈对应的内容,即当前匹配已经形成
			//则括弧栈中对应的半个括号应该被弹出,匹配栈中相关内容也被弹出
			char elem = 0;//定义临时变量
			pStack->pop(elem);
			//当推出半个括号之后,栈顶改变,则currentNeed也需要被改变
			//这时候currentNeed的内容就是现在改变了栈顶之后的栈顶匹配的括弧
			//pNeedStack->pop(currentNeed);
			//从而扫描的时候就能继续匹配了

			//如果pop(currentNeed)失败的话,应该将其赋值为初值
			//以此完善代码
			if (!pNeedStack->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
	}

	//当匹配结束之后,判断一下字符串是否已经结束
	if (pStack->stackEmpty())
	{
		cout << "字符串匹配" << endl;
	}
	else
	{
		cout << "字符串不匹配" << endl;
	}

	delete pStack;
	pStack = NULL;

	delete pNeedStack;
	pNeedStack = NULL;

	system("pause");
	return 0;
}