#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

//ʵ��8���Ƶ�ת��
void OctConversion(LinkedStack ps, int n)
{
	int temp = 0;//��ʼ��temp
	while (n)
	{
		//��n����8������ѹ��ջ��
		Push_link(ps, n % 8);
		//�µ�n = ԭn / 8  (����)
		n /= 8;
	}
	printf("ת��Ϊ�˽���֮��,���Ϊ:");
	//ֻҪ���վ�һֱ��ջ,ֱ��ջΪ��Ϊֹ
	while (!IsNullStack_link(ps))
	{
		//�������޸���8���Ƶĳ�ջ���ú���
		//temp = Pop_seq_return(ps);
		temp = PopWithReturn_link(ps);
		printf("%d", temp);
		//Pop_link(ps);
	}
	printf("\n");
	//End OCTONARY
}

//ʵ��16���Ƶ�ת��
void HexConversion(LinkedStack ps, int n)
{
	//��16������,��ABCDEF����ʾ,��Ҫ��һ��switch���
	int temp = 0;//��ʼ��temp
	while (n)
	{
		//��16��ģ,��ֵ��temp,�����ж�֮����ѹ��ջ��
		temp = n % 16;
		switch (temp)
		{
		case 10:
		{
			temp = 'A';
			break;
		}
		case 11:
		{
			temp = 'B';
			break;
		}
		case 12:
		{
			temp = 'C';
			break;
		}
		case 13:
		{
			temp = 'D';
			break;
		}
		case 14:
		{
			temp = 'E';
			break;
		}
		case 15:
		{
			temp = 'F';
			break;
		}
		default:
			break;
		}
		//��ջ
		Push_link(ps, temp);
		//n = n/16
		n /= 16;
	}
	printf("ת��Ϊʮ�����ƺ�Ľ��Ϊ:");
	while (!IsNullStack_link(ps))
	{
		//�������޸���16���Ƶĳ�ջ���ú���
		temp = PopWithReturn_link(ps);
		//temp = Pop_seq_return(ps);
		if (temp<10)
		{
			printf("%d", temp);
		}
		else
		{
			printf("%c", temp);
		}
		//���һ�����ͳ�һ��ջ,ֱ��ջΪ��
		//Pop_link(ps);
	}
	printf("\n");
	//End HEXADECIMAL
}

//ʵ��2���Ƶ�ת��
void BinConversion(LinkedStack ps, int n)
{
	int temp = 0;//��ʼ��temp
	while (n)
	{
		//��n����2������ѹ��ջ��
		Push_link(ps, n % 2);
		//�µ�n = ԭn / 2  (����)
		n /= 2;
	}
	printf("ת��Ϊ������֮��,���Ϊ:");
	//ֻҪ���վ�һֱ��ջ,ֱ��ջΪ��Ϊֹ
	while (!IsNullStack_link(ps))
	{
		//�������޸���2���Ƶĳ�ջ���ú���
		temp = PopWithReturn_link(ps);
		//temp = Pop_seq_return(ps);
		printf("%d", temp);
		//Pop_link(ps);
	}
	printf("\n");
	//End BINARY
}

int main()
{
	//������ջ
	LinkedStack mystack = SetNullStack_Link();
	int n = 0;
	printf("*************************************************\n");
	printf("��������Ҫת����ʮ������:");
	scanf_s("%d", &n);
	printf("\n");
	printf("��������Ҫ��ʾ���ֽ��ƵĽ��:\n");
	printf("1.2����\n");
	printf("2.8����\n");
	printf("3.16����\n");
	printf("4.ȫ��������ʾ\n");
	printf("*************************************************\n");
	int i = 0;//switch���ж�ֵ
	scanf_s("%d", &i);
	if (i>4)
	{
		printf("�������!������������!\n");
		return 0;
	}
	switch (i)
	{
		case 1:
		{
			BinConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		case 2:
		{
			OctConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		case 3:
		{
			HexConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		case 4:
		{
			printf("�������ʮ������Ϊ:%d", n);
			printf("\n");
			BinConversion(mystack, n);
			OctConversion(mystack, n);
			HexConversion(mystack, n);
			printf("*************************************************\n");
			break;
		}
		default:
			break;
	}

	system("pause");
}