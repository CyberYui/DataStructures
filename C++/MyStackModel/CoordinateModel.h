#ifndef COORDINATEMODEL_H
#define COORDINATEMODEL_H
#include <ostream>
using namespace std;

class Coordinate
{
	//10.对<<进行运算符重载
	//[注意]如果没有宏定义而是使用#pragma one则会在之后的函数体编译中报错
	friend ostream& operator<<(ostream &out, Coordinate &coor);
public:
	Coordinate(int x = 0, int y = 0);//构造函数需要有相应的默认值
	void printCoordinate();

private:
	int m_iX;
	int m_iY;
};

#endif // COORDINATETHIRD_H