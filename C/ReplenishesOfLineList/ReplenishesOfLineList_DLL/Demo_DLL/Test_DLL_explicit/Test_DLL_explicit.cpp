#include <windows.h>
#include <iostream>

using namespace std;

//��ʾ���÷�ʽ
int main()
{
	float m, n, ResAdd, ResSub;
	//��ʼ���ֲ�������
	ResAdd = 0;
	ResSub = 0;
	//��C���ԵĽṹ������;һ��,���ص�����
	//������������Ϊfloat���͵���������ָ��,����ΪMyGetAdd��MyGetSub,������float����
	//����_cdecl��C Declaration����д,��ʾʹ��C����Ĭ�ϵĺ������÷���
	typedef float(_cdecl *MyGetAdd)(float, float);
	typedef float(_cdecl *MyGetSub)(float, float);
	//����Ŀ��DLL�⵽���̵������ַ�ռ�,����ִ�гɹ�����DLLģ��ľ��,���򷵻�NULL
	HMODULE hModule = LoadLibrary("Demo_DLL.dll");

	//����GetProcAddress���Ŀ��DLL�е��������ĵ�ַ
  //��������صĺ���ָ��GetAddValue��GetSubValue
  //(MyGetAdd)������������,�е���ǿ������ת������˼
	MyGetAdd GetAddValue = (MyGetAdd)GetProcAddress(hModule, "GetAdd");
	MyGetSub GetSubValue = (MyGetSub)GetProcAddress(hModule, "GetSub");

	//������Щ����,�Ϳ���ʹ��GetAddValue(float m,float n)�����������

	cout << "������m��n" << endl;
	cin >> m >> n;

	ResAdd = GetAddValue(m, n);
	cout << ResAdd << endl;

	ResSub = GetSubValue(m, n);
	cout << ResSub << endl;

	//����FreeLibrary�ͷ���Դ
	FreeLibrary(hModule);

	system("pause");
}