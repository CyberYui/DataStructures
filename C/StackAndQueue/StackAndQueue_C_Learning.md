关于栈和队列的相关知识<font color=brown>(C语言)</font>
=====

```c
//如切如磋者,道学也;如琢如磨者,自修也.
```

栈和队列是一对双胞胎,其关键词是:<font color=purple>**策略工具+递归思想**</font><br>

|相关应用|迷宫问题|农夫过河问题|
|:---------:|:----------:|:----------:|
|工具|<font color=green>栈</font>|<font color=green>队列</font>|
|策略|<font color=red>深度</font>优先策略|<font color=red>广度</font>优先策略|

>同样的,栈也可以用于解决农夫过河问题,队列也可以用于解决迷宫问题

栈和队列的概念
-----------

<table>
    <tr>
        <td><center>栈</center></td> 
        <td><center>队列</center></td>
   </tr>
    <tr>
        <td colspan="2"><center>栈和队列是<font color=whitegr>操作受限</font>的<font color=whitegr>线性表</font></center></td>
    </tr>
    <tr>
        <td>栈限定在<font color=blue>表尾进行插入或删除</font><br>
表尾端称<font color=blue>栈顶</font>,表头端称<font color=blue>栈底</font>.</td>
        <td>而队列限定在<font color=blue>一端进行插入、一端删除</font><br>
插入端称<font color=blue>队尾</font>,删除端称<font color=blue>队头</font>.</td>
    </tr>
    <tr>
        <td><center>栈的特点:<br>
        <font color=red>后进先出(LIFO)</font></center></td>
        <td><center>队列的特点:<br>
        <font color=red>先进先出(FIFO)</font></center></td>
    </tr>
    <tr>
        <td colspan="2"><center>两者的区别就在于<font color=pink>栈是后进先出,队列是先进先出</font></center></td>
    </tr>
</table>

* 栈的后进先出
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/StackGraphEx1.png)<br>

* 队列的先进先出
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/QueueGraphEx1.png)<br>

栈和队列的抽象数据类型
------------

* 栈的抽象数据类型:

```c(fake)
ADT Stack is
Operations
    Stack SetNullStack(void)            //创建一个空栈
    int IsNullStack(Stack stack)        //判断栈是否为空栈
    void Push(Stack stack,Datatype x)   //往栈中插入(推入)一个元素
    void Pop(Stack stack)               //从栈中删除(弹出)一个元素
    Datatype Top(Stack stack)           //获取栈顶元素的值
End ADT Queue
```

* 队列的抽象数据类型:

```c(fake)
ADT Queue is
Operations
    Queue SetNullQueue(void)            //创建一个空队列
    int IsNullQueue(Queue que)          //判断队列que是否为空
    void enQueue(Queue que,Datatype x)  //向队列que中插入元素x
    void DeQueue(Queue que)             //从队列que中删除一个元素
    Datatype Front(Queue que)           //获取队头元素
End ADT Queue
```

栈举例(便于理解之前提到的栈的抽象数据类型)
--------
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/StackExample1.png)<br>

栈混洗
--------
&emsp;&emsp;假设有n个数据(a<sub>1</sub>,a<sub>2</sub>,...,a<sub>n</sub>)依次进栈,并随时可能出栈,按照其出栈次序得到的每一个序列(a<sub>k1</sub>,a<sub>k2</sub>,...,a<sub>kn</sub>)都称为一个<font color=red>栈混洗</font>.<br>
&emsp;&emsp;现在考虑有三个元素(i,j,k)<font color=blue>按照先后次序</font>压入栈中,则可能的栈混洗有五种:<br>
(i,j,k)&emsp;(i,k,j)&emsp;(k,j,i)&emsp;(j,i,k)&emsp;(j,k,i)<br>
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/StackMixedGraph1.png)<br>

>[注意]虽然三个元素的排列有六种可能,但<font color=whitegr>(k,i,j)</font>不是栈混洗

&emsp;&emsp;一般地,对于长度为n的输入序列,每一个栈混洗都对应n次push和n次pop构成的合法序列,反之,由n次push和n次pop构成序列,只要满足"任一前缀中的push不少于pop"这个限制条件,则该序列也必然对应于一个栈混洗.<br>
&emsp;&emsp;对于上述三个数据的栈混洗,可以推广到栈混洗的甄别的一般情况:<br>
&emsp;&emsp;即任意三个元素能否按某相对次序出现于混洗中,与其他元素无关.<br>
&emsp;&emsp;对于任何1<=i<j<k<=n,(k,i,j)必然非栈混洗,其余为栈混洗.推广到更为一般的序列(1,2,3,...,i,...,j,...,k,...,n),形如(...,k,...,i,...,j,...)的序列必然不是栈混洗.<br>

栈按顺序的实现---顺序栈(栈的实现:顺序表示)
==========
* 和顺序表类似,顺序栈是一个<font color=red>静态结构</font>,需要提前分配好空间位置
* <font color=red>进栈</font>:MAXNUM是栈中最大元素个数,当栈中已经有这么多元素时,再进行进栈操作就会产生数据溢出现象,称为<font color=red>上溢(overflow)</font>
* <font color=red>出栈</font>:做出栈运算时,首先需要判断是否为空栈,否则同样会产生溢出,称为<font color=red>下溢(underflow)</font>
* 写相应运算的算法时,注意<font color=red>判断栈满或栈空</font>

栈的类型定义
-------
```c
typedef int DataType;
struct Stack
{
    int MAX;        //最大容量
    int top;        //栈顶指针
    DataType *elem; //存放元素的数组起始指针
};
typedef struct Stack *SeqStack//定义顺序栈类型
```

创建空栈
-------
<font color=brown>[算法思路]</font><br>
&emsp;创建空的顺序栈就是为顺序栈分配一个预先定义的数组空间,并将顺序栈的栈顶top成员变量设置为-1

```c
//创建空顺序栈,m是分配的最大空间
SeqStack SetNullStack_Seq(int m)
{
    //定义变量sstack
    SeqStack sstack=(SeqStack)malloc(sizeof(struct SeqStack));
    if(sstack!=NULL)
    {
        //申请结构体空间成功,开始申请数组空间
        sstack->elem=(int*)malloc(sizeof(int)*m);
        if(sstack->elem!=NULL)
        {
            //申请数组空间成功,开始初始化
            sstack->MAX=m;  //顺序栈最大容量
            sstack->top=-1; //设置栈顶初值为-1,这样压入元素就会从0开始
            return(sstack); //返回初始化了的栈
        }
        else
        {
            //申请结构体空间成功,但申请数组空间失败
            free(sstack);//释放结构体空间
            return NULL;
        }
    }
    else
    {
        //申请空间失败
        printf("out of space!");
        return NULL;
    }
}
```
>[注]这样设计之后,进栈就必须栈顶+1再进栈


