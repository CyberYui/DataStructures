#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include "graphlistutil.h"
#include "graphinverselistutil.h"

/****************************************************************/
/*int eventEarliestTime(GraphList *graphList, int *earliestTime)*/
/*	����:���¼����ܵ����緢��ʱ��								*/
/*	�������graphList:���ڽӱ��ʾ��ͼ							*/
/*	�������earliestTime:�¼����ܵ����緢��ʱ��					*/
/*	����ֵsuccess:1--�ɹ�	0--ʧ��								*/
/*	��������:2019-6-4						Author:Cyber Kaka	*/
/****************************************************************/
int eventEarliestTime(GraphList *graphList, int *earliestTime);

/****************************************************************************/
/*	int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime)*/
/*	����:�����¼��������ٷ���ʱ��											*/
/*	�������graphInverseList:�����ڽӱ��ʾ��ͼ								*/
/*	�������latestTime:�¼��������ٷ���ʱ������							*/
/*	����ֵsuccess:1--�ɹ�	0--ʧ��											*/
/*	��������:2019-6-4									Author:Cyber Kaka	*/
/****************************************************************************/
int eventLatestTime(GraphInverseList *graphInverseList, int *latestTime);

/********************************************************************************/
/*	void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList)	*/
/*	����:����һ��ͼ���ڽӱ�����ڽӱ����ؼ�·��								*/
/*	�������graphList:���ڽӱ��ʾ��ͼ											*/
/*	�������graphInverseList:�����ڽӱ��ʾ��ͼ									*/
/*	����ֵ:��																	*/
/*	��������:2019-6-4										Author:Cyber Kaka	*/
/********************************************************************************/
void criticalPath(GraphList *graphList, GraphInverseList *graphInverseList);

#endif	//	CRITICALPATH_H
