#include <iostream>
#include "TreeBasic.h"
using namespace std;

/****************************************************************/
/* Tree(int size,int *pRoot)									*/
/* ����:����һ����,���������г�ʼ������							*/
/* 																*/
/* ��������:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
Tree::Tree(int size, int *pRoot)			//������
{
	m_iSize = size;
	m_pTree = new int[size];//�Ӷ��з����ڴ�
	//�������ʼ״̬
	for (int i = 0; i < size; i++)
	{
		//����˵Ӧ�öԷ����ڴ��ָ������п�,�����Թ�
		m_pTree[i] = 0;
	}
	//������ڵ�
	m_pTree[0] = *pRoot;//�����ָ��ֵ��Ϊ���ڵ��ֵ
}


/****************************************************************/
/* ~Tree()														*/
/* ����:�����ڹ��캯���д�������								*/
/* 																*/
/* ��������:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
Tree::~Tree()					//������
{
	delete[]m_pTree;
	m_pTree = NULL;
}


/****************************************************************/
/* int *SearchNode(int nodeIndex)								*/
/* ����:���ݸ���������Ѱ����Ӧ���								*/
/* 																*/
/* ��������:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
int *Tree::SearchNode(int nodeIndex)	//��������Ѱ�ҽ��
{
	//�жϴ��������ĺϷ���
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return NULL;
	}
	//������,���ֵΪ0,�������ﲻ��һ��Ҷ�ӽڵ�/�ӽڵ�
	if (m_pTree[nodeIndex] == 0)
	{
		return NULL;
	}
	return &m_pTree[nodeIndex];
}


/****************************************************************/
/* bool AddNode(int nodeIndex, int direction, int *pNode)		*/
/* ����:��ӽ��												*/
/*																*/
/* ��������:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
bool Tree::AddNode(int nodeIndex, int direction, int *pNode)
{
	//�жϴ��������ĺϷ���
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	//������,���ֵΪ0,�������ﲻ��һ��Ҷ�ӽڵ�/�ӽڵ�
	if (&m_pTree[nodeIndex] == 0)
	{
		return false;
	}
	//���������,��Ҫ�����ӻ����Һ���
	if (direction == 0)		//����0���������
	{
		//�жϴ��������ĺϷ���
		//���nodeIndex!<0,��ô�Ͳ����ܻ���(nodeIndex*2+1)<0�����
		if ((nodeIndex * 2 + 1) >= m_iSize)
		{
			return false;
		}
		//�����в鿴ԭ�������Ƿ���ֵ,��ֵ�򲻴�,������봫���ֵ
		if (m_pTree[nodeIndex * 2 + 1] != 0)
		{
			return false;
		}
		m_pTree[nodeIndex * 2 + 1] = *pNode;
	}

	if (direction == 1)		//����1�����Ҳ���,+1����,��+2����
	{
		//�жϴ��������ĺϷ���
		//���nodeIndex!<0,��ô�Ͳ����ܻ���(nodeIndex*2+2)<0�����
		if ((nodeIndex * 2 + 2) >= m_iSize)
		{
			return false;
		}
		//�����в鿴ԭ�������Ƿ���ֵ,��ֵ�򲻴�,������봫���ֵ
		if (m_pTree[nodeIndex * 2 + 2] != 0)
		{
			return false;
		}
		m_pTree[nodeIndex * 2 + 2] = *pNode;
	}
	//�����������������,Ҳ���ǲ�����,�����漴��
	return true;
}


/****************************************************************/
/* bool DeleteNode(int nodeIndex, int *pNode)					*/
/* ����:ɾ�����												*/
/* 																*/
/* ��������:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
bool Tree::DeleteNode(int nodeIndex, int *pNode)
{
	//�������ж������ĺϷ���
	if (nodeIndex < 0 || nodeIndex >= m_iSize)
	{
		return false;
	}
	//�жϸô���ֵ�Ƿ�Ϊ0,Ϊ0��ʾ���ڵ�����û��ֵ
	if (m_pTree[nodeIndex] == 0)
	{
		return false;
	}
	//��Ҫɾ����ֵ����pNode,��ɾ�������ڵ�,����0
	*pNode = m_pTree[nodeIndex];
	m_pTree[nodeIndex] = 0;
	return true;
}


/****************************************************************/
/* void TreeTraverse()											*/
/* ����:���������												*/
/*																*/
/* ��������:2019-3-13						Author:Cyber Kaka	*/
/****************************************************************/
void Tree::TreeTraverse()		//�������
{
	//�������Ǳ�������,ֻ��Ҫ��һ��ѭ������
	for (int i = 0; i < m_iSize; i++)
	{
		cout << m_pTree[i] << ",";
	}
}