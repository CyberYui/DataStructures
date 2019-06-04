/*图的邻接表及其相关函数*/
#ifndef GRAPHADJLISTUTIL_H
#define GRAPHADJLISTUTIL_H

//图的结点的类型定义
typedef struct GRAPHLISTNODE_STRU
{
	int nodeno;	//图中结点的编号
	int weight;	//图中相关的权值
	struct GRAPHLISTNODE_STRU * next;	//指向下一个结点的指针
}GraphListNode;

//图的类型定义
typedef struct GRAPHLIST_STRU
{
	int size;	//图中结点的个数
	GraphListNode * graphListArray;	//图的邻接表
}GraphList;

/****************************************************************/
/* GraphList* InitGraph(int num)								*/
/* 功能:初始化图												*/
/* 输入参数num:图中结点的个数									*/
/* 返回值:用邻接表表示的图										*/
/* 创建日期:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
GraphList* InitGraph(int num);

/****************************************************************/
/* void ReadGraph(GraphList* graphList)							*/
/* 功能:将数据读入图中											*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphList* graphList);

/****************************************************************/
/* void WriteGraph(GraphList* graphList)						*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphList:图											*/
/* 返回值:无													*/
/* 创建日期:2019-5-24						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphList* graphList);

#endif	//	GRAPHADJLISTUTIL_H
