#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义画布,坐标原点,初始化宽和高
static char* image;
static int x = 0;
static int y = 0;
static int w = 0;
static int h = 0;

static void Put(int i, int j, char c) 
{
	//i即x,j即y,c为要插入的字符
	char *p = image + j * w + i;//定位
	//下划线和空格可以被/或者\替代,用于对特殊地方的显示
	if (*p == ' ' || *p == '_')
	{
		*p = c;//插入字符
	}
}

//实现科赫曲线,n为阶数,dir为方向
static void KochCurve(int n, int dir) 
{
	if (n == 0)
	{
		//有六个方向,求方向与6的模
		switch (dir % 6)
		{
			//向右
			case 0:
			{
				Put(x++, y, '_');
				Put(x++, y, '_');
				break;
			}
			//右上
			case 1:
			{
				Put(x++, y--, '/');
				break;
			}
			//左上
			case 2:
			{
				Put(--x, y--, '\\');
				break;
			}
			//向左
			case 3:
			{
				Put(--x, y, '_');
				Put(--x, y, '_');
				break;
			}
			//左下
			case 4:
			{
				Put(--x, ++y, '/');
				break;
			}
			//右下
			case 5:
			{
				Put(x++, ++y, '\\');
				break;
			}
		}
	}
	else 
	{
		//递归,直到n为0,然后画图
		KochCurve(n - 1, dir);
		KochCurve(n - 1, dir + 1);
		KochCurve(n - 1, dir + 5);
		KochCurve(n - 1, dir);
	}
}

int main() 
{
	//定义开始的(一阶)画布的宽和高
	w = 2;
	h = 1;
	//循环输出不同阶的科赫曲线,n为要输出的最大阶数+1
	for (int n = 0; n < 5; n++) 
	{
		//申请数组,大小为w*h
		image = (char*)malloc(w * h);
		//将画布用空格填空
		memset(image, ' ', w * h);//关于此函数见StackAndQueue_C_Learning.md
		//定义原点
		x = 0;
		y = h - 1;
		//开始画图,从画布右上角开始
		KochCurve(n, 0);//画n阶的科赫曲线
		//每画出一阶就打印出阶数
		printf("\n n=%d \n \n", n);
		//开始画图
		for (int j = 0; j < h; j++) 
		{
			for (int i = 0; i < w; i++)//循环输出数组
				putchar(image[j * w + i]);
			putchar('\n');//每输出一行就另起一行
		}
		//每画完一阶就要用对应新一阶的画布
		w *= 3;//w=w*3
		h = (n == 0) ? 1 : h * 3;//当n=0时h=1,否则h=h*3
		free(image);//释放旧的画布空间
	}
}