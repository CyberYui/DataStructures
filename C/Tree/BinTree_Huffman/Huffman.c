#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"

/****************************************************************/
/* int *GetFrequency()											*/
/* 功能:读入自选文件或默认文件进行字频分析						*/
/* 输入参数:无													*/
/* 返回值:freq为字频分析结果数组								*/
/* 创建日期:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
int *GetFrequency()
{
	int i;
	int LEN = CHARLEN;
	FILE *fp = NULL;
	int *freq = (int *)malloc(sizeof(int)*LEN);
	//初始化freq数组
	for (i = 0; i < LEN; i++)
	{
		freq[i] = 0;
	}
	//使用不安全的老函数会报错
	//fp = fopen(".\\file.txt", "r");	//打开相对路径下的文件,文件名为file.txt
	//[ERROR]以下注释是一行的内容
	//error C4996: 'fopen': This function or variable may be unsafe.
	//Consider using fopen_s instead.
	//To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
	//See online help for details.

	//解决方式是使用fopen_s
	//在使用fopen_s前需要另外定义一个变量
	errno_t err;	//定义的额外变量,这么做是因为fopen_s比fopen多了溢出检测,更安全一些
	//打开相对路径下的文件,文件名为file.txt
	err = fopen_s(&fp, ".\\file.txt", "r");	//文件内容会保存给fp的引用
	//txt文件内容即每个小写字符重复几次,这里就会统计几作为相应的权值
	if (fp == NULL)
	{
		printf("\n\t\t找不到文件\"\n");
		exit(0);
	}
	//对文件进行字频分析,在这里只是小写字母
	//这里直接用以下内容会报错
	//for (char ch; 0 < fscanf_s(fp, "%c", &ch);)
	//warning C4473: “fscanf_s”: 没有为格式字符串传递足够的参数
	//这是因为fscanf_s和scanf_s一样,需要给定变量的长度,也就是这里循环中的ch
	//可以是sizeof(char)也可以是sizeof(ch)
	//for (char ch; 0 < fscanf_s(fp,"%c", &ch ,sizeof(char));)
	for (char ch; 0 < fscanf_s(fp, "%c", &ch, sizeof(ch));)
	{
		//利用循环进行统计
		printf("%c ", ch);
		if (ch >= 0x61)
		{
			freq[ch - 0x61] ++;	//频率++
		}
	}
	printf("\n");
	fclose(fp);
	return freq;
}

/****************************************************************/
/* HuffTree CreateHuffTree(int n, int *w)						*/
/* 功能:构造哈夫曼树											*/
/* 输入参数:n--结点个数		w--结点权值							*/
/* 返回值:huffman树的根											*/
/* 创建日期:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
HuffTree CreateHuffTree(int n, int *w)
{
	HuffTree pht;
	//创建变量并初始化
	int i = 0;
	int j = 0;
	int x1 = 0;
	int x2 = 0;
	int min1 = 0;
	int min2 = 0;

	//申请临时结点空间
	pht = (HuffTree)malloc(sizeof(struct HuffTreeNode));
	if (pht == NULL)
	{
		printf("out of space!\n");
		return pht;
	}
	//为哈夫曼树申请2n-1个空间
	pht->ht = (HtNode)malloc(sizeof(struct HuffNode)*(2 * n - 1));

	if (pht->ht == NULL)
	{
		printf("Out of space!\n");
		return pht;
	}
	//初始化哈夫曼树
	for (i = 0; i < 2 * n - 1; i++)
	{
		pht->ht[i].leftchild = -1;	//初始化左孩子位置
		pht->ht[i].rightchild = -1;	//初始化右孩子位置
		pht->ht[i].parent = -1;		//初始化父结点位置
		//外部结点赋权值,对应为w[i]数组的内容,数组是参数
		if (i < n)
		{
			pht->ht[i].weight = w[i];
		}
		//内部结点默认权值为-1
		else
		{
			pht->ht[i].weight = -1;
		}
	}
	//
	for (i = 0; i < n - 1; i++)
	{
		min1 = MAX;
		min2 = MAX;
		x1 = -1;
		x2 = -1;
		//循环寻找最小权值和次小权值的结点
		for (j = 0; j < n + i; j++)
		{
			//找到极小值下标x1并把权值赋值给min1
			if (pht->ht[j].weight < min1 && pht->ht[j].parent == -1)
			{
				min2 = min1;
				x2 = x1;
				min1 = pht->ht[j].weight;
				x1 = j;
			}
			//找到次小值下标x2并把次小值的权值赋值给min2
			else if (pht->ht[j].weight < min2 && pht->ht[j].parent == -1)
			{
				min2 = pht->ht[j].weight;
				x2 = j;
			}
		}
		//构建x1,x2的父结点
		//新生成的父结点是两个孩子结点共同的父结点
		pht->ht[x1].parent = n + i;	//x1的父结点下标
		pht->ht[x2].parent = n + i;	//x2的父结点下标

		//父结点的权值为两孩子结点权值之和
		pht->ht[n + i].weight = min1 + min2;

		pht->ht[n + i].leftchild = x1;	//父结点的左孩子为x1
		pht->ht[n + i].rightchild = x2;	//父结点的右孩子为x1
	}
	pht->root = 2 * n - 2;	//哈夫曼树根结点位置
	pht->n = n;	//n为参数,即结点数
	return pht;
}