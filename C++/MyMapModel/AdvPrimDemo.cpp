#include <iostream>
#include <stdlib.h>

#include "MapAdvPrim.h"
using namespace std;

/************************************************************************/
/*  ��Ŀ����:Project11
/*  ��Ŀ����:����ͼ��ʵ������
/*  ����ʱ��:2019-3-15
/*  Author:Cyber Kaka
/************************************************************************/

/************************************************************************/
/* ͼ����С������֮����ķ�㷨
/*
/*		A			//���ͼ���漰���˱ߵ�Ȩֵ,�������ͨ��ͼ��˵,������
/*	 /  |  \		//���������Edge.h+.cpp
/*	B---F---E
/*	 \ / \ /
/*	  C---D
/*
/*	A B C D E F		//����
/*	0 1 2 3 4 5		//��Ӧ����
/*
/*	A-B(6)	A-E(5)	A-F(1)
/*	B-C(3)	B-F(2)
/*	C-F(8)	C-D(7)
/*	D-F(4)	D-E(2)
/*	E-F(9)
/*
/************************************************************************/

int main(void)
{
	//����Ͷ�Ӧ��Ž��н���
	cout << "����Ϊ:A B C D E F" << endl;
	cout << "���Ϊ:0 1 2 3 4 5" << endl;
	//����ͼ
	CMap *pMap = new CMap(6);
	//��������,�ǵ��޸��������printMatrix()
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	//��������ӽ�ͼ��
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	//�����ڽӾ���,����������ͼ,дһ��ͺ�,��ʮ����
	pMap->setValueToMatrixForUndirectedGraph(0, 1, 6);//A->B
	pMap->setValueToMatrixForUndirectedGraph(0, 4, 5);//A->E
	pMap->setValueToMatrixForUndirectedGraph(0, 5, 1);//A->F
	pMap->setValueToMatrixForUndirectedGraph(1, 2, 3);//B->C
	pMap->setValueToMatrixForUndirectedGraph(1, 5, 2);//B->F
	pMap->setValueToMatrixForUndirectedGraph(2, 5, 8);//C->F
	pMap->setValueToMatrixForUndirectedGraph(2, 3, 7);//C->D
	pMap->setValueToMatrixForUndirectedGraph(3, 5, 4);//D->F
	pMap->setValueToMatrixForUndirectedGraph(3, 4, 2);//D->E
	pMap->setValueToMatrixForUndirectedGraph(4, 5, 9);//E->F
	//��������ķ������,ӦΪA->F->B->C->D->E
	//��Ϊ:A-F(1),F-B(2),B-C(3),F-D(4),D-E(2)
	pMap->primTree(0);//��0��ʼ,����A��ʼ
	//���Խ���

	system("pause");
	return 0;
}