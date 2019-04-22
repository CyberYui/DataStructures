线性表的补充---动态链接库
==========
DLL(Dynamic Link Library) DSO(Dynamic Shared Objects)动态链接库
----------
* 动态链接库(.dll , .ocx 等)
* 动态共享对象(.so )
* 静态链接库(.lib )
* 静态库(.a )

* 文件格式:
* Windows:PE(Protable Executable)
* Linux:ELF(Executable Linkable Format)

可执行文件,目标文件,.dll,.lib,.so,.a<br>

DLL(Dynamic Link Library)
--------
* 首先看看我们的可执行程序依赖了什么

* 通过工具dumpbin.exe进行观察
* <font color=grey>dumpbin.exe是VS自带的工具,VS2017也自带</font>
>路径为:F:\MicrosoftVisualStudio2017\VC\Tools\MSVC\14.16.27023\bin\Hostx64\arm64

[注]由于dumpbin.exe也是需要一些依赖的,所以最好的使用方式是用VS自身的命令行进行使用<br>
>VS2017-->工具(T)-->Visual Studio 命令提示(C)

有两种方式使用:<br>
1. 用命令行打开路径之后再使用,可以用dumpbin /?来测试是否进入了正确的路径
2. 将dumpbin.exe所在目录放入PATH环境变量中就可以直接使用了

对于dumpbin.exe的使用,需要用到以下命令:<br>
* /IMPORTS[:文件名]----查看一个应用程序运行时要导入哪些动态库<br>

例子:比如要看csgo.exe导入了哪些动态库<br>
```cmd
F:\MicrosoftVisualStudio2017\VC\Tools\MSVC\14.16.27023\bin\Hostx64\arm64>dumpbin /imports "I:\Steam\steamapps\common\Counter-Strike Global Offensive\csgo.exe"
Microsoft (R) COFF/PE Dumper Version 14.16.27030.1
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file I:\Steam\steamapps\common\Counter-Strike Global Offensive\csgo.exe

File Type: EXECUTABLE IMAGE

  Section contains the following imports:

    USER32.dll
                454180 Import Address Table
                46F05C Import Name Table
                     0 time date stamp
                     0 Index of first forwarder reference

                  215 MessageBoxW
                  333 wsprintfW

    KERNEL32.dll
                454000 Import Address Table
                46EEDC Import Name Table
                     0 time date stamp
                     0 Index of first forwarder reference

                  459 SetEvent
                  2D4 HeapSize
                  52E WriteProcessMemory
                  4EF VirtualProtect
                   EE EnterCriticalSection
                  1C0 GetCurrentProcess
                  339 LeaveCriticalSection
                  2E2 InitializeCriticalSection
                   9B CreateMutexA
                  4F9 WaitForSingleObject
                  3FA ReleaseMutex
                  273 GetSystemInfo
                  4EA VirtualAllocEx
                   D1 DeleteCriticalSection
                  158 FlushInstructionCache
                  4F1 VirtualQuery
                  139 FindFirstFileW
                  1F1 GetFileSizeEx
                  145 FindNextFileW
                  525 WriteFile
                  214 GetModuleFileNameW
                  12E FindClose
                   8F CreateFileW
                  4D6 UnmapViewOfFile
                  215 GetModuleHandleA
                  15E FormatMessageW
                  202 GetLastError
                   88 CreateFileA
                  33C LoadLibraryA
                   52 CloseHandle
                  245 GetProcAddress
                   89 CreateFileMappingA
                  348 LocalFree
                  357 MapViewOfFile
                  33E LoadLibraryExW
                  3A7 QueryPerformanceCounter
                  3A8 QueryPerformanceFrequency
                  511 WideCharToMultiByte
                  367 MultiByteToWideChar
                   EA EncodePointer
                   CA DecodePointer
                  473 SetLastError
                  2E3 InitializeCriticalSectionAndSpinCount
                   85 CreateEventW
                  4C5 TlsAlloc
                  4C7 TlsGetValue
                  4C8 TlsSetValue
                  4C6 TlsFree
                  279 GetSystemTimeAsFileTime
                  218 GetModuleHandleW
                  32D LCMapStringW
                  269 GetStringTypeW
                  172 GetCPInfo
                  2E7 InitializeSListHead
                  524 WriteConsoleW
                  40F ResetEvent
                  4FA WaitForSingleObjectEx
                  304 IsProcessorFeaturePresent
                  300 IsDebuggerPresent
                  4D3 UnhandledExceptionFilter
                  4A5 SetUnhandledExceptionFilter
                  263 GetStartupInfoW
                  1C1 GetCurrentProcessId
                  1C5 GetCurrentThreadId
                  4C0 TerminateProcess
                  2F1 InterlockedPushEntrySList
                  3B1 RaiseException
                  418 RtlUnwind
                  162 FreeLibrary
                  457 SetEnvironmentVariableW
                  44D SetCurrentDirectoryW
                  1BF GetCurrentDirectoryW
                  2CB HeapAlloc
                  2CF HeapFree
                  2D2 HeapReAlloc
                  119 ExitProcess
                  217 GetModuleHandleExW
                  213 GetModuleFileNameA
                  264 GetStdHandle
                  168 GetACP
                  467 SetFilePointerEx
                  1AC GetConsoleMode
                  1F3 GetFileType
                  24A GetProcessHeap
                  133 FindFirstFileExA
                  143 FindNextFileA
                  30A IsValidCodePage
                  237 GetOEMCP
                  186 GetCommandLineA
                  187 GetCommandLineW
                  1DA GetEnvironmentStringsW
                  161 FreeEnvironmentStringsW
                  487 SetStdHandle
                  157 FlushFileBuffers
                  19A GetConsoleCP

  Summary

        6000 .data
        1000 .gfids
       1C000 .rdata
        6000 .reloc
       A5000 .rsrc
       53000 .text
        1000 .tls
```
可见例子中用到了USER32.dll和KERNEL32.dll两个动态库<br>

