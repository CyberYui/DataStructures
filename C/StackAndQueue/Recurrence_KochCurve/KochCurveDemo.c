#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���廭��,����ԭ��,��ʼ����͸�
static char* image;
static int x = 0;
static int y = 0;
static int w = 0;
static int h = 0;

static void Put(int i, int j, char c) 
{
	//i��x,j��y,cΪҪ������ַ�
	char *p = image + j * w + i;//��λ
	//�»��ߺͿո���Ա�/����\���,���ڶ�����ط�����ʾ
	if (*p == ' ' || *p == '_')
	{
		*p = c;//�����ַ�
	}
}

//ʵ�ֿƺ�����,nΪ����,dirΪ����
static void KochCurve(int n, int dir) 
{
	if (n == 0)
	{
		//����������,������6��ģ
		switch (dir % 6)
		{
			//����
			case 0:
			{
				Put(x++, y, '_');
				Put(x++, y, '_');
				break;
			}
			//����
			case 1:
			{
				Put(x++, y--, '/');
				break;
			}
			//����
			case 2:
			{
				Put(--x, y--, '\\');
				break;
			}
			//����
			case 3:
			{
				Put(--x, y, '_');
				Put(--x, y, '_');
				break;
			}
			//����
			case 4:
			{
				Put(--x, ++y, '/');
				break;
			}
			//����
			case 5:
			{
				Put(x++, ++y, '\\');
				break;
			}
		}
	}
	else 
	{
		//�ݹ�,ֱ��nΪ0,Ȼ��ͼ
		KochCurve(n - 1, dir);
		KochCurve(n - 1, dir + 1);
		KochCurve(n - 1, dir + 5);
		KochCurve(n - 1, dir);
	}
}

int main() 
{
	//���忪ʼ��(һ��)�����Ŀ�͸�
	w = 2;
	h = 1;
	//ѭ�������ͬ�׵Ŀƺ�����,nΪҪ�����������+1
	for (int n = 0; n < 5; n++) 
	{
		//��������,��СΪw*h
		image = (char*)malloc(w * h);
		//�������ÿո����
		memset(image, ' ', w * h);//���ڴ˺�����StackAndQueue_C_Learning.md
		//����ԭ��
		x = 0;
		y = h - 1;
		//��ʼ��ͼ,�ӻ������Ͻǿ�ʼ
		KochCurve(n, 0);//��n�׵Ŀƺ�����
		//ÿ����һ�׾ʹ�ӡ������
		printf("\n n=%d \n \n", n);
		//��ʼ��ͼ
		for (int j = 0; j < h; j++) 
		{
			for (int i = 0; i < w; i++)//ѭ���������
				putchar(image[j * w + i]);
			putchar('\n');//ÿ���һ�о�����һ��
		}
		//ÿ����һ�׾�Ҫ�ö�Ӧ��һ�׵Ļ���
		w *= 3;//w=w*3
		h = (n == 0) ? 1 : h * 3;//��n=0ʱh=1,����h=h*3
		free(image);//�ͷžɵĻ����ռ�
	}
}