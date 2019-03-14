/************************************************************************/
/* ������(�����ʾ)
/*	   Ҫ��:������Ļ�������
/*			1.���Ĵ���������
/*			2.���нڵ������
/*			3.���нڵ�������ɾ��
/*			4.���нڵ�ı���
/* (C��������)
/*	   BOOL CreateTree(Tree **pTree,Node *pRoot);				//������
/*	   void DestroyTree(Tree *pTree);							//������
/*	   Node *SearchNode(Tree *pTree,int nodeIndex);				//��������Ѱ�ҽڵ�
/*
/*	   //��ӽڵ�
/*	   BOOL AddNode(Tree *pTree,int nodeIndex,int direction,Node *pNode);
/*	   BOOL DeleteNode(Tree *pTree,int nodeIndex,Node *pNode);	//ɾ���ڵ�
/*	   void TreeTraverse(Tree *pTree);							//����
/*
/* ������������֮����㷨ת��
/*
/*	   int tree[n]   3    			[�������Ĺ���]:
/*					5 8				���׽ڵ��±�*2+1=�ýڵ���
/*				  2 6 9 7			���׽ڵ��±�*2+2=�ýڵ���
/*
/* ����������������:   ��ʽ:ֵ(����)
/*----�����������������е�����
/*			   3(0)
/*
/*		5(1)			8(2)
/*
/*	2(3)	6(4)	9(5)	7(6)
/*----����ֻ��һ�ຢ�ӵ����,������һ�ຢ��ֵ��Ϊ0,�����˵����нڵ����
/*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "TreeBasic.h"
using namespace std;

int main(void)
{
	int root = 3;//���ڵ�
	//ͨ�����ü��������Ĵ����Ƿ�����
	Tree *pTree = new Tree(10, &root);
	int note1 = 5;//��ڵ�
	int note2 = 8;//�ҽڵ�
	pTree->AddNode(0, 0, &note1);//note1���뵽3(0)�����
	pTree->AddNode(0, 1, &note2);//note2���뵽3(0)���ұ�

	int note3 = 2;
	int note4 = 6;
	pTree->AddNode(1, 0, &note3);//note3���뵽5(1)�����
	pTree->AddNode(1, 1, &note4);//note4���뵽5(1)���ұ�

	int note5 = 9;
	int note6 = 7;
	pTree->AddNode(2, 0, &note5);//note5���뵽8(2)�����
	pTree->AddNode(2, 1, &note6);//note6���뵽8(2)���ұ�

	pTree->TreeTraverse();

	int *p = pTree->SearchNode(2);//��ջ������ָ��,�ǲ���Ҫ�ͷŲ�����
	cout << endl << "Node= " << *p << endl;

	pTree->TreeTraverse();
	pTree->DeleteNode(6, p);
	cout << endl << "Node= " << *p << endl;
	pTree->TreeTraverse();


	delete pTree;
	pTree = NULL;

	system("pause");
	return 0;
}