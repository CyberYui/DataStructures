#ifndef LISTCOORDINATE_H
#define LISTCOORDINATE_H

#include <iostream>
using namespace std;

class Coordinate
{
	//������������
	friend ostream &operator<<(ostream &out, Coordinate &coor);
public:
	//���ع�ϵ�����
	bool operator==(Coordinate &coor);

	Coordinate(int x = 0, int y = 0);
	void printCoordinate();

private:
	int m_iX;
	int m_iY;
};


#endif
