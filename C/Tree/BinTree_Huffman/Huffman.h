#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX 100;
#define CHARLEN 50;

//定义哈夫曼结点
struct HuffNode 
{
	int weight;	//权值
	int parent, leftchild, rightchild;	//父结点与左右孩子
};
typedef struct HuffNode *HtNode;

//定义哈夫曼树
typedef struct HuffTreeNode
{
	int n;		//哈夫曼树叶子结点个数
	int root;	//哈夫曼树树根
	HtNode ht;	//指向哈夫曼树的指针
}*HuffTree;

/****************************************************************/
/* int *GetFrequency()											*/
/* 功能:读入自选文件或默认文件进行字频分析						*/
/* 输入参数:无													*/
/* 返回值:freq为字频分析结果数组								*/
/* 创建日期:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
int *GetFrequency();//字频作为权值输入给哈夫曼树

/****************************************************************/
/* HuffTree CreateHuffTree(int n, int *w)						*/
/* 功能:构造哈夫曼树											*/
/* 输入参数:n--结点个数		w--结点权值							*/
/* 返回值:huffman树的根											*/
/* 创建日期:2019-5-16						Author:Cyber Kaka	*/
/****************************************************************/
HuffTree CreateHuffTree(int n, int *w);

#endif // HUFFMAN_H
