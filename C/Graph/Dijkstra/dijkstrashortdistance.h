#ifndef DIJKSTRASHORTDISTANCE_H
#define DIJKSTRASHORTDISTANCE_H

#include "graphmatrixutil.h"

/****************************************************************/
/* int* dijkstra(int source, GraphMatrix *graphMatrix)			*/
/* 功能:对邻接矩阵表示的图使用dijkstra算法找出一个顶点到其它顶点*/
/*		的最短路径												*/
/* 输入参数source:起点											*/
/* 输入参数graphMatrix:图										*/
/* 返回值:存放最短路径的一维数组distance						*/
/* 创建日期:2019-6-1						Author:Cyber Kaka	*/
/****************************************************************/
int* dijkstra(int source, GraphMatrix *graphMatrix);

#endif // DIJKSTRASHORTDISTANCE_H
