#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include "graphlistutil.h"
#include "graphinverselistutil.h"

/****************************************************************/
/*int eventEarliestTime(GraphList *graphList, int *earliestTime)*/
/*	功能:求事件可能的最早发生时间								*/
/*	输入参数graphList:用邻接表表示的图							*/
/*	输入参数earliestTime:事件可能的最早发生时间					*/
/*	返回值success:1--成功	0--失败								*/
/*	创建日期:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
int eventEarliestTime(GraphList *graphList, int *earliestTime);

/****************************************************************************/
/*	int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)*/
/*	功能:计算事件允许的最迟发生时间											*/
/*	输入参数graphInverseList:用逆邻接表表示的图								*/
/*	输入参数latestTime:事件允许的最迟发生时间数组							*/
/*	返回值success:1--成功	0--失败											*/
/*	创建日期:2019-6-4									Author:Cyber Kaka	*/
/****************************************************************************/
int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime);

/********************************************************************************/
/*	void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)	*/
/*	功能:根据一个图的邻接表和逆邻接表计算关键路径								*/
/*	输入参数graphList:用邻接表表示的图											*/
/*	输入参数graphInverseList:用逆邻接表表示的图									*/
/*	返回值:无																	*/
/*	创建日期:2019-6-4										Author:Cyber Kaka	*/
/********************************************************************************/
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList);

#endif	//	CRITICALPATH_H
