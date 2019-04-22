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