判断栈是否为空
---------
<font color=brown>[算法思路]</font><br>
&emsp;顺序栈的判空是检查栈顶指针是否等于初始化的-1,若等于-1,则是空栈,返回1,否则返回0

```c
//判断一个栈是否为空
int IsNullStack_seq(SeqStack sstack)
{
    return(sstack->top==-1);    //检查栈顶top是否为-1
}
```

判断栈是否为满
----------

<font color=brown>[算法思路]</font><br>
&emsp;检查栈顶是否已经达到了最大值,如果是,则栈已满,否则栈不满

```c
//判断一个栈是否为满
int IsFullStack_seq(SeqStack sstack)
{
    //检查栈顶是否已经达到了最大值,数组从0数,所以是MAX-1
    return(sstack->top >= sstack->MAX-1);
}
```

进栈
-------
<font color=brown>[算法思路]</font><br>
&emsp;首先判断栈是否满了,也就是检查栈顶是否已经达到了最大值,如果是,则不能再进行进栈操作,否则能够进栈.进栈时需要先修改栈顶,然后将元素压入栈中.

```c
void Push_seq(SeqStack sstack,int x)
{
    //压入x元素进入栈中
    if(IsFullStack_seq(sstack))
    {
        printf("Overflow!\n");
    }
    else
    {
        sstack -> top++;                    //若不满,先修改栈顶变量
        sstack -> elem[sstack->top] = x;    //把元素x放到栈顶变量的位置中
    }
}
```

出栈
--------
<font color=brown>[算法思路]</font><br>
&emsp;首先检查栈是否为空,如果是空栈,输出提示信息,不为空,则栈顶指针减1

```c
void Pop_seq(SeqStack sstack)
{
    //出栈
    if(IsNullStack_seq(sstack))
    {
        //判断栈是否为空,为空则提示
        printf("Underflow!\n");
    }
    else
    {
        //栈非空,出栈栈顶元素,栈顶逻辑-1即可,原内容会被下次入栈给覆盖掉
        sstack->top = sstack->top-1;    //栈顶减1
    }
}
```

获取栈顶元素
--------
<font color=brown>[算法思路]</font><br>
&emsp;取顺序栈的栈顶元素时,首先检查是否为空栈,如果是空栈,输出提示信息;否则,返回栈顶元素.

```c
//取栈顶元素
DataType Top_seq(SeqStack sstack)
{
    if(IsNullStack_seq(sstack))
    {
        //判断栈是否为空,为空则提示
        printf("It is an empty stack!\n");
        return 0;
    }
    else
    {
        return sstack->elem[sstack->top];
    }
}
```

*******************************************

链栈的实现
=========


链栈的类型定义
--------
```c
typedef int DataType;
struct Node
{
    DataType data;
    struct Node *next;
};
typedef struct Node *PNode; //结点类型
typedef struct Node *top,*LinkedStack;   //栈顶和链栈类型,其实top和LinkStack是一样的含义
```
>[注意]为和之前的链表一致,链栈也设置了头结点,指针从栈顶开始,往栈底方向链接,注意是有头结点的

![F5](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/LinkedStackGraph1.png)<br>

创建空栈
-------
<font color=brown>[算法思路]</font><br>
&emsp;创建空的链栈,需要申请struct Node结构体空间,并设置top的next为空,因为这里是<font color=green>**带有头结点**</font>的空链栈.

```c
//创建带有头结点的空链栈
LinkedStack SetNullStack_Link()
{
	//申请结点空间
	LinkedStack top = (LinkedStack)malloc(sizeof(struct Node));
	if (top != NULL)
	{
		top->next = NULL;	//头结点之后为NULL,因为是空栈
	}
	else
	{
		printf("Alloc failure!\n");
	}
	return top; //返回栈顶指针
}
```

判断链栈是否为空
---------
<font color=brown>[算法思路]</font><br>
&emsp;判断链栈中栈顶结点的后即指针是否为空,若为空则是空栈,返回1,否则返回0

```c
//判断一个链栈是否为空
int IsNullStack_link(LinkedStack top)
{
    if(top->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
```

>[注意]链栈是没有满一说的,只要允许,它可以推进去无数个结点

进栈
-------
>[注意]进栈都是从栈顶进行的,所以每一个新结点进栈都是从头结点之后压入栈中的

![F6](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/LinkedStackPush1.png)<br>

1. 设要压入的结点为p,首先<code>p->next = top->next</code>
2. 之后断开头结点和D的链接,<code>top->next = p</code>

<font color=brown>[算法思路]</font><br>
&emsp;将一个元素压入链栈中,首先要申请结点空间,然后给数据域和指针域赋值,并修改栈顶top的后继指针,将其赋值为新插入的结点

```c
//进栈
void Push_link(LinkedStack top, DataType x)
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node)); //申请结点空间
	if (p == NULL)
	{
		printf("Alloc failure!\n");
	}
	else
	{
		p->data = x;            //数据域赋值
		p->next = top->next;    //指针域赋值
		top->next = p;          //修改栈顶
	}
}
```

出栈
----------
>[注意]出栈同样是在栈顶进行,出栈永远都是出头结点之后的结点

![F7](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/LinkedStackPop1.png)<br>

1. 设要出栈的结点为D,令为p结点,首先<code>p=top->next;</code>
2. 修改头结点的next,<code>top->next = p->next;</code>
3. 释放掉D结点,<code>free(p)</code>

<font color=brown>[算法思路]</font><br>
&emsp;出栈时,首先判断栈是否为空,如果栈不为空,则修改栈顶指针,释放结点空间

```c
//删除栈顶元素
void Pop_link(LinkedStack top)
{
    PNode p;
    if(IsNullStack_link(top))
    {
        printf("It is an empty stack!\n");
    }
    else
    {
        p = top->next;          //p指向待删除结点
        top->next = p->next;        //修改栈顶指针
        free(p);                //释放要删除的结点的空间,完成删除
    }
}
```

取栈顶元素
---------
<font color=brown>[算法思路]</font><br>
&emsp;先判断栈是否为空,为空则提示,不为空则取栈顶元素的值,并返回.

>[注意]操作过程中栈的结构要保持不变

