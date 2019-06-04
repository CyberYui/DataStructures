/*图的逆邻接表及其相关函数*/
#ifndef GRAPHINVERSELISTUTIL_H
#define GRAPHINVERSELISTUTIL_H

//图的结点的类型定义
typedef struct GRAPHINVERSELISTNODE_STRU
{
	int nodeno;	//图中结点的编号
	int weight;	//图中相关的权值
	struct GRAPHINVERSELISTNODE_STRU * next;	//指向下一个结点的指针
}GraphInverseListNode;

//图的类型定义
typedef struct GRAPHINVERSELIST_STRU
{
	int size;	//图中结点的个数
	GraphInverseListNode * graphInverseListArray;	//图的逆邻接表
}GraphInverseList;

/****************************************************************/
/* GraphInverseList* InitGraph(int num)							*/
/* 功能:初始化图												*/
/* 输入参数num:图中结点的个数									*/
/* 返回值:用逆邻接表表示的图									*/
/* 创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
GraphInverseList* InitInverseGraph(int num);

/****************************************************************/
/* void ReadInverseGraph(GraphInverseList* graphInverseList)	*/
/* 功能:将数据读入图中											*/
/* 输入参数graphInverseList:图									*/
/* 返回值:无													*/
/* 创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void ReadInverseGraph(GraphInverseList* graphInverseList);

/****************************************************************/
/* void WriteInverseGraph(GraphInverseList *graphInverseList)	*/
/* 功能:将图的结构显示出来										*/
/* 输入参数graphInverseList:图									*/
/* 返回值:无													*/
/* 创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
void WriteInverseGraph(GraphInverseList *graphInverseList);

#endif	//	GRAPHINVERSELISTUTIL_H
