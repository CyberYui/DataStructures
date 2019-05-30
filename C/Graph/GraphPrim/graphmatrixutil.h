/*图的邻接矩阵表示及相关函数*/
#ifndef GRAPHADJMATRIXUTIL_H
#define GRAPHADJMATRIXUTIL_H

//结构体定义
typedef struct GRAPHMATRIX_STRU
{
	int size;       //图中结点的个数
	int **graph;    //二维数组保存图
}GraphMatrix;

/****************************************************************/
/* GraphMatrix* InitGraph(int num)								*/
/* 功能:初始化图												*/
/* 输入参数num:图中结点的个数									*/
/* 返回值:用邻接矩阵表示的图									*/
/* 创建日期:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* InitGraph(int num);

/****************************************************************/
/* void ReadGraph(GraphMatrix* graphMatrix)						*/
/* 功能:将数据读入图中											*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphMatrix* graphMatrix);

/****************************************************************/
/* void WriteGraph(GraphMatrix* graphMatrix)					*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphMatrix* graphMatrix);

/****************************************************************/
/* GraphMatrix* prim(int source, GraphMatrix *graphMatrix)		*/
/* 功能:普利姆算法生成最小生成树								*/
/* 输入参数source:初始位置										*/
/* 输入参数graphMatrix:邻接矩阵表示的图							*/
/* 返回值tree:最小生成树										*/
/* 创建日期:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* prim(int source, GraphMatrix *graphMatrix);

#endif // GRAPHADJMATRIXUTIL_H