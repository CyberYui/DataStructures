#ifndef MAPADVEDGEA_H
#define MAPADVEDGEA_H

class Edge
{
public:
	//设立构造函数并初始化默认值
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);

public:
	//定义边的开始A,终点B以及权值
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;
	//标记已经挑选过的边
	bool m_bSelected;
protected:
private:
};

#endif // MAPADVEDGEA_H
