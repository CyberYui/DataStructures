#ifndef CUSTOMERTEST_H
#define CUSTOMERTEST_H

#include <string>
using namespace std;

class Customer
{
	//对输出运算符进行重载
	friend ostream &operator<<(ostream &out, Customer &customer);
public:
	Customer(string name = " ", int age = 0);
	void printInfo()const;
protected:
private:
	string m_strName;
	int m_iAge;
};

#endif // CUSTOMERTEST_H
