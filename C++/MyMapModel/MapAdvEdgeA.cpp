#include "MapAdvEdgeA.h"


/****************************************************************/
/* Edge(int nodeIndexA=0,int nodeIndexB=0,int weightValue=0)	*/
/* ����:��ʼ��һ����,�俪ʼΪA��,�յ�ΪB��,ȨֵΪweightValue��Ӧ*/
/*		��ֵ.													*/
/* 																*/
/* ��������:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
Edge::Edge(int nodeIndexA, int nodeIndexB, int weightValue)
{
	m_iNodeIndexA = nodeIndexA;
	m_iNodeIndexB = nodeIndexB;
	m_iWeightValue = weightValue;
	m_bSelected = false;
}