#ifndef COORDINATEMODEL_H
#define COORDINATEMODEL_H
#include <ostream>
using namespace std;

class Coordinate
{
	//10.��<<�������������
	//[ע��]���û�к궨�����ʹ��#pragma one�����֮��ĺ���������б���
	friend ostream& operator<<(ostream &out, Coordinate &coor);
public:
	Coordinate(int x = 0, int y = 0);//���캯����Ҫ����Ӧ��Ĭ��ֵ
	void printCoordinate();

private:
	int m_iX;
	int m_iY;
};

#endif // COORDINATETHIRD_H