* /EXPORTS----查看一个动态库会导出哪些函数

例子:比如要看USER32.dll和KERNEL32.dll两个动态库会导出哪些函数<br>
&emsp;&emsp;首先要知道这两个动态库的位置<br>
&emsp;&emsp;比如KERNEL32.dll位于C:\Windows\System32中<br>
>即dumpbin /exports C:\Windows\System32\kernel32.dll<br>

```cmd
f:\MicrosoftVisualStudio2017\Common7\Tools>dumpbin /exports C:\Windows\System32\kernel32.dll
Microsoft (R) COFF/PE Dumper Version 14.16.27030.1
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file C:\Windows\System32\kernel32.dll

File Type: DLL

  Section contains the following exports for KERNEL32.dll

    00000000 characteristics
    A9E3D878 time date stamp
        0.00 version
           1 ordinal base
        1629 number of functions
        1629 number of names

    ordinal hint RVA      name

          1    0          AcquireSRWLockExclusive (forwarded to NTDLL.RtlAcquireSRWLockExclusive)
          2    1          AcquireSRWLockShared (forwarded to NTDLL.RtlAcquireSRWLockShared)
          3    2 0001E860 ActivateActCtx
          4    3 0001A570 ActivateActCtxWorker
          5    4 00021A70 AddAtomA
          6    5 0000FE30 AddAtomW
          7    6 00022DE0 AddConsoleAliasA
          8    7 00022DF0 AddConsoleAliasW
          9    8          AddDllDirectory (forwarded to api-ms-win-core-libraryloader-l1-1-0.AddDllDirectory)
         10    9 000375B0 AddIntegrityLabelToBoundaryDescriptor
..............(内容过多,略去)
       1627  65A 00033430 uaw_wcsicmp
       1628  65B 00033440 uaw_wcslen
       1629  65C 00033460 uaw_wcsrchr

  Summary

        2000 .data
        6000 .pdata
       32000 .rdata
        1000 .reloc
        1000 .rsrc
       76000 .text
```
可见会显示出dll文件中的所有函数的函数名,比如本台电脑上的kernel32.dll有1629个函数<br>

