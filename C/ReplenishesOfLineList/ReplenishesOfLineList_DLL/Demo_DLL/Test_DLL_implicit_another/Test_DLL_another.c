#include <stdio.h>
#include <stdlib.h>
#include "Create_DLL.h"//�����Ӧ��ͷ�ļ�

//��ʽ���ӷ�ʽһ:��linker--input�����������lib�ļ�

//��ʽ���ӷ�ʽ��:#pragma comment(lib,"Demo_DLL")
#pragma comment(lib,"Demo_DLL")
int main()
{
	float m, n, ResAdd, ResSub, ResMul;
	//�������ֲ�������ʼ��,����ᱨ��
	ResAdd = 0;
	ResSub = 0;
	ResMul = 0;
	printf("������m��n,�ö��Ÿ���\n");
	scanf_s("%f,%f", &m, &n);//ʹ�ø�Ϊ��ȫ��scanf����
	//ֱ��ʵ�ּӼ��˵Ľ��
	ResAdd = GetAdd(m, n);
	printf("%f\n", ResAdd);

	ResAdd = GetSub(m, n);
	printf("%f\n", ResSub);

	ResAdd = GetMul(m, n);
	printf("%f\n", ResMul);
	//Ҫʹ��system����,��Ҫ#include <stdlib.h>
	system("pause");
}