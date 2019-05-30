#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graphmatrixutil.h"

/*边的结构*/
typedef struct EDGE_STRU
{
	int begin;	//边的起点
	int end;	//边的终点
	int weight;	//权值
}Edge;

/****************************************************************/
/* GraphMatrix* kruskal(GraphMatrix *graphMatrix)				*/
/* 功能:使用克鲁斯卡尔算法生成最小生成树						*/
/* 输入参数graphMatrix:											*/
/* 返回值tree:最小生成树										*/
/* 创建日期:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* kruskal(GraphMatrix *graphMatrix);

#endif	//	KRUSKAL_H