Windows与DLL
---------
&emsp;&emsp;Windows系统中大量采用了DLL机制,甚至windows内核结构在很大程度上都依赖DLL机制.<br>

&emsp;&emsp;Windows平台上大型软件的升级是通过DLL实现的.比如Office,IE,VS系列等.<br>

&emsp;&emsp;Service Packs软件升级包<br>

使用DLL的优点
---------
* <font color=blue>节省内存和减少交换操作</font><br>
    &emsp;很多进程可以同时使用一个DLL,在内存中共享该DLL的一个副本.<br>
    &emsp;相反,对于每个用静态链接库生成的应用程序,Windows必须在内存中加载库代码的一个副本.<br>

* <font color=blue>易于升级,提供售后支持</font><br>
    &emsp;当DLL中的函数发生更改时,只要函数的参数和返回值没有更改,就不需重新编译或重新链接使用它们的应用程序.<br>
    &emsp;相反,静态链接的对象代码要求在函数更改时重新链接应用程序.<br>

* <font color=blue>支持多语言程序</font><br>
    &emsp;只要程序遵循函数的调用约定,用不同编程语言编写的程序就卡一调用相同的DLL函数.<br>

* <font color=green>比如:</font><br>
    &emsp;使用VB或C#编写应用程序的界面,业务逻辑使用C++或C语言<br>

* <font color=pink>隐藏代码的实现</font><br>

使用DLL的缺点
----------
* <font color=red>应用程序不是独立的</font>

* <font color=red>意味着发布自己的应用程序时,必须同时发布DLL</font>

***************************

<font color=pink>**DLL的创建和使用**</font>
==========
命令行下的创建和使用
----------
* 创建一个DLL:

    新建MathTest.c程序;<br>
    注意使用指定符号:_declspec(dllexport)<br>

```c
//在函数前面加上_declspec(dllexport)即可表示动态链接库导出符号对应
_declspec (dllexport) float GetAdd(float a, float b)
{
	return a + b;
}

_declspec (dllexport) float GetSub(float a, float b)
{
	return a - b;
}

_declspec (dllexport) float GetAdd(float a, float b)
{
	return a * b;
}
```
在命令行中对MathTest.c程序进行编译<br>
<br>
要想使用cl命令,还是要从VS中进入命令行使用<br>

    cl /LDd MathTest.c 创建Debug版DLL
    cl /LD Math.c 创建release版DLL

在使用时,可能会出现"无法打开编译器生成的文件"这样的错误<br>
解决方法是将文件所在项目的项目属性修改一下<br>
>项目(P)-->XXX(项目名)属性(P)-->C/C++-->输出文件-->汇编程序输出-->无列表<br>
或者打开一个其他的项目,解除该项目的编译器占用<br>

单独的文件,就将.c文件放在一个简单的文件夹中,再进行编译即可<br>

```cmd
G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>cl MathTest.c
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.16.27030.1 版
版权所有(C) Microsoft Corporation。保留所有权利。

MathTest.c
Microsoft (R) Incremental Linker Version 14.16.27030.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:MathTest.exe
MathTest.obj
  正在创建库 MathTest.lib 和对象 MathTest.exp
LINK : fatal error LNK1561: 必须定义入口点
```

编译完成后会产生.exp,.lib,.obj三种文件,但没有想要的dll文件<br>
>解决方法:添加main函数到文件中去即可<br>

```c
_declspec (dllexport) float GetAdd(float a, float b)
{
	return a + b;
}

_declspec (dllexport) float GetSub(float a, float b)
{
	return a - b;
}

_declspec (dllexport) float GetAdd(float a, float b)
{
	return a * b;
}
//添加入口
int main()
{
    return 0;
}
```

删掉原先生成的.exp,.lib,.obj三种文件,重新编译<br>

