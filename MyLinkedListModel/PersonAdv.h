#ifndef PERSONADV_H
#define PERSONADV_H

#include <string>
#include <ostream>
using namespace std;

class Person
{
	//重载输出(<<)运算符
	friend ostream &operator<<(ostream &out, Person &person);
public:
	string name;//姓名
	string phone;//电话
	//重载赋值(=)运算符
	Person &operator=(Person &person);
	//重载关系(==)运算符
	bool operator==(Person &person);
protected:
private:
};

#endif // PERSONADV_H
