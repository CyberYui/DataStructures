#include "PersonAdv.h"

//������������
ostream &operator<<(ostream &out, Person &person)
{
	out << "����: " << person.name << "-------�绰: " << person.phone << endl;
	return out;
}

//���ظ�ֵ�����
Person &Person::operator=(Person &person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this;
}

//���ع�ϵ�����
bool Person::operator==(Person &person)
{
	if (this->name == person.name&&this->phone == person.phone)
	{
		return true;
	}
	return false;
}