```cmd
G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>cl /LDd MathTest.c
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.16.27030.1 版
版权所有(C) Microsoft Corporation。保留所有权利。

MathTest.c
Microsoft (R) Incremental Linker Version 14.16.27030.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:MathTest.dll
/dll
/implib:MathTest.lib
MathTest.obj
  正在创建库 MathTest.lib 和对象 MathTest.exp

G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>dir
 驱动器 G 中的卷是 LearningFiles
 卷的序列号是 707B-2E13

 G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList 的目录

2019-04-22  Yui.PM 06:59    <DIR>          .
2019-04-22  Yui.PM 06:59    <DIR>          ..
2019-04-22  Yui.PM 06:58               262 MathTest.c
2019-04-22  Yui.PM 06:59           253,952 MathTest.dll
2019-04-22  Yui.PM 06:59               846 MathTest.exp
2019-04-22  Yui.PM 06:59             2,026 MathTest.lib
2019-04-22  Yui.PM 06:59               855 MathTest.obj
2019-04-22  Yui.PM 07:00            11,478 ReplenishesOfLineList.md
               6 个文件        269,419 字节
               2 个目录 225,654,464,512 可用字节
```

可见产生了.dll,.exp,.lib,.obj文件<br>
<br>
使用dumpbin查看一下DLL的导出符号<br>

    dumpbin /EXPORTS Math.dll 查看DLL的导出符号

```cmd
G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>dumpbin /EXPORTS MathTest.dll
Microsoft (R) COFF/PE Dumper Version 14.16.27030.1
Copyright (C) Microsoft Corporation.  All rights reserved.


Dump of file MathTest.dll

File Type: DLL

  Section contains the following exports for MathTest.dll

    00000000 characteristics
    FFFFFFFF time date stamp
        0.00 version
           1 ordinal base
           3 number of functions    //函数个数为3个
           3 number of names        //函数名为3个

    ordinal hint RVA      name

          1    0 00001000 GetAdd
          2    1 00001040 GetMul
          3    2 00001020 GetSub

  Summary

        2000 .data
        F000 .rdata
        2000 .reloc
       2D000 .text
```
可见有三个函数,函数名分别是GetAdd,GetMul,GetSub(按字母顺序排列)<br>
<br>
要想使用这个dll动态链接库,需要再写一个文件TestMathDemo.c导入想用的函数即可<br>

```c
//TestMathDemo.c

#include <stdio.h>

_declspec (dllimport) float GetAdd(float a, float b);

int main(int agrc, char **argv)
{
	float result = GetAdd(2, 3);
	printf("result=%f\n", result);
	return 0;
}
```

对其进行编译,并连接生成的.obj和刚刚生成的.lib文件<br>

        cl /c TestMathDemo.c
        link TestMathDemo.obj MathTest.lib

