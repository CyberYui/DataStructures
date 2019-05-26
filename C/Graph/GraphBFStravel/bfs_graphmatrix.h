#ifndef BFS_GRAPHMATRIX_H
#define BFS_GRAPHMATRIX_H

#include "graphmatrixutil.h"
#include "LinkQueue.h"

/****************************************************************/
/* void BFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* 功能:图的广度优先遍历,邻接矩阵表示图							*/
/* 输入参数graphMatrix:图										*/
/* 输入参数visited:用于保存访问状态的一位数组					*/
/* 输入参数i:结点编号											*/
/* 返回值:														*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphMatrix* graphMatrix, int * visited, int i);

/****************************************************************/
/* void BFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* 功能:图的广度优先遍历,邻接矩阵表示图							*/
/* 输入参数graphMatrix:图										*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphMatrix(GraphMatrix* graphMatrix);

#endif	//	BFS_GRAPHMATRIX_H
