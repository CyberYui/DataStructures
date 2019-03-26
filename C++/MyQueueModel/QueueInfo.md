此目录的文件皆关于一种独特的数据结构-----环形队列
===========================
目录包含14个文件,一共四组
------------------------
* 第一组:PracticeQueue.cpp+MyQueue.h

        这两个文件是环形队列关于普通数据类型的模版
        PracticeQueue.cpp
        内容:
        包含主函数,以及两个不同数据类型的例子

        MyQueue.h
        内容:
        包含模版类及模版函数,以及一些简短的注释说明

* 第二组:PracticeDemo.cpp<br>
　　　　MyQueueBasic.cpp+MyQueueBasic.h

        这三个文件是环形队列关于整数类型int的例子,并不是模版类
        PracticeDemo.cpp
        内容:
        包含主函数,主函数中包括了一些简单的命令代码用于测试

        MyQueueBasic.h
        内容:
        环形队列相关函数的声明,
        简要介绍了函数声明的原因和在C语言中的对应声明方式

        MyQueueBasic.cpp
        内容:
        对MyQueueBasic.h文件中声明的各项函数的具体实现,
        添加了很多注释以表明函数体的编写代码原因

* 第三组:PracticeAdv.cpp<br>
　　　　CustomerBasic.cpp＋CustomerBasic.h<br>
　　　　MyQueueAdv.cpp+MyQueueAdv.h

        这五个文件是环形队列关于存储非普通数据类型的例子,并不是模版类
        PracticeAdv.cpp
        内容:
        包含主函数,主函数中包括了一些简单的命令代码用于测试

        CustomerBasic.h
        内容:
        Customer类的声明以及相关成员函数的声明

        CustomerBasic.cpp
        内容:
        CustomerBasic.h中Customer类的成员函数实现,这只是一个简单的类

        MyQueueAdv.h
        内容:
        环形队列相关函数的声明,并简要介绍了函数声明的原因,
        由于是基于MyQueueBasic.h建立的文件,所以会包含一些MyQueueBasic.h文件的内容

        MyQueueAdv.cpp
        内容:
        关于MyQueueAdv.h文件中的函数实现,添加了很多注释以表明函数体的编写代码原因

* 第四组:QueueModelDemo.cpp<br>
　　　　CustomerTest.h+CustomerTest.cpp<br>
　　　　MyQueueModel.h

        这四个文件是环形队列的模版类的例子
        QueueModelDemo.cpp
        内容:
        整个模版类的测试例子,配有简短的注释

        CustomerTest.h
        内容:
        用于测试的用户头文件,包括对成员函数和数据成员的声明
        [注]有关于输出运算符重载的声明

        CustomerTest.cpp
        内容:
        用于实现CustomerTest.h的内容,简单的逻辑

        MyQueueModel.h
        内容:
        在MyQueueAdv.h的基础上进行内容修改,使其成为模版类
        由于模版类要求.h和.cpp文件整合,故没有相关的.cpp文件
        内容的具体实现详见代码,逻辑与MyQueueAdv.h基本没有区别


[PS]关于队列的知识:<br>
　　队列是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，而在表的后端（rear/tail）进行插入操作，和栈一样，队列是一种操作受限制的线性表。<br>
　　进行插入操作的端称为队尾，进行删除操作的端称为队头。队列中没有元素时，称为空队列。<br>
　　队列的数据元素又称为队列元素。在队列中插入一个队列元素称为入队，从队列中删除一个队列元素称为出队。因为队列只允许在一端插入，在另一端删除，所以只有最早进入队列的元素才能最先从队列中删除，故队列又称为先进先出（FIFO—first in first out）线性表。

>本文件编写完成于2019-03-09-20:15