```cmd
G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>cl /c TestMathDemo.c
用于 x86 的 Microsoft (R) C/C++ 优化编译器 19.16.27030.1 版
版权所有(C) Microsoft Corporation。保留所有权利。

TestMathDemo.c

G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>dir
 驱动器 G 中的卷是 LearningFiles
 卷的序列号是 707B-2E13

 G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList 的目录

2019-04-22  Yui.PM 07:13    <DIR>          .
2019-04-22  Yui.PM 07:13    <DIR>          ..
2019-04-22  Yui.PM 06:58               262 MathTest.c
2019-04-22  Yui.PM 06:59           253,952 MathTest.dll
2019-04-22  Yui.PM 06:59               846 MathTest.exp
2019-04-22  Yui.PM 06:59             2,026 MathTest.lib
2019-04-22  Yui.PM 06:59               855 MathTest.obj
2019-04-22  Yui.PM 07:12            14,394 ReplenishesOfLineList.md
2019-04-22  Yui.PM 07:08               212 TestMathDemo.c
2019-04-22  Yui.PM 07:13             1,827 TestMathDemo.obj
               8 个文件        274,374 字节
               2 个目录 225,651,830,784 可用字节

G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>link TestMathDemo.obj MathTest.lib
Microsoft (R) Incremental Linker Version 14.16.27030.1
Copyright (C) Microsoft Corporation.  All rights reserved.


G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>dir
 驱动器 G 中的卷是 LearningFiles
 卷的序列号是 707B-2E13

 G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList 的目录

2019-04-22  Yui.PM 07:13    <DIR>          .
2019-04-22  Yui.PM 07:13    <DIR>          ..
2019-04-22  Yui.PM 06:58               262 MathTest.c
2019-04-22  Yui.PM 06:59           253,952 MathTest.dll
2019-04-22  Yui.PM 06:59               846 MathTest.exp
2019-04-22  Yui.PM 06:59             2,026 MathTest.lib
2019-04-22  Yui.PM 06:59               855 MathTest.obj
2019-04-22  Yui.PM 07:12            14,394 ReplenishesOfLineList.md
2019-04-22  Yui.PM 07:08               212 TestMathDemo.c
2019-04-22  Yui.PM 07:13           101,376 TestMathDemo.exe
2019-04-22  Yui.PM 07:13             1,827 TestMathDemo.obj
               9 个文件        375,750 字节
               2 个目录 225,651,728,384 可用字节
```

&emsp;这样就会生成TestMathDemo.exe文件,运行它,就得到了TestMathDemo.c文件的结果<br>
&emsp;直接打开该文件会一闪而过,因为没有system(pause)命令,所以接着使用命令行运行<br>
>[注]如果该目录里没有MathTest.dll文件的话,运行exe文件时,会报错说系统缺失DLL文件<br>

```cmd
G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList>TestMathDemo.exe
result=5.000000
```

得到结果result=5.000000<br>

>小结步骤:<br>
1>新建c文件,并写入使用指定符号:_declspec(dllexport)修饰的函数,再配备一个入口(main函数)<br>
2>编译此文件,创建DLL文件(cl /LDd MathTest.c 创建Debug版DLL)<br>
3>新建新的c文件,写入使用指定符号:_declspec (dllimport)修饰的函数声明,写出使用函数的主函数体<br>
4>编译此文件,链接obj文件和lib文件,并将dll文件放入同目录下,运行链接后生成的.exe文件,得到结果<br>
>>注:链接obj文件和lib文件,这种使用DLL文件创建应用程序的方式是一种静态链接过程,并不是动态链接过程,所以要在目录中放入dll文件<br>

VS开发环境下的创建和使用
----------
1. 创建DLL工程

新建-->项目-->Visual C++-->Windows桌面-->Windows桌面向导-->应用程序类型:选择dll-->附加选项:选择空项目-->完成<br>
>例子:参照项目---Demo_DLL<br>

项目包含两个文件:<br>

    Create_DLL.h和Create_DLL.c
<br>
Create_DLL.h<br>

```c
#ifndef Create_DLL_H
#define Create_DLL_H

//要导出的函数在这里声明
_declspec (dllexport) float GetAdd(float a, float b);
_declspec (dllexport) float GetSub(float a, float b);
_declspec (dllexport) float GetMul(float a, float b);

#endif // Create_DLL_H
```

Create_DLL.c<br>

```c
#include "Create_DLL.h"

//写入要导出的函数的函数体

float GetAdd(float a, float b)
{
	return a + b;
}

float GetSub(float a, float b)
{
	return a - b;
}

float GetMul(float a, float b)
{
	return a * b;
}
```
生成项目,可见项目的Debug文件夹下产生了相应的文件,其中包括lib和dll文件<br>

2. 创建测试DLL工程

&emsp;<font color=red>演示隐式链接有两种方法</font><br>
<br>
<font color=blue>隐式链接:在加载时动态链接(常用的方法)</font><br>
<br>
&emsp;&emsp;在加载时动态链接中,应用程序像调用本地函数一样对导出的DLL函数进行调用.<br>
&emsp;&emsp;要使用加载时动态链接,需要在编译和链接应用程序时提供头文件(.h)和导入库文件(.lib)<br>
&emsp;&emsp;这样做时,链接器将向系统提供加载DLL所需的信息,并在加载时解析导出的DLL函数的位置<br>

