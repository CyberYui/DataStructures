#include <iostream>
#include "CustomerBasic.h"
using namespace std;

Customer::Customer(string name, int age)
{
	m_strName = name;
	m_iAge = age;
}

void Customer::printInfo()const
{
	cout << "ÐÕÃû:" << m_strName << "  ÄêÁä" << m_iAge << endl;
	cout << endl;
}