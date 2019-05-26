#ifndef BFS_GRAPHLIST_H
#define BFS_GRAPHLIST_H

#include "graphlistutil.h"

/****************************************************************/
/* void BFS(GraphList* graphList, int * visited, int i)			*/
/* 功能:对邻接表表示的图进行广度优先遍历						*/
/* 输入参数graphList:图,邻接表表示								*/
/* 输入参数visited:用于标记结点是否被访问过的一位数组			*/
/* 输入参数i:结点编号											*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphList* graphList, int * visited, int i);

/****************************************************************/
/* void BFSGraphList(GraphList* graphList)						*/
/* 功能:图的广度优先遍历,邻接表表示图							*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphList(GraphList* graphList);

#endif	//	BFS_GRAPHLIST_H
