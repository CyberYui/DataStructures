#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graphmatrixutil.h"

/*�ߵĽṹ*/
typedef struct EDGE_STRU
{
	int begin;	//�ߵ����
	int end;	//�ߵ��յ�
	int weight;	//Ȩֵ
}Edge;

/****************************************************************/
/* GraphMatrix* kruskal(GraphMatrix *graphMatrix)				*/
/* ����:ʹ�ÿ�³˹�����㷨������С������						*/
/* �������graphMatrix:											*/
/* ����ֵtree:��С������										*/
/* ��������:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* kruskal(GraphMatrix *graphMatrix);

#endif	//	KRUSKAL_H
