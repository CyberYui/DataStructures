搜索树
========
[关键词]动静观和平衡术

有序表---动态调整效率低
二叉排序树---单分支的最坏情况
AVL树(平衡二叉排序树)---近似平衡
红黑树---大致平衡(引入颜色)

二分查找判定树
=========
检索效率:平均检索长度(ASL Average Search Length)
&emsp;&emsp;查找或搜索是指从一组数据元素中找到需要的数据元素.衡量查找效率的主要标准是查找过程中平均比较次数,即平均检索长度ASL,定义:
![F1](https://github.com/CyberYui/DataStructures/blob/master/C/SearchTree/SearchTreeG1.png)<br>
&emsp;其中,n是结点的个数,p<sub>i</sub>是查找第i个结点的概率,若不特别声明,一般认为每个结点的查找概率是相等的,即p<sub>1</sub>=p<sub>2</sub>=...=p<sub>n</sub>=1/n
&emsp;c<sub>i</sub>是查找到第i个结点成功,所需要比较的次数
&emsp;uc<sub>i</sub>是查找到第i个结点失败,所需要比较的次数
![F2](https://github.com/CyberYui/DataStructures/blob/master/C/SearchTree/SearchTreeG2.png)<br>
![F3](https://github.com/CyberYui/DataStructures/blob/master/C/SearchTree/SearchTreeG3.png)<br>

[示例]用二分检索算法求ASL
序列:5&nbsp;13&nbsp;19&nbsp;21&nbsp;37&nbsp;56&nbsp;64&nbsp;75&nbsp;80&nbsp;88&nbsp;92

比较一次就成功的1个;(即56)
