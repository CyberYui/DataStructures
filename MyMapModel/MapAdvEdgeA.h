#ifndef MAPADVEDGEA_H
#define MAPADVEDGEA_H

class Edge
{
public:
	//�������캯������ʼ��Ĭ��ֵ
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0);

public:
	//����ߵĿ�ʼA,�յ�B�Լ�Ȩֵ
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;
	//����Ѿ���ѡ���ı�
	bool m_bSelected;
protected:
private:
};

#endif // MAPADVEDGEA_H
