#ifndef DFS_GRAPHLIST_H
#define DFS_GRAPHLIST_H

#include "graphlistutil.h"

/****************************************************************/
/* void DFS(GraphList* graphList, int * visited, int i)			*/
/* 功能:图的深度优先遍历递归算法,邻接表表示图					*/
/* 输入参数graphList:图											*/
/* 输入参数visited:做标记用(设置点是否被访问过)的一维数组		*/
/* 输入参数i:结点编号											*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphList* graphList, int * visited, int i);

/****************************************************************/
/* void GFSGraphList(GraphList* graphList)						*/
/* 功能:深度遍历,邻接表表示图									*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphList(GraphList* graphList);

#endif	//	DFS_GRAPHLIST_H
