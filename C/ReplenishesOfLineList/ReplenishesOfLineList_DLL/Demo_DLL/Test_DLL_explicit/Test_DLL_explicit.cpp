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
  //并传给相关的函数指针GetAddValue和GetSubValue
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