#include <iostream>
#include "CustomerTest.h"
using namespace std;

ostream &operator<<(ostream &out, Customer &customer)
{
	out << "����:" << customer.m_strName << "  ����" << customer.m_iAge << endl;
	return out;
}

Customer::Customer(string name, int age)
{
	m_strName = name;
	m_iAge = age;
}

void Customer::printInfo()const
{
	cout << "����:" << m_strName << "  ����" << m_iAge << endl;
	cout << endl;
}