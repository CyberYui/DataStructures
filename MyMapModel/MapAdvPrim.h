#ifndef MAPADVPRIM_H
#define MAPADVPRIM_H

#include <vector>
using namespace std;
#include "MapAdvPrimEdge.h"
#include "MapAdvPrimNode.h"

//����Map������һ����׼ģ���,��������CMap��Ϊ������
class CMap
{
public:
	CMap(int capacity);			//���캯��
	~CMap();					//��������
	bool addNode(Node *pNode);	//��ͼ�м��붥��(���)

	//��ͼ�����ж�������,��m_bIsVisited����Ϊfalse
	void resetNode();			//���ö���

	//[ע]��������������ʵ�������ߵ�����,���ڽӾ���ı�ͷ
	//row��������,col��������,val����Ȩֵ(Ĭ��Ϊ1)
	//Ҫע�����,����ʱ���Ǵ�1��ʼ������,����ʵ�������������Ǵ�0��ʼ�����
	//Ϊ����ͼ�����ڽӾ���
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	//Ϊ����ͼ�����ڽӾ���
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);

	void printMatrix();			//��ӡ�ڽӾ���

	void depthFirstTraverse(int nodeIndex);		//������ȱ���
	void breadthFirstTraverse(int nodeIndex);	//������ȱ���

	void primTree(int nodeIndex);//����ķ������

private:
	//�Ӿ����л�ȡȨֵ
	bool getValueFromMatrix(int row, int col, int &val);
	//������ȱ���ʵ�ֺ���
	void breadthFirstTraverseImpl(vector<int> preVec);
	//��ȡ��С�ߵĺ���,����һ���ߵ�����,����������С��
	//������С�߶�Ӧ������
	int getMinEdge(vector<Edge> edgeVec);

private:
	int m_iCapacity;	//ͼ�����������ɵĶ�����

	//����һ��ͼ��˵,������һ��һ���Ž�ȥ��,Ҫ�и�������
	int m_iNodeCount;	//(������)�Ѿ���ӵĶ���(���)����
	Node *m_pNodeArray;	//ָ��������Ŷ������������
	int *m_pMatrix;		//ָ����������ڽӾ��������

	//����һ����ָ��
	Edge *m_pEdge;
};

#endif // MAPADVPRIM_H
