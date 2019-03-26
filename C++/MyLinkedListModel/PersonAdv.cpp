#include "PersonAdv.h"

//重载输出运算符
ostream &operator<<(ostream &out, Person &person)
{
	out << "姓名: " << person.name << "-------电话: " << person.phone << endl;
	return out;
}

//重载赋值运算符
Person &Person::operator=(Person &person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this;
}

//重载关系运算符
bool Person::operator==(Person &person)
{
	if (this->name == person.name&&this->phone == person.phone)
	{
		return true;
	}
	return false;
}