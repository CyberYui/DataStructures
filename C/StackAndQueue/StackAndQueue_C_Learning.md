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