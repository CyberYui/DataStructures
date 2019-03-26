#include <iostream>
#include <ostream>

#include "CoordinateModel.h"

using namespace std;

//11.对运算符重载函数进行编写
//此时由于MyStack3.h已经是一个类模板了,所以在它中理论上包含Coordinate3.h已经没用了
//但是如果不在MyStack3中包含Coordinate3.h,VS2017会由于没有关于<<的重载声明而无法使用cout
//错误为:error C3861 : “cout”: 找不到标识符
//12.在主函数cpp文件中包含Coordinate3.h
ostream& operator<<(ostream &out, Coordinate &coor)
{
	out << "(" << coor.m_iX << "," << coor.m_iY << ")";

	return out;
}

Coordinate::Coordinate(int x, int y)
{
	m_iX = x;
	m_iY = y;
}

void Coordinate::printCoordinate()
{
	cout << "(" << m_iX << "," << m_iY << ")" << endl;
}