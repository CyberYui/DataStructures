#ifndef PERSONADV_H
#define PERSONADV_H

#include <string>
#include <ostream>
using namespace std;

class Person
{
	//�������(<<)�����
	friend ostream &operator<<(ostream &out, Person &person);
public:
	string name;//����
	string phone;//�绰
	//���ظ�ֵ(=)�����
	Person &operator=(Person &person);
	//���ع�ϵ(==)�����
	bool operator==(Person &person);
protected:
private:
};

#endif // PERSONADV_H
