#ifndef DFS_GRAPHMATRIX_H
#define DFS_GRAPHMATRIX_H

#include "graphmatrixutil.h"

/****************************************************************/
/* void DFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* 功能:图的深度优先遍历递归算法,邻接矩阵表示图					*/
/* 输入参数graphMatrix:图										*/
/* 输入参数visited:做标记用(设置点是否被访问)的一位数组			*/
/* 输入参数i:遍历起始的结点编号									*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphMatrix* graphMatrix, int * visited, int i);

/****************************************************************/
/* void DFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* 功能:深度遍历,邻接矩阵表示图									*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphMatrix(GraphMatrix* graphMatrix);

#endif	//	DFS_GRAPHMATRIX_H
