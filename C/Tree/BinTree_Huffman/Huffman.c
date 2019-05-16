#include <stdio.h>
#include <stdlib.h>
#include "Huffman.h"

/****************************************************************/
/* int *GetFrequency()											*/
/* ����:������ѡ�ļ���Ĭ���ļ�������Ƶ����						*/
/* �������:��													*/
/* ����ֵ:freqΪ��Ƶ�����������								*/
/* ��������:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
int *GetFrequency()
{
	int i;
	int LEN = CHARLEN;
	FILE *fp = NULL;
	int *freq = (int *)malloc(sizeof(int)*LEN);
	//��ʼ��freq����
	for (i = 0; i < LEN; i++)
	{
		freq[i] = 0;
	}
	//ʹ�ò���ȫ���Ϻ����ᱨ��
	//fp = fopen(".\\file.txt", "r");	//�����·���µ��ļ�,�ļ���Ϊfile.txt
	//[ERROR]����ע����һ�е�����
	//error C4996: 'fopen': This function or variable may be unsafe.
	//Consider using fopen_s instead.
	//To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
	//See online help for details.

	//�����ʽ��ʹ��fopen_s
	//��ʹ��fopen_sǰ��Ҫ���ⶨ��һ������
	errno_t err;	//����Ķ������,��ô������Ϊfopen_s��fopen����������,����ȫһЩ
	//�����·���µ��ļ�,�ļ���Ϊfile.txt
	err = fopen_s(&fp, ".\\file.txt", "r");	//�ļ����ݻᱣ���fp������
	//txt�ļ����ݼ�ÿ��Сд�ַ��ظ�����,����ͻ�ͳ�Ƽ���Ϊ��Ӧ��Ȩֵ
	if (fp == NULL)
	{
		printf("\n\t\t�Ҳ����ļ�\"\n");
		exit(0);
	}
	//���ļ�������Ƶ����,������ֻ��Сд��ĸ
	//����ֱ�����������ݻᱨ��
	//for (char ch; 0 < fscanf_s(fp, "%c", &ch);)
	//warning C4473: ��fscanf_s��: û��Ϊ��ʽ�ַ��������㹻�Ĳ���
	//������Ϊfscanf_s��scanf_sһ��,��Ҫ���������ĳ���,Ҳ��������ѭ���е�ch
	//������sizeof(char)Ҳ������sizeof(ch)
	//for (char ch; 0 < fscanf_s(fp,"%c", &ch ,sizeof(char));)
	for (char ch; 0 < fscanf_s(fp, "%c", &ch, sizeof(ch));)
	{
		//����ѭ������ͳ��
		printf("%c ", ch);
		if (ch >= 0x61)
		{
			freq[ch - 0x61] ++;	//Ƶ��++
		}
	}
	printf("\n");
	fclose(fp);
	return freq;
}

/****************************************************************/
/* HuffTree CreateHuffTree(int n, int *w)						*/
/* ����:�����������											*/
/* �������:n--������		w--���Ȩֵ							*/
/* ����ֵ:huffman���ĸ�											*/
/* ��������:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
HuffTree CreateHuffTree(int n, int *w)
{
	HuffTree pht;
	//������������ʼ��
	int i = 0;
	int j = 0;
	int x1 = 0;
	int x2 = 0;
	int min1 = 0;
	int min2 = 0;

	//������ʱ���ռ�
	pht = (HuffTree)malloc(sizeof(struct HuffTreeNode));
	if (pht == NULL)
	{
		printf("out of space!\n");
		return pht;
	}
	//Ϊ������������2n-1���ռ�
	pht->ht = (HtNode)malloc(sizeof(struct HuffNode)*(2 * n - 1));

	if (pht->ht == NULL)
	{
		printf("Out of space!\n");
		return pht;
	}
	//��ʼ����������
	for (i = 0; i < 2 * n - 1; i++)
	{
		pht->ht[i].leftchild = -1;	//��ʼ������λ��
		pht->ht[i].rightchild = -1;	//��ʼ���Һ���λ��
		pht->ht[i].parent = -1;		//��ʼ�������λ��
		//�ⲿ��㸳Ȩֵ,��ӦΪw[i]���������,�����ǲ���
		if (i < n)
		{
			pht->ht[i].weight = w[i];
		}
		//�ڲ����Ĭ��ȨֵΪ-1
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
		//ѭ��Ѱ����СȨֵ�ʹ�СȨֵ�Ľ��
		for (j = 0; j < n + i; j++)
		{
			//�ҵ���Сֵ�±�x1����Ȩֵ��ֵ��min1
			if (pht->ht[j].weight < min1 && pht->ht[j].parent == -1)
			{
				min2 = min1;
				x2 = x1;
				min1 = pht->ht[j].weight;
				x1 = j;
			}
			//�ҵ���Сֵ�±�x2���Ѵ�Сֵ��Ȩֵ��ֵ��min2
			else if (pht->ht[j].weight < min2 && pht->ht[j].parent == -1)
			{
				min2 = pht->ht[j].weight;
				x2 = j;
			}
		}
		//����x1,x2�ĸ����
		//�����ɵĸ�������������ӽ�㹲ͬ�ĸ����
		pht->ht[x1].parent = n + i;	//x1�ĸ�����±�
		pht->ht[x2].parent = n + i;	//x2�ĸ�����±�

		//������ȨֵΪ�����ӽ��Ȩֵ֮��
		pht->ht[n + i].weight = min1 + min2;

		pht->ht[n + i].leftchild = x1;	//����������Ϊx1
		pht->ht[n + i].rightchild = x2;	//�������Һ���Ϊx1
	}
	pht->root = 2 * n - 2;	//�������������λ��
	pht->n = n;	//nΪ����,�������
	return pht;
}