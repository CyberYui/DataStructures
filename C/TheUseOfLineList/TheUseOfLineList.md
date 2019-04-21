线性表的应用
==========
一元多项式的加法:
------------
&emsp;&emsp;在数学上,一个一元多项式P<sub>n</sub>(x)可<font color=blue>按升幂</font>写成:<br>
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/TheUseOfLineList/PolynomialAddition/polymerizationF1.png)<br>
&emsp;&emsp;它由n+1个系数唯一确定<br>

&emsp;&emsp;可以用一个线性表P来表示多项式:<br>
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/TheUseOfLineList/PolynomialAddition/polymerizationF2.png)<br>
&emsp;&emsp;每一项的指数i隐含在其系数p<sub>i</sub>的序号中<br>

1. 全部系数顺序存储结构
* 优点:多项式相加的算法定义十分简洁
* 缺点:对一些特别的多项式会造成浪费空间的效果<br>
    如<font color=red>S(x)=1+3x<sup>10000</sup>+2x<sup>20000</sup></font><br>
    这样的多项式就需要一个长度为20001的线性表来表示,但其中非0元素只有三个而已<br>

2. 非零系数顺序存储结构,必须同时存储相应的指数
* P<sub>n</sub>(x)=p<sub>1</sub>x<sup>e<sub>1</sub></sup>+p<sub>2</sub>x<sup>e<sub>2</sub></sup>+...+p<sub>n</sub>x<sup>e<sub>m</sub></sup><br>
    p<sub>i</sub>是指数为e<sub>i</sub>的项的非0系数,且满足<br>
    <font color=green>0<=e<sub>1</sub><e<sub>2</sub><...<e<sub>m</sub>=n</font><br>
    线性表中的数据项有两个数据元素:系数和指数:<br>
    {(p<sub>1</sub>,e<sub>1</sub>),(p<sub>2</sub>,e<sub>2</sub>),...,(p<sub>m</sub>,e<sub>m</sub>)}<br>

&emsp;&emsp;在<font color=red>最坏情况</font>下,n+1(=m)个系数都不为0,则比只存储每项系数的方案要多存储一倍的数据,但对于特别的多项式则会大大节省空间.<br>

3. 非零系数单链表存储结构
* [<font color=purple>Star</font>]若只对多项式进行"<font color=red>求值</font>"等不改变多项式的系数和指数的运算,则采用<font color=red>顺序存储结构</font>即可;<font color=red>否则应采用链表表示</font>.<br>
&emsp;&emsp;结点包括3部分:系数+指数+指针域<br>
例如这两个多项式:<br>
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/TheUseOfLineList/PolynomialAddition/polymerizationF3.png)<br>

如何实现用有序链表表示的多项式的加法运算?
-------------
&emsp;&emsp;根据一元多项式相加的运算规则:
* 对于两个一元多项式中所有指数相同的项,对应系数相加;
* 若其和不为0,则构成和"多项式"中的一项;
* 对于两个一元多项式中所有指数不同的项,则分别复制到"和多项式"中去;

在有序链表中,就可以按这样的三步进行<br>
如下图,有两个指针,一个指向pa多项式链表,另一个指向pb多项式链表<br>
![F4](https://github.com/CyberYui/DataStructures/blob/master/C/TheUseOfLineList/PolynomialAddition/polymerizationF4.png)<br>
将pa多项式作为"和多项式"<br>

```c
//首先摘去第二个链表头结点,便于两表相连
//exponent n. 指数
(1)pa->exponent < pb->exponent;//对比两个结点的指数,若不同,则把小的先放到和多项式链表中
(2)pa->exponent == pb->exponent;//指数相同,则系数相加coefficient n.系数
   pa->coefficient + pb->coefficient;
   //这样得到的结果,如果不为0,则修改*pa的系数,然后释放*pb;
   //若为0,则删除*pa和*pb的系数,并释放两个结点;
(3)pa->exponent > pb->exponent;//对比两个结点的指数,若不同,则把小的先放到和多项式链表中
   //在这里,需要有前驱结点的指针域变化,应放入考虑范围内
```

[注]在进行时,pa后移,则其前面的部分链表就是"和多项式",其后的就是pa多项式
    最后,当*pa和*pb指向NULL时,算法结束<br>

相关算法框架:
----------
主要涉及到的主要算法:<br>
1. 建立多项式,并对输入的多项式进行升幂排序
2. 输出输入的多项式
3. 多项式的加法算法

```c
//多项式的加法
void AddPolyn(linklist *pa,linklist *pb)
{
    int x;//系数临时变量
    //设置跳过两个多项式头结点的指针
    DataType *p=pa->link;
    DataType *q=pb->link;
    while(p!-NULL && q!=NULL)
    {
        //没有空链表,开始对比指数
        if(p->exp == q->exp)
        {
            //系数相加
            x = p->coef + q->coef;
            if(x == 0)
            {
                //删除p当前结点
                //删除并释放q当前结点
            }
            else
            {
                //修改p当前结点的系数为x
                //p后移
                //删除并释放q的当前节点
                //q后移
            }
        }
        else
        {
            //将q当前结点插入到p中
            //修改p的前驱结点指针域
        }
    }
    //当有一个指针指向NULL时,循环会跳出来
    if(q!=NULL)
    {
        //将q的剩余结点加到和多项式中
    }
    //如果p!=NULL而q=NULL的话,p作为"和多项式",剩余的结点都可以不用动
    else
    {
        //do nothing
    }
}
```
流程图如下:<br>
![F5](https://github.com/CyberYui/DataStructures/blob/master/C/TheUseOfLineList/PolynomialAddition/polymerizationF5.png)<br>
