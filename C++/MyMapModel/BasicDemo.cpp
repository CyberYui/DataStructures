#include <iostream>
#include <stdlib.h>

#include "MapBasic.h"
using namespace std;

/************************************************************************/
/*  ��Ŀ����:Project11
/*  ��Ŀ����:����ͼ��ʵ������
/*  ����ʱ��:2019-3-15
/*  Author:Cyber Kaka
/************************************************************************/

/************************************************************************/
/* ͼ�Ĵ洢��ͼ�ı���
/*						//�ڽӾ���Ĵ洢����
/*			 A			//ͼ��������ȱ����͹�����ȱ���
/*		   /   \
/*		  B	    D		//���Ϊ��8�������ͼ
/*		 / \   / \		//�ɼ���һ������ͼ
/*	    C	F G - H
/*		 \ /
/*        E
/*	//���ڽӾ���Ϊ:
/*	  |A|B|C|D|E|F|G|H|		//Ĭ��Ȩֵ��Ϊ1
/*	A |\|1| |1| | | | |		//����������Խ��߶Գ�
/*	B |1|\|1| | |1| | |
/*	C | |1|\| |1|1| | |
/*	D |1| | |\| | |1|1|
/*	E | | |1| |\| | | |
/*	F | |1|1| | |\| | |
/*	G | | | |1| | |\|1|
/*	H | | | |1| | |1|\|		//'\'��ʾ�Գ���
/*
/************************************************************************/

int main(void)
{
	//����ͼ
	CMap *pMap = new CMap(8);
	//��������
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');
	//��������ӽ�ͼ��
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);
	//�����ڽӾ���,����������ͼ,дһ��ͺ�
	//һ���ŶԱ�,Ҫһһ����һ��
	//ע���кͱ߶��Ǵ�0��ʼ���
	pMap->setValueToMatrixForUndirectedGraph(0, 1);//A->B
	pMap->setValueToMatrixForUndirectedGraph(0, 3);//A->D
	pMap->setValueToMatrixForUndirectedGraph(1, 2);//B->C
	pMap->setValueToMatrixForUndirectedGraph(1, 5);//B->F
	pMap->setValueToMatrixForUndirectedGraph(2, 4);//C->E
	pMap->setValueToMatrixForUndirectedGraph(2, 5);//C->F
	pMap->setValueToMatrixForUndirectedGraph(3, 6);//D->G
	pMap->setValueToMatrixForUndirectedGraph(3, 7);//D->H
	pMap->setValueToMatrixForUndirectedGraph(6, 7);//G->H
	//��ӡһ�¿�Ч��
	pMap->printMatrix();//�ɼ���һ�µ�����
	cout << endl;
	//����������ȱ���
	pMap->depthFirstTraverse(0);//ָ�����,��A,����Ϊ0
	cout << endl;
	//����һ���ѷ��ʱ�ʶ
	pMap->resetNode();
	//���ù�����ȱ���
	pMap->breadthFirstTraverse(0);//ָ�����ΪA
	//���Խ���

	system("pause");
	return 0;
}