#include <iostream>
#include "CustomerTest.h"
using namespace std;

ostream &operator<<(ostream &out, Customer &customer)
{
	out << "姓名:" << customer.m_strName << "  年龄" << customer.m_iAge << endl;
	return out;
}

Customer::Customer(string name, int age)
{
	m_strName = name;
	m_iAge = age;
}

void Customer::printInfo()const
{
	cout << "姓名:" << m_strName << "  年龄" << m_iAge << endl;
	cout << endl;
}