在现有解决方案中创建DLL测试工程<br>
&emsp;&emsp;[注]因为是一个测试工程,所以要有exe应用程序输出,故在此不是一个dll项目了,而是exe项目<br>

右键项目解决方案名-->添加-->新建项目-->Visual C++-->Windows桌面-->Windows桌面向导-->输入名称-->解决方案选择:添加到解决方案-->应用程序类型:选择控制台应用程序(.exe)-->附加选项:选择空项目-->完成<br>

>例子:参照项目---Test_DLL_implicit<br>

    项目包含两个文件:Create_DLL.h和Test_DLL.c

Create_DLL.h文件和第一个项目并没有不同<br>

```c
#ifndef Create_DLL_H
#define Create_DLL_H

//要导出的函数在这里声明
_declspec (dllexport) float GetAdd(float a, float b);
_declspec (dllexport) float GetSub(float a, float b);
_declspec (dllexport) float GetMul(float a, float b);

#endif // Create_DLL_H
```
Test_DLL.c是测试的源文件<br>

```c
#include <stdio.h>
#include <stdlib.h>
#include "Create_DLL.h"//添加相应的头文件

//隐式链接方式一:在linker--input中添加依赖项lib文件

//隐式链接方式二:#pragma comment(lib,"Demo_DLL")
//#pragma comment(lib,"Demo_DLL")
int main()
{
	float m, n, ResAdd, ResSub, ResMul;
	//给三个局部变量初始化,否则会报错
	ResAdd = 0;
	ResSub = 0;
	ResMul = 0;
	printf("请输入m和n,用逗号隔开\n");
	scanf_s("%f,%f", &m, &n);//使用更为安全的scanf函数
	//直接实现加减乘的结果
	ResAdd = GetAdd(m, n);
	printf("%0.0f\n", ResAdd);

	ResAdd = GetSub(m, n);
	printf("%0.0f\n", ResSub);

	ResAdd = GetMul(m, n);
	printf("%0.0f\n", ResMul);
	//要使用system命令,需要#include <stdlib.h>
	system("pause");
}
```
现在这种情况下,是无法直接运行的,因为并不知道三个函数函数体在哪<br>

>解决方式:需要使用两种隐式链接方式的一种<br>
<br>

比如要使用方法一:在linker--input中添加依赖项lib文件<br>

>具体操作:右键点击项目名Test_DLL_implicit-->属性-->链接器-->输入-->附加依赖项-->编辑-->添加文件名:Demo_DLL.lib<br>
<br>

&emsp;&emsp;在使用VS2017时,c语言的很多函数需要使用加_s的方式使用,即新的安全模式函数<br>
&emsp;&emsp;另外,局部变量需要初始化<br>
<br>
遇到报错<br>
>LINK : fatal error LNK1104: 无法打开文件“Demo_DLL.lib"<br>
>解决方式:右键点击项目名Test_DLL_implicit-->属性-->VC++目录-->库目录-->添加G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList_DLL\Demo_DLL\Debug(即Demo_DLL.lib所在的目录)<br>

<br>
运行,成功<br>

<br>
在现有解决方案中创建DLL测试工程<br>

右键项目解决方案名-->添加-->新建项目-->Visual C++-->Windows桌面-->Windows桌面向导-->输入名称-->解决方案选择:添加到解决方案-->应用程序类型:选择控制台应用程序(.exe)-->附加选项:选择空项目-->完成<br>

***********************

方法二即不需要单独配置lib文件,直接释放注释中的下行代码即可<br>
<code>#pragma comment(lib,"Demo_DLL")</code><br>
>例子:参照项目---Test_DLL_implicit_another<br>

项目包含两个文件:<br>

    Create_DLL.h和Test_DLL_another.c

Create_DLL.h文件和第一个项目并没有不同<br>

```c
#ifndef Create_DLL_H
#define Create_DLL_H

//要导出的函数在这里声明
_declspec (dllexport) float GetAdd(float a, float b);
_declspec (dllexport) float GetSub(float a, float b);
_declspec (dllexport) float GetMul(float a, float b);

#endif // Create_DLL_H
```
Test_DLL_another.c是测试的源文件<br>

```c
#include <stdio.h>
#include <stdlib.h>
#include "Create_DLL.h"//添加相应的头文件

//隐式链接方式一:在linker--input中添加依赖项lib文件

//隐式链接方式二:#pragma comment(lib,"Demo_DLL")
#pragma comment(lib,"Demo_DLL")
int main()
{
	float m, n, ResAdd, ResSub, ResMul;
	//给三个局部变量初始化,否则会报错
	ResAdd = 0;
	ResSub = 0;
	ResMul = 0;
	printf("请输入m和n,用逗号隔开\n");
	scanf_s("%f,%f", &m, &n);//使用更为安全的scanf函数
	//直接实现加减乘的结果
	ResAdd = GetAdd(m, n);
	printf("%f\n", ResAdd);

	ResAdd = GetSub(m, n);
	printf("%f\n", ResSub);

	ResAdd = GetMul(m, n);
	printf("%f\n", ResMul);
	//要使用system命令,需要#include <stdlib.h>
	system("pause");
}
```

>两个项目都是测试项目,要运行哪一个呢?<br>
>>右键点击项目名-->设为启动项目<br>

<font color=pink>即最后一个设定为启动项目的就是按ctrl+f5会生成并运行的项目</font><br>

[Different]两个测试都是隐式测试,但结果不同<br>
&emsp;&emsp;Test_DLL_implicit结果为X<br>
&emsp;&emsp;Test_DLL_implicit_another结果为X.0000<br>

遇到报错<br>

>LINK : fatal error LNK1104: 无法打开文件“Demo_DLL.lib"<br>
>解决方式:右键点击项目名Test_DLL_implicit-->属性-->VC++目录-->库目录-->添加G:\C_StructureAlgorithmCollegeMooc\LineList\ReplenishesOfLineList_DLL\Demo_DLL\Debug(即Demo_DLL.lib所在的目录)<br>

3. 创建测试工程

演示显示链接<br>

&emsp;<font color=blue>显示链接:运行时动态链接</font><br>

&emsp;&emsp;在运行时动态链接中,应用程序调用LoadLibrary函数或LoadLibraryEx函数实现在运行时加载DLL.<br>
&emsp;&emsp;成功加载DLL后,可以使用GetProcAddress函数获得要调用的导出的DLL函数的地址.在使用运行时动态链接时,无需使用导入库文件.<br>

在现有解决方案中创建DLL测试工程<br>

&emsp;&emsp;[注]因为是一个测试工程,所以要有exe应用程序输出,故在此不是一个dll项目了,而是exe项目<br>

右键项目解决方案名-->添加-->新建项目-->Visual C++-->Windows桌面-->Windows桌面向导-->输入名称-->解决方案选择:添加到解决方案-->应用程序类型:选择控制台应用程序(.exe)-->附加选项:选择空项目-->完成<br>
>例子:参照项目---Test_DLL_explicit<br>

项目包含一个文件<br>

    Test_DLL_explicit.cpp

