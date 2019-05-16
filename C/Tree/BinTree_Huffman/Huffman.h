#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX 100;
#define CHARLEN 50;

//������������
struct HuffNode 
{
	int weight;	//Ȩֵ
	int parent, leftchild, rightchild;	//����������Һ���
};
typedef struct HuffNode *HtNode;

//�����������
typedef struct HuffTreeNode
{
	int n;		//��������Ҷ�ӽ�����
	int root;	//������������
	HtNode ht;	//ָ�����������ָ��
}*HuffTree;

/****************************************************************/
/* int *GetFrequency()											*/
/* ����:������ѡ�ļ���Ĭ���ļ�������Ƶ����						*/
/* �������:��													*/
/* ����ֵ:freqΪ��Ƶ�����������								*/
/* ��������:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
int *GetFrequency();//��Ƶ��ΪȨֵ�������������

/****************************************************************/
/* HuffTree CreateHuffTree(int n, int *w)						*/
/* ����:�����������											*/
/* �������:n--������		w--���Ȩֵ							*/
/* ����ֵ:huffman���ĸ�											*/
/* ��������:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
HuffTree CreateHuffTree(int n, int *w);

#endif // HUFFMAN_H
