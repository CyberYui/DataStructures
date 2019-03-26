#pragma once

class Coordinate
{
public:
	//对于类类型的对象需要有默认值
	Coordinate(int x = 0, int y = 0);
	void printCoordinate();

private:
	int m_iX;
	int m_iY;
};