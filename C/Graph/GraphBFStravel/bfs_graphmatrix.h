#ifndef BFS_GRAPHMATRIX_H
#define BFS_GRAPHMATRIX_H

#include "graphmatrixutil.h"
#include "LinkQueue.h"

/****************************************************************/
/* void BFS(GraphMatrix* graphMatrix, int * visited, int i)		*/
/* ����:ͼ�Ĺ�����ȱ���,�ڽӾ����ʾͼ							*/
/* �������graphMatrix:ͼ										*/
/* �������visited:���ڱ������״̬��һλ����					*/
/* �������i:�����											*/
/* ����ֵ:														*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFS(GraphMatrix* graphMatrix, int * visited, int i);

/****************************************************************/
/* void BFSGraphMatrix(GraphMatrix* graphMatrix)				*/
/* ����:ͼ�Ĺ�����ȱ���,�ڽӾ����ʾͼ							*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-26						Author:Cyber Kaka	*/
/****************************************************************/
void BFSGraphMatrix(GraphMatrix* graphMatrix);

#endif	//	BFS_GRAPHMATRIX_H