Test_DLL_explicit.cpp<br>
```c++
#include <windows.h>
#include <iostream>

using namespace std;

//显示调用方式
int main()
{
	float m, n, ResAdd, ResSub;
  //初始化局部变量先
	ResAdd = 0;
	ResSub = 0;
  //和C语言的结构体中用途一样,做回调函数
  //声明返回类型为float类型的两个函数指针,名称为MyGetAdd和MyGetSub,含两个float参数
  //其中_cdecl是C Declaration的缩写,表示使用C语言默认的函数调用方法
	typedef float(_cdecl *MyGetAdd)(float, float);
	typedef float(_cdecl *MyGetSub)(float, float);
	//加载目标DLL库到进程的虚拟地址空间,函数执行成功返回DLL模块的句柄,否则返回NULL
	HMODULE hModule = LoadLibrary("Demo_DLL.dll");

	//调用GetProcAddress获得目标DLL中导出函数的地址
  //并放入相关的函数指针变量GetAddValue和GetSubValue中
  //(MyGetAdd)用于声明类型,有点像强制类型转换的意思
	MyGetAdd GetAddValue = (MyGetAdd)GetProcAddress(hModule, "GetAdd");
	MyGetSub GetSubValue = (MyGetSub)GetProcAddress(hModule, "GetSub");

  //经过这些操作,就可以使用GetAddValue(float m,float n)这样的语句了

	cout << "请输入m和n" << endl;
	cin >> m >> n;

	ResAdd = GetAddValue(m, n);
	cout << ResAdd << endl;

	ResSub = GetSubValue(m, n);
	cout << ResSub << endl;

	//调用FreeLibrary释放资源
	FreeLibrary(hModule);

	system("pause");
}
```

遇到报错<br>
>error C2664: “HMODULE LoadLibraryW(LPCWSTR)”: 无法将参数 1 从“const char [13]”转换为“LPCWSTR”<br>
>note: 与指向的类型无关；强制转换要求 reinterpret_cast、C 样式强制转换或函数样式强制转换<br>

>解决方式:<br>
>>1)右键项目名称-->属性-->常规-->字符集-->使用多字节字符集<br>
>>2)右键项目名称-->属性-->C/C++-->预处理器-->预处理定义-->删掉UNICODE的项<br>
<br>

运行,成功<br>
<br>

[注]相关的知识点:<br>
<1>typedef float(_cdecl *MyGetAdd)(float, float);<br>
//首先,这是一个回调函数的用法,要使用的部分只有MyGetAdd这个函数指针而已<br>
//float表示这个含有两个参数(float, float)的函数指针返回类型为float类型<br>
//由于是c语言的练习,所以即使用了c++,能调的地方也调一下,因此用到了_cdecl这个缩写<br>
<br>
<2>HMODULE hModule = LoadLibrary("Demo_DLL.dll");<br>
//HMODULE是表示模块句柄的关键字<br>
//这是一行返回DLL模块句柄的代码,dll文件为Demo_DLL.dll<br>
<br>
//LoadLibrary函数<br>
//[格式]:<br>
//function LoadLibrary(LibFileName:PChar):Thandle;<br>
//即加载由参数LibFileName指定的dll文件<br>
<br>
<3>FreeLibrary函数<br>
//[格式]:<br>
//procedure FreeLibrary(Module:Thandle);<br>
将由参数 Module 指定的 DLL 文件从内存中卸载 1 次<br>
<br>
>[注意]：每调用一次 LoadLibrary 函数就应调用一次 FreeLibrary 函数,以保证不会有多余的库模块在应用程序结束后仍留在内存中,否则导致内存泄漏<br>

<br>
<4>GetProcAddress 函数<br>
//[格式]:<br>
//function GetProcAddress(Module:Thandle; ProcName:PChar): TfarProc;<br>
//返回Module指定的模块中,由参数ProcName指定的过程或函数的入口地址<br>
//参数Module包含被调用函数的DLL句柄,这个值由LoadLibrary函数返回<br>
//ProcName是指向含有函数名的以nil结尾的字符串指针,或者可以是函数的次序值,<font color=green>但大多数情况下,用函数名是一种更稳妥的选择</font><br>
//如果该函数执行成功,则返回DLL中由参数ProcName指定的过程或函数的入口地址,否则返回nil<br>
<br>

>>到此为止结束相关内容<br>
>>拓展书籍:<<程序员的自我修养--链接、装载与库>>,<<Windows核心编程(第5版)>><br>