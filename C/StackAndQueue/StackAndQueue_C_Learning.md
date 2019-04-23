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

