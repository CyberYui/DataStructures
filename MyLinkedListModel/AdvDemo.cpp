#include <stdlib.h>
#include <iostream>
#include "SLListAdv.h"
#include "NodeAdv.h"
using namespace std;

/************************************************************************/
/* 线性表 -- 通讯录
/*
/*	 联系人信息:姓名  电话
/*   //将联系人信息作为结点的数据域进行存储
/************************************************************************/

int main(void)
{
	Node node1;
	node1.data.name = "Jim";
	node1.data.phone = "13639779291";
	Node node2;
	node2.data.name = "Cyebr";
	node2.data.phone = "13757326643";

	List *pList = new List();

	//pList->ListInsertTail(&node1);
	//pList->ListInsertTail(&node2);
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);

	pList->ListTraverse();

	delete pList;
	pList = NULL;

	system("pause");

	return 0;
}

//对相关内容进行设计,可以完成一个很简易的通讯录例子
//只需要设计好相应的功能函数即可

/************************************************************************/
/* 线性表 -- 通讯录
/*
/*	 联系人信息:姓名  电话
/*   //将联系人信息作为结点的数据域进行存储
/*
/*	 功能菜单:
/*		----------------
/*		| 1.新建联系人 |
/*		| 2.删除联系人 |
/*		| 3.浏览通讯录 |
/*		| 4.退出通讯录 |
/*		----------------
/*		| 请输入:
/************************************************************************/
//
//int menu(int order);
//void creatPerson(List *pList);
//void deletePerson(List *pList);


//int main(void)
//{
//	int userOrder = 0;
//
//	List *pList = new List();
//
//	while (userOrder != 4)
//	{
//		userOrder = menu(userOrder);
//		switch (userOrder)
//		{
//		case 1:
//			cout << "您选择了:新建联系人...." << endl;
//			creatPerson(pList);
//			break;
//		case 2:
//			cout << "您选择了:删除联系人...." << endl;
//			deletePerson(pList);
//			break;
//		case 3:
//			pList->ListTraverse();
//			cout << "您选择了:浏览通讯录...." << endl;
//			break;
//		case 4:
//			cout << "您选择了:退出通讯录...." << endl;
//			break;
//		default:
//			break;
//		}
//	}
//
//	delete pList;
//	pList = NULL;
//
//	system("pause");
//
//	return 0;
//}

//int menu(int order)
//{
//	//显示通讯录功能菜单
//	cout << "----------------" << endl;
//	cout << "| 1.新建联系人 |" << endl;
//	cout << "| 2.删除联系人 |" << endl;
//	cout << "| 3.浏览通讯录 |" << endl;
//	cout << "| 4.退出通讯录 |" << endl;
//	cout << "----------------" << endl;
//	cout << "| 请输入: " << endl;
//
//	cin >> order;
//	return order;
//}


//void creatPerson(List *pList)
//{
//	Node node;
//
//	Person person;
//	cout << "请输入姓名: " << endl;
//	cin >> node.data.name;
//	cout << "请输入电话: " << endl;
//	cin >> node.data.phone;
//
//	//或者
//	//cout << "请输入姓名: " << endl;
//	//cin >> person.name;
//	//cout << "请输入电话: " << endl;
//	//cin >> person.phone;
//	//node.data = person;
//	//因为已经完成了=运算符重载,所以这样使用=是没有问题的
//
//	//将node插入链表
//	pList->ListInsertTail(&node);
//}

//void deletePerson(List *pList)
//{
//	Node node;
//	//新建一个个人信息,保存输入的内容
//	Person person;
//	cout << "请输入姓名: " << endl;
//	cin >> node.data.name;
//	cout << "请输入电话: " << endl;
//	cin >> node.data.phone;
//
//	int pIndex = 0;
//	//先定位结点
//	pIndex = pList->LocateElem(&node);
//	pList->ListDelete(pIndex - 1, &node);
//	cout << "删除完成" << endl;
//}