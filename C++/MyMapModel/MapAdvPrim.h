#ifndef MAPADVPRIM_H
#define MAPADVPRIM_H

#include <vector>
using namespace std;
#include "MapAdvPrimEdge.h"
#include "MapAdvPrimNode.h"

//由于Map本身是一个标准模版库,所以起名CMap是为了区分
class CMap
{
public:
	CMap(int capacity);			//构造函数
	~CMap();					//析构函数
	bool addNode(Node *pNode);	//向图中加入顶点(结点)

	//将图中所有顶点重置,其m_bIsVisited重置为false
	void resetNode();			//重置顶点

	//[注]下面两个函数其实是在做边的设置,即邻接矩阵的表头
	//row即是行数,col就是列数,val就是权值(默认为1)
	//要注意的是,看的时候是从1开始看行列,但是实际上在数组中是从0开始保存的
	//为有向图设置邻接矩阵
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);
	//为无向图设置邻接矩阵
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);

	void printMatrix();			//打印邻接矩阵

	void depthFirstTraverse(int nodeIndex);		//深度优先遍历
	void breadthFirstTraverse(int nodeIndex);	//广度优先遍历

	void primTree(int nodeIndex);//普里姆生成树

private:
	//从矩阵中获取权值
	bool getValueFromMatrix(int row, int col, int &val);
	//广度优先遍历实现函数
	void breadthFirstTraverseImpl(vector<int> preVec);
	//获取最小边的函数,传入一个边的数组,从中挑出最小边
	//返回最小边对应的索引
	int getMinEdge(vector<Edge> edgeVec);

private:
	int m_iCapacity;	//图中最多可以容纳的顶点数

	//对于一个图来说,顶点是一个一个放进去的,要有个计数器
	int m_iNodeCount;	//(计数器)已经添加的顶点(结点)个数
	Node *m_pNodeArray;	//指向用来存放顶点数组的内容
	int *m_pMatrix;		//指向用来存放邻接矩阵的内容

	//定义一个边指针
	Edge *m_pEdge;
};

#endif // MAPADVPRIM_H