```c
//取出栈顶元素
DataType Pop_seq_return(LinkedStack top)
{
	//判断栈是否为空
	if (IsNullStack_link(top))
	{
		printf("It is an empty stack!\n");
		return 0;	//因为DataType即是int类型
	}
	else
	{
		return top->next->data;
	}
}
```

********************************************
栈的应用举例
=========
* 数制转换
* 括号匹配
* 迷宫问题
* 栈和递归:"聪明的学生"
* 表达式求值

数制转换
------
&emsp;即类似于计算器的进制转换,这种问题是如何实现的呢?<br>
算法的基本原理:<font color=green>**N=(N div d)*d+N mod d**</font><br>

[例子]<font color=orange>(2016)<sub>10</sub>=(3740)<sub>8</sub></font><br>
&emsp;在计算时,需要记录两个信息:<br>
1. N div 8 (即N除以8得到的商)
2. N mod 8 (即N除以8得到的余数)

表格如下:<br>
|N|N div 8(商)|N mod 8(余数)|
|:------:|:------:|:------:|
|2016|252|0  <font color=red>低位</font>|
|252|31|4&nbsp;&emsp;&emsp;|
|31|3|7&nbsp;&emsp;&emsp;|
|3|0|3  <font color=red>高位</font>|
这样获得一个由低到高的0473这四个数字<br>
逆序输出这四个数字,即<font color=red>3740</font>就是所要求的八进制数
>[注]计算顺序和输出顺序相反

<font color=pink>**代码实现参照LinkedStackHEX项目**</font>

相关主要代码:
-----------
<1>.实现8进制的转换
```c
//实现8进制的转换
void OctConversion(LinkedStack ps, int n)
{
	int temp;
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
		temp = Pop_seq_return(ps);
		printf("%d", temp);
		Pop_link(ps);
	}
	printf("\n");
	//End OCTONARY
}
```

<2>.实现16进制的转换
```c
//实现16进制的转换
void HexConversion(LinkedStack ps, int n)
{
	//在16进制中,有ABCDEF的显示,需要加一个switch句段
	int temp;
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
		temp = Pop_seq_return(ps);
		if (temp<10)
		{
			printf("%d", temp);
		}
		else
		{
			printf("%c", temp);
		}
		//输出一个数就出一次栈,直到栈为空
		Pop_link(ps);
	}
	printf("\n");
	//End HEXADECIMAL
}
```

<3>.实现2进制的转换
```c
//实现2进制的转换
void BinConversion(LinkedStack ps, int n)
{
	int temp;
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
		temp = Pop_seq_return(ps);
		printf("%d", temp);
		Pop_link(ps);
	}
	printf("\n");
	//End BINARY
}
```

一个特殊的出栈操作
---------
<font color=brown>[改进措施]</font><br>
&emsp;&emsp;之前的函数中,出栈和取栈元素的函数是分开的,这样导致要想在出栈前输出栈顶元素,需要先调用Pop_seq_return(取栈顶元素函数),然后再调用Pop_link(出栈函数),很麻烦<br>
&emsp;&emsp;所以写出一个PopWithReturn_link(出栈并取栈顶元素函数),代码如下<br>
```c
//出栈栈顶元素,并返回其值
DataType PopWithReturn_link(LinkedStack top)
{
	PNode p;
	int temp = 0;
	//判断栈是否为空
	if (IsNullStack_link(top))
	{
		printf("It is an empty stack!\n");
		return 0;	//因为DataType即是int类型
	}
	else
	{
		temp = top->next->data;	//保存栈顶结点数据域内容
		//出栈栈顶
		p = top->next;          //p指向待删除结点
		top->next = p->next;    //修改栈顶指针
		free(p);                //释放要删除的结点的空间,完成删除
		return temp;
	}
}
```

括号匹配
--------
&emsp;在编码过程中,会使用到()和[]以及{}这样的括号,使用栈就可以知道这些括号是否匹配<br>

&emsp;假设允许有两种括号:圆括号()和方括号[]<br>
那么"([]())"这样的就是一种匹配的情况,"([][()]"这样的就是不匹配的情况<br>

检查括号是否匹配的方法可以用"<font color=red>期待的优先级</font>"这个概念描述.
例如:考虑下列的括号序列
|[|(|[|]|)|]|
|:------:|:------:|:------:|:------:|:------:|:------:|
|1|2|3|4|5|6|

