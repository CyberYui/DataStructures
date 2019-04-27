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

