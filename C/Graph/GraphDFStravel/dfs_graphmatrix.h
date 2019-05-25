#ifndef DFS_GRAPHMATRIX_H
#define DFS_GRAPHMATRIX_H

#include "graphmatrixutil.h"

/****************************************************************/
/* void DFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* ����:ͼ��������ȱ����ݹ��㷨,�ڽӾ����ʾͼ					*/
/* �������graphMatrix:ͼ										*/
/* �������visited:�������(���õ��Ƿ񱻷���)��һλ����			*/
/* �������i:������ʼ�Ľ����									*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFS(GraphMatrix* graphMatrix, int * visited, int i);

/****************************************************************/
/* void DFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* ����:��ȱ���,�ڽӾ����ʾͼ									*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-25						Author:Cyber Kaka	*/
/****************************************************************/
void DFSGraphMatrix(GraphMatrix* graphMatrix);

#endif	//	DFS_GRAPHMATRIX_H
