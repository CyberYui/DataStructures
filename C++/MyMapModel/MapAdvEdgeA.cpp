#include "MapAdvEdgeA.h"


/****************************************************************/
/* Edge(int nodeIndexA=0,int nodeIndexB=0,int weightValue=0)	*/
/* 功能:初始化一条边,其开始为A点,终点为B点,权值为weightValue对应*/
/*		的值.													*/
/* 																*/
/* 创建日期:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
Edge::Edge(int nodeIndexA, int nodeIndexB, int weightValue)
{
	m_iNodeIndexA = nodeIndexA;
	m_iNodeIndexB = nodeIndexB;
	m_iWeightValue = weightValue;
	m_bSelected = false;
}