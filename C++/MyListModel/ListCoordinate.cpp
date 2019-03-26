#include <iostream>
#include "ListCoordinate.h"
using namespace std;

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}

bool Coordinate::operator==(Coordinate &coor)
{
	if (this->m_iX == coor.m_iX&&this->m_iY == coor.m_iY)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream &operator<<(ostream &out, Coordinate &coor)
{
	out << "(" << coor.m_iX << "," << coor.m_iY << ")" << endl;
	return out;
}