第一步,获取到了一个[,那么就要有相应的"]"来对应它<br>
但是第二步,获取到了(,那么就要再有相应的")"来对应它<br>
以此类推,在匹配时,优先级最高的是3,当3匹配成功后,优先级最高的变为2,从而慢慢完成匹配<br>
这种特性刚刚好满足栈的结构,即栈顶元素最后入栈,但优先级最高

[分析]可能的不匹配情况有三种:
* 到来的右括号不是所"期待"的;
		例子:[())
* 有多余的右括号;
		例子:[()]]
* 有多余的左括号,即直到结束也有未匹配项;
		例子:[()

<font color=brown>[算法的设计思路]</font>:<br>
1. 只要出现左括号,就进栈
2. 只要出现右括号,首先检查<font color=blue>栈是否为空</font>:<br>
&emsp;栈空,则表明<font color=orange>右括号多了</font>;<br>
&emsp;栈不空,则<font color=blue>与栈顶元素比较</font>:<br>
&emsp;&emsp;&emsp;&emsp;&emsp;若匹配,则左括号出栈;<br>
&emsp;&emsp;&emsp;&emsp;&emsp;若不匹配,直接就可以结束了,因为<font color=orange>右括号不是"期待"的</font>
3. 表达式检验结束时,检查<font color=blue>栈是否为空</font>:<br>
&emsp;若栈空,则匹配成功;<br>
&emsp;否则,说明<font color=orange>左括号多了</font>

算法的流程图如下:<br>
![F8](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/BracketsMatchFlowProcessDiagram.png)<br>

<font color=pink>**代码实现参照LinkedStackBrackets项目**</font>

相关主要代码
-------

```c
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
```

栈和递归:聪明的学生
---------
&emsp;递归是程序设计中的一个强有力的工具
* 很多数学函数是递归定义的
* 有的数据结构,如二叉树,广义表等,由于结构本身固有的递归特性,使得它们的操作可递归地描述
* 有些问题,虽然问题本身没有明显的递归结构,但用递归求解比迭代求解更简单,如背包问题,汉诺塔问题,八皇后问题等.

下面先看一个求n的阶乘的例子:<br>
```c
//求n的阶乘的非尾部递归
int factorial(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 1;
	else
		return(n*factorial(n-1));//递归调用
};
//假如输入n=5,那么会有以下的调用行为
//1--首先n=5,返回n*factorial(n-1),即5*factorial(4)
//接下来进行factorial(4)
//2--n=4,则返回4*factorial(3)
//以此类推
//3--n=3,返回3*factorial(2)
//4--n=2,返回2*factorial(1)
//此时n=1,则factorial(1)走的是if(n==1)这一个判断
//5--返回1
//最后调用的factorial(1)先返回,以此类推,类似于栈的"后进先出"
//这样把式子连起来,就是5*4*3*2*1,即5的阶乘
```
* 即函数自己调用自己称为递归调用
* 递归可以分为直接调用和间接调用
* 递归是一种思维方式,如果熟悉了这种思维方式,有些无从下手的问题会得到事半功倍的效果

[补充]阶乘的例子可以使用循环和顺序栈这样做<br>
```c
//阶乘函数
int Factorial_NR(int n)
{
	int res = 1;//定义临时变量并初始化,用于返回result
	//初始化顺序栈,n为最大元素数,也是阶乘的最大数
	LinkedStack sstack;
	sstack = SetNullStack_link(n);
	//阶乘数依次入栈
	while(n>0)
	{
		Push_link(sstack,n);
		n = n-1;
	}//当n=0时,结束入栈
	//栈非空,开始出栈操作
	while(!IsNullStack_link(sstack))
	{
		//类似于递归的操作
		res = res*Top_link(sstack);//栈顶元素出栈并乘以之前的结果,实现阶乘
		//每取一个栈顶元素就输出一次
		printf("当前栈顶元素是:%d\n",Top_link(sstack));
		Pop_link(sstack);//取完栈顶元素就出栈
	}
	//返回阶乘的结果
	return(res);
}
```
>对比可见使用递归的操作与循环的操作的不同,在阶乘这个问题上,明显递归的操作要更简洁

回顾函数调用的过程从而更好地理解递归
----------
* 函数调用:
调用前<br>
<1> 将所有的实参,返回地址传递给被调用函数保存<br>
<2> 为被调用函数的局部变量分配存储区<br>
<3> 将控制转移到被调用函数入口<br>
调用后<br>
<1> 保存被调用函数的计算结果<br>
<2> 释放被调用函数的数据区<br>
<3> 依照被调用函数保存的返回地址将控制转移到调用函数<br>

* 多个函数嵌套调用时,按照"<font color=orange>**后调用先返回**</font>"的原则进行
>后调用先返回即类似后进先出的行为
* 内存管理实行"<font color=orange>**栈式管理**</font>"
* <font color=orange>**运行栈**</font>:运行时动态分配的空间

&emsp;每次调用函数都会有一个<font color=red>活动记录[Active Record]</font>(或者叫<font color=red>堆栈帧[Stack Frame]</font>)<br>
>活动记录的作用是保存一个函数调用所需要维护的各项信息

![F9](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/ActiveRecordWithStack.png)<br>

递归分类
--------
1. 尾部递归

<font color=red>**[注意]十分不推荐使用这种递归方式**</font><br>
>这样的递归完全可以通过一个循环实现
```c(fake)
void tail(int i)
{
	if( i>0 )
		printf( "%d\n", i);
	tail( i - 1);//调用放在整个函数的最后
}
```

2. 非尾部递归
```c(fake)
//如果输入abc,返回的则是cba
void NonTail()
{
	char ch;
	ch = getchar();
	if(ch != '\n')
	{
		NonTail();//递归并不在主函数体最后
		output(ch);
	}
}
```

3. 非尾部递归的非递归实现
```c(fake)
//使用栈实现非尾部递归
void NonRecursive()
{
	char ch;
	ch = getchar();
	//依次入栈的循环
	while(ch != '\n')
	{
		push(st,ch);//st是一个栈
		ch = getchar();
	}
	//依次出栈的循环
	while(!IsEmpty(st))
	{
		output(top(st));//输出提取到的栈顶元素
		pop(st);//出栈
	}
}
```

"聪明的学生"
--------
[BackGround]一位逻辑学的教授有三个<font color=red>非常聪明善于推理且精于心算</font>的学生,一天教授出了一道题:<br>
&emsp;&emsp;教授在每个人脑门上贴了一个纸条,每个纸条上写了一个<font color=orange>正整数</font>.<br>
&emsp;教授告诉学生:"你们脑门上的数字中,<font color=orange>两个数的和等于第三个</font>.规则是:每个人<font color=orange>只能看见另外两个人头上的正整数</font>,但是<font color=red>没法看自己的</font>."<br>
&emsp;&emsp;[比如]A学生:3&emsp;&emsp;B学生:5&emsp;&emsp;C学生:8<br>
&emsp;然后教授分别问学生自己的数字,A:我不知道,B和C给出了相同的回答,但是在若干次之后,C学生准确地报出了自己的数字.<br>

[递归过程]<br>
&emsp;&emsp;首先,要想得出结论,至少要把三个人都问完才可以<br>
1. 假设是3,5,8,那么第六次问C的时候,C判断自己是5-3=2或者5+3=8,如果C是2的话,就会转化为3,5,2的问题,
>B应该在第五次答对,但是B没有答对,所以C应该能在这一次正确判断自己不是2,从而回答出自己是8

2. 假设是3,5,2,那么第五次问B的时候,B判断自己是3-2=1或者3+2=5,如果B是1的话,就会转化为3,1,2的问题,
>A应该在第四次答对,但是A没有答对,所以B应该能在这一次正确判断自己不是1,从而回答出自己是5

3. 假设是3,1,2,那么第四次问A的时候,A判断自己是2-1=1或者1+2=3,如果A是1的话,就会转化为1,1,2的问题,
>C应该在第三次答对,但是C没有答对,所以A应该能在这一次正确判断自己不是1,从而回答出自己是3

4. 假设是1,1,2,那么第三次问C的时候,C判断自己是1-1=0或者1+1=2,
<font color=red>因为0不是正整数,所以C应该能在教授第三次提问时正确回答出自己是2</font>

[!!!]注意观察每次问题,每次问题中应该答对的人,他头上的数字刚刚好就是另外两个人头上数字的和.<br>

上面这个问题可以抽象为以下内容:<br>
&emsp;&emsp;已知三个人的正整数,教授在第几次提问时,轮到回答问题的那个人猜出了自己头上的数?<br>
>[注]总是贴着最大数的那个人猜出自己头上的数
不妨<font color=green>假设</font><font color=red>第三个人的数最大</font><br>
[定义函数]times(i,j,t<sub>1</sub>,t<sub>2</sub>,t<sub>3</sub>)
* i表示t<sub>1</sub>的人头上的数为i
* j表示t<sub>2</sub>的人头上的数为j
* 则编号为t<sub>3</sub>的人头上的数为i+j
* 返回由t<sub>3</sub>猜出自己的数时教授需要提问的次数

[递归关系]
当t<sub>1</sub>,t<sub>2</sub>,t<sub>3</sub>头上的数字定死的那一刻,其实就已经确定了轮数了,那么我们不妨就在此直接设t<sub>3</sub>的人头上的数为最大的.<br>
那么t<sub>3</sub>判断出自己数字的依据就是自己头上的数!=|i-j|<br>
这样就确定了一次i+j,将其替换原来的i+j,就形成了一个新的i,j,i+j<br>
如此递归即可求知解.<br>
```c++
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
	//ab谁前谁后无所谓，只要找到正确的最大值和ab正确坐标即可
	result = times(arr[a - 1], arr[b - 1], a, b, c);
	//得到结果
	printf("第%d位学生", c);
	printf("在第%d次提问时回答正确\n", result);
	return 0;
}
```

这个问题是一个典型的BZOJ(八中Online Judgement)的问题[题号2523],原题的描述如下<br>
>[Discription]<br>
一位教授逻辑学的教授有三名非常善于推理且精于心算的学生A，B和C。有一天,教授给他们三人出了一道题：教授在每个人脑门上贴了一张纸条并告诉他们，每个人的纸条上都写了一个正整数，且某两个数的和等于第三个。于是，每个学生都能看见贴在另外两个同学头上的整数，但却看不见自己的数。<br>
>这时，教授先对学生A发问了：“你能猜出自己的数吗？”A回答:“不能.” <br>
教授又转身问学生B：“你能猜出自己的数吗？”B想了想,也回答:“不能.” <br>
教授再问学生C同样的问题，C思考了片刻后，摇了摇头：“不能”.<br>
接着，教授又重新问A同样的问题，再问B和C，……，经过若干轮的提问之后，当教授再次询问某人时，此人突然露出了得意的笑容，把贴在自己头上的那个数准确无误的报了出来。<br>
<br>
现在，如果告诉你：教授在第N次提问时，轮到回答问题的那个人猜出了贴在自己头上的数是M，你能推断出另外两个学生的头上贴的是什么数吗？<br>
<br>
>[提示] <br>
在没有人猜出自己头上的数之前，大家对教授提问的回答始终都是“不能”；而且除此之外在A，B，C之间是没有进行任何信息交流的。也就是说，每个人推断的依据仅仅是另外两个人的头上数，以及大家对教授的提问所做出的否定回答.<br>
教授总是从学生A开始提问的.<br>
你可以假定，这三个足够聪明的学生能够根据已知的条件在最早的轮次猜出自己的数，并且永远都不会猜错.<br>
稍经分析和推理，你将得出以下结论：总是头上贴着最大的那个数的人最先猜出自己头上的数<br>


[思考]Koch雪花问题的递归实现
------------
&emsp;&emsp;科赫曲线(Koch curve)是一种典型的分形(fractal)曲线,其简单的构造方法为:<br>
&emsp;给定一直线线段，把它等分三段，加入一个等边三角形，以三段的中间一段为底对齐，再去除该段线段。然后，对每个新线段重复进行上述步骤，就能形成科赫曲线:<br>
![F10](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/KochCurveEx1.png)<br>
&emsp;如果画3条科赫曲线，每次旋转120<sup>o</sup>，就能得到科赫雪花:<br>
![F11](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/KochCurveEx2.png)<br>

<font color=brown>[算法思路]</font><br>
&emsp;可以用/,\,_, ,来画出这个图形,也就是说,写出程序,获得以下的结果<br>
```c(fake)
//n=0
__
//n=1
__/\__
//n=2
	  __/\__
      \    /
__/\__/    \__/\__

//当n=3时,情况会有些不同,例如下面标记的,需要在适当的位置画出下划线和斜线
				       __/\__
			           \    /
			     __/\__/    \__/\__
				 \		          /
		  这里 -> /__		    __\ <- 这里
			   		 \		   /
       __/\__      __/		   \__      __/\__
       \    /      \		     /	    \    /
 __/\__/    \__/\__/		     \__/\__/    \__/\__
//这种地方可以选择只画出/_或者\_
```
&emsp;首先建立一个字符数组作为画布,用于存储绘画的中间结果,最后我们再把数组打印出来即可,空白的地方刚刚好就能用到" "(空格)这个字符,画布的大小即数组的大小,是w*h(宽*高)<br>
&emsp;设直角坐标系为x(→),y(↓),例如:画笔从(x,y)处往右画,即是image[y*w + x]="_",然后x++<br>
&emsp;对于输出的字符,我们定义六个方向,0代表向右,1代表右上,2代表左上(注意使用转义字符\\),3代表向左,4代表右上,5代表右下(注意使用转义字符\\)<br>
>注意的是,在需要输出"__"的时候使用的是两个"_",即0和3时使用

&emsp;使用递归完成这一操作,<br>
每次调用KochCurve(n,dir)函数,表示我们要从当前位置(x,y)向dir方向绘画一条n阶科赫曲线.<br>
那么要画一条n阶科赫曲线,其实就只需要根据所需方向画4条n-1阶科赫曲线.<br>
[比如]:若n=2,然后要向右画,即dir=0,那么就要先画一条"__",然后画一个"/",再画一个"\",再画一个"__"<br>
也就是<br>
```c
KochCurve(1, 0);	//KochCurve(n - 1, dir);
KochCurve(1, 1);	//KochCurve(n - 1, dir + 1);
KochCurve(1, 5);	//KochCurve(n - 1, dir + 5);
KochCurve(1, 0);	//KochCurve(n - 1, dir);
```
直到n=0,一条0阶科赫曲线就是一条直线<br>

>>具体项目参照Recurrence_KochCurve项目
>>项目借鉴了Milo Yip大佬的教程https://zhuanlan.zhihu.com/p/24688522

[注]项目中的一些特别函数:<br>
<1> memset函数,首先它是对字节为单位赋值的.<br>
例如:void *memset(void *s, int ch, size_t n);<br>
//将s中前n个字节(typedef unsigned int size_t)用ch替换并返回s<br>
//其实这里面的ch就是ascii为ch的字符；<br>
即:memset的作用是在一段内存块中填充某个给定的值,它是对较大的结构体或数组进行清零操作的一种最快方法<br>

迷宫问题
-------
&emsp;例如有下图这样一个迷宫,如何找到一条从入口到出口的路径呢?<br>
![F12](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/MazeGraph1.png)<br>
<font color=brown>[方法]</font><font color=red>广度优先策略</font>和<font color=red>深度优先策略</font><br>
&emsp;假设在一个格子中,有八个方向的选择<br>
&emsp;每个方向坐标和原坐标位置关系像这样:<br>
↖(x-1,y-1)&emsp;↑(x-1,y)&emsp;↗(x-1,y+1)<br>
←(x,y-1)&emsp;&emsp;&nbsp;A(x,y)&emsp;&emsp;→(x,y+1)<br>
↙(x+1,y-1)&emsp;↓(x+1,y)&emsp;↘(x+1,y+1)<br>
//按顺时针对每个方向进行编号,从小到大进行选择前进,以此类推,从而类穷举找到出口<br>
&emsp;[Eg]从入口开始,有两个方向的选择,选择好了之后开始前进,当不能前进并且不是出口的时候返回,这时就是后走的格子先返回,刚刚好就是类似于栈的"后进先出"原则.<br>
>[So]采用深度优先策略,使用的数据结构就是栈.<br>

迷宫问题中要找到路径并输出需要解决三个问题:<br>
<1> 从某一个坐标点(x,y)出发如何搜索其相邻位置(g,h)?<br>
&emsp;不妨假设8个方向的顺序是从<font color=red>正东开始按顺时针</font><br>
>建立一个数组,表示方向,例如东边(→)就是(x,y+1),增量为{0,1}<br>

则数组为:<br>
&emsp;direction[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}}<br>

相邻位置(g,h)相对于当前位置(x,y)的增量.即:<br>
&emsp;g = x + direction[i][j]<br>
&emsp;h = y + direction[i][j]<br>
假设从当前位置(3,5)向南出发,则:<br>
&emsp;g = x + direction[2][0] = 3 + 1 = 4<br>
&emsp;h = y + direction[2][1] = 5 + 0 = 5<br>

<2> 如何记录探索过的路径?<br>
&emsp;&emsp;采用<font color=green>回溯方法</font>,因此,设计一个栈来存放探索过的路径,当不能向前继续探索时,从栈中回弹出元素.可以<font color=red>使用两个栈LinkedStackX和LinkedStackY分别存放行坐标和列坐标</font>.<br>

<3> 如何防止重复探索某位置<br>
&emsp;&emsp;通过设置标志来识别,初始时各个位置的标识为<font color=green>mark[i][j]=0</font>,当探索到某位置之后设置<font color=green>mark[i][j]=1</font>.<br>

<font color=brown>[算法思路]:</font><br>
&emsp;首先创建两个用于保存横纵坐标的栈StackX和StackY<br>
&emsp;将入口坐标entryX和entryY分别压入栈StackX和StackY中<br>
&emsp;while(栈不空)<br>
&emsp;&emsp;&emsp;取栈顶元素,出栈.当前位置为栈顶元素.<br>
&emsp;&emsp;&emsp;while(mov < 8)判断方向,小于8表示在0~7中选,一个数对应一个方向
&emsp;&emsp;&emsp;即还存在探索的方向<br>
&emsp;&emsp;&emsp;&emsp;&emsp;按照顺时针依次探索各个位置(posX,posY)<br>
&emsp;&emsp;&emsp;&emsp;&emsp;如果(posX,posY)是出口,则输出路径,返回1<br>
&emsp;&emsp;&emsp;&emsp;&emsp;如果(posX,posY)是没有走过的通路,<br>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;设置标志mark[posX][posY] = 1<br>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;当前位置的坐标进栈<br>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;将(posX,posY)设置为当前位置<br>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;设置mov = 0,即从这个位置再探索8个方向<br>
&emsp;&emsp;&emsp;&emsp;&emsp;否则(如果(X,Y)是没有走过的通路),则mov++,即换个方向<br>

**<以下内容在了解队列之后进行>**<br>
如何找到一条从入口到出口的最短路径?<br>
可以使用广度优先搜索策略<br>
即从一个位置出发,将当前可以探索的所有内容都探索完毕,然后再进行下一步探索<br>
在整个过程中,探索的方向同深度优先搜索,每探索一个地方就入队一次,直到找到出口<br>
这样,从出口逆着推,就可以找到一条最短路径<br>

<font color=brown>[算法思路]:</font><br>
&emsp;首先创建两个空队列LinkQueueX和LinkQueueY<br>
&emsp;将入口entryX和entryY分别压入两个队列中<br>
&emsp;while(队列不空)<br>
&emsp;&emsp;取队头元素,出队<br>
&emsp;&emsp;for(mov=0;mov<8;mov++),即还存在可以探索的相邻方向<br>
&emsp;&emsp;&emsp;按照顺时针依次探索各个位置(X,Y)<br>
&emsp;&emsp;&emsp;如果(posX,posY)是没有走过的通路<br>
&emsp;&emsp;&emsp;&emsp;设置标志mark[posX][posY]=1<br>
&emsp;&emsp;&emsp;&emsp;当前位置入队<br>
&emsp;&emsp;&emsp;&emsp;记录前驱位置,方便输出路径<br>

[迷宫问题拓展]<br>
如何最快找到一条从入口到出口的路径呢?<br>
即基于时间效率设定此问题<br>
问题相关的变量有:迷宫的规模,迷宫的形态,迷宫入口和出口的设置等<br>

如何用其他方法找到一条从入口到出口的最短路径呢?<br>
可以使用人工智能方面的算法<br>

>具体实现参照MazeDFS项目(该项目mazeutl.c内容未完成,需要补充才能运行)
>就是一个二维数组的读入和输出的过程
>>主要未完成原因在于:结构体内的数组指针无法在函数中初始化

表达式求值
--------
前缀表达式---波兰式(Polish Notation,PN)
>例如中缀表达式(1+(2*3))可以写为前缀表达式(+1(*2 3))---在SCHEME语言中只接受前缀表达式

* 例如这个就是个前缀表达式 +* 31 -5 22 70

中缀表达式
>例如31*(5-22)+70

后缀表达式---逆波兰式(Reverse Polish Notation,RPN)
>例如31 5 22 - * 70 +

表达式计算问题---后缀表达式计算
---------
[算法过程]
* 顺序扫描后缀表达式
* &emsp;如果是操作数,则压入栈中
* &emsp;如果是操作符,则从栈中弹出两个操作数进行计算,把结果再压入栈
* 扫描结束时,栈顶元素就是表达式的值

![F13](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/RPNcalculateG1.png)<br>
1. 已知后缀表达式为 31 5 22 - * 70 +
2. 首先是操作数31,直接入栈
3. 操作数5,入栈
4. 操作数22,入栈,此时栈为(栈顶到栈底)22 5 31
5. 操作符'-',取栈中两元素,进行计算,首先取出的元素放符号右边,即5-22=-17,将结果压入栈中
6. 操作符'*',取栈中两元素计算,即31*(-17)=-527,结果压入栈中
7. 操作数70,入栈
8. 操作符'+',取栈中两元素计算,即-527+70=-457,将结果压入栈中
9. 待处理的表达式为空,结束计算

表达式计算问题---中缀表达式转换为后缀表达式
---------
[注]在本例中默认所有的中缀表达式是成立且正确的.<br>
[操作符的优先级]<br>
* 乘除高于加减,()的优先级最低
* 同一优先级的,按照先后规定优先级
* ()里面的是同一层次需要一起计算

[算法过程]<br>
* 从左至右依次扫描中缀表达式
* &emsp;如果是操作数,则直接输出,可见栈中只存放<font color=blue>操作符</font>
* &emsp;如果是"(",则入栈
* &emsp;如果是")",则弹出栈顶元素并放入后缀表达式中,反复执行直到栈顶元素为"("时为止,表明这一层括号内的操作处理完毕.
* &emsp;如果是操作符,则将该操作符和操作符栈顶元素比较
* &emsp;&emsp;如果<font color=red>大于</font>栈顶元素的优先级时,则将它压入栈中
* &emsp;&emsp;如果<font color=red>小于</font>栈顶元素的优先级时,则取出栈顶元素放入后缀表达式,并弹出该栈顶元素,反复执行直到栈顶元素的优先级小于当前操作符的优先级.
* 重复上述步骤直到遇到中缀表达式的结束符"#",弹出栈中的所有元素并放入后缀表达式中,算法结束

![F14](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/RPNcalculateG2.png)<br>
1. 扫描中缀表达式为31*(5-22)+70
2. 操作数,直接输出,即31
3. 操作符'*',栈中无其他操作符,入栈
4. 操作符'(',直接入栈
5. 操作数5,直接输出
6. 操作符'-',与栈顶元素'('对比,'('的优先级最低,则'-'入栈
7. 操作数22,直接输出
8. 操作符')',弹出栈顶元素直到'(',括号只出栈不输出,则现在的后缀表达式为31 5 22 -
9. 操作符'+',与栈顶元素'*'对比,'+'的优先级低,则输出栈顶元素'*','+'入栈
10. 操作数70,直接输出
11. 结束符'#',依次弹出栈元素,转换结束,获得后缀表达式31 5 22 - * 70 +

*******************************************************
>以下为队列相关内容

循环队列
======
队列和栈不同,队列是先进先出,后进后出<br>

队列的顺序表示---假溢出
---------
&emsp;&emsp;下图解释了假溢出,其中enQueue(queue,elem)为入队函数,deQueue(queue,elem)为出队函数<br>
![F15](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/QueueFackOverFlowG1.png)<br>
&emsp;&emsp;假如队列就是一个8空间长度,按图中的内容可见当压入40之后,想要再压入元素,就会有溢出错误,而前两位因为出队了两个数5和10明明有地方,但却无法入队,这样的情况就叫假溢出.<br>
<br>
<font color=red>假上溢</font>:当前队列并不满,但不能入队<br>
&emsp;[原因]&emsp;被删除元素的空间没有再被使用<br>
[解决方式]使用环形队列(循环队列)<br>
![F16](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/CircleQueueG1.png)<br>

* 环形队列的头尾指针开始都指向0位置,之后每进一个数,在添加的同时尾指针会向后移动一位
* 出队时,头指针所指内容出队,之后头指针后移一位
* 循环,不断入队,当插入到7这个位置的时候,假设0和1的位置元素已被出队,即空间为空,此时尾指针会后移一位,即移到8,但是尾指针会直接指向0而不是提示溢出错误
* 当尾指针和头指针再次重合时,即队列的的确确满了

[循环队列的思路]<br>
<font color=red>入队</font>:<br>
```c(fake)
//r表示尾指针,paqu表示队列,MAXNUM表示队列最大空间
if(paqu->r = MAXNUM)
{
	paqu->r = 0;
}
else
{
	paqu->r ++;
}
```

<font color=red>利用模运算</font>使位置大于容量时自动移至归零位:<br>
```c(fake)
paqu->r = (paqu->r+1) % MAXNUM
paqu->r = (paqu->r+1) mod MAXNUM
```

<font color=red>出队</font>:<br>
```c(fake)
//f表示头指针
//和尾指针一样,指向大于空间的内容时自动归零
paqu->f = (paqu->f+1) % MAXNUM
```

[思考]如何判断队列的空和满呢?<br>
空和满的条件都是头指针和尾指针重合,即<br>
&emsp;&emsp;某一元素出队后,若头指针已从后面追上尾指针,则当前队列为空:<br>
<code>paqu->r == paqu->f</code><br>
&emsp;&emsp;某一元素入队后,若尾指针已从后面追上头指针,则当前队列为满:<br>
<code>paqu->r == paqu->f</code><br>

<font color=red>判断队空的条件:</font><br>
<code>paqu->r == paqu->f</code><br>
<font color=red>判断队满的条件:</font><br>
<font color=blue>当尾指针 + 1 == 头指针的时候</font>,判断队列为满,此时仅仅是浪费了一个空间,但达成了判断队列空满的结果<br>

<code>(paqu->r + 1) % MAXNUM == paqu->f</code>

>循环队列的相关程序设计和代码见SeqQueue项目

链队列
========
首先定义结点以及队列的结构体,即结点包括数据域和指针域,队列里有头结点和尾结点
```c
typedef int DataType;
struct Node
{
	DataType data;
	struct Node *link;
};
typedef struct Node *PNode;
struct Queue
{
	PNode f;
	PNode r;
};
typedef struct Queue *LinkQueue;
```

创建空队列
--------
```c
//创建一个空队列
LinkQueue SetNullQueue_Link()
{
	LinkQueue lqueue;
	lqueue = (LinkQueue)malloc(sizeof(struct Queue));
	if(lqueue != NULL)
	{
		lqueue->f = NULL;
		lqueue->r = NULL;
	}
	else
	{
		printf("Alloc failure!\n");
	}
	return lqueue;
}
```

判断队列是否为空
-----------
```c
//判断队列是否为空
int IsNullQueue_Link(LinkQueue lqueue)
{
	return(lqueue->f == NULL);
}
```

入队
--------
一个新结点要入队,在队的结尾进行该操作,此时原队尾结点的指针域指向新结点,队列的尾指针指向新结点.
算法实现时有特殊情况,即空队列在插入结点时,头尾指针都需要指向新插入的结点.
```c
//入队操作
void EnQueue_Link(LinkQueue lqueue,DataType x)
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node));//申请结点空间
	if(p == NULL)
	{
		printf("Alloc failure!\n");
	}
	else
	{
		p->data = x;	//数据域赋值
		p->link = NULL;	//指针域赋值
		//如果是空队列,则特殊处理
		if(lqueue->f == NULL)
		{
			lqueue->f = p;
			lqueue->r = p;
		}
		else
		{
			lqueue->r->link = p;	//新结点插入队尾
			lqueue->r = p;			//修改队尾指针
		}
	}
}
```

出队
----------
一个结点要出队,在队列的队头进行操作,首先确定要删除的结点,并用一个p指针指向它,之后头结点指向原队列的第二个结点,释放p即可.
```c
//出队操作
void DeQueue_Link(LinkQueue lqueue)
{
	struct Node *p;
	//对于空队列的报错提示
	if(lqueue->f == NULL)
	{
		printf("It is already an empty queue!\n");
	}
	else
	{
		p = lqueue->f;		//p指向队头结点,用于释放
		lqueue->f = lqueue->f->link;	//修改队头指针
		free(p);			//释放结点空间
	}
}
```

队列的应用--农夫过河问题
---------
<font color=green>[背景]</font>农夫带着自己的狼,菜和羊,要过到河对岸去<br>
<font color=orange>[要求]</font><br>
船只能装两个东西,即农夫只能一个人或者带一个物品坐船<br>
另外,农夫必须和物品在同一岸才能带走<br>
狼会吃羊,羊会吃菜<br>
<font color=blue>[思考]</font>如何用队列解决这个问题呢?<br>
不可能的状态:两个物品不在同一岸<br>
不安全的状态,狼会吃羊,羊会吃菜,不能共存<br>
处理过的状态,记录处理过的状态,保证最后输出<br>

假设初始为在南岸,四个物品都在,即0000<br>
那么终止为在北岸,四个物品都到,即1111<br>
解决问题的答案只有一种,如图:<br>
![F17](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/FarmerPassRiverG1.png)<br>
这里的问题是,狼会吃羊,羊会吃菜,应该怎么做呢<br>
首先,农夫必定要先带羊走,即1001,以此类推,从而有了上图<br>
[<font color=red>注意</font>]<br>
图中第5列的0111状态是错误的,因为这个状态中狼菜羊共存,而农夫不见了,类似的状态还有很多<br>

>注:0000的意思是:农夫,狼,菜,羊在南岸(值为0)

那么最终的判断路径为:
![F18](https://github.com/CyberYui/DataStructures/blob/master/C/StackAndQueue/FarmerPassRiverG2.png)<br>
>图中绿色表示不可能,不安全,或者处理过的状态<br>
>紫色表示到达北岸经过的中间状态

>>上例中如何使用队列呢?

[解决思路]用队列实现广度搜索策略
每次针对一个初始的状态都将其四种可能状态入队,并对这四个状态进行状态分析,将不可行的状态不管,将可行的状态入队,以此类推.
此外,需要通过一个数组status来实现中间状态的记录

<font color=brown>[算法思路]:</font><br>
&emsp;初始状态0000入队<br>
&emsp;当队列不空且没有到达结束状态1111时,循环以下操作:<br>
&emsp;&emsp;队头状态出队<br>
&emsp;&emsp;按照农夫一个人走,农夫分别带上一件物品走,循环以下操作:<br>
&emsp;&emsp;&emsp;农夫和物品如果在同一岸,则计算新的状态<br>
&emsp;&emsp;&emsp;如果新状态时安全的并且时没有处理过的,则更新状态数组,并将新状态入队<br>
&emsp;当状态为1111时,逆向输出状态数组<br>

>项目略

补充:两种特殊的队列
==========
双端队列(double-ended queue,deque)
--------
具有队列和栈的性质,即可以在头部和尾部进行插入和删除元素的数据结构<br>

优先队列(priority queue)
--------
根据元素的优先级和在队列中的位置决定出队的先后次序<br>

>这两种数据结构都在标准模版库中有相应实现(标准模版库STL:Standard Template Library)

双端队列的应用--滑动最小值
--------
[问题描述]
给定一个长度为n的数列a<sub>0</sub>,a<sub>1</sub>,a<sub>2</sub>,...,a<sub>n-1</sub>和一个整数k<br>
求数列b<sub>i</sub>=min{a<sub>i</sub>,a<sub>i+1</sub>,a<sub>i+2</sub>,...,a<sub>i+k-1</sub>}<br>
限制条件:1<=k<=n<=10<sup>6</sup>&emsp;&emsp;0<=a<sub>i</sub><=10<sup>9</sup><br>
输入:n=5,k=3,a={1,3,5,4,2}<br>
//k=3,即每3个数比较,(1,3,5)中1最小,(3,5,4)中3最小,(5,4,2)中2最小<br>
输出:b={1,3,2}<br>

>说明:可以使用STL中的双端队列容器

[分析]<br>
双端队列开始为空,队列中存放数组a的下标,然后通过维护双端队列得到最小值.<br>
(1)把0到k-1依次加入队列.加入i时,当双端队列的末尾的值j满足a<sub>j</sub>>=a<sub>i</sub>,则不断从末尾取出,直到双端队列为空或者a<sub>j</sub><a<sub>i</sub>,之后在末尾加入i.<br>
(2)当k-1都加入双端队列之后,查看双端队列头部的值j,那么b<sub>0</sub>=a<sub>j</sub>,如果j=0,由于之后的计算中不再需要,因而从头部删除.<br>
(3)继续计算b<sub>i</sub>,在双端队列的末尾加入k,进入(1)重复执行.<br>

>即每次都进行判断然后入队<br>
>当队尾元素比将入队元素大时,大的元素出队,然后继续判断<br>
>当队尾元素比将入队元素小时,将入队元素入队,然后小的元素出队<br>
>以此类推,完成问题<br>
