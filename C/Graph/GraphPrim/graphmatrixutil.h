/*ͼ���ڽӾ����ʾ����غ���*/
#ifndef GRAPHADJMATRIXUTIL_H
#define GRAPHADJMATRIXUTIL_H

//�ṹ�嶨��
typedef struct GRAPHMATRIX_STRU
{
	int size;       //ͼ�н��ĸ���
	int **graph;    //��ά���鱣��ͼ
}GraphMatrix;

/****************************************************************/
/* GraphMatrix* InitGraph(int num)								*/
/* ����:��ʼ��ͼ												*/
/* �������num:ͼ�н��ĸ���									*/
/* ����ֵ:���ڽӾ����ʾ��ͼ									*/
/* ��������:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* InitGraph(int num);

/****************************************************************/
/* void ReadGraph(GraphMatrix* graphMatrix)						*/
/* ����:�����ݶ���ͼ��											*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void ReadGraph(GraphMatrix* graphMatrix);

/****************************************************************/
/* void WriteGraph(GraphMatrix* graphMatrix)					*/
/* ����:��ͼ�Ľṹ��ʾ����										*/
/* �������graphMatrix:ͼ										*/
/* ����ֵ:��													*/
/* ��������:2019-5-23						Author:Cyber Kaka	*/
/****************************************************************/
void WriteGraph(GraphMatrix* graphMatrix);

/****************************************************************/
/* GraphMatrix* prim(int source, GraphMatrix *graphMatrix)		*/
/* ����:����ķ�㷨������С������								*/
/* �������source:��ʼλ��										*/
/* �������graphMatrix:�ڽӾ����ʾ��ͼ							*/
/* ����ֵtree:��С������										*/
/* ��������:2019-5-30						Author:Cyber Kaka	*/
/****************************************************************/
GraphMatrix* prim(int source, GraphMatrix *graphMatrix);

#endif // GRAPHADJMATRIXUTIL_H