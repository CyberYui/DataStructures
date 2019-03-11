此目录的文件皆关于一种独特的数据结构-----栈
===========================
目录包含五组共计16个文件
------------------------
* 第一组:PracticeStack.cpp<br>
　　　　MyStackBasic.cpp+MyStackBasic.h

        这三个文件是栈关于普通数据类型char类型的例子,并不是模版类
        PracticeStack.cpp
        内容:
        包含主函数,以及char数据类型的例子

        MyStackBasic.h
        内容:
        包含栈类及相关成员函数的声明,以及一些注释说明

        MyStackBasic.cpp
        内容:
        包含栈类及相关成员函数,以及一些注释说明

* 第二组:PracticeAdv.cpp<br>
　　　　MyStackAdv.cpp+MyStackAdv.h<br>
　　　　CoordinateAdv.cpp+CoordinateAdv.h

        这五个文件是栈关于Coordinate类型的例子,并不是模版类
        PracticeAdv.cpp
        内容:
        包含主函数,
        主函数中包括了一些简单的命令代码用于测试

        MyStackAdv.h
        内容:
        栈相关函数的声明,
        简要介绍了函数声明的原因,
        对比与第一组中MyStackBasic.h的声明区别,
        并简要阐述了理由

        MyStackAdv.cpp
        内容:
        对MyStackAdv.h文件中声明的各项函数的具体实现,
        添加了很多注释以表明函数体的编写代码原因

        CoordinateAdv.h
        内容:
        对于Coordinate类及相关成员函数的声明,
        添加了一些简单的注释解释

        CoordinateAdv.cpp
        内容:
        对于Coordinate类相关函数的实现,
        添加了一些简单的注释解释


* 第三组:StackModelDemo.cpp<br>
　　　　CoordinateModel.cpp＋CoordinateModel.h<br>
　　　　MyStackModel.h

        这四个文件是栈关于各种数据类型的模版类的相关文件
        ([注]:这里用于测试的类Coordinate较为简单)
        StackModelDemo.cpp
        内容:
        包含主函数,主函数中包括了一些简单的命令代码用于测试

        CoordinateModel.h
        内容:
        Coordinate类及相关成员函数的声明,
        添加了一些简单的注释解释

        CoordinateModel.cpp
        内容:
        对于Coordinate类相关函数的实现,
        添加了一些简单的注释解释

        MyStackModel.h
        内容:
        栈模版类及相关内容的实现,包含主要的函数体代码以及大量的注释内容

* 第四组:NSConversionDemo.cpp<br>
　　　　StackNSConversion.h

        这两个文件实现了简单的十进制转二进制,十进制转八进制,十进制转十六进制的功能
        NSConversionDemo.cpp
        内容:
        包含主函数,主函数中包括了一些主要的命令代码用于实现功能,
        并对一个数字进行了必要的测试

        StackNSConversion.h
        内容:
        Stack类及相关成员函数的声明,
        添加了一些简单的注释解释

* 第五组:ParentMatchDemo.cpp<br>
　　　　StackParentMatch.h

        这两个文件实现了对于()[]{}的括号匹配功能
        ParentMatchDemo.cpp
        内容:
        包含主函数,主函数中包括了一些主要的命令代码用于实现功能,
        并对一个括号字符串进行了必要的测试

        StackParentMatch.h
        内容:
        Stack类及相关成员函数的声明,
        添加了一些简单的注释解释

[PS]关于栈的知识:<br>
　　栈（stack）又名堆栈，它是一种运算受限的线性表。其限制是仅允许在表的一端进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。<br>
　　向一个栈插入新元素又称作进栈、入栈或压栈，它是把新元素放到栈顶元素的上面，使之成为新的栈顶元素；从一个栈删除元素又称作出栈或退栈，它是把栈顶元素删除掉，使其相邻的元素成为新的栈顶元素。<br>
　　栈是允许在同一端进行插入和删除操作的特殊线性表。允许进行插入和删除操作的一端称为栈顶(top)，另一端为栈底(bottom)；栈底固定，而栈顶浮动；栈中元素个数为零时称为空栈。插入一般称为进栈（PUSH），删除则称为退栈（POP）。栈也称为后进先出(FILO---First In Last Out)表。

<<<<<<< HEAD
>本文件编写完成于2019-03-10-23:32<br>
>本文件最新修改于2019-03-11-16:21
=======
>本文件编写完成于2019-03-10-23:32
>本文件最新修改于2019-03-11-16:21
>>>>>>> 77f5d071e8e0d0acad7a344a324cc5977712e7ff
