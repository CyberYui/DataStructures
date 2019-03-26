#ifndef LISTCOORDINATE_H
#define LISTCOORDINATE_H

#include <iostream>
using namespace std;

class Coordinate
{
	//重载输出运算符
	friend ostream &operator<<(ostream &out, Coordinate &coor);
public:
	//重载关系运算符
	bool operator==(Coordinate &coor);

	Coordinate(int x = 0, int y = 0);
	void printCoordinate();

private:
	int m_iX;
	int m_iY;
};


#endif
