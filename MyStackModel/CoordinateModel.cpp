#include <iostream>
#include <ostream>

#include "CoordinateModel.h"

using namespace std;

//11.����������غ������б�д
//��ʱ����MyStack3.h�Ѿ���һ����ģ����,���������������ϰ���Coordinate3.h�Ѿ�û����
//�����������MyStack3�а���Coordinate3.h,VS2017������û�й���<<�������������޷�ʹ��cout
//����Ϊ:error C3861 : ��cout��: �Ҳ�����ʶ��
//12.��������cpp�ļ��а���Coordinate